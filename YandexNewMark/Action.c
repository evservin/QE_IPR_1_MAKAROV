Action()
{
	curSec = showCurrentSecDigit(x);
	lr_save_int(curSec, "ALLSECDATE");

	lr_start_transaction("1_Main_NM");

	web_set_sockets_option("SSL_VERSION", "AUTO");

/*Correlation comment: Automatic rules - Do not change!  
Original value='73671981642338644' 
Name ='yu' 
Type ='Rule' 
AppName ='YANDEX' 
RuleName ='UID'*/
	web_reg_save_param_regexp(
		"ParamName=yu",
		"RegExp=yandexuid=(.*?);",
		LAST);

/*Correlation comment: Automatic rules - Do not change!  
Original value='e3dcbc283e739183cbd8076de61342fcc22bcd15:1642338644875' 
Name ='csrf_token' 
Type ='Rule' 
AppName ='YANDEX' 
RuleName ='crsf'*/
	web_reg_save_param_regexp(
		"ParamName=csrf_token",
		"RegExp=csrf_token\"\\ value=\"(.*?)\"",
		LAST);

/*Correlation comment: Automatic rules - Do not change!  
Original value='944376cf-ea94-4358-8c3c-7c18467be11f' 
Name ='process_uuid' 
Type ='Rule' 
AppName ='YANDEX' 
RuleName ='process_uuid'*/
	web_reg_save_param_regexp(
		"ParamName=process_uuid",
		"RegExp=process_uuid=(.*?)\"",
		LAST);
		
	web_reg_find("Search=All",
		"Text=Узнать больше",
		LAST);

	web_url("auth", 
		"URL=https://passport.yandex.ru/auth", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t143.inf", 
		"Mode=HTML", 
		LAST);



	lr_end_transaction("1_Main_NM",LR_AUTO);


	lr_start_transaction("2_login_NM");

	

	/*Possible OAUTH authorization was detected. It is recommended to correlate the authorization parameters.*/

/*Correlation comment - Do not change!  Original value='28343870cce15caf30112ec2ed8563194d' Name ='track_id' Type ='ResponseBased'*/
	web_reg_save_param_json(
		"ParamName=track_id",
		"QueryString=$.track_id",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=No",
		LAST);

	web_submit_data("start",
		"Action=https://passport.yandex.ru/registration-validations/auth/multi_step/start",
		"Method=POST",
		"EncodeAtSign=YES",
		"TargetFrame=",
		"RecContentType=application/json",
		"Referer=https://passport.yandex.ru/",
		"Snapshot=t157.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=csrf_token", "Value={csrf_token}", ENDITEM,
		"Name=login", "Value={login}", ENDITEM,
		"Name=process_uuid", "Value={process_uuid}", ENDITEM,
		LAST);

	

/*Correlation comment - Do not change!  Original value='1431766764' Name ='uid' Type ='ResponseBased'*/
	web_reg_save_param_regexp(
		"ParamName=uid",
		"RegExp=X-Default-UID:\\ (.*?)\\\r\\\n",
		SEARCH_FILTERS,
		"Scope=Headers",
		"IgnoreRedirections=No",
		LAST);
		
	lr_think_time(10);

	web_submit_data("commit_password",
		"Action=https://passport.yandex.ru/registration-validations/auth/multi_step/commit_password",
		"Method=POST",
		"TargetFrame=",
		"RecContentType=application/json",
		"Referer=https://passport.yandex.ru/",
		"Snapshot=t164.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=csrf_token", "Value={csrf_token}", ENDITEM,
		"Name=track_id", "Value={track_id}", ENDITEM,
		"Name=password", "Value={pass}", ENDITEM,
		"Name=retpath", "Value=https://passport.yandex.ru/profile", ENDITEM,
		LAST);

	

	web_submit_data("accounts",
		"Action=https://passport.yandex.ru/registration-validations/auth/accounts",
		"Method=POST",
		"TargetFrame=",
		"RecContentType=application/json",
		"Referer=https://passport.yandex.ru/",
		"Snapshot=t167.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=csrf_token", "Value={csrf_token}", ENDITEM,
		LAST);
		
	web_reg_find("Search=All",
		"Text=Почта и телефоны",
		LAST);	
	

	web_url("redirect", 
		"URL=https://passport.yandex.ru/redirect?url=https%3A%2F%2Fpassport.yandex.ru%2Fprofile", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://passport.yandex.ru/", 
		"Snapshot=t170.inf", 
		"Mode=HTML", 
		LAST);

	

	lr_end_transaction("2_login_NM",LR_AUTO);

	

	lr_start_transaction("3_inPost_NM");

/*Correlation comment - Do not change!  Original value='53816276-1642338703277' Name ='CorrelationParameter_1' Type ='Manual'*/
	web_reg_save_param_regexp(
		"ParamName=CorrelationParameter_1",
		"RegExp=LIZA-(.*?);",
		LAST);

/*Correlation comment: Automatic rules - Do not change!  
Original value='v1ms7TIwJtUK4eL2bfIagsqkb+U=!kyipi0gc' 
Name ='CorrelationParameter_2' 
Type ='Rule' 
AppName ='YANDEX' 
RuleName ='ckey":"(.*?)"'*/
	web_reg_save_param_regexp(
		"ParamName=CorrelationParameter_2",
		"RegExp=ckey\":\"(.*?)\"",
		LAST);
		
	web_reg_find("Search=All",
		"Text=Выйти из аккаунта",
		LAST);		

	web_url("mail.yandex.ru", 
		"URL=https://mail.yandex.ru/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://passport.yandex.ru/", 
		"Snapshot=t189.inf", 
		"Mode=HTML", 
		LAST);

	

	web_url("1_11", 
		"URL=https://an.yandex.ru/jserr/1", 
		"TargetFrame=", 
		"Resource=0", 
		"Referer=https://mail.yandex.ru/", 
		"Snapshot=t200.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=../resource/spacer.gif", "Referer=", ENDITEM, 
		LAST);

	

	lr_end_transaction("3_inPost_NM",LR_AUTO);

	

	lr_start_transaction("4_newMark");
	
	
	web_reg_find("Search=Body",
	             "Text=add\"\,\"status\"\:\"ok",
					LAST);	



	web_custom_request("liza1_17",
		"URL=https://mail.yandex.ru/web-api/models/liza1?_m=do-labels-add,labels",
		"Method=POST",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=application/json",
		"Referer=https://mail.yandex.ru/",
		"Snapshot=t251.inf",
		"Mode=HTML",
		"EncType=application/json; encoding=utf-8",
		"Body={\"models\":[{\"name\":\"do-labels-add\",\"params\":{\"label_name\":\"{label}{ALLSECDATE}\",\"label_color\":\"{COLOR}\"},\"meta\":{\"requestAttempt\":1}},{\"name\":\"labels\",\"params\":{},\"meta\":{\"requestAttempt\":1}}],\"_ckey\":\"{CorrelationParameter_2}\",\"_uid\":\"{uid}\",\"_locale\":\"ru\",\"_timestamp\":1642338778307,\"_product\":\"RUS\",\"_connection_id\":\"LIZA-{CorrelationParameter_1}\",\"_exp\":\"457741,0,-1;462916,0,79;451868,0,63;407772,0,43;404892,0,31;414430,0,2;406173,0,24;380961,0,91;428729,0,34;400316,0,16;475161,0,73;261659,0,32;118737,0,52;467180,0,23;406512,0,46;453153,0,50;443223,0,18;416833,0,81;456408,0,65;453083,0,38;403319,0,20;470107,0,99;286809,0,8;420030,0,61;300740,0,15;470118,0,82;317929,0,61;92934,0,82;416857,0,23;416853,0,6;383125,0,19;399880,0,7;358334,0,75;367504,0,64;402861,0,46;262911,0,86;381544,0,97;227595,0,55;343047,0,79\",\"_eexp\":\"457741,0,-1;462916,0,79;451868,0,63;404892,0,31;406173,0,24;380961,0,91;428729,0,34;475161,0,73;261659,0,32;118737,0,52;406512,0,46;456408,0,6"
		"5;453083,0,38;286809,0,8;300740,0,15;470118,0,82;317929,0,61;416853,0,6;383125,0,19;399880,0,7;358334,0,75;367504,0,64;262911,0,86;381544,0,97;227595,0,55\",\"_service\":\"LIZA\",\"_version\":\"28.0.1\",\"_messages_per_page\":\"30\"}",
		LAST);

	lr_think_time(10);

	lr_end_transaction("4_newMark",LR_AUTO);



	lr_start_transaction("5_logout_NM");

	web_reg_find("Search=Body",
		"Text=Войдите с Яндекс ID",
		LAST);

/*Correlation comment - Do not change!  Original value='003d5059-8bc3-45c4-812d-b12dd8546304' Name ='CorrelationParameter_3' Type ='Manual'*/
	web_reg_save_param_regexp(
		"ParamName=CorrelationParameter_3",
		"RegExp=nonce-(.*?)",
		LAST);


	web_url("passport",
		"URL=https://passport.yandex.ru/passport?mode=embeddedauth&action=logout&yu={yu}&uid={uid}&origin=&retpath=https%3A%2F%2Fmail.yandex.ru&",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=text/html",
		"Referer=https://mail.yandex.ru/",
		"Snapshot=t271.inf",
		"Mode=HTML",
		LAST);


	web_custom_request("csp",
		"URL=https://csp.yandex.net/csp?from=passport&project=passport&yandex_login=&yandexuid={yu}",
		"Method=POST",
		"TargetFrame=",
		"Resource=0",
		"Referer=https://passport.yandex.ru/",
		"Snapshot=t272.inf",
		"Mode=HTML",
		"EncType=application/csp-report",
		"Body={\"csp-report\":{\"document-uri\":\"https://passport.yandex.ru/auth?from=mail&origin=hostroot_homer_auth_L_ru&retpath=https%3A%2F%2Fmail.yandex.ru%2F&backpath=https%3A%2F%2Fmail.yandex.ru%3Fnoretpath%3D1\",\"referrer\":\"https://mail.yandex.ru/\",\"violated-directive\":\"img-src\",\"effective-directive\":\"img-src\",\"original-policy\":\"default-src 'none';style-src 'self' yastatic.net 'unsafe-inline' 'unsafe-eval' s3.mds.yandex.net s3.mdst.yandex.net;script-src 'self' yastatic.net mc.admetrica.ru mc.yandex.ru chat.s3.yandex.net api-maps.yandex.ru suggest-maps.yandex.net export.yandex.ru 'unsafe-eval' 'unsafe-inline' 'nonce-{CorrelationParameter_3}' https://yandex.ru/global-notifications/butterfly/stable/butterfly.js;img-src 'self' yastatic.net https://ysa-static.passport.yandex.ru https://ysa-static.passport.yandex.net yandex.st data: mc.admetrica.ru mc.yandex.ru api-maps.yandex.ru *.captcha.yandex.net s3.mds.yandex.net s3.mdst.yandex.net avatars.mds.yandex.net avatars.mdst.yandex.net clck."
		"yandex.ru *.maps.yandex.net yapic.yandex.ru img.yandex.ru static-maps.yandex.ru https://video-tub-ru.yandex.net https://img0-tub-ru.yandex.net https://img1-tub-ru.yandex.net https://img2-tub-ru.yandex.net https://img3-tub-ru.yandex.net blob:  mc.webvisor.com mc.webvisor.org;font-src 'self' data: yastatic.net;object-src yastatic.net;media-src *.captcha.yandex.net data:;connect-src mail.yandex.ru 'self' mc.admetrica.ru mc.yandex.ru trust.yandex.ru suggest-maps.yandex.net mc.webvisor.com mc.webvisor.org yandex.ru api.passport.yandex.ru;frame-ancestors 'self';frame-src 'self' yandex.st s4.money.yandex.net https://yandex.ru/chat split.yandex.ru yandex.ru null pass.yandex.ru passport.yandex.ru https://trust.yandex.ru blob: mc.yandex.ru magic.passport.yandex.ru https://yandex.ru/forms https://forms.yandex.ru/;child-src 'self' yandex.st yandex.ru null passport.yandex.ru pass.yandex.ru https://trust.yandex.ru blob: mc.yandex.ru;report-uri https://csp.yandex.net/csp?from=passport&project=passport&yandex_login=&yandex"
		"uid={yu}\",\"disposition\":\"enforce\",\"blocked-uri\":\"https://mail.yandex.ru/u2709/favicon/png/main-favicon/16/0.png\",\"line-number\":1,\"source-file\":\"https://passport.yandex.ru/auth\",\"status-code\":200,\"script-sample\":\"\"}}",
		LAST);

	lr_think_time(10);

	web_custom_request("csp_2",
		"URL=https://csp.yandex.net/csp?from=passport&project=passport&yandex_login=&yandexuid={yu}",
		"Method=POST",
		"TargetFrame=",
		"Resource=0",
		"Referer=https://passport.yandex.ru/",
		"Snapshot=t277.inf",
		"Mode=HTML",
		"EncType=application/csp-report",
		"Body={\"csp-report\":{\"document-uri\":\"https://passport.yandex.ru/auth?from=mail&origin=hostroot_homer_auth_L_ru&retpath=https%3A%2F%2Fmail.yandex.ru%2F&backpath=https%3A%2F%2Fmail.yandex.ru%3Fnoretpath%3D1\",\"referrer\":\"https://mail.yandex.ru/\",\"violated-directive\":\"img-src\",\"effective-directive\":\"img-src\",\"original-policy\":\"default-src 'none';style-src 'self' yastatic.net 'unsafe-inline' 'unsafe-eval' s3.mds.yandex.net s3.mdst.yandex.net;script-src 'self' yastatic.net mc.admetrica.ru mc.yandex.ru chat.s3.yandex.net api-maps.yandex.ru suggest-maps.yandex.net export.yandex.ru 'unsafe-eval' 'unsafe-inline' 'nonce-{CorrelationParameter_3}' https://yandex.ru/global-notifications/butterfly/stable/butterfly.js;img-src 'self' yastatic.net https://ysa-static.passport.yandex.ru https://ysa-static.passport.yandex.net yandex.st data: mc.admetrica.ru mc.yandex.ru api-maps.yandex.ru *.captcha.yandex.net s3.mds.yandex.net s3.mdst.yandex.net avatars.mds.yandex.net avatars.mdst.yandex.net clck."
		"yandex.ru *.maps.yandex.net yapic.yandex.ru img.yandex.ru static-maps.yandex.ru https://video-tub-ru.yandex.net https://img0-tub-ru.yandex.net https://img1-tub-ru.yandex.net https://img2-tub-ru.yandex.net https://img3-tub-ru.yandex.net blob:  mc.webvisor.com mc.webvisor.org;font-src 'self' data: yastatic.net;object-src yastatic.net;media-src *.captcha.yandex.net data:;connect-src mail.yandex.ru 'self' mc.admetrica.ru mc.yandex.ru trust.yandex.ru suggest-maps.yandex.net mc.webvisor.com mc.webvisor.org yandex.ru api.passport.yandex.ru;frame-ancestors 'self';frame-src 'self' yandex.st s4.money.yandex.net https://yandex.ru/chat split.yandex.ru yandex.ru null pass.yandex.ru passport.yandex.ru https://trust.yandex.ru blob: mc.yandex.ru magic.passport.yandex.ru https://yandex.ru/forms https://forms.yandex.ru/;child-src 'self' yandex.st yandex.ru null passport.yandex.ru pass.yandex.ru https://trust.yandex.ru blob: mc.yandex.ru;report-uri https://csp.yandex.net/csp?from=passport&project=passport&yandex_login=&yandex"
		"uid={yu}\",\"disposition\":\"enforce\",\"blocked-uri\":\"https://mail.yandex.ru/u2709/favicon/png/main-favicon/32/0.png\",\"line-number\":1,\"source-file\":\"https://passport.yandex.ru/auth\",\"status-code\":200,\"script-sample\":\"\"}}",
		LAST);
	
	lr_end_transaction("5_logout_NM",LR_AUTO);
	

	return 0;
}

Action()
{
	curSec = showCurrentSecDigit(x);
	lr_save_int(curSec, "ALLSECDATE");
	
	lr_start_transaction("1_main_NMSG");
	


	web_set_sockets_option("SSL_VERSION", "AUTO");

/*Correlation comment - Do not change!  Original value='908543471641556456' Name ='yu' Type ='ResponseBased'*/
	web_reg_save_param_regexp(
		"ParamName=yu",
		"RegExp=yandexuid=(.*?);",
		LAST);

/*Correlation comment: Automatic rules - Do not change!  
Original value='3377a4b1613f3af54afdbb0c64c93d391b8e21b9:1641556456146' 
Name ='csrf_token' 
Type ='Manual'*/
	web_reg_save_param_regexp(
		"ParamName=csrf_token",
		"RegExp=csrf_token\"\\ value=\"(.*?)\"",
		LAST);

/*Correlation comment: Automatic rules - Do not change!  
Original value='dd6be570-70c7-4e83-9346-9025f64695a2' 
Name ='process_uuid' 
Type ='ResponseBased'*/
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
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);



	lr_end_transaction("1_main_NMSG",LR_AUTO);


	lr_start_transaction("2_login_NMSG");



	/*Possible OAUTH authorization was detected. It is recommended to correlate the authorization parameters.*/

/*Correlation comment - Do not change!  Original value='8394bc51edfa4621c9c42dd7a51b468229' Name ='track_id' Type ='Manual'*/
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
		"Snapshot=t13.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=csrf_token", "Value={csrf_token}", ENDITEM,
		"Name=login", "Value={login}", ENDITEM,
		"Name=process_uuid", "Value={process_uuid}", ENDITEM,
		LAST);
	
	lr_think_time(10);

/*Correlation comment - Do not change!  Original value='1431766764' Name ='uid' Type ='ResponseBased'*/
	web_reg_save_param_regexp(
		"ParamName=uid",
		"RegExp=X-Default-UID:\\ (.*?)\\\r\\\n",
		SEARCH_FILTERS,
		"Scope=Headers",
		"IgnoreRedirections=No",
		LAST);

	web_submit_data("commit_password",
		"Action=https://passport.yandex.ru/registration-validations/auth/multi_step/commit_password",
		"Method=POST",
		"TargetFrame=",
		"RecContentType=application/json",
		"Referer=https://passport.yandex.ru/",
		"Snapshot=t22.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=csrf_token", "Value={csrf_token}", ENDITEM,
		"Name=track_id", "Value={track_id}", ENDITEM,
		"Name=password", "Value={pass}", ENDITEM,
		"Name=retpath", "Value=https://passport.yandex.ru/profile", ENDITEM,
		LAST);
	


/*Correlation comment - Do not change!  Original value='9421fc0ce555b929bc76ff6da65bb98314f5e5d5:1641556493086' Name ='csrf_token_1' Type ='Manual'*/
	web_reg_save_param_json(
		"ParamName=csrf_token_1",
		"QueryString=$.csrf",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=No",
		LAST);

	web_submit_data("accounts",
		"Action=https://passport.yandex.ru/registration-validations/auth/accounts",
		"Method=POST",
		"TargetFrame=",
		"RecContentType=application/json",
		"Referer=https://passport.yandex.ru/",
		"Snapshot=t24.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=csrf_token", "Value={csrf_token}", ENDITEM,
		LAST);

	web_submit_data("ask_v2",
		"Action=https://passport.yandex.ru/registration-validations/auth/additional_data/ask_v2",
		"Method=POST",
		"TargetFrame=",
		"RecContentType=application/json",
		"Referer=https://passport.yandex.ru/",
		"Snapshot=t25.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=csrf_token", "Value={csrf_token_1}", ENDITEM,
		"Name=uid", "Value={uid}", ENDITEM,
		LAST);

	web_url("redirect", 
		"URL=https://passport.yandex.ru/redirect?url=https%3A%2F%2Fpassport.yandex.ru%2Fprofile", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://passport.yandex.ru/", 
		"Snapshot=t27.inf", 
		"Mode=HTML", 
		LAST);


	lr_end_transaction("2_login_NMSG",LR_AUTO);

	lr_start_transaction("3_inPost_NMSG");

/*Correlation comment: Automatic rules - Do not change!  
Original value='Toyxb8ctUmT1zul2kkOJj98PhcE=!ky5rt2rv' 
Name ='CorrelationParameter' 
Type ='Manual'*/
	web_reg_save_param_regexp(
		"ParamName=CorrelationParameter",
		"RegExp=ckey\":\"(.*?)\"",
		LAST);

/*Correlation comment - Do not change!  Original value='LIZA-95430491-1641556518451' Name ='_connection_id' Type ='Manual'*/
	web_reg_save_param_regexp(
		"ParamName=_connection_id",
		"RegExp=reqid=(.*?);",
		LAST);

	web_url("mail.yandex.ru", 
		"URL=https://mail.yandex.ru/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://passport.yandex.ru/", 
		"Snapshot=t45.inf", 
		"Mode=HTML", 
		LAST);

	web_convert_param("CorrelationParameter_URL1",
		"SourceString={CorrelationParameter}",
		"SourceEncoding=HTML",
		"TargetEncoding=URL",
		LAST);

	
	web_url("1_12", 
		"URL=https://an.yandex.ru/jserr/1", 
		"TargetFrame=", 
		"Resource=0", 
		"Referer=https://mail.yandex.ru/", 
		"Snapshot=t65.inf", 
		"Mode=HTML", 
		LAST);


	lr_end_transaction("3_inPost_NMSG",LR_AUTO);


	lr_start_transaction("4_mess");
	
	web_reg_find("Search=Body",
		"Text=endbernar\"\:\{\"status\"\:\"ok",
		LAST);	

	web_custom_request("liza1_45",
		"URL=https://mail.yandex.ru/web-api/do-send/liza1?_send=true",
		"Method=POST",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=application/json",
		"Referer=https://mail.yandex.ru/",
		"Snapshot=t138.inf",
		"Mode=HTML",
		"Body=&bcc=&captcha_entered=&captcha_key=&cc=&charset=&confirm_limit=&current_folder=6&doit=&fid=&from_mailbox={from}&from_name=C%D0%B0%D1%88%D0%B0%20%D0%9C%D0%B0%D0%BA%D0%B0%D1%80%D0%BE%D0%B2&get_abook=&html=&idcs=&&ign_overwrite=no&initial_cc=&initial_to=&inreplyto=&&mark_as=&&disk_att=&nosave=&nosend=&notify_on_send=no&overwrite=178173660257845346&&phone=&references=&remind_period=&retpath=&returl=&saveDraft=&save_symbol=draft&send=%3Cdiv%3E{date}{cent}{cent_2}test{ALLSECDATE}%3C%2Fdiv%3E&send_time=&store_fid=&store_name=&strict_charset=&style=&subj=&to=%22aleksandr.makarov.1995%40mail.ru%22%20%3Caleksandr.makarov.1995%40mail.ru%3E&ttype=html&withUpdatedUndoAndDelayedErrorHandling=yes&_connection_id={_connection_id}&_ckey={CorrelationParameter_URL1}&_uid={uid}&_eexp=335955%2C0%2C-1%3B419150%2C0%2C-1%3B473828%2C0%2C-1%3B412205%2C0%2C-1%3B457741%2C0%2C-1%3B462916%2C0%2C79%3B451868%2C0%2C63%3B404892%2C0%2C31%3B406173%2C0%2C24%3B380961%2C0%2C91%3B428729%2C0%2C34%3B475161%2C0%2C73%3B261659%2C0%2C32%3B118737%2C0%2C52%3B4"
		"06512%2C0%2C46%3B456408%2C0%2C65%3B453083%2C0%2C38%3B286809%2C0%2C8%3B300740%2C0%2C15%3B317929%2C0%2C61%3B416853%2C0%2C6%3B383125%2C0%2C19%3B399880%2C0%2C7%3B358334%2C0%2C75%3B367504%2C0%2C64%3B262911%2C0%2C86%3B381544%2C0%2C97%3B227595%2C0%2C55&message_id=%3C4220181641556539%40mail.yandex.ru%3E&current_time=&parts_json=",
		LAST);
	
	lr_think_time(10);
	
	lr_end_transaction("4_mess",LR_AUTO);


	lr_start_transaction("5_logout_NMSG");
	
	web_reg_find("Search=Body",
		"Text=Войдите с Яндекс ID",
		LAST);

/*Correlation comment - Do not change!  Original value='f23df61a-5c7a-43d6-bd50-71b0961e7d57' Name ='CorrelationParameter_1' Type ='Manual'*/
	web_reg_save_param_regexp(
		"ParamName=CorrelationParameter_1",
		"RegExp=nonce-(.*?)",
		LAST);

	web_url("passport",
		"URL=https://passport.yandex.ru/passport?mode=embeddedauth&action=logout&yu={yu}&uid={uid}&origin=&retpath=https%3A%2F%2Fmail.yandex.ru&",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=text/html",
		"Referer=https://mail.yandex.ru/",
		"Snapshot=t179.inf",
		"Mode=HTML",
		LAST);

	web_custom_request("csp",
		"URL=https://csp.yandex.net/csp?from=passport&project=passport&yandex_login=&yandexuid={yu}",
		"Method=POST",
		"TargetFrame=",
		"Resource=0",
		"Referer=https://passport.yandex.ru/",
		"Snapshot=t180.inf",
		"Mode=HTML",
		"EncType=application/csp-report",
		"Body={\"csp-report\":{\"document-uri\":\"https://passport.yandex.ru/auth?from=mail&origin=hostroot_homer_auth_L_ru&retpath=https%3A%2F%2Fmail.yandex.ru%2F&backpath=https%3A%2F%2Fmail.yandex.ru%3Fnoretpath%3D1\",\"referrer\":\"https://mail.yandex.ru/\",\"violated-directive\":\"img-src\",\"effective-directive\":\"img-src\",\"original-policy\":\"default-src 'none';style-src 'self' yastatic.net 'unsafe-inline' 'unsafe-eval' s3.mds.yandex.net s3.mdst.yandex.net;script-src 'self' yastatic.net mc.admetrica.ru mc.yandex.ru chat.s3.yandex.net api-maps.yandex.ru suggest-maps.yandex.net export.yandex.ru 'unsafe-eval' 'unsafe-inline' 'nonce-{CorrelationParameter_1}' https://yandex.ru/global-notifications/butterfly/stable/butterfly.js;img-src 'self' yastatic.net https://ysa-static.passport.yandex.ru https://ysa-static.passport.yandex.net yandex.st data: mc.admetrica.ru mc.yandex.ru api-maps.yandex.ru *.captcha.yandex.net s3.mds.yandex.net s3.mdst.yandex.net avatars.mds.yandex.net avatars.mdst.yandex.net clck.yandex.ru *."
		"maps.yandex.net yapic.yandex.ru img.yandex.ru static-maps.yandex.ru https://video-tub-ru.yandex.net https://img0-tub-ru.yandex.net https://img1-tub-ru.yandex.net https://img2-tub-ru.yandex.net https://img3-tub-ru.yandex.net blob:  mc.webvisor.com mc.webvisor.org;font-src 'self' data: yastatic.net;object-src yastatic.net;media-src *.captcha.yandex.net data:;connect-src mail.yandex.ru 'self' mc.admetrica.ru mc.yandex.ru trust.yandex.ru suggest-maps.yandex.net mc.webvisor.com mc.webvisor.org yandex.ru api.passport.yandex.ru;frame-ancestors 'self';frame-src 'self' yandex.st s4.money.yandex.net https://yandex.ru/chat split.yandex.ru yandex.ru null pass.yandex.ru passport.yandex.ru https://trust.yandex.ru blob: mc.yandex.ru magic.passport.yandex.ru https://yandex.ru/forms https://forms.yandex.ru/;child-src 'self' yandex.st yandex.ru null passport.yandex.ru pass.yandex.ru https://trust.yandex.ru blob: mc.yandex.ru;report-uri https://csp.yandex.net/csp?from=passport&project=passport&yandex_login=&yandexuid={yu}\","
		"\"disposition\":\"enforce\",\"blocked-uri\":\"https://mail.yandex.ru/u2709/favicon/png/main-favicon/16/0.png\",\"status-code\":200,\"script-sample\":\"\"}}",
		LAST);
		
lr_think_time(10);

	web_custom_request("csp_2",
		"URL=https://csp.yandex.net/csp?from=passport&project=passport&yandex_login=&yandexuid={yu}",
		"Method=POST",
		"TargetFrame=",
		"Resource=0",
		"Referer=https://passport.yandex.ru/",
		"Snapshot=t181.inf",
		"Mode=HTML",
		"EncType=application/csp-report",
		"Body={\"csp-report\":{\"document-uri\":\"https://passport.yandex.ru/auth?from=mail&origin=hostroot_homer_auth_L_ru&retpath=https%3A%2F%2Fmail.yandex.ru%2F&backpath=https%3A%2F%2Fmail.yandex.ru%3Fnoretpath%3D1\",\"referrer\":\"https://mail.yandex.ru/\",\"violated-directive\":\"img-src\",\"effective-directive\":\"img-src\",\"original-policy\":\"default-src 'none';style-src 'self' yastatic.net 'unsafe-inline' 'unsafe-eval' s3.mds.yandex.net s3.mdst.yandex.net;script-src 'self' yastatic.net mc.admetrica.ru mc.yandex.ru chat.s3.yandex.net api-maps.yandex.ru suggest-maps.yandex.net export.yandex.ru 'unsafe-eval' 'unsafe-inline' 'nonce-{CorrelationParameter_1}' https://yandex.ru/global-notifications/butterfly/stable/butterfly.js;img-src 'self' yastatic.net https://ysa-static.passport.yandex.ru https://ysa-static.passport.yandex.net yandex.st data: mc.admetrica.ru mc.yandex.ru api-maps.yandex.ru *.captcha.yandex.net s3.mds.yandex.net s3.mdst.yandex.net avatars.mds.yandex.net avatars.mdst.yandex.net clck.yandex.ru *."
		"maps.yandex.net yapic.yandex.ru img.yandex.ru static-maps.yandex.ru https://video-tub-ru.yandex.net https://img0-tub-ru.yandex.net https://img1-tub-ru.yandex.net https://img2-tub-ru.yandex.net https://img3-tub-ru.yandex.net blob:  mc.webvisor.com mc.webvisor.org;font-src 'self' data: yastatic.net;object-src yastatic.net;media-src *.captcha.yandex.net data:;connect-src mail.yandex.ru 'self' mc.admetrica.ru mc.yandex.ru trust.yandex.ru suggest-maps.yandex.net mc.webvisor.com mc.webvisor.org yandex.ru api.passport.yandex.ru;frame-ancestors 'self';frame-src 'self' yandex.st s4.money.yandex.net https://yandex.ru/chat split.yandex.ru yandex.ru null pass.yandex.ru passport.yandex.ru https://trust.yandex.ru blob: mc.yandex.ru magic.passport.yandex.ru https://yandex.ru/forms https://forms.yandex.ru/;child-src 'self' yandex.st yandex.ru null passport.yandex.ru pass.yandex.ru https://trust.yandex.ru blob: mc.yandex.ru;report-uri https://csp.yandex.net/csp?from=passport&project=passport&yandex_login=&yandexuid={yu}\","
		"\"disposition\":\"enforce\",\"blocked-uri\":\"https://mail.yandex.ru/u2709/favicon/png/main-favicon/32/0.png\",\"status-code\":200,\"script-sample\":\"\"}}",
		LAST);
	lr_end_transaction("5_logout_NMSG",LR_AUTO);

	return 0;
}

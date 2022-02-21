Action()
{

	lr_start_transaction("1_transaction");
	
	//1) ������ ������ ������������� ���� ���������� ���� "���������: 13 ��� 19". �������� � ��������� � �������� ����
	//�������� �� 3 ���������, dd - ����, mm - �����, yy -���
	web_reg_save_param_regexp(
		"ParamName=dd",
		"RegExp=(\\d{2})&nbsp;(.*?)&nbsp;(\\d{2})",
		"Group=1",
		LAST);
	
	web_reg_save_param_regexp(
		"ParamName=mm",
		"RegExp=(\\d{2})&nbsp;(.*?)&nbsp;(\\d{2})",
		"Group=2",
		LAST);
	
	web_reg_save_param_regexp(
		"ParamName=yy",
		"RegExp=(\\d{2})&nbsp;(.*?)&nbsp;(\\d{2})",
		"Group=3",
		LAST);
	//2 - ���������� ������������ �� ���������
	
	web_reg_save_param_regexp(
		"ParamName=comment_count",
		"RegExp=\\s(\\d{1})<",
		"Group=1",
		LAST);
	// 3 ����� ������� �����������
	
	web_reg_save_param_regexp(
		"ParamName=text_first_comment",
		"RegExp=Goras\<\/b>\\r\\n\\s+<\/div>\\r\\n\\s\+\<div class\=\"post\"\>\\r\\n\\s\+\<p\>(.*?)\<\/p\>",
		"Ordinal=1",
		LAST);
	
	// 4) ��� ������������ ����������� ������ �����������
	
	web_reg_save_param_regexp(
		"ParamName=first_author",
		"RegExp=\<b class\=\"author\"\>(.*?)\<\/b\>",
		"Ordinal=1",
		LAST);

	//5) ��� ����� �������������, ���������� �����������
	
	web_reg_save_param_regexp(
		"ParamName=all_author",
		"RegExp=\<b class\=\"author\"\>(.*?)\<\/b\>",
		"Ordinal=ALL",
		LAST);	
	
	// 6 ������, ������� ����� ��� ������� "�����������������"

	web_reg_save_param_regexp(
		"ParamName=link_comment",
		"RegExp=\<a href\=\"(.*?)\"\\sclass\=\"comment\"",
		"Ordinal=ALL",
		LAST);		
	
		
	//7 ����� ���� ����� (����� ������ "����")
	
	web_reg_save_param_regexp(
		"ParamName=all_tags",
		"RegExp=\\r\\n\\s\+\<a href\=\"\/blogs\/iyun\/tags\/\.\+\>(.*?)\<\/a\>",
		"Ordinal=ALL",
		LAST);			


	web_set_sockets_option("SSL_VERSION", "AUTO");

	web_url("2267", 
		"URL=https://www.sql.ru/blogs/iyun/2267", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);



	lr_end_transaction("1_transaction",LR_AUTO);

	return 0;
}
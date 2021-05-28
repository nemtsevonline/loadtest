Action()
{
	lr_start_transaction("Deleting_ticket");

	web_reg_find("Text=Web Tours",
        LAST);

	lr_start_transaction("Web_tours");

	web_set_sockets_option("SSL_VERSION", "AUTO");

	web_add_auto_header("Sec-Fetch-Site", 
		"none");

	web_add_auto_header("Sec-Fetch-Dest", 
		"document");

	web_add_auto_header("Sec-Fetch-Mode", 
		"navigate");

	web_add_auto_header("Sec-Fetch-User", 
		"?1");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");

	web_add_auto_header("sec-ch-ua", 
		"\" Not;A Brand\";v=\"99\", \"Google Chrome\";v=\"91\", \"Chromium\";v=\"91\"");

	web_add_auto_header("sec-ch-ua-mobile", 
		"?0");

/*Correlation comment - Do not change!  Original value='131406.335358445zHfQcVDpDHftAfffpciAcf' Name ='userSession' Type ='ResponseBased'*/
	web_reg_save_param_attrib(
		"ParamName=userSession",
		"TagName=input",
		"Extract=value",
		"Name=userSession",
		"Type=hidden",
		SEARCH_FILTERS,
		"IgnoreRedirections=No",
		"RequestUrl=*/nav.pl*",
		LAST);

	web_url("WebTours", 
		"URL=http://localhost:1080/WebTours/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("Web_tours",LR_AUTO);
	
	web_reg_find("Text=User password was correct",
        LAST);

	lr_start_transaction("Login");

	web_revert_auto_header("Sec-Fetch-User");

	web_add_auto_header("Sec-Fetch-Dest", 
		"frame");

	web_revert_auto_header("Upgrade-Insecure-Requests");

	web_add_header("Origin", 
		"http://localhost:1080");

	web_add_auto_header("Sec-Fetch-Site", 
		"same-origin");

	lr_think_time(22);

/*Correlation comment - Do not change!  Original value='itinerary' Name ='page' Type ='ResponseBased'*/
	web_reg_save_param_regexp(
		"ParamName=page",
		"RegExp=page=(.*?)\"\\ TARGET",
		"Ordinal=2",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=No",
		"RequestUrl=*/nav.pl*",
		LAST);

	web_submit_data("login.pl",
		"Action=http://localhost:1080/cgi-bin/login.pl",
		"Method=POST",
		"TargetFrame=body",
		"RecContentType=text/html",
		"Referer=http://localhost:1080/cgi-bin/nav.pl?in=home",
		"Snapshot=t2.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=userSession", "Value={userSession}", ENDITEM,
		"Name=username", "Value=Jo", ENDITEM,
		"Name=password", "Value=123", ENDITEM,
		"Name=login.x", "Value=60", ENDITEM,
		"Name=login.y", "Value=8", ENDITEM,
		"Name=JSFormSubmit", "Value=off", ENDITEM,
		LAST);

	lr_end_transaction("Login",LR_AUTO);
	
	web_reg_find("Text= User wants the intineraries",
		LAST);

	lr_start_transaction("Itinerary");

	web_add_auto_header("Sec-Fetch-User", 
		"?1");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");

	lr_think_time(42);

/*Correlation comment - Do not change!  Original value='251444829-798-JJ' Name ='flightID' Type ='ResponseBased'*/
	web_reg_save_param_attrib(
		"ParamName=flightID",
		"TagName=input",
		"Extract=value",
		"Name=flightID",
		"Type=hidden",
		SEARCH_FILTERS,
		"IgnoreRedirections=No",
		"RequestUrl=*/{page}.pl*",
		LAST);

	web_url("Itinerary Button",
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page={page}",
		"TargetFrame=body",
		"Resource=0",
		"RecContentType=text/html",
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home",
		"Snapshot=t3.inf",
		"Mode=HTML",
		LAST);

	lr_end_transaction("Itinerary",LR_AUTO);
	

	lr_start_transaction("Cancel");

	web_add_header("Origin", 
		"http://localhost:1080");

	lr_think_time(20);

	web_submit_data("itinerary.pl",
		"Action=http://localhost:1080/cgi-bin/{page}.pl",
		"Method=POST",
		"TargetFrame=",
		"RecContentType=text/html",
		"Referer=http://localhost:1080/cgi-bin/{page}.pl",
		"Snapshot=t4.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=flightID", "Value={flightID}", ENDITEM,
		"Name=removeAllFlights.x", "Value=56", ENDITEM,
		"Name=removeAllFlights.y", "Value=5", ENDITEM,
		"Name=.cgifields", "Value=1", ENDITEM,
		LAST);

	lr_end_transaction("Cancel",LR_AUTO);
	
	web_reg_find("Text=Web Tours",
        LAST);

	lr_start_transaction("Log_out");

	web_revert_auto_header("Sec-Fetch-User");

	web_add_header("Sec-Fetch-User", 
		"?1");

	lr_think_time(30);

	web_url("SignOff Button",
		"URL=http://localhost:1080/cgi-bin/welcome.pl?signOff=1",
		"TargetFrame=body",
		"Resource=0",
		"RecContentType=text/html",
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in={page}",
		"Snapshot=t5.inf",
		"Mode=HTML",
		LAST);

	lr_end_transaction("Log_out",LR_AUTO);
	
	lr_end_transaction("Deleting_ticket", LR_AUTO);


	return 0;
}
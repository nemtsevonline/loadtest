Action()
{
	
	
	int flight_count_before = 0;
	int flight_count_after = 0;
	int i;
	int j;
	
	lr_start_transaction("5_Deleting_ticket");

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
		
	web_reg_find("Text=Web Tours",
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
	
	web_reg_find("Text=User password was correct",
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
		"Name=username", "Value={login}", ENDITEM,
		"Name=password", "Value={password}", ENDITEM,
		"Name=login.x", "Value=60", ENDITEM,
		"Name=login.y", "Value=8", ENDITEM,
		"Name=JSFormSubmit", "Value=off", ENDITEM,
		LAST);

	lr_end_transaction("Login",LR_AUTO);
	
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
		"RequestUrl=*/itinerary.pl*",
		LAST);
		
		web_reg_save_param("flight_ID_origin",
		"LB=name=\"flightID\" value=\"",
		"RB=-",
		"Ord=ALL",
		LAST);
		
	web_reg_find("Text= User wants the intineraries",
		LAST);


	web_url("Itinerary Button",
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=itinerary",
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

	web_add_header("Sec-Fetch-Dest", 
		"frame");

	web_add_header("Sec-Fetch-Mode", 
		"navigate");

	web_add_header("Sec-Fetch-Site", 
		"same-origin");

	web_add_header("Sec-Fetch-User", 
		"?1");

	web_add_header("Upgrade-Insecure-Requests", 
		"1");

	web_add_header("sec-ch-ua", 
		"\" Not;A Brand\";v=\"99\", \"Google Chrome\";v=\"91\", \"Chromium\";v=\"91\"");

	web_add_header("sec-ch-ua-mobile", 
		"?0");

	lr_think_time(32);
	
	web_reg_save_param("flight_ID",
		"LB=name=\"flightID\" value=\"",
		"RB=-",
		"Ord=ALL",
		LAST);
	
	web_reg_find("Text=Flights List",
		LAST);
	
	web_reg_find("Fail=Found",
	             "Text=Flights_ID_origin_1})",
		LAST);

	web_submit_form("itinerary.pl", 
		"Snapshot=t16.inf", 
		ITEMDATA, 
		"Name=1", "Value=on", ENDITEM, 
		"Name=removeFlights.x", "Value=65", ENDITEM, 
		"Name=removeFlights.y", "Value=9", ENDITEM, 
		LAST);
	

//	flight_count_before = atoi(lr_eval_string("{flight_ID_origin_count}"));
//	flight_count_after = atoi(lr_eval_string("{flight_ID_count}"));
//	lr_message("Броней до: %i, Броней после: %i", flight_count_before, flight_count_after);
//
//	for (j=0; j < flight_count_before; j++){
//	           	i = strcmp(lr_eval_string("{flight_ID_origin_1}"), lr_paramarr_idx("{flight_ID}", j));
//		if (i != 0){
//	           		lr_end_transaction("Cancel",LR_FAIL);
//	           	}}
	
	lr_end_transaction("Cancel",LR_AUTO);
		
	
	lr_message("До удаления - %s", lr_eval_string("{flight_ID_origin_count}"));
	lr_message("После удаления - %s", lr_eval_string("{flight_ID_count}"));

	lr_start_transaction("Log_out");

	web_revert_auto_header("Sec-Fetch-User");

	web_add_header("Sec-Fetch-User", 
		"?1");

	lr_think_time(30);

	web_reg_find("Text=Web Tours",
        LAST);
	
	web_url("SignOff Button",
		"URL=http://localhost:1080/cgi-bin/welcome.pl?signOff=1",
		"TargetFrame=body",
		"Resource=0",
		"RecContentType=text/html",
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=itinerary",
		"Snapshot=t5.inf",
		"Mode=HTML",
		LAST);

	lr_end_transaction("Log_out",LR_AUTO);
	
	lr_end_transaction("5_Deleting_ticket", LR_AUTO);

	return 0;
}
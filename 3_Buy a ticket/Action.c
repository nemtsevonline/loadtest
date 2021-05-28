Action()
{
	lr_start_transaction("Buy_a_ticket");

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

/*Correlation comment - Do not change!  Original value='131405.135358445zHfQVfVpzftAfftpQAQQ' Name ='userSession' Type ='ResponseBased'*/
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

	lr_think_time(32);

/*Correlation comment - Do not change!  Original value='welcome' Name ='page' Type ='ResponseBased'*/
	web_reg_save_param_regexp(
		"ParamName=page",
		"RegExp=A\\ HREF=\"(.*?)\\.pl",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=No",
		"RequestUrl=*/nav.pl*",
		LAST);

/*Correlation comment - Do not change!  Original value='flights' Name ='in' Type ='ResponseBased'*/
	web_reg_save_param_regexp(
		"ParamName=in",
		"RegExp=images/(.*?)\\.gif",
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
		"Name=login.x", "Value=58", ENDITEM,
		"Name=login.y", "Value=12", ENDITEM,
		"Name=JSFormSubmit", "Value=off", ENDITEM,
		LAST);

	lr_end_transaction("Login",LR_AUTO);
	
	web_reg_find("Text=User has returned to the search page",
		LAST);

	lr_start_transaction("Flights");

	web_add_auto_header("Sec-Fetch-User", 
		"?1");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");

	lr_think_time(35);

/*Correlation comment - Do not change!  Original value='roundtrip' Name ='.cgifields' Type ='ResponseBased'*/
	web_reg_save_param_attrib(
		"ParamName=.cgifields",
		"TagName=input",
		"Extract=name",
		"Type=checkbox",
		SEARCH_FILTERS,
		"IgnoreRedirections=No",
		"RequestUrl=*/reservations.pl*",
		LAST);

/*Correlation comment - Do not change!  Original value='seatPref' Name ='Name' Type ='ResponseBased'*/
	web_reg_save_param_attrib(
		"ParamName=Name",
		"TagName=input",
		"Extract=name",
		"Type=radio",
		SEARCH_FILTERS,
		"IgnoreRedirections=No",
		"RequestUrl=*/reservations.pl*",
		LAST);

/*Correlation comment - Do not change!  Original value='seatType' Name ='Name_1' Type ='ResponseBased'*/
	web_reg_save_param_attrib(
		"ParamName=Name_1",
		"TagName=input",
		"Extract=name",
		"Type=radio",
		SEARCH_FILTERS,
		"IgnoreRedirections=No",
		"RequestUrl=*/reservations.pl*",
		LAST);

	web_url("Search Flights Button",
		"URL=http://localhost:1080/cgi-bin/{page}.pl?page=search",
		"TargetFrame=body",
		"Resource=0",
		"RecContentType=text/html",
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home",
		"Snapshot=t3.inf",
		"Mode=HTML",
		LAST);

	lr_end_transaction("Flights",LR_AUTO);
	
	web_reg_find("Text=Flight Selections",
		LAST);

	lr_start_transaction("Find_flight");

	web_add_auto_header("Origin", 
		"http://localhost:1080");

	lr_think_time(52);

/*Correlation comment - Do not change!  Original value='120;266;05/30/2021' Name ='outboundFlight' Type ='ResponseBased'*/
	web_reg_save_param_attrib(
		"ParamName=outboundFlight",
		"TagName=input",
		"Extract=value",
		"Name=outboundFlight",
		"Type=radio",
		SEARCH_FILTERS,
		"IgnoreRedirections=No",
		LAST);

	web_submit_data("reservations.pl",
		"Action=http://localhost:1080/cgi-bin/reservations.pl",
		"Method=POST",
		"TargetFrame=",
		"RecContentType=text/html",
		"Referer=http://localhost:1080/cgi-bin/reservations.pl?page={page}",
		"Snapshot=t4.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=advanceDiscount", "Value=0", ENDITEM,
		"Name=depart", "Value={depart}", ENDITEM,
		"Name=departDate", "Value={data1}", ENDITEM,
		"Name=arrive", "Value={arrive}", ENDITEM,
		"Name=returnDate", "Value={data2}", ENDITEM,
		"Name=numPassengers", "Value={num}", ENDITEM,
		"Name={Name}", "Value=None", ENDITEM,
		"Name={Name_1}", "Value=Coach", ENDITEM,
		"Name=findFlights.x", "Value=48", ENDITEM,
		"Name=findFlights.y", "Value=7", ENDITEM,
		"Name=.cgifields", "Value={.cgifields}", ENDITEM,
		"Name=.cgifields", "Value={Name_1}", ENDITEM,
		"Name=.cgifields", "Value={Name}", ENDITEM,
		LAST);

	lr_end_transaction("Find_flight",LR_AUTO);

	lr_think_time(48);
	
	web_reg_find("Text=Flight Reservation",
		LAST);

	lr_start_transaction("Choice");

	web_submit_data("reservations.pl_2",
		"Action=http://localhost:1080/cgi-bin/reservations.pl",
		"Method=POST",
		"TargetFrame=",
		"RecContentType=text/html",
		"Referer=http://localhost:1080/cgi-bin/reservations.pl",
		"Snapshot=t5.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=outboundFlight", "Value={outboundFlight}", ENDITEM,
		"Name=numPassengers", "Value=1", ENDITEM,
		"Name=advanceDiscount", "Value=0", ENDITEM,
		"Name={Name_1}", "Value=Coach", ENDITEM,
		"Name={Name}", "Value=None", ENDITEM,
		"Name=reserveFlights.x", "Value=34", ENDITEM,
		"Name=reserveFlights.y", "Value=9", ENDITEM,
		LAST);

	lr_end_transaction("Choice",LR_AUTO);
	
	web_reg_find("Text=Reservation Made",
		LAST);

	lr_start_transaction("Payment_details");

	web_revert_auto_header("Origin");

	web_revert_auto_header("Sec-Fetch-User");

	web_revert_auto_header("Upgrade-Insecure-Requests");

	web_add_header("Origin", 
		"http://localhost:1080");

	lr_think_time(34);

	web_submit_data("reservations.pl_3",
		"Action=http://localhost:1080/cgi-bin/reservations.pl",
		"Method=POST",
		"TargetFrame=",
		"RecContentType=text/html",
		"Referer=http://localhost:1080/cgi-bin/reservations.pl",
		"Snapshot=t6.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=firstName", "Value=Jo", ENDITEM,
		"Name=lastName", "Value=Jo", ENDITEM,
		"Name=address1", "Value=Jo", ENDITEM,
		"Name=address2", "Value=Jo", ENDITEM,
		"Name=pass1", "Value=Jo Jo", ENDITEM,
		"Name=creditCard", "Value=creditCard={creditCard}", ENDITEM,
		"Name=expDate", "Value={expdate}", ENDITEM,
		"Name=oldCCOption", "Value=", ENDITEM,
		"Name=numPassengers", "Value=1", ENDITEM,
		"Name={Name_1}", "Value=Coach", ENDITEM,
		"Name={Name}", "Value=None", ENDITEM,
		"Name=outboundFlight", "Value={outboundFlight}", ENDITEM,
		"Name=advanceDiscount", "Value=0", ENDITEM,
		"Name=returnFlight", "Value=", ENDITEM,
		"Name=JSFormSubmit", "Value=off", ENDITEM,
		"Name=buyFlights.x", "Value=16", ENDITEM,
		"Name=buyFlights.y", "Value=7", ENDITEM,
		"Name=.cgifields", "Value=saveCC", ENDITEM,
		LAST);

	lr_end_transaction("Payment_details",LR_AUTO);
	
	web_reg_find("Text=Web Tours",
        LAST);

	lr_start_transaction("Log_out");

	web_add_header("Sec-Fetch-User", 
		"?1");

	web_add_header("Upgrade-Insecure-Requests", 
		"1");

	lr_think_time(38);

	web_url("SignOff Button",
		"URL=http://localhost:1080/cgi-bin/{page}.pl?signOff=1",
		"TargetFrame=body",
		"Resource=0",
		"RecContentType=text/html",
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in={in}",
		"Snapshot=t7.inf",
		"Mode=HTML",
		LAST);

	lr_end_transaction("Log_out",LR_AUTO);
	
lr_end_transaction("Buy_a_ticket", LR_AUTO);



	return 0;
}
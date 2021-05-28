Action()
{
	lr_start_transaction("Ticket_selection");
	
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

/*Correlation comment - Do not change!  Original value='131405.056865128zHfQVtHpzVcftAfftpiifzHf' Name ='userSession' Type ='ResponseBased'*/
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

	lr_think_time(15);

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
		"Name=login.x", "Value=56", ENDITEM,
		"Name=login.y", "Value=11", ENDITEM,
		"Name=JSFormSubmit", "Value=off", ENDITEM,
		LAST);

	lr_end_transaction("Login",LR_AUTO);
	
	web_reg_find("Text=User has returned to the search page",
		LAST);

	lr_start_transaction("flights");

	web_add_auto_header("Sec-Fetch-User", 
		"?1");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");

	lr_think_time(17);

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

	lr_end_transaction("flights",LR_AUTO);
	
	web_reg_find("Text=Flight Selections",
		LAST);

	lr_start_transaction("Find_flight");

	web_add_auto_header("Origin", 
		"http://localhost:1080");

	lr_think_time(32);

/*Correlation comment - Do not change!  Original value='120;266;05/29/2021' Name ='outboundFlight' Type ='ResponseBased'*/
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
		"Name=findFlights.x", "Value=59", ENDITEM,
		"Name=findFlights.y", "Value=8", ENDITEM,
		"Name=.cgifields", "Value={.cgifields}", ENDITEM,
		"Name=.cgifields", "Value={Name_1}", ENDITEM,
		"Name=.cgifields", "Value={Name}", ENDITEM,
		LAST);

	lr_end_transaction("Find_flight",LR_AUTO);

	lr_think_time(44);
	
	web_reg_find("Text=Flight Reservation",
		LAST);

	lr_start_transaction("Selection");

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
		"Name=reserveFlights.x", "Value=5", ENDITEM,
		"Name=reserveFlights.y", "Value=9", ENDITEM,
		LAST);

	lr_end_transaction("Selection",LR_AUTO);
	
	web_reg_find("Text=Web Tours",
        LAST);

	lr_start_transaction("Log_out");

	web_revert_auto_header("Origin");

	web_revert_auto_header("Sec-Fetch-User");

	lr_think_time(14);

	web_url("SignOff Button",
		"URL=http://localhost:1080/cgi-bin/{page}.pl?signOff=1",
		"TargetFrame=body",
		"Resource=0",
		"RecContentType=text/html",
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in={in}",
		"Snapshot=t6.inf",
		"Mode=HTML",
		LAST);

	lr_end_transaction("Log_out",LR_AUTO);
	
	lr_end_transaction("Ticket_selection", LR_AUTO);


	return 0;
}
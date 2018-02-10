<!--

function InputCheck(theForm,tmpChk) {
if (theForm.sSearchword.value.replace(/ /gi,"").length < 3) {
	alert("Please, You must input more than two characters !!");
	theForm.sSearchword.focus();
	return (false);
}
if (hanchk(theForm.sSearchword.value) == 2 ) {
	alert("Invalid search word! \nPlease use the alphabet, numbers, symbols(+,-,_./...).");
	theForm.sSearchword.focus();
	return (false);
}

if(tmpChk==1) theForm.action = "http://www.alldatasheet.net/view.jsp?Searchword=" + theForm.sSearchword.value.toUpperCase(); 
 else theForm.action = "http://category.alldatasheet.net/index.jsp?Searchword=" + theForm.sSearchword.value.toLowerCase();

theForm.sSearchword.value=theForm.sSearchword.value.toUpperCase();
theForm.seekcls.value='ON';
return(true);
}

function sda(data,tmpfileld) {
frmSearch.sSearchword.value = data;
frmSearch.sSort.value = 1;
frmSearch.sField.value = tmpfileld;
frmSearch.action='http://www.alldatasheet.net/view.jsp?Searchword=' + frmSearch.sSearchword.value.toUpperCase();
frmSearch.submit();
}
function semicoductor(got1,data,tmpfileld,got2) {
frmSearch.sSearchword.value = data;
frmSearch.sSort.value = 1;
frmSearch.sField.value = tmpfileld;
frmSearch.action='/view.jsp?Searchword=' + frmSearch.sSearchword.value.toUpperCase();
frmSearch.submit();
}

function components(got1,data,tmpfileld,got2) {
frmSearch.sSearchword.value = data;
frmSearch.sSort.value = 1;
frmSearch.sField.value = tmpfileld;
frmSearch.action='http://www.alldatasheet.net/view.jsp?Searchword=' + frmSearch.sSearchword.value.toUpperCase();
frmSearch.submit();
}
function hanchk(str){

   for(i = 0 ; i < str.length ;i++)
   {
      var code = str.charCodeAt(i);
      var ch= str.substr(i,1).toUpperCase();
      code= parseInt(code);
      if((ch < "0" || ch > "9") && (ch <"A" || ch >"Z") && ((code >255) || (code < 0)))
        return 2;
   }
	return 1;
}


//-->

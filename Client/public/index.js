function IniciarSesion() {
	var usuarioText = document.getElementById("textBox1").value;
	var passwordText = document.getElementById("textBox2").value;
	
	if(usuarioText == "ADMIN" && passwordText == "140918")
	{
		createCookie('usuario', usuarioText, 7);
		createCookie('password', passwordText, 7);
		alert("Se loggeara como el administrador del sitio");
		CambiarPagina('http://192.168.56.1:8080/administracion/AdminCP.html');
	}
	else 
	{
		var req = new HttpClient();
		var datosUsuario = {usuario: usuarioText, password: passwordText};
		var input = {sesion:datosUsuario};
		req.post("http://192.168.56.101:7777/server/IniciarSesion", input, function(response) {
			
			var result = JSON.parse(response);
			console.log("Usuario: " + result.result.usuario + ", Password: " + result.result.password) + "\n";
			if(result.result.usuario == "DUMMY")
			{
				alert("Credenciales de acceso no validas");
			}
			else
			{
				createCookie('usuario', result.result.usuario, 7);
				createCookie('password', result.result.password, 7);
				alert("Se loggeara como usuario: " + result.result.usuario);
				CambiarPagina('administracion_usuario/UCP.html');
			}
		});
		
	}
}

function HttpClient() {
	this.get = function(aUrl, aCallback) {
		var anHttpRequest = new XMLHttpRequest();

		anHttpRequest.open( "GET", aUrl, true );
		anHttpRequest.setRequestHeader('Content-Type', 'application/json');
    
		anHttpRequest.onreadystatechange = function() { 
	    	if (anHttpRequest.readyState == 4 && anHttpRequest.status == 200)
			aCallback(anHttpRequest.responseText);
		}
     
		anHttpRequest.send();
	}
	this.post = function(aUrl, obj, aCallback) {
		var anHttpRequest = new XMLHttpRequest();

		anHttpRequest.open( "POST", aUrl, true );
		anHttpRequest.setRequestHeader('Content-Type', 'application/json');  

		anHttpRequest.onreadystatechange = function() { 
	    	if (anHttpRequest.readyState == 4 && anHttpRequest.status == 200)
			aCallback(anHttpRequest.responseText);
		}
  		var sendObj = JSON.stringify(obj);
		anHttpRequest.send(sendObj);
	}
}

function CambiarPagina(url)
{
	window.location.href = url;
}

function createCookie(name,value,days) {
	if (days) {
		var date = new Date();
		date.setTime(date.getTime()+(days*24*60*60*1000));
		var expires = "; expires="+date.toGMTString();
	}
	else var expires = "";
	document.cookie = name+"="+value+expires+"; path=/";
}

function readCookie(name) {
	var nameEQ = name + "=";
	var ca = document.cookie.split(';');
	for(var i=0;i < ca.length;i++) {
		var c = ca[i];
		while (c.charAt(0)==' ') c = c.substring(1,c.length);
		if (c.indexOf(nameEQ) == 0) return c.substring(nameEQ.length,c.length);
	}
	return null;
}

function eraseCookie(name) {
	createCookie(name,"",-1);
}


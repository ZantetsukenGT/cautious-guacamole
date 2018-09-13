window.onload = function() {
	var boton = document.getElementById("bModificar");
	boton.disabled = true;
	boton = document.getElementById("bEliminar");
	boton.disabled = true;
}

function HabilitarModificar() {
	var texto = document.getElementById("textBoxModificar");
	var boton = document.getElementById("bModificar");	
	if(texto.value == "" || texto.value == texto.placeholder)
	{
		boton.disabled = true;
	}
	else
	{	
		boton.disabled = false;
	}
}

function HabilitarEliminar() {
	var texto = document.getElementById("textBoxEliminar");
	var boton = document.getElementById("bEliminar");
	if(texto.value == "" || texto.value == texto.placeholder)
	{
		boton.disabled = true;
	}
	else
	{	
		boton.disabled = false;
	}
}

function VisualizarArbol() {
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
				CambiarPagina('http://192.168.56.1:8080/UCP.html');
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


function setup() {
	noCanvas();
}

function IniciarSesion() {
	var usuarioText = document.getElementById("textBox1").value;
	var passwordText = document.getElementById("textBox2").value;
	
	if(usuarioText == "ADMIN" && passwordText == "140918")
	{
		alert("Se loggeara como el administrador del sitio");
		CambiarPagina('http://192.168.56.1:8080/administracion/AdminCP.html');
	}
	else 
	{
		var req = new HttpClient();
		var datosUsuario = {usuario: usuarioText, password: passwordText};
		var input = {sesion:datosUsuario};
		req.post("http://192.168.56.101:7777/server/IniciarSesion", true, input, function(response) {
			
			var result = JSON.parse(response);
			console.log("Usuario: " + result.result.usuario + ", Password: " + result.result.password) + "\n";
			if(result.result.usuario == "NOT_FOUND")
			{
				alert("Credenciales de acceso no validas");
			}
			else
			{
				alert("Se loggeara como usuario: " + result.result.usuario);
				CambiarPagina('http://192.168.56.1:8080/user/UCP.html');
			}
		});
		
	}
}

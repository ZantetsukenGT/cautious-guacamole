var text_imagen = "";
var text_estudiantes = "";

var carnet_busqueda = "";

function VisualizarArbol() {
	var req = new HttpClient();
	req.get("http://192.168.56.101:7777/server/ArbolBinario", true, function(response) {
	
		var result = JSON.parse(response);
		console.log(result.result);
		AbrirPagina(result.result);
	});
}

function CargarEstudiantes() {
	var req = new HttpClient();
	
	var array = text_estudiantes.split("\n");
	for(var i = 0; i < array.length; i++)
	{
		if(array[i].length > 0)
		{
			var data = JSON.parse(array[i]);
			data = JSON.stringify(data);
			data = data.replace("\"carnet\":", "\"carne\":");
			data = data.replace("\"nombres\":", "\"nombre\":");
			console.log(data);
			data = JSON.parse(data);
			var input = {nuevo:data};
			req.post("http://192.168.56.101:7777/server/InsertarEstudiante", false, input, function(response) {

				var result = JSON.parse(response);
				console.log(result.result);
			});
		}
	}
	DynamicRefresh();
}

function VerImagen() {
	var req = new HttpClient();
	
	var lineas = text_imagen.split("\n");
	var data = "";
	var maxIteraciones = 0;
	for(var i = 0; i < lineas.length;)
	{
		if(lineas.length - i > 50000)
		{	
			maxIteraciones = 50000;
		}
		else
		{
			maxIteraciones = lineas.length - i;
		}
			
		for(var j = 0; j < maxIteraciones ; i++, j++)
		{
			data += lineas[i];
		}
		var input = {text:data};
		req.post("http://192.168.56.101:7777/server/LineaImagen", false, input, function(response) {

			var result = JSON.parse(response);
			console.log(result.result);
		});
		data = "";
	}
	
	
	var input = {usuario: "-2"};
	req.post("http://192.168.56.101:7777/server/Matriz", true, input, function(response) {
	
		var result = JSON.parse(response);
		console.log(result.result);
		if(result.result[0] == 'h')
		{
			AbrirPagina(result.result);
		}
		else
		{
			alert(result.result);
		}

	});
}

function VerImagenNodos() {
	var req = new HttpClient();

	var lineas = text_imagen.split("\n");
	var data = "";
	var maxIteraciones = 0;
	for(var i = 0; i < lineas.length;)
	{
		if(lineas.length - i > 50000)
		{	
			maxIteraciones = 50000;
		}
		else
		{
			maxIteraciones = lineas.length - i;
		}
			
		for(var j = 0; j < maxIteraciones ; i++, j++)
		{
			data += lineas[i];
		}
		var input = {text:data};
		req.post("http://192.168.56.101:7777/server/LineaImagen", false, input, function(response) {

			var result = JSON.parse(response);
			console.log(result.result);
		});
		data = "";
	}

	var input = {usuario: "-1"};
	req.post("http://192.168.56.101:7777/server/Matriz", true,input, function(response) {
	
		var result = JSON.parse(response);
		console.log(result.result);
		if(result.result[0] == 'h')
		{
			AbrirPagina(result.result);
		}
		else
		{
			alert(result.result);
		}
	});
}

function AgregarEstudiante() {
	var carnetText = document.getElementById("textBoxCarnet").value;
	var dpiText = document.getElementById("textBoxDPI").value;
	var nombresText = document.getElementById("textBoxNombres").value;
	var apellidosText = document.getElementById("textBoxApellidos").value;
	var fechaNacText = document.getElementById("textBoxFechaDD").value + "/" + document.getElementById("textBoxFechaMM").value + "/" + document.getElementById("textBoxFechaYYYY").value;
	var direccionText = document.getElementById("textBoxDireccion").value;
	var creditosText = document.getElementById("textBoxCreditos").value;
	var contrasenaText = document.getElementById("textBoxContrasena").value;

	if(carnetText != "" && dpiText != "")
	{
		if(document.getElementById("textBoxFechaDD").value != "" && document.getElementById("textBoxFechaMM").value != "" && document.getElementById("textBoxFechaYYYY").value != "")
		{
			if(creditosText != "" && contrasenaText != "")
			{
				var req = new HttpClient();
				var datosEstudiante = {carne: carnetText, dpi: dpiText, nombre: nombresText, apellidos: apellidosText, fechaNacimiento: fechaNacText, direccion: direccionText, creditos:creditosText, password:contrasenaText};
				var input = {nuevo:datosEstudiante};
				req.post("http://192.168.56.101:7777/server/InsertarEstudiante", true, input, function(response) {

					var result = JSON.parse(response);
					console.log(result.result);
				});

				if(text_imagen != "")
				{

					var lineas = text_imagen.split("\n");
					var data = "";
					var maxIteraciones = 0;
					for(var i = 0; i < lineas.length;)
					{
						if(lineas.length - i > 50000)
						{	
							maxIteraciones = 50000;
						}
						else
						{
							maxIteraciones = lineas.length - i;
						}
	
						for(var j = 0; j < maxIteraciones ; i++, j++)
						{
							data += lineas[i];
						}
						var input = {text:data};
						req.post("http://192.168.56.101:7777/server/LineaImagen", false, input, function(response) {

							var result = JSON.parse(response);
							console.log(result.result);
						});
						data = "";
					}

					req.post("http://192.168.56.101:7777/server/Imagen", true, carnetText, function(response) {

						var result = JSON.parse(response);
						console.log(result.result);
					});
				}
				DynamicRefresh();
			}
			else
			{
				alert("No deje los campos de Creditos/Contraseña vacios");
			}
		}
		else
		{
			alert("No deje la fecha de nacimiento vacia");
		}
		
	}
	else
	{
		alert("No deje los campos de Carnet/DPI vacios");
	}
	/*
	if(contrasenaText != "")
	{
		var datosPassword = {usuario: carnetText, password: contrasenaText};
		var inputPassword = {sesion: datosPassword}
		req.post("http://192.168.56.101:7777/server/Contrasena", true, inputPassword, function(response) {
		
			var result = JSON.parse(response);
			console.log(result.result);
		});
	}*/
}

function BuscarEstudiante() {
	var carnetText = document.getElementById("textBoxModificarEliminar").value;

	var req = new HttpClient();
	var input = {usuario:carnetText};
	req.post("http://192.168.56.101:7777/server/BuscarEstudiante", true, input, function(response) {
		
		var result = JSON.parse(response);
		console.log(JSON.stringify(result.result));
		if(result.result.carne[0] != 'N')
		{
			var array = result.result.fechaNacimiento.split("/");
			carnet_busqueda = result.result.carne;
			document.getElementById("textBoxCarnet").value = result.result.carne;
			document.getElementById("textBoxDPI").value = result.result.dpi;
			document.getElementById("textBoxNombres").value = result.result.nombre;
			document.getElementById("textBoxApellidos").value = result.result.apellidos;
			document.getElementById("textBoxFechaDD").value = array[0];
			document.getElementById("textBoxFechaMM").value = array[1];
			document.getElementById("textBoxFechaYYYY").value = array[2];
			document.getElementById("textBoxDireccion").value = result.result.direccion;
			document.getElementById("textBoxCreditos").value = result.result.creditos;
			document.getElementById("textBoxContrasena").value = result.result.password;
			document.getElementById("bModificar").disabled = false;
			document.getElementById("bModificar").innerHTML = "Modificar Estudiante: " + result.result.carne;
			document.getElementById("bEliminar").disabled = false;
			document.getElementById("bEliminar").innerHTML = "Eliminar Estudiante: " + result.result.carne;
			document.getElementById("bVisualizar").disabled = false;
			document.getElementById("bVisualizar").innerHTML = "Visualizar Estudiante: " + result.result.carne;
		}
		else
		{
			DynamicRefresh();
		}
	});
	
}

function VisualizarEstudiante() {
	var carnetText = document.getElementById("textBoxModificarEliminar").value;

	var req = new HttpClient();
	var input = {visualizado:carnetText};
	req.post("http://192.168.56.101:7777/server/VisualizarEstudiante", true, input, function(response) {
		
		var result = JSON.parse(response);
		console.log(result.result);
		if(result.result[0] == 'h')
		{
			AbrirPagina(result.result);
		}
		else
		{
			alert(result.result);
		}
	});
	
}

function ModificarEstudiante() {
	var carnetText = document.getElementById("textBoxCarnet").value;
	var dpiText = document.getElementById("textBoxDPI").value;
	var nombresText = document.getElementById("textBoxNombres").value;
	var apellidosText = document.getElementById("textBoxApellidos").value;
	var fechaNacText = document.getElementById("textBoxFechaDD").value + "/" + document.getElementById("textBoxFechaMM").value + "/" + document.getElementById("textBoxFechaYYYY").value;
	var direccionText = document.getElementById("textBoxDireccion").value;
	var creditosText = document.getElementById("textBoxCreditos").value;
	var contrasenaText = document.getElementById("textBoxContrasena").value;

	if(carnetText != "" && dpiText != "")
	{
		if(document.getElementById("textBoxFechaDD").value != "" && document.getElementById("textBoxFechaMM").value != "" && document.getElementById("textBoxFechaYYYY").value != "")
		{
			if(creditosText != "" && contrasenaText != "")
			{
				var req = new HttpClient();
				var datosEstudiante = {carne: carnetText, dpi: dpiText, nombre: nombresText, apellidos: apellidosText, fechaNacimiento: fechaNacText, direccion: direccionText, creditos:creditosText, password:contrasenaText};
				var input = {nuevo:datosEstudiante,viejo:carnet_busqueda};
				console.log(JSON.stringify(input));
				req.post("http://192.168.56.101:7777/server/ModificarEstudiante", true, input, function(response) {

					var result = JSON.parse(response);
					console.log(result.result);
				});

				if(text_imagen != "")
				{

					var lineas = text_imagen.split("\n");
					var data = "";
					var maxIteraciones = 0;
					for(var i = 0; i < lineas.length;)
					{
						if(lineas.length - i > 50000)
						{	
							maxIteraciones = 50000;
						}
						else
						{
							maxIteraciones = lineas.length - i;
						}

						for(var j = 0; j < maxIteraciones ; i++, j++)
						{
							data += lineas[i];
						}
						var input = {text:data};
						req.post("http://192.168.56.101:7777/server/LineaImagen", false, input, function(response) {

							var result = JSON.parse(response);
							console.log(result.result);
						});
						data = "";
					}

					req.post("http://192.168.56.101:7777/server/Imagen", true, carnetText, function(response) {

						var result = JSON.parse(response);
						console.log(result.result);
					});
				}
				DynamicRefresh();
			}
			else
			{
				alert("No deje los campos de Creditos/Contraseña vacios");
			}
		}
		else
		{
			alert("No deje la fecha de nacimiento vacia");
		}
		
	}
	else
	{
		alert("No deje los campos de Carnet/DPI vacios");
	}
}

function EliminarEstudiante() {
	var req = new HttpClient();
	var input = {eliminar:carnet_busqueda,viejo:carnet_busqueda};
	req.post("http://192.168.56.101:7777/server/EliminarEstudiante", true, input, function(response) {
		
		var result = JSON.parse(response);
		console.log(result.result);
		DynamicRefresh();
	});
}

function DynamicRefresh()
{
	document.getElementById("textBoxCarnet").value = "";
	document.getElementById("textBoxDPI").value = "";
	document.getElementById("textBoxNombres").value = "";
	document.getElementById("textBoxApellidos").value = "";
	document.getElementById("textBoxFechaDD").value = "";
	document.getElementById("textBoxFechaMM").value = "";
	document.getElementById("textBoxFechaYYYY").value = "";
	document.getElementById("textBoxDireccion").value = "";
	document.getElementById("textBoxCreditos").value = "";
	document.getElementById("textBoxContrasena").value = "";
	document.getElementById("textBoxModificarEliminar").value = "";
	document.getElementById("bModificar").disabled = true;
	document.getElementById("bModificar").innerHTML = "Modificar Estudiante";
	document.getElementById("bEliminar").disabled = true;
	document.getElementById("bEliminar").innerHTML = "Eliminar Estudiante";
	document.getElementById("bVisualizar").disabled = true;
	document.getElementById("bVisualizar").innerHTML = "Visualizar Estudiante";
	document.getElementById("bVerImagen").disabled = true;
	document.getElementById("bVerImagenNodos").disabled = true;
	document.getElementById("bCargarEstudiantes").disabled = true;
	text_imagen = "";
	carnet_busqueda = "";
	text_estudiantes = "";
}

function imagenSelected(file)
{
	if(file.type == "text")
	{
		text_imagen = file.data;
	}
	else
	{
		var base64 = file.data.replace("data:;base64,", "");
		var text = window.atob(base64);
		text_imagen = text;
	}
	var boton = document.getElementById("bVerImagen");
	boton.disabled = false;
	boton = document.getElementById("bVerImagenNodos");
	boton.disabled = false;
}

function estudiantesSelected(file)
{
	if(file.type == "text")
	{
		text_estudiantes = file.data;
	}
	else
	{
		var base64 = file.data.replace("data:;base64,", "");
		var text = window.atob(base64);
		text_estudiantes = text;
	}
	var boton = document.getElementById("bCargarEstudiantes");
	boton.disabled = false;
}


function setup() {
	noCanvas();

	DynamicRefresh();

	var imagenChooser =  createFileInput(imagenSelected);
	imagenChooser.position(565,608);
	var estudiantesChooser =  createFileInput(estudiantesSelected);
	estudiantesChooser.position(600,242);
}


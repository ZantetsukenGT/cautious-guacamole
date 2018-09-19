var text_horarios = "";

var horario_busqueda = "";
var curso_busqueda = "";

var dias_curso = [];

function horariosSelected(file)
{
	if(file.type == "text")
	{
		text_horarios = file.data;
	}
	else
	{
		var base64 = file.data.replace("data:;base64,", "");
		var text = window.atob(base64);
		text_horarios = text;
	}
	var boton = document.getElementById("bCargarHorarios");
	boton.disabled = false;
}

function CargarHorarios() {
	var req = new HttpClient();
	
	var yyyyText = document.getElementById("textBoxYYYYCargaMasiva").value;
	var i = document.getElementById("ciclosOptionsCargaMasiva").selectedIndex;
	var versionText = document.getElementById("textBoxVersionCargaMasiva").value;

	if(yyyyText != "" && i != -1 && versionText != "")
	{
		var cicloText = document.getElementById("ciclosOptionsCargaMasiva").options[i].text;
		var array = text_horarios.split("\n");
		for(var i = 0; i < array.length; i++)
		{
			if(array[i].length > 0)
			{
				var data = JSON.parse(array[i]);
				console.log(JSON.stringify(data));
				var datosCiclo = {yyyy:yyyyText,ciclo:cicloText,version:versionText};
				var input = {nuevo:data,ciclo:datosCiclo};
				var req = new HttpClient();
				req.post("http://192.168.56.101:7777/server/InsertarCursoSistema", false, input, function(response) {
	
					var result = JSON.parse(response);
					console.log(result.result);
				});
			}
		}
		DynamicRefresh();
	}
	else
	{
		alert("No deje los campos vacios");
	}
}

function AgregarHorario() {
	var yyyyText = document.getElementById("textBoxYYYY").value;
	var i = document.getElementById("ciclosOptions").selectedIndex;
	var versionText = document.getElementById("textBoxVersion").value;

	if(yyyyText != "" && i != -1 && versionText != "")
	{
		var cicloText = document.getElementById("ciclosOptions").options[i].text;
		var req = new HttpClient();
		var datosHorario = {yyyy: yyyyText, ciclo: cicloText, version: versionText};
		var input = {nuevo:datosHorario};
		console.log(JSON.stringify(input));
		req.post("http://192.168.56.101:7777/server/InsertarHorario", false, input, function(response) {
		
			var result = JSON.parse(response);
			console.log(result.result);
		});
		alert("Horario agregado correctamente");
		DynamicRefresh();
	}
	else
	{
		alert("No deje los campos vacios");
	}
}

function BuscarHorario() {
	var textBoxBuscar = document.getElementById("textBoxBuscar").value;
	if(textBoxBuscar != "")
	{
		var input = {buscado:textBoxBuscar};
		var req = new HttpClient();
		req.post("http://192.168.56.101:7777/server/BuscarHorario", true, input, function(response) {
	
			var result = JSON.parse(response);
			console.log(result.result);
			if(result.result[0] != 'N')
			{
				document.getElementById("bEliminarHorario").innerHTML = "Eliminar Horario: " + horario_busqueda;
				document.getElementById("bVisualizarHorario").innerHTML = "Visualizar Horario: " + horario_busqueda;

				document.getElementById("bEliminarHorario").disabled = false;
				document.getElementById("bVisualizarHorario").disabled = false;

				horario_busqueda = textBoxBuscar;
			}
			else
			{
				DynamicRefresh();
			}
		});
	}
}

function EliminarHorario() {
	var input = {eliminado:horario_busqueda};
	var req = new HttpClient();
	req.post("http://192.168.56.101:7777/server/EliminarHorario", true, input, function(response) {
	
		var result = JSON.parse(response);
		console.log(result.result);
		DynamicRefresh();
	});
}

function VisualizarHorario() {
	var input = {buscado:horario_busqueda};
	var req = new HttpClient();
	req.post("http://192.168.56.101:7777/server/VisualizarHorario", true, input, function(response) {
	
		var result = JSON.parse(response);
		console.log(result.result);
		AbrirPagina(result.result);
	});
}

function VisualizarTodosHorarios() {
	var req = new HttpClient();
	req.get("http://192.168.56.101:7777/server/VisualizarTodosHorarios", true, function(response) {
	
		var result = JSON.parse(response);
		console.log(result.result);
		AbrirPagina(result.result);
	});
}

function VisualizarCiclo()
{
	var i = document.getElementById("yyyyOptions").selectedIndex;
	var j = document.getElementById("ciclosCursoOptions").selectedIndex;
	if(i != -1 && j != -1)
	{
		var yyyyOptionsText = document.getElementById("yyyyOptions").options[i].text;
		var ciclosCursoOptionsText = document.getElementById("ciclosCursoOptions").options[j].text;
	
		var datosCiclo = {yyyy:yyyyOptionsText,ciclo:ciclosCursoOptionsText,version:""};
		var input = {ciclo:datosCiclo};
		var req = new HttpClient();
		req.post("http://192.168.56.101:7777/server/VisualizarCiclo", true, input, function(response) {

			var result = JSON.parse(response);
			console.log(JSON.stringify(result.result));
			AbrirPagina(result.result);
		});
	}
	else
	{
		alert("No deje Año/Ciclo sin seleccionar");
	}
}

function yyyySelected()
{
	var genericOptions = document.getElementById("ciclosCursoOptions");
	while(genericOptions.length > 0) {
	    genericOptions.remove(0);
	}

	genericOptions = document.getElementById("versionOptions");
	while(genericOptions.length > 0) {
	    genericOptions.remove(0);
	}

	var i = document.getElementById("yyyyOptions").selectedIndex;
	var yyyyOptionsText = document.getElementById("yyyyOptions").options[i].text;
	var input = {yyyy:yyyyOptionsText};

	var req = new HttpClient();
	req.post("http://192.168.56.101:7777/server/BuscarCiclos", false, input, function(response) {
		
		var result = JSON.parse(response);
		console.log(result.result);

		if(result.result != "")
		{
			var array = result.result.split("$");
			var ciclosCursoOptions = document.getElementById("ciclosCursoOptions");
			for(var i = 0; i < array.length; i++)
			{
				var option = document.createElement("option");
				option.text = array[i];
				ciclosCursoOptions.add(option);
			}
		}
	});
	genericOptions = document.getElementById("ciclosCursoOptions");
	genericOptions.selectedIndex = -1;
	genericOptions = document.getElementById("versionOptions");
	genericOptions.selectedIndex = -1;
}

function cicloSelected()
{
	var genericOptions = document.getElementById("versionOptions");
	while(genericOptions.length > 0) {
	    genericOptions.remove(0);
	}

	var i = document.getElementById("ciclosCursoOptions").selectedIndex;
	var cicloText = document.getElementById("ciclosCursoOptions").options[i].text;

	i = document.getElementById("yyyyOptions").selectedIndex;
	var yyyyText = document.getElementById("yyyyOptions").options[i].text;
	var input = {yyyy:yyyyText,ciclo:cicloText};

	var req = new HttpClient();
	req.post("http://192.168.56.101:7777/server/BuscarVersiones", false, input, function(response) {
		
		var result = JSON.parse(response);
		console.log(result.result);

		if(result.result != "")
		{
			var array = result.result.split("$");
			var versionOptions = document.getElementById("versionOptions");
			for(var i = 0; i < array.length; i++)
			{
				var option = document.createElement("option");
				option.text = array[i];
				versionOptions.add(option);
			}
		}
	});
	genericOptions = document.getElementById("versionOptions");
	genericOptions.selectedIndex = -1;
}

function AgregarDiaCurso()
{
	
	var textBoxDiaText = document.getElementById("textBoxDia").value;
	var textBoxHHinicioText = document.getElementById("textBoxHHinicio").value;
	var textBoxMMinicioText = document.getElementById("textBoxMMinicio").value;
	var textBoxHHfinText = document.getElementById("textBoxHHfin").value;
	var textBoxMMfinText = document.getElementById("textBoxMMfin").value;


	if(textBoxDiaText != "")
	{
		if(textBoxHHinicioText != "" && textBoxMMinicioText != "" && textBoxHHfinText != "" && textBoxMMfinText != "")
		{	
			textBoxHHinicioText += ":" + textBoxMMinicioText;
			textBoxHHfinText += ":" + textBoxMMfinText;
			var input = {dia:textBoxDiaText,hora_in:textBoxHHinicioText,hora_fin:textBoxHHfinText};
			dias_curso.push(input);
			document.getElementById("textBoxDia").value = "";
			document.getElementById("textBoxHHinicio").value = "";
			document.getElementById("textBoxMMinicio").value = "";
			document.getElementById("textBoxHHfin").value = "";
			document.getElementById("textBoxMMfin").value = "";
			console.log(JSON.stringify(input));
			console.log(input);
		}
		else
		{
			alert("Ingrese las horas para impartir el curso");
		}
	}
	else
	{
		alert("Ingrese un dia para impartir el curso");
	}
}

function AgregarCurso()
{

	var i = document.getElementById("yyyyOptions").selectedIndex;
	var j = document.getElementById("ciclosCursoOptions").selectedIndex;
	var k = document.getElementById("versionOptions").selectedIndex;
	if(i != -1 && j != -1 && k != -1)
	{
		if(dias_curso.length != 0)
		{
			var yyyyOptionsText = document.getElementById("yyyyOptions").options[i].text;
			var ciclosCursoOptionsText = document.getElementById("ciclosCursoOptions").options[j].text;
			var versionOptionsText = document.getElementById("versionOptions").options[k].text;

			var textBoxCodigoText = document.getElementById("textBoxCodigo").value;
			var textBoxNombreText = document.getElementById("textBoxNombre").value;
			var textBoxSeccionText = document.getElementById("textBoxSeccion").value;
			var textBoxEdificioText = document.getElementById("textBoxEdificio").value;
			var textBoxSalonText = document.getElementById("textBoxSalon").value;
			var textBoxCatedraticoText = document.getElementById("textBoxCatedratico").value;
			
			var datosCurso = {codigo:textBoxCodigoText,nombre:textBoxNombreText,seccion:textBoxSeccionText,edificio:textBoxEdificioText,salon:textBoxSalonText,catedratico:textBoxCatedraticoText,horario:dias_curso};
			var datosCiclo = {yyyy:yyyyOptionsText,ciclo:ciclosCursoOptionsText,version:versionOptionsText};
			var input = {nuevo:datosCurso,ciclo:datosCiclo};
			console.log(JSON.stringify(input));
			var req = new HttpClient();
			req.post("http://192.168.56.101:7777/server/InsertarCursoSistema", true, input, function(response) {
		
				var result = JSON.parse(response);
				console.log(result.result);
				DynamicRefresh();
			});
			
		}
		else
		{
			alert("Debe agregar por lo menos un dia para impartir el curso");
		}
		
	}
	else
	{
		alert("No deje Año/Ciclo/Version sin seleccionar");
	}
}

function BuscarCurso()
{
	var textBoxBuscarCursoText = document.getElementById("textBoxBuscarCurso").value;

	var i = document.getElementById("yyyyOptions").selectedIndex;
	var j = document.getElementById("ciclosCursoOptions").selectedIndex;
	var k = document.getElementById("versionOptions").selectedIndex;
	if(i != -1 && j != -1 && k != -1)
	{
		if(textBoxBuscarCursoText != "")
		{
			var yyyyOptionsText = document.getElementById("yyyyOptions").options[i].text;
			var ciclosCursoOptionsText = document.getElementById("ciclosCursoOptions").options[j].text;
			var versionOptionsText = document.getElementById("versionOptions").options[k].text;
		
			var datosCiclo = {yyyy:yyyyOptionsText,ciclo:ciclosCursoOptionsText,version:versionOptionsText};
			var input = {buscado:textBoxBuscarCursoText,ciclo:datosCiclo};
			var req = new HttpClient();
			req.post("http://192.168.56.101:7777/server/BuscarCursoSistema", true, input, function(response) {
	
				var result = JSON.parse(response);
				console.log(JSON.stringify(result.result));
				if(result.result.codigo != "NOT_FOUND")
				{
					document.getElementById("bEliminarCurso").innerHTML = "Eliminar Curso: " + result.result.codigo;
					document.getElementById("bVisualizarCurso").innerHTML = "Visualizar Curso: " + result.result.codigo;

					document.getElementById("bEliminarCurso").disabled = false;
					document.getElementById("bVisualizarCurso").disabled = false;

					curso_busqueda = textBoxBuscarCursoText;
				}
				else
				{
					DynamicRefresh();
				}
			});
		}
		else
		{
			alert("No deje casilla sin llenar");
		}
	}
	else
	{
		alert("No deje Año/Ciclo/Version sin seleccionar");
	}
}

function EliminarCurso()
{
	var i = document.getElementById("yyyyOptions").selectedIndex;
	var j = document.getElementById("ciclosCursoOptions").selectedIndex;
	var k = document.getElementById("versionOptions").selectedIndex;
	if(i != -1 && j != -1 && k != -1)
	{
		var yyyyOptionsText = document.getElementById("yyyyOptions").options[i].text;
		var ciclosCursoOptionsText = document.getElementById("ciclosCursoOptions").options[j].text;
		var versionOptionsText = document.getElementById("versionOptions").options[k].text;
	
		var datosCiclo = {yyyy:yyyyOptionsText,ciclo:ciclosCursoOptionsText,version:versionOptionsText};
		var input = {eliminado:curso_busqueda,ciclo:datosCiclo};
		var req = new HttpClient();
		req.post("http://192.168.56.101:7777/server/EliminarCursoSistema", true, input, function(response) {

			var result = JSON.parse(response);
			console.log(JSON.stringify(result.result));
			DynamicRefresh();
		});
	}
	else
	{
		alert("No deje Año/Ciclo/Version sin seleccionar");
	}
}

function VisualizarCurso()
{
	var i = document.getElementById("yyyyOptions").selectedIndex;
	var j = document.getElementById("ciclosCursoOptions").selectedIndex;
	var k = document.getElementById("versionOptions").selectedIndex;
	if(i != -1 && j != -1 && k != -1)
	{
		var yyyyOptionsText = document.getElementById("yyyyOptions").options[i].text;
		var ciclosCursoOptionsText = document.getElementById("ciclosCursoOptions").options[j].text;
		var versionOptionsText = document.getElementById("versionOptions").options[k].text;
	
		var datosCiclo = {yyyy:yyyyOptionsText,ciclo:ciclosCursoOptionsText,version:versionOptionsText};
		var input = {visualizado:curso_busqueda,ciclo:datosCiclo};
		var req = new HttpClient();
		req.post("http://192.168.56.101:7777/server/VisualizarCursoSistema", true, input, function(response) {

			var result = JSON.parse(response);
			console.log(JSON.stringify(result.result));
			AbrirPagina(result.result);
		});
	}
	else
	{
		alert("No deje Año/Ciclo/Version sin seleccionar");
	}
}

function DynamicRefresh()
{
	var genericOptions = document.getElementById("ciclosCursoOptions");
	while(genericOptions.length > 0) {
	    genericOptions.remove(0);
	}

	var genericOptions = document.getElementById("yyyyOptions");
	while(genericOptions.length > 0) {
	    genericOptions.remove(0);
	}

	genericOptions = document.getElementById("versionOptions");
	while(genericOptions.length > 0) {
	    genericOptions.remove(0);
	}
	dias_curso = [];

	document.getElementById("textBoxDia").value = "";
	document.getElementById("textBoxHHinicio").value = "";
	document.getElementById("textBoxMMinicio").value = "";
	document.getElementById("textBoxHHfin").value = "";
	document.getElementById("textBoxMMfin").value = "";

	document.getElementById("textBoxCodigo").value = "";
	document.getElementById("textBoxNombre").value = "";
	document.getElementById("textBoxSeccion").value = "";
	document.getElementById("textBoxEdificio").value = "";
	document.getElementById("textBoxSalon").value = "";
	document.getElementById("textBoxCatedratico").value = "";

	document.getElementById("textBoxYYYY").value = "";
	document.getElementById("textBoxVersion").value = "";
	document.getElementById("ciclosOptions").selectedIndex = -1;

	
	document.getElementById("textBoxYYYYCargaMasiva").value = "";
	document.getElementById("ciclosOptionsCargaMasiva").selectedIndex = -1;
	document.getElementById("textBoxVersionCargaMasiva").value = "";

	
	horario_busqueda = "";
	document.getElementById("textBoxBuscar").value = "";
	document.getElementById("bEliminarHorario").innerHTML = "Eliminar Horario";
	document.getElementById("bVisualizarHorario").innerHTML = "Visualizar Horario";

	document.getElementById("bEliminarHorario").disabled = true;
	document.getElementById("bVisualizarHorario").disabled = true;


	curso_busqueda = "";
	document.getElementById("textBoxBuscarCurso").value = "";
	document.getElementById("bEliminarCurso").innerHTML = "Eliminar Curso";
	document.getElementById("bVisualizarCurso").innerHTML = "Visualizar Curso";

	document.getElementById("bEliminarCurso").disabled = true;
	document.getElementById("bVisualizarCurso").disabled = true;

	var req = new HttpClient();
	req.get("http://192.168.56.101:7777/server/BuscarHorarios", false, function(response) {
	
		var result = JSON.parse(response);

		if(result.result != "")
		{
			var array = result.result.split("$");
			console.log(array);
			var yyyyOptions = document.getElementById("yyyyOptions");
			for(var i = 0; i < array.length; i++)
			{
				var option = document.createElement("option");
				option.text = array[i];
				yyyyOptions.add(option);
			}
		}
	});

	genericOptions = document.getElementById("yyyyOptions");
	genericOptions.selectedIndex = -1;
	genericOptions = document.getElementById("ciclosCursoOptions");
	genericOptions.selectedIndex = -1;
	genericOptions = document.getElementById("versionOptions");
	genericOptions.selectedIndex = -1;
}

function setup() {
	noCanvas();
	DynamicRefresh();
	
	var boton = document.getElementById("bCargarHorarios");
	boton.disabled = true;
	boton = document.getElementById("bEliminarHorario");
	boton.disabled = true;
	boton = document.getElementById("bVisualizarHorario");
	boton.disabled = true;
	boton = document.getElementById("bEliminarCurso");
	boton.disabled = true;
	boton = document.getElementById("bVisualizarCurso");
	boton.disabled = true;
	document.getElementById("ciclosOptionsCargaMasiva").selectedIndex = -1;
	document.getElementById("ciclosOptions").selectedIndex = -1;

	var horariosChooser =  createFileInput(horariosSelected);
	horariosChooser.position(600,242);
}


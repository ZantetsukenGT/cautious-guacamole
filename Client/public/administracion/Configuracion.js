function setup() {
	noCanvas();
	document.getElementById("ciclos").selectedIndex = "-1";
}

function Guardar()
{
	var yyyyText = document.getElementById("yyyy").value;
 	var i = document.getElementById("ciclos").selectedIndex;
    	var cicloText = "";
	if(i != -1 && yyyyText != "")
	{
		cicloText = document.getElementById("ciclos").options[i].text;

		var input = {yyyy:yyyyText,ciclo:cicloText}
		var req = new HttpClient();
		req.post("http://192.168.56.101:7777/server/SetCicloActual", true, input, function(response) {
	
			var result = JSON.parse(response);
			console.log(result.result);
		});
	}
	else
	{
		alert("No deje los campos vacios");
	}

	
}

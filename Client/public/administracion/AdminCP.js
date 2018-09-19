function setup() {
	noCanvas();
	var req = new HttpClient();
	req.get("http://192.168.56.101:7777/server/GetCicloActual", true, function(response) {
			var result = JSON.parse(response);
			console.log(result.result);
			if(result.result == "NOT_SET")
			{
				var boton = document.getElementById("bHorarios");
				boton.disabled = true;
			}
	});
}

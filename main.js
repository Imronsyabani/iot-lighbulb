const uri = "http://192.168.18.208";

function getDapurLed(){
    fetch(uri + "/dapur",{
        method: "GET"
    }).then((response) => response.text()).then((result) => {
        console.log(result);
        if(result == "ON"){
            ledImageDapur.src = "assets/led-on.png";
            ledDapur.style.backroundColor = "blue";
        } else {
            ledImageDapur.src = "assets/led-off.png";
            ledDapur.style.backroundColor = "#579fff";
        }
    });
}

function getKamarLed(){
    fetch(uri + "/kamar",{
        method: "GET"
    }).then((response) => response.text()).then((result) => {
        if(result === "ON"){
            ledImageKamar.src = "assets/led-on.png";
            ledKamar.style.backroundColor = "blue";
        } else {
            ledImageKamar.src = "assets/led-off.png";
            ledKamar.style.backroundColor = "#579fff";
        }
    });
}

function getTamuLed(){
    fetch(uri + "/tamu",{
        method: "GET"
    }).then((response) => response.text()).then((result) => {
        if(result === "ON"){
            ledImageTamu.src = "assets/led-on.png";
            ledTamu.style.backroundColor = "blue";
        } else {
            ledImageTamu.src = "assets/led-off.png";
            ledTamu.style.backroundColor = "#579fff";
        }
    });
}

function setDapurLed(){
    fetch(uri + '/dapur', {
        method: "POST",
    }).then(() => location.reload());
    // ledImageDapur.src = "assets/led-on.png";
    // ledDapur.style.backroundColor = "red";
}

function setKamarLed(){
    fetch(uri + '/kamar', {
        method: "POST",
    }).then(() => location.reload());
    // ledImageKamar.src = "assets/led-on.png";
    // ledKamar.style.backroundColor = "red";
}

function setTamuLed() {
    fetch(uri + '/tamu', {
        method: "POST",
    }).then(() => location.reload());
    // ledImageTamu.src = "assets/l 
}

function setTerasLed(){
    ledImageTeras.src = "assets/led-on.png";
    ledTeras.style.backroundColor = "red";
}

getDapurLed()
getKamarLed()
getTamuLed()
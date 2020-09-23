const char MAIN_page[] PROGMEM = R"=====(


<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>

<body>

    <button id="dataAl">data Al</button>
    <button id="dataGonder">data Gönder</button>
    <button id="videoBaslat">Video Başlat</button>
    <button id="videoBitir">Video Bitir</button>
    <!--
    <img src="http://192.168.4.1/view" alt="" id="video">
    -->


    <style>
        img{
            width: 500px;
            height: 500px;
        }
    </style>
    <script>

        const dataAl = document.querySelector("#dataAl")
        const dataGonder = document.querySelector("#dataGonder")
        const videoBaslat = document.querySelector("#videoBaslat")
        const videoBitir = document.querySelector("#videoBitir")
        const video = document.querySelector("#video")


        eventListeners()

        function eventListeners() {

            dataAl.addEventListener("click", (e) => {

                datayiAl()
                .then(response =>{
                    console.log(response)
                })


            })

            dataGonder.addEventListener("click", (e) => {
                sendData("http://192.168.4.1:80/dataGonder", { name: "HalilKaya" })
            })

            videoBaslat.addEventListener("click", (e) => {
                
                let element = document.createElement("img")
                element.src = "http://192.168.4.1/view"
                element.id = "video"
                element.alt = ""
                

                document.querySelector("body").appendChild(element)
    

            })

            videoBitir.addEventListener("click", (e) => {
                document.querySelector("video").remove()
            })

        }


        function sendData(url, data) {

            return new Promise((resolve, reject) => {
                fetch(url, {
                    method: "post",
                    body: JSON.stringify(data),
                    headers: {
                        "Content-type": "application/json; charset=UTF-8"
                    }
                })
                    .then(response => {
                        console.log(response)
                    })
                    .catch(err => {
                        console.log("göndermede hata oldu")
                    })
            })

        }

        function videoyuAl() {


            return new Promise((resolve, reject) => {

                fetch("http://192.168.4.1:80/view")
                    .then(response => {
                        
                        resolve(response)
                    })
                    .catch(err => {
                        reject("Hata verdi: " + err)
                    })

            })


        }

        function datayiAl() {

            return new Promise((resolve, reject) => {

                fetch("http://192.168.4.1:80/dataAl")
                    .then(response => {
                        return response.text()
                    })
                    .then(data =>{
                        console.log(data)
                        resolve(data)
                    })
                    .catch(err => {
                        reject("Hata verdi: " + err)
                    })

            })

        }



    </script>
</body>

</html>

)=====";

var speechRecognition = window.webkitSpeechRecognition
var recognition = new speechRecognition()
var textbox = $("#textbox")
var instructions = $("#instructions")
var content = ''

recognition.lang = 'AR-SA'

recognition.onstart = function () {
    instructions.text("Lestening....")
}

recognition.onspeechend = function () {
    instructions.text("Stopped lestening, press start to speak again")
}

recognition.onerror = function () {
    instructions.text("Sorry, please try again")
}

recognition.onresult = function (event) {
    var current = event.resultIndex
    var transcript = event.results[current][0].transcript
    content = transcript
    onChangespeech()
    textbox.val(content)
}


$("#start-btn").click(function (event) {
    if (content.length) {
        content += ''
    }
    recognition.start()
})

textbox.on('input', function () {
    content = $(this).val()
})
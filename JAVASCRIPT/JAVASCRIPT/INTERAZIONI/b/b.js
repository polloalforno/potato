window.onload = function () {
    main()
}


function main() {
    CF = document.getElementById("CF")

    CF.addEventListener("input", () => {
        CF.value = CF.value.toUpperCase()//trasforma le lettere da minuscole a maiuscole
    })
}
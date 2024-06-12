//Código referente ao funcionamento dos botões 
$(document).ready(function(){
    $('#botao1').click(function(){
        window.location.href = "cadastro.html";
    });

    $('#botao2').click(function(){
        window.location.href = "loggin.html";
    });

    $('#botao3').click(function(){
        window.location.href = "index.html";
    });
});


//Código de validação de campos loggin 
$(document).ready(function(){
    $('.formulario_loggin').validate({
        rules:{
            emailloggin:{
                required: true,
            },
            senhaloggin:{
                required: true
            }
        },

        submitHandler: function(form){
            alert("Tudo certo por aqui!");
        }
    });
})
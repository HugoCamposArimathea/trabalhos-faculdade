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


//Código de validação para campos de cadastro
$(document).ready(function(){
    $('.formulario_cadastro').validate({
        rules:{
            nomecadastro:{
                required: true,
                minlength: 2
            },
            emailcadastro:{
                required: true,
                emailcadastro:true
            },
            cepcadastro:{
                required: true,
                cepcadastro:true,
                minlength: 9,
                maxlength: 9
            },
            senhacadastro:{
                required:true
            }
        },
        
        submitHandler: function(form){
            alert("Cadastro feito com sucesso!")
        }
    });
})
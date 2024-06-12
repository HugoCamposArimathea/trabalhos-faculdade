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
            },
            cepcadastro:{
                required: true,
                number:true,
                minlength: 8
            },
            senhacadastro:{
                required:true
            },
            confirmsenhacadastro:{
                required: true,
                equalTo: "#senhacadastro"
            }
        },

        submitHandler: function(form){
            alert("Cadastro feito com sucesso!");
        }
    });
})


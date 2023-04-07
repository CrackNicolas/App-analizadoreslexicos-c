# Project name -->  Analizador lexico

** Descripcion
  -- Consiste en un sistema que recibe un texto de entrada y nos devuelve un analisis lexico del mismo.

** Descripcion del code
  -- N = Numeros 0-9
  -- P = Punto .
  -- E = Espacio en blanco
  -- L = Letras A-Z y a-z
  -- X = Otros caracteres
 
  Estados
   .4 = Numero decimal
   .5 = Numero entero
   .6 = Letras
   .7 = Error 

** Uso 
  -- Digitar cada digito separado por espacios en blanco, y finalizar la cadena con otro espacio en blanco.

** Tecnologias utilizadas
   .C++
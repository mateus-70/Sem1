-- Lasciate ogni speranza, o voi che entrate
--
-- LISTA 2 HASKELL
-- import Data.Text
import Data.Char
-- import Numeric (showHex, showIntAtBase)
-- import Text.Show
--import TextShow.Data.Integral (showbBin)
-- Gotta b enof

-- EX 1
pertence x [] = False
pertence x (a:as) = if x == a then True else pertence x as

-- EX 2
intersecao [] _ = []
intersecao _ [] = []
intersecao (x:xs) (y:ys) = if pertence x (y:ys) then [x]++intersecao xs (y:ys) else intersecao xs (y:ys)

-- EX 3
inverso [] = []
inverso (x:xs) = inverso xs ++ [x]

-- EX 4
nUltimos n (x:xs) = inverso(nPrimeiros n (inverso (x:xs)))

nPrimeiros 1 (x:xs) = [x]
nPrimeiros n (x:xs) = [x] ++ nPrimeiros (n-1) xs

-- EX 5
soma2 [] (y:ys) = []
soma2 (x:xs) [] = []
soma2 (x:xs) (y:ys) = [x+y] ++ soma2 xs ys

-- EX 6
pot2_aux 1 = [2]
pot2_aux n =  [2^n] ++ pot2_aux (n-1)

pot2 n = inverso (pot2_aux n)

-- EX 7
intercalacao [] ys = ys
intercalacao xs [] = xs
intercalacao (x:xs) (y:ys) = if x <= y then [x] ++ intercalacao xs (y:ys) else [y] ++ intercalacao (x:xs) ys

-- EX 8
menor [x] = x
menor (x:xs) = if x < menor xs then x else menor xs

-- EX 9
removerElem n (x:xs) = if n /= x then [x] ++ removerElem n xs else xs

-- EX 10
ordenar [] = []
ordenar (x:xs) = [menor (x:xs)] ++ ordenar ( removerElem (menor (x:xs)) (x:xs) )

-- EX 11
insereOrd n [] = [n]
insereOrd n (x:xs) = 
  if x < n then [x] ++ insereOrd n xs 
  else if x == n then [n]++xs
  else [n] ++ (x:xs)

-- Who needs TO CATCH AN ERROR?
-- EX 12
enesimo n lista = lista!!(n-1)

-- EX 13
repetir 0 k = []
-- TUDO É RECURSAO NISSO AQ FFS
-- !!!
repetir n k = [k] ++repetir (n-1) k

-- EX 14
removeTab [] = []
removeTab (x:xs) = 
  if x == '\t' 
  then [' '] ++ removeTab xs
  else [x] ++ removeTab xs

-- minusculas s = unpack . toLower . pack $ s
minusculas [] = []
minusculas (s:sx) = toLower s : minusculas sx

-- EX 16
-- SE COMPILA FUNCIONA, SE FUNCIONA ESTÁ SERTO
-- SE ESTÁ CERTO NÃO Á O Q REKLAMA
inversoDupla [] = []
inversoDupla ((x,y):xys) =  [(y,x)] ++ inversoDupla xys

-- EX 17
simetrico [] = []
simetrico ((x,y):xys) = if x==y then [True] ++ simetrico xys else [False] ++ simetrico xys

paraVetorChar 0 = []
paraVetorChar n = paraVetorChar(div n 10) ++ [paraChar (mod n 10)]

paraChar 0 = '0'
paraChar 1 = '1'
paraChar 2 = '2'
paraChar 3 = '3'
paraChar 4 = '4'
paraChar 5 = '5'
paraChar 6 = '6'
paraChar 7 = '7'
paraChar 8 = '8'
paraChar 9 = '9'

-- EX 18
numString n = paraVetorChar n

paraInt '0' = 0
paraInt '1' = 1
paraInt '2' = 2
paraInt '3' = 3
paraInt '4' = 4
paraInt '5' = 5
paraInt '6' = 6
paraInt '7' = 7
paraInt '8' = 8
paraInt '9' = 9

stringParaVetorInt [] = []
stringParaVetorInt (s:sx) = [paraInt s] ++ stringParaVetorInt sx

somaPot10 [] _ = 0
somaPot10 (x:xs) n = x * 10^n + somaPot10 xs (n+1)

-- EX 19
stringNum s = somaPot10 (stringParaVetorInt (reverse s)) 0

divisoesSucessivas 0 = [0]
divisoesSucessivas 1 = [1]
divisoesSucessivas n = [mod n 2] ++ divisoesSucessivas (div n 2)

vIntParavChar [] = []
vIntParavChar (x:xs) = [ paraChar x ] ++ vIntParavChar xs

-- EX 20
decBin n = vIntParavChar( reverse (divisoesSucessivas n))

somaPot2 [] _ = 0
somaPot2 (b:bs) n = b*2^n + somaPot2 bs (n+1)

-- EX 21
binDec b = somaPot2( reverse(stringParaVetorInt b) ) 0

-- quantidadeMoedas50 0 = 0
-- quantidadeMoedas50 n = div n 50
-- quantidadeMoedas20 n = div n 20
-- quantidadeMoedas10 n = div n 10
-- quantidadeMoedas5 n = div n 5

-- 5, 10, 20, 50
moedas = [50,20,10,5]
-- EX 22
trocoCafe preco valorPago = descontarValor (valorPago - preco) 0

descontarValor valorADescontar 3 = [(moedas!!3, div valorADescontar (moedas!!3))]
descontarValor valorADescontar tipoMoeda = 
  [(moedas!!tipoMoeda, div valorADescontar (moedas!!tipoMoeda) )] ++
  descontarValor (mod valorADescontar (moedas!!tipoMoeda) ) (tipoMoeda+1)

-- stringNum s = read s :: Int

-- decBin d = showIntAtBase 2 ""
-- toBinary n = toText . showbBin

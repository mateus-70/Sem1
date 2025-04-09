-- Lasciate ogni speranza, o voi che entrate
--
--
import Data.Text
import Numeric (showHex, showIntAtBase)
import Text.Show
--import TextShow.Data.Integral (showbBin)

pertence x [] = False
pertence x (a:as) = if x == a then True else pertence x as

intersecao [] _ = []
intersecao _ [] = []
intersecao (x:xs) (y:ys) = if pertence x (y:ys) then [x]++intersecao xs (y:ys) else intersecao xs (y:ys)

inverso l = Prelude.reverse l


nUltimos n (x:xs) = inverso(nPrimeiros n (inverso (x:xs)))

nPrimeiros 1 (x:xs) = [Prelude.head (x:xs)]
nPrimeiros n (x:xs) = [x] ++ nPrimeiros (n-1) xs

soma2 [] (y:ys) = []
soma2 (x:xs) [] = []
soma2 (x:xs) (y:ys) = [x+y] ++ soma2 xs ys

pot2_aux 1 = [2]
pot2_aux n =  [2^n] ++ pot2_aux (n-1)

pot2 n = inverso (pot2_aux n)

intercalacao [] ys = ys
intercalacao xs [] = xs
intercalacao (x:xs) (y:ys) = if x <= y then [x] ++ intercalacao xs (y:ys) else [y] ++ intercalacao (x:xs) ys

menor x = Prelude.minimum x

removerElem n (x:xs) = if n /= x then [x] ++ removerElem n xs else xs

ordenar [] = []
ordenar (x:xs) = [menor (x:xs)] ++ ordenar ( removerElem (menor (x:xs)) (x:xs) )

insereOrd n [] = [n]
insereOrd n (x:xs) = 
  if x < n then [x] ++ insereOrd n xs 
  else if x == n then [n]++xs
  else [n] ++ (x:xs)

-- Who needs TO CATCH AN ERROR?
enesimo n lista = lista!!(n-1)

repetir 0 k = []
-- TUDO É RECURSAO NISSO AQ FFS
-- !!!
repetir n k = [k] ++repetir (n-1) k

removeTab [] = []
removeTab (x:xs) = 
  if x == '\t' 
  then [' '] ++ removeTab xs
  else [x] ++ removeTab xs

minusculas s = unpack . toLower . pack $ s

-- SE COMPILA FUNCIONA, SE FUNCIONA ESTÁ SERTO
-- SE ESTÁ CERTO NÃO Á O Q REKLAMA
inversoDupla [] = []
inversoDupla ((x,y):xys) =  [(y,x)] ++ inversoDupla xys

simetrico [] = []
simetrico ((x,y):xys) = if x==y then [True] ++ simetrico xys else [False] ++ simetrico xys

-- SHOW!
numString n = show n

stringNum s = read s :: Int

-- decBin d = showIntAtBase 2 ""
toBinary n = toText . showbBin

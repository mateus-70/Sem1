-- tri a b c = if a + b < c then True else False

ehTriangulo a b c = 
 if ( (a+b > c) && (a + c > b) && (b+c > a) ) 
 then True 
 else False


tipoTriangulo a b c
 | a == b && a == c = "equilatero" 
 | a == b || b == c || a == c = "isosceles"
 | otherwise = "escaleno"

triangulo a b c = 
 if ehTriangulo a b c
 then
  tipoTriangulo a b c
 else
  "nao eh um triangulo"

somaParesAux 0 = 0
somaParesAux n = n + somaParesAux(n - 2)
somaPares n = 
  -- if (n == 0) then "Zero" else "Um"
  if (n `rem` 2 == 0)
  then somaParesAux n 
  else somaParesAux (n-1)

somaPot2m m 0 = m
somaPot2m m n = m*2^^n + somaPot2m m (n-1)


primo 1 = True
primo m = primoAux m (m-1)

primoAux m 1 = True
primoAux m a = 
  if m `rem` a /= 0
  then primoAux m (a-1)
  else False

-- n const de controle
-- k iterável

-- termo n = ((-1)^^n)/(2*n + 1) 
termo :: (Integral a1, Fractional a2) => a1 -> a2
termo n =  ( fromIntegral ( (-1)^n))  / fromIntegral (2*n +1)* 4

supremo m k = if abs(termo k) < m then k else supremo m (k+1)

seriePISoma n k =
  if k >= 1 
  then termo k + seriePISoma n (k-1)
  else termo 0

seriePI n = seriePISoma n (supremo (fromIntegral 4 / fromIntegral n) 1)
--  termo k >= (fromIntegral 4 / fromIntegral n)

-- seriePiSoma n k = print k 
-- seriePiSoma n 0 = termo 0 
-- 
-- seriePiSoma (abs(pi - 
-- seriePiTermo k = 
--  if ( abs(pi - seriePiTermo) >= 4/n )
--  then
--    ((-1)^^k)/(2*k + 1) + seriePiSoma (k+1)
--  else 

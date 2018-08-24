--cabal install random
--main = print $ "Hello, world!"
--runghc hspi.hs

module Main where

import Control.Monad (replicateM)
import Data.Time.Clock
import System.Random

calc = do
rand1 <- rand
rand2 <- rand
return . fromEnum $ (rand1 - 1) ^ 2 + (rand2 - 1) ^ 2 <= 1
where
rand = randomIO :: IO Double

main = do
start <- getCurrentTime
pi <- makePi <$> replicateM n calc
stop <- getCurrentTime
putStrLn $ show pi ++ " Time: " ++ show (diffUTCTime stop start)
where
n = 10 ^ 6
makePi vs = realToFrac (4 * sum vs) / realToFrac n


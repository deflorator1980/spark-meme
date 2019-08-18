module Main (main) where

import System.Random.MWC

import Control.Monad (replicateM_, when)
import Control.StopWatch
import System.Clock
import Control.Monad.ST
import Data.STRef

toSec :: TimeSpec -> Double
toSec ts = realToFrac (sec ts) + realToFrac (nsec ts) / 1000000000

n = 10 ^ 9 :: Int

calcPi :: ST Double Double -> ST Double Double
calcPi gen = do
  s <- newSTRef 0
  replicateM_ n $ do
    r1 <- gen
    r2 <- gen
    when ((r1 - 1) ^ 2 + (r2 - 1) ^ 2 <= 1) $ modifySTRef' s (+ 1)
  (/ realToFrac n) . (* 4) <$> readSTRef s


main :: IO ()
main = do
  (pi, t) <- stopWatch $ withSystemRandom $ calcPi . uniform
  putStrLn $ show pi ++ " Time: " ++ show (toSec t)



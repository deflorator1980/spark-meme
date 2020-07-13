n = 10^9

function pipi(sum=0)
  for i =1:n
  #         println(rand())
      if (rand()-1)^2 + (rand()-1)^2 <=1
          sum +=1
      end
  end
  println(4 * sum / n)
end

@time pipi()

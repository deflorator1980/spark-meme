program main
  implicit none
  integer :: n, i
  real :: r, s, res, pi, start, stop
  double precision :: sum

  sum = 0
  n = 10**9

  call cpu_time(start)
  do i = 1, n
    call random_number(r)
    call random_number(s)
    res = (r-1)**2 + (s-1)**2

    if (res <= 1) then
      sum = sum +1
    end if
  end do
  call cpu_time(stop)
  pi = 4 * sum / n
  print *, pi
  print '("Time = ", f6.3, " seconds.")', stop - start

end program main
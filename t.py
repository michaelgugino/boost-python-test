import wsgi_app

def t1(t):
  print(t)

a = wsgi_app.App()
a()

a.apply(t1, 'calling apply')
a.set_fun1(t1)

#a.fun1() doesn't work.
#a.fun1('calling fun1')

#calling a get to return a function and calling that function works.
f2 = a.get_fun1()
f2('calling f2')

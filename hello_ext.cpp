#include <boost/python.hpp>

// http://www.boost.org/doc/libs/1_64_0/libs/python/doc/html/tutorial/index.html#tutorial.quickstart

char const* greet()
{
   return "hello, world";
}


// argument to this should be same name as the libary.so you generate.
BOOST_PYTHON_MODULE(hello_ext)
{
    using namespace boost::python;
    def("greet", greet);
}

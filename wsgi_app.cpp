#include <boost/python.hpp>

// http://www.boost.org/doc/libs/1_64_0/libs/python/doc/html/tutorial/index.html#tutorial.quickstart
using namespace boost::python;

struct App
{

    void apply(PyObject* my_callable, std::string test)
    {
       // callable(test)
       call<void>(my_callable, test);
    }
    void set_response_status(std::string response_status) { this->response_status = response_status; }
    void set_fun1(PyObject* fun1) { this->fun1 = fun1; }
    PyObject* get_fun1() { return fun1; }
    char const* on_call(dict env, PyObject* start_response)
    {
        call<void>(start_response, env.items());
        return "done";
    }
    std::string get_response_status() { return response_status; }
    std::string response_status;
    PyObject* fun1;
};

// def __call__(self, env, start_response):
//      status = "200 OK"
//     start_response(status, headers.items())

// argument to this should be same name as the libary.so you generate.
BOOST_PYTHON_MODULE(wsgi_app)
{
    class_<App>("App")
      .def("__call__", &App::on_call)
      .def("get_response_status", &App::get_response_status)
      .def("set_response_status", &App::set_response_status)
      .def("get_fun1", &App::get_fun1)
      .def("set_fun1", &App::set_fun1)
      .def("apply", &App::apply)
    ;
}

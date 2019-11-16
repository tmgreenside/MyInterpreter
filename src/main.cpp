#include <iostream>
#include <memory>
#include <boost/program_options.hpp>

#include <Interpreter/Interpreter.hpp>

using namespace boost::program_options;
using namespace std;

int main(int argc, char** argv) {
  options_description desc;
  desc.add_options()
    ("help,h", "This")
    ("version,v", "Print version number")
    ("file,f", value<string>(), "Path to main program file")
    ("inspect,i", value<bool>(), "Inspect interactively after running");
  variables_map vm;
  store(parse_command_line(argc, argv, desc), vm);
  notify(vm);

  if (vm.count("help"))
    std::cout << desc << endl;
  else if (vm.count("version"))
    std::cout << "1.0.0" << endl;
  else if (vm.count("file"))
    string file_in = vm["file"].as<string>();
    unique_ptr<Interpreter> m_p_interpreter;
    m_p_interpreter = make_shared<Interpreter>(file_in);
  return 0;
}
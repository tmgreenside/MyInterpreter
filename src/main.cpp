#include <iostream>
#include <memory>
#include <vector>
#include <boost/program_options.hpp>

#include "Interpreter/Interpreter.hpp"

using namespace boost::program_options;
using namespace std;

int main(int argc, char** argv) {
    options_description desc;
    desc.add_options()
        ("help,h", "This")
        ("version,v", "Print version number")
        ("file,f", value<string>(), "Path to main program file")
        ("args,a", value<vector<string>>()->multitoken(), "Main program command line arguments")
        ("inspect,i", value<bool>(), "Inspect interactively after running");
    variables_map vm;
    store(parse_command_line(argc, argv, desc), vm);
    notify(vm);

    if (vm.count("help") || argc < 2)
        cout << desc << endl;
    else if (vm.count("version"))
        cout << "1.0.0" << endl;
    else if (vm.count("inspect"))
        cout << "--inspect,i\tNot implemented yet." << endl;
    else if (vm.count("file")) {
        string file_in;
        vector<string> args_in;
        file_in = vm["file"].as<std::string>();
        unique_ptr<Interpreter> m_p_interpreter;
        if (!vm["args"].empty()){
            args_in = vm["args"].as<vector<string>>();
        }
        m_p_interpreter = make_unique<Interpreter>(file_in, args_in);
    }
    else {
        string file_in = argv[1];
        vector<string> args_in;
        if (argc > 2) {
            for (int i = 2; i < argc; i++) {
                args_in.push_back(argv[i]);
            }
        }
        unique_ptr<Interpreter> m_p_interpreter;
        m_p_interpreter = make_unique<Interpreter>(file_in, args_in);
    }
    return 0;
}

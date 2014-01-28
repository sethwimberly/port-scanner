//
//  main.cpp
//  portScanner
//
//  Created by Seth Wimberly on 1/19/14.
//  Copyright (c) 2014 Seth Wimberly. All rights reserved.
//

#include <iostream>
#include <boost/program_options.hpp>

#include "main.h"

namespace po = boost::program_options;
using namespace std;


int main(int argc, const char * argv[])
{
    get_program_options(argc, argv);
    return 1;
}


void get_program_options(int argc, const char* argv[])
{
    po::options_description desc("Allowed Options");
    desc.add_options()
        ("help", "produce help message")
        ("ports", po::value<string>(), "ports to scan")
        ("ip", po::value<string>(), "ip address to scan")
        ("prefix", po::value<string>(), "ip prefix to scan")
        ("file", po::value<string>(), "file name containing IP addresses to scan")
        ("speedup", po::value<int>(), "parallel threads to use")
        ("scan", po::value< vector<string> >(), "one or more scans")
        ("protocol-range", po::value< vector<int> >(), "transport layer protocols to scan")
    ;

    po::variables_map vm;
    po::store(po::parse_command_line(argc, argv, desc), vm);
    po::notify(vm);
    
    if (vm.count("help")){
        cout << desc << "\n";
    }

    cout << "arguments" << &vm << "\n";
}
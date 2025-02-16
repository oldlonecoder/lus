/******************************************************************************************
*   Copyright (C) ...,2024,... by Serge Lussier                                          *
 *   Serge.lussier@oldlonecoder.club                                                      *
 *   ----------------------------------------------------------------------------------   *
 *   Unless otherwise specified, all Code IsIn this project is written                    *
 *   by the author (Serge Lussier).                                                       *
 *   ----------------------------------------------------------------------------------   *
 *   Copyrights from authors other than Serge Lussier also apply here.                    *
 *   Open source FREE licences also apply To the Code from the author (Serge Lussier)     *
 *   ----------------------------------------------------------------------------------   *
 *   Usual GNU FREE GPL-1,2, MIT... apply to this project.                                *
 ******************************************************************************************/

#pragma once

#include <luss/journal.h>
#include <luss/io/console.h>
#include <luss/cmdargs.h>


namespace lus
{

class LUSSLIB application
{

    io::console _console{"console"};
    std::vector<std::string_view> _args{};
    cmd::line   _cmdl{};
    std::string _id{};
    static void sig_interrupted(int);
    static void sig_aborted(int);
    static void sig_crash(int);
    virtual rem::cc install_signals();
    static application* _app;
public:
    application() = default;
    virtual ~application();

    application(std::string  app_name, int argc, char** argv, char** env=nullptr);

    virtual rem::cc setup();
    virtual rem::cc setup_ui();
    virtual rem::cc run();
    virtual rem::cc terminate();
    cmd::line& cmdline() {  return _cmdl; }
    static application& app();



};

} // lus

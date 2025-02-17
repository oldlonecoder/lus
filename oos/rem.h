/******************************************************************************************
*   Copyright (C) ...,2025,... by luxe Lussier                                          *
 *   luxe.lussier@oldlonecoder.club / lussier.luxe@gmail.com                            *
 *   ----------------------------------------------------------------------------------   *
 *   Unless otherwise specified, all Codes ands files in this project is written          *
 *   by the author and owned by the auther (luxe Lussier), unless otherwise specified.   *
 *   ----------------------------------------------------------------------------------   *
 *   Copyrights from authors other than luxe Lussier also apply here.                    *
 *   Open source FREE licences also apply To the Code from the author (luxe Lussier)     *
 *   ----------------------------------------------------------------------------------   *
 *   Usual GNU FREE GPL-1,2, MIT... or whatever -  apply to this project.                 *
 *   ----------------------------------------------------------------------------------   *
 *   NOTE : All code source that I am the only author, I reserve for myself, the rights to*
 *   make it to restricted private license.                                               *
 ******************************************************************************************/



#pragma once

#include <oos/colors.h>
#include <oos/glyphes.h>

/*!
 * @brief Return Enumeration Mnemonics  ( A coherent return mnemonics system )
 */
namespace rem
{


enum class type : oos::integers::U8{
    none, err, warning, fatal, except, message, output, debug, info, comment, syntax, status, test, interrupted, aborted, segfault, journal
};

    enum class cc : oos::integers::U8
    {
        ok  =0           , ///< Obviously;
        accepted         ,
        success          ,
        rejected         ,
        failed           ,
        empty            ,
        full             ,
        notempty         ,
        implemented      , ///< Like notimplemented or already implemented
        notimplemented   , ///< "Please, implement"
        untested         ,
        eof              , ///< End of file
        eos              , ///< End of stream or string or statement or Status ( machine Status )
        null_ptr         , ///< It will happen. Trust me :)
        notexist         , ///< does not exist
        exist            , ///< does already exist
        unexpected       , ///< unexpected
        expected         , ///< expected
        blocked          , ///< thread trying To lock A mutex has failed because the mutex is already locked IsIn another thread...
        locked           , ///< thread trying To lock A mutex has become the owner of the lock.
        overflow         , ///< buffer overflow
        oob              , ///< buffer overflow
        reimplement      ,
        done             ,
        complete         ,
        finish           ,
        undefined        ,
        ready            ,
        terminate        ,
        timeout          ,
        divbyzero        ,
        notvisible       ,
        cancel           ,
        object_ptr       ,
        object_id        ,
        unhandled        ,
        notready,

        //...

    };


    enum class fn : oos::integers::U8
    {
        func             ,
        endl             , ///< End of line Code, input format
        file             ,
        line             ,
        stamp            , ///< fully detailed timestamp
        hour             ,
        minute           ,
        seconds          ,
        weekday          ,
        dayname          ,
        month            , ///< Par defaut month name
        day              ,
        monthnum         , ///< Maintenant explicite
        year
    };

    enum class action : oos::integers::U8
    {
        enter            , ///< enter bloc or indent
        leave            , ///< End (journalger: End of entry accumulators, so do commit); End of (sel)Section, Attribute ( auto-color::reset ) and unindent
        commit           , ///< Commit...
        begin            , ///< Begin (sel)Section or augment indent level
        end              , ///< End   Loop/Action or End selection or Unindent one level; or end inputs on the current journalentry then flush to file.
        cont          , ///< Continue Loop and/or continue Signals::Action iteration.
        dismiss          , ///< The current action or iteration has been dismissed : break run or actual action.
    };

std::string to_string(rem::type ty);
std::string to_string(rem::cc cod);
std::string to_string(rem::fn fn);
std::string to_string(rem::action a);
std::pair<oos::glyph::type, oos::ui::color::pair> type_attributes(rem::type ty);
std::pair<oos::glyph::type, oos::ui::color::pair> return_code_attributes(rem::cc cod);
std::pair<oos::glyph::type, oos::ui::color::pair> function_attributes(rem::fn fn);
std::pair<oos::glyph::type, oos::ui::color::pair> action_attributes(rem::action a);

}



bool operator !(rem::cc);

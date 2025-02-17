#include <map>
#include <oos/rem.h>

//#include <vector>

using oos::ui::color;
using oos::glyph;
using oos::accent_fr;

bool operator !(rem::cc c)
{
    return (c != rem::cc::accepted)&&
           (c != rem::cc::ok)      &&
           (c != rem::cc::success) &&
           (c != rem::cc::done)    &&
           (c != rem::cc::ready)   &&
           (c != rem::cc::finish)  &&
           (c != rem::cc::complete);
}

namespace rem
{
std::map<rem::type, const char*> enums_type_dictionary = {
    {rem::type::none,        "none"},
    {rem::type::err  ,       "err"},
    {rem::type::warning,     "warning"},
    {rem::type::fatal,       "fatal"},
    {rem::type::except,      "exception"},
    {rem::type::message,     "message"},
    {rem::type::output,      ""},
    {rem::type::debug,       "debug"},
    {rem::type::info,        "info"},
    {rem::type::comment,     "comment"},
    {rem::type::syntax,      "syntax error"},
    {rem::type::status,      "status"},
    {rem::type::test,        "test"},
    {rem::type::interrupted, "interrupted"},
    {rem::type::aborted,     "aborted"},
    {rem::type::segfault,    "segmentation fault"},
    {rem::type::journal,         "journal"}
};


std::map<rem::cc, const char*> return_codes_dictionary = {
    {rem::cc::ok,             "ok"},
    {rem::cc::accepted,       "accepted"},
    {rem::cc::success,        "success "},
    {rem::cc::rejected,       "rejected"},
    {rem::cc::failed,         "failed"},
    {rem::cc::empty,          "empty"},
    {rem::cc::full,           "full"},
    {rem::cc::notempty,       "not empty"},
    {rem::cc::implemented,    "implemented"},
    {rem::cc::notimplemented, "not implemented"},
    {rem::cc::untested,       "untested"},
    {rem::cc::eof,            "end of file"},
    {rem::cc::eos,            "end of stream or string"},
    {rem::cc::null_ptr,       "null pointer"},
    {rem::cc::notexist,       "does not exist"},
    {rem::cc::exist,          "exist"},
    {rem::cc::unexpected,     "unexpected"},
    {rem::cc::expected,       "expected"},
    {rem::cc::blocked,        "blocked"},
    {rem::cc::locked,         "locked"},
    {rem::cc::overflow,       "buffer overflow"},
    {rem::cc::oob,            "out of boundaries"},
    {rem::cc::reimplement,    "need to be re-implemented in derived instances"},
    {rem::cc::done,           "done"},
    {rem::cc::complete,       "completed"},
    {rem::cc::finish,         "finished"},
    {rem::cc::undefined,      "undefined"},
    {rem::cc::ready,          "ready"},
    {rem::cc::terminate,      "terminate"},
    {rem::cc::timeout,        "timeout"},
    {rem::cc::divbyzero,      "division by zero"},
    {rem::cc::notvisible,     "not visible"},
    {rem::cc::cancel,         "cancel"},
    {rem::cc::object_ptr,     "pointer to object"},
    {rem::cc::object_id,      "object id"},
    {rem::cc::unhandled,      "unhandled"},
    {rem::cc::notready,      "not ready"},
};


std::map<rem::action, const char*> actions_dictionary= {
    {rem::action::enter,   "enter"},
    {rem::action::leave,   "leave"},
    {rem::action::begin,   "begin"},
    {rem::action::end,     "end"},
    {rem::action::commit,  "commit"},
    {rem::action::cont,    "continue"},
    {rem::action::dismiss, "dismissed"},
};


std::map<rem::fn, const char*> functions_dictionary= {

    {rem::fn::endl,           "end line"},
    {rem::fn::func,            "function"},
    {rem::fn::file,           "file"},
    {rem::fn::line,           "line"},
    {rem::fn::stamp,          "stamp"},
    {rem::fn::hour,           "hour"},
    {rem::fn::minute,         "minute"},
    {rem::fn::seconds,        "seconds"},
    {rem::fn::weekday,        "weekday"},
    {rem::fn::month,          "month name"},
    {rem::fn::dayname,        "day name"},
    {rem::fn::day,            "day"},
    {rem::fn::monthnum,       "month number"},
    {rem::fn::year,           "year"}
};




std::string to_string(rem::type ty)
{
    return enums_type_dictionary[ty];
}

std::string to_string(rem::cc cod)
{
    return return_codes_dictionary[cod];
}



std::string to_string(rem::fn fn)
{
    return functions_dictionary[fn];
}

std::string to_string(rem::action ac)
{
    return actions_dictionary[ac];
}

std::map<rem::type, std::pair<oos::glyph::type, color::pair>> types_database={

    {rem::type::none,        {oos::glyph::computer,  {color::aquamarine1         , color::reset }}},
    {rem::type::err,         {oos::glyph::err1,      {color::red4                , color::reset }}},
    {rem::type::warning,     {oos::glyph::warning,   {color::yellow              , color::reset }}},
    {rem::type::fatal,       {oos::glyph::dead_head, {color::hotpink4            , color::reset }}},
    {rem::type::except,      {oos::glyph::bolt,      {color::skyblue3            , color::reset }}},
    {rem::type::message,     {oos::glyph::comment,   {color::green4              , color::reset }}},
    {rem::type::output,      {oos::glyph::notepad,   {color::grey39              , color::reset }}},
    {rem::type::debug,       {oos::glyph::bug,       {color::pink3               , color::reset }}},
    {rem::type::info,        {oos::glyph::info,      {color::lightskyblue4       , color::reset }}},
    {rem::type::comment,     {oos::glyph::comment,   {color::grey42              , color::reset }}},
    {rem::type::syntax,      {oos::glyph::handwrite, {color::lighcoreateblue     , color::reset }}},
    {rem::type::status,      {oos::glyph::admin,     {color::lightcyan3          , color::reset }}},
    {rem::type::test,        {oos::glyph::file,      {color::aquamarine3         , color::reset }}},
    {rem::type::interrupted, {oos::glyph::circle_x,     {color::khaki3              , color::reset }}},
    {rem::type::aborted,     {oos::glyph::stop,      {color::red4                , color::reset }}},
    {rem::type::segfault,    {oos::glyph::bomb,      {color::sandybrown          , color::reset }}},
    {rem::type::journal,         {oos::glyph::journal,       {color::orangered1          , color::reset }}}
    //...
};


std::map<rem::action      , std::pair<oos::glyph::type, color::pair>> actions_color_db = {
    {rem::action::enter   , {oos::glyph::enter        , {color::white               , color::reset}}},
    {rem::action::leave   , {oos::glyph::file         , {color::white               , color::reset}}},
    {rem::action::begin   , {oos::glyph::chronos      , {color::white               , color::reset}}},
    {rem::action::end     , {oos::glyph::dead_head    , {color::white               , color::reset}}},
    {rem::action::commit  , {oos::glyph::pencil_dr    , {color::white               , color::reset}}},
    {rem::action::cont , {oos::glyph::success      , {color::white               , color::reset}}},
    {rem::action::dismiss , {oos::glyph::arrow_dhead_right , {color::yellow         , color::reset}}},
};

std::map<rem::cc, std::pair<oos::glyph::type, color::pair>> codes_database={
    {rem::cc::ok,              {oos::glyph::thumb_up,        {color::lime              ,color::reset }}},
    {rem::cc::accepted,        {oos::glyph::thumb_up,        {color::lime              ,color::reset }}},
    {rem::cc::success,         {oos::glyph::success,         {color::darkgreen         ,color::reset }}},
    {rem::cc::rejected,        {oos::glyph::thumb_down,      {color::hotpink4          ,color::reset }}},
    {rem::cc::failed,          {oos::glyph::poop,            {color::darkgoldenrod     ,color::reset }}},
    {rem::cc::empty,           {oos::glyph::arrowright,      {color::lighcoreategrey   ,color::reset }}},
    {rem::cc::full,            {oos::glyph::small_dot,       {color::white             ,color::reset }}},
    {rem::cc::notempty,        {oos::glyph::big_dot,         {color::white             ,color::reset }}},
    {rem::cc::implemented,     {oos::glyph::arrow_head_right,{color::lime              ,color::reset }}},
    {rem::cc::notimplemented,  {oos::glyph::err1,            {color::orange3           ,color::reset }}},
    {rem::cc::untested,        {oos::glyph::flag,            {color::yellow            ,color::reset }}},
    {rem::cc::eof,             {oos::glyph::baseline,        {color::white             ,color::reset }}},
    {rem::cc::eos,             {oos::glyph::baseline,        {color::white             ,color::reset }}},
    {rem::cc::null_ptr,        {oos::glyph::circle_x,        {color::hotpink4          ,color::reset }}},
    {rem::cc::notexist  ,      {oos::glyph::circle_x ,       {color::white             ,color::reset }}},
    {rem::cc::exist     ,      {oos::glyph::star5 ,          {color::white             ,color::reset }}},
    {rem::cc::unexpected,      {oos::glyph::flag ,           {color::yellow            ,color::reset }}},
    {rem::cc::expected  ,      {oos::glyph::cat ,            {color::white             ,color::reset }}},
    {rem::cc::blocked   ,      {oos::glyph::unauth ,         {color::indianred3        ,color::reset }}},
    {rem::cc::locked    ,      {oos::glyph::err3 ,           {color::white             ,color::reset }}},
    {rem::cc::overflow  ,      {oos::glyph::dead_head,       {color::red4              ,color::reset }}},
    {rem::cc::oob       ,      {oos::glyph::alien,           {color::lightcoral        ,color::reset }}},
    {rem::cc::reimplement,     {oos::glyph::journal,             {color::yellow            ,color::reset }}},
    {rem::cc::done       ,     {oos::glyph::ok,              {color::yellow            ,color::reset }}},
    {rem::cc::complete   ,     {oos::glyph::ok,              {color::yellow            ,color::reset }}},
    {rem::cc::finish     ,     {oos::glyph::ok,              {color::lime              ,color::reset }}},
    {rem::cc::undefined  ,     {oos::glyph::err3,            {color::red               ,color::reset }}},
    {rem::cc::ready      ,     {oos::glyph::ok,              {color::lime              ,color::reset }}},
    {rem::cc::terminate  ,     {oos::glyph::flag,            {color::hotpink4          ,color::reset }}},
    {rem::cc::timeout    ,     {oos::glyph::chronos,         {color::lime              ,color::reset }}},
    {rem::cc::divbyzero  ,     {oos::glyph::circle_x,        {color::red4              ,color::reset }}},
    {rem::cc::notvisible ,     {oos::glyph::circle_x,        {color::yellow            ,color::reset }}},
    {rem::cc::cancel     ,     {oos::glyph::circle_x,        {color::red4              ,color::reset }}},
    {rem::cc::object_ptr ,     {oos::glyph::edit_pencil_br,{color::lightsteelblue3     ,color::reset }}},
    {rem::cc::object_id ,      {oos::glyph::arrowright,      {color::yellow            ,color::reset }}},
    {rem::cc::unhandled ,      {oos::glyph::alien,           {color::yellow            ,color::reset }}},
    {rem::cc::notready ,       {oos::glyph::circle_x,           {color::orange5            ,color::reset }}},
};


std::map<rem::fn, std::pair<oos::glyph::type, color::pair>> functions_database={

    {rem::fn::stamp     ,      {oos::glyph::chronos  ,   {color::skyblue3          ,color::reset }}},
    {rem::fn::func      ,      {oos::glyph::function ,   {color::skyblue3          ,color::reset }}},
    {rem::fn::file      ,      {oos::glyph::file     ,   {color::lightcyan3        ,color::reset }}},
    {rem::fn::line      ,      {oos::glyph::baseline ,   {color::lime              ,color::reset }}},
    {rem::fn::stamp     ,      {oos::glyph::chronos  ,   {color::yellow            ,color::reset }}},
    {rem::fn::hour      ,      {oos::glyph::chronos  ,   {color::white             ,color::reset }}},
    {rem::fn::minute    ,      {oos::glyph::chronos  ,   {color::white             ,color::reset }}},
    {rem::fn::seconds   ,      {oos::glyph::chronos  ,   {color::white             ,color::reset }}},
    {rem::fn::weekday   ,      {oos::glyph::fabric   ,   {color::yellow            ,color::reset }}},
    {rem::fn::month     ,      {oos::glyph::chronos  ,   {color::white             ,color::reset }}},
    {rem::fn::dayname   ,      {oos::glyph::star5    ,   {color::white             ,color::reset }}},
    {rem::fn::day       ,      {oos::glyph::star5    ,   {color::white             ,color::reset }}},
    {rem::fn::monthnum  ,      {oos::glyph::star5    ,   {color::white             ,color::reset }}},
    {rem::fn::year      ,      {oos::glyph::star5    ,   {color::white             ,color::reset }}}

};





std::pair<oos::glyph::type, color::pair> type_attributes(rem::type ty)
{
    return rem::types_database[ty];
}

std::pair<oos::glyph::type, color::pair> return_code_attributes(rem::cc cod)
{
    return rem::codes_database[cod];
}

std::pair<oos::glyph::type, color::pair> function_attributes(rem::fn fn)
{
    return rem::functions_database[fn];
}

std::pair<oos::glyph::type, color::pair> action_attributes(rem::action a)
{
    return rem::actions_color_db[a];
}


}

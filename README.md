
# project lus( my out of standard base code Library )
- No smart pointers.
- Bare minimum decl(...)-forward types to make the compiler NOT to program in my place.

# Roadmap of this hobbist project

### Exploring, Learning and write a set of C++ framework of (from my own) libraries

## core support classes ( namespace lus ) main directory( for ex.: #include <oos/string.h>)

    - [class oos::string]
        Composite accumulator for serializing and formatting supported components into its container - std::string.
    - [oos::color]
        Ansi (and future HTML) colours mnemonics and renderers
    - [rem :  return enumrated mnemonic]
        Coherant global return mnemonic codes.
        Also used by the messaging system and journals.
    - [class oos::signals::notify; oos::signals::signotify ]
        C++ template header for basic signal-slots - A modified copy of :
        https://schneegans.github.io/tutorials/2015/09/20/signal-slot
        -> Not fully multi-threads yet, but I am starting to explore using a working notify signals across threads.
    - [class oos::ui::application]
        Base application class..., will holds and manage the config data of the components and events queu, and will manage a threads pool.
    - [ oos::ui::geometry classes ]
        {oos::ui::cxy, oos::ui::size, oos::ui::rectangle, oos::ui::string2d} Bare 2D geometry components.
    - [class  oos::object]
        Base Object class on the parent-child relational journalistic ( smart-pointers not used there - Too much overload (yet?) )
    -[class  oos::glyph and  oos::accent_fr]
        Actually, some hardcoded unicode and french accent glyphes. Waiting to find a coherant and a definitive easy to use unicode API.
    -[oos::cmd::cmd_switch oos::cmd::line,  with notify-hook]
        Developping my own command-line arguments processor.
        -> It is very hard to create a coherent realistic model. POSIX or not, the syntax is a mess because there is NO format rules excepted white space separators and confused quotes and subshell/commands tokens.
    
---
---
copyrights ...,2025,... Serge Lussier

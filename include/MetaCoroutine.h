#pragma once

#include "config/Export.h"

struct lua_State;

namespace nbe
{
    class Lua;

    class NODEBACKEND_API MetaCoroutine
    {
    public:
        enum Error
        {
            NoError,
            FailedToMoveFunction,
            FailedToResume
        };
    public:
        //! Expects the function on the top of the stack.
        MetaCoroutine(Lua & lua);

        bool ok() const
        {
            return _errod == NoError;
        }

        lua_State * thread()
        {
            return _thread;
        }

        Error error() const
        {
            return _errod;
        }

        int resume(int* nres);
    private:
        Error _errod;
        Lua & _lua;
        lua_State * _thread;
    };
}

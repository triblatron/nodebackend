//
// Created by tony on 18/02/24.
//
#include "config/config.h"

#include "SignalPath.h"
#include "InputStream.h"
#include "TypedPort.h"
#include "NodeLibrary.h"
#include "OutputStream.h"
#include "Node.h"

namespace dag
{
    SignalPathID SignalPath::_nextID = 0;

    OutputStream &SignalPath::write(OutputStream &str) const
    {
        str.write(_id);
        if (str.writeRef(_source))
        {
            _source->write(str);
        }
        if (str.writeRef(_dest))
        {
            _dest->write(str);
        }
        str.write(_flags);

        return str;
    }


    SignalPath::SignalPath(InputStream &str, NodeLibrary& nodeLib)
    :
    _source(nullptr),
    _dest(nullptr),
    _flags(0x0)
    {
        str.read(&_id);

        _source = str.readPort(nodeLib);
        _dest = str.readPort(nodeLib);

        str.read(&_flags);
    }

    std::ostream &SignalPath::toLua(std::ostream &str)
    {
        str << "{ ";
        str << "sourceNode = \"" << _source->parent()->name() << "\", ";
        str << "sourcePort = " << _source->parent()->indexOfPort(_source) << ", ";
        str << "destNode = \"" << _dest->parent()->name() << "\", ";
        str << "destPort = " << _dest->parent()->indexOfPort(_dest);
        str << " }";

        return str;
    }
}

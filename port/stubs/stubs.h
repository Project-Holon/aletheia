/*
 * port/stubs/stubs.h -- the two shapes a not-yet-matched game function may
 * take in the port, and nothing else.
 *
 * A matched translation unit calls game functions that have not been
 * decompiled yet.  The linker needs a definition for each; the port refuses
 * to invent behaviour for them.  So each one gets its own file, holding
 * exactly one symbol, in one of two shapes:
 *
 *   BW_STUB       the honest shape.  Aborts naming the DS address.  Use it
 *                 whenever the function's behaviour is not attested by
 *                 something already in the tree.  If a test reaches one, the
 *                 test is wrong about its closure and says so loudly.
 *
 *   a reimplementation, written out by hand with a header comment that cites
 *                 where the behaviour is attested (a matched caller, a
 *                 docs/notes entry, an asset tool that round-trips against
 *                 it).  Never a guess.  These are the port's own code and
 *                 are NOT claimed to be byte-matching: when the real function
 *                 is decompiled, the reimplementation is deleted and the
 *                 matched file takes its place in port/CMakeLists.txt.
 *
 * One symbol per file is load bearing.  The port library is a static
 * archive, so a stub is only pulled in when nothing else defines the symbol;
 * that is what lets a test supply its own substitute for one function
 * without displacing any other.
 */

#ifndef BW_PORT_STUBS_H
#define BW_PORT_STUBS_H

#include "../sdk/port.h"

#define BW_STUB(name, addr, what)                      \
    void name(void)                                    \
    {                                                  \
        bw_panic("unimplemented game function",        \
                 (u32)(addr), what);                   \
    }

#endif /* BW_PORT_STUBS_H */

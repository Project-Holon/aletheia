/*
 * port/sdk/aliases.c -- name aliases between matched files that spell the
 * same address two different ways.
 *
 * The DS build never needs these.  tools/csrc.py resolves a relocation to an
 * *address*, so a file that declares `extern void func_02034734(...)` and a
 * file that defines `void sub_02034734(...)` agree perfectly: both name
 * 0x02034734 and the splice lands at 0x02034734.  A host linker resolves by
 * name, and those two are different names.
 *
 * So every divergent pair needs one forwarder here, and
 * `python tools/port/closure.py` prints them under `alias` so the list can be
 * kept complete mechanically rather than by waiting for a link error.
 *
 * These forwarders are port code and are never compiled into the DS build.
 * The right long-term fix is a naming convention in src/matched/ (one prefix
 * per address, chosen by whoever matches it first), but renaming a symbol in
 * a matched file means re-verifying that file against the ROM, so it is the
 * integrator's call and not this lane's.
 */

#include "port.h"

/*
 * 0x02034734, the assertion sink.
 *
 *   defined  as sub_02034734  in src/matched/sub_02034734.c
 *   declared as func_02034734 in src/matched/func_02049578.c
 *                              and src/matched/func_0204944C.c
 *
 * The variadic tail is dropped rather than forwarded: sub_02034734's body
 * reads only the handler out of g_Sink and ignores every argument, so there
 * is nothing to forward, and C has no portable way to pass `...` on.
 */
extern void sub_02034734(const char *expr, u32 line, const char *file, ...);

void func_02034734(const char *expr, u32 line, const char *file, ...)
{
    sub_02034734(expr, line, file);
}

/*
 * port/sdk/game_globals.c -- the ARM9 global objects the matched code reaches
 * by name, defined for the host.
 *
 * These are not SDK functions.  They are the *data* half of the shim: objects
 * that live at fixed addresses in the DS image and that some not-yet-matched
 * start-up code initialises there.  Until that start-up code is decompiled,
 * the port creates each object itself and documents what fills it.
 *
 * `python tools/port/closure.py --seed ...` lists these under the `data`
 * class; every name in that list must appear here or the link fails, which is
 * exactly the agreement between the closure script and the linker the port is
 * built around.
 *
 * Two of the definitions below deliberately differ from the matched file's
 * own declaration, and both differences are findings, not conveniences:
 *
 *  1. `g_02146270` (src/matched/unit_02019C54.c) is declared there as
 *
 *         struct Memo { u16 b; u16 a; u8 obj[0x10]; };
 *
 *     but the write into `obj` is 0x3C bytes wide: src/matched/unit_0201ADA4.c
 *     calls func_020495F4(handle, 0x3C, dest) with that same buffer, and 0x3C
 *     is the personal record's size.  On the DS the under-declaration is
 *     harmless, because the real object at 0x02146274 is a plain global with
 *     the rest of the record after it and nothing in unit_02019C54.c indexes
 *     past +0x10.  On the host the object has to be big enough or the write
 *     runs off it, so it is defined here at the true size.  The matched file
 *     is left exactly as it is; it still produces the right DS bytes.
 *
 *  2. `func_02019B04_Table` (src/matched/unit_02019B04.c) is declared there
 *     `const s8 [][5]`.  The port cannot define it const, because its
 *     contents are game data that has to be copied in at run time out of the
 *     player's own extracted ARM9 image.  A definition whose qualifiers
 *     differ from another translation unit's declaration is outside what C99
 *     guarantees; it links and behaves correctly on every toolchain this port
 *     targets, and the alternative (editing the matched file) is forbidden.
 *     Recorded in port/README.md under "Known type mismatches".
 */

#include <string.h>

#include "port.h"

/* ------------------------------------------------------------------ */
/* g_Sink -- the assertion sink src/matched/sub_02034734.c dispatches to */
/* ------------------------------------------------------------------ */

typedef void (*BwAssertHandler)(void);

struct BwSink {
    u32 unk0;
    u32 unk4;
    u32 unk8;
    BwAssertHandler handler;
};

static void sink_handler(void)
{
    bw_panic("game assertion", 0x02034734, "sub_02034734 assert sink fired");
}

struct BwSink g_Sink = { 0, 0, 0, sink_handler };

/* ------------------------------------------------------------------ */
/* The __FILE__ / message strings the archive readers pass to the sink  */
/* ------------------------------------------------------------------ */

/*
 * On the DS these are pointers into the packed string area (0x020A7EE0 and
 * 0x020A7F18 for func_02049578, 0x020A78xx for func_0204944C), and the
 * matched files declare them as externs pinned by address because a
 * `__FILE__` literal has no attestable witness of its own
 * (docs/idioms/file-string-is-an-abs32-into-the-string-area.md).  Their
 * contents never affect behaviour: they are arguments to an assert that only
 * fires on an out-of-range member.  The port supplies its own text, which is
 * why no ROM string is reproduced here.
 */
const char func_02049578_File[] = "arc_tool.c";
const char func_02049578_Msg[]  = "member index out of range";
const char func_0204944C_File[] = "arc_tool.c";
const char func_0204944C_Msg[]  = "member index out of range";

/* ------------------------------------------------------------------ */
/* g_02146270 -- the one-entry personal-record memo                     */
/* ------------------------------------------------------------------ */

#define BW_PERSONAL_RECORD_SIZE 0x3C

struct BwMemo {
    u16 b;
    u16 a;
    u8  obj[BW_PERSONAL_RECORD_SIZE + 4];   /* see note 1 above */
};

struct BwMemo g_02146270;

/* ------------------------------------------------------------------ */
/* g_0214652C -- the personal-data archive handle                       */
/* ------------------------------------------------------------------ */

static BwArcFile g_personal_arc;

void *g_0214652C;

int bw_open_personal_archive(void)
{
    if (g_0214652C != NULL) {
        return 0;
    }
    if (bw_arc_open(&g_personal_arc, "a/0/1/6") != 0) {
        return -1;
    }
    g_0214652C = &g_personal_arc;

    /*
     * The memo caches by (a, b) and starts zeroed, which would read as
     * "species 0, form 0 already loaded".  Poison the key so the first real
     * call always misses and goes to the archive.
     */
    g_02146270.a = 0xFFFF;
    g_02146270.b = 0xFFFF;
    memset(g_02146270.obj, 0, sizeof(g_02146270.obj));
    return 0;
}

void bw_close_personal_archive(void)
{
    if (g_0214652C == NULL) {
        return;
    }
    bw_arc_close(&g_personal_arc);
    g_0214652C = NULL;
}

/* ------------------------------------------------------------------ */
/* func_02019B04_Table -- the nature multiplier table                   */
/* ------------------------------------------------------------------ */

/*
 * 25 natures by 5 stats of { -1, 0, +1 }, at ARM9 0x0209E324.  The index is
 * [nature][n - 1] with n as src/matched/sub_02018A7C.c passes it: 1 attack,
 * 2 defence, 3 sp. attack, 4 sp. defence, 5 speed.  Loaded from the player's
 * own extract/arm9_dec.bin; never stored in this repository.
 */
#define BW_NATURE_TABLE_ADDRESS 0x0209E324u
#define BW_NATURE_COUNT         25
#define BW_NATURE_STATS         5

s8 func_02019B04_Table[BW_NATURE_COUNT][BW_NATURE_STATS];

int bw_load_nature_table(void)
{
    const void *src = bw_arm9_rodata(BW_NATURE_TABLE_ADDRESS,
                                     BW_NATURE_COUNT * BW_NATURE_STATS);

    if (src == NULL) {
        return -1;
    }
    memcpy(func_02019B04_Table, src, BW_NATURE_COUNT * BW_NATURE_STATS);
    return 0;
}

/*
 * function: sub_0200EEAC
 * address:  0x0200EEAC
 * packet:   pkt_0200EE64
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * promoted: from src/pending on 2026-09-19, no C change: its blocker is filed,
 *           every relocation site resolves and match.py one reports EXACT*.
 * status:   EXACT*
 *
 * symbols:
 *   func_0200F104  0x0200F104  thumb
 *   func_0200EF78  0x0200EF78  thumb
 *
 * Walks 64 0x50-byte records; for each whose leading word has bit 0 set,
 * looks up a free slot with func_0200F104 and hands it, the record and
 * the context to func_0200EF78. Stores the record count (always 0x40)
 * into the context at +6 once the walk finishes.
 *
 * Every concrete byte matches; func_0200F104 (a documented near miss,
 * still open) and func_0200EF78 are each called from exactly this one
 * site in the whole ROM, so both relocations stay unresolved under the
 * honesty rule.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0200EEAC.c \
 *       --func sub_0200EEAC --addr 0x0200EEAC --cc 1.1p1
 *
 * The `matched` class does not reach it: neither func_0200F104 nor
 * func_0200EF78 is matched, so no EXACT entry covers either address.  It closes
 * when one of the two is matched, or when the image acquires a second caller.
 */
#include "../include/Obj00606.h"

typedef unsigned char u8;
typedef unsigned int u32;

extern void *func_0200F104(void *ctx);
extern void func_0200EF78(void *slot, const void *rec, void *ctx);

void sub_0200EEAC(void *ctx, void *list)
{
    u8 *rec = (u8 *)list;
    u32 i;

    for (i = 0; i < 0x40; i++, rec += 0x50) {
        if (((struct Obj00606 *)rec)->f0 & 1) {
            func_0200EF78(func_0200F104(ctx), rec, ctx);
        }
    }

    *(unsigned short *)((u8 *)ctx + 6) = (unsigned short)i;
}

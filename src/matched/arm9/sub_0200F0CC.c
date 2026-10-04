/*
 * function: sub_0200F0CC
 * address:  0x0200F0CC
 * packet:   pkt_0200F168
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Scans an array of 0x100-byte records starting at *idxptr, looking for one
 * whose leading word has bit 0 set. obj+4 holds a u16 record count and
 * obj+0x18 holds the array base. On a hit, *out gets the record pointer,
 * *idxptr is left one past the hit, and the function returns 1; scanning
 * to the end without a hit returns 0, leaving *idxptr == count. The two
 * "return 0" paths (guard and loop exhaustion) are separate, out-of-line
 * blocks rather than a shared tail; see
 * docs/idioms/a-shared-exit-block-is-written-out-in-each-arm.md.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0200F0CC.c \
 *       --func sub_0200F0CC --addr 0x0200F0CC --cc 1.1p1
 */
#include "../include/Obj11712.h"
#include "../include/Obj16720.h"
#include "../include/Obj16721.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

u32 sub_0200F0CC(const void *obj, void *out, u32 *idxptr)
{
    u32 count = *(const u16 *)&((struct Obj11712 *)obj)->f4;
    u32 idx = *idxptr;
    u8 *rec;

    if (idx < count) {
        rec = *(u8 * *)&((struct Obj11712 *)obj)->f18 + idx * 0x100;
        do {
            *idxptr = *idxptr + 1;
            if (((struct Obj16721 *)rec)->f0 & 1) {
                ((struct Obj16720 *)out)->f0 = rec;
                return 1;
            }
            rec += 0x100;
        } while (*idxptr < count);
    }
    return 0;
}

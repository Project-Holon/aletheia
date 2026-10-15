/*
 * function: MISC_SAVEDATA_GetRecordDate
 * address:  0x0200EC98
 * packet:   pkt_0200EC98
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * An unlabelled leaf accessor (it saves no lr, so disasm.py gives it no
 * label, see docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).
 * It unpacks the three fields at +0x168..+0x16b of the object into a
 * four-word output record and zeroes the fourth word.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/MISC_SAVEDATA_GetRecordDate.c \
 *       --func MISC_SAVEDATA_GetRecordDate --addr 0x0200EC98 --cc 1.1p1 --thumb
 */
#include "../include/Obj08961.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Out0200EC98 {
    u32 a;
    u32 b;
    u32 c;
    u32 d;
};

void MISC_SAVEDATA_GetRecordDate(const u8 *o, struct Out0200EC98 *out)
{
    out->a = *(const u16 *)&((struct Obj08961 *)o)->f168;
    out->b = o[0x16a];
    out->c = o[0x16b];
    out->d = 0;
}

/*
 * unit: yes
 * function: PMS_INPUT_DATA_GetInitialWordId, PMS_INPUT_DATA_GetWordString
 * address: 0x021B99F0
 * packet: pkt_ov110_021B99F0
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: explicit if/else increments preserve the branch after the skip call.
 * symbols:
 *   d_021C1C88 0x021C1C88 data ov110 a4
 *   PMS_INPUT_DATA_SkipRangeEntry 0x021B99E4 thumb ov110
 *   PMS_WORD_GetString  0x02024810  thumb  arm9
 */
#include "../include/Obj07996.h"
#include "../include/Obj22314.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern u8 *d_021C1C88[];
extern u8 *PMS_INPUT_DATA_SkipRangeEntry(u8 *);
extern int PMS_WORD_GetString(u8 *);
u16 PMS_INPUT_DATA_GetInitialWordId(int unused, int id, int index) {
    u8 *p = d_021C1C88[id];
    int n = 0;
    while (((struct Obj07996 *)p)->f0 != 65535) {
        if (n == index) {
            if (((struct Obj07996 *)p)->f0 == 65534) p = PMS_INPUT_DATA_SkipRangeEntry(p);
            return ((struct Obj07996 *)p)->f0;
        }
        if (((struct Obj07996 *)p)->f0 == 65534) {
            p = PMS_INPUT_DATA_SkipRangeEntry(p);
            p += 2;
        } else {
            p += 2;
        }
        ++n;
    }
    return 0;
}
int PMS_INPUT_DATA_GetWordString(u8 *p, u16 a1, int a2) { return PMS_WORD_GetString(*(u8 * *)&((struct Obj22314 *)p)->f4); }

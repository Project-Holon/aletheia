/*
 * function: func_0217F1E8
 * address: 0x0217F1E8
 * packet: pkt_ov018_0217F1E8
 * region: ov018
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: Two bytes of alignment padding at 0x0217F212.
 * symbols:
 *   func_020120F4 0x020120F4 thumb
 *   func_02012B70 0x02012B70 thumb
 */
#include "../include/Obj00092.h"
typedef unsigned char u8;
struct BigObj;
struct Ctx;
extern void *func_020120F4(const struct Ctx *p);
extern int func_02012B70(const struct BigObj *p);
int func_0217F1E8(u8 *p)
{
    if (func_02012B70(func_020120F4(((struct Obj00092 *)p)->f0)) == 1) {
        switch (((struct Obj00092 *)p)->fDC) {
        case 2: case 3: case 4: return 1;
        }
    }
    return 0;
}

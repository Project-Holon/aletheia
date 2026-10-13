/*
 * function: func_02164844
 * address:  0x02164844
 * packet:   pkt_ov010_02164844
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Looks up a table entry; 0xFFFF means missing and forwards to
 * ZONEDATA_GetWeatherId, otherwise reads one byte through func_0204944C.
 *
 * symbols:
 *   func_021648A8  0x021648A8  thumb ov010
 *   ZONEDATA_GetWeatherId  0x02013C10  thumb
 *   func_021648CC  0x021648CC  thumb ov010
 *   func_0204944C  0x0204944C  arm
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj18978.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 func_021648A8(u8 *p, u32 n);
extern u8   ZONEDATA_GetWeatherId(u32 b);
extern u16 func_021648CC(int n, int k);
struct ArcFile;
extern void func_0204944C(struct ArcFile *a, u32 b, u32 c, u32 d, void *e);

u8 func_02164844(u8 *a, u32 b, u8 c, u8 d)
{
    u32 t = func_021648A8(a, b);
    u8 out;
    u16 s;
    if (t == 0xffff) {
        return ZONEDATA_GetWeatherId(b);
    }
    s = t + func_021648CC(c, d);
    func_0204944C((struct ArcFile *)((struct Obj18978 *)a)->f8, 0, s, 1, &out);
    return out;
}

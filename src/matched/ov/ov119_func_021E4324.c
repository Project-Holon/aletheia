/*
 * function: func_021E4324
 * address:  0x021E4324
 * packet:   pkt_ov119_021E4324
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * 2026-10-03 (wB3 lane07): EXACT. The doubled zero-extension of the loop-invariant
 * comes from an int parameter stored in a u16 local and then added as (int)e.
 *
 * symbols:
 *   func_02048F60  0x02048F60  arm
 *   func_021E42B4  0x021E42B4  thumb  ov119
 */
#include "../include/Obj00908.h"

typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    char pad00[0x24];
    u16 v[0x300];       /* 0x024 */
} Buf;

extern void *func_02048F60(u32 archive_id, u32 member, u32 heap);
extern void func_021E42B4(char *p);

void func_021E4324(char *p, int d)
{
    int i;
    u16 e;

    *(Buf * *)&((struct Obj00908 *)p)->f1174 = func_02048F60(0x66, 0xE, ((struct Obj00908 *)p)->f5F4);
    *(Buf * *)&((struct Obj00908 *)p)->f1178 = func_02048F60(0x66, 0xF, ((struct Obj00908 *)p)->f5F4);
    *(Buf * *)&((struct Obj00908 *)p)->f117C = func_02048F60(0x66, 0x19, ((struct Obj00908 *)p)->f5F4);
    *(Buf * *)&((struct Obj00908 *)p)->f1180 = func_02048F60(0x66, 0x1A, ((struct Obj00908 *)p)->f5F4);
    e = d;
    for (i = 0; i < 0x300; i++) {
        (*(Buf * *)&((struct Obj00908 *)p)->f1174)->v[i] += (int)e;
        (*(Buf **)(p + 0x1178))->v[i] += (int)e;
        (*(Buf **)(p + 0x117C))->v[i] += (int)e;
        (*(Buf **)(p + 0x1180))->v[i] += (int)e;
    }
    ((struct Obj00908 *)p)->f107C = ((struct Obj00908 *)p)->f63C - 0x50;
    func_021E42B4(p);
}

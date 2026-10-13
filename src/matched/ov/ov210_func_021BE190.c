/*
 * function: func_021BE190
 * address: 0x021BE190
 * packet: pkt_ov210_021BE190
 * region: ov210
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: compiled through 021BE20A; remaining 00 00 at 021BE20A is two-byte alignment padding before 021BE20C.
 * prototype: 93D4's s16 parameter widened because the original forwards full r4 without truncation.
 * symbols:
 *   FRAME_LIST_GetScrollPos 0x021B93B8 thumb ov067
 *   func_021BCEEC 0x021BCEEC thumb ov210
 *   FRAME_LIST_SetCursor 0x021B93D4 thumb ov067
 *   func_021BEA54 0x021BEA54 thumb ov210
 *   func_021BF89C 0x021BF89C thumb ov210
 */
#include "../include/Obj04619.h"
#include "../include/Obj25608.h"
#include "../include/Obj25609.h"
typedef unsigned char u8;
extern int FRAME_LIST_GetScrollPos(char *p);
typedef unsigned int   u32;
extern u32 func_021BCEEC(u32 a, u32 b);
struct S;
extern void FRAME_LIST_SetCursor(struct S *s, int v);
extern void func_021BEA54(u8 *p);
extern void func_021BF89C(char *p, u8 a, u8 b);
void func_021BE190(u8 *p, int n)
{
    int value = func_021BCEEC((u32)p, n + FRAME_LIST_GetScrollPos(((struct Obj04619 *)p)->f1E0));
    u8 *data = *(u8 * *)&((struct Obj25608 *)(*(u8 * *)&((struct Obj04619 *)p)->f0))->f8;
    if (data[3] == 255) {
        data[3] = value;
    } else if (data[4] == 255) {
        if (data[3] == value)
            data[3] = 255;
        else
            data[4] = value;
    } else if (data[3] == value) {
        data[3] = data[4];
        (*(u8 **)(*(u8 * *)&((struct Obj04619 *)p)->f0 + 8))[4] = 255;
    } else if (data[4] == value) {
        data[4] = 255;
    } else {
        data[3] = data[4];
        (*(u8 **)(*(u8 * *)&((struct Obj04619 *)p)->f0 + 8))[4] = value;
    }
    FRAME_LIST_SetCursor(((struct Obj04619 *)p)->f1E0, n);
    func_021BEA54(p);
    data = *(u8 * *)&((struct Obj25609 *)(*(u8 * *)&((struct Obj04619 *)p)->f0))->f8;
    func_021BF89C((char *)p, data[3], data[4]);
}

/*
 * function: func_02178A18
 * address:  0x02178A18
 * packet:   pkt_ov014_02178A18
 * region:   ov014
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   g_021797A8     0x021797A8  data  a4
 *   func_02178138  0x02178138  thumb  ov014
 *   func_0217814C  0x0217814C  thumb  ov014
 *   func_02178AB8  0x02178AB8  thumb  ov014
 */
#include "../../../matched/include/Obj04957.h"
#include "../../../matched/include/G_S.h"

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

extern struct S *g_021797A8;
void func_02178138(int a);
void func_0217814C(int a);
int func_02178AB8(void);

void func_02178A18(u8 *m)
{
    u32 v;
    void (*cb)(int);

    if (((struct Obj04957 *)m)->f2 != 0) {
        func_0217814C(((struct Obj04957 *)m)->f2);
        v = ((struct Obj04957 *)m)->f2;
        if (v == 0xC) {
            func_02178138(9);
            return;
        }
        if (v == 0xB) {
            func_02178138(9);
            return;
        }
        if (v == 1) {
            func_02178138(8);
            return;
        }
        func_02178138(9);
        return;
    }
    v = ((struct Obj04957 *)m)->f8;
    if (v == 8)
        return;
    if (v == 7) {
        func_02178138(4);
        if (func_02178AB8() == 0) {
            func_02178138(3);
            return;
        }
        *(u16 *)(((u8 *)g_021797A8) + 0x1EA8) = ((struct Obj04957 *)m)->fA;
        cb = *(void (**)(int))(((u8 *)g_021797A8) + 0x1E84);
        if (cb != 0)
            cb(((struct Obj04957 *)m)->fA);
        return;
    }
    if (v == 6)
        return;
    if (v == 9) {
        func_0217814C(0x14);
        func_02178138(9);
        return;
    }
    if (v == 0x1A)
        return;
    func_02178138(9);
}

/*
 * function: REPORT_EVENT_CreateMessageWindow
 * address:  0x02169E4C
 * packet:   pkt_02169E4C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BMP_WIN_Create  0x020450F0  arm
 *   func_0201F5BC  0x0201F5BC  thumb
 *   func_02049B40  0x02049B40  arm
 */
#include "../include/Obj00029.h"
#include "../include/Obj17747.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern int func_0201F5BC();
extern int func_02049B40();

void REPORT_EVENT_CreateMessageWindow(int a0)
{
    int a1;
    int a2;
    int a3;
    unsigned char fr[12];
    int t4;
    int t5;
    int o4;
    int o5;
    int o6;
t5 = a0 + 0;
a0 = 4;
    o4 = a0;
a0 = 0xc;
    o5 = a0;
a0 = 1;
    o6 = a0;
a0 = 6;
a1 = 1;
a2 = 1;
a3 = 0x1e;
t4 = 6;
    a0 = BMP_WIN_Create(a0, a1, a2, a3, o4, o5, o6);
loc_02169E6C:
a1 = *(int *)&((struct Obj00029 *)t5)->f18;
a2 = 0xd;
((struct Obj17747 *)a1)->f8 = a0;
a0 = ((struct Obj00029 *)t5)->f10;
a1 = 1;
a3 = 0;
    o4 = a0;
a0 = 6;
    a0 = func_0201F5BC(a0, a1, a2, a3, o4);
loc_02169E80:
a0 = 0x20;
    o4 = a0;
a0 = ((struct Obj00029 *)t5)->f10;
a1 = 5;
a2 = 4;
    o5 = a0;
a0 = 0x17;
a3 = t4 << 6;
    a0 = func_02049B40(a0, a1, a2, a3, o4, o5);
loc_02169E94:
    return;
}

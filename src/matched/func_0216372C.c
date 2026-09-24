/*
 * function: func_0216372C
 * address:  0x0216372C
 * packet:   pkt_0216372C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021636A8  0x021636A8  thumb  ov010
 *   func_021636C8  0x021636C8  thumb  ov010
 *   func_0216D568  0x0216D568  thumb  ov010
 *   func_0216D570  0x0216D570  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_021636A8();
extern int func_021636C8();
extern int func_0216D568();
extern int func_0216D570();

void func_0216372C(int a0, int a1)
{
    int t4;
    int t5;

t5 = a0 + 0;
t4 = a1 + 0;
    a0 = func_021636A8();
loc_02163736:
    if (a0 != 1) goto loc_0216375A;
loc_0216373A:
a0 = t4 + 0;
    a0 = func_021636C8(a0);
loc_02163740:
    if (a0 != 0) goto loc_02163750;
loc_02163744:
a1 = 2;
a0 = t5 + 0;
a1 = a1 << 0xe;
    a0 = func_0216D568(a0, a1);
loc_0216374E:
    return;
loc_02163750:
a1 = 2;
a0 = t5 + 0;
a1 = a1 << 0xe;
    a0 = func_0216D570(a0, a1);
loc_0216375A:
    return;}

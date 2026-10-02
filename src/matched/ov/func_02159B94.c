/*
 * function: func_02159B94
 * address:  0x02159B94
 * packet:   pkt_02159B94
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02048F60  0x02048F60  arm
 *   func_02159D04  0x02159D04  thumb  ov010
 *   func_020307B0  0x020307B0  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_02048F60(u32 archive_id, u32 member, u32 heap);
extern int func_02159D04();
extern int func_020307B0();

int func_02159B94(int a0, int a1, int a2, int a3)
{
    int t5;
    int t6;
    int t7;
    void *t4;

t5 = a0 + 0;
t7 = a2 + 0;
a0 = 9;
a2 = a3 + 0;
t6 = a1 + 0;
    t4 = func_02048F60(a0, a1, a2);
loc_02159BA4:
a0 = t5 + 0;
a2 = t6 + 0;
a3 = t7 + 0;
    a0 = func_02159D04(a0, t4, a2, a3);
loc_02159BB2:
    a0 = func_020307B0(t4);
loc_02159BB8:
    return a0;}

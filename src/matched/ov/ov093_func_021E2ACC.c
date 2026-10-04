/*
 * unit:     yes
 * function: func_021E2ACC, func_021E2B0C
 * address:  0x021E2ACC
 * packet:   pkt_ov093_021E2ACC
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D5844  0x021D5844  thumb  ov093
 *   func_02017E1C  0x02017E1C  thumb
 *   func_021D76BC  0x021D76BC  thumb  ov093
 *   _u32_div_f     0x0209C2B0  arm
 *   d_021F29F8     0x021F29F8  data  ov093  a4
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int func_021D775C(int key);
extern void *func_021C7CF4(int *p, int i);
extern void *func_021D5844(void *m);
extern u32 func_02017E1C(void *p, u32 id, u32 v);
extern int func_021D76BC(int key, u32 val);
extern u8 d_021F29F8[];

void func_021E2ACC(int u, void *p, int k)
{
    u32 v;
    if (k == func_021D775C(3)) {
        v = (u32)((0xff - func_02017E1C(func_021D5844(func_021C7CF4(p, k)), 9, 0)) * 10) / 25;
        if (v == 0)
            v = 1;
        func_021D76BC(0x30, v);
    }
}

u8 *func_021E2B0C(int *p)
{
    *p = 2;
    return d_021F29F8;
}

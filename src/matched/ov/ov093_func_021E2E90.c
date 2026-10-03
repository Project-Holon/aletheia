/*
 * unit:     yes
 * function: func_021E2E90
 * function: func_021E2EC8
 * address:  0x021E2E90
 * packet:   pkt_ov093_021E2E90
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
 *   func_021D5BB0  0x021D5BB0  thumb  ov093
 *   func_021E8860  0x021E8860  thumb  ov093
 *   d_021F24CC     0x021F24CC  data  ov093  a4
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int func_021D775C(int key);
struct UtilWork;
extern void *func_021C7CF4(int *p, int i);
extern int func_021D5BB0(struct UtilWork *p, u32 n);
extern void func_021E8860(int n);
extern u8 d_021F24CC[];

void func_021E2E90(int u, void *p, int k)
{
    if (k == func_021D775C(3)) {
        if (func_021D5BB0(func_021C7CF4(p, (u8)func_021D775C(4)), 2) != 0)
            func_021E8860(2);
    }
}

u8 *func_021E2EC8(int *p)
{
    *p = 1;
    return d_021F24CC;
}

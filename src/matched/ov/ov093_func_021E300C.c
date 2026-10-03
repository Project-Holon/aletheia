/*
 * unit:     yes
 * function: func_021E300C, func_021E3044
 * address:  0x021E300C
 * packet:   pkt_ov093_021E300C
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
 *   func_021D5BDC  0x021D5BDC  thumb  ov093
 *   func_021E8860  0x021E8860  thumb  ov093
 *   data_021F2464  0x021F2464  data   ov093  a4
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int func_021D775C(int key);
extern void *func_021C7CF4(void *p, u8 x);
struct UtilWork;
extern int func_021D5BDC(struct UtilWork *p, u32 n);
extern void func_021E8860(int n);
extern u8 data_021F2464[];

void func_021E300C(int u, void *p, int key)
{
    int k = 3;
    if (key == func_021D775C(k)) {
        if (func_021D5BDC(func_021C7CF4(p, func_021D775C(4)), k) != 0)
            func_021E8860(2);
    }
}

u8 *func_021E3044(u32 *out)
{
    *out = 1;
    return data_021F2464;
}

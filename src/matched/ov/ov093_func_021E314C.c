/*
 * unit:     yes
 * function: func_021E314C, func_021E3184
 * address:  0x021E314C
 * packet:   pkt_ov093_021E314C
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
 *   func_021D7704  0x021D7704  thumb  ov093
 *   data_021F25F4  0x021F25F4  data   a4
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int func_021D775C(int key);
extern void *func_021C7CF4(int *p, int i);
struct UtilWork;
extern int func_021D5BDC(struct UtilWork *p, u32 n);
extern void func_021D7704(int key, s32 m);
extern u8 data_021F25F4[];

void func_021E314C(int u, void *p, int key)
{
    int k = 4;
    if (key == func_021D775C(3)) {
        if (func_021D5BDC(func_021C7CF4(p, (u8)func_021D775C(k)), 5) != 0)
            func_021D7704(0x35, k << 11);
    }
}

u8 *func_021E3184(u32 *out)
{
    *out = 1;
    return data_021F25F4;
}

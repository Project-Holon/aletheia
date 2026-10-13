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
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_TestContFlag  0x021D5BDC  thumb  ov093
 *   BTL_EVENT_MultiplyVar  0x021D7704  thumb  ov093
 *   data_021F25F4  0x021F25F4  data   a4
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int BTL_EVENT_GetVar(int key);
extern void *func_021C7CF4(int *p, int i);
struct UtilWork;
extern int BTL_POKEPARAM_TestContFlag(struct UtilWork *p, u32 n);
extern void BTL_EVENT_MultiplyVar(int key, s32 m);
extern u8 data_021F25F4[];

void func_021E314C(int u, void *p, int key)
{
    int k = 4;
    if (key == BTL_EVENT_GetVar(3)) {
        if (BTL_POKEPARAM_TestContFlag(func_021C7CF4(p, (u8)BTL_EVENT_GetVar(k)), 5) != 0)
            BTL_EVENT_MultiplyVar(0x35, k << 11);
    }
}

u8 *func_021E3184(u32 *out)
{
    *out = 1;
    return data_021F25F4;
}

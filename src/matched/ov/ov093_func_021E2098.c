/*
 * function: func_021E2098
 * address:  0x021E2098
 * packet:   pkt_ov093_021E2098
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_EVENT_GetFactorKey  0x021D70A8  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021E03D8  0x021E03D8  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int BTL_EVENT_GetVar(int key);
struct QQ;
extern u16 BTL_EVENT_GetFactorKey(struct QQ *p);
extern void *func_021C7CF4(int *p, int i);
extern void func_021E03D8(u8 *a, int b);

void func_021E2098(void *u, int a, int b, int *p)
{
    int t;

    if (b == BTL_EVENT_GetVar(2)) {
        t = BTL_EVENT_GetVar(0x12);
        if (t == BTL_EVENT_GetFactorKey(u)) {
            p[6] = 1;
            return;
        }
        func_021E03D8(func_021C7CF4((int *)a, b), BTL_EVENT_GetFactorKey(u));
    }
}

/*
 * unit:     yes
 * function: func_021E2E28
 * function: func_021E2E84
 * address:  0x021E2E28
 * packet:   pkt_ov093_021E2E28
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
 *   func_021D67A8  0x021D67A8  thumb  ov093
 *   func_021D70A8  0x021D70A8  thumb  ov093
 *   func_021D679C  0x021D679C  thumb  ov093
 *   func_021D76BC  0x021D76BC  thumb  ov093
 *   d_021F25AC     0x021F25AC  data  ov093  a4
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int func_021D775C(int key);
struct QL;
struct QQ;
extern void *func_021C7CF4(int *p, int i);
extern u16 func_021D67A8(struct QL *p);
extern u16 func_021D70A8(struct QQ *p);
extern u16 func_021D679C(u8 *p);
extern int func_021D76BC(int key, u32 val);
extern u8 d_021F25AC[];

void func_021E2E28(int u, void *p, int k)
{
    void *q;
    u32 t;
    u32 n;
    u32 i;
    if (k == func_021D775C(3)) {
        q = func_021C7CF4(p, k);
        if (func_021D67A8(q) == func_021D70A8((void *)u)) {
            t = func_021D775C(0x30);
            n = func_021D679C(q);
            for (i = 0; i < n; i++) {
                t <<= 1;
                if (t > 0xa0) {
                    t = 0xa0;
                    break;
                }
            }
            func_021D76BC(0x30, t);
        }
    }
}

u8 *func_021E2E84(int *p)
{
    *p = 1;
    return d_021F25AC;
}

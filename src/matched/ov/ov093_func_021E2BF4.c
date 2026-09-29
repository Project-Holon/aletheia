/*
 * unit:     yes
 * function: func_021E2BF4
 * function: func_021E2C40
 * address:  0x021E2BF4
 * packet:   pkt_ov093_021E2BF4
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
 *   func_021D62C4  0x021D62C4  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   d_021F2CC0     0x021F2CC0  data  a4
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

typedef struct Msg {
    u8 f0[4];
    u32 f4;
    u8 f8;
    u8 f9[11];
    u8 f14;
} Msg;

extern int func_021D775C(int key);
extern void *func_021C7CF4(void *p, int k);
extern int func_021D62C4(void *p, int i);
extern Msg *func_021C88A4(void *a, int k, int b);
extern void func_021C88C8(void *a, void *b);
extern u8 d_021F2CC0[];

void func_021E2BF4(int u, void *p, int k)
{
    u8 t;
    Msg *m;
    if (k == func_021D775C(3)) {
        t = func_021D775C(6);
        if (t != 0x1f) {
            if (func_021D62C4(func_021C7CF4(p, t), 1) != 0) {
                m = func_021C88A4(p, 0xb, k);
                m->f8 = t;
                m->f14 = 1;
                m->f4 = 1;
                func_021C88C8(p, m);
            }
        }
    }
}

u8 *func_021E2C40(int *p)
{
    *p = 3;
    return d_021F2CC0;
}

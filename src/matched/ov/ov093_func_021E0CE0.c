/*
 * function: func_021E0CE0
 * address:  0x021E0CE0
 * packet:   pkt_ov093_021E0CE0
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D62C4  0x021D62C4  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021D7D9C  0x021D7D9C  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_021D775C(int key);
extern void *func_021C7CF4(void *p, int k);
extern int func_021D62C4(void *p, int i);
extern void *func_021C88A4(void *a, int k, int b);
extern void func_021C88C8(void *a, void *b);
extern void func_021C8838(void *p, int a, int b);
extern void func_021C8860(void *p, u32 v);
extern u32 func_021D7D9C(int x);

void func_021E0CE0(int unused, void *q, int id)
{
    u8 *r;
    u8 k;

    if (id == func_021D775C(3)) {
        k = func_021D775C(6);
        if (func_021D62C4(func_021C7CF4(q, k), 0x16) == 0) {
            r = (u8 *)func_021C88A4(q, 0xc, id);
            r[0xf] = k;
            *(int *)(r + 4) = 0x16;
            *(u32 *)(r + 8) = func_021D7D9C(id);
            func_021C8838(r + 0x14, 2, 0x368);
            func_021C8860(r + 0x14, k);
            func_021C88C8(q, r);
        }
    }
}

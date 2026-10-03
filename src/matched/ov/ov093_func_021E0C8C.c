/*
 * function: func_021E0C8C
 * address:  0x021E0C8C
 * packet:   pkt_ov093_021E0C8C
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
 *   func_021D62A8  0x021D62A8  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_021D775C(int key);
struct Unk021D62A8;
extern void *func_021C7CF4(int *p, int i);
extern int func_021D62A8(struct Unk021D62A8 *p);
extern void *func_021C88A4(void *a, int k, int b);
extern void func_021C88C8(void *a, void *b);

void func_021E0C8C(int unused, void *q, int id)
{
    u8 *r;
    int t;

    if (id == func_021D775C(3)) {
        t = func_021D62A8(func_021C7CF4(q, id));
        if (t == 5 || t == 1 || t == 4) {
            r = (u8 *)func_021C88A4(q, 0xb, id);
            *(int *)(r + 4) = t;
            r[8] = id;
            r[0x14] = 1;
            func_021C88C8(q, r);
        }
    }
}

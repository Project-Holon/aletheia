/*
 * function: func_021DA9E0
 * address:  0x021DA9E0
 * packet:   pkt_ov093_021DA9E0
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
 *   func_021D7B74  0x021D7B74  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88B4  0x021C88B4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_021D775C(int key);
extern void *func_021C7CF4(int *p, int i);
extern int func_021D7B74(u8 *p, u32 k);
extern void *func_021C88A4(void *a, int k, int b);
extern void func_021C88B4(void *a, int k, int b);
extern void func_021C88C8(void *a, void *b);

void func_021DA9E0(int unused, void *a, int id)
{
    u8 *r;
    void *m;
    u8 c;

    if (id == func_021D775C(2)) {
        m = func_021C7CF4(a, id);
        c = func_021D775C(0x39);
        if (c == 1) {
            func_021C88B4(a, 2, id);
            r = (u8 *)func_021C88A4(a, 7, id);
            r[6] = id;
            *(u16 *)(r + 4) = func_021D7B74(m, 8);
            func_021C88C8(a, r);
            func_021C88B4(a, 3, id);
        } else if (c == 2) {
            r = (u8 *)func_021C88A4(a, 5, id);
            *(u32 *)r |= 0x800000;
            r[6] = id;
            *(u16 *)(r + 4) = func_021D7B74(m, 8);
            func_021C88C8(a, r);
        }
    }
}

/*
 * function: func_021DB134
 * address:  0x021DB134
 * packet:   pkt_ov093_021DB134
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021D70A8  0x021D70A8  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88B4  0x021C88B4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_021D775C(int key);
struct QQ;
extern u16 func_021D70A8(struct QQ *p);
extern void *func_021C88A4(void *a, int k, int b);
extern void func_021C88B4(void *a, int k, int b);
extern void func_021C88C8(void *a, void *b);
extern void func_021C8838(void *p, int a, int b);
extern void func_021C8860(void *p, u32 v);

void func_021DB134(void *p, void *a, int id)
{
    u8 *r;
    int k;

    if (id == func_021D775C(2)) {
        switch (func_021D70A8(p)) {
        case 0xa3:
            k = 0x1f9;
            break;
        case 0xa4:
            k = 0x1f6;
            break;
        default:
            k = 0x1ba;
            break;
        }
        func_021C88B4(a, 2, id);
        r = (u8 *)func_021C88A4(a, 4, id);
        func_021C8838(r + 4, 2, k);
        func_021C8860(r + 4, id);
        func_021C88C8(a, r);
        func_021C88B4(a, 3, id);
    }
}

/*
 * function: func_021E1354
 * address:  0x021E1354
 * packet:   pkt_ov093_021E1354
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021D70A8  0x021D70A8  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_021D775C(int key);
struct QQ;
struct S;
extern u16 func_021D70A8(struct QQ *p);
extern void func_021C8838(void *p, int a, int b);
extern void func_021C8860(struct S *p, u32 val);

void func_021E1354(void *a, void *unused, int id)
{
    void *p;
    u8 k;
    int v;

    if (id != func_021D775C(3))
        return;
    if (func_021D775C(0x1d) != 8)
        return;
    p = (void *)func_021D775C(0x3f);
    k = func_021D775C(4);
    switch (func_021D70A8(a)) {
    case 0x23:
        v = 0x32a;
        break;
    case 0x14:
        v = 0x323;
        break;
    case 0x53:
        v = 0x33b;
        break;
    case 0x80:
        v = 0x331;
        break;
    case 0x148:
        v = 0x341;
        break;
    case 0x1cf:
        v = 0x33e;
        break;
    case 0xfa:
        v = 0x338;
        break;
    default:
        return;
    }
    func_021C8838(p, 2, v);
    func_021C8860(p, k);
    func_021C8860(p, id);
}

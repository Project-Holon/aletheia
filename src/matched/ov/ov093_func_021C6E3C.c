/*
 * function: func_021C6E3C
 * address: 0x021C6E3C
 * packet: pkt_ov093_021C6E3C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D57FC 0x021D57FC thumb ov093
 *   func_021E8CFC 0x021E8CFC thumb ov093
 *   func_021E8D04 0x021E8D04 thumb ov093
 *   func_021E8DA8 0x021E8DA8 thumb ov093
 *   func_021C7038 0x021C7038 thumb ov093
 *   func_021D79E8 0x021D79E8 thumb ov093
 *   func_021C6F0C 0x021C6F0C thumb ov093
 *   func_021C5750 0x021C5750 thumb ov093
 *   func_021C6FC0 0x021C6FC0 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u16 func_021D57FC(void *);
extern u8 func_021E8CFC(int);
extern int func_021E8D04(int);
extern int func_021E8DA8(int);
extern int func_021C7038(u8 *, u8 *, u8 *, u32, u8);
extern int func_021D79E8(int, int);
extern int func_021C6F0C(u8 *, u8 *, int);
extern void func_021C5750(u8 *, u8 *);
extern void func_021C6FC0(u8 *, u8 *);
int func_021C6E3C(u8 *p, u8 *a, u8 *b, u8 *q, int flag)
{
    int r, x;
    int changed = 0;
    if (q[6] == 17) return 3;
    x = func_021D57FC(b);
    r = func_021C7038(p, a, b, q[6], func_021E8CFC(x));
    if (func_021E8DA8(x) == 0)
        r = func_021D79E8(r, func_021C7038(p, a, b, q[6], func_021E8D04(x)));
    if (r != 0) {
        if (q[6] != 4) return r;
        changed = func_021C6F0C(p, b, 0);
        if (changed == 0) return r;
        r = 0;
    } else if (q[6] == 4) {
        if (func_021C6F0C(p, b, 1) == 0) return 3;
    }
    if (r == 0 && flag != 0) {
        if (changed == 0) func_021C5750(p, b);
        else func_021C6FC0(p, b);
    }
    return r;
}

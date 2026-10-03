/*
 * function: func_021E8508
 * address: 0x021E8508
 * packet: pkt_ov170_021E8508
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02025DE8 0x02025DE8 thumb
 *   func_020061E4 0x020061E4 thumb
 *   func_021E8F50 0x021E8F50 thumb ov170
 *   func_021E949C 0x021E949C thumb ov170
 *   func_021E8FE0 0x021E8FE0 thumb ov170
 *   func_021E8FD0 0x021E8FD0 thumb ov170
 */
typedef unsigned char u8;
struct Sound;
extern int func_02025DE8(struct Sound *obj);
extern void func_020061E4(unsigned);
extern int func_021E8F50(u8 *, int);
extern int func_021E949C(u8 *, int, int);
extern int func_021E8FE0(u8 *, int);
extern int func_021E8FD0(u8 *, int);
int func_021E8508(u8 *p)
{
    unsigned v = func_02025DE8(*(void **)(*(u8 **)(p + 0x2c) + 0x70));
    switch (v) {
    case 0:
        func_020061E4(0x54c);
        return func_021E949C(p, 2, func_021E8F50(p, 0x60));
    case 1:
        func_020061E4(0x54c);
        *(u8 *)(*(u8 **)(p + 0x2c) + 0xA17C) = 0;
        return func_021E949C(p, 3, func_021E8F50(p, 0x64));
    case 2:
        func_020061E4(0x54c);
        return func_021E949C(p, 4, 0x67);
    case 3:
        func_020061E4(0x551);
        return func_021E949C(p, 5, func_021E8F50(p, 0x5f));
    case -2:
        func_020061E4(0x551);
        return func_021E949C(p, 5, func_021E8F50(p, 0x5f));
    case -3:
        func_020061E4(0x548);
        return func_021E8FD0(p, func_021E8FE0(p, 0x5e));
    }
    return 0x5e;
}

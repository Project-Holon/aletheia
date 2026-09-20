/*
 * function: func_0202B59C
 * address:  0x0202B59C
 * packet:   pkt_0202B59C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH*
 * note:     re-verified 2026-09-20: MATCH*; see verify output
 *
 * Parked: five of the six initialisers resolve as `matched` (0x0202B5FC,
 * 0x0202B610, 0x0202B624, 0x0202B63C, 0x0202B65C).  The one that does not is
 * 0x0202B64C at +002A, which is itself capped on 0x0202C070, which is capped
 * on 0x0202C148 (DIFF).  Every concrete byte reproduces; the C is final.
 *
 * Constructor hub: fills the four word/halfword members of a node and runs
 * its six initialisers in order.
 *
 * symbols:
 *   func_0202B5FC  0x0202B5FC  thumb
 *   func_0202B610  0x0202B610  thumb
 *   func_0202B624  0x0202B624  thumb
 *   func_0202B63C  0x0202B63C  thumb
 *   func_0202B64C  0x0202B64C  thumb
 *   func_0202B65C  0x0202B65C  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_0202B5FC(u8 *p);
extern void func_0202B610(u8 *p);
extern void func_0202B624(u8 *p);
extern void func_0202B63C(u8 *p);
extern void func_0202B64C(u8 *p);
extern void func_0202B65C(u8 *p);

void func_0202B59C(u8 *p, u32 a, u32 b)
{
    *(u32 *)(p + 4)  = a;
    *(u32 *)(p + 8)  = 0xffffffff;
    *(u16 *)(p + 0)  = (u16)b;
    *(u32 *)(p + 0xc) = 0;

    func_0202B5FC(p);
    func_0202B610(p);
    func_0202B624(p);
    func_0202B63C(p);
    func_0202B64C(p);
    func_0202B65C(p);
}

/*
 * function: func_0202B59C
 * address:  0x0202B59C
 * packet:   pkt_0202B59C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 * blocker: 0202B63C and 0202B64C - both still unfiled; every concrete byte reproduces.
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
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_0202B59C.c \
 *       --func func_0202B59C --addr 0x0202B59C --thumb --cc 1.1p1
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

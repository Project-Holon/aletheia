/*
 * function: func_0202C09C
 * address:  0x0202C09C
 * packet:   pkt_0202BE00
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * When func_0202C2D8 reports true, runs func_0202C1C4 and func_0202C2C0.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202C09C.c \
 *       --func func_0202C09C --addr 0x0202C09C --thumb --cc 1.1p1
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern u32  func_0202C2D8(u8 *p);
extern void func_0202C1C4(u8 *p);
extern void func_0202C2C0(void *p);

void func_0202C09C(u8 *p)
{
    if (func_0202C2D8(p) != 0) {
        func_0202C1C4(p);
        func_0202C2C0(p);
    }
}

/*
 * function: func_0203195C
 * address:  0x0203195C
 * packet:   pkt_0203195C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203195C.c \\
 *       --func func_0203195C --addr 0x0203195C --arm --cc 1.1p1
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern void func_020307B0(void *p);
extern void func_020339B4(u32 v);
extern u32  func_02033B68(u32 v);
extern void func_020339D0(u32 a, u32 b);
extern void func_02033410(u8 *p, u32 v);

void func_0203195C(u8 *p)
{
    func_020339B4(*(u32 *)(p + 0x2c));
    func_020307B0(*(void **)(p + 0x138));
    if (p[0x1d] == 1) {
        func_020307B0(*(void **)(p + 0x34));
    }
    func_020307B0(p);
}

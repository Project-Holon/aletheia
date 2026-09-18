/*
 * function: func_0203D6CC
 * address:  0x0203D6CC
 * packet:   pkt_0203D6CC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_0203D788  0x0203D788  arm
 *   func_02034714  0x02034714  arm
 *   file_020A7CA0  0x020A7CA0  data
 *   file_020A7D2C  0x020A7D2C  data
 *
 * Halfword getter for the null-test sibling of func_0203D680: reports through
 * func_02034714 at line 0x5B1 (1457) when func_0203D788 comes back null, then
 * reads +0x6C from it regardless.  The null test is the `movs r4, r0` /
 * `bne` pair, so the result is kept in a local that the tail still
 * dereferences rather than being re-requested.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203D6CC.c  *       --func func_0203D6CC --addr 0x0203D6CC --cc 1.1p1 --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u8 *func_0203D788(void);
extern void func_02034714(const char *file, u32 line, const char *msg);
extern const char file_020A7CA0[];
extern const char file_020A7D2C[];

u32 func_0203D6CC(void)
{
    u8 *p = func_0203D788();

    if (p == 0)
        func_02034714(file_020A7CA0, 0x5B1, file_020A7D2C);
    return *(u16 *)(p + 0x6C);
}

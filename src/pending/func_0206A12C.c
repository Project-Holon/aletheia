/*
 * function: func_0206A12C
 * address:  0x0206A12C
 * packet:   pkt_0206A12C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 * blocker:  DIFF, 9 bytes: size, instruction sequence and all three calls are right; mwccarm puts the surviving `flag` in r4 and `p` in r5, the original the other way round. Eight spellings (u16 and u32 value locals, the compound-assignment value, `u32 flag`, `!flag` for the tail test, a one-argument leading call, a u8* parameter) all allocate the pair identically
 *
 * symbols:
 *   func_0207FA0C    0x0207FA0C  arm
 *   func_0207FA40    0x0207FA40  arm
 *   func_0207FADC    0x0207FADC  arm
 *
 * Tears down (or sets up) one surface: the flag bit 0 of the halfword at
 * +0x32 is set unconditionally, and both the leading and the trailing call
 * only happen when the caller's flag is non-zero.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_0206A12C.c \
 *       --func func_0206A12C --addr 0x0206A12C --cc 1.1p1 --arm
 */

typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_0207FA0C(char *p, int flag);
extern void func_0207FA40(char *dst, u32 a, u32 b);
extern void func_0207FADC(u32 v);

void func_0206A12C(char *p, int flag)
{
    u16 v;

    if (flag != 0)
        func_0207FA0C(p, flag);
    func_0207FA40(p + *(u32 *)(p + 0x38), (u32)(*(u32 *)(p + 0x2C) << 16) >> 13,
                  (u32)(*(u16 *)(p + 0x30) << 3));
    v = (u16)(*(u16 *)(p + 0x32) | 1);
    *(u16 *)(p + 0x32) = v;
    if (flag == 0)
        return;
    func_0207FADC(v);
}

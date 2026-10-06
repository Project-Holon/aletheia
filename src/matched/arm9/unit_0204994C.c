/*
 * A whole translation unit, matched as one byte range.
 *
 * unit:     yes
 * function: func_0204994C, func_02049990, func_020499D4
 * address:  0x0204994C
 * packet:   pkt_0204994C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_0204A1BC  0x0204A1BC  arm
 *   func_0204A380  0x0204A380  arm
 *   func_02049A18  0x02049A18  arm
 *
 * Sound / audio event trigger wrappers.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0204994C.c \
 *       --addr 0x0204994C --arm
 */

typedef unsigned short u16;
typedef unsigned int   u32;

extern int func_0204A1BC(int a0, int a1, int a2, int a3);
extern void *func_0204A380(void *a0, u32 a1, u32 a2, u32 a3);
extern u32 func_02049A18(void *file, u32 channel, u32 a2, u32 add, u32 size, u32 flag);

u32 func_0204994C(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7)
{
    u32 res = func_0204A1BC(a0, a1, a6, a7);
    return func_02049A18((void *)res, a2, a3, a4, a5, 0);
}

u32 func_02049990(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7)
{
    u32 res = (u32)func_0204A380(a0, a1, a6, a7);
    return func_02049A18((void *)res, a2, a3, a4, a5, 0);
}

u32 func_020499D4(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7)
{
    u32 res = (u32)func_0204A380(a0, a1, a6, a7);
    return func_02049A18((void *)res, a2, a3, a4, a5, 1);
}

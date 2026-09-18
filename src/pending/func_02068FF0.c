/*
 * function: func_02068FF0
 * address:  0x02068FF0
 * packet:   pkt_02068FF0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 * blocker:  DIFF/SIZE, 180 compiled against 136: a partial reconstruction only.  The two `clz`+`rsb #0x1f` pairs are the front end's `__cntlz` intrinsic (it compiles here, so the spelling is real) and the bit-level table indexing through g_020A18F4[sh2*8 + sh1*2] is read correctly, but the frame does not close: the original reads its outgoing argument slot [sp, #0xc] before the compiler makes its first store there, i.e. the source keeps a fifth value in the frame that this C does not have.  Evidence-capped regardless: ABS32 g_020A18E8 at +0x74 appears in exactly one literal pool in the image, its own, so the entry could never reach EXACT.
 *           (1) the two `clz` sequences are mwccarm's `__cntlz` intrinsic
 *           (`clzlt` + `rsblt #0x1f`), not reachable from a plain C highest-
 *           set-bit expression; (2) the frame reads its outgoing argument
 *           slots ([sp, #0xc]) before the compiler's first store to them,
 *           i.e. the source keeps a value in a local the scheduler moves.
 *           The entry is evidence-capped regardless: ABS32 g_020A18E8 at
 *           +0x74 appears in exactly one literal pool in the image, its own,
 *           so it can never reach EXACT.
 *
 * symbols:
 *   g_020A18F4       0x020A18F4  data
 *   g_020A18E8       0x020A18E8  data
 *   func_02068E78    0x02068E78  arm
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_02068FF0.c \
 *       --func func_02068FF0 --addr 0x02068FF0 --cc 1.1p1 --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void  func_02068E78(char *p, u32 a1, u32 a2, u32 a3, u8 a5, u32 a6, u32 a7);
extern const char g_020A18F4[];
extern const char g_020A18E8[];

void func_02068FF0(char *p, u32 arg1, u32 r2, u32 r3, u32 a5, u32 a6, u32 a7)
{
    u32 sh1;
    u32 sh2;
    u32 v;

    sh1 = (r2 < 8) ? (u32)(31 - __cntlz(r2)) : 3;
    sh2 = (r3 < 8) ? (u32)(31 - __cntlz(r3)) : 3;
    v = (a5 & ~0xFFu) | (u8)g_020A18F4[sh2 * 8 + sh1 * 2];
    v = (v & ~0xFF00u)
        | ((u32)((u8)g_020A18F4[sh2 * 8 + sh1 * 2 + 1] << 24) >> 16);
    func_02068E78(p, arg1, r2, r3, (u8)(v >> 0), (u32)(char *)g_020A18E8, a7);
}

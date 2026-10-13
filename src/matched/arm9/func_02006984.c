/*
 * function: func_02006984
 * address:  0x02006984
 * packet:   pkt_02006948
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02005C64  0x02005C64  thumb
 *   func_02085A38  0x02085A38  arm
 *   PM_VOICE_Prepare  0x020069D4  thumb
 *   PM_VOICE_Start  0x02006A64  thumb
 *
 * Eight parameters: four arrive in registers and four in the caller's stack
 * frame, which this function copies down into its own outgoing argument area
 * (the `sub sp, #0x14` plus the saved r3 is exactly that home area).  The
 * wait loop is an `if` around a `do`/`while` rather than one `while`, because
 * `v = 2` is emitted *after* the first test and the back edge skips it.
 *
 * PROMOTED, no C change: this file was parked at MATCH on 02006A64 above and
 * became EXACT the moment pkt_02006948's shard was written - the `matched`
 * class needs only that the callee has an EXACT entry of its own.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02006984.c \
 *       --func func_02006984 --addr 0x02006984 --cc 1.1p1 --thumb
 */

typedef unsigned short u16;
typedef unsigned int   u32;

extern int  func_02005C64(void);
extern void func_02085A38(u32 v);
extern int PM_VOICE_Prepare(int a0, int a1, int a2, int a3, int a5, int a6, int a7, int a8);
extern int PM_VOICE_Start(u32 idx);

u32 func_02006984(u32 a0, u32 a1, u32 a2, u32 a3,
                  u32 a4, u32 a5, u32 a6, u32 a7)
{
    u32 v;

    if (func_02005C64() == 1) {
        v = 2;
        do {
            func_02085A38(v);
        } while (func_02005C64() == 1);
    }
    v = (u16)PM_VOICE_Prepare(a0, a1, a2, a3, a4, a5, a6, a7);
    PM_VOICE_Start(v);
    return v;
}

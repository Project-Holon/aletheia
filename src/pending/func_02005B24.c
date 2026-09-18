/*
 * function: func_02005B24
 * address:  0x02005B24
 * packet:   pkt_02005B24
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 * blocker:  02005B6C - the 8-byte ARM `ldr pc, [pc, #-4]` stub at 0x02005B6C
 *           and its pointer word 0x02704364, which lies outside every region
 *           of layout/layout.json, so `veneer_at()`'s `names_known_code()`
 *           refuses it and the `veneer` class cannot attest the call.
 *
 * symbols:
 *   g_020AA9B4   0x020AA9B4  data
 *   g_020AA260   0x020AA260  data
 *   g_020A7010   0x020A7010  data
 *   g_020AA2BC   0x020AA2BC  data
 *   func_020726D0  0x020726D0  arm
 *   func_020746E8  0x020746E8  arm
 *   func_02073FB8  0x02073FB8  arm
 *   func_02005B74  0x02005B74  thumb
 *   func_02085D3C  0x02085D3C  arm
 *   func_02005B6C  0x02005B6C  arm
 *
 * Network bring-up: take a block out of the static buffer at 0x020AA9B4
 * (0x95AD0 bytes, a pool word and not a `movs`-able constant), publish the
 * handle at +0x10 of the connection-slot global and hand the pair to the
 * handler installer, then run the console-type-specific tail.  The two
 * arguments are forwarded straight through in r0/r1 with nothing in between,
 * so the first call sees this function's own parameters.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_02005B24.c \
 *       --func func_02005B24 --addr 0x02005B24 --cc 1.1p1 --thumb
 */

typedef unsigned int u32;

extern char g_020AA9B4[];
extern char g_020AA260[];
extern char g_020A7010[];
extern char g_020AA2BC[];

extern void func_020726D0(u32 a0, u32 a1);
extern u32  func_020746E8(char *base, u32 size);
extern void func_02073FB8(char *a, char *b, u32 c, u32 d);
extern void func_02005B74(u32 flag);
extern int  func_02085D3C(void);
extern void func_02005B6C(void);

void func_02005B24(u32 a0, u32 a1)
{
    u32 handle;

    func_020726D0(a0, a1);
    handle = func_020746E8(g_020AA9B4, 0x95AD0);
    *(u32 *)(g_020AA260 + 0x10) = handle;
    func_02073FB8(g_020AA2BC, g_020A7010, handle, 0);
    func_02005B74(1);
    if (func_02085D3C() == 1) {
        func_02005B6C();
    }
}

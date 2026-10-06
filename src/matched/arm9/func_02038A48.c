/*
 * function: func_02038A48
 * address:  0x02038A48
 * packet:   pkt_02037F48
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Idempotent bring-up: when the argument is non-zero and the mode byte at
 * 0x020A7A21 still reads 2, it is flipped to 4 and the call is skipped; in
 * every other case the 0x5C0-byte block at 0x020A7A24 is handed to
 * func_02034714 with 0x020A7A50 as the third argument.  Either way the
 * function answers 1 through the single shared epilogue (`mov r0, #1;
 * pop {r3, pc}`), which is why the taken arm ends in `beq` to that epilogue
 * and not in a predicated return.
 *
 * The three globals are *arrays*, not pointers: the image loads the pool word
 * straight into r0 and then does `ldrb r1, [r0, #1]`, so `extern u8
 * g_020A7A20[]` with a `[1]` subscript is the spelling that reproduces it - as
 * `extern u8 *g_020A7A20` the compiler adds a second load and the file grows
 * to 88 bytes.  The arm's two instructions are predicated (`moveq`/`strbeq`)
 * rather than branched.
 *
 * Addresses are Black-image addresses.
 *
 * symbols:
 *   g_020A7A20     0x020A7A20  data
 *   g_020A7A24     0x020A7A24  data
 *   g_020A7A50     0x020A7A50  data
 *   func_02034714  0x02034714  arm
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02038A48.c \
 *       --func func_02038A48 --addr 0x02038A48 --cc 1.1p1 --arm
 */

typedef unsigned char u8;

extern u8   g_020A7A20[];
extern u8   g_020A7A24[];
extern u8   g_020A7A50[];
typedef unsigned int   u32;
extern void func_02034714(const char *expr, u32 line, const char *file);

int func_02038A48(int a)
{
    if (a != 0 && g_020A7A20[1] == 2) {
        g_020A7A20[1] = 4;
    } else {
        func_02034714((const char *)g_020A7A24, 0x5C0, (const char *)g_020A7A50);
    }
    return 1;
}

/*
 * unit:     no
 * function: func_0203D26C
 * address:  0x0203D26C
 * packet:   pkt_0203D1B4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_0203D788  0x0203D788  arm
 *
 * TU: net.c.
 *
 * "State is 3 or 4" predicate on the +0x65 mode byte of the network
 * singleton.  The range test is written as one unsigned compare on the
 * biased byte, so the original spells `- 3` as `add r0, r0, #0xfd` with the
 * `and r0, r0, #0xff` that the u8 cast forces.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203D26C.c \
 *       --func func_0203D26C --addr 0x0203D26C --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct NetSys {
    u8 pad_00[0x65];
    u8 mode;
};

extern void *func_0203D788(void);

u32 func_0203D26C(void)
{
    struct NetSys *s = func_0203D788();

    if (s != 0) {
        if ((u8)(s->mode + 0xfd) <= 1) {
            return 1;
        }
    }
    return 0;
}

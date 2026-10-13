/*
 * unit:     no
 * function: GFL_NET_IsNetTypeBeacon
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
 *   GFL_NET_GetSession  0x0203D788  arm
 *
 * TU: net.c.
 *
 * "State is 3 or 4" predicate on the +0x65 mode byte of the network
 * singleton.  The range test is written as one unsigned compare on the
 * biased byte, so the original spells `- 3` as `add r0, r0, #0xfd` with the
 * `and r0, r0, #0xff` that the u8 cast forces.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_IsNetTypeBeacon.c \
 *       --func GFL_NET_IsNetTypeBeacon --addr 0x0203D26C --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct NetSys {
    u8 pad_00[0x65];
    u8 mode;
};

extern void *GFL_NET_GetSession(void);

u32 GFL_NET_IsNetTypeBeacon(void)
{
    struct NetSys *s = GFL_NET_GetSession();

    if (s != 0) {
        if ((u8)(s->mode + 0xfd) <= 1) {
            return 1;
        }
    }
    return 0;
}

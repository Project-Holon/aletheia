/*
 * unit:     no
 * function: GFL_NET_IsNetTypeWifi
 * address:  0x0203D29C
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
 * Sibling of GFL_NET_IsNetTypeBeacon one range lower: "state is 1 or 2" on the +0x65
 * mode byte.  Same shape, `add r0, r0, #0xff` for the bias instead of
 * `#0xfd`.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_IsNetTypeWifi.c \
 *       --func GFL_NET_IsNetTypeWifi --addr 0x0203D29C --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct NetSys {
    u8 pad_00[0x65];
    u8 mode;
};

extern void *GFL_NET_GetSession(void);

u32 GFL_NET_IsNetTypeWifi(void)
{
    struct NetSys *s = GFL_NET_GetSession();

    if (s != 0) {
        if ((u8)(s->mode + 0xff) <= 1) {
            return 1;
        }
    }
    return 0;
}

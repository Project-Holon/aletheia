/*
 * unit:     no
 * function: GFL_NET_SetAcceptConnection
 * address:  0x0203D1E8
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
 * Dispatch through the +0xb8 slot of the callback block hanging off +0x340
 * of the network singleton.  The first parameter is dead: the original
 * overwrites r0 with the singleton before the call and forwards r1, which
 * is what spends r4 on a two-argument function that only uses the second.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_SetAcceptConnection.c \
 *       --func GFL_NET_SetAcceptConnection --addr 0x0203D1E8 --cc 1.1p1 --arm
 */

typedef unsigned char u32_pad;
typedef unsigned int  u32;

struct NetVtbl {
    u32_pad pad_00[0xb8];
    void (*unk_b8)(void *arg);
};

struct NetSys {
    u32_pad         pad_000[0x340];
    struct NetVtbl *vtbl;
};

extern struct NetSys *GFL_NET_GetSession(void);

void GFL_NET_SetAcceptConnection(u32 unused, void *arg)
{
    void (*fn)(void *) = GFL_NET_GetSession()->vtbl->unk_b8;

    if (fn == 0) {
        return;
    }
    fn(arg);
}

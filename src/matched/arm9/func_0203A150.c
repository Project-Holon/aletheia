/*
 * unit:     no
 * function: func_0203A150
 * address:  0x0203A150
 * packet:   pkt_0203A150
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT*
 *
 * symbols:
 *   func_0203D798  0x0203D798  arm
 *   func_020395EC  0x020395EC  arm
 *   func_0203A118  0x0203A118  arm
 *   func_0203EFC8  0x0203EFC8  arm
 *   func_0203996C  0x0203996C  arm
 *   func_0203DAC4  0x0203DAC4  arm
 *   OS_GetMacAddress  0x02087C6C  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Msg
{
    u8 pad_00[6];
    u8 mac[6];
    u8 f0c;
    u8 f0d;
    u8 f0e;
    u8 f0f;
};

struct Peer
{
    u8 pad_00[0x4a];
    u8 f4a;
};

struct Glob
{
    u8 pad_00[0xc];
    void (*f0c)(int, u32);
    u8 pad_10[0x57];
    u8 f67;
    u8 pad_68[6];
    u16 f6e;
};

extern struct Glob *func_0203D798(void);
extern u32 func_020395EC(struct Peer *);
extern void func_0203A118(struct Peer *);
extern int func_0203EFC8(const void *, const void *, u32);
extern struct Peer *func_0203996C(u32);
extern void func_0203DAC4(void *);
extern void OS_GetMacAddress(u8 *);

void func_0203A150(int a0, int a1, struct Msg *msg, int a3, struct Peer *peer)
{
    struct Glob *g;
    u8 mac[8];
    u32 id;

    g = func_0203D798();
    id = func_020395EC(peer);
    if (id == 0xff)
    {
        peer->f4a = 5;
        return;
    }

    if (g->f6e != 0)
    {
        if (g->f6e != msg->f0f)
            func_0203A118(peer);
        if (g->f6e != msg->f0e)
            func_0203A118(peer);
    }
    else
    {
        if (g->f67 != msg->f0f)
            func_0203A118(peer);
        if (g->f67 != msg->f0e)
            func_0203A118(peer);
    }

    OS_GetMacAddress(mac);
    if (func_0203EFC8(msg->mac, mac, 6) == 0)
    {
        if (msg->f0c != func_020395EC(peer))
            func_0203A118(peer);
    }

    if (peer->f4a == 7)
        return;

    func_0203996C(msg->f0c)->f4a = 5;

    if (g->f0c != 0)
        g->f0c(a3, msg->f0c);

    func_0203DAC4(msg->mac);
    func_0203DAC4(msg);
}

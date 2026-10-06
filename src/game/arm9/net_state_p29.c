/*
 * file:     net_state_p29.c
 * unit:     yes
 * function: func_0203A118, func_0203A150
 * address:  0x0203A118
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0203D798  0x0203D798  arm
 *   func_020395EC  0x020395EC  arm
 *   func_0203EFC8  0x0203EFC8  arm
 *   func_0203996C  0x0203996C  arm
 *   func_0203DAC4  0x0203DAC4  arm
 *   OS_GetMacAddress  0x02087C6C  arm
 */
#include "../../matched/include/Obj15952.h"

struct Entry;
typedef unsigned char u8;

typedef unsigned int  u32;

typedef unsigned short u16;

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

typedef signed int     s32;

extern void *func_0203D788(void);
extern void *func_0203D798(void);
extern int func_020395EC(struct Entry *a);
extern s32 func_0203EFC8(const u8 *a, const u8 *b, u32 n);
extern struct Peer *func_0203996C(u32);
extern void func_0203DAC4(const u8 *mac);
extern void OS_GetMacAddress(u8 *);
void func_0203A118(u8 *p);


/*
 * Conditional state repair: when the context's +0x352 flag is clear the
 * object's +0x4A state is only pushed to 7 if it is not already 5, otherwise
 * 7 is stored unconditionally.  The `!= 0` arm is the branch and the `== 0`
 * arm is the fall-through, so that polarity is the source order; the inner
 * store is the conditional `movne`/`strbne` pair.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203A118.c \
 *       --func func_0203A118 --addr 0x0203A118 --cc 1.1p1 --arm
 */
void func_0203A118(u8 *p)
{
    if (((struct Obj15952 *)((char *)func_0203D788()))->f352 == 0) {
        if (p[0x4A] != 5)
            p[0x4A] = 7;
    } else {
        p[0x4A] = 7;
    }
}


void func_0203A150(int a0, int a1, struct Msg *msg, int a3, struct Peer *peer)
{
    struct Glob *g;
    u8 mac[8];
    u32 id;

    g = func_0203D798();
    id = func_020395EC((struct Entry *)peer);
    if (id == 0xff)
    {
        peer->f4a = 5;
        return;
    }

    if (g->f6e != 0)
    {
        if (g->f6e != msg->f0f)
            func_0203A118((u8 *)peer);
        if (g->f6e != msg->f0e)
            func_0203A118((u8 *)peer);
    }
    else
    {
        if (g->f67 != msg->f0f)
            func_0203A118((u8 *)peer);
        if (g->f67 != msg->f0e)
            func_0203A118((u8 *)peer);
    }

    OS_GetMacAddress(mac);
    if (func_0203EFC8(msg->mac, mac, 6) == 0)
    {
        if (msg->f0c != func_020395EC((struct Entry *)peer))
            func_0203A118((u8 *)peer);
    }

    if (peer->f4a == 7)
        return;

    func_0203996C(msg->f0c)->f4a = 5;

    if (g->f0c != 0)
        g->f0c(a3, msg->f0c);

    func_0203DAC4(msg->mac);
    func_0203DAC4((const u8 *)msg);
}

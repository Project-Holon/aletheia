/*
 * function: GFL_NET_HANDLE_CheckTimingSyncAll
 * address:  0x02039CD8
 * packet:   pkt_02039CD8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   GFL_NET_HANDLE_IsBitSet  0x0203A2F0  arm
 *   GFL_NET_SendData  0x0203D3F8  arm
 *   GFL_NET_HANDLE_SetBitMask  0x0203A28C  arm
 *
 * Sweep the eight slot pointers at +0x8.  A slot that is still marked in use
 * (+0xd non-zero) and whose bit is not set in the key word at +0x3e is torn
 * down through the eight-argument delegate; a delegate failure aborts the
 * whole sweep with 0, otherwise the key's bit is set.  Falling off the end
 * clears the key word and reports success.
 *
 * The eight-argument call's first stack slot is the slot pointer itself and
 * the remaining three are the constants 1, 0, 1 (r5 is the object, 0xff/4/
 * 0x10 are the register arguments).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_HANDLE_CheckTimingSyncAll.c \
 *       --func GFL_NET_HANDLE_CheckTimingSyncAll --addr 0x02039CD8 --cc 1.1p1 --arm
 */
#include "../include/Obj15949.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 GFL_NET_HANDLE_IsBitSet(u32 a0, u32 a1);
extern u32 GFL_NET_SendData(u32 entry, u32 sendID, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);
extern u16 GFL_NET_HANDLE_SetBitMask(u16 mask, u32 idx, u32 set);

struct Obj {
    u8   pad_00[8];
    void *slot[8];
    u8   pad_28[0x16];
    u16  key;
};

int GFL_NET_HANDLE_CheckTimingSyncAll(struct Obj *p)
{
    int i;

    for (i = 0; i < 8; i++) {
        if (((struct Obj15949 *)((char *)p->slot[i]))->fD == 0)
            continue;
        if (GFL_NET_HANDLE_IsBitSet(p->key, i) != 0)
            continue;
        if (GFL_NET_SendData((u32)p, 0xff, 4, 0x10, (u32)p->slot[i], 1, 0, 1) != 0)
            GFL_NET_HANDLE_SetBitMask(p->key, i, 1);
        else
            return 0;
    }
    p->key = 0;
    return 1;
}

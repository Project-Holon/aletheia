/*
 * function: GFL_NET_STATE_SetErrorMode
 * address:  0x0203C938
 * packet:   pkt_0203C938
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   unk_021469DC   0x021469DC  data
 *   GFL_NET_SYSTEM_SetError  0x02039548  arm
 *   GFL_NET_SYSTEM_SetNoSend  0x02039578  arm
 *
 * Opens the state: with no live object the answer is 0, otherwise the mode
 * byte at +0x4D is written, the two setup calls run and the answer is 1.
 * src/matched/GFL_NET_STATE_ClearErrorMode.c is the matching close.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_STATE_SetErrorMode.c \
 *       --func GFL_NET_STATE_SetErrorMode --addr 0x0203C938 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern u32 unk_021469DC;
extern void GFL_NET_SYSTEM_SetError(void);
extern void GFL_NET_SYSTEM_SetNoSend(void);

u32 GFL_NET_STATE_SetErrorMode(u8 mode)
{
    u8 *p;

    p = (u8 *)unk_021469DC;
    if (p == 0)
        return 0;
    p[0x4D] = mode;
    GFL_NET_SYSTEM_SetError();
    GFL_NET_SYSTEM_SetNoSend();
    return 1;
}

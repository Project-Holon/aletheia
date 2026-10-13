/*
 * function: GFL_NET_STATE_ClearErrorMode
 * address:  0x0203C968
 * packet:   pkt_0203C938
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   unk_021469DC   0x021469DC  data
 *   GFL_NET_SYSTEM_ResetError  0x02039560  arm
 *
 * Closes the state src/matched/GFL_NET_STATE_SetErrorMode.c opens: clears the mode byte and
 * runs the teardown call.  With no live object it is a bare `popeq`.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_STATE_ClearErrorMode.c \
 *       --func GFL_NET_STATE_ClearErrorMode --addr 0x0203C968 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern u32 unk_021469DC;
extern void GFL_NET_SYSTEM_ResetError(void);

void GFL_NET_STATE_ClearErrorMode(void)
{
    u8 *p;

    p = (u8 *)unk_021469DC;
    if (p == 0)
        return;
    p[0x4D] = 0;
    GFL_NET_SYSTEM_ResetError();
}

/*
 * function: FIELD_MSGBG_MsgStreamCallback
 * address:  0x02190D08
 * packet:   pkt_ov021_02190D08
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb  arm9
 *   GFL_USE_IsAnySeBusy  0x02006238  thumb  arm9
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef short          s16;

extern void GFL_USE_PlaySeDefaultVolume(u32 se);
extern int GFL_USE_IsAnySeBusy(void);

int FIELD_MSGBG_MsgStreamCallback(int x)
{
    switch (x) {
    case 3:
        GFL_USE_PlaySeDefaultVolume(0x56B);
        break;
    case 6:
        return GFL_USE_IsAnySeBusy();
    }
    return 0;
}

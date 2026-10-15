/*
 * function: INTRO_CMD_CmdBgmWait
 * address:  0x021BE3B8
 * packet:   pkt_021BE3B8
 * region:   ov204
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   GFL_USE_IsBgmPlaying  0x02005F38  thumb  arm9
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern int GFL_USE_IsBgmPlaying(void);

u32 INTRO_CMD_CmdBgmWait(void)
{
    if (GFL_USE_IsBgmPlaying() != 0) {
        return 1;
    }
    return 0;
}


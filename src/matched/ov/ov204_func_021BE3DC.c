/*
 * function: INTRO_CMD_CmdBgmFadeIn
 * address:  0x021BE3DC
 * packet:   pkt_021BE3DC
 * region:   ov204
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GFL_USE_FadeInBgmFull 0x02005DF8 thumb
 */

typedef unsigned int   u32;
extern void GFL_USE_FadeInBgmFull(u32 a);

int INTRO_CMD_CmdBgmFadeIn(int a, int b, int *p)
{
    GFL_USE_FadeInBgmFull((unsigned short)*p);
    return 1;
}

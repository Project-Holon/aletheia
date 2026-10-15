/*
 * function: INTRO_G3D_SetSlotAnim, INTRO_G3D_GetSlotAnimFinished
 * unit: yes
 * address: 0x021BF744
 * packet: pkt_ov204_021BF744
 * region: ov204
 * compiler: 1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * 10-byte getter follower 0x021BF77C is included; function_starts seed. Enum zero separates field and argument clears.
 * symbols:
 *   MCSS_SetAnimeIndex 0x02016028 thumb
 *   MCSS_ResetAnmStopFlag 0x02015E4C thumb
 *   MCSS_SetAnimCallback 0x02015F2C thumb
 *   INTRO_G3D_OnAnimEnd 0x021BF7F0 thumb ov204
 */

extern void MCSS_SetAnimeIndex(void *, unsigned int);
extern void MCSS_ResetAnmStopFlag(void *);
typedef unsigned char  u8;
extern void INTRO_G3D_OnAnimEnd(u8 *p);
extern void MCSS_SetAnimCallback(void *, void *, void (*)(void *, void *), int);

void INTRO_G3D_SetSlotAnim(char *p, unsigned int i, unsigned int flag, unsigned int v)
{
    char *base = p + 8;
    unsigned int off = i * 12;
    enum { Zero } zero;
    MCSS_SetAnimeIndex(*(void **)(base + off), flag);
    MCSS_ResetAnmStopFlag(*(void **)(base + off));
    zero = Zero;
    *(unsigned int *)(p + off + 12) = zero;
    *(unsigned int *)(p + off + 16) = v;
    MCSS_SetAnimCallback(*(void **)(base + off), base + off, (void (*)(void *, void *))INTRO_G3D_OnAnimEnd, 0);
}

unsigned int INTRO_G3D_GetSlotAnimFinished(char *p, u8 i)
{
    return *(unsigned int *)(p + i * 12 + 12);
}

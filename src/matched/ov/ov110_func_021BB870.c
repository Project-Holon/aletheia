/*
 * unit: yes
 * function: PMSIV_CATEGORY_StartBlendIn, PMSIV_CATEGORY_IsBlendInDone
 * address: 0x021BB870
 * packet: pkt_ov110_021BB870
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * extent: includes the unlabelled forwarding stub at 0x021BB8AC.
 * symbols:
 *   func_0207D63C 0x0207D63C arm
 *   func_02040588 0x02040588 arm
 *   PMSIV_FADE_StartBlend 0x021BC868 thumb ov110
 *   PMSIV_FADE_IsBlendDone 0x021BC898 thumb ov110
 */
typedef unsigned char u8;
extern void func_0207D63C(void *, int, int, int, int);
typedef unsigned int   u32;
extern void func_02040588(unsigned char which, unsigned char enable);
extern void PMSIV_FADE_StartBlend(u8 *p, int a, int b, int start, int end, int frames);
extern int PMSIV_FADE_IsBlendDone(u8 *p);
void PMSIV_CATEGORY_StartBlendIn(u8 *p)
{
    func_0207D63C((void *)0x04000050, 2, 63, 0, 16);
    func_02040588(1, 1);
    PMSIV_FADE_StartBlend(p + 0x18, 2, 63, 0, 124, 12);
}
int PMSIV_CATEGORY_IsBlendInDone(u8 *p)
{
    return PMSIV_FADE_IsBlendDone(p + 0x18);
}

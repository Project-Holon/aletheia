/*
 * function: NAMEIN_GRAPHIC_CallbackFadeIn
 * address: 0x021F4674
 * packet: pkt_ov194_021F4674
 * region: ov194
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   FADE_Start 0x0204E720 arm
 *   FADE_IsActive 0x0204E804 arm
 *   NAMEIN_GRAPHIC_SetCallback 0x021F462C thumb ov194
 *   NAMEIN_GRAPHIC_CallbackGridAction 0x021F47B4 thumb ov194
 */
typedef signed int     s32;
typedef unsigned int   u32;
extern void FADE_Start(u32 a, s32 b, s32 c, s32 d);
extern int FADE_IsActive(void);
extern void NAMEIN_GRAPHIC_SetCallback(unsigned char *,unsigned);
extern void NAMEIN_GRAPHIC_CallbackGridAction(unsigned char *owner, void *unused, char *p);
void NAMEIN_GRAPHIC_CallbackFadeIn(unsigned char *p,int *state) {
    switch (*state) {
    case 0: FADE_Start(3,16,0,0); *state=1; break;
    case 1: if (!FADE_IsActive()) *state=2; break;
    case 2: NAMEIN_GRAPHIC_SetCallback(p,(unsigned)NAMEIN_GRAPHIC_CallbackGridAction); break;
    }
}

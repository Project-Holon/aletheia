/*
 * function: TOWNMAP_StepFadeOut
 * address: 0x021B99AC
 * packet: pkt_ov072_021B99AC
 * region: ov072
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * note: trailing two-byte alignment padding.
 * symbols:
 *   FADE_Start 0x0204E720 arm
 *   FADE_IsActive 0x0204E804 arm
 *   TOWNMAP_ProcFinish 0x021B9964 thumb ov072
 */
typedef signed int     s32;
typedef unsigned int   u32;
extern void FADE_Start(u32 a, s32 b, s32 c, s32 d);
extern int FADE_IsActive(void);
extern void TOWNMAP_ProcFinish(int *);
void TOWNMAP_StepFadeOut(int *p, int *state) {
    switch (*state) {
    case 0: FADE_Start(3,0,16,0); *state = 1; break;
    case 1: if (FADE_IsActive() == 0) *state = 2; break;
    case 2: TOWNMAP_ProcFinish(p); break;
    }
}

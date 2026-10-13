/*
 * function: TOWNMAP_StepFadeIn
 * address:  0x021B996C
 * packet:   pkt_ov072_021B996C
 * region:   ov072
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FADE_Start  0x0204E720  arm
 *   FADE_IsActive  0x0204E804  arm
 *   TOWNMAP_ProcSetStep  0x021B995C  thumb  ov072
 *   TOWNMAP_StepBrowse  0x021B99E8  thumb  ov072
 */

typedef signed int     s32;
typedef unsigned int   u32;
void FADE_Start(u32 a, s32 b, s32 c, s32 d);
int FADE_IsActive(void);
void TOWNMAP_ProcSetStep(int *p, int x);
int TOWNMAP_StepBrowse(int *a, int unused, char *p);

void TOWNMAP_StepFadeIn(int a, int *b)
{
    switch (b[0]) {
    case 0:
        FADE_Start(3, 0x10, 0, 0);
        b[0] = 1;
        break;
    case 1:
        if (FADE_IsActive() == 0) {
            b[0] = 2;
        }
        break;
    case 2:
        TOWNMAP_ProcSetStep((int *)a, (int)TOWNMAP_StepBrowse);
        break;
    }
}

/*
 * function: C_GEAR_Restart
 * address:  0x021F2994
 * packet:   pkt_ov029_021F2994
 * region:   ov029
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WIPE_SetBrightnessFadeOut  0x0202223C  thumb
 *   WIPE_ResetBrightness  0x02022230  thumb
 *   C_GEAR_Cleanup  0x021F26E0  thumb  ov029
 *   C_GEAR_Init  0x021F251C  thumb  ov029
 *   C_GEAR_StepIdle  0x021F2180  thumb  ov029
 */

typedef unsigned int   u32;
extern void WIPE_SetBrightnessFadeOut(u32 a, u32 color);
extern void WIPE_ResetBrightness(u32 which);
typedef unsigned char  u8;
extern void C_GEAR_Cleanup(char *p);
extern void C_GEAR_Init(u8 *p, int a1, int a2, int a3, int e);
extern void C_GEAR_StepIdle(char *p);

int C_GEAR_Restart(int *p)
{
    int a = p[8];
    int b = p[6];
    int c = p[7];

    if (p[0] == (int)C_GEAR_StepIdle) {
        WIPE_SetBrightnessFadeOut(1, 0);
        C_GEAR_Cleanup((char *)p);
        C_GEAR_Init((u8 *)p, a, b, c, 0);
        WIPE_ResetBrightness(1);
        return 1;
    }
    return 0;
}

/*
 * function: func_021D6DF4
 * address: 0x021D6DF4
 * packet: pkt_ov121_021D6DF4
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   FADE_Start 0x0204E720 arm
 *   FADE_IsActive 0x0204E804 arm
 *   func_021DA8B0 0x021DA8B0 thumb ov121
 *   func_021D80C0 0x021D80C0 thumb ov121
 *   GFL_USE_FadeOutBgm  0x02005E30  thumb  arm9
 */
typedef signed int     s32;
typedef unsigned int   u32;
extern void FADE_Start(u32 a, s32 b, s32 c, s32 d);
extern int FADE_IsActive(void);
extern void GFL_USE_FadeOutBgm(u32 a);
extern void func_021DA8B0(u32 *p, u32 a);
extern void func_021D80C0(void *p, int n, char *q);
void func_021D6DF4(void *a, int *state)
{
    switch (*state) {
    case 0: FADE_Start(12, 0, 16, 0); GFL_USE_FadeOutBgm(8); *state = 1; break;
    case 1: if (!FADE_IsActive()) *state = 2; break;
    case 2: func_021DA8B0(a, (u32)func_021D80C0); break;
    }
}

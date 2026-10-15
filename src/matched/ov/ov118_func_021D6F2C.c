/*
 * function: POKETRADE_DEMO_MIDDLE_StepStartCompare
 * address:  0x021D6F2C
 * packet:   pkt_ov118_021D6F2C
 * region:   ov118
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   POKETRADE_DEMO_DOWN_SetFinishFlag  0x021D6744  thumb
 *   MCSS_SetAnimeIndex  0x02016028  thumb
 *   POKETRADE_PROC_IsHostSide  0x021D8AA8  thumb ov119
 *   POKETRADE_DEMO_DOWN_SetFrame  0x021D6738  thumb
 *   POKETRADE_PROC_SetStep  0x021D8E84  thumb
 *   POKETRADE_DEMO_DOWN_StepStartPlayback  0x021D6750  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;
typedef unsigned char u8;

extern void POKETRADE_DEMO_DOWN_SetFinishFlag(u8 *p);
extern void MCSS_SetAnimeIndex(void *a, u32 flag);
extern int POKETRADE_PROC_IsHostSide(void *p);
extern void POKETRADE_DEMO_DOWN_SetFrame(u8 *p, u32 v);
extern void POKETRADE_PROC_SetStep(void *p, int next);
extern void POKETRADE_DEMO_DOWN_StepStartPlayback(u8 *p);

#define OBJ(i) (((u32 *)(p + 0x844))[i])
#define FLAG(i) (((int *)(p + 0x854))[i])

void POKETRADE_DEMO_MIDDLE_StepStartCompare(u8 *p)
{
    u32 t;

    POKETRADE_DEMO_DOWN_SetFinishFlag(p);
    FLAG(0) = 1;
    MCSS_SetAnimeIndex((void *)OBJ(0), 0);
    FLAG(1) = 1;
    MCSS_SetAnimeIndex((void *)OBJ(1), 0);
    if (POKETRADE_PROC_IsHostSide(p)) {
        t = OBJ(0);
        OBJ(0) = OBJ(1);
        OBJ(1) = t;
    }
    POKETRADE_DEMO_DOWN_SetFrame(p, 0);
    POKETRADE_PROC_SetStep(p, (int)POKETRADE_DEMO_DOWN_StepStartPlayback);
}

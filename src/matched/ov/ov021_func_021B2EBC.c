/*
 * function: SCRCMD_SCREENEFFECTS_CreateFadeTask
 * address:  0x021B2EBC
 * packet:   pkt_ov021_021B2EBC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELDMAP_GetTcblSys  0x02188D30  thumb  ov021
 *   func_02030734  0x02030734  arm
 *   func_02030DA8  0x02030DA8  arm
 *   FIELDMAP_SetScriptEffectBusy  0x02189A1C  thumb  ov021
 *   SCRCMD_SCREENEFFECTS_StepFadeTask  0x021B2F18  thumb  ov021
 *   d_021DE14C     0x021DE14C  data  a4
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 FIELDMAP_GetTcblSys(u8 *p);
extern void *func_02030734(u32, u32, int, const char *, u16);
extern void func_02030DA8(int, void (*)(), u32 *, u32);
extern void FIELDMAP_SetScriptEffectBusy(u8 *p, u32 v);
extern void SCRCMD_SCREENEFFECTS_StepFadeTask(int p, int *q);
extern u8 d_021DE14C;

void SCRCMD_SCREENEFFECTS_CreateFadeTask(u32 a, u32 b, u32 c, u32 d, u32 e)
{
    int h = FIELDMAP_GetTcblSys((u8 *)b);
    u32 *w = func_02030734(4, 0x18, 1, (const char *)&d_021DE14C, 0x369);

    func_02030DA8(h, SCRCMD_SCREENEFFECTS_StepFadeTask, w, 0);
    FIELDMAP_SetScriptEffectBusy((u8 *)b, 1);
    w[5] = 0;
    w[0] = a;
    w[1] = b;
    w[2] = d;
    w[3] = e;
    w[4] = c;
}

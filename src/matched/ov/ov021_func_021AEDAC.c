/*
 * function: SCRCMD_IncrementTrainerRecord
 * address:  0x021AEDAC
 * packet:   pkt_ov021_021AEDAC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   ZONEDATA_IsZoneInTableDFD2  0x02014024  thumb
 *   FIELDMAP_GetZoneId  0x02188C9C  thumb  ov021
 *   SCRIPT_WORK_ResetFieldParam  0x02158F58  thumb  ov010
 *   SCRCMD_WORK_GetGameData  0x0215A5E4  thumb  ov010
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   GAME_DATA_GetTrainerRecord  0x02012F2C  thumb  arm9
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

typedef struct R { u32 f0; u32 f4; } R;

extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern void *SCRCMD_WORK_GetGameData(void *a0);
struct Sub02008C20Obj;
extern int SCRIPT_WORK_ResetFieldParam(int a0);
extern void *GAME_DATA_GetTrainerRecord(int *p);
extern u16 FIELDMAP_GetZoneId(u8 *p);
extern int ZONEDATA_IsZoneInTableDFD2(u32 a);
extern u32 func_02008DF0(struct Sub02008C20Obj *obj, int i);

void SCRCMD_IncrementTrainerRecord(u32 a)
{
    R *p = (R *)SCRIPT_WORK_ResetFieldParam((int)SCRCMD_WORK_GetScriptWork((void *)a));
    u32 q = (u32)GAME_DATA_GetTrainerRecord(SCRCMD_WORK_GetGameData((void *)a));

    if (ZONEDATA_IsZoneInTableDFD2(FIELDMAP_GetZoneId((u8 *)p->f4)) != 0)
        func_02008DF0((struct Sub02008C20Obj *)q, 0x20);
}

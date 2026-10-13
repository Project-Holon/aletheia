/*
 * function: SCRCMD_GetTrainerHitKind
 * address:  0x021AE9CC
 * packet:   pkt_ov021_021AE9CC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRIPT_WORK_GetTrainerEntry  0x02159124  thumb  ov010
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

typedef struct R { u8 pad[0x14]; u32 f14; u32 f18; } R;

extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern char *SCRIPT_WORK_GetTrainerEntry(char *p, int i);
extern u16 *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);

int SCRCMD_GetTrainerHitKind(u32 a, u32 b)
{
    R *p = (R *)SCRIPT_WORK_GetTrainerEntry(SCRCMD_WORK_GetScriptWork((void *)b), 0);

    *SCRIPT_WORK_ReadWorkPointer((void *)a, (void *)b) = p->f14;
    return 0;
}

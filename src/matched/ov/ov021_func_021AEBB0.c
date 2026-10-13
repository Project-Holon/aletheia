/*
 * function: SCRCMD_GetTrainerMessageIds
 * address:  0x021AEBB0
 * packet:   pkt_ov021_021AEBB0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRIPT_WORK_GetScriptId  0x02158F8C  thumb  ov010
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   func_0215A460  0x0215A460  thumb  ov010
 *   func_0215A4B4  0x0215A4B4  thumb  ov010
 *   func_0215A4A0  0x0215A4A0  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;
typedef unsigned short u16;

extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern unsigned short SCRIPT_WORK_GetScriptId(unsigned char *p);
extern u16 *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
extern u32 func_0215A460(u32 a);
extern int func_0215A4B4(int a0);
extern u32 func_0215A4A0(u32 a);

int SCRCMD_GetTrainerMessageIds(u32 a, u32 b)
{
    u32 h;
    u16 *x, *y, *z;
    u32 v0, v1, v2;

    h = SCRIPT_WORK_GetScriptId((unsigned char *)SCRCMD_WORK_GetScriptWork((void *)b));
    x = SCRIPT_WORK_ReadWorkPointer((void *)a, (void *)b);
    y = SCRIPT_WORK_ReadWorkPointer((void *)a, (void *)b);
    z = SCRIPT_WORK_ReadWorkPointer((void *)a, (void *)b);
    if ((u16)func_0215A4B4(func_0215A460(h)) == 0) {
        v0 = 0;
        v1 = 2;
        v2 = 24;
    } else if ((u16)func_0215A4A0(h) == 0) {
        v0 = 3;
        v1 = 5;
        v2 = 6;
    } else {
        v0 = 7;
        v1 = 9;
        v2 = 10;
    }
    *x = v0;
    *y = v1;
    *z = v2;
    return 0;
}

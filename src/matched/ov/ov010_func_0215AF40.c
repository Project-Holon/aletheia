/*
 * function: SCRCMD_WORK_CmdGetZukanSeenCount
 * address:  0x0215AF40
 * packet:   pkt_ov010_0215AF40
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   SCRCMD_WORK_GetGameData  0x0215A5E4  thumb  ov010
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   func_0200CA1C  0x0200CA1C  thumb
 *   func_0200D064  0x0200D064  thumb
 *   func_0200CED4  0x0200CED4  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *SCRCMD_WORK_GetGameData(void *a0);
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *a0, void *a1);
extern u16 *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
extern void *func_0200CA1C(void *a);
extern int func_0200D064();
extern int func_0200CED4();

int SCRCMD_WORK_CmdGetZukanSeenCount(int a0, int a1)
{
    void *v;
    int k, x;
    u16 *out;
    v = func_0200CA1C((void *)SCRCMD_WORK_GetGameData((void *)a1));
    k = (int)SCRIPT_WORK_ReadWorkValue((void *)a0, (void *)a1);
    x = (int)SCRIPT_WORK_ReadWorkValue((void *)a0, (void *)a1);
    out = SCRIPT_WORK_ReadWorkPointer((void *)a0, (void *)a1);
    switch (k) {
    case 0:
        *out = func_0200D064(v, x);
        break;
    case 1:
        *out = func_0200CED4(v, x);
        break;
    default:
        *out = 0;
        break;
    }
    return 0;
}

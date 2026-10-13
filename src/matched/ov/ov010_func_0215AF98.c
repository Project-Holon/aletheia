/*
 * function: SCRCMD_WORK_CmdGetZukanGetCount
 * address:  0x0215AF98
 * packet:   pkt_ov010_0215AF98
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRCMD_WORK_GetGameData  0x0215A5E4  thumb  ov010
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   func_0200CA1C  0x0200CA1C  thumb
 *   func_0200D0CC  0x0200D0CC  thumb
 *   func_0200CF28  0x0200CF28  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *SCRCMD_WORK_GetGameData(void *a0);
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *a0, void *a1);
extern u16 *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
extern void *func_0200CA1C(void *a);
struct Blk37;
extern u16 func_0200D0CC(struct Blk37 *p);
extern u16 func_0200CF28(struct Blk37 *p);

int SCRCMD_WORK_CmdGetZukanGetCount(int a0, int a1)
{
    void *v;
    int k;
    u16 *out;
    v = func_0200CA1C((void *)SCRCMD_WORK_GetGameData((void *)a1));
    k = (int)SCRIPT_WORK_ReadWorkValue((void *)a0, (void *)a1);
    out = SCRIPT_WORK_ReadWorkPointer((void *)a0, (void *)a1);
    switch (k) {
    case 0:
        *out = func_0200D0CC(v);
        break;
    case 1:
        *out = func_0200CF28(v);
        break;
    default:
        *out = 0;
        break;
    }
    return 0;
}

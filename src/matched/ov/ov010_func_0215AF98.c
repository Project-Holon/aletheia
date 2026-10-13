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
 *   ZUKAN_SAVE_GetFromGameData  0x0200CA1C  thumb
 *   ZUKAN_SAVE_CountSeenNational  0x0200D0CC  thumb
 *   ZUKAN_SAVE_CountCaughtNational  0x0200CF28  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *SCRCMD_WORK_GetGameData(void *a0);
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *a0, void *a1);
extern u16 *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
extern void *ZUKAN_SAVE_GetFromGameData(void *a);
struct Blk37;
extern u16 ZUKAN_SAVE_CountSeenNational(struct Blk37 *p);
extern u16 ZUKAN_SAVE_CountCaughtNational(struct Blk37 *p);

int SCRCMD_WORK_CmdGetZukanGetCount(int a0, int a1)
{
    void *v;
    int k;
    u16 *out;
    v = ZUKAN_SAVE_GetFromGameData((void *)SCRCMD_WORK_GetGameData((void *)a1));
    k = (int)SCRIPT_WORK_ReadWorkValue((void *)a0, (void *)a1);
    out = SCRIPT_WORK_ReadWorkPointer((void *)a0, (void *)a1);
    switch (k) {
    case 0:
        *out = ZUKAN_SAVE_CountSeenNational(v);
        break;
    case 1:
        *out = ZUKAN_SAVE_CountCaughtNational(v);
        break;
    default:
        *out = 0;
        break;
    }
    return 0;
}

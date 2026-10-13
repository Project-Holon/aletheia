/*
 * function: SCRCMD_WORK_CmdGetZukanNationalFlag
 * address:  0x0215AFF4
 * packet:   pkt_0215AFF4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   SCRCMD_WORK_GetGameData  0x0215A5E4  thumb  ov010
 *   ZUKAN_SAVE_GetFromGameData  0x0200CA1C  thumb
 *   ZUKAN_SAVE_IsNationalDexEnabled  0x0200CA38  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u16 *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
extern void *SCRCMD_WORK_GetGameData(void *a0);
extern void *ZUKAN_SAVE_GetFromGameData(void *a);
struct Blk37;
extern u32 ZUKAN_SAVE_IsNationalDexEnabled(struct Blk37 *p);

int SCRCMD_WORK_CmdGetZukanNationalFlag(int a0, int a1)
{
    int t5;
    void *p;
    u16 *q;
    void *v0;

t5 = a1 + 0;
    q = SCRIPT_WORK_ReadWorkPointer((void *)a0, (void *)a1);
loc_0215AFFC:
a0 = t5 + 0;
    v0 = SCRCMD_WORK_GetGameData((void *)a0);
loc_0215B004:
    p = ZUKAN_SAVE_GetFromGameData(v0);
loc_0215B008:
    a0 = ZUKAN_SAVE_IsNationalDexEnabled(p);
loc_0215B00C:
*q = a0;
a0 = 0;
    return a0;}

/*
 * function: SCRCMD_WORK_CmdCheckMapReplaceFlag
 * address:  0x0215AEB8
 * packet:   pkt_0215AEB8
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
 *   MAP_REPLACE_CheckFlag  0x02159F54  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *SCRCMD_WORK_GetGameData(void *a0);
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *, void *);
extern u16 *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
extern int MAP_REPLACE_CheckFlag(int a, int b);

int SCRCMD_WORK_CmdCheckMapReplaceFlag(int a0, int a1)
{
    int t4;
    int t5;
    int t7;
    u16 *q;
    void *v0;

t4 = a1 + 0;
t5 = a0 + 0;
a0 = t4 + 0;
    v0 = SCRCMD_WORK_GetGameData((void *)a0);
loc_0215AEC4:
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = SCRIPT_WORK_ReadWorkValue((void *)a0, (void *)a1);
loc_0215AECE:
t7 = a0 + 0;
a0 = t5 + 0;
a1 = t4 + 0;
    q = SCRIPT_WORK_ReadWorkPointer((void *)a0, (void *)a1);
loc_0215AED8:
a1 = t7 + 0;
    a0 = MAP_REPLACE_CheckFlag((int)v0, a1);
loc_0215AEE2:
*q = a0;
a0 = 0;
    return a0;}

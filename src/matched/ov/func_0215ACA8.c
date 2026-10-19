/*
 * function: SCRCMD_WORK_CmdGetBadgeCount
 * address:  0x0215ACA8
 * packet:   pkt_0215ACA8
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
 *   GAME_DATA_GetMiscSave  0x02012F08  thumb
 *   MISC_CountBadges  0x0200C258  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u16 *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
extern void *SCRCMD_WORK_GetGameData(void *a0);
extern void *GAME_DATA_GetMiscSave(int *p);
struct Blk34;
extern u32 MISC_CountBadges(struct Blk34 *p);

int SCRCMD_WORK_CmdGetBadgeCount(int a0, int a1)
{
    u16 *t4;
    int t5;
    void *p;
    void *v0;

t5 = a1 + 0;
    t4 = SCRIPT_WORK_ReadWorkPointer((void *)a0, (void *)a1);
loc_0215ACB0:
a0 = t5 + 0;
    v0 = SCRCMD_WORK_GetGameData((void *)a0);
loc_0215ACB8:
    p = GAME_DATA_GetMiscSave((int *)v0);
loc_0215ACBC:
    a0 = MISC_CountBadges(p);
loc_0215ACC0:
*t4 = a0;
a0 = 0;
    return a0;}

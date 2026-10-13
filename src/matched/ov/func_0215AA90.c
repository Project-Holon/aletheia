/*
 * function: SCRCMD_WORK_CmdGetConfigFlag
 * address:  0x0215AA90
 * packet:   pkt_0215AA90
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * blocked:  
 *
 * symbols:
 *   SCRCMD_WORK_GetGameData  0x0215A5E4  thumb  ov010
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   func_0200873C  0x0200873C  thumb
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   CONFIG_GetAppliedFlag  0x020083E4  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Big;
struct Sub02008700Obj;
extern void *SCRCMD_WORK_GetGameData(void *a0);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern struct Sub02008700Obj *func_0200873C(void *sys);
extern u16 *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
extern int CONFIG_GetAppliedFlag(unsigned short *p);

int SCRCMD_WORK_CmdGetConfigFlag(int a0, int a1)
{
    int t5;
    int t6;
    void *p;
    struct Sub02008700Obj *t4;
    u16 *q;
    void *v0;

t6 = a1 + 0;
t5 = a0 + 0;
a0 = t6 + 0;
    v0 = SCRCMD_WORK_GetGameData((void *)a0);
loc_0215AA9C:
    p = GAME_DATA_GetSaveControl((struct Big *)v0);
loc_0215AAA0:
    t4 = func_0200873C(p);
loc_0215AAA4:
a0 = t5 + 0;
a1 = t6 + 0;
    q = SCRIPT_WORK_ReadWorkPointer((void *)a0, (void *)a1);
loc_0215AAAE:
    a0 = CONFIG_GetAppliedFlag((short unsigned int *)t4);
loc_0215AAB6:
*q = a0;
a0 = 0;
    return a0;}

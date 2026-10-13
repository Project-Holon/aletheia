/*
 * function: SCRIPT_WORK_CmdGetContinueFlag
 * address:  0x02159708
 * packet:   pkt_02159708
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
 *   GAME_DATA_GetMoveModelSys  0x02012B38  thumb
 *   FIELD_STATUS_GetContinueFlag  0x02014460  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct BigObj;
extern u16 *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
extern void *SCRCMD_WORK_GetGameData(void *a0);
extern void *GAME_DATA_GetMoveModelSys(const struct BigObj *p);
struct Sub02014444Obj;
extern u8 FIELD_STATUS_GetContinueFlag(struct Sub02014444Obj *o);

int SCRIPT_WORK_CmdGetContinueFlag(int a0, int a1)
{
    int t5;
    void *p;
    u16 *q;
    void *v0;

t5 = a1 + 0;
    q = SCRIPT_WORK_ReadWorkPointer((void *)a0, (void *)a1);
loc_02159710:
a0 = t5 + 0;
    v0 = SCRCMD_WORK_GetGameData((void *)a0);
loc_02159718:
    p = GAME_DATA_GetMoveModelSys((const struct BigObj *)v0);
loc_0215971C:
    a0 = FIELD_STATUS_GetContinueFlag(p);
loc_02159720:
*q = a0;
a0 = 0;
    return a0;}

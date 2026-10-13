/*
 * function: SCRCMD_WORK_CmdGetButtonMode
 * address:  0x0215B028
 * packet:   pkt_0215B028
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * blocked:  
 *
 * symbols:
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   func_0200873C  0x0200873C  thumb
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   CONFIG_GetButtonMode  0x02008428  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Ctx;
struct Big;
struct Sub02008700Obj;
extern void *SCRCMD_WORK_GetGameSystem(void *a0);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern struct Sub02008700Obj *func_0200873C(void *sys);
extern u16 *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
extern int CONFIG_GetButtonMode(unsigned short *p);

int SCRCMD_WORK_CmdGetButtonMode(int a0, int a1)
{
    int t5;
    int t6;
    void *p;
    void *q;
    struct Sub02008700Obj *t4;
    u16 *dst;
    void *v0;

t6 = a1 + 0;
t5 = a0 + 0;
a0 = t6 + 0;
    v0 = SCRCMD_WORK_GetGameSystem((void *)a0);
loc_0215B034:
    p = GAMESYSTEM_GetGameData((const struct Ctx *)v0);
loc_0215B038:
    q = GAME_DATA_GetSaveControl(p);
loc_0215B03C:
    t4 = func_0200873C(q);
loc_0215B040:
a0 = t5 + 0;
a1 = t6 + 0;
    dst = SCRIPT_WORK_ReadWorkPointer((void *)a0, (void *)a1);
loc_0215B04A:
    a0 = CONFIG_GetButtonMode((short unsigned int *)t4);
loc_0215B052:
    if (a0 == 0) goto loc_0215B05C;
loc_0215B056:
    if (a0 == 1) goto loc_0215B060;
loc_0215B05A:
    goto loc_0215B064;
loc_0215B05C:
a0 = 0;
    goto loc_0215B062;
loc_0215B060:
a0 = 1;
loc_0215B062:
*dst = a0;
loc_0215B064:
a0 = 0;
    return a0;}

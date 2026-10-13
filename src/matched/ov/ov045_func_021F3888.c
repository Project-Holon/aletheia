/*
 * function: GIMMICK45_StartSwitchToggleEvent
 * address: 0x021F3888
 * packet: pkt_ov045_021F3888
 * region: ov045
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   FIELDMAP_GetGameSystem 0x02188C80 thumb ov021
 *   FIELDMAP_GetCommonWork 0x021897BC thumb ov021
 *   GIMMICK45_SwitchToggleEventProc 0x021F3A68 thumb ov045
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb  arm9
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb  arm9
 *   GAME_DATA_GetFieldSave  0x02012EC4  thumb  arm9
 */
typedef unsigned int u32;
struct Ctx;
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *);
typedef unsigned char  u8;
struct Big;
extern void *FIELDMAP_GetGameSystem(void *p);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern u8 *GAME_DATA_GetFieldSave(struct Big *p);
extern int *FIELDMAP_GetCommonWork(char *,int);
extern int GIMMICK45_SwitchToggleEventProc(void *,int *);
struct Desc;
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
void *GIMMICK45_StartSwitchToggleEvent(void *a,int b)
{
    u32 p;
    int *q;
    p=(u32)GAMESYSTEM_GetFieldMap(a);
    GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem((void *)p)));
    q=FIELDMAP_GetCommonWork((char *)p,1);
    if(b>=3)return 0;
    *q=b;
    return func_020122C0(a,0,GIMMICK45_SwitchToggleEventProc,0);
}

/*
 * function: FIELD_GIMMICK_LANE_TRAINS_Update
 * address: 0x021F373C
 * packet: pkt_ov058_021F373C
 * region: ov058
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   FIELDMAP_GetGameSystem 0x02188C80 thumb ov021
 *   FIELDMAP_GetExpObj 0x02188D2C thumb ov021
 *   FIELDMAP_GetCommonWork 0x021897BC thumb ov021
 *   FLD_EXP_OBJ_GetModelStatus 0x021BE480 thumb ov021
 *   FIELDMAP_GetFieldPlayer 0x02188CB4 thumb ov021
 *   FIELD_PLAYER_GetPos 0x021A3038 thumb ov021
 *   GAMESYSTEM_GetGameData 0x020120F4 thumb
 *   GAME_DATA_GetFieldSave 0x02012EC4 thumb
 *   GAME_DATA_GetBgmInfo 0x02012A30 thumb
 *   func_020056EC 0x020056EC thumb
 *   GFL_USE_GetSeSlot 0x02006148 thumb
 *   GFL_USE_IsSeSlotBusy 0x02006224 thumb
 *   FIELD_SOUND_SYSTEM_ClaimSlot 0x02028A7C thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Ctx;
struct Big;
struct BigObj;
struct SoundSys2;
struct VecFx32 { int x,y,z; };
extern void *FIELDMAP_GetGameSystem(void *);
extern int FIELDMAP_GetExpObj(int *);
extern int *FIELDMAP_GetCommonWork(char *,int);
extern int FLD_EXP_OBJ_GetModelStatus(char *p, unsigned i, int j);
struct Obj00020;
extern void *FIELDMAP_GetFieldPlayer(struct Obj00020 *p);
extern void FIELD_PLAYER_GetPos(u8 *,struct VecFx32 *);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *);
extern u8 *GAME_DATA_GetFieldSave(struct Big *);
extern u32 GAME_DATA_GetBgmInfo(const struct BigObj *);
extern u32 func_020056EC(u32);
extern int GFL_USE_GetSeSlot(u32);
extern int GFL_USE_IsSeSlotBusy(u32);
extern void FIELD_SOUND_SYSTEM_ClaimSlot(struct SoundSys2 *,u32);
#define W(p,k) (*(int *)((u8 *)(p)+(k)))
#define H(p,k) (*(u16 *)((u8 *)(p)+(k)))
void FIELD_GIMMICK_LANE_TRAINS_Update(struct Obj00020 *p)
{
    struct VecFx32 pos;
    int first;
    int second;
    void *big;
    void *scene;
    void *state;
    u8 *part;
    int i;
    int *entry;
    struct SoundSys2 *sound;
    int delta;
    big=GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(p));
    GAME_DATA_GetFieldSave(big);
    scene=(void *)FIELDMAP_GetExpObj((int *)p);
    state=FIELDMAP_GetCommonWork((char *)p,1);
    part=(u8 *)state+8;
    if(H(part,4)!=0) H(part,4)--;
    else {
        i=H(part,6)*4;
        W(part,0)++;
        entry=(int *)FLD_EXP_OBJ_GetModelStatus(scene,0,(u16)i);
        *entry=(W(part,0)<<16)+0x1770000;
        if(*entry>=0x1c60000) {
            W(part,0)=0;
            W(state,16)=0;
            H(part,4)=func_020056EC(30)+30;
            H(part,6)=func_020056EC(3);
        }
        first=*entry;
        entry=(int *)FLD_EXP_OBJ_GetModelStatus(scene,0,(u16)(i+1));
        *entry=(W(part,0)<<16)+0x1710000;
        if(*entry>=0x1c60000) W(part,0)=0;
    }
    part=(u8 *)state+20;
    if(H(part,4)!=0) H(part,4)--;
    else {
        i=H(part,6)*4+2;
        W(part,0)++;
        entry=(int *)FLD_EXP_OBJ_GetModelStatus(scene,0,(u16)i);
        *entry=0x1c60000-(W(part,0)<<16);
        if(*entry<=0x1770000) {
            W(part,0)=0;
            W(state,28)=0;
            H(part,4)=func_020056EC(30);
            H(part,6)=func_020056EC(3);
        }
        second=*entry;
        entry=(int *)FLD_EXP_OBJ_GetModelStatus(scene,0,(u16)(i+1));
        *entry=0x1cc0000-(W(part,0)<<16);
        if(*entry<=0x1770000) W(part,0)=0;
    }
    FIELD_PLAYER_GetPos(FIELDMAP_GetFieldPlayer(p),&pos);
    if(pos.z>=0x2020000 && pos.z<=0x2140000) {
        sound=(struct SoundSys2 *)GAME_DATA_GetBgmInfo(big);
        delta=pos.x-first;
        if(delta>=0 && delta<=0x40000 && W(state,16)==0) {
            if(GFL_USE_IsSeSlotBusy(GFL_USE_GetSeSlot(0x77e))==0) {
                W(state,16)=1;
                FIELD_SOUND_SYSTEM_ClaimSlot(sound,0x77e);
            }
        }
        delta=second-pos.x;
        if(delta>=0 && delta<=0x40000 && W(state,28)==0) {
            if(GFL_USE_IsSeSlotBusy(GFL_USE_GetSeSlot(0x77f))==0) {
                W(state,28)=1;
                FIELD_SOUND_SYSTEM_ClaimSlot(sound,0x77f);
            }
        }
    }
}

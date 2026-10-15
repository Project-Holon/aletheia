/*
 * file:     livebattlematch_flow.c
 * unit:     yes
 * function: LIVEBATTLEMATCH_FLOW_Create, LIVEBATTLEMATCH_FLOW_Delete, LIVEBATTLEMATCH_FLOW_Release, LIVEBATTLEMATCH_FLOW_GetResult, LIVEBATTLEMATCH_FLOW_SelectPhase, LIVEBATTLEMATCH_FLOW_End, LIVEBATTLEMATCH_FLOW_Main, LIVEBATTLEMATCH_FLOW_Confirm, LIVEBATTLEMATCH_FLOW_Battle, LIVEBATTLEMATCH_FLOW_Result, LIVEBATTLEMATCH_FLOW_Card, LIVEBATTLEMATCH_FLOW_Sub, LIVEBATTLEMATCH_FLOW_DrawMenu, LIVEBATTLEMATCH_FLOW_HideWindow, LIVEBATTLEMATCH_FLOW_GetWindowResult
 * address:  0x0217B984
 * region:   ov176
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from battle_championship_flow.c by tools/splitfile.py.
 *
 * symbols:
 *   MI_CpuFill8 0x02082BCC arm
 *   func_021E8A3C 0x021E8A3C thumb ov177
 *   BTLV_CORE_IsSlotKind1Index15  0x021E8A78  thumb  ov093
 *   func_021E8A80 0x021E8A80 thumb ov177
 *   func_021E8A90 0x021E8A90 thumb ov177
 *   WIFIBATTLEMATCH_GRAPHIC_GetCamera  0x021E5548  thumb  ov177
 *   GF_FONT_Create 0x0201D7EC thumb
 *   func_02045B38 0x02045B38 arm
 *   MSGDATA_Delete  0x02045C04  arm
 *   GF_FONT_Delete  0x0201D83C  thumb
 *   func_021E8AA0 0x021E8AA0 thumb ov177
 *   func_021E8AA8 0x021E8AA8 thumb ov177
 *   func_02034714 0x02034714 arm
 *   func_02030734 0x02030734 arm
 *   func_020307B0 0x020307B0 arm
 *   BATTLE_REC_ClearWork 0x0200B480 thumb
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   BATTLE_COMPETITION_GetFromSave 0x0200B358 thumb
 *   REGULATION_GetCard 0x0200B1D4 thumb
 *   func_021E88B0 0x021E88B0 thumb ov177
 *   func_021E89D0 0x021E89D0 thumb ov177
 *   func_021E8A00 0x021E8A00 thumb ov177
 *   BATTLE_REC_IsDataExist 0x0200B45C thumb
 *   func_021E58A4 0x021E58A4 thumb ov177
 *   WORDSET_Create 0x0201EC74 thumb
 *   func_0217E00C 0x0217E00C thumb ov176
 *   func_021E7D20 0x021E7D20 thumb ov177
 *   func_021E7E0C 0x021E7E0C thumb ov177
 *   MISC_SAVEDATA_GetBlock3C 0x0200E9F4 thumb
 *   MISC_SAVEDATA_GetRecordBase 0x0200EA08 thumb
 *   POKEPARTY_Create 0x0201A920 thumb
 *   UI_SetFlags39Global 0x0203516C arm
 *   d_0217E600 0x0217E600 data a4
 *   UI_ClearFlags39Global 0x020351A0 arm
 *   func_0217D174 0x0217D174 thumb ov176
 *   func_0217D224 0x0217D224 thumb ov176
 *   func_021E7DF0 0x021E7DF0 thumb ov177
 *   func_0217E058 0x0217E058 thumb ov176
 *   WORDSET_DeleteStrbufED04 0x0201ED04 thumb
 *   func_0217E074 0x0217E074 thumb ov176
 *   func_021E7E08 0x021E7E08 thumb ov177
 *   func_021E64C0 0x021E64C0 thumb ov177
 *   func_021E7774 0x021E7774 thumb ov177
 *   func_021E84F8 0x021E84F8 thumb ov177
 *   REGULATION_Card_GetValue 0x0200B078 thumb
 *   d_0217E618 0x0217E618 data a4
 *   func_0217D028 0x0217D028 thumb ov176
 *   func_0217D1A0 0x0217D1A0 thumb ov176
 *   func_0217D188 0x0217D188 thumb ov176
 *   BATTLE_BOX_GetFromSave 0x0200BAC8 thumb
 *   func_0217CFE8 0x0217CFE8 thumb ov176
 *   func_021E8AB4 0x021E8AB4 thumb ov177
 *   func_0217D194 0x0217D194 thumb ov176
 *   func_0217D010 0x0217D010 thumb ov176
 *   REGULATION_GetParty 0x0200B204 thumb
 *   REGULATION_Card_SetValue 0x0200B110 thumb
 *   GAME_DATA_SaveStart 0x02012DAC thumb
 *   GAME_DATA_SaveMain 0x02012DD0 thumb
 *   func_0217D000 0x0217D000 thumb ov176
 *   func_021E8AB8 0x021E8AB8 thumb ov177
 *   BATTLE_BOX_IsLocked 0x0200BBFC thumb
 *   func_0217E318 0x0217E318 thumb ov176
 *   func_0217E380 0x0217E380 thumb ov176
 *   func_0217E078 0x0217E078 thumb ov176
 *   KEY_GetTrg 0x020362DC arm
 *   func_0217E40C 0x0217E40C thumb ov176
 *   func_0217E414 0x0217E414 thumb ov176
 *   REGULATION_Card_IsCrcValid 0x0200B1A8 thumb
 *   func_0200E904 0x0200E904 thumb
 *   REGULATION_InitParty 0x0200B1F8 thumb
 *   REGULATION_SetCard 0x0200B1E0 thumb
 *   func_0217D244 0x0217D244 thumb ov176
 *   func_0217D2A4 0x0217D2A4 thumb ov176
 *   func_0217D2B0 0x0217D2B0 thumb ov176
 *   func_0217D290 0x0217D290 thumb ov176
 *   REGULATION_NoOp 0x0200AE14 thumb
 *   func_0217D2BC 0x0217D2BC thumb ov176
 *   POKEPARTY_GetBattleReadyCount 0x0201AA50 thumb
 *   POKE_REGULATION_CheckParty 0x0201A090 thumb
 *   func_0200BAF4 0x0200BAF4 thumb
 *   BATTLE_BOX_SetLockFlags 0x0200BBC8 thumb
 *   REGULATION_BuildParty 0x0200B2A4 thumb
 *   func_0217D2F0 0x0217D2F0 thumb ov176
 *   func_0200E918 0x0200E918 thumb
 *   REGULATION_GetRuleValue 0x0200AE54 thumb
 *   BATTLE_BOX_ClearLockFlags 0x0200BBD8 thumb
 *   BATTLE_REC_IsVersionSupported 0x0200BA38 thumb
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   func_0217E0A8 0x0217E0A8 thumb ov176
 *   func_0217E0B0 0x0217E0B0 thumb ov176
 *   func_0217E158 0x0217E158 thumb ov176
 *   func_0217E178 0x0217E178 thumb ov176
 *   func_0217D388 0x0217D388 thumb ov176
 *   func_0217E1FC 0x0217E1FC thumb ov176
 *   func_0217E23C 0x0217E23C thumb ov176
 *   POKE_REGULATION_GetDataSize 0x0201A918 thumb
 *   MI_CpuCopy8 0x02082D44 arm
 *   func_0200E994 0x0200E994 thumb
 *   GFL_USE_StopAllSe 0x02006210 thumb
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_HANDLE_SetTimingSyncRange 0x02039C68 arm
 *   GFL_NET_HANDLE_IsTimingSyncRange 0x02039CB4 arm
 *   func_0217E2C0 0x0217E2C0 thumb ov176
 *   func_0217E2F8 0x0217E2F8 thumb ov176
 *   func_0217E1B8 0x0217E1B8 thumb ov176
 *   func_0217E1C0 0x0217E1C0 thumb ov176
 *   func_02040588 0x02040588 arm
 *   func_0217D1C8 0x0217D1C8 thumb ov176
 *   func_0217D238 0x0217D238 thumb ov176
 *   MISC_SAVEDATA_GetBlock44 0x0200ED48 thumb
 *   func_02008530 0x02008530 thumb
 *   MISC_SAVEDATA_InsertRecentValue 0x0200ED54 thumb
 *   func_0200E958 0x0200E958 thumb
 *   func_0200E978 0x0200E978 thumb
 *   func_0200E920 0x0200E920 thumb
 *   func_0217D160 0x0217D160 thumb ov176
 */
#include "../../matched/include/Obj14362.h"
#include "../../matched/include/Obj14363.h"
#include "../../matched/include/Obj00053.h"
#include "../../matched/include/Obj24408.h"
#include "../../matched/include/Obj24409.h"
#include "../../matched/include/Obj24410.h"
#include "../../matched/include/Obj00241.h"
#include "../../matched/include/Obj24411.h"
#include "../../matched/include/Obj24412.h"
#include "../../matched/include/Obj24413.h"
#include "../../matched/include/Obj01271.h"
#include "../../matched/include/Obj24414.h"
#include "../../matched/include/Obj24416.h"
#include "../../matched/include/Obj24417.h"
#include "../../matched/include/Obj24418.h"
#include "../../matched/include/Obj24419.h"
#include "battle_championship_flow_shared_types.h"

struct Party;

struct WordSet;

struct Reg2;

struct Obj;

struct Rec1E;

struct RecBig;

struct Reg;

struct Entry;

struct Link;

struct L0200ED54;

struct Sub0200852CObj;

typedef unsigned int   u32_0217BA9C;

typedef unsigned u32_0217BBDC;

typedef unsigned u32_0217BFF8;

typedef unsigned u32_0217C2EC;

typedef unsigned u32_0217C628;

typedef unsigned u32_0217CAE0;

typedef unsigned int u32_0217CC78;

typedef unsigned int u32_0217CEAC;

typedef struct { u32_0217CEAC f00, f04, f08, option0, option1, option2, f18, count; u16 f20, f22, f24, f26; u32_0217CEAC f28; u16 f2c, f2e; } Menu_0217B970;

extern void MI_CpuFill8(void *,int,unsigned);

extern int *func_021E8A3C(int a, int b, int c);

extern void BTLV_CORE_IsSlotKind1Index15(int);

extern int func_021E8A90(int **);

extern int WIFIBATTLEMATCH_GRAPHIC_GetCamera(int *p);

extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);

extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);

extern u32 MSGDATA_Delete(struct Rec *rec);

extern u32 GF_FONT_Delete(void *ptr);

extern void func_021E8AA0(int *p, int v);

extern void func_021E8AA8(int a);

extern void func_02034714(const char *expr, u32 line, const char *file);

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);

extern u32 func_020307B0(void *p);

extern void BATTLE_REC_ClearWork(void);

extern void *GAME_DATA_GetSaveControl(struct Big *p);

extern void *BATTLE_COMPETITION_GetFromSave(void *);

extern struct RegulationCard *REGULATION_GetCard(struct RegulationCard *arr, u32 index);

extern void *func_021E88B0(Desc *,u8,u8,u8,u32,int);

extern void func_021E89D0(void *);

extern int func_021E8A00(void *);

extern u32 BATTLE_REC_IsDataExist(void);

extern void func_021E58A4(int,int,u32);

extern void *WORDSET_Create(u32,u32,u32);

extern void *func_0217E00C(int,int);

extern void **func_021E7D20(void *,void *,u32);

extern void func_021E7E0C(void **,int);

extern void *MISC_SAVEDATA_GetBlock3C(void *);

extern int MISC_SAVEDATA_GetRecordBase(int p);

extern struct Party *POKEPARTY_Create(u32 heap);

extern void UI_SetFlags39Global(int);

extern int UI_ClearFlags39Global(u32_0217BA9C v);

extern void func_0217D174(int *);

extern void func_0217D224(int *);

extern void func_021E7DF0(int *p);

extern void func_0217E058(int *p);

extern u32_0217BA9C WORDSET_DeleteStrbufED04(struct WordSet *p);

extern void func_0217E074(int);

extern void func_021E7E08(int);

extern int func_021E64C0(unsigned char *, void *);

extern int func_021E7774(void *p, void *mgr);

extern int func_021E84F8(char *p, void *q);

extern s32 REGULATION_Card_GetValue(struct Reg2 *p, unsigned int id);

extern void func_0217D028(u8 *);

extern void func_0217D1A0(u8 *,int);

extern int func_0217D188(u8 *);

extern void * BATTLE_BOX_GetFromSave(void *);

extern void func_0217CFE8(void *,int,int);

extern void func_021E8AB4(u32_0217BBDC,u32_0217BBDC);

extern int func_0217D194(int *p);

extern void func_0217D010(u8 *,int);

extern struct Rec1E *REGULATION_GetParty(struct RecBig *p, u32_0217BBDC index);

extern void REGULATION_Card_SetValue(struct Reg2 *p, u32_0217BBDC id, s32 value);

extern int GAME_DATA_SaveStart(int);

extern int GAME_DATA_SaveMain(u8 *);

extern int func_0217D000(u8 *);

extern void func_021E8AB8(u32_0217BBDC);

extern u32_0217BBDC BATTLE_BOX_IsLocked(struct Obj *p, u32_0217BBDC mask);

extern void func_0217E318(char *,unsigned);

extern int func_0217E380(char *);

extern int func_0217E078(u8 *p);

extern u32_0217BBDC KEY_GetTrg(void);

extern void func_0217E40C(int *);

extern int func_0217E414(char *);

extern u32_0217BBDC REGULATION_Card_IsCrcValid(struct Reg2 *p);

extern void func_0200E904(void *);

extern void REGULATION_InitParty(struct Rec1E *p);

extern void REGULATION_SetCard(struct RegulationCard *arr, u32_0217BBDC index, const struct RegulationCard *src);

extern void func_0217D244(char *);

extern int func_0217D2A4(u8 *);

extern int func_0217D2B0(u8 *);

extern void func_0217D290(u8 *);

extern void * REGULATION_NoOp(void *);

extern void func_0217D2BC(u8 *p, const void *q);

extern u32_0217BFF8 POKEPARTY_GetBattleReadyCount(void *);

extern int POKE_REGULATION_CheckParty(void *,void *,u32_0217BFF8 *);

extern void * func_0200BAF4(int,int);

extern void BATTLE_BOX_SetLockFlags(struct Obj *p, u32_0217BFF8 v);

extern void REGULATION_BuildParty(int,int);

extern void func_0217D2F0(u8 *,u8 *);

extern u8 func_0200E918(const u8 *base, u32_0217C2EC idx);

extern u32_0217C2EC REGULATION_GetRuleValue(struct Reg *p, u32_0217C2EC id);

extern void BATTLE_BOX_ClearLockFlags(struct Obj *p, int v);

extern u32_0217C2EC BATTLE_REC_IsVersionSupported(u32_0217C2EC v);

extern void GFL_USE_PlaySeDefaultVolume(u32_0217C628);

extern int func_0217E0A8(int *);

extern int func_0217E0B0(unsigned *);

extern void func_0217E158(unsigned *);

extern int func_0217E178(int *);

extern void func_0217D388(int *,int *);

extern int func_0217E1FC(int,int);

extern int func_0217E23C(char *,void **);

extern int POKE_REGULATION_GetDataSize(void);

extern void MI_CpuCopy8(const void *,void *,u32_0217C628);

extern u32_0217C628 func_0200E994(void *base, void *key);

extern void GFL_USE_StopAllSe(void);

extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);

extern void GFL_NET_HANDLE_SetTimingSyncRange(struct Link *,u32_0217C628,u32_0217C628);

extern u32_0217C628 GFL_NET_HANDLE_IsTimingSyncRange(struct Link *,u32_0217C628,u32_0217C628);

extern u32_0217C628 func_0217E2C0(int unused, int a);

extern int func_0217E2F8(u8 *p, const void *q);

extern int func_0217E1B8(int *);

extern int func_0217E1C0(int *);

extern void func_02040588(unsigned char which, unsigned char enable);

extern void func_0217D1C8(char *,int);

extern int func_0217D238(u8 *);

extern void *MISC_SAVEDATA_GetBlock44(void *);

extern u32_0217CAE0 func_02008530(const struct Sub0200852CObj *obj);

extern void MISC_SAVEDATA_InsertRecentValue(struct L0200ED54 *l, u32_0217CAE0 val);

extern void func_0200E958(u8 *,u32_0217CAE0,const void *);

extern void func_0200E978(u8 *,u32_0217CAE0,u32_0217CAE0,u8);

extern void func_0200E920(u8 *,u32_0217CAE0,int);

extern void func_0217D160(int *);

u8 *LIVEBATTLEMATCH_FLOW_Create(LiveBattleMatchInit *src,u32 heap);

void LIVEBATTLEMATCH_FLOW_Delete(int *p);

void LIVEBATTLEMATCH_FLOW_Release(int *p);

int LIVEBATTLEMATCH_FLOW_GetResult(int *p);

void LIVEBATTLEMATCH_FLOW_SelectPhase(int p,int *state,char *q);

void LIVEBATTLEMATCH_FLOW_End(int p);

void LIVEBATTLEMATCH_FLOW_Main(int *sys,u32_0217BBDC *state,u8 *p);

void LIVEBATTLEMATCH_FLOW_Confirm(int *sys,u32_0217BFF8 *state,u8 *p);

void LIVEBATTLEMATCH_FLOW_Battle(int *sys,u32_0217C2EC *state,u8 *p);

void LIVEBATTLEMATCH_FLOW_Result(int *sys,u32_0217C628 *state,u8 *p);

void LIVEBATTLEMATCH_FLOW_Card(int *sys,u32_0217CAE0 *state,u8 *p);

void LIVEBATTLEMATCH_FLOW_Sub(int *a, int *state, u8 *p);

void LIVEBATTLEMATCH_FLOW_DrawMenu(u8 *p, int mode);

void LIVEBATTLEMATCH_FLOW_HideWindow(int *p);

int LIVEBATTLEMATCH_FLOW_GetWindowResult(int *p);

extern const char d_0217E600[];

extern const char d_0217E618[];

/*
 * Note 2026-10-04 (wD2 lane12): byte-correct. Only unresolved relocation: MISC_SAVEDATA_GetRecordBase (witness). Filed src/matched/arm9/MISC_SAVEDATA_GetRecordBase.c (EXACT) this wave; it needs a manifest/shard so the witness exists, then this file re-verifies as EXACT with no C change.
 *   unsigned char *MISC_SAVEDATA_GetRecordBase(unsigned char *p) { return p; }
 */
u8 *LIVEBATTLEMATCH_FLOW_Create(LiveBattleMatchInit *src,u32 heap)
{
    int size=0x109;
    u8 *p;
    size=0x1dc;
    p=func_02030734(heap,size,0,d_0217E600,0x109);
    MI_CpuFill8(p,0,size);
    *(LiveBattleMatchInit *)(p+0x1a0)=*src;
    *(u16 *)(p+0x1c8)=heap;
    *(u32 *)(p+0x1d0)=BATTLE_REC_IsDataExist();
    func_021E58A4(*(int *)(p+0x1b0),1,heap);
    *(void **)(p+0x2c)=WORDSET_Create(8,0x40,heap);
    *(void **)(p+0x20)=func_02045B38(0,2,0x3a,heap);
    *(void **)(p+0x24)=func_02045B38(0,2,0xd2,heap);
    *(void **)(p+0x28)=GF_FONT_Create(0x17,3,0,0,heap);
    *(int **)p=func_021E8A3C((int)p,(int)LIVEBATTLEMATCH_FLOW_SelectPhase,heap);
    *(void **)(p+0xc)=func_0217E00C(*(int *)(p+0x1b8),heap);
    *(void ***)(p+0x1c)=func_021E7D20((void *)WIFIBATTLEMATCH_GRAPHIC_GetCamera(*(int **)(p+0x1b4)),*(void **)(p+0x1b0),heap);
    func_021E7E0C(*(void ***)(p+0x1c),0);
    *(void **)(p+0x38)=REGULATION_GetCard(BATTLE_COMPETITION_GetFromSave(GAME_DATA_GetSaveControl(*(void **)(p+0x1b8))),1);
    *(void **)(p+0x34)=(void *)MISC_SAVEDATA_GetRecordBase((int)MISC_SAVEDATA_GetBlock3C(GAME_DATA_GetSaveControl(*(void **)(p+0x1b8))));
    *(void **)(p+0x30)=POKEPARTY_Create(heap);
    if(*(int *)(p+0x1a0)==0)UI_SetFlags39Global(8);
    return p;
}

void LIVEBATTLEMATCH_FLOW_Delete(int *p)
{
    func_020307B0((void *)p[12]);
    if (p[0x67] == 1) UI_ClearFlags39Global(8);
    func_0217D174(p);
    func_0217D224(p);
    func_021E7DF0((int *)p[7]);
    func_0217E058((int *)p[3]);
    BTLV_CORE_IsSlotKind1Index15((int)((void *)p[0]));
    GF_FONT_Delete((void *)p[10]);
    MSGDATA_Delete((struct Rec *)p[9]);
    MSGDATA_Delete((struct Rec *)p[8]);
    WORDSET_DeleteStrbufED04((struct WordSet *)p[11]);
    func_020307B0(p);
}

void LIVEBATTLEMATCH_FLOW_Release(int *p)
{
    func_021E8A80((FlowCallback *)p[0]);
    func_0217E074(p[3]);
    func_021E7E08(p[7]);
    if (p[4]) func_021E64C0((unsigned char *)p[4], (void *)p[0x6B]);
    if (p[5]) func_021E7774((void *)p[5], (void *)p[0x6B]);
    if (p[6]) func_021E84F8((char *)p[6], (void *)p[0x6B]);
}

int LIVEBATTLEMATCH_FLOW_GetResult(int *p)
{
    if (func_021E8A90((int **)(((struct Obj14362 *)p)->f0)))
        return ((struct Obj14362 *)p)->f19C;
    return 0;
}

void LIVEBATTLEMATCH_FLOW_SelectPhase(int p,int *state,char *q)
{
    switch(((struct Obj14363 *)q)->f1A0) {
    case 0: func_021E8AA0((int *)p,(int)LIVEBATTLEMATCH_FLOW_Main); break;
    case 1:
        if(REGULATION_Card_GetValue((struct Reg2 *)(((struct Obj14363 *)q)->f38),10)==3) func_021E8AA0((int *)p,(int)LIVEBATTLEMATCH_FLOW_Sub);
        else func_021E8AA0((int *)p,(int)LIVEBATTLEMATCH_FLOW_Battle);
        break;
    case 2: func_021E8AA0((int *)p,(int)LIVEBATTLEMATCH_FLOW_Card); break;
    case 3: func_021E8AA0((int *)p,(int)LIVEBATTLEMATCH_FLOW_Sub); break;
    default: func_02034714(d_0217E618,0,d_0217E618); break;
    }
}

void LIVEBATTLEMATCH_FLOW_End(int p) {func_021E8AA8(p);}

void LIVEBATTLEMATCH_FLOW_Main(int *sys,u32_0217BBDC *state,u8 *p)
{
    switch(*state){
    case 0:
        switch(REGULATION_Card_GetValue(((struct Obj00053 *)p)->f38,10)){
        case 0:case 3:case 4:case 5:
            if(REGULATION_Card_GetValue(((struct Obj00053 *)p)->f38,2)==0)*state=12;else *state=1;break;
        case 1:func_021E8AA0(sys,(int)LIVEBATTLEMATCH_FLOW_Confirm);break;
        case 2:func_021E8AA0(sys,(int)LIVEBATTLEMATCH_FLOW_Battle);break;
        }break;
    case 1:func_0217D028(p);func_0217D1A0(p,1);*state=2;break;
    case 2:if(func_0217D188(p))*state=3;break;
    case 3:if(BATTLE_BOX_IsLocked(BATTLE_BOX_GetFromSave(GAME_DATA_GetSaveControl(((struct Obj00053 *)p)->f1B8)),2))*state=5;else *state=4;break;
    case 4:func_0217CFE8(p,0,1);*state=31;func_021E8AB4((u32_0217BBDC)sys,6);break;
    case 5:func_0217CFE8(p,1,1);*state=31;func_021E8AB4((u32_0217BBDC)sys,6);break;
    case 6:LIVEBATTLEMATCH_FLOW_DrawMenu(p,0);*state=7;break;
    case 7:{
        int v=LIVEBATTLEMATCH_FLOW_GetWindowResult((int *)p);
        if(v!=-1){LIVEBATTLEMATCH_FLOW_HideWindow((int *)p);switch(v){case 0:*state=8;break;case 1:*state=10;break;}}break;
    }
    case 8:if(func_0217D194((int *)p))*state=9;break;
    case 9:func_0217D174((int *)p);*state=12;break;
    case 10:if(func_0217D194((int *)p))*state=11;break;
    case 11:func_0217D174((int *)p);func_0217D010(p,1);break;
    case 12:func_0217CFE8(p,2,1);*state=31;func_021E8AB4((u32_0217BBDC)sys,13);break;
    case 13:func_021E7E0C(*(void ** *)&((struct Obj00053 *)p)->f1C,1);func_0217CFE8(p,32,0);*state=31;func_021E8AB4((u32_0217BBDC)sys,14);break;
    case 14:func_0217E318(*(char * *)&((struct Obj00053 *)p)->fC,(u32_0217BBDC)(p+0x3c));*state=15;break;
    case 15:{
        int v=func_0217E380(*(char * *)&((struct Obj00053 *)p)->fC);
        if(v){func_021E7E0C(*(void ** *)&((struct Obj00053 *)p)->f1C,0);if(v==1)*state=21;else *state=26;}
        if(func_0217E078(((struct Obj00053 *)p)->fC)==1){func_021E7E0C(*(void ** *)&((struct Obj00053 *)p)->f1C,0);*state=12;}
        else if(KEY_GetTrg()&2)*state=16;
        break;
    }
    case 16:func_0217E40C(*(int * *)&((struct Obj00053 *)p)->fC);*state=17;break;
    case 17:if(func_0217E414(*(char * *)&((struct Obj00053 *)p)->fC))*state=18;break;
    case 18:func_021E7E0C(*(void ** *)&((struct Obj00053 *)p)->f1C,0);func_0217CFE8(p,21,1);*state=31;func_021E8AB4((u32_0217BBDC)sys,19);break;
    case 19:LIVEBATTLEMATCH_FLOW_DrawMenu(p,0);*state=20;break;
    case 20:{
        int v=LIVEBATTLEMATCH_FLOW_GetWindowResult((int *)p);
        if(v!=-1){LIVEBATTLEMATCH_FLOW_HideWindow((int *)p);switch(v){case 0:*state=30;break;case 1:*state=12;break;}}break;
    }
    case 21:
        if(REGULATION_Card_IsCrcValid((struct Reg2 *)(p+0x3c))){
            unsigned a=REGULATION_Card_GetValue((struct Reg2 *)(p+0x3c),1);
            if(a&0x200000){
                unsigned a=REGULATION_Card_GetValue(((struct Obj00053 *)p)->f38,2);
                unsigned b=REGULATION_Card_GetValue((struct Reg2 *)(p+0x3c),2);
                if(a==b){
                    switch(REGULATION_Card_GetValue(((struct Obj00053 *)p)->f38,10)){
                    case 4:*state=27;break;
                    case 3:*state=28;break;
                    default:*state=22;break;
                    }
                }else *state=22;
            }else *state=26;
        }else *state=25;
        break;
    case 22:BATTLE_REC_ClearWork();func_0217CFE8(p,10,2);*state=31;func_021E8AB4((u32_0217BBDC)sys,23);break;
    case 23:{
        void *base=BATTLE_COMPETITION_GetFromSave(GAME_DATA_GetSaveControl(((struct Obj00053 *)p)->f1B8));
        void *entry=REGULATION_GetParty(base,1);
        REGULATION_Card_SetValue((struct Reg2 *)(p+0x3c),10,1);
        func_0200E904(((struct Obj00053 *)p)->f34);
        REGULATION_InitParty(entry);
        REGULATION_SetCard(base,1,(const struct RegulationCard *)(p+0x3c));
        GAME_DATA_SaveStart(*(int *)&((struct Obj00053 *)p)->f1B8);*state=24;break;
    }
    case 24:if(GAME_DATA_SaveMain(*(u8 * *)&((struct Obj00053 *)p)->f1B8)==2)*state=29;break;
    case 25:func_0217CFE8(p,26,1);*state=31;func_021E8AB4((u32_0217BBDC)sys,30);break;
    case 26:func_0217CFE8(p,27,1);*state=31;func_021E8AB4((u32_0217BBDC)sys,30);break;
    case 27:func_0217CFE8(p,3,1);*state=31;func_021E8AB4((u32_0217BBDC)sys,30);break;
    case 28:func_0217CFE8(p,4,1);*state=31;func_021E8AB4((u32_0217BBDC)sys,30);break;
    case 29:func_021E8AA0(sys,(int)LIVEBATTLEMATCH_FLOW_Confirm);break;
    case 30:func_0217D010(p,1);break;
    case 31:if(func_0217D000(p))func_021E8AB8((u32_0217BBDC)sys);break;
    }
}

void LIVEBATTLEMATCH_FLOW_Confirm(int *sys,u32_0217BFF8 *state,u8 *p)
{
    switch(*state){
    case 0:func_0217D028(p);func_0217D1A0(p,2);func_0217D244((char *)p);*state=1;break;
    case 1:{
        int flag=1;
        flag&=func_0217D188(p);
        flag&=func_0217D2A4(p);
        if(flag)*state=2;break;
    }
    case 2:func_0217CFE8(p,5,1);*state=21;func_021E8AB4((u32_0217BFF8)sys,3);break;
    case 3:LIVEBATTLEMATCH_FLOW_DrawMenu(p,0);*state=4;break;
    case 4:{
        int v=LIVEBATTLEMATCH_FLOW_GetWindowResult((int *)p);
        if(v!=-1){LIVEBATTLEMATCH_FLOW_HideWindow((int *)p);switch(v){case 0:*state=8;break;case 1:*state=5;break;}}break;
    }
    case 5:func_0217CFE8(p,8,1);*state=21;func_021E8AB4((u32_0217BFF8)sys,6);break;
    case 6:LIVEBATTLEMATCH_FLOW_DrawMenu(p,0);*state=7;break;
    case 7:{
        int v=LIVEBATTLEMATCH_FLOW_GetWindowResult((int *)p);
        if(v!=-1){LIVEBATTLEMATCH_FLOW_HideWindow((int *)p);switch(v){case 0:*state=19;break;case 1:*state=2;break;}}break;
    }
    case 8:if(func_0217D2B0(p)){func_0217D290(p);*state=9;}break;
    case 9:{
        u32_0217BFF8 mask=0;
        void *v=REGULATION_NoOp(((struct Obj00053 *)p)->f38);
        func_0217D2BC(p,((struct Obj00053 *)p)->f30);
        if(POKEPARTY_GetBattleReadyCount(((struct Obj00053 *)p)->f30)==0)*state=11;
        else if(POKE_REGULATION_CheckParty(v,((struct Obj00053 *)p)->f30,&mask)==0)*state=13;
        else *state=10;
        break;
    }
    case 10:func_0217CFE8(p,9,1);*state=21;func_021E8AB4((u32_0217BFF8)sys,12);break;
    case 11:func_0217CFE8(p,37,1);*state=21;func_021E8AB4((u32_0217BFF8)sys,12);break;
    case 12:if(func_0217D194((int *)p)){func_0217D174((int *)p);*state=20;}break;
    case 13:{
        void *base=GAME_DATA_GetSaveControl(((struct Obj00053 *)p)->f1B8);
        void *rules=BATTLE_BOX_GetFromSave(base);
        void *entry=REGULATION_GetParty(BATTLE_COMPETITION_GetFromSave(base),1);
        void *tmp=func_0200BAF4((int)rules,0x8056);
        BATTLE_BOX_SetLockFlags(rules,2);
        REGULATION_Card_SetValue(((struct Obj00053 *)p)->f38,10,2);
        REGULATION_BuildParty((int)entry,(int)tmp);
        func_020307B0(tmp);
        *state=14;break;
    }
    case 14:func_0217CFE8(p,10,2);*state=21;func_021E8AB4((u32_0217BFF8)sys,15);break;
    case 15:GAME_DATA_SaveStart(*(int *)&((struct Obj00053 *)p)->f1B8);*state=16;break;
    case 16:if(GAME_DATA_SaveMain(*(u8 * *)&((struct Obj00053 *)p)->f1B8)==2)*state=17;break;
    case 17:func_0217D1A0(p,0);func_0217CFE8(p,11,1);*state=21;func_021E8AB4((u32_0217BFF8)sys,18);break;
    case 18:func_021E8AA0(sys,(int)LIVEBATTLEMATCH_FLOW_Battle);break;
    case 19:{
        int flag=1;
        flag&=func_0217D194((int *)p);
        flag&=func_0217D2B0(p);
        if(flag){func_0217D174((int *)p);func_0217D290(p);*state=20;}break;
    }
    case 20:func_0217D010(p,1);break;
    case 21:if(func_0217D000(p))func_021E8AB8((u32_0217BFF8)sys);break;
    }
}

void LIVEBATTLEMATCH_FLOW_Battle(int *sys,u32_0217C2EC *state,u8 *p)
{
    switch(*state){
    case 0:func_0217D2F0(*(u8 * *)&((struct Obj00053 *)p)->f1BC,p);if(*(int *)&((struct Obj00053 *)p)->f10)*state=4;else{func_0217D028(p);func_0217D1A0(p,0);*state=1;}break;
    case 1:if(func_0217D188(p))*state=2;break;
    case 2:if(((struct Obj24408 *)(*(u8 * *)&((struct Obj00053 *)p)->f1C4))->fC)*state=3;else *state=4;break;
    case 3:func_0217CFE8(p,39,1);*state=25;func_021E8AB4((u32_0217C2EC)sys,4);break;
    case 4:{
        void *v=REGULATION_NoOp(((struct Obj00053 *)p)->f38);
        unsigned sel=func_0200E918(*(u8 * *)&((struct Obj00053 *)p)->f34,0);
        if(sel>=REGULATION_GetRuleValue(v,22))func_021E8AA0(sys,(int)LIVEBATTLEMATCH_FLOW_Sub);else *state=5;break;
    }
    case 5:func_0217CFE8(p,12,1);*state=25;func_021E8AB4((u32_0217C2EC)sys,6);break;
    case 6:LIVEBATTLEMATCH_FLOW_DrawMenu(p,1);*state=7;break;
    case 7:{
        int v=LIVEBATTLEMATCH_FLOW_GetWindowResult((int *)p);
        if(v!=-1){LIVEBATTLEMATCH_FLOW_HideWindow((int *)p);
            if(((struct Obj00053 *)p)->f1D0&&((struct Obj24409 *)(*(u8 * *)&((struct Obj00053 *)p)->f1C4))->fC==0){
                switch(v){case 0:*state=23;break;case 1:*state=19;break;case 2:*state=8;break;}
            }else switch(v){case 0:*state=23;break;case 1:*state=8;break;}
        }break;
    }
    case 8:func_0217CFE8(p,17,1);*state=25;func_021E8AB4((u32_0217C2EC)sys,9);break;
    case 9:LIVEBATTLEMATCH_FLOW_DrawMenu(p,3);*state=10;break;
    case 10:{
        int v=LIVEBATTLEMATCH_FLOW_GetWindowResult((int *)p);
        if(v!=-1){LIVEBATTLEMATCH_FLOW_HideWindow((int *)p);switch(v){case 0:*state=11;break;case 1:*state=5;break;}}break;
    }
    case 11:func_0217CFE8(p,18,1);*state=25;func_021E8AB4((u32_0217C2EC)sys,12);break;
    case 12:LIVEBATTLEMATCH_FLOW_DrawMenu(p,3);*state=13;break;
    case 13:{
        int v=LIVEBATTLEMATCH_FLOW_GetWindowResult((int *)p);
        if(v!=-1){LIVEBATTLEMATCH_FLOW_HideWindow((int *)p);switch(v){case 0:*state=14;break;case 1:*state=5;break;}}break;
    }
    case 14:func_0217CFE8(p,10,2);*state=25;func_021E8AB4((u32_0217C2EC)sys,15);break;
    case 15:REGULATION_Card_SetValue(((struct Obj00053 *)p)->f38,10,4);BATTLE_BOX_ClearLockFlags(BATTLE_BOX_GetFromSave(GAME_DATA_GetSaveControl(((struct Obj00053 *)p)->f1B8)),2);GAME_DATA_SaveStart(*(int *)&((struct Obj00053 *)p)->f1B8);*state=16;break;
    case 16:switch((u32_0217C2EC)GAME_DATA_SaveMain(*(u8 * *)&((struct Obj00053 *)p)->f1B8)){case 2:case 3:*state=17;break;case 0:case 1:break;}break;
    case 17:func_0217D1A0(p,1);func_0217CFE8(p,19,1);*state=25;func_021E8AB4((u32_0217C2EC)sys,18);break;
    case 18:if(func_0217D194((int *)p)){func_0217D174((int *)p);*state=24;}break;
    case 19:if(BATTLE_REC_IsVersionSupported((u8)(((struct Obj24410 *)(*(u8 * *)&((struct Obj00053 *)p)->f1C0))->f44)))*state=20;else *state=21;break;
    case 20:func_0217CFE8(p,16,1);*state=25;func_021E8AB4((u32_0217C2EC)sys,22);break;
    case 21:func_0217CFE8(p,34,1);*state=25;func_021E8AB4((u32_0217C2EC)sys,5);break;
    case 22:func_0217D010(p,4);break;
    case 23:func_021E8AA0(sys,(int)LIVEBATTLEMATCH_FLOW_Result);break;
    case 24:func_0217D010(p,1);break;
    case 25:if(func_0217D000(p))func_021E8AB8((u32_0217C2EC)sys);break;
    }
}

/*
 * prototypes: E1FC and E2C0 return r0 consumed by the original although their own C returns void.
 */
void LIVEBATTLEMATCH_FLOW_Result(int *sys,u32_0217C628 *state,u8 *p)
{
    if(func_0217E078(((struct Obj00241 *)p)->fC)==1){
        ((struct Obj24411 *)(*(u8 * *)&((struct Obj00241 *)p)->f1C4))->fC=1;
        func_021E8AA0(sys,(int)LIVEBATTLEMATCH_FLOW_Battle);
    }
    switch(*state){
    case 0:func_0217CFE8(p,20,1);*state=40;func_021E8AB4((u32_0217C628)sys,1);break;
    case 1:func_0217CFE8(p,33,0);func_021E7E0C(*(void ** *)&((struct Obj00241 *)p)->f1C,1);GFL_USE_PlaySeDefaultVolume(0x80d);((struct Obj00241 *)p)->f1D4=0;((struct Obj00241 *)p)->f1D8=0;*state=40;func_021E8AB4((u32_0217C628)sys,2);break;
    case 2:if(func_0217E0A8(*(int * *)&((struct Obj00241 *)p)->fC))*state=3;break;
    case 3:switch(func_0217E0B0(*(unsigned * *)&((struct Obj00241 *)p)->fC)){case 1:*state=13;break;case 2:*state=9;break;}if(KEY_GetTrg()&2)*state=4;break;
    case 4:func_0217E158(*(unsigned * *)&((struct Obj00241 *)p)->fC);*state=5;break;
    case 5:if(func_0217E178(*(int * *)&((struct Obj00241 *)p)->fC))*state=6;break;
    case 6:func_021E7E0C(*(void ** *)&((struct Obj00241 *)p)->f1C,0);func_0217CFE8(p,21,1);*state=40;func_021E8AB4((u32_0217C628)sys,7);break;
    case 7:LIVEBATTLEMATCH_FLOW_DrawMenu(p,0);*state=8;break;
    case 8:{
        int v=LIVEBATTLEMATCH_FLOW_GetWindowResult((int *)p);
        if(v!=-1){LIVEBATTLEMATCH_FLOW_HideWindow((int *)p);switch(v){
        case 0:func_021E7E0C(*(void ** *)&((struct Obj00241 *)p)->f1C,0);func_021E8AA0(sys,(int)LIVEBATTLEMATCH_FLOW_Battle);break;
        case 1:*state=1;break;
        }}break;
    }
    case 9:func_021E7E0C(*(void ** *)&((struct Obj00241 *)p)->f1C,0);func_0217E158(*(unsigned * *)&((struct Obj00241 *)p)->fC);*state=10;break;
    case 10:if(func_0217E178(*(int * *)&((struct Obj00241 *)p)->fC))*state=11;break;
    case 11:func_0217CFE8(p,28,1);*state=40;func_021E8AB4((u32_0217C628)sys,12);break;
    case 12:func_021E8AA0(sys,(int)LIVEBATTLEMATCH_FLOW_Battle);break;
    case 13:func_0217D388(*(int * *)&((struct Obj00241 *)p)->f1BC,(int *)p);if(func_0217E1FC(*(int *)&((struct Obj00241 *)p)->fC,*(int *)&((struct Obj00241 *)p)->f1BC))*state=14;break;
    case 14:{
        void *out;
        if(func_0217E23C(*(char * *)&((struct Obj00241 *)p)->fC,&out)){MI_CpuCopy8(out,((struct Obj00241 *)p)->f1C0,POKE_REGULATION_GetDataSize()+0xd4);*state=15;}break;
    }
    case 15:
        if(((struct Obj24412 *)(*(u8 * *)&((struct Obj00241 *)p)->f1BC))->f40==((struct Obj24413 *)(*(u8 * *)&((struct Obj00241 *)p)->f1C0))->f40){
            u32_0217C628 a=REGULATION_Card_GetValue(((struct Obj00241 *)p)->f38,12);
            int b=func_0200E994(((struct Obj00241 *)p)->f34,*(u8 * *)&((struct Obj00241 *)p)->f1C0+0x20);
            ((struct Obj00241 *)p)->f1D4=(a!=0||(a==0&&b==0));
            *state=16;
        }else{func_021E7E0C(*(void ** *)&((struct Obj00241 *)p)->f1C,0);GFL_USE_StopAllSe();*state=21;}
        break;
    case 16:GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),0x48,0x1f);*state=17;break;
    case 17:if(GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),0x48,0x1f))*state=18;break;
    case 18:if(func_0217E2C0((int)(((struct Obj00241 *)p)->fC),(int)((u32_0217C628 *)(p+0x1d4))))*state=19;break;
    case 19:if(func_0217E2F8(((struct Obj00241 *)p)->fC,(u32_0217C628 *)(p+0x1d8)))*state=20;break;
    case 20:
        func_021E7E0C(*(void ** *)&((struct Obj00241 *)p)->f1C,0);GFL_USE_StopAllSe();
        if(((struct Obj00241 *)p)->f1D8&&((struct Obj00241 *)p)->f1D4){GFL_USE_PlaySeDefaultVolume(0x63a);*state=27;}else *state=24;break;
    case 21:if(func_0217E1B8(*(int * *)&((struct Obj00241 *)p)->fC))*state=22;break;
    case 22:if(func_0217E1C0(*(int * *)&((struct Obj00241 *)p)->fC))*state=23;break;
    case 23:func_0217CFE8(p,22,1);*state=40;func_021E8AB4((u32_0217C628)sys,39);break;
    case 24:if(func_0217E1B8(*(int * *)&((struct Obj00241 *)p)->fC))*state=25;break;
    case 25:if(func_0217E1C0(*(int * *)&((struct Obj00241 *)p)->fC))*state=26;break;
    case 26:func_0217CFE8(p,36,1);*state=40;func_021E8AB4((u32_0217C628)sys,39);break;
    case 27:func_0217CFE8(p,23,1);*state=40;func_021E8AB4((u32_0217C628)sys,28);break;
    case 28:if((((struct Obj00241 *)p)->f1CC)++>120){((struct Obj00241 *)p)->f1CC=0;func_02040588(0,0);*state=29;}break;
    case 29:func_0217D1C8((char *)p,*(int *)&((struct Obj00241 *)p)->f1C0);*state=30;break;
    case 30:if(func_0217D238(p))*state=31;break;
    case 31:if((((struct Obj00241 *)p)->f1CC)++>300){((struct Obj00241 *)p)->f1CC=0;*state=32;}break;
    case 32:func_02040588(0,1);func_0217CFE8(p,24,1);*state=40;func_021E8AB4((u32_0217C628)sys,33);break;
    case 33:func_0217CFE8(p,35,2);*state=40;func_021E8AB4((u32_0217C628)sys,34);break;
    case 34:GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),0x47,0x1f);*state=35;break;
    case 35:if(GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),0x47,0x1f))*state=36;break;
    case 36:func_02040588(0,1);func_0217CFE8(p,38,2);*state=40;func_021E8AB4((u32_0217C628)sys,37);break;
    case 37:
        if((((struct Obj00241 *)p)->f1CC)++>60){
            void *v=REGULATION_NoOp(((struct Obj00241 *)p)->f38);
            ((struct Obj00241 *)p)->f1CC=0;REGULATION_GetRuleValue(v,19);*state=38;
        }break;
    case 38:func_0217D010(p,2);break;
    case 39:func_021E8AA0(sys,(int)LIVEBATTLEMATCH_FLOW_Battle);break;
    case 40:if(func_0217D000(p))func_021E8AB8((u32_0217C628)sys);break;
    }
}

void LIVEBATTLEMATCH_FLOW_Card(int *sys,u32_0217CAE0 *state,u8 *p)
{
    if(func_0217E078(((struct Obj01271 *)p)->fC)==1){
        ((struct Obj24414 *)(*(u8 * *)&((struct Obj01271 *)p)->f1C4))->fC=1;
        func_021E8AA0(sys,(int)LIVEBATTLEMATCH_FLOW_Battle);
    }
    switch(*state){
    case 0:{
        void *v=MISC_SAVEDATA_GetBlock44(GAME_DATA_GetSaveControl(((struct Obj01271 *)p)->f1B8));
        MISC_SAVEDATA_InsertRecentValue(v,func_02008530(((struct Obj01271 *)p)->f1C0));
        *state=1;break;
    }
    case 1:if(func_0217E1B8(*(int * *)&((struct Obj01271 *)p)->fC)) *state=2;break;
    case 2:if(func_0217E1C0(*(int * *)&((struct Obj01271 *)p)->fC)) *state=3;break;
    case 3:{
        int a=0;
        int b;
        u8 index=(u32_0217CAE0)func_0200E918(*(u8 * *)&((struct Obj01271 *)p)->f34,0);
        func_0200E958(*(u8 * *)&((struct Obj01271 *)p)->f34,index,*(u8 * *)&((struct Obj01271 *)p)->f1C0+0x20);
        func_0200E978(*(u8 * *)&((struct Obj01271 *)p)->f34,index,0,(*(u8 **)(p+0x1c4))[8]);
        func_0200E978(*(u8 * *)&((struct Obj01271 *)p)->f34,index,1,(*(u8 **)(p+0x1c4))[9]);
        b=0;
        switch(**(u32_0217CAE0 * *)&((struct Obj01271 *)p)->f1C4){
        case 1:case 4:a=1;break;
        case 0:case 3:b=1;break;
        case 2:break;
        default:func_02034714(d_0217E618,0,d_0217E618);break;
        }
        func_0200E920(*(u8 * *)&((struct Obj01271 *)p)->f34,1,a);
        func_0200E920(*(u8 * *)&((struct Obj01271 *)p)->f34,2,b);
        func_0200E920(*(u8 * *)&((struct Obj01271 *)p)->f34,0,1);
        func_0217D160((int *)p);
        *state=4;break;
    }
    case 4:func_0217CFE8(p,10,2);*state=8;func_021E8AB4((u32_0217CAE0)sys,5);break;
    case 5:GAME_DATA_SaveStart(*(int *)&((struct Obj01271 *)p)->f1B8);*state=6;break;
    case 6:if(GAME_DATA_SaveMain(*(u8 * *)&((struct Obj01271 *)p)->f1B8)==2)*state=7;break;
    case 7:func_0217D010(p,3);break;
    case 8:if(func_0217D000(p))func_021E8AB8((u32_0217CAE0)sys);break;
    }
}

/*
 * ABI: 0200AE14 leaves supplied pointer in r0 despite its void own declaration.
 */
void LIVEBATTLEMATCH_FLOW_Sub(int *a, int *state, u8 *p)
{
    void *record;
    u32_0217CC78 value;
    int result;
    switch (*state) {
    case 0:
        func_0217D160((int *)p);
        if (REGULATION_Card_GetValue(((struct Obj00053 *)p)->f38, 10) == 3) *state = 6;
        else *state = 1;
        break;
    case 1:
        record = REGULATION_NoOp(((struct Obj00053 *)p)->f38);
        value = func_0200E918(*(u8 * *)&((struct Obj00053 *)p)->f34, 0);
        if (value >= REGULATION_GetRuleValue(record, 0x16)) *state = 2;
        else *state = 16;
        break;
    case 2: func_0217CFE8(p, 10, 2); *state = 17; func_021E8AB4((u32_0217CC78)a, 3); break;
    case 3:
        REGULATION_Card_SetValue(((struct Obj00053 *)p)->f38, 10, 3);
        BATTLE_BOX_ClearLockFlags(BATTLE_BOX_GetFromSave(GAME_DATA_GetSaveControl(((struct Obj00053 *)p)->f1B8)), 2);
        GAME_DATA_SaveStart((int)(((struct Obj00053 *)p)->f1B8)); *state = 4; break;
    case 4:
        switch (GAME_DATA_SaveMain(((struct Obj00053 *)p)->f1B8)) {
        case 0: case 1: break;
        case 2: case 3: *state = 5; break;
        }
        break;
    case 5: func_0217D1A0(p, 1); func_0217CFE8(p, 25, 1); *state = 17; func_021E8AB4((u32_0217CC78)a, 6); break;
    case 6: func_0217CFE8(p, 29, 1); *state = 17; func_021E8AB4((u32_0217CC78)a, 7); break;
    case 7: LIVEBATTLEMATCH_FLOW_DrawMenu(p, 2); *state = 8; break;
    case 8:
        result = LIVEBATTLEMATCH_FLOW_GetWindowResult((int *)p);
        if (result != -1) {
            LIVEBATTLEMATCH_FLOW_HideWindow((int *)p);
            if (((struct Obj00053 *)p)->f1D0 && ((struct Obj24416 *)(*(u8 * *)&((struct Obj00053 *)p)->f1C4))->fC == 0) {
                switch (result) { case 0: *state = 11; break; case 1: *state = 9; break; }
            } else if (result == 0) *state = 9;
        }
        break;
    case 9: func_0217CFE8(p, 31, 1); *state = 17; func_021E8AB4((u32_0217CC78)a, 10); break;
    case 10: if (func_0217D194((int *)p)) { func_0217D174((int *)p); *state = 15; } break;
    case 11:
        if (BATTLE_REC_IsVersionSupported((u8)(((struct Obj24417 *)(*(u8 * *)&((struct Obj00053 *)p)->f1C0))->f44))) *state = 12;
        else *state = 13;
        break;
    case 12: func_0217CFE8(p, 16, 1); *state = 17; func_021E8AB4((u32_0217CC78)a, 14); break;
    case 13: func_0217CFE8(p, 34, 1); *state = 17; func_021E8AB4((u32_0217CC78)a, 6); break;
    case 14: func_0217D010(p, 4); break;
    case 15: func_0217D010(p, 1); break;
    case 16: func_021E8AA0(a, (int)LIVEBATTLEMATCH_FLOW_Battle); break;
    case 17: if (func_0217D000(p)) func_021E8AB8((u32_0217CC78)a); break;
    }
}

/*
 * function_starts: 0217CFD0,0217CFDC
 * ABI: coordinates are byte locals; X/width/height externs are widened because original has no call-site narrowing.
 */
void LIVEBATTLEMATCH_FLOW_DrawMenu(u8 *p, int mode)
{
    Menu_0217B970 rec;
    int layout;
    u8 x, y, width, height;
    MI_CpuFill8(&rec, 0, 0x30);
    rec.f00 = ((struct Obj00053 *)p)->f20;
    rec.f04 = *(u32_0217CEAC *)&((struct Obj00053 *)p)->f1A8;
    rec.f08 = *(u32_0217CEAC *)&((struct Obj00053 *)p)->f1AC;
    switch (mode) {
    case 3: rec.f2e = 1;
    case 0:
        rec.option0 = 6; rec.option1 = 7; rec.count = 2; rec.f28 = 1; rec.f2c = 1; layout = 1; break;
    case 1:
        rec.f28 = 0;
        if (((struct Obj00053 *)p)->f1D0 && ((struct Obj24418 *)(*(u8 * *)&((struct Obj00053 *)p)->f1C4))->fC == 0) {
            rec.option0 = 13; rec.option1 = 14; rec.option2 = 15; rec.count = 3;
        } else { rec.option0 = 13; rec.option1 = 15; rec.count = 2; }
        layout = 0; break;
    case 2:
        rec.f28 = 0;
        if (((struct Obj00053 *)p)->f1D0 && ((struct Obj24419 *)(*(u8 * *)&((struct Obj00053 *)p)->f1C4))->fC == 0) {
            rec.option0 = 14; rec.option1 = 30; rec.count = 2;
        } else { rec.option0 = 30; rec.count = 1; }
        layout = 0; break;
    }
    rec.f20 = 0; rec.f22 = 15; rec.f24 = 13; rec.f26 = 1;
    switch (layout) {
    case 0: width = 28; height = rec.count * 2; x = 2; y = 9 - height / 2; break;
    case 1: width = 12; height = rec.count * 2; x = 19; y = 17 - height; break;
    }
    ((struct Obj00053 *)p)->f4 = func_021E88B0((Desc *)&rec, x, y, width, height, ((struct Obj00053 *)p)->f1C8);
    ((struct Obj00053 *)p)->f8 = mode;
}

void LIVEBATTLEMATCH_FLOW_HideWindow(int *p) { func_021E89D0((void *)p[1]); }

int LIVEBATTLEMATCH_FLOW_GetWindowResult(int *p) { return func_021E8A00((void *)p[1]); }

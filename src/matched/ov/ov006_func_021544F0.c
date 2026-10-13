/*
 * function: EVENT_WIFICLUB_Main
 * address: 0x021544F0
 * packet: pkt_ov006_021544F0
 * region: ov006
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * blockers: code-start witnesses for ov006 EVENT_WIFICLUB_SetBattleParty and ov099
 * WIFICLUB_RunPeerAddrRoutine; overlay-ID consumer evidence for GAME_EVENT_CallProc:r1
 * (IDs 127,134,8,119,195,172). All concrete bytes match.
 * Matching levers: typed Sel table folds the u16 field offset into its
 * pool word; Pair struct copies to SP; char-pointer field addressing
 * avoids loop spills; repeated cleanup tails preserve cross-jumped hops.
 * checks: 1 callees and PC-relative IDs rederived; 2 no matching twin;
 * 3 const 02031330 and unsigned counter worsened; 4 repeated cleanup
 * tails closed branch residue; 5 idioms relisted and neighbours reread.
 * TU --suggest-split: one section, no viable cut; tool consumer correction
 * needed before filing the two overlay leaves. No ARM9 blocker remains.
 * Prototype evidence: 02031324 and 02031348 forward all registers to
 * 02031354(int) and 020314F4(obj,u32,u32,u32); 0200F7B8 receives the
 * explicitly loaded zero despite its legacy void declaration.
 * 2026-10-04 note (wave D2 lane 15): still MATCH, bytes identical. Unresolved after re-run:
 * THM_CALL WIFICLUB_RunPeerAddrRoutine (ov099 hint present, but 021C2850 is a Thumb veneer in ov099, 64 bytes
 * incl. data, no matched witness exists) and six single-use overlay-id words (ov008 0x8,
 * ov119 0x77, ov127 0x7f, ov134 0x86, ov172 0xac, ov195 0xc3) with no witness outside this
 * function. Nothing left to change in the C.
 * 2026-10-05 note (D4-14): re-run, still MATCH (1484 bytes, 111 of 112 relocations resolve; the open one is WIFICLUB_RunPeerAddrRoutine, a Thumb veneer in ov099). No change possible in C.
 *
 * symbols:
 *   func_02012138 0x02012138 thumb
 *   GAME_COMM_GetKind 0x02026454 thumb
 *   FIELD_STATUS_CreateFieldCloseEvent 0x020144DC thumb
 *   GAME_EVENT_CallEvent 0x02012374 thumb
 *   RINGTONE_SYS_RegisterSleepCallbacks 0x02029F6C thumb
 *   FIELD_STATUS_CreateFieldOpenEvent 0x020145CC thumb
 *   func_020120F4 0x020120F4 thumb
 *   func_0201283C 0x0201283C thumb
 *   BTL_SETUP_Delete 0x020130B4 thumb
 *   BTL_SETUP_Create 0x02013090 thumb
 *   GAME_EVENT_CallProc 0x02012444 thumb
 *   func_02012950 0x02012950 thumb
 *   GAME_DATA_GetTrainerRecord 0x02012F2C thumb
 *   ov008_id 0x8 data a1
 *   ov067_id 0x43 data a1
 *   ov127_id 0x7f data a1
 *   ov115_id 0x73 data a1
 *   ov099_id 0x63 data a1
 *   ov134_id 0x86 data a1
 *   ov093_id 0x5d data a1
 *   ov119_id 0x77 data a1
 *   ov195_id 0xc3 data a1
 *   ov172_id 0xac data a1
 *   GFL_NET_IsSessionNull 0x0203CDBC arm
 *   MI_CpuFill8 0x02082BCC arm
 *   PROCSYS_Create 0x02031324 arm
 *   PROCSYS_Push 0x02031348 arm
 *   PROCSYS_Main 0x02031330 arm
 *   func_0203133C 0x0203133C arm
 *   func_02034AC4 0x02034AC4 arm
 *   func_02034A5C 0x02034A5C arm
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_COMMAND_AddCommandTable 0x0203A574 arm
 *   GFL_NET_HANDLE_SetTimingSyncRange 0x02039C68 arm
 *   GFL_NET_HANDLE_IsTimingSyncRange 0x02039CB4 arm
 *   GFL_NET_GetRunState 0x0203CD98 arm
 *   GFL_NET_GetHandleNetID 0x0203D1A4 arm
 *   GFL_NET_COMMAND_DeleteCommandTable 0x0203A5E4 arm
 *   func_02030734 0x02030734 arm
 *   func_020307B0 0x020307B0 arm
 *   GFL_NET_Exit 0x0203CEAC arm
 *   GFL_NET_IsIdle 0x0203D210 arm
 *   EVENT_FIELDMAP_CONTROL_StartFadeIn 0x021BE92C thumb ov021
 *   EVENT_WIFICLUB_BuildBattleEntry 0x0215444C thumb ov006
 *   EVENT_WIFICLUB_SetBattleParty 0x021544BC thumb ov006
 *   EVENT_WIFICLUB_ResetSound 0x021544D4 thumb ov006
 *   EVENT_WIFICLUB_FreeWork 0x02154ABC thumb ov006
 *   EVENT_WIFICLUB_SetupBattle 0x021542C0 thumb ov006
 *   WIFICLUB_RunPeerAddrRoutine 0x021C2850 thumb ov099
 *   gNetSaveMainProc 0x021D6338 data ov115 a4
 *   gNetSaveRetryProc 0x021D654C data ov115 a4
 *   d_021C37E8 0x021C37E8 data ov099 a4
 *   d_02154C40 0x02154C40 data ov006 a2
 *   d_021DCCA4 0x021DCCA4 data ov134 a4
 *   d_021F03C4 0x021F03C4 data ov093 a4
 *   d_02154C2C 0x02154C2C data ov006 a1
 *   d_0215513C 0x0215513C data ov008 a4
 *   d_021E75C0 0x021E75C0 data ov119 a4
 *   d_02154C80 0x02154C80 data ov006 a4
 *   d_02208C40 0x02208C40 data ov195 a4
 *   d_021C7240 0x021C7240 data ov172 a4
 *   GFL_USE_SetSleepVolumeHooks  0x020057AC  thumb  arm9
 *   GFL_USE_GetBgmNo  0x02005C44  thumb  arm9
 *   GFL_USE_CancelChangeAndPlayBgm  0x02005D90  thumb  arm9
 *   GFL_USE_FadeInBgmFull  0x02005DF8  thumb  arm9
 *   GFL_USE_FadeOutBgm  0x02005E30  thumb  arm9
 *   PM_VOICE_ResetMasterVolume  0x02006740  thumb  arm9
 *   GFL_NET_ERR_ShowScreen  0x0200F7B8  thumb  arm9
 *   GFL_NET_ERR_ShowSimpleScreen  0x0200F83C  thumb  arm9
 */
/*
 * 2026-10-05 (wave D8 lane08): still MATCH, no C change. The open relocation WIFICLUB_RunPeerAddrRoutine (ov099) is NOT a veneer:
 *  it is a 12-byte Thumb tail call, `void WIFICLUB_RunPeerAddrRoutine(char *p) { OS_GetMacAddress(p + 0xe); }` with symbols line
 *  `OS_GetMacAddress 0x02087C6C arm`, verified EXACT in a scratch test. It is in ov099 (not arm9, not this overlay), so
 *  this lane did not file it. Filing src/matched/ov/ov099_func_021C2850.c (packet pkt_ov099_021C2850) closes this
 *  draft's last unresolved relocation.
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
#define W(p,k) (*(u32 *)((char *)(p)+(k)))
#define H(p,k) (*(u16 *)((char *)(p)+(k)))
#define B(p,k) (*(u8 *)((char *)(p)+(k)))
typedef struct {u32 pad00[5];u32 values[2];} Sub;
extern u16 GFL_USE_GetBgmNo(void);
extern void GFL_USE_FadeOutBgm(u32);
struct BigObj;
struct Ctx;
struct Entry;
struct Evt;
struct Link;
struct Obj;
struct Rec44;
struct S020314B8;
struct Sub020097BCObj;
struct Sub24;
extern u32 func_02012138(const struct Ctx *p);
extern u32 GAME_COMM_GetKind(void *);
extern int FIELD_STATUS_CreateFieldCloseEvent(int,int);
extern void *FIELD_STATUS_CreateFieldOpenEvent(void *);
extern void GAME_EVENT_CallEvent(struct Evt *evt, struct Evt **out);
extern void GFL_USE_SetSleepVolumeHooks(void);
extern int GFL_NET_IsSessionNull(void);
extern void RINGTONE_SYS_RegisterSleepCallbacks(void);
extern int EVENT_FIELDMAP_CONTROL_StartFadeIn(void *,int,int,int,int,u8,u8);
extern void MI_CpuFill8(void *,int,int);
extern void *func_020120F4(const struct Ctx *p);
extern void PM_VOICE_ResetMasterVolume(void);
extern void GFL_USE_CancelChangeAndPlayBgm(u32,u16);
extern void GFL_USE_FadeInBgmFull(u32);
extern void *PROCSYS_Create(int);
extern void PROCSYS_Push(void *,u32,u32,u32);
extern u32 PROCSYS_Main(void *);
extern void func_0203133C(struct S020314B8 *p);
extern u32 GFL_NET_ERR_ShowScreen(u32 a0);
extern u32 func_0201283C(const struct BigObj *p);
extern u32 func_02009A34(struct Sub020097BCObj *obj);
extern int func_02034AC4(int);
extern void func_02034A5C(int);
extern void WIFICLUB_RunPeerAddrRoutine(char *p);
extern int BTL_SETUP_Delete(int);
extern void GAME_EVENT_CallProc(struct Obj *obj, u32 a1, u32 a2, u32 a3);
extern void EVENT_WIFICLUB_BuildBattleEntry(char *,u32,int);
extern void *BTL_SETUP_Create(u32);
extern void EVENT_WIFICLUB_SetupBattle(char *,int);
extern void EVENT_WIFICLUB_SetBattleParty(char *,u32,int);
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern void GFL_NET_COMMAND_AddCommandTable(u32,u32,u32,u32);
extern void GFL_NET_HANDLE_SetTimingSyncRange(struct Link *p, u32 lo, u32 hi);
extern u32 GFL_NET_HANDLE_IsTimingSyncRange(struct Link *p, u32 lo, u32 hi);
extern int GFL_NET_GetRunState(void);
extern u32 func_0200FB24(void);
extern u32 func_0200FBB0(void);
extern void GFL_NET_ERR_ShowSimpleScreen(void);
extern u32 GFL_NET_GetHandleNetID(struct Link *p);
extern struct Rec44 *func_02012950(struct Sub24 *p, u32 i);
extern void *GAME_DATA_GetTrainerRecord(int *);
extern void func_02009BB8(struct Sub020097BCObj *obj, int i, int a, int b, int c);
extern void GFL_NET_COMMAND_DeleteCommandTable(u32);
extern void *func_02030734(u32,u32,int,const char *,u16);
extern u32 func_020307B0(void *p);
extern void EVENT_WIFICLUB_ResetSound(u8 *);
extern int GFL_NET_Exit(int);
extern u32 GFL_NET_IsIdle(void);
extern void EVENT_WIFICLUB_FreeWork(int *);
extern const char gNetSaveMainProc[],gNetSaveRetryProc[],d_021DCCA4[],d_021F03C4[],d_021C37E8[];
extern const char d_0215513C[],d_021E75C0[],d_02154C80[],d_02208C40[],d_021C7240[];
extern char ov008_id[],ov067_id[],ov127_id[],ov115_id[],ov099_id[];
extern char ov134_id[],ov093_id[],ov119_id[],ov195_id[],ov172_id[];
typedef struct {u8 a,b;} Pair;
extern const Pair d_02154C2C;
typedef struct {u8 val,pad;u16 state;} Sel;
extern const Sel d_02154C40[];

int EVENT_WIFICLUB_Main(void *evt,u32 *state,char *obj)
{
    void *p;
    u32 s;
    int i,off;
    Pair pair;
    char *r;
    p=(void *)W(obj,4);
    s=*state;
    switch(s) {
    case 0:
        H(obj,0x170)=GFL_USE_GetBgmNo();
        GFL_USE_FadeOutBgm(6);
        ++*state;
        break;
    case 1:
        if (!GAME_COMM_GetKind((void *)func_02012138(p))) {
            W(obj,0x10)=0;
            GAME_EVENT_CallEvent(evt,(void *)FIELD_STATUS_CreateFieldCloseEvent((int)p,W(obj,8)));
            ++*state;
        }
        break;
    case 2:
        GFL_USE_SetSleepVolumeHooks();
        *state=8;
        break;
    case 3: break;
    case 4:
        if (GFL_NET_IsSessionNull()) {
            ++*state;
            EVENT_WIFICLUB_FreeWork((int *)obj);
            PM_VOICE_ResetMasterVolume();
            GFL_USE_CancelChangeAndPlayBgm(H(obj,0x170),0xffff);
            GFL_USE_FadeInBgmFull(60);
        }
        break;
    case 5:
        RINGTONE_SYS_RegisterSleepCallbacks();
        GAME_EVENT_CallEvent(evt,FIELD_STATUS_CreateFieldOpenEvent(p));
        ++*state;
        break;
    case 6:
        if (W(obj,0x14))
            GAME_EVENT_CallEvent(evt,(void *)EVENT_FIELDMAP_CONTROL_StartFadeIn(p,W(obj,8),0,0,1,0,0));
        ++*state;
        break;
    case 7: return 1;
    case 8:
        MI_CpuFill8(obj+0x98,0,0x28);
        *state=9;
        W(obj,0xac)=0;
        break;
    case 9:
        W(obj,0x98)=(u32)func_020120F4(p);
        W(obj,0xa0)=1;
        W(obj,0x9c)=0;
        W(obj,0xa4)=10;
        W(obj,0xb0)=1;
        GFL_USE_CancelChangeAndPlayBgm(0x481,0xffff);
        W(obj,0x1c)=(u32)PROCSYS_Create(4);
        PROCSYS_Push((void *)W(obj,0x1c),(u32)ov115_id,(u32)gNetSaveMainProc,(u32)(obj+0x98));
        W(W(obj,0x5c),0xc)=0;
        *state=10;
        break;
    case 10:
        if (PROCSYS_Main((void *)W(obj,0x1c))) { GFL_NET_ERR_ShowScreen(0); return 0; }
        func_0203133C((void *)W(obj,0x1c));
        if (!W(obj,0xb4)) {
            if (!func_02009A34((void *)func_0201283C((void *)W(obj,0x90)))) *state=30;
            else { *state=11; GFL_USE_FadeOutBgm(6); }
        } else { GFL_USE_FadeOutBgm(6); *state=25; }
        break;
    case 30:
        W(obj,0xc0)=(u32)func_020120F4(p);
        W(obj,0xc8)=1;
        W(obj,0xc4)=0;
        W(obj,0xcc)=1;
        W(obj,0xd0)=0;
        W(obj,0xd4)=0;
        W(obj,0xd8)=0;
        W(obj,0x1c)=(u32)PROCSYS_Create(4);
        PROCSYS_Push((void *)W(obj,0x1c),(u32)ov115_id,(u32)gNetSaveRetryProc,(u32)(obj+0xc0));
        ++*state;
        break;
    case 31:
        if (PROCSYS_Main((void *)W(obj,0x1c))) { GFL_NET_ERR_ShowScreen(0); return 0; }
        func_0203133C((void *)W(obj,0x1c));
        GFL_USE_FadeOutBgm(6);
        *state=4;
        break;
    case 11:
        func_02034AC4((int)ov099_id);
        func_02034AC4((int)ov067_id);
        WIFICLUB_RunPeerAddrRoutine((char *)W(W(obj,0x5c),0));
        if (W(obj,0xdc)) { BTL_SETUP_Delete(W(obj,0xdc)); W(obj,0xdc)=0; }
        GAME_EVENT_CallProc((void *)W(obj,0),(u32)ov127_id,(u32)d_021C37E8,W(obj,0x5c));
        ++*state;
        break;
    case 12:
        *state=d_02154C40[W(W(obj,0x5c),0xc)].state;
        if (W(W(obj,0x5c),0xc)==1) W(obj,0xac)=1;
        B(obj,0x172)=d_02154C40[W(W(obj,0x5c),0xc)].val;
        func_02034A5C((int)ov067_id);
        func_02034A5C((int)ov099_id);
        break;
    case 13:
        EVENT_WIFICLUB_BuildBattleEntry(obj,(u32)func_020120F4(p),s);
        W(obj,0xdc)=(u32)BTL_SETUP_Create(4);
        EVENT_WIFICLUB_SetupBattle(obj,W(W(obj,0x5c),0xc));
        GAME_EVENT_CallProc((void *)W(obj,0),(u32)ov134_id,(u32)d_021DCCA4,(u32)(obj+0x20));
        ++*state;
        break;
    case 14:
        if (W(obj,0x48)==1) {
            if (GFL_NET_GetRunState()) {
                B(W(obj,0x5c),0x49)=0;
                *state=11;
            } else {
                EVENT_WIFICLUB_ResetSound((u8 *)obj);
                *state=9;
            }
        } else {
            EVENT_WIFICLUB_SetBattleParty(obj,(u32)func_020120F4(p),s);
            func_02034AC4((int)ov093_id);
            GFL_NET_COMMAND_AddCommandTable(0x100,(u32)d_021F03C4,9,0);
            GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),100,10);
            ++*state;
        }
        break;
    case 15:
        if (!GFL_NET_GetRunState() || func_0200FB24()) {
            func_0200FBB0(); GFL_NET_ERR_ShowSimpleScreen(); goto cleanup;
        }
        if (GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),100,10)) ++*state;
        break;
    case 16:
        GFL_USE_CancelChangeAndPlayBgm(0x490,0xffff);
        W(obj,0x124)=1;
        if (!GFL_NET_GetHandleNetID((struct Link *)GFL_NET_HANDLE_GetCurrentHandle())) {
            for (i=0;i<2;i++) {
                off=i<<4;
                W((u32)obj+off,0xe4)=(u32)func_02012950((void *)func_020120F4(p),i);
                W((u32)obj+off,0xe0)=((Sub *)W(obj,0x5c))->values[i];
            }
        } else {
            pair=d_02154C2C;
            for (i=0;i<2;i++) {
                off=((u8 *)&pair)[i]<<4;
                W((u32)obj+off,0xe4)=(u32)func_02012950((void *)func_020120F4(p),i);
                W((u32)obj+off,0xe0)=((Sub *)W(obj,0x5c))->values[i];
            }
        }
        W(obj,0x138)=(u32)func_020120F4((void *)W(obj,4));
        W(obj,0x13c)=W(obj,0xdc);
        W(obj,0x140)=(u32)(obj+0xe0);
        W(obj,0x14c)=1;
        W(obj,0x134)=(u32)GAME_DATA_GetTrainerRecord((int *)func_020120F4((void *)W(obj,4)));
        func_02034A5C((int)ov093_id);
        GAME_EVENT_CallProc((void *)W(obj,0),(u32)ov008_id,(u32)d_0215513C,(u32)(obj+0x138));
        ++*state;
        break;
    case 17:
        if (!GFL_NET_GetRunState()) goto cleanup;
        if (W(obj,0x120)==0)
            func_02009BB8((void *)func_0201283C((void *)func_020120F4((void *)W(obj,4))),B(W(obj,0x5c),0x47)-1,1,0,0);
        else if (W(obj,0x120)==1)
            func_02009BB8((void *)func_0201283C((void *)func_020120F4((void *)W(obj,4))),B(W(obj,0x5c),0x47)-1,0,1,0);
        GFL_NET_COMMAND_DeleteCommandTable(0x100);
        *state=11;
        break;
    case 18:
        W(obj,0x68)=0;
        H(obj,0x8c)=B(W(obj,0x5c),0x47);
        ++*state;
        break;
    case 19:
        W(obj,0x74)=(u32)func_020120F4(p);
        GAME_EVENT_CallProc((void *)W(obj,0),(u32)ov119_id,(u32)d_021E75C0,(u32)(obj+0x60));
        ++*state;
        break;
    case 20:
        switch(W(obj,0x68)) {
        case 1: *state=21; break;
        case 2: W(W(obj,0x5c),0xc)=1; *state=11; break;
        default: *state=11; break;
        }
        if (!GFL_NET_GetRunState()) {
            EVENT_WIFICLUB_ResetSound((u8 *)obj);
            *state=9;
        }
        break;
    case 21:
        r=func_02030734(4,0x14,0,d_02154C80,0x24b);
        W(r,0)=(u32)func_020120F4((void *)W(obj,4));
        W(r,4)=W(obj,0x7c);
        H(r,8)=W(obj,0x6c);
        B(r,0xa)=0;
        B(r,0xb)=W(obj,0x70);
        W(r,0xc)=1;
        W(r,0x10)=0;
        W(obj,0x80)=(u32)r;
        GAME_EVENT_CallProc((void *)W(obj,0),(u32)ov195_id,(u32)d_02208C40,(u32)r);
        *state=22;
        break;
    case 22:
        func_020307B0((void *)W(obj,0x80));
        W(obj,0x68)=1;
        *state=19;
        if (!GFL_NET_GetRunState()) {
            EVENT_WIFICLUB_ResetSound((u8 *)obj);
            *state=9;
        }
        break;
    case 23:
        W(obj,0x4c)=(u32)func_020120F4(p);
        W(obj,0x50)=3;
        GAME_EVENT_CallProc((void *)W(obj,0),(u32)ov172_id,(u32)d_021C7240,(u32)(obj+0x4c));
        ++*state;
        break;
    case 24:
        if (GFL_NET_GetRunState()) goto menu;
cleanup:
        EVENT_WIFICLUB_ResetSound((u8 *)obj);
        *state=9;
        break;
menu:
        *state=11;
        break;
    case 28: GFL_NET_Exit(0); *state=29; break;
    case 29: if (GFL_NET_IsIdle()) *state=4; break;
    case 25: case 26: case 27: *state=4; break;
    }
    return 0;
}

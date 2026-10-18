/*
 * function: WIFIBATTLEMATCH_NET_CompStepC
 * address: 0x021D6DB8
 * packet: pkt_ov175_021D6DB8
 * region: ov175
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note: The listing stops at the epilogue label 021D76B8; the full body
 *       ends at 021D76D4 after its epilogue and pools, followed by our
 *       separately matched WIFIBATTLEMATCH_NET_CompStepD.c.
 * lever: Enum context offset keeps 0x104 in r7; reload aux by literal 0x108.
 *        Distinct Request locals preserve the three eight-byte stack objects.
 *        The masked byte decrement is spelled as addition of 0xfc.
 * symbols:
 *   WIFIBATTLEMATCH_NET_CompStepD 0x021D76D4 thumb ov175
 *   WIFIBATTLEMATCH_NET_SetupCompRecord 0x021D965C thumb
 *   WIFIBATTLEMATCH_NET_StartTradeIconAnim 0x021D97E4 thumb
 *   WIFIBATTLEMATCH_NET_SetupCompCard 0x021D9874 thumb
 *   WIFIBATTLEMATCH_NET_IsTradeIconReady 0x021D97B8 thumb
 *   WIFIBATTLEMATCH_NET_IsRegSpriteReady 0x021D98CC thumb
 *   WIFIBATTLEMATCH_NET_SetupRegSprite 0x021D98E4 thumb
 *   WIFIBATTLEMATCH_NET_IsCompSpriteAnimDone 0x021D9A08 thumb
 *   WIFIBATTLEMATCH_NET_DeleteCompSprite 0x021D99F4 thumb
 *   WIFIBATTLEMATCH_NET_IsRegSpriteAnimDone 0x021D98D8 thumb
 *   WIFIBATTLEMATCH_NET_DeleteRegSprite 0x021D98B8 thumb
 *   WIFIBATTLEMATCH_NET_CopyCompBox 0x021D9A50 thumb
 *   POKEPARTY_GetBattleReadyCount 0x0201AA50 thumb
 *   REGULATION_NoOp 0x0200AE14 thumb
 *   POKE_REGULATION_CheckParty 0x0201A090 thumb
 *   WIFIBATTLEMATCH_NET_SetupPostData 0x021DCB58 thumb
 *   WIFIBATTLEMATCH_NET_HttpRapPost 0x021DCC28 thumb
 *   POKEPARTY_GetCount 0x0201AA18 thumb
 *   WIFIBATTLEMATCH_NET_SetupGdbUpload 0x021DBC04 thumb
 *   WIFIBATTLEMATCH_NET_GdbUpdateRecord 0x021DBDAC thumb
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   BATTLE_BOX_GetFromSave 0x0200BAC8 thumb
 *   BATTLE_COMPETITION_GetFromSave 0x0200B358 thumb
 *   REGULATION_GetParty 0x0200B204 thumb
 *   func_0200BAF4 0x0200BAF4 thumb
 *   BATTLE_BOX_SetLockFlags 0x0200BBC8 thumb
 *   REGULATION_Card_SetValue 0x0200B110 thumb
 *   REGULATION_BuildParty 0x0200B2A4 thumb
 *   func_020307B0 0x020307B0 arm
 *   GAME_DATA_SaveStart 0x02012DAC thumb
 *   GAME_DATA_SaveMain 0x02012DD0 thumb
 *   MI_CpuFill8 0x02082BCC arm
 *   WIFIBATTLEMATCH_NET_GetGsProfileId 0x021DD020 thumb
 *   WIFIBATTLEMATCH_NET_SetupHttpRap 0x021DC8B4 thumb
 *   WIFIBATTLEMATCH_NET_HttpRapSend 0x021DC908 thumb
 *   WIFIBATTLEMATCH_NET_HandleNetError 0x021D9F04 thumb
 *   WIFIBATTLEMATCH_UTIL_PrintMessage 0x021E8738 thumb ov177
 *   WIFIBATTLEMATCH_UTIL_SetCallback 0x021E8AA0 thumb ov177
 *   WIFIBATTLEMATCH_UTIL_SetRequest 0x021E8AB4 thumb ov177
 *   WIFIBATTLEMATCH_UTIL_CommitRequest 0x021E8AB8 thumb ov177
 *   WIFIBATTLEMATCH_UTIL_GetBusy 0x021E8844 thumb ov177
 *   WIFIBATTLEMATCH_NET_CompCleanup 0x021D9064 thumb
 *   WIFIBATTLEMATCH_NET_CompStepE 0x021D7BE4 thumb
 *   WIFIBATTLEMATCH_NET_CompStepK 0x021D8EC8 thumb
 *   REGULATION_Card_GetValue 0x0200B078 thumb
 *   WIFIBATTLEMATCH_NET_SetupDownload 0x021DC2F4 thumb
 *   WIFIBATTLEMATCH_NET_DownloadProcess 0x021DC338 thumb
 *   WIFIBATTLEMATCH_NET_GetRegCardName 0x021DC66C thumb
 *   REGULATION_Card_IsCrcValid 0x0200B1A8 thumb
 *   WIFIBATTLEMATCH_NET_SetCompWaitCallback 0x021D9A1C thumb
 *   WIFIBATTLEMATCH_NET_GetCompWaitResult 0x021D9A30 thumb
 *   WIFIBATTLEMATCH_NET_CompStepM 0x021D9090 thumb
 *   BATTLE_BOX_IsLocked 0x0200BBFC thumb
 *   WIFIBATTLEMATCH_NET_DeleteTradeIcon 0x021D97A4 thumb
 *   WIFIBATTLEMATCH_NET_IsTradeIconAnimDone 0x021D97C4 thumb
 *   MI_CpuCopy8 0x02082D44 arm
 *   BATTLE_BOX_ClearLockFlags 0x0200BBD8 thumb
 *   BSUBWAY_SAVEDATA_SetStat 0x0200DFE4 thumb
 *   REGULATION_InitParty 0x0200B1F8 thumb
 *   WIFIBATTLEMATCH_NET_GdbRequest 0x021DB3A4 thumb
 *   WIFIBATTLEMATCH_NET_GdbGetMyRecords 0x021DB478 thumb
 *   BSUBWAY_SAVEDATA_GetStat 0x0200DFD8 thumb
 *   WIFIBATTLEMATCH_NET_GetSetCompStat 0x021D9D50 thumb
 *   WIFIBATTLEMATCH_NET_CompExit 0x021D905C thumb
 */
extern void WIFIBATTLEMATCH_NET_CompStepD(unsigned int sys, int *state, char *p);
typedef unsigned int u32;
typedef struct { unsigned char a,b,c,d;u32 id;} Request;
typedef struct {char pad[0x104];u32 *ctx;u32 aux;} ObjectView;
struct Obj;
extern void WIFIBATTLEMATCH_NET_SetupCompRecord(struct Obj *obj);
extern void WIFIBATTLEMATCH_NET_StartTradeIconAnim(char *,unsigned);
extern void WIFIBATTLEMATCH_NET_SetupCompCard(char *);
extern unsigned WIFIBATTLEMATCH_NET_IsTradeIconReady(char *);
extern int WIFIBATTLEMATCH_NET_IsRegSpriteReady(char *);
extern void WIFIBATTLEMATCH_NET_SetupRegSprite(char *,unsigned);
extern int WIFIBATTLEMATCH_NET_IsCompSpriteAnimDone(char *);
extern void WIFIBATTLEMATCH_NET_DeleteCompSprite(char *);
extern int WIFIBATTLEMATCH_NET_IsRegSpriteAnimDone(char *);
extern void WIFIBATTLEMATCH_NET_DeleteRegSprite(char *);
extern void WIFIBATTLEMATCH_NET_CopyCompBox(char *,char *);
typedef signed int     s32;
struct Rec1E;
struct RecBig;
struct Reg2;
extern u32 POKEPARTY_GetBattleReadyCount(void *p);
typedef unsigned short u16;
typedef unsigned char  u8;
struct Obj;
extern void REGULATION_NoOp(void);
extern int POKE_REGULATION_CheckParty(void *rules, void *party, u32 *mask);
extern void WIFIBATTLEMATCH_NET_SetupPostData(char *,void *,int);
struct Record;
extern int WIFIBATTLEMATCH_NET_HttpRapPost(char *p, u8 *out);
extern u32 POKEPARTY_GetCount(void *);
extern void WIFIBATTLEMATCH_NET_SetupGdbUpload(u8 *p, u32 mode, struct Record *src);
extern int WIFIBATTLEMATCH_NET_GdbUpdateRecord(char *);
struct Big;
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern void * BATTLE_BOX_GetFromSave(void *);
extern void *BATTLE_COMPETITION_GetFromSave(void *sys);
extern struct Rec1E *REGULATION_GetParty(struct RecBig *p, u32 index);
extern void *func_0200BAF4(int a0, int a1);
extern void BATTLE_BOX_SetLockFlags(struct Obj *p, u32 v);
extern void REGULATION_Card_SetValue(struct Reg2 *p, u32 id, s32 value);
extern void REGULATION_BuildParty(int,int);
extern u32 func_020307B0(void *p);
extern int GAME_DATA_SaveStart(int);
extern int GAME_DATA_SaveMain(unsigned char *);
extern void MI_CpuFill8(void *,int,unsigned);
extern unsigned WIFIBATTLEMATCH_NET_GetGsProfileId(char *);
extern void WIFIBATTLEMATCH_NET_SetupHttpRap(char *,void *,unsigned);
extern int WIFIBATTLEMATCH_NET_HttpRapSend(char *);
extern int WIFIBATTLEMATCH_NET_HandleNetError(char *,void *,void *);
extern void WIFIBATTLEMATCH_UTIL_PrintMessage(int *,int,int,int);
extern void WIFIBATTLEMATCH_UTIL_SetCallback(int *,int);
extern void WIFIBATTLEMATCH_UTIL_SetRequest(unsigned,unsigned);
extern void WIFIBATTLEMATCH_UTIL_CommitRequest(unsigned);
extern int WIFIBATTLEMATCH_UTIL_GetBusy(const int *p);
extern void WIFIBATTLEMATCH_NET_CompCleanup(void *obj, int unused, u8 *p);
extern void WIFIBATTLEMATCH_NET_CompStepE(u32 sys, int *state, char *p);
extern void WIFIBATTLEMATCH_NET_CompStepK(u32 sys, int *state, char *p);
extern s32 REGULATION_Card_GetValue(struct Reg2 *p, u32 id);
extern void WIFIBATTLEMATCH_NET_SetupDownload(char *,unsigned);
extern int WIFIBATTLEMATCH_NET_DownloadProcess(u8 *p);
extern void WIFIBATTLEMATCH_NET_GetRegCardName(const char *p, void *out);
extern u32 REGULATION_Card_IsCrcValid(struct Reg2 *p);
extern void WIFIBATTLEMATCH_NET_SetCompWaitCallback(char *,void *);
extern u32 WIFIBATTLEMATCH_NET_GetCompWaitResult(char *obj);
extern void WIFIBATTLEMATCH_NET_CompStepM(u32 sys, int *state, char *p);
extern u32 BATTLE_BOX_IsLocked(struct Obj *p, u32 mask);
extern void WIFIBATTLEMATCH_NET_DeleteTradeIcon(char *);
extern int WIFIBATTLEMATCH_NET_IsTradeIconAnimDone(char *);
extern void MI_CpuCopy8(const void *,void *,unsigned);
extern void BATTLE_BOX_ClearLockFlags(struct Obj *p, int v);
extern void BSUBWAY_SAVEDATA_SetStat(unsigned,unsigned,unsigned,unsigned);
struct Rec1E;
extern void REGULATION_InitParty(struct Rec1E *);
extern void WIFIBATTLEMATCH_NET_GdbRequest(char *,unsigned,int,unsigned);
extern int WIFIBATTLEMATCH_NET_GdbGetMyRecords(char *);
extern unsigned BSUBWAY_SAVEDATA_GetStat(unsigned,unsigned,unsigned);
extern int WIFIBATTLEMATCH_NET_GetSetCompStat(char *obj, u32 *rec);
extern void WIFIBATTLEMATCH_NET_CompExit(u32 sys);
#define W(k) (*(u32 *)(p+(k)))
#define CTX (*(u32 **)(p+offset))
#define H ((char *)W(0x34))
void WIFIBATTLEMATCH_NET_CompStepC(int *sys,int *state,char *p)
{
    enum { CTX_OFFSET=0x104 } offset=CTX_OFFSET;
    u32 aux=*(u32 *)(p+(offset+4));
    u32 *ctx=CTX;
    int r;
    unsigned char b;
    u32 saved,temp,item;
    void *box;
    Request request1,request7,request40;
    switch(*state) {
    case 0: if(((unsigned char *)ctx[12])[4]==1) *state=1; else *state=3; break;
    case 1: {
        MI_CpuFill8(&request1,0,8); request1.b=0; request1.a=((unsigned char *)CTX[12])[4];
        request1.id=WIFIBATTLEMATCH_NET_GetGsProfileId(H); ((unsigned char *)CTX[12])[5]=0;
        WIFIBATTLEMATCH_NET_SetupHttpRap(H,&request1,87); *state=2; break;
    }
    case 2:
        r=WIFIBATTLEMATCH_NET_HttpRapSend(H);
        if(r==1) *state=11; else if(r==3) WIFIBATTLEMATCH_UTIL_SetCallback(sys,(int)WIFIBATTLEMATCH_NET_CompCleanup);
        if(r!=0) switch(WIFIBATTLEMATCH_NET_HandleNetError(H,(void *)1,0)) {case 1:case 2:WIFIBATTLEMATCH_UTIL_SetCallback(sys,(int)WIFIBATTLEMATCH_NET_CompCleanup);break;}
        break;
    case 3:
        if(((unsigned char *)CTX[12])[5]==REGULATION_Card_GetValue((struct Reg2 *)aux,10)) *state=4;
        else if(REGULATION_Card_GetValue((struct Reg2 *)aux,10)==4 || REGULATION_Card_GetValue((struct Reg2 *)aux,10)==5) *state=7;
        else *state=4;
        break;
    case 4:
        b=((unsigned char *)ctx[12])[5];
        if(b==3) *state=5; else if((unsigned char)(b+0xfc)<=1) *state=6; else *state=11; break;
    case 5:WIFIBATTLEMATCH_UTIL_PrintMessage((int *)W(0x2c),W(0x14),0x39,1);WIFIBATTLEMATCH_UTIL_SetRequest((u32)sys,46);*state=56;break;
    case 6:WIFIBATTLEMATCH_UTIL_PrintMessage((int *)W(0x2c),W(0x14),0x39,1);WIFIBATTLEMATCH_UTIL_SetRequest((u32)sys,46);*state=56;break;
    case 7: {
        MI_CpuFill8(&request7,0,8); request7.b=REGULATION_Card_GetValue((struct Reg2 *)aux,10); request7.id=WIFIBATTLEMATCH_NET_GetGsProfileId(H);
        ((unsigned char *)CTX[12])[5]=REGULATION_Card_GetValue((struct Reg2 *)aux,10);
        WIFIBATTLEMATCH_NET_SetupHttpRap(H,&request7,87);*state=8;break;
    }
    case 8:
        r=WIFIBATTLEMATCH_NET_HttpRapSend(H);if(r==1)*state=9;else if(r==3)WIFIBATTLEMATCH_UTIL_SetCallback(sys,(int)WIFIBATTLEMATCH_NET_CompCleanup);
        if(r!=0)switch(WIFIBATTLEMATCH_NET_HandleNetError(H,(void *)1,0)){case 1:case 2:WIFIBATTLEMATCH_UTIL_SetCallback(sys,(int)WIFIBATTLEMATCH_NET_CompCleanup);break;}break;
    case 9:*state=6;break;
    case 10:
        r=WIFIBATTLEMATCH_NET_GdbUpdateRecord(H);if(r==1){*(u32 *)CTX[8]=0x708;*state=6;}
        if(r!=0)switch(WIFIBATTLEMATCH_NET_HandleNetError(H,(void *)1,0)){case 1:case 2:WIFIBATTLEMATCH_UTIL_SetCallback(sys,(int)WIFIBATTLEMATCH_NET_CompCleanup);break;}break;
    case 11:WIFIBATTLEMATCH_UTIL_PrintMessage((int *)W(0x2c),W(0x14),0x5b,2);WIFIBATTLEMATCH_UTIL_SetRequest((u32)sys,12);*state=56;break;
    case 12:WIFIBATTLEMATCH_NET_SetupDownload(H,*(u32 *)ctx[12]);*state=13;break;
    case 13:
        r=WIFIBATTLEMATCH_NET_DownloadProcess((u8 *)H);
        if(r==1){WIFIBATTLEMATCH_NET_GetRegCardName(H,p+0x10c);if(REGULATION_Card_IsCrcValid((struct Reg2 *)(p+0x10c)))*state=14;else *state=15;}
        else if(r==2)*state=15;
        if(r!=0)switch(WIFIBATTLEMATCH_NET_HandleNetError(H,(void *)1,0)){case 1:case 2:WIFIBATTLEMATCH_UTIL_SetCallback(sys,(int)WIFIBATTLEMATCH_NET_CompCleanup);break;}break;
    case 15:if(REGULATION_Card_GetValue((struct Reg2 *)aux,2)==0)*state=18;else *state=16;break;
    case 16:
        r=WIFIBATTLEMATCH_NET_HandleNetError(H,(void *)1,0);
        switch(r){case 1:case 2:WIFIBATTLEMATCH_UTIL_SetCallback(sys,(int)WIFIBATTLEMATCH_NET_CompCleanup);break;case 0:WIFIBATTLEMATCH_NET_SetCompWaitCallback(p,WIFIBATTLEMATCH_NET_CompStepM);*state=17;break;}break;
    case 17:
        r=WIFIBATTLEMATCH_NET_GetCompWaitResult(p);if(r!=0xffff)*state=46;if(r==3)WIFIBATTLEMATCH_UTIL_SetCallback(sys,(int)WIFIBATTLEMATCH_NET_CompCleanup);
        switch(WIFIBATTLEMATCH_NET_HandleNetError(H,(void *)1,0)){case 1:case 2:WIFIBATTLEMATCH_UTIL_SetCallback(sys,(int)WIFIBATTLEMATCH_NET_CompCleanup);break;}break;
    case 18:WIFIBATTLEMATCH_UTIL_PrintMessage((int *)W(0x2c),W(0x14),0x3b,1);WIFIBATTLEMATCH_UTIL_SetRequest((u32)sys,55);*state=56;break;
    case 14:
        b=((unsigned char *)ctx[12])[5];if(b==0)*state=19;else if(b==1)*state=53;else if(b==2)*state=54;else *state=55;break;
    case 19:if(REGULATION_Card_GetValue((struct Reg2 *)aux,2)==0)*state=42;else *state=20;break;
    case 20:
        WIFIBATTLEMATCH_NET_SetupCompRecord((struct Obj *)p);
        if(BATTLE_BOX_IsLocked(BATTLE_BOX_GetFromSave((void *)GAME_DATA_GetSaveControl((struct Big *)(*(u32 *)ctx[2]))),1))WIFIBATTLEMATCH_NET_StartTradeIconAnim(p,0);else WIFIBATTLEMATCH_NET_StartTradeIconAnim(p,1);
        *state=21;break;
    case 21:if(WIFIBATTLEMATCH_NET_IsTradeIconReady(p))*state=22;break;
    case 22:if(BATTLE_BOX_IsLocked(BATTLE_BOX_GetFromSave((void *)GAME_DATA_GetSaveControl((struct Big *)(*(u32 *)ctx[2]))),1))*state=23;else *state=29;break;
    case 23:WIFIBATTLEMATCH_UTIL_PrintMessage((int *)W(0x2c),W(0x14),0x3d,1);WIFIBATTLEMATCH_UTIL_SetRequest((u32)sys,24);*state=56;break;
    case 24:WIFIBATTLEMATCH_NET_SetupRegSprite(p,0);*state=25;break;
    case 25:r=WIFIBATTLEMATCH_NET_IsCompSpriteAnimDone(p);if(r!=-1){WIFIBATTLEMATCH_NET_DeleteCompSprite(p);switch(r){case 0:*state=35;break;case 1:*state=26;break;}}break;
    case 26:WIFIBATTLEMATCH_UTIL_PrintMessage((int *)W(0x2c),W(0x14),0x3e,1);WIFIBATTLEMATCH_UTIL_SetRequest((u32)sys,27);*state=56;break;
    case 27:WIFIBATTLEMATCH_NET_SetupRegSprite(p,0);*state=28;break;
    case 28:r=WIFIBATTLEMATCH_NET_IsCompSpriteAnimDone(p);if(r!=-1){WIFIBATTLEMATCH_NET_DeleteCompSprite(p);switch(r){case 0:*state=55;break;case 1:*state=23;break;}}break;
    case 29:WIFIBATTLEMATCH_UTIL_PrintMessage((int *)W(0x2c),W(0x14),0x3c,1);WIFIBATTLEMATCH_UTIL_SetRequest((u32)sys,30);*state=56;break;
    case 30:WIFIBATTLEMATCH_NET_SetupRegSprite(p,0);*state=31;break;
    case 31:r=WIFIBATTLEMATCH_NET_IsCompSpriteAnimDone(p);if(r!=-1){WIFIBATTLEMATCH_NET_DeleteCompSprite(p);switch(r){case 0:*state=35;break;case 1:*state=32;break;}}break;
    case 32:WIFIBATTLEMATCH_UTIL_PrintMessage((int *)W(0x2c),W(0x14),0x3e,1);WIFIBATTLEMATCH_UTIL_SetRequest((u32)sys,33);*state=56;break;
    case 33:WIFIBATTLEMATCH_NET_SetupRegSprite(p,0);*state=34;break;
    case 34:r=WIFIBATTLEMATCH_NET_IsCompSpriteAnimDone(p);if(r!=-1){WIFIBATTLEMATCH_NET_DeleteCompSprite(p);switch(r){case 0:*state=55;break;case 1:*state=29;break;}}break;
    case 35:if(WIFIBATTLEMATCH_NET_IsTradeIconAnimDone(p))*state=36;break;
    case 36:WIFIBATTLEMATCH_NET_DeleteTradeIcon(p);*state=42;break;
    case 37:WIFIBATTLEMATCH_UTIL_PrintMessage((int *)W(0x2c),W(0x14),0x46,2);WIFIBATTLEMATCH_UTIL_SetRequest((u32)sys,38);*state=56;break;
    case 38:if(*(u32 *)ctx[8]==0){MI_CpuFill8((void *)(ctx[13]+0x18),0,0x534);WIFIBATTLEMATCH_NET_SetupGdbUpload((u8 *)H,0,(void *)(CTX[13]+0x18));*state=39;}break;
    case 39:
        r=WIFIBATTLEMATCH_NET_GdbUpdateRecord(H);if(r==1){*(u32 *)CTX[8]=0x708;*state=40;}
        if(r!=0)switch(WIFIBATTLEMATCH_NET_HandleNetError(H,(void *)1,0)){case 1:case 2:WIFIBATTLEMATCH_UTIL_SetCallback(sys,(int)WIFIBATTLEMATCH_NET_CompCleanup);break;}break;
    case 40:{
        MI_CpuFill8(&request40,0,8);request40.a=0;request40.b=1;request40.id=WIFIBATTLEMATCH_NET_GetGsProfileId(H);
        ((unsigned char *)CTX[12])[5]=1;WIFIBATTLEMATCH_NET_SetupHttpRap(H,&request40,87);*state=41;break;
    }
    case 41:
        r=WIFIBATTLEMATCH_NET_HttpRapSend(H);if(r==1)*state=53;else if(r==3)WIFIBATTLEMATCH_UTIL_SetCallback(sys,(int)WIFIBATTLEMATCH_NET_CompCleanup);
        if(r!=0)switch(WIFIBATTLEMATCH_NET_HandleNetError(H,(void *)1,0)){case 1:case 2:WIFIBATTLEMATCH_UTIL_SetCallback(sys,(int)WIFIBATTLEMATCH_NET_CompCleanup);break;}break;
    case 42:WIFIBATTLEMATCH_UTIL_PrintMessage((int *)W(0x2c),W(0x14),0x3a,2);WIFIBATTLEMATCH_UTIL_SetRequest((u32)sys,43);*state=56;break;
    case 43:
        saved=(u32)GAME_DATA_GetSaveControl((struct Big *)(*(u32 *)ctx[2]));box=BATTLE_BOX_GetFromSave((void *)saved);
        item=(u32)REGULATION_GetParty((struct RecBig *)BATTLE_COMPETITION_GetFromSave((void *)saved),0);
        MI_CpuCopy8(p+0x10c,(void *)W(0x108),0x160);
        BATTLE_BOX_ClearLockFlags(box,1);REGULATION_Card_SetValue((struct Reg2 *)W(0x108),10,1);
        BSUBWAY_SAVEDATA_SetStat(ctx[4],10,0,0);BSUBWAY_SAVEDATA_SetStat(ctx[4],10,1,0);BSUBWAY_SAVEDATA_SetStat(ctx[4],10,2,0);
        REGULATION_InitParty((struct Rec1E *)item);GAME_DATA_SaveStart(*(u32 *)ctx[2]);*state=44;break;
    case 44:r=GAME_DATA_SaveMain((unsigned char *)*(u32 *)ctx[2]);if(r==2)*state=37;else if(r==3)*state=45;break;
    case 45:WIFIBATTLEMATCH_UTIL_PrintMessage((int *)W(0x2c),W(0x14),0x40,1);WIFIBATTLEMATCH_UTIL_SetRequest((u32)sys,55);*state=56;break;
    case 46:WIFIBATTLEMATCH_UTIL_PrintMessage((int *)W(0x2c),W(0x14),0x5a,2);WIFIBATTLEMATCH_UTIL_SetRequest((u32)sys,47);*state=56;break;
    case 47:if(*(u32 *)ctx[8]==0){WIFIBATTLEMATCH_NET_GdbRequest(H,-1,1,ctx[13]);*state=48;}break;
    case 48:
        r=WIFIBATTLEMATCH_NET_GdbGetMyRecords(H);if(r==1){*(u32 *)CTX[8]=0x708;*state=49;}
        if(r!=0)switch(WIFIBATTLEMATCH_NET_HandleNetError(H,(void *)1,0)){case 1:case 2:WIFIBATTLEMATCH_UTIL_SetCallback(sys,(int)WIFIBATTLEMATCH_NET_CompCleanup);break;}break;
    case 49:if(((u32 *)CTX[13])[4]!=BSUBWAY_SAVEDATA_GetStat(ctx[4],10,0))*state=50;else *state=55;break;
    case 50:WIFIBATTLEMATCH_UTIL_PrintMessage((int *)W(0x2c),W(0x14),0x3a,2);WIFIBATTLEMATCH_UTIL_SetRequest((u32)sys,51);*state=56;break;
    case 51:WIFIBATTLEMATCH_NET_GetSetCompStat(p,(void *)ctx[13]);GAME_DATA_SaveStart(*(u32 *)ctx[2]);*state=52;break;
    case 52:if(GAME_DATA_SaveMain((unsigned char *)*(u32 *)ctx[2])==2)*state=55;break;
    case 53:WIFIBATTLEMATCH_UTIL_SetCallback(sys,(int)WIFIBATTLEMATCH_NET_CompStepD);break;
    case 54:WIFIBATTLEMATCH_UTIL_SetCallback(sys,(int)WIFIBATTLEMATCH_NET_CompStepE);break;
    case 55:ctx[1]=0;WIFIBATTLEMATCH_UTIL_SetCallback(sys,(int)WIFIBATTLEMATCH_NET_CompExit);break;
    case 56:if(WIFIBATTLEMATCH_UTIL_GetBusy((const int *)W(0x2c)))WIFIBATTLEMATCH_UTIL_CommitRequest((u32)sys);break;
    }
}

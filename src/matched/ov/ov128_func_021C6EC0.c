/*
 * function: Wf2dmapFriend_TopBarMain
 * address: 0x021C6EC0
 * packet: pkt_ov128_021C6EC0
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * note: 2026-10-05 lane P24L6. Bytes equal to the original (632 B function, 640 B listing
 * extent includes the 8 B stub Wf2dmapFriend_Exit). Only the two Wf2dmapFriend_Exit relocations
 * lack a witness: the stub is now filed as src/matched/ov/Wf2dmapFriend_Exit.c (EXACT),
 * so this file should become EXACT after the next manifest refresh. Recoup trail: the
 * condition chain on *p (3,4,1) is an if/else-if chain with q[8]=5 repeated in each arm
 * (bne over b); the shared finish block (Wf2dmapFriend_ResetListWindow with ctx as 2nd argument,
 * WF2DMAP_TOUCH_UpdateTopBar, q[8]=3) is written out in each of its three arms (case 10 arm 0, case 10
 * arm 1, case 11) and case 10 is an inner switch on the menu status. A goto finish form
 * and a return-0 form were each 4 to 70 bytes off. Callee problem: matched Wf2dmapFriend_ResetListWindow
 * takes one parameter but this caller passes two (p, ctx).
 * symbols:
 *   Wf2dmapFriend_Exit 0x021C7138 thumb ov128
 *   Wf2dmapFriend_InitTopBar 0x021C6EA0 thumb ov128
 *   Wf2dmapFriend_DrawListBg 0x021C72E4 thumb ov128
 *   Wf2dmapFriend_ListInput 0x021C74C4 thumb ov128
 *   WF2DMAP_TOUCH_PlayActorAnimA 0x021CA3A0 thumb ov128
 *   WF2DMAP_TOUCH_PlayActorAnimB 0x021CA3C4 thumb ov128
 *   WF2DMAP_TOUCH_StepTopBarBlink 0x021CA1E0 thumb ov128
 *   Wf2dmapFriend_HasEntry 0x021C76BC thumb ov128
 *   Wf2dmapFriend_SetListState 0x021C74E8 thumb ov128
 *   Wf2dmapFriend_ClearListScreen 0x021C7500 thumb ov128
 *   Wf2dmapFriend_PrintMessage 0x021C7558 thumb ov128
 *   WF2DMAP_TOUCH_ParseKey 0x021CA014 thumb ov128
 *   Wf2dmapFriend_SetFriendCode 0x021C6B50 thumb ov128
 *   Wf2dmapFriend_CheckPrintStream 0x021C7674 thumb ov128
 *   Wf2dmapFriend_OpenMenu 0x021C6E3C thumb ov128
 *   Wf2dmapFriend_UpdateMenu 0x021C6E74 thumb ov128
 *   Wf2dmapFriend_SubmitFriendKey 0x021C6460 thumb ov128
 *   WF2DMAP_TOUCH_GetConfirmInput 0x021CA084 thumb ov128
 *   Wf2dmapFriend_ResetListWindow 0x021C7694 thumb ov128
 *   WF2DMAP_TOUCH_UpdateTopBar 0x021CA19C thumb ov128
 *   WIPE_SYS_Start 0x0202208C thumb
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 *   BLINK_PALANM_Update 0x0202EA40 thumb
 *   CLACT_IsActorAnimActive 0x0204B98C arm
 *   MYSTATUS_Create 0x0200846C thumb
 *   func_020084E4 0x020084E4 thumb
 *   WORDSET_SetSlotMyStatus 0x0201F02C thumb
 *   func_020307B0 0x020307B0 arm
 *   func_020355C4 0x020355C4 arm
 *   gWf2dmapFriendKeyErrorMsgIds 0x021CA4F9 data a1
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
extern void Wf2dmapFriend_InitTopBar(u8 *,u8 *,u8 *,u16);
struct Actor;
struct U16Vec;
struct WordSet;
extern void Wf2dmapFriend_DrawListBg(u8 *p, int *q, u8 *ctx);
extern int Wf2dmapFriend_ListInput(int *p, int *q, u8 *r);
extern void WF2DMAP_TOUCH_PlayActorAnimA(char *);
extern void WF2DMAP_TOUCH_PlayActorAnimB(char *);
extern int WF2DMAP_TOUCH_StepTopBarBlink(char *p);
extern int Wf2dmapFriend_HasEntry(int *p, u8 *q);
extern void Wf2dmapFriend_SetListState(u32 *p, u8 *q);
extern void Wf2dmapFriend_ClearListScreen(u8 *,u8 *);
extern void Wf2dmapFriend_PrintMessage(u8 *,u8 *,unsigned,unsigned);
extern u64 WF2DMAP_TOUCH_ParseKey(void *,int *);
extern void Wf2dmapFriend_SetFriendCode(void **p, unsigned long long value);
extern int Wf2dmapFriend_CheckPrintStream(void *p, int *q, u8 *r);
extern void *Wf2dmapFriend_OpenMenu(void *p, void **q, int a, int heap);
extern int Wf2dmapFriend_UpdateMenu(u8 *p);
extern int Wf2dmapFriend_SubmitFriendKey(char *p, void *q, u32 arg);
extern int WF2DMAP_TOUCH_GetConfirmInput(int *p);
extern void Wf2dmapFriend_ResetListWindow(u8 *p, void *ctx);
extern void WF2DMAP_TOUCH_UpdateTopBar(unsigned *p);
extern void WIPE_SYS_Start(void *,u32,u32,u32,u32,u32,u32);
extern u32 WIPE_SYS_EndCheck(void);
typedef signed int     s32;
struct Row;
extern s32 BLINK_PALANM_Update(struct Row *p);
extern u32 CLACT_IsActorAnimActive(struct Actor *a);
extern void *MYSTATUS_Create(int);
extern void func_020084E4(u16 *out, struct U16Vec *vec);
extern void WORDSET_SetSlotMyStatus(struct WordSet *p, u32 i, void *a);
extern u32 func_020307B0(void *p);
extern u8 func_020355C4(void);
extern void Wf2dmapFriend_Exit(u8 *,u8 *,u8 *);
extern const u8 gWf2dmapFriendKeyErrorMsgIds[];
int Wf2dmapFriend_TopBarMain(u8 *p, u8 *q, u8 *ctx, int heap)
{
    int result;
    void *text;
    u64 number;
    switch(q[8]) {
    case 0:
        Wf2dmapFriend_InitTopBar(p,q,ctx,52);
        Wf2dmapFriend_DrawListBg(p,(int *)q,ctx);
        WIPE_SYS_Start(0,1,1,0,6,1,heap);
        q[8]=1;
        break;
    case 1:
        if(WIPE_SYS_EndCheck()!=0) q[8]=3;
        break;
    case 2:
        Wf2dmapFriend_InitTopBar(p,q,ctx,52);
        Wf2dmapFriend_DrawListBg(p,(int *)q,ctx);
        q[8]=3;
        break;
    case 3:
        BLINK_PALANM_Update(*(void **)(ctx+0x184));
        result=Wf2dmapFriend_ListInput((int *)p,(int *)q,ctx);
        if(result!=0) {
            if(*(u32 *)p==3) WF2DMAP_TOUCH_PlayActorAnimA((char *)ctx);
            else if(*(u32 *)p==4) WF2DMAP_TOUCH_PlayActorAnimB((char *)ctx);
            else *(u16 *)(p+8)=0;
            q[8]=4;
        }
        break;
    case 4:
        if(*(u32 *)p==3) {
            if(CLACT_IsActorAnimActive(*(void **)(ctx+0x164))==1) break;
        } else if(*(u32 *)p==4) {
            if(CLACT_IsActorAnimActive(*(void **)(ctx+0x168))==1) break;
        } else {
            if(WF2DMAP_TOUCH_StepTopBarBlink((char *)p)==1) break;
        }
        if(Wf2dmapFriend_HasEntry((int *)p,q)==1) {
            Wf2dmapFriend_SetListState((u32 *)p,q);
            if(*(u32 *)p==3) q[8]=5;
            else if(*(u32 *)p==4) q[8]=5;
            else if(*(u32 *)p==1) q[8]=5;
            else {
                Wf2dmapFriend_ClearListScreen(p,ctx);
                Wf2dmapFriend_Exit(p,q,ctx);
                return 1;
            }
        } else {
            Wf2dmapFriend_PrintMessage(p,ctx,58,heap);
            q[8]=11;
        }
        break;
    case 5:
        WIPE_SYS_Start(0,0,0,0,6,1,heap);
        q[8]++;
        break;
    case 6:
        if(WIPE_SYS_EndCheck()==1) {
            Wf2dmapFriend_Exit(p,q,ctx);
            return 1;
        }
        break;
    case 7:
        Wf2dmapFriend_InitTopBar(p,q,ctx,52);
        Wf2dmapFriend_DrawListBg(p,(int *)q,ctx);
        WIPE_SYS_Start(0,1,1,0,6,1,heap);
        q[8]=8;
        break;
    case 8:
        if(WIPE_SYS_EndCheck()!=0) {
            text=MYSTATUS_Create(heap);
            func_020084E4(text,*(void **)(q+0x58));
            WORDSET_SetSlotMyStatus(*(void **)ctx,0,text);
            func_020307B0(text);
            number=WF2DMAP_TOUCH_ParseKey(*(void **)(q+0x5C),&result);
            if(result!=0) {
                Wf2dmapFriend_SetFriendCode((void **)ctx,number);
                Wf2dmapFriend_PrintMessage(p,ctx,55,heap);
                q[8]=9;
            } else {
                Wf2dmapFriend_PrintMessage(p,ctx,56,heap);
                q[8]=11;
            }
        }
        break;
    case 9:
        if(Wf2dmapFriend_CheckPrintStream(p,(int *)q,ctx)!=0) {
            *(void **)(p+0x4C)=Wf2dmapFriend_OpenMenu(p+0x30,(void **)(p+0x48),1,heap);
            q[8]=10;
        }
        break;
    case 10:
        switch(Wf2dmapFriend_UpdateMenu(*(void **)(p+0x4C))) {
        case 0:
            {
            int submission;
            *(u32 *)q=func_020355C4();
            submission=Wf2dmapFriend_SubmitFriendKey((char *)q,*(void **)(q+0x5C),*(u32 *)(q+0x58));
            if(submission==0) {
                Wf2dmapFriend_ResetListWindow(p,ctx);
                WF2DMAP_TOUCH_UpdateTopBar((unsigned int *)p);
                q[8]=3;
            } else {
                Wf2dmapFriend_PrintMessage(p,ctx,gWf2dmapFriendKeyErrorMsgIds[submission],heap);
                q[8]=11;
            }
            }
            break;
        case 1:
            *(u32 *)q=func_020355C4();
            Wf2dmapFriend_ResetListWindow(p,ctx);
            WF2DMAP_TOUCH_UpdateTopBar((unsigned int *)p);
            q[8]=3;
            break;
        }
        break;
    case 11:
        if(Wf2dmapFriend_CheckPrintStream(p,(int *)q,ctx)!=0 && WF2DMAP_TOUCH_GetConfirmInput((int *)q)==1) {
            Wf2dmapFriend_ResetListWindow(p,ctx);
            WF2DMAP_TOUCH_UpdateTopBar((unsigned int *)p);
            q[8]=3;
        }
        break;
    default:
        break;
    }
    return 0;
}

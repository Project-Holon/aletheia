/*
 * function: func_021C6EC0
 * address: 0x021C6EC0
 * packet: pkt_ov128_021C6EC0
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * note: 2026-10-05 lane P24L6. Bytes equal to the original (632 B function, 640 B listing
 * extent includes the 8 B stub func_021C7138). Only the two func_021C7138 relocations
 * lack a witness: the stub is now filed as src/matched/ov/ov128_func_021C7138.c (EXACT),
 * so this file should become EXACT after the next manifest refresh. Recoup trail: the
 * condition chain on *p (3,4,1) is an if/else-if chain with q[8]=5 repeated in each arm
 * (bne over b); the shared finish block (func_021C7694 with ctx as 2nd argument,
 * WF2DMAP_TOUCH_UpdateTopBar, q[8]=3) is written out in each of its three arms (case 10 arm 0, case 10
 * arm 1, case 11) and case 10 is an inner switch on the menu status. A goto finish form
 * and a return-0 form were each 4 to 70 bytes off. Callee problem: matched func_021C7694
 * takes one parameter but this caller passes two (p, ctx).
 * symbols:
 *   func_021C7138 0x021C7138 thumb ov128
 *   func_021C6EA0 0x021C6EA0 thumb ov128
 *   func_021C72E4 0x021C72E4 thumb ov128
 *   func_021C74C4 0x021C74C4 thumb ov128
 *   WF2DMAP_TOUCH_PlayActorAnimA 0x021CA3A0 thumb ov128
 *   WF2DMAP_TOUCH_PlayActorAnimB 0x021CA3C4 thumb ov128
 *   WF2DMAP_TOUCH_StepTopBarBlink 0x021CA1E0 thumb ov128
 *   func_021C76BC 0x021C76BC thumb ov128
 *   func_021C74E8 0x021C74E8 thumb ov128
 *   func_021C7500 0x021C7500 thumb ov128
 *   func_021C7558 0x021C7558 thumb ov128
 *   WF2DMAP_TOUCH_ParseKey 0x021CA014 thumb ov128
 *   func_021C6B50 0x021C6B50 thumb ov128
 *   func_021C7674 0x021C7674 thumb ov128
 *   func_021C6E3C 0x021C6E3C thumb ov128
 *   func_021C6E74 0x021C6E74 thumb ov128
 *   func_021C6460 0x021C6460 thumb ov128
 *   WF2DMAP_TOUCH_GetConfirmInput 0x021CA084 thumb ov128
 *   func_021C7694 0x021C7694 thumb ov128
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
 *   d_021CA4F9 0x021CA4F9 data a1
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
extern void func_021C6EA0(u8 *,u8 *,u8 *,u16);
struct Actor;
struct U16Vec;
struct WordSet;
extern void func_021C72E4(u8 *p, int *q, u8 *ctx);
extern int func_021C74C4(int *p, int *q, u8 *r);
extern void WF2DMAP_TOUCH_PlayActorAnimA(char *);
extern void WF2DMAP_TOUCH_PlayActorAnimB(char *);
extern int WF2DMAP_TOUCH_StepTopBarBlink(char *p);
extern int func_021C76BC(int *p, u8 *q);
extern void func_021C74E8(u32 *p, u8 *q);
extern void func_021C7500(u8 *,u8 *);
extern void func_021C7558(u8 *,u8 *,unsigned,unsigned);
extern u64 WF2DMAP_TOUCH_ParseKey(void *,int *);
extern void func_021C6B50(void **p, unsigned long long value);
extern int func_021C7674(void *p, int *q, u8 *r);
extern void *func_021C6E3C(void *p, void **q, int a, int heap);
extern int func_021C6E74(u8 *p);
extern int func_021C6460(char *p, void *q, u32 arg);
extern int WF2DMAP_TOUCH_GetConfirmInput(int *p);
extern void func_021C7694(u8 *p, void *ctx);
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
extern void func_021C7138(u8 *,u8 *,u8 *);
extern const u8 d_021CA4F9[];
int func_021C6EC0(u8 *p, u8 *q, u8 *ctx, int heap)
{
    int result;
    void *text;
    u64 number;
    switch(q[8]) {
    case 0:
        func_021C6EA0(p,q,ctx,52);
        func_021C72E4(p,(int *)q,ctx);
        WIPE_SYS_Start(0,1,1,0,6,1,heap);
        q[8]=1;
        break;
    case 1:
        if(WIPE_SYS_EndCheck()!=0) q[8]=3;
        break;
    case 2:
        func_021C6EA0(p,q,ctx,52);
        func_021C72E4(p,(int *)q,ctx);
        q[8]=3;
        break;
    case 3:
        BLINK_PALANM_Update(*(void **)(ctx+0x184));
        result=func_021C74C4((int *)p,(int *)q,ctx);
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
        if(func_021C76BC((int *)p,q)==1) {
            func_021C74E8((u32 *)p,q);
            if(*(u32 *)p==3) q[8]=5;
            else if(*(u32 *)p==4) q[8]=5;
            else if(*(u32 *)p==1) q[8]=5;
            else {
                func_021C7500(p,ctx);
                func_021C7138(p,q,ctx);
                return 1;
            }
        } else {
            func_021C7558(p,ctx,58,heap);
            q[8]=11;
        }
        break;
    case 5:
        WIPE_SYS_Start(0,0,0,0,6,1,heap);
        q[8]++;
        break;
    case 6:
        if(WIPE_SYS_EndCheck()==1) {
            func_021C7138(p,q,ctx);
            return 1;
        }
        break;
    case 7:
        func_021C6EA0(p,q,ctx,52);
        func_021C72E4(p,(int *)q,ctx);
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
                func_021C6B50((void **)ctx,number);
                func_021C7558(p,ctx,55,heap);
                q[8]=9;
            } else {
                func_021C7558(p,ctx,56,heap);
                q[8]=11;
            }
        }
        break;
    case 9:
        if(func_021C7674(p,(int *)q,ctx)!=0) {
            *(void **)(p+0x4C)=func_021C6E3C(p+0x30,(void **)(p+0x48),1,heap);
            q[8]=10;
        }
        break;
    case 10:
        switch(func_021C6E74(*(void **)(p+0x4C))) {
        case 0:
            {
            int submission;
            *(u32 *)q=func_020355C4();
            submission=func_021C6460((char *)q,*(void **)(q+0x5C),*(u32 *)(q+0x58));
            if(submission==0) {
                func_021C7694(p,ctx);
                WF2DMAP_TOUCH_UpdateTopBar((unsigned int *)p);
                q[8]=3;
            } else {
                func_021C7558(p,ctx,d_021CA4F9[submission],heap);
                q[8]=11;
            }
            }
            break;
        case 1:
            *(u32 *)q=func_020355C4();
            func_021C7694(p,ctx);
            WF2DMAP_TOUCH_UpdateTopBar((unsigned int *)p);
            q[8]=3;
            break;
        }
        break;
    case 11:
        if(func_021C7674(p,(int *)q,ctx)!=0 && WF2DMAP_TOUCH_GetConfirmInput((int *)q)==1) {
            func_021C7694(p,ctx);
            WF2DMAP_TOUCH_UpdateTopBar((unsigned int *)p);
            q[8]=3;
        }
        break;
    default:
        break;
    }
    return 0;
}

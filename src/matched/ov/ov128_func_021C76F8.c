/*
 * function: func_021C76F8,func_021C7AC4
 * unit: yes
 * address: 0x021C76F8
 * packet: pkt_ov128_021C76F8
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * extent: 021C7AC4 is the eight-byte tail stub to 021C7D48.
 * calls: Entry r0-r3 stay live into argumentless switch-arm calls.
 * Original explicit r1=ctx on 021C87B0/8850/8880 is retained even
 * where the callee reads only r0. All signed indexed reads are modular.
 * symbols:
 *   func_021C76F0 0x021C76F0 thumb ov128
 *   func_021C6520 0x021C6520 thumb ov128
 *   func_021C7E0C 0x021C7E0C thumb ov128
 *   func_021C81C8 0x021C81C8 thumb ov128
 *   func_021C8668 0x021C8668 thumb ov128
 *   WF2DMAP_TOUCH_SetActorAnimSeq 0x021CA40C thumb ov128
 *   func_021C81FC 0x021C81FC thumb ov128
 *   func_021C8240 0x021C8240 thumb ov128
 *   func_021C8354 0x021C8354 thumb ov128
 *   WF2DMAP_TOUCH_StepItemBarBlink 0x021CA320 thumb ov128
 *   func_021C87A0 0x021C87A0 thumb ov128
 *   func_021C651C 0x021C651C thumb ov128
 *   func_021C83B0 0x021C83B0 thumb ov128
 *   func_021C873C 0x021C873C thumb ov128
 *   func_021C83DC 0x021C83DC thumb ov128
 *   func_021C8470 0x021C8470 thumb ov128
 *   func_021C7E48 0x021C7E48 thumb ov128
 *   func_021C6438 0x021C6438 thumb ov128
 *   func_021C7AC4 0x021C7AC4 thumb ov128
 *   func_021C7D48 0x021C7D48 thumb ov128
 *   func_021C6514 0x021C6514 thumb ov128
 *   func_021C8548 0x021C8548 thumb ov128
 *   func_021C8574 0x021C8574 thumb ov128
 *   func_021C6E74 0x021C6E74 thumb ov128
 *   func_021C875C 0x021C875C thumb ov128
 *   func_021C87B0 0x021C87B0 thumb ov128
 *   func_021C8850 0x021C8850 thumb ov128
 *   func_021C85A4 0x021C85A4 thumb ov128
 *   func_021C8880 0x021C8880 thumb ov128
 *   func_021C84E8 0x021C84E8 thumb ov128
 *   WF2DMAP_TOUCH_GetConfirmInput 0x021CA084 thumb ov128
 *   BLINK_PALANM_Update 0x0202EA40 thumb
 *   BLINK_PALANM_ResetPhase 0x0202EB04 thumb
 *   WIPE_SYS_Start 0x0202208C thumb
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 *   GAME_DATA_GetWifiList 0x0201283C thumb
 *   func_020099D4 0x020099D4 thumb
 *   func_02009A00 0x02009A00 thumb
 *   func_02009A74 0x02009A74 thumb
 *   func_020355C4 0x020355C4 arm
 *   CLACT_IsActorAnimActive 0x0204B98C arm
 */
#include "../include/Obj00179.h"
#include "../include/Obj00298.h"
#include "../include/Obj03809.h"
typedef unsigned int u32;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned char u8;
typedef signed char s8;
extern void func_021C76F0(u8 *,u8 *,u8 *,u32);
extern void func_021C6520(char *);
extern void func_021C7E0C(u8 *,u8 *,u8 *,u16);
struct BigObj;
struct CodeIn;
struct Sub020097BCObj;
extern int func_021C81C8(s16 *p, u8 *q, u8 *r);
extern void func_021C8668(u8 *,u8 *,int);
extern void WF2DMAP_TOUCH_SetActorAnimSeq(char *p, int n);
extern void func_021C81FC(u8 *,void *,u8 *,u16);
extern int func_021C8240(u8 *,u8 *,u8 *,u16),func_021C8354(u8 *,u8 *);
extern int WF2DMAP_TOUCH_StepItemBarBlink(char *),func_021C87A0(s16 *);
extern void func_021C651C(char *,int),func_021C6514(char *,int);
extern void func_021C83B0(s16 *p, u8 *q, u8 *r, u16 heap);
extern int func_021C873C(void *p, int *state, u8 *q);
extern void func_021C83DC(u8 *,u8 *,void *,int);
extern int func_021C8470(u8 *,int *,void *);
extern void func_021C7E48(u8 *p, void *q, u8 *r);
extern void func_021C6438(u8 *,u8,u8);
extern void func_021C7AC4(u8 *,u8 *,u8 *),func_021C7D48(u8 *,void *,u8 *);
extern void func_021C8548(s16 *p, u8 *q, u8 *r, u16 heap);
extern int func_021C8574(u8 *p, int *q, u8 *r, int heap);
extern int func_021C6E74(u8 *p);
extern void func_021C875C(char *p, char *q);
extern void func_021C87B0(u8 *,u8 *);
extern int func_021C8850(u8 *,u8 *);
extern void func_021C85A4(u8 *,u8 *,u8 *,int,int,int,u16),func_021C8880(u8 *,u8 *);
extern int func_021C84E8(u8 *,u8 *,u8 *,int);
extern int WF2DMAP_TOUCH_GetConfirmInput(int *p);
typedef signed int     s32;
struct Row;
extern s32 BLINK_PALANM_Update(struct Row *p);
extern void BLINK_PALANM_ResetPhase(struct CodeIn *p);
extern void WIPE_SYS_Start(void *,u32,u32,u32,u32,u32,u32);
extern u32 WIPE_SYS_EndCheck(void);
extern u32 GAME_DATA_GetWifiList(const struct BigObj *p);
struct Actor;
struct Sub020097BCEnt;
struct Sub020097BCObj;
extern struct Sub020097BCEnt *func_020099D4(struct Sub020097BCObj *obj, int i);
extern void func_02009A00(struct Sub020097BCObj *obj, int i, void *dest);
extern void func_02009A74(struct Sub020097BCObj *obj, u32 i);
extern u8 func_020355C4(void);
extern u32 CLACT_IsActorAnimActive(struct Actor *a);
int func_021C76F8(u8 *p,u8 *q,u8 *ctx,u16 heap)
{
    int idx;
    u32 base;
    switch(q[8]) {
    case 0:
        *(u16 *)&((struct Obj00179 *)p)->f0=0; ((struct Obj00179 *)p)->f2=0; *(u16 *)&((struct Obj00179 *)p)->f4=0; ((struct Obj00179 *)p)->f6=0;
    case 1:
        func_021C76F0(p,q,ctx,52);
        func_021C6520((char *)q);
        func_021C7E0C(p,q,ctx,heap);
        q[8]=2;
        break;
    case 2:
        BLINK_PALANM_Update(((struct Obj03809 *)ctx)->f184);
        BLINK_PALANM_Update(((struct Obj03809 *)ctx)->f188);
        switch(func_021C81C8((s16 *)p,q,ctx)) {
        case 0: break;
        case 1:
            func_021C8668(p,q,2);
            WF2DMAP_TOUCH_SetActorAnimSeq((char *)p,((struct Obj00179 *)p)->f0);
            BLINK_PALANM_ResetPhase(((struct Obj03809 *)ctx)->f188);
            BLINK_PALANM_Update(((struct Obj03809 *)ctx)->f188);
            break;
        case 2:
            func_021C8668(p,q,3);
            WF2DMAP_TOUCH_SetActorAnimSeq((char *)p,((struct Obj00179 *)p)->f0);
            BLINK_PALANM_ResetPhase(((struct Obj03809 *)ctx)->f188);
            BLINK_PALANM_Update(((struct Obj03809 *)ctx)->f188);
            break;
        case 3: q[8]=25; break;
        case 4: q[8]=26; break;
        case 5: q[8]=6; break;
        }
        break;
    case 3: func_021C81FC(p,q,ctx,heap); q[8]=4; break;
    case 4: if(func_021C8240(p,q,ctx,heap)==1) q[8]=5; break;
    case 5: if(func_021C8354(p,ctx)==1) q[8]=2; break;
    case 6:
        if(WF2DMAP_TOUCH_StepItemBarBlink((char *)p)!=1) {
            func_021C651C((char *)q,func_021C87A0((s16 *)p));
            func_021C83B0((s16 *)p,q,ctx,heap); q[8]=7;
        }
        break;
    case 7:
        if(func_021C873C(p,(int *)q,ctx)==1) {func_021C83DC(p,q,ctx,heap);q[8]=8;}
        break;
    case 8: q[8]=func_021C8470(p,(int *)q,ctx); break;
    case 9: ((struct Obj00179 *)p)->f19C=8; q[8]=10; break;
    case 10:
        (((struct Obj00179 *)p)->f19C)--;
        if(((struct Obj00179 *)p)->f19C<=0) {
            func_021C7E48(p,q,ctx);func_021C6438(q,4,0);func_021C7AC4(p,q,ctx);return 1;
        }
        break;
    case 11:
        ((struct Obj00179 *)p)->f0=((struct Obj00298 *)q)->fB/8;
        ((struct Obj00179 *)p)->f4=((struct Obj00298 *)q)->fB%8;
        q[8]=1;
        break;
    case 12:
        WIPE_SYS_Start(0,0,0,0,6,1,heap);
        idx=func_021C87A0((s16 *)p);
        base=GAME_DATA_GetWifiList(((struct Obj00298 *)q)->f4);
        func_021C6514((char *)q,(int)func_020099D4((void *)base,*(u8 *)((u32)q+(u32)idx+24)));
        q[8]=13;
        break;
    case 13:
        if(WIPE_SYS_EndCheck()!=0) {
            func_021C7E48(p,q,ctx);func_021C6438(q,2,4);func_021C7AC4(p,q,ctx);return 1;
        }
        break;
    case 14:
        idx=func_021C87A0((s16 *)p);
        base=GAME_DATA_GetWifiList(((struct Obj00298 *)q)->f4);
        func_02009A00((void *)base,*(u8 *)((u32)q+(u32)idx+24),((struct Obj00298 *)q)->f58);
    case 15:
        func_021C76F0(p,q,ctx,52);func_021C7E0C(p,q,ctx,heap);
        WIPE_SYS_Start(0,1,1,0,6,1,heap);q[8]=16;
        break;
    case 16: if(WIPE_SYS_EndCheck()!=0) q[8]=2; break;
    case 17: func_021C8548((s16 *)p,q,ctx,heap);q[8]=18;break;
    case 18: if(func_021C8574(p,(int *)q,ctx,heap)==1) q[8]=19;break;
    case 19:
        switch(func_021C6E74(((struct Obj00179 *)p)->f194)) {
        case 0:
            ((struct Obj00298 *)q)->f0=func_020355C4();func_021C875C((char *)p,(char *)ctx);q[8]=20;break;
        case 1:
            ((struct Obj00298 *)q)->f0=func_020355C4();func_021C875C((char *)p,(char *)ctx);q[8]=2;break;
        }
        break;
    case 20: func_021C87B0(p,ctx);q[8]=21;break;
    case 21:
        if(func_021C8850(p,ctx)==1) {
            base=GAME_DATA_GetWifiList(((struct Obj00298 *)q)->f4);
            idx=func_021C87A0((s16 *)p);
            func_02009A74((void *)base,*(u8 *)((u32)q+(u32)idx+24));
            func_021C6520((char *)q);
            func_021C85A4(p,q,ctx,((struct Obj00179 *)p)->f0,((struct Obj00179 *)p)->f4,0,heap);q[8]=22;
        }
        break;
    case 22: func_021C8880(p,ctx);q[8]=2;break;
    case 23:
        if(func_021C84E8(p,q,ctx,heap)==1) q[8]=24;
        else q[8]=2;
        break;
    case 24:
        if(func_021C873C(p,(int *)q,ctx)!=0 && WF2DMAP_TOUCH_GetConfirmInput((int *)q)==1) {q[8]=2;func_021C875C((char *)p,(char *)ctx);}
        break;
    case 25:
        if(CLACT_IsActorAnimActive(((struct Obj03809 *)ctx)->f164)!=1) {
            func_021C7E48(p,q,ctx);func_021C6438(q,0,2);func_021C7AC4(p,q,ctx);return 1;
        }
        break;
    case 26: if(CLACT_IsActorAnimActive(((struct Obj03809 *)ctx)->f168)!=1) q[8]=27;break;
    case 27: WIPE_SYS_Start(0,0,0,0,6,1,heap);q[8]=28;break;
    case 28:
        if(WIPE_SYS_EndCheck()!=0) {func_021C6438(q,6,0);func_021C7AC4(p,q,ctx);return 1;}
        break;
    }
    return 0;
}
void func_021C7AC4(u8 *p,u8 *q,u8 *ctx) {func_021C7D48(p,q,ctx);}

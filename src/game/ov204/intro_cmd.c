/*
 * file:     intro_cmd.c
 * unit:     yes
 * function: func_021BE328, func_021BE360, func_021BE374, func_021BE398, func_021BE3A4, func_021BE3B8, func_021BE3CC, func_021BE3DC, func_021BE3EC, func_021BE420, func_021BE430, func_021BE44C, func_021BE460, func_021BE478, func_021BE4AC, func_021BE4B8, func_021BE510, func_021BE524, func_021BE53C, func_021BE54C, func_021BE560, func_021BE578, func_021BE61C, func_021BE6A4, func_021BE6B4, func_021BE6E8, func_021BE6F8, func_021BE708, func_021BE770, func_021BE78C, func_021BE7A8, func_021BE838, func_021BE864, func_021BE874, func_021BE884, func_021BE898, func_021BE970, func_021BE984, func_021BEB00, func_021BEBEC, func_021BED6C, func_021BEDB8, func_021BEE5C, func_021BEEF0, func_021BEF08, func_021BEF20, func_021BEF74, func_021BEF88, func_021BF00C, func_021BF030, func_021BF080, func_021BF094
 * address:  0x021BE328
 * region:   ov204
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from intro_cmd.c by tools/splitfile.py.
 *
 * symbols:
 *   FADE_Start 0x0204E720 arm
 *   FADE_IsActive 0x0204E804 arm
 *   BRIGHTNESS_ChangeRequest 0x02023EF4 thumb
 *   BRIGHTNESS_IsFinished 0x02024004 thumb
 *   GFL_USE_FadeOutBgm 0x02005E30 thumb
 *   GFL_USE_FadeInBgmFull 0x02005DF8 thumb
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   GFL_USE_GetSeSlot 0x02006148 thumb
 *   GFL_USE_SetSeSlotVolume 0x020062BC thumb
 *   GFL_USE_SetSeSlotParams 0x02006268 thumb
 *   GFL_USE_StopSeSlot 0x020061F8 thumb
 *   d_021C09D4 0x021C09D4 data a4
 *   INTRO_G3D_AddPokemonSlot 0x021BF67C thumb ov204
 *   INTRO_G3D_SetSlotMepachi 0x021BF7CC thumb ov204
 *   d_021BFFE4 0x021BFFE4 data a1
 *   INTRO_G3D_SetVanishFlag 0x021BF720 thumb ov204
 *   INTRO_G3D_SetSlotAnim 0x021BF744 thumb ov204
 *   INTRO_G3D_GetSlotAnimFinished 0x021BF77C thumb ov204
 *   INTRO_G3D_ClearSlotAnimFinished 0x021BF788 thumb ov204
 *   INTRO_G3D_MoveSlot 0x021BF804 thumb ov204
 *   INTRO_G3D_SetSlotAlpha 0x021BF794 thumb ov204
 *   SAVE_CONTROL_INTR_Start 0x021BD2B0 thumb
 *   SAVE_CONTROL_INTR_Pause 0x021BD368 thumb ov088
 *   SAVE_CONTROL_INTR_IsPausedOrFinished 0x021BD380 thumb ov088
 *   SAVE_CONTROL_INTR_Resume 0x021BD374 thumb ov088
 *   SAVE_CONTROL_INTR_NoOp 0x021BD39C thumb ov088
 *   SAVE_CONTROL_INTR_IsFinished 0x021BD3A0 thumb ov088
 *   CONFIG_SetAppliedFlag 0x020083EC thumb
 *   func_0200854C 0x0200854C thumb
 *   GFL_USE_IsAnySeBusy  0x02006238  thumb
 *   PM_VOICE_Start  0x02006A64  thumb
 *   PM_VOICE_IsSlotActive  0x02006BD0  thumb
 *   INTRO_G3D_MoveSlot1  0x021BF864  thumb ov204
 *   func_0207D63C 0x0207D63C arm
 *   INTRO_PARTICLE_StartEffect 0x021BFCE8 thumb ov204
 *   INTRO_G3D_SetVisible 0x021BFAE4 thumb
 *   INTRO_G3D_SetAnimFrame 0x021BFBC8 thumb
 *   INTRO_G3D_UpdateIntro 0x021BFA40 thumb ov204
 *   INTRO_G3D_SetAnimMode 0x021BFAE8 thumb ov204
 *   INTRO_G3D_UpdateAnimMode 0x021BFB2C thumb ov204
 *   KEY_GetTrg 0x020362DC arm
 *   INTRO_G3D_UpdateAnimFrame 0x021BFBA0 thumb ov204
 *   BG_SYS_DrawTileSub 0x020411E8 arm
 *   func_02040588 0x02040588 arm
 *   func_02041B6C 0x02041B6C arm
 *   BG_SYS_SetTileEntry 0x02041300 arm
 *   func_020490F4 0x020490F4 arm
 *   func_02008550 0x02008550 thumb
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterPalette 0x0204ABF0 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   func_021BDD78 0x021BDD78 thumb ov204
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   init 0x021BFFCC data a2
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   CLACT_SetActorObjMode 0x0204B688 arm
 *   CLACT_GetActorObjMode 0x0204B6E4 arm
 *   WORDSET_SetSlotMyStatus 0x0201F02C thumb
 *   func_02030734 0x02030734 arm
 *   d_021C0AAC 0x021C0AAC data a1
 *   func_020307B0 0x020307B0 arm
 *   d_021C09D8 0x021C09D8 data a4
 *   d_021C0AB8 0x021C0AB8 data a4
 *   gIntroSite 0x021C0AE4 data a1
 *   TOUCHPANEL_GetTrg  0x02035C60  arm
 *   GFL_USE_CancelChangeAndPlayBgm  0x02005D90  thumb  arm9
 *   BRIGHTNESS_Set  0x02023F60  thumb  arm9
 *   GFL_USE_IsBgmPlaying  0x02005F38  thumb  arm9
 *   INTRO_MSG_Create 0x021BF0A0 thumb ov204
 *   INTRO_MSG_Delete 0x021BF1A4 thumb ov204
 *   INTRO_MSG_SetMsgBank 0x021BF204 thumb ov204
 *   INTRO_MSG_Main 0x021BF228 thumb ov204
 *   INTRO_MSG_PrintText 0x021BF23C thumb ov204
 *   INTRO_MSG_DrawWindowBorder 0x021BF2D4 thumb ov204
 *   INTRO_MSG_GetPrintState 0x021BF2E0 thumb ov204
 *   INTRO_MSG_UpdatePrint 0x021BF2F4 thumb ov204
 *   INTRO_MSG_GetWordSet 0x021BF55C thumb ov204
 *   INTRO_MSG_StartTimeIcon 0x021BF560 thumb ov204
 *   INTRO_MSG_DeleteTimeIcon 0x021BF580 thumb ov204
 *   INTRO_MCSS_AddSlot 0x021BF624 thumb ov204
 */
#include "../../matched/include/Obj25350.h"
#include "../../matched/include/Obj14608.h"
#include "../../matched/include/Obj25352.h"
#include "../../matched/include/Obj10874.h"
#include "../../matched/include/Obj25353.h"
#include "../../matched/include/Obj25354.h"
#include "../../matched/include/Obj25355.h"
#include "../../matched/include/Obj25357.h"
#include "../../matched/include/Obj25359.h"
#include "../../matched/include/Obj04609.h"
#include "../../matched/include/Obj05529.h"
#include "../../matched/include/Obj25360.h"
#include "../../matched/include/Obj14612.h"
#include "../../matched/include/Obj25361.h"
#include "../../matched/include/Obj25362.h"
#include "../../matched/include/Obj05530.h"
#include "../../matched/include/Obj25363.h"
#include "../../matched/include/Obj25365.h"
#include "../../matched/include/Obj25366.h"
#include "../../matched/include/Obj08382.h"
#include "../../matched/include/Obj25369.h"
#include "../../matched/include/Obj25370.h"
#include "../../matched/include/Obj25372.h"
#include "../../matched/include/Obj25374.h"
#include "../../matched/include/Obj03920.h"
#include "../../matched/include/Obj25376.h"
#include "../../matched/include/Obj00550.h"
#include "../../matched/include/Obj06672.h"
#include "../../matched/include/Obj08383.h"
#include "../../matched/include/Obj14616.h"
#include "../../matched/include/Obj14617.h"
#include "../../matched/include/Obj25378.h"
#include "../../matched/include/Obj14618.h"
#include "../../matched/include/Obj03921.h"
#include "../../matched/include/Obj25381.h"
#include "../../matched/include/Obj25382.h"
#include "../../matched/include/Obj06673.h"
#include "../../matched/include/Obj14620.h"
#include "intro_types.h"

struct Sub0200852CObj;

struct Actor;

struct Q021BF00C;

struct S021BF00C;

struct State;

typedef signed short   s16;

typedef enum { B_FALSE, B_TRUE } Bool;

struct S { u8 pad[0xA8]; u8 data[4096]; };

typedef struct {u16 v[12];} Init;

typedef struct Row { unsigned tag; unsigned data[5]; } Row;

struct S021BF00C
{
    char pad[0x20];
    void *slots[8];
};

struct Q021BF00C
{
    char pad[0x14];
    unsigned char b : 1;
};

typedef struct Command { unsigned tag; unsigned data[5]; } Command;

typedef struct State { char pad[0x20]; Command *commands[8]; Slot slots[8]; } State;

extern void FADE_Start(unsigned,int,int,int);

extern int FADE_IsActive(void);

extern void BRIGHTNESS_Set(u32 a0, u32 a1, u32 mask);

extern void BRIGHTNESS_ChangeRequest(int, int, int, int, int);

extern int BRIGHTNESS_IsFinished(int a);

extern void GFL_USE_CancelChangeAndPlayBgm(u32, u32);

extern int GFL_USE_IsBgmPlaying(void);

extern void GFL_USE_FadeOutBgm(u32 a);

extern void GFL_USE_FadeInBgmFull(u32 a);

extern void GFL_USE_PlaySeDefaultVolume(unsigned),GFL_USE_SetSeSlotVolume(int,unsigned),GFL_USE_SetSeSlotParams(int,unsigned,unsigned,unsigned);

extern int GFL_USE_GetSeSlot(unsigned);

extern void GFL_USE_StopSeSlot(int);

extern int TOUCHPANEL_GetTrg(void);

extern u32 KEY_GetTrg(void);

extern void INTRO_G3D_AddPokemonSlot(char *p, unsigned int a, unsigned int b, unsigned int c, unsigned int species, unsigned char i);

extern void INTRO_G3D_SetSlotMepachi(u8 *p, u8 index, int flag);

extern void INTRO_G3D_SetVanishFlag(u8 *p, int flag, u8 index);

extern void INTRO_G3D_SetSlotAnim(char *p, unsigned int i, unsigned int flag, unsigned int v);

extern unsigned INTRO_G3D_GetSlotAnimFinished(char *,unsigned char);

extern void INTRO_G3D_ClearSlotAnimFinished(u8 *p, u8 index);

extern int INTRO_G3D_MoveSlot(char *p, unsigned int i, int step, int limit);

extern void INTRO_G3D_SetSlotAlpha(u8 *p, u8 index, u32 alpha);

extern void SAVE_CONTROL_INTR_Start(int);

extern void SAVE_CONTROL_INTR_Pause(unsigned char *);

extern int SAVE_CONTROL_INTR_IsPausedOrFinished(unsigned char *);

extern void SAVE_CONTROL_INTR_Resume(unsigned char *p);

extern void SAVE_CONTROL_INTR_NoOp(int);

extern int SAVE_CONTROL_INTR_IsFinished(unsigned char *p);

extern void CONFIG_SetAppliedFlag(u16*,u32);

extern void func_0200854C(struct Sub0200852CObj*,u32);

extern void GFL_USE_PlaySeDefaultVolume(u32);

extern int  GFL_USE_IsAnySeBusy(void);

extern int PM_VOICE_Start(u32 idx);

extern u32 PM_VOICE_IsSlotActive(u32 i);

extern int INTRO_G3D_MoveSlot1(char *p, int delta, int limit);

extern void func_0207D63C(volatile void *, int, int, int, int);

extern void INTRO_PARTICLE_StartEffect(u32*,u32,u32,u32);

extern void INTRO_G3D_SetVisible(char *p, int v);

extern void INTRO_G3D_SetAnimFrame(char *p, unsigned value);

extern int INTRO_G3D_UpdateIntro(char*);

extern void INTRO_G3D_SetAnimMode(char *,u32);

extern int INTRO_G3D_UpdateAnimMode(char *);

extern int INTRO_G3D_UpdateAnimFrame(int *p);

extern void BG_SYS_DrawTileSub(u32,u32,u32,u32,u8,u32,u8,u8,u8,u8);

extern void func_02040588(unsigned char which, unsigned char enable);

extern void func_02041B6C(u32);

extern void BG_SYS_SetTileEntry(u32,int,int,int,u8,u8,u8);

extern void *func_020490F4(u32 id, u32 heap);

extern u8 func_02008550(const struct Sub0200852CObj *obj);

extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);

extern s32 CLACT_RegisterPalette(void *a, u32 b, u32 c, u32 d, u16 g);

extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);

extern void ARC_TOOL_DeleteHandle(void *);

extern unsigned func_021BDD78(char *p);

extern struct Obj *CLACT_CreateActor(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);

extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);

extern void CLACT_ReleaseCharacter(unsigned);

extern void CLACT_ReleasePalette(unsigned);

extern void CLACT_ReleaseCellAnim(unsigned);

extern void CLACT_DeleteActor(struct Obj *p);

extern void CLACT_SetActorObjMode(struct Actor *actor, u32 value);

extern u32 CLACT_GetActorObjMode(const struct Actor *actor);

extern void WORDSET_SetSlotMyStatus(struct WordSet*,u32,void*);

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *sitePath, u16 tag);

extern u32 func_020307B0(void *p);

int func_021BE328(char *p,int *state,int *q);

u32 func_021BE360(u32 a, u32 b, u32 *c);

int func_021BE374(int a0, int a1, int *src);

int func_021BE398(void);

u32 func_021BE3A4(u32 a, u32 b, u32 *c);

u32 func_021BE3B8(void);

int func_021BE3CC(int a, int b, int *p);

int func_021BE3DC(int a, int b, int *p);

int func_021BE3EC(char *p,int *state,unsigned *q);

int func_021BE420(int a, int b, int *p);

u32 func_021BE430(void);

int func_021BE44C(char *p,int *state,unsigned *q);

int func_021BE460(char *p,int *state,int *q);

int func_021BE478(char *p,int *state,unsigned *q);

int func_021BE4AC(char *p,int *state,int *q);

int func_021BE4B8(char *p, int unused, unsigned *q);

int func_021BE510(char *p,int *state,int *q);

int func_021BE524(char *p,int *state,unsigned *q);

unsigned func_021BE53C(char *p,int *state,unsigned *q);

int func_021BE54C(char *p,int *state,unsigned *q);

int func_021BE560(char *p,int *state,int *q);

int func_021BE578(char *p, int *state, unsigned *q);

int func_021BE61C(char *p, int *state, unsigned *q);

int func_021BE6A4(char *a);

int func_021BE6B4(char *p,int *state,unsigned *q);

int func_021BE6E8(char *a);

int func_021BE6F8(char *a);

int func_021BE708(char *p, int *state);

int func_021BE770(u8*p,u32 unused,u32*q);

int func_021BE78C(u8*p,u32 unused,u32*q);

int func_021BE7A8(u8 *p, u32 *q);

int func_021BE838(u8*p,u32 unused,u32*q);

int func_021BE864(char *a, int b, int *p);

int func_021BE874(char *a, int b, int *p);

int func_021BE884(u8*p);

int func_021BE898(char *p,u32 *q);

int func_021BE970(u8*p);

int func_021BE984(struct S *p,u32 *q);

int func_021BEB00(void *p,u32 *q);

int func_021BEBEC(char *p);

int func_021BED6C(char *p);

int func_021BEDB8(char *p, unsigned *state, unsigned *q);

int func_021BEE5C(char *p, unsigned *state, unsigned *q);

int func_021BEEF0(u8*p);

void func_021BEF08(u8*p,u32 a);

char *func_021BEF20(void *a, unsigned b, unsigned c, char *d, unsigned e, unsigned short heap);

void func_021BEF74(u8*p);

int func_021BEF88(char *p);

int func_021BF00C(struct S021BF00C *p, struct Q021BF00C *q);

int func_021BF030(State *p);

void func_021BF080(char *p, u8 i);

Row *func_021BF094(u32 n);

char *INTRO_MSG_Create(u16 heap);

void INTRO_MSG_Delete(char *p);

void INTRO_MSG_SetMsgBank(char *p, unsigned a, unsigned short b);

void INTRO_MSG_Main(u8*p);

void INTRO_MSG_PrintText(char *p, void *a, int flag);

void INTRO_MSG_DrawWindowBorder(u8*p);

u32 INTRO_MSG_GetPrintState(u8*p);

int INTRO_MSG_UpdatePrint(char *a);

int INTRO_MSG_GetWordSet(u8 *p);

void INTRO_MSG_StartTimeIcon(u8 *p);

void INTRO_MSG_DeleteTimeIcon(u8 *p);

void INTRO_MCSS_AddSlot(char *p, unsigned int a, unsigned int b, unsigned int c, void *d, unsigned char i);

extern const char d_021BFFE4[];

extern const Init init;

extern const char d_021C0AAC[];

extern const u32 d_021C0AB8[];

int func_021BE328(char *p,int *state,int *q){switch(*state){case 0:FADE_Start(q[0],q[1],q[2],q[3]);(*state)++;break;case 1:if(FADE_IsActive()==0)return 1;break;}return 0;}

/*
 * Addresses are Black-image addresses.
 */
u32 func_021BE360(u32 a, u32 b, u32 *c)
{
    BRIGHTNESS_Set((s16)*c, 0x1d, 1);
    return 1;
}

int func_021BE374(int a0, int a1, int *src)
{
    BRIGHTNESS_ChangeRequest((unsigned char)src[0], (short)src[1], (short)src[2], 0x1d, 1);
    return 1;
}

int func_021BE398(void) {BRIGHTNESS_IsFinished(1);return 1;}

u32 func_021BE3A4(u32 a, u32 b, u32 *c)
{
    GFL_USE_CancelChangeAndPlayBgm(*c, 0xffff);
    return 1;
}

u32 func_021BE3B8(void)
{
    if (GFL_USE_IsBgmPlaying() != 0) {
        return 1;
    }
    return 0;
}

int func_021BE3CC(int a, int b, int *p)
{
    GFL_USE_FadeOutBgm((unsigned short)*p);
    return 1;
}

int func_021BE3DC(int a, int b, int *p)
{
    GFL_USE_FadeInBgmFull((unsigned short)*p);
    return 1;
}

int func_021BE3EC(char *p,int *state,unsigned *q){int i;GFL_USE_PlaySeDefaultVolume(q[0]);i=GFL_USE_GetSeSlot(q[0]);if(q[1])GFL_USE_SetSeSlotVolume(i,q[1]);if(q[2])GFL_USE_SetSeSlotParams(i,-1,-1,q[2]);return 1;}

int func_021BE420(int a, int b, int *p)
{
    GFL_USE_StopSeSlot(GFL_USE_GetSeSlot(*p));
    return 1;
}

u32 func_021BE430(void)
{
    if (TOUCHPANEL_GetTrg() != 0 || KEY_GetTrg() != 0) {
        return 1;
    }
    return 0;
}

int func_021BE44C(char *p,int *state,unsigned *q){INTRO_MSG_SetMsgBank(*(char * *)&((struct Obj25350 *)p)->f18,q[0],q[1]);return 1;}

extern int (*const d_021C09D4[])(char *,int);

int func_021BE460(char *p,int *state,int *q){d_021C09D4[q[0]](p,q[1]);return 1;}

int func_021BE478(char *p,int *state,unsigned *q){switch(*state){case 0:INTRO_MSG_PrintText(*(char * *)&((struct Obj14608 *)p)->f18,(void *)q[0],q[1]);(*state)++;break;case 1:if(INTRO_MSG_UpdatePrint(*(char * *)&((struct Obj14608 *)p)->f18))return 1;break;}return 0;}

int func_021BE4AC(char *p,int *state,int *q){INTRO_MSG_DrawWindowBorder((u8 *)(*(char * *)&((struct Obj25352 *)p)->f18));return 1;}

int func_021BE4B8(char *p, int unused, unsigned *q)
{
    if (q[1] == 0) {
        INTRO_MCSS_AddSlot(((struct Obj10874 *)p)->f8, q[2], q[3], 0, (void *)d_021BFFE4, q[0]);
        INTRO_G3D_SetSlotMepachi(((struct Obj10874 *)p)->f8, q[0], 1);
    } else {
        INTRO_G3D_AddPokemonSlot(((struct Obj10874 *)p)->f8, q[2], q[3], 0x1000, q[1], q[0]);
    }
    return 1;
}

int func_021BE510(char *p,int *state,int *q){INTRO_G3D_SetVanishFlag(((struct Obj25353 *)p)->f8,q[1],q[0]);return 1;}

/*
 * follower: tail-call stub 0x021BE53C included; function_starts seed.
 */
int func_021BE524(char *p,int *state,unsigned *q){INTRO_G3D_SetSlotAnim(*(char * *)&((struct Obj25354 *)p)->f8,(unsigned char)q[0],q[1],q[2]);return 1;}

unsigned func_021BE53C(char *p,int *state,unsigned *q){return INTRO_G3D_GetSlotAnimFinished(*(char * *)&((struct Obj25355 *)p)->f8,q[0]);}

int func_021BE54C(char *p,int *state,unsigned *q){INTRO_G3D_ClearSlotAnimFinished((u8 *)(*(char * *)&((struct Obj25357 *)p)->f8),q[0]);return 1;}

int func_021BE560(char *p,int *state,int *q){return INTRO_G3D_MoveSlot(*(char * *)&((struct Obj25359 *)p)->f8,(unsigned char)q[0],q[1],q[2]);}

int func_021BE578(char *p, int *state, unsigned *q)
{
    switch (*state) {
    case 0:
        if (q[1] != 0)
            INTRO_G3D_SetSlotAlpha(((struct Obj04609 *)p)->f8, q[0], (unsigned char)1);
        else
            INTRO_G3D_SetSlotAlpha(((struct Obj04609 *)p)->f8, q[0], (unsigned char)31);
        INTRO_G3D_SetVanishFlag(((struct Obj04609 *)p)->f8, 1, q[0]);
        state[1] = 31;
        ++*state;
        break;
    case 1:
        state[1] -= 2;
        if (state[1] <= 0) {
            INTRO_G3D_SetSlotAlpha(((struct Obj04609 *)p)->f8, q[0], (unsigned char)31);
            INTRO_G3D_SetVanishFlag(((struct Obj04609 *)p)->f8, q[1], q[0]);
            return 1;
        }
        if (q[1] == 1)
            INTRO_G3D_SetSlotAlpha(((struct Obj04609 *)p)->f8, q[0], (unsigned char)(31 - state[1]));
        else if (q[1] == 0)
            INTRO_G3D_SetSlotAlpha(((struct Obj04609 *)p)->f8, q[0], (unsigned char)state[1]);
        break;
    }
    return 0;
}

int func_021BE61C(char *p, int *state, unsigned *q)
{
    unsigned index = q[0];
    unsigned other = q[1];
    switch (*state) {
    case 0:
        INTRO_MSG_PrintText(((struct Obj05529 *)p)->f18, (void *)index, q[2]);
        ++*state;
        break;
    case 1:
        if (INTRO_MSG_UpdatePrint(((struct Obj05529 *)p)->f18) != 0) {
            INTRO_G3D_SetSlotMepachi(((struct Obj05529 *)p)->f8, other, 1);
            return 1;
        }
        switch (INTRO_MSG_GetPrintState(((struct Obj05529 *)p)->f18)) {
        case 1:
            INTRO_G3D_SetSlotMepachi(((struct Obj05529 *)p)->f8, other, 1);
            state[1] = 0;
            break;
        case 0:
            INTRO_G3D_SetSlotMepachi(((struct Obj05529 *)p)->f8, other, state[1] % 12 < 6 ? 1 : 0);
            state[1]++;
            break;
        case 2:
            break;
        }
        break;
    }
    return 0;
}

int func_021BE6A4(char *a)
{
    SAVE_CONTROL_INTR_Start(((struct Obj25360 *)a)->fA4);
    return 1;
}

int func_021BE6B4(char *p,int *state,unsigned *q){switch(*state){case 0:SAVE_CONTROL_INTR_Pause(*(unsigned char * *)&((struct Obj14612 *)p)->fA4);(*state)++;break;case 1:if(SAVE_CONTROL_INTR_IsPausedOrFinished(*(unsigned char * *)&((struct Obj14612 *)p)->fA4)==1)return 1;break;}return 0;}

int func_021BE6E8(char *a)
{
    SAVE_CONTROL_INTR_Resume((unsigned char *)(((struct Obj25361 *)a)->fA4));
    return 1;
}

/*
 * UNBLOCKED: 0x021BD39C is now an EXACT entry in layout/matched/ov088 (the
 * only overlay in the window that does not overlap the caller's ov204), so
 * the bl gIntroSite resolves as matched and the verdict promoted to EXACT.
 */
int func_021BE6F8(char *a)
{
    SAVE_CONTROL_INTR_NoOp(((struct Obj25362 *)a)->fA4);
    return 1;
}

int func_021BE708(char *p, int *state)
{
    switch (*state) {
    case 0:
        if (SAVE_CONTROL_INTR_IsFinished(((struct Obj05530 *)p)->fA4) == 1)
            return 1;
        INTRO_MSG_PrintText(((struct Obj05530 *)p)->f18, (void *)5, 0);
        ++*state;
        break;
    case 1:
        if (INTRO_MSG_UpdatePrint(((struct Obj05530 *)p)->f18) == 1) {
            INTRO_MSG_StartTimeIcon(((struct Obj05530 *)p)->f18);
            ++*state;
        }
        break;
    case 2:
        if (SAVE_CONTROL_INTR_IsFinished(((struct Obj05530 *)p)->fA4) == 1) {
            INTRO_MSG_DeleteTimeIcon(((struct Obj05530 *)p)->f18);
            return 1;
        }
        break;
    }
    return 0;
}

int func_021BE770(u8*p,u32 unused,u32*q){u16*obj=*(u16* *)&((struct Obj25365 *)(*(u8* *)&((struct Obj25363 *)p)->f4))->f4;Bool flag;if(*q==0)flag=B_FALSE;else flag=B_TRUE;CONFIG_SetAppliedFlag(obj,flag);return 1;}

/*
 * prototype: 0200854C widened to u32: original has no byte truncation; its u8 prototype added a shift pair.
 */
int func_021BE78C(u8*p,u32 unused,u32*q){struct Sub0200852CObj*obj=**(struct Sub0200852CObj** *)&((struct Obj25366 *)p)->f4;Bool flag;if(*q==0)flag=B_FALSE;else flag=B_TRUE;func_0200854C(obj,flag);return 1;}

int func_021BE7A8(u8 *p, u32 *q)
{
    switch (*q) {
    case 0:
        if (q[1] == 3) {
            q[1] = 0;
            (*q)++;
        } else {
            q[1] = q[1] + 1;
        }
        break;
    case 1:
        if (INTRO_G3D_MoveSlot1((char *)(((struct Obj08382 *)p)->f8), 0x1000, 0xFFFF4800) == 1) {
            GFL_USE_PlaySeDefaultVolume(0x7F5);
            (*q)++;
        }
        break;
    case 2:
        if (GFL_USE_IsAnySeBusy() == 0) {
            INTRO_G3D_SetSlotAnim((char *)(((struct Obj08382 *)p)->f8), 1, 0, 1);
            PM_VOICE_Start(*(u32 *)(((struct Obj08382 *)p)->f4 + 0x10));
            (*q)++;
        }
        break;
    case 3:
        if (PM_VOICE_IsSlotActive(*(u32 *)(((struct Obj08382 *)p)->f4 + 0x10)) == 0) {
            *q = 0;
            return 1;
        }
        break;
    }
    return 0;
}

int func_021BE838(u8*p,u32 unused,u32*q){func_0207D63C((void*)0x04000050,1,9,0,0);INTRO_PARTICLE_StartEffect(*(u32* *)&((struct Obj25369 *)p)->f10,q[0],q[1],0);return 1;}

int func_021BE864(char *a, int b, int *p)
{
    INTRO_G3D_SetVisible((char *)(((struct Obj25370 *)a)->fC), *p);
    return 1;
}

int func_021BE874(char *a, int b, int *p)
{
    INTRO_G3D_SetAnimFrame((char *)(((struct Obj25372 *)a)->fC), *p);
    return 1;
}

int func_021BE884(u8*p){if(INTRO_G3D_UpdateIntro(*(char* *)&((struct Obj25374 *)p)->fC))return 1;return 0;}

/*
 * lever: load the case-2 object once before q[1]'s comparison and reuse
 *   it in both arms; repeated arm loads gave 220 bytes/80 different.
 */
int func_021BE898(char *p,u32 *q)
{
    void *obj;
    switch (*q) {
    case 0:
        INTRO_G3D_SetAnimMode(*(char * *)&((struct Obj03920 *)p)->fC,0);
        *q=4;
        break;
    case 1:
        if (KEY_GetTrg()&16) {
            if (q[1]!=1) {
                GFL_USE_PlaySeDefaultVolume(0x548);
                INTRO_G3D_SetAnimMode(*(char * *)&((struct Obj03920 *)p)->fC,2);
                q[1]=1;
                *q=4;
            }
        } else if (KEY_GetTrg()&32) {
            if (q[1]!=0) {
                GFL_USE_PlaySeDefaultVolume(0x548);
                INTRO_G3D_SetAnimMode(*(char * *)&((struct Obj03920 *)p)->fC,1);
                q[1]=0;
                *q=4;
            }
        } else if (KEY_GetTrg()&1) {
            GFL_USE_PlaySeDefaultVolume(0x54D);
            (*q)++;
        }
        break;
    case 2:
        obj=**(void ** *)&((struct Obj03920 *)p)->f4;
        if (q[1]==0) {
            func_0200854C(obj,0);
            INTRO_G3D_SetAnimMode(*(char * *)&((struct Obj03920 *)p)->fC,3);
        } else {
            func_0200854C(obj,1);
            INTRO_G3D_SetAnimMode(*(char * *)&((struct Obj03920 *)p)->fC,4);
        }
        (*q)++;
        break;
    case 3:
        if (INTRO_G3D_UpdateAnimMode(*(char * *)&((struct Obj03920 *)p)->fC)!=0) return 1;
        break;
    case 4:
        if (INTRO_G3D_UpdateAnimMode(*(char * *)&((struct Obj03920 *)p)->fC)!=0) *q=1;
        break;
    }
    return 0;
}

int func_021BE970(u8*p){if(INTRO_G3D_UpdateAnimFrame((int *)(*(char* *)&((struct Obj25376 *)p)->fC)))return 1;return 0;}

/*
 * lever: unsigned integer p+0xA8 at the first paired call, member address
 *   at the second, keeps equivalent addresses apart; pointer-only was 364
 *   bytes/275 different, this spelling EXACT380 (existing distinct-arithmetic idiom).
 */
int func_021BE984(struct S *p,u32 *q)
{
    switch (*q) {
    case 0:
        func_02040588(2,1);
        BG_SYS_DrawTileSub(2,0,8,64,2,(u32)p->data,0,8,64,32);
        func_02041B6C(2);
        (*q)++;
        break;
    case 1:
        BG_SYS_DrawTileSub(2,0,7,64,1,(u32)p+0xA8,0,7,64,32);
        BG_SYS_DrawTileSub(2,0,10,64,1,(u32)p->data,0,10,64,32);
        func_02041B6C(2);
        (*q)++;
        break;
    case 2:
        BG_SYS_DrawTileSub(2,0,6,64,1,(u32)p+0xA8,0,6,64,32);
        BG_SYS_DrawTileSub(2,0,11,64,1,(u32)p->data,0,11,64,32);
        func_02041B6C(2);
        (*q)++;
        break;
    case 3:
        BG_SYS_DrawTileSub(2,0,5,64,1,(u32)p+0xA8,0,5,64,32);
        BG_SYS_DrawTileSub(2,0,12,64,1,(u32)p->data,0,12,64,32);
        func_02041B6C(2);
        (*q)++;
        break;
    case 4:
        BG_SYS_DrawTileSub(2,0,4,64,1,(u32)p+0xA8,0,4,64,32);
        BG_SYS_DrawTileSub(2,0,13,64,1,(u32)p->data,0,13,64,32);
        func_02041B6C(2);
        *q=0;
        return 1;
    }
    return 0;
}

/*
 * extent: two bytes of zero alignment at 0x021BEBEA.
 */
int func_021BEB00(void *p,u32 *q)
{
    switch (*q) {
    case 0:
        BG_SYS_SetTileEntry(2,0,0,7,64,1,0);
        BG_SYS_SetTileEntry(2,0,0,16,64,1,0);
        func_02041B6C(2);
        (*q)++;
        break;
    case 1:
        BG_SYS_SetTileEntry(2,0,0,8,64,1,0);
        BG_SYS_SetTileEntry(2,0,0,15,64,1,0);
        func_02041B6C(2);
        (*q)++;
        break;
    case 2:
        BG_SYS_SetTileEntry(2,0,0,6,64,1,0);
        BG_SYS_SetTileEntry(2,0,0,14,64,1,0);
        func_02041B6C(2);
        (*q)++;
        break;
    case 3:
        BG_SYS_SetTileEntry(2,0,0,5,64,1,0);
        BG_SYS_SetTileEntry(2,0,0,13,64,1,0);
        func_02041B6C(2);
        (*q)++;
        break;
    case 4:
        func_02040588(2,0);
        *q=0;
        return 1;
    }
    return 0;
}

int func_021BEBEC(char *p)
{
    Init local;
    void *arc;
    u32 i;
    char *row;
    arc=func_020490F4(170,((struct Obj00550 *)p)->f0);
    if(func_02008550(**(void ** *)&((struct Obj00550 *)p)->f4)==0){
        ((struct Obj00550 *)p)->f10B4=(void *)CLACT_RegisterCharacter(arc,6,0,0,((struct Obj00550 *)p)->f0);
        ((struct Obj00550 *)p)->f10C0=(void *)CLACT_RegisterPalette(arc,7,0,0,((struct Obj00550 *)p)->f0);
        ((struct Obj00550 *)p)->f10CC=(void *)CLACT_RegisterCellAnim(arc,5,4,((struct Obj00550 *)p)->f0);
    }else{
        ((struct Obj00550 *)p)->f10B4=(void *)CLACT_RegisterCharacter(arc,10,0,0,((struct Obj00550 *)p)->f0);
        ((struct Obj00550 *)p)->f10C0=(void *)CLACT_RegisterPalette(arc,11,0,0,((struct Obj00550 *)p)->f0);
        ((struct Obj00550 *)p)->f10CC=(void *)CLACT_RegisterCellAnim(arc,9,8,((struct Obj00550 *)p)->f0);
    }
    ((struct Obj00550 *)p)->f10B8=(void *)CLACT_RegisterCharacter(arc,17,0,0,((struct Obj00550 *)p)->f0);
    ((struct Obj00550 *)p)->f10C4=(void *)CLACT_RegisterPalette(arc,18,0,32,((struct Obj00550 *)p)->f0);
    ((struct Obj00550 *)p)->f10D0=(void *)CLACT_RegisterCellAnim(arc,16,15,((struct Obj00550 *)p)->f0);
    ((struct Obj00550 *)p)->f10BC=(void *)CLACT_RegisterCharacter(arc,21,0,0,((struct Obj00550 *)p)->f0);
    ((struct Obj00550 *)p)->f10C8=(void *)CLACT_RegisterPalette(arc,22,0,64,((struct Obj00550 *)p)->f0);
    ((struct Obj00550 *)p)->f10D4=(void *)CLACT_RegisterCellAnim(arc,20,19,((struct Obj00550 *)p)->f0);
    ARC_TOOL_DeleteHandle(arc);
    local=init;
    for(i=0;i<3;i++){
        row=p+i*4;
        ((struct Obj06672 *)row)->f10A8=CLACT_CreateActor((void *)func_021BDD78(((struct Obj00550 *)p)->f14),(unsigned int)((struct Obj06672 *)row)->f10B4,(unsigned int)((struct Obj06672 *)row)->f10C0,(unsigned int)((struct Obj06672 *)row)->f10CC,(char *)&local+i*8,0,((struct Obj00550 *)p)->f0);
        CLACT_SetActorDrawEnable(((struct Obj06672 *)row)->f10A8,0);
    }
    return 1;
}

int func_021BED6C(char *p)
{
    unsigned i;
    for (i = 0; i < 3; i++) {
        char *q = p + i * 4;
        CLACT_ReleaseCharacter(((struct Obj08383 *)q)->f10B4);
        CLACT_ReleasePalette(((struct Obj08383 *)q)->f10C0);
        CLACT_ReleaseCellAnim(((struct Obj08383 *)q)->f10CC);
        CLACT_DeleteActor(((struct Obj08383 *)q)->f10A8);
    }
    return 1;
}

static inline void change_alpha(int a, int b)
{
    *(volatile unsigned short *)0x04000052 = (unsigned short)(a | (b << 8));
}

int func_021BEDB8(char *p, unsigned *state, unsigned *q)
{
    unsigned i;
    switch (*state) {
    case 0:
        func_0207D63C((volatile void *)0x04000050, 0, 12, 0, 16);
        CLACT_SetActorObjMode(*(void **)(p + 0x10a8 + q[0] * 4), 1);
        CLACT_SetActorDrawEnable(*(void **)(p + 0x10a8 + q[0] * 4), 1);
        ++*state;
        break;
    case 16:
        for (i = 0; i < 3; i++) {
            char *row = p + i * 4;
            if (CLACT_GetActorObjMode(((struct Obj14616 *)row)->f10A8) == 1)
                CLACT_SetActorObjMode(((struct Obj14616 *)row)->f10A8, 0);
        }
        *state = 0;
        return 1;
    default:
        ++*state;
        change_alpha(*state, 16 - *state);
        break;
    }
    return 0;
}

/*
 * volatile: hardware BLDALPHA write at 021BEEDC.
 */
int func_021BEE5C(char *p, unsigned *state, unsigned *q)
{
    unsigned i;
    switch (*state) {
    case 0:
        func_0207D63C((volatile void *)0x04000050, 0, 12, 16, 0);
        for (i = 0; i < 3; i++)
            CLACT_SetActorObjMode(*(void **)(p + 0x10a8 + i * 4), 1);
        ++*state;
        break;
    case 16:
        for (i = 0; i < 3; i++) {
            char *row = p + i * 4;
            CLACT_SetActorObjMode(((struct Obj14617 *)row)->f10A8, 0);
            CLACT_SetActorDrawEnable(((struct Obj14617 *)row)->f10A8, 0);
        }
        *state = 0;
        return 1;
    default:
        ++*state;
        change_alpha(16 - *state, *state);
        break;
    }
    return 0;
}

int func_021BEEF0(u8*p){if(!func_02008550(**(struct Sub0200852CObj** *)&((struct Obj25378 *)p)->f4))return 1;return 0;}

void func_021BEF08(u8*p,u32 a){struct WordSet*q=(struct WordSet *)INTRO_MSG_GetWordSet(*(u8* *)&((struct Obj14618 *)p)->f18);WORDSET_SetSlotMyStatus(q,a,**(void** *)&((struct Obj14618 *)p)->f4);}

char *func_021BEF20(void *a, unsigned b, unsigned c, char *d, unsigned e, unsigned short heap)
{
    char *p = func_02030734(heap, 0x10d8, 1, d_021C0AAC, 0x6f2);
    ((struct Obj03921 *)p)->f0 = heap;
    *(char * *)&((struct Obj03921 *)p)->f4 = d;
    ((struct Obj03921 *)p)->f8 = c;
    ((struct Obj03921 *)p)->fC = a;
    ((struct Obj03921 *)p)->f10 = b;
    ((struct Obj03921 *)p)->f14 = e;
    ((struct Obj03921 *)p)->fA4 = ((struct Obj25381 *)d)->fC;
    ((struct Obj03921 *)p)->f18 = INTRO_MSG_Create(heap);
    return p;
}

void func_021BEF74(u8*p){INTRO_MSG_Delete(*(char* *)&((struct Obj25382 *)p)->f18);func_020307B0(p);}

extern int (*const d_021C09D8[])(void *, void *, void *);

int func_021BEF88(char *p)
{
    INTRO_MSG_Main(((struct Obj06673 *)p)->f18);
    if (func_021BF030((struct State *)p) == 0) {
        char *base = p;
        int i;
        base += 0x40;
        for (i = 0; i < 9; i++) {
            Row *row = func_021BF094(((struct Obj06673 *)p)->f1C) + ((struct Obj06673 *)p)->fA0;
            if (row->tag == 1) {
                d_021C09D8[row->tag](p, base + i * 12, row->data);
                row = func_021BF094(((struct Obj06673 *)p)->f1C);
            }
            if (row->tag == 0x34)
                return 0;
            ++((struct Obj06673 *)p)->fA0;
            if (!func_021BF00C((struct S021BF00C *)p, (struct Q021BF00C *)row))
                break;
        }
    }
    return 1;
}

int func_021BF00C(struct S021BF00C *p, struct Q021BF00C *q)
{
    int i;
    for (i = 0; i < 8; i++)
    {
        if (p->slots[i] == 0)
        {
            p->slots[i] = q;
            break;
        }
    }
    return q->b;
}

extern int (*const d_021C09D8[])(void *, void *, void *);

int func_021BF030(State *p)
{
    int result = 0;
    int i;
    for (i = 0; i < 8; i++) {
        Command *q = p->commands[i];
        if (q) {
            if (!d_021C09D8[q->tag](p, &p->slots[i], q->data)) result = 1;
            else func_021BF080((char *)p, i);
        }
    }
    return result;
}

void func_021BF080(char *p, u8 i)
{
    char *q;

    *(int *)(p + i * 4 + 0x20) = 0;
    q = p + i * 0xC;
    ((struct Obj14620 *)q)->f40 = 0;
    ((struct Obj14620 *)q)->f44 = 0;
}

Row *func_021BF094(u32 n){return *(Row **)((u32)d_021C0AB8+n*4);}

/*
 * function: POKETRADE_SAVE_RestoreBackups
 * address: 0x021E02E8
 * packet: pkt_ov119_021E02E8
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   func_02008FEC 0x02008FEC thumb
 *   func_02008FFC 0x02008FFC thumb
 *   MI_CpuCopy8 0x02082D44 arm
 *   func_020307B0 0x020307B0 arm
 *   GAME_DATA_GetTrainerRecord 0x02012F2C thumb
 *   func_02008C20 0x02008C20 thumb
 *   POKETRADE_SAVE_RestoreSaveControl 0x021E017C thumb ov119
 *   POKETRADE_SAVE_RestoreZukan 0x021E01E0 thumb ov119
 *   POKETRADE_SAVE_RestoreBlock1F 0x021E0240 thumb ov119
 *   POKEPARTY_Copy 0x0201AC2C thumb
 *   GAME_DATA_GetPlayTime 0x02012FCC thumb
 *   func_020086F8 0x020086F8 thumb
 *   func_02007AEC 0x02007AEC thumb
 *   func_02007AF4 0x02007AF4 thumb
 *   GAME_DATA_GetPerapVoiceSave 0x02012F98 thumb
 *   func_02007B5C 0x02007B5C thumb
 *   MI_CpuFill8 0x02082BCC arm
 */
#include "../include/Obj00589.h"
#include "../include/Obj22755.h"
typedef unsigned int u32;
typedef unsigned short u16;
struct Big;
struct PerapVoice;
struct PlayTime;
struct PlayTimeStamp;
struct Rec534;
struct Sub02007AC8Entry;
struct Sub02008F80Obj;
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern struct Sub02008F80Obj *func_02008FEC(void *sys);
extern void *GAME_DATA_GetTrainerRecord(int *p);
extern int GAME_DATA_GetPlayTime(int p0);
extern struct Sub02007AC8Entry *func_02007AF4(void **save, u32 box);
extern struct Sub02007AC8Entry *GAME_DATA_GetPerapVoiceSave(void *p);
extern u32 func_02008FFC(void);
extern u32 func_02008C20(void);
extern u32 func_02007AEC(void);
extern void MI_CpuCopy8(const void *,void *,u32);
extern u32 func_020307B0(void *p);
extern void POKETRADE_SAVE_RestoreSaveControl(void *,void *);
extern void POKETRADE_SAVE_RestoreZukan(void *,void *);
extern void POKETRADE_SAVE_RestoreBlock1F(void **h, void *dst);
extern void POKEPARTY_Copy(const struct Rec534 *src, struct Rec534 *dst);
extern void func_020086F8(struct PlayTime *p, const struct PlayTimeStamp *in);
extern void func_02007B5C(struct PerapVoice *p);
extern void MI_CpuFill8(void *,int,u32);
void POKETRADE_SAVE_RestoreBackups(char *p)
{
    void *dest,*src;
    u32 n;
    dest=((struct Obj00589 *)p)->f60C;
    if(dest) {
        src=((struct Obj00589 *)p)->f82C;
        GAME_DATA_GetSaveControl(src);
        src=func_02008FEC(src);
        n=func_02008FFC();
        MI_CpuCopy8(dest,src,n);
        func_020307B0(dest);
    }
    dest=((struct Obj00589 *)p)->f610;
    if(dest) {
        src=GAME_DATA_GetTrainerRecord(((struct Obj00589 *)p)->f82C);
        n=func_02008C20();
        MI_CpuCopy8(dest,src,n);
        func_020307B0(dest);
    }
    if(((struct Obj00589 *)p)->f614) POKETRADE_SAVE_RestoreSaveControl(((struct Obj00589 *)p)->f82C,((struct Obj00589 *)p)->f614);
    if(((struct Obj00589 *)p)->f618) POKETRADE_SAVE_RestoreZukan(((struct Obj00589 *)p)->f82C,((struct Obj00589 *)p)->f618);
    if(((struct Obj00589 *)p)->f61C) POKETRADE_SAVE_RestoreBlock1F(((struct Obj00589 *)p)->f82C,((struct Obj00589 *)p)->f61C);
    if(((struct Obj00589 *)p)->f620) {
        POKEPARTY_Copy(((struct Obj00589 *)p)->f620,((struct Obj00589 *)p)->f838);
        func_020086F8((void *)GAME_DATA_GetPlayTime((int)(((struct Obj00589 *)p)->f82C)),(const struct PlayTimeStamp *)(p+0x628));
        func_020307B0(((struct Obj00589 *)p)->f620);
        *(int *)&((struct Obj00589 *)p)->f620=0;
    }
    if(((struct Obj00589 *)p)->f624) {
        n=func_02007AEC();
        src=func_02007AF4(((struct Obj00589 *)p)->f828,((struct Obj22755 *)(*(char * *)&((struct Obj00589 *)p)->f8))->f28);
        MI_CpuCopy8(((struct Obj00589 *)p)->f624,src,n);
        func_020307B0(((struct Obj00589 *)p)->f624);
    }
    if(((struct Obj00589 *)p)->f62C) func_02007B5C((struct PerapVoice *)GAME_DATA_GetPerapVoiceSave(((struct Obj00589 *)p)->f82C));
    MI_CpuFill8(p+0x60c,0,0x24);
}

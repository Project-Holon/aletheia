/*
 * file:     br_codein_rec.c
 * unit:     yes
 * function: BR_CODEIN_ShowMenuText, BR_CODEIN_HideMenuText, BR_CODEIN_GetMenuCallbacks, BR_CODEIN_CreateMenuButtons, BR_CODEIN_DeleteMenuButtons, BR_CODEIN_HitTestOptionLeft, BR_CODEIN_HitTestOptionRight
 * address:  0x021E2FA8
 * region:   ov183
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   BR_UTIL_CreateTextWin 0x021FD12C thumb ov186
 *   BR_UTIL_SetWindowText 0x021FD170 thumb ov186
 *   BR_UTIL_StartEffect 0x021FD860 thumb ov186
 *   BR_UTIL_DeleteTextWin 0x021FD15C thumb ov186
 *   d_021E3910 0x021E3910 data a4
 *   BR_RES_GetFont 0x021FC20C thumb ov186
 *   BR_RES_GetMsgData 0x021FC214 thumb ov186
 *   BR_RES_GetWordSet 0x021FC21C thumb ov186
 *   STRBUF_Create 0x020457B0 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   BR_RES_LoadSprite 0x021FBE54 thumb ov186
 *   BR_RES_GetSprite 0x021FC124 thumb ov186
 *   MSGDATA_ReadString 0x02045CAC arm
 *   WORDSET_SetSlotTag 0x0201EE0C thumb
 *   WORDSET_CopyTaggedText 0x0201F250 thumb
 *   BR_BTN_CreateObject 0x021FB3BC thumb ov186
 *   BR_BTN_CreateFromMessage 0x021FB378 thumb ov186
 *   BATTLE_REC_GetWork 0x0200B910 thumb
 *   GDS_PROFILE_CreateNameStr 0x0200D6D0 thumb
 *   GDS_PROFILE_GetEggFlag 0x0200D6EC thumb
 *   BR_UTIL_SetWindowTextBuf 0x021FD19C thumb ov186
 *   STRBUF_Delete 0x02045808 arm
 *   BR_BTN_DeleteObject 0x021FB494 thumb ov186
 *   BR_RES_ReleaseSprite 0x021FC0C8 thumb ov186
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 */
#include "br_codein_types.h"

struct Pair;
struct PrintSys;
struct U16Vec;
struct RecGet;
struct MsgBank;
struct WordSet;
struct BattleRecSave;
typedef unsigned short u16;

typedef unsigned char u8;

typedef unsigned int u32;

typedef struct { u32 a,b; } Pair;

typedef struct { u32 f0,f4; Pair callbacks; } Table;

typedef struct Desc {short x,y,n;unsigned char flag,pad;} Desc;

typedef struct Triple {int a,b,c;} Triple;

extern void *BR_UTIL_CreateTextWin(void *a, void *owner, u16 heap);
extern void BR_UTIL_SetWindowText(char *p, char *q, void *text);
extern void BR_UTIL_StartEffect(int, int, int *);
extern void BR_UTIL_DeleteTextWin(void *,int);
struct BrRes;
extern unsigned BR_RES_GetFont(struct BrRes *res);
extern int BR_RES_GetMsgData(struct BrRes *res);
extern int BR_RES_GetWordSet(struct BrRes *res);
struct Strbuf;
extern struct Strbuf *STRBUF_Create(u32 capacity, u32 heapId);
extern void MI_CpuFill8(void *,int,unsigned),BR_RES_LoadSprite(char *,unsigned,unsigned);
extern int BR_RES_GetSprite(struct BrRes *res, unsigned int spriteIndex, void *outSprite);
extern void MSGDATA_ReadString(struct MsgBank *bank, unsigned int index, struct Strbuf *dest);
extern void WORDSET_SetSlotTag(struct WordSet *words, unsigned int slot, struct Strbuf *src, unsigned int grammarCase, unsigned int isPlural, unsigned int gender);
extern void WORDSET_CopyTaggedText(struct WordSet *words, struct Strbuf *dst, struct Strbuf *src);
extern void *BR_BTN_CreateObject(void *,void *,int,int,int,int,int,void *,u16);
extern void *BR_BTN_CreateFromMessage(void *ctx, int file, u16 a, int b, int c, void *d, int e, int archive, void *config, u16 heap);
extern struct BattleRecSave *BATTLE_REC_GetWork(void);
extern void *GDS_PROFILE_CreateNameStr(const void *src, u32 tag);
struct StoredMon;
extern u32 GDS_PROFILE_GetEggFlag(struct StoredMon *p);
extern void BR_UTIL_SetWindowTextBuf(char *p, void *q, void *text);
extern void STRBUF_Delete(struct Strbuf *strbuf);
extern void BR_BTN_DeleteObject(char *p);
extern void BR_RES_ReleaseSprite(struct BrRes *res, unsigned int spriteIndex);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
void BR_CODEIN_ShowMenuText(struct CodeinSoclWork *menu);
void BR_CODEIN_HideMenuText(struct CodeinSoclWork *menu);
void BR_CODEIN_GetMenuCallbacks(Pair *out);
void BR_CODEIN_CreateMenuButtons(struct CodeinSoclWork *menu,struct CodeinMenuArg *arg);
void BR_CODEIN_DeleteMenuButtons(struct CodeinSoclWork *menu,struct CodeinMenuArg *arg);
int BR_CODEIN_HitTestOptionLeft(struct CodeinSoclWork *menu, int x, int y);
int BR_CODEIN_HitTestOptionRight(struct CodeinSoclWork *menu, int x, int y);
extern const Table d_021E3910;



void BR_CODEIN_ShowMenuText(struct CodeinSoclWork *menu)
{
    int args[2];
    if (menu->textWin == 0)
        menu->textWin = BR_UTIL_CreateTextWin((void *)(((struct CodeinMenuSub *)menu->arg)->handle), menu->printQue, menu->heapId);
    BR_UTIL_SetWindowText(menu->textWin, (char *)((struct CodeinMenuSub *)menu->arg)->handle, (void *)0x14b);
    args[0] = 0x80;
    args[1] = 0x60;
    BR_UTIL_StartEffect(menu->introFx, 4, args);
}




void BR_CODEIN_HideMenuText(struct CodeinSoclWork *menu) { int zero=0;BR_UTIL_StartEffect(menu->introFx, 0, (int *)0);if(menu->textWin){BR_UTIL_DeleteTextWin(menu->textWin,((struct CodeinMenuSub *)menu->arg)->handle);*(int *)&menu->textWin=zero;} }




void BR_CODEIN_GetMenuCallbacks(Pair *out) {
    *out=d_021E3910.callbacks;
}




void BR_CODEIN_CreateMenuButtons(struct CodeinSoclWork *menu,struct CodeinMenuArg *arg)
{
    Triple t;
    Desc d;
    int h,c;
    void *a,*b,*s,*owner,*tmp;
    int i;
    unsigned offset;
    h=BR_RES_GetFont((struct BrRes *)arg->resource);
    c=BR_RES_GetMsgData((struct BrRes *)arg->resource);
    a=(void *)BR_RES_GetWordSet((struct BrRes *)arg->resource);
    b=STRBUF_Create(0x80,menu->heapId);
    s=STRBUF_Create(0x80,menu->heapId);
    MI_CpuFill8(&d,0,8);
    d.x=0x30;d.y=0x28;d.n=11;d.flag=1;
    BR_RES_LoadSprite((char *)arg->resource,1,menu->heapId);
    BR_RES_GetSprite(arg->resource,1,&t);
    for(i=0;i<3;i++) {
        offset=(i+1)*4;
        if(*(unsigned *)((char *)arg->entries+offset)) {
            MSGDATA_ReadString((struct MsgBank *)c,0x1a,s);
            WORDSET_SetSlotTag(a,0,(struct Strbuf *)(*(unsigned *)((char *)arg->entries+offset+0x10)),*(unsigned *)((char *)arg->entries+offset+0x20),1,2);
            WORDSET_CopyTaggedText(a,b,s);
        }else MSGDATA_ReadString((struct MsgBank *)c,9,b);
        menu->button[i]=BR_BTN_CreateObject(&d,b,0xa0,1,arg->windowKind,(int)menu->oamSys,h,&t,menu->heapId);
        d.y=d.y+0x28;
    }
    d.n=1;
    menu->button[3]=BR_BTN_CreateFromMessage((void *)(&d),4,0xa0,1,arg->windowKind,menu->oamSys,h,c,&t,menu->heapId);
    owner=BATTLE_REC_GetWork();
    tmp=GDS_PROFILE_CreateNameStr(owner,(u16)((menu->heapId&0x7fff)|0x8000));
    if(!menu->textWin) menu->textWin=BR_UTIL_CreateTextWin(arg->resource,menu->printQue,menu->heapId);
    MSGDATA_ReadString((struct MsgBank *)c,0x5c,s);
    WORDSET_SetSlotTag(a,0,(struct Strbuf *)tmp,GDS_PROFILE_GetEggFlag(owner),1,2);
    WORDSET_CopyTaggedText(a,b,s);
    BR_UTIL_SetWindowTextBuf(menu->textWin,arg->resource,b);
    STRBUF_Delete(tmp);STRBUF_Delete(s);STRBUF_Delete(b);
}




void BR_CODEIN_DeleteMenuButtons(struct CodeinSoclWork *menu,struct CodeinMenuArg *arg) { int i;if(menu->textWin){BR_UTIL_DeleteTextWin(menu->textWin,(int)arg->resource);menu->textWin=0;}for(i=0;i<4;i++){if(menu->button[i]){BR_BTN_DeleteObject(menu->button[i]);menu->button[i]=0;}}BR_RES_ReleaseSprite((struct BrRes *)arg->resource,1); }




int BR_CODEIN_HitTestOptionLeft(struct CodeinSoclWork *menu, int x, int y)
{
    int ok = ((unsigned int)(x - 0x20) <= 0x48) &
             ((unsigned int)(y - 0x30) <= 0x10);
    if (ok) {
        int args[2];
        args[0] = x;
        args[1] = y;
        BR_UTIL_StartEffect(menu->tapFx, 1, args);
        GFL_USE_PlaySeDefaultVolume(0x703);
    }
    return ok;
}




int BR_CODEIN_HitTestOptionRight(struct CodeinSoclWork *menu, int x, int y)
{
    int ok = ((unsigned int)(x - 0x90) <= 0x48) &
             ((unsigned int)(y - 0x30) <= 0x10);

    if (ok) {
        int args[2];

        args[0] = x;
        args[1] = y;
        BR_UTIL_StartEffect(menu->tapFx, 1, args);
        GFL_USE_PlaySeDefaultVolume(0x703);
    }
    return ok;
}

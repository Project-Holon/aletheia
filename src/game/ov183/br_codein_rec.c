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

struct BrCodeinRecPair;
struct PrintSys;
struct U16Vec;
struct RecGet;
struct MsgBank;
struct WordSet;
struct BattleRecSave;
#include "../types.h"

typedef struct BrCodeinRecPair { u32 a,b; } BrCodeinRecPair;

typedef struct { u32 f0,f4; BrCodeinRecPair callbacks; } Table;

#include "../ov186/br_util.h"
struct BrRes;
#include "../ov186/br_res.h"
struct Strbuf;
#include "../arm9/strbuf.h"
extern void MI_CpuFill8(void *,int,unsigned);
#include "../arm9/msgdata.h"
#include "../arm9/wordset.h"
#include "../ov186/br_btn.h"
#include "../arm9/battle_rec.h"
#include "../arm9/gds_profile.h"
struct StoredMon;
#include "../arm9/gfl_use.h"
void BR_CODEIN_ShowMenuText(struct CodeinSoclWork *menu);
void BR_CODEIN_HideMenuText(struct CodeinSoclWork *menu);
void BR_CODEIN_GetMenuCallbacks(BrCodeinRecPair *out);
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
    BR_UTIL_SetWindowText((char *)menu->textWin, (char *)((struct CodeinMenuSub *)menu->arg)->handle, (void *)0x14b);
    args[0] = 0x80;
    args[1] = 0x60;
    BR_UTIL_StartEffect((char *)menu->introFx, 4, (const BrPair *)args);
}

void BR_CODEIN_HideMenuText(struct CodeinSoclWork *menu) { int zero=0;BR_UTIL_StartEffect((char *)menu->introFx, 0, (const BrPair *)((int *)0));if(menu->textWin){BR_UTIL_DeleteTextWin((void *)menu->textWin,((struct CodeinMenuSub *)menu->arg)->handle);*(int *)&menu->textWin=zero;} }

void BR_CODEIN_GetMenuCallbacks(BrCodeinRecPair *out) {
    *out=d_021E3910.callbacks;
}

void BR_CODEIN_CreateMenuButtons(struct CodeinSoclWork *menu,struct CodeinMenuArg *arg)
{
    BrBtnSpriteIds t;
    BrBtnPlacement d;
    sptr h, c;
    void *a,*b,*s,*owner,*tmp;
    int i;
    unsigned offset;
    h=BR_RES_GetFont((struct BrRes *)arg->resource);
    c=BR_RES_GetMsgData((struct BrRes *)arg->resource);
    a=(void *)BR_RES_GetWordSet((struct BrRes *)arg->resource);
    b=STRBUF_Create(0x80,menu->heapId);
    s=STRBUF_Create(0x80,menu->heapId);
    MI_CpuFill8(&d,0,8);
    d.x=0x30;d.y=0x28;d.value=11;d.flag=1;
    BR_RES_LoadSprite(arg->resource,1,menu->heapId);
    BR_RES_GetSprite(arg->resource,1,&t);
    for(i=0;i<3;i++) {
        offset=(i+1)*4;
        if(*(unsigned *)((char *)arg->entries+offset)) {
            MSGDATA_ReadString((struct MsgBank *)c,0x1a,s);
            WORDSET_SetSlotTag((struct WordSet *)a,0,(struct Strbuf *)(*(unsigned *)((char *)arg->entries+offset+0x10)),*(unsigned *)((char *)arg->entries+offset+0x20),1,2);
            WORDSET_CopyTaggedText((struct WordSet *)a,(struct Strbuf *)b,(struct Strbuf *)s);
        }else MSGDATA_ReadString((struct MsgBank *)c,9,(struct Strbuf *)b);
        menu->button[i]=BR_BTN_CreateObject(&d,b,0xa0,1,(void *)(sptr)arg->windowKind,(void *)(sptr)menu->oamSys,(void *)h,&t,menu->heapId);
        d.y=d.y+0x28;
    }
    d.value=1;
    menu->button[3]=BR_BTN_CreateFromMessage((void *)(&d),4,0xa0,1,(void *)arg->windowKind,(void *)menu->oamSys,(void *)h,(struct MsgBank *)c,(void *)&t,menu->heapId);
    owner=BATTLE_REC_GetWork();
    tmp=GDS_PROFILE_CreateNameStr(owner,(u16)((menu->heapId&0x7fff)|0x8000));
    if(!menu->textWin) menu->textWin=BR_UTIL_CreateTextWin(arg->resource,menu->printQue,menu->heapId);
    MSGDATA_ReadString((struct MsgBank *)c,0x5c,s);
    WORDSET_SetSlotTag(a,0,(struct Strbuf *)tmp,GDS_PROFILE_GetEggFlag(owner),1,2);
    WORDSET_CopyTaggedText(a,b,s);
    BR_UTIL_SetWindowTextBuf(menu->textWin,arg->resource,b);
    STRBUF_Delete(tmp);STRBUF_Delete(s);STRBUF_Delete(b);
}

void BR_CODEIN_DeleteMenuButtons(struct CodeinSoclWork *menu,struct CodeinMenuArg *arg) { int i;if(menu->textWin){BR_UTIL_DeleteTextWin(menu->textWin,(sptr)arg->resource);menu->textWin=0;}for(i=0;i<4;i++){if(menu->button[i]){BR_BTN_DeleteObject(menu->button[i]);menu->button[i]=0;}}BR_RES_ReleaseSprite((struct BrRes *)arg->resource,1); }

int BR_CODEIN_HitTestOptionLeft(struct CodeinSoclWork *menu, int x, int y)
{
    int ok = ((unsigned int)(x - 0x20) <= 0x48) &
             ((unsigned int)(y - 0x30) <= 0x10);
    if (ok) {
        int args[2];
        args[0] = x;
        args[1] = y;
        BR_UTIL_StartEffect((char *)menu->tapFx, 1, (const BrPair *)args);
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
        BR_UTIL_StartEffect((char *)menu->tapFx, 1, (const BrPair *)args);
        GFL_USE_PlaySeDefaultVolume(0x703);
    }
    return ok;
}

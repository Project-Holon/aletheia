/*
 * function: PLIST_MENU_UpdateLevelUp
 * address: 0x021BC6CC
 * packet: pkt_ov091_021BC6CC
 * region: ov091
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * checks: 1 seven-argument C724 and scalar stack widths read; 2 own ARM9 C724/D304/18328 and ov091 callees read; 3 u8 flag retained5 out, u32 width with explicit truncation gave20 out; 4 scoped spill locals and narrowed coordinate extern restore instruction order; 5 neighbours and struct-local idiom re-read; permuter300 baseline10 out, verified winner5 out; next lever is flag/width spill allocation.
 * retry: declaring case0 flag before width swaps their spill slots into
 * the original order and closes all 1376 bytes; one wave59 retry run.
 * symbols:
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_02045EC0 0x02045EC0 arm
 *   STRBUF_Delete 0x02045808 arm
 *   STRBUF_Create 0x020457B0 arm
 *   BMP_FillRect 0x02043AF4 arm
 *   KEY_GetTrg 0x020362DC arm
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   BMP_WIN_ClearScreen 0x020456F8 arm
 *   BMP_WIN_Delete 0x020452E8 arm
 *   BMP_MENUWORK_DrawWindow 0x0201F73C thumb
 *   func_02017E1C 0x02017E1C thumb
 *   PRINTSYS_PrintQueColor 0x0201C724 thumb
 *   WORDSET_CreateDefault 0x0201EC64 thumb
 *   WORDSET_SetSlotNumber 0x0201EFA4 thumb
 *   WORDSET_CopyTaggedText 0x0201F250 thumb
 *   func_0201D304 0x0201D304 thumb
 *   WORDSET_DeleteStrbufED04 0x0201ED04 thumb
 *   PRINTSYS_QUE_IsExistTarget 0x0201C6C4 thumb
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   BMP_MENUWORK_DrawWindowBorder 0x0201F7A8 thumb
 *   POKE_TOOL_GetLevelUpMove 0x02018328 thumb
 *   SHINKA_CHECK_CheckEvolution 0x0201B2B0 thumb
 *   PLIST_MESSAGE_CloseWindow 0x021BB7A4 thumb ov091
 *   PLIST_MESSAGE_CreateWordSet 0x021BB97C thumb ov091
 *   PLIST_MESSAGE_SetWordSetPokemon 0x021BB99C thumb ov091
 *   PLIST_MESSAGE_SetWordSetMove 0x021BB9CC thumb ov091
 *   POKELIST_ShowMessage 0x021B9788 thumb ov091
 *   PLIST_MESSAGE_DestroyWordSet 0x021BB98C thumb ov091
 *   POKELIST_OpenGiveUpMoveMenu 0x021B9EB0 thumb ov091
 *   PLIST_MENU_BeginExitWait 0x021BC6C0 thumb ov091
 *   POKELIST_CloseMessageIfItemInBag 0x021B9E44 thumb ov091
 *   gPlistStatParamIds 0x021BECE4 data ov091 a2
 * BB9CC's last parameter is a full word here: result stays untruncated in r3.
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
struct Bmp;
struct Cfg;
struct CharBuf;
struct Descriptor;
struct MsgBank;
struct PrintSys;
struct StrObj;
struct U16Vec;
struct WordSet;
extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void BMP_MENUWORK_DrawWindow(void *a0, int a1, int a2, int a3);
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern void func_02041B6C(u32 bit);
extern u32 func_02017E1C(void *p,u32 id,u32 v);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void PRINTSYS_PrintQueColor(u32,u32,s16,s16,u32,u32,u16);
extern void STRBUF_Delete(struct U16Vec *vec);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern struct WordSet *WORDSET_CreateDefault(u32 heap);
extern void WORDSET_SetSlotNumber(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void WORDSET_CopyTaggedText(struct WordSet *ws, void *dst, void *src);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern u32 WORDSET_DeleteStrbufED04(struct WordSet *p);
extern u32 PRINTSYS_QUE_IsExistTarget(struct PrintSys *p, void *v);
extern u32 KEY_GetTrg(void);
extern int TOUCHPANEL_GetTrg(void);
extern void GFL_USE_PlaySeDefaultVolume(u32);
extern void BMP_FillRect(struct Bmp *b, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6);
extern void BMP_WIN_ClearScreen(struct Descriptor *d);
extern void BMP_MENUWORK_DrawWindowBorder(void *desc, u32 kind);
extern u32 BMP_WIN_Delete(struct Descriptor *d);
extern u16 POKE_TOOL_GetLevelUpMove(void *p, u32 *idx, u32 heap);
extern void PLIST_MESSAGE_CloseWindow(void *p, u32 *s);
extern void PLIST_MESSAGE_CreateWordSet(u16 *p, u32 s);
extern void PLIST_MESSAGE_SetWordSetPokemon(int a, int b, int c, int d);
extern void PLIST_MESSAGE_SetWordSetMove(int a, int b, int c, int d);
extern void POKELIST_ShowMessage(u8 *,int,int,int);
extern void PLIST_MESSAGE_DestroyWordSet(void *p, u32 s);
extern void POKELIST_OpenGiveUpMoveMenu(u8 *p);
extern void PLIST_MENU_BeginExitWait(char *p);
extern u32 SHINKA_CHECK_CheckEvolution(void *party, void *mon, u32 context, u32 param, u8 timezone, u32 *methodOut, u16 heap);
extern void POKELIST_CloseMessageIfItemInBag(u8 *);
extern u16 gPlistStatParamIds[];
#define W(k) (*(u32 *)(p+(k)))
#define H(k) (*(u16 *)(p+(k)))
#define S ((u8 *)W(0x280))
#define T(k) (*(u32 *)(S+(k)))
void PLIST_MENU_UpdateLevelUp(u8 *p)
{
    u8 i,j,x;
    u32 q,result,off;
    switch(p[0xe]) {
    case 0: {
        u8 flag;
        u32 delta,buf,tmp,text;
        int y;
        u16 width;
        flag=0;
        W(0x130)=BMP_WIN_Create(0,1,1,14,12,14,1);
        BMP_MENUWORK_DrawWindow((void *)W(0x130),1,1,12);
        BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)W(0x130))),15);
        q=W(0x130); BMP_WIN_TransferChars((struct Descriptor *)q); BMP_WIN_MakeScreen((struct Cfg *)q); func_02041B6C(BMP_WIN_GetBgLayer((struct Descriptor *)q));
        for(i=0;i<6;i++) {
            off=i; off=off*2;
            delta=func_02017E1C((void *)W(0x38),*(u16 *)((u8 *)gPlistStatParamIds+off),0)-*(u16 *)(p+off+0x124);
            if(delta>=10) flag=1;
            buf=(u32)func_02045EC0((struct MsgBank *)W(0x134),i+0x95); y=i<<4;
            PRINTSYS_PrintQueColor(W(0x140),(u32)BMP_WIN_GetBmp((struct Descriptor *)W(0x130)),0,(s16)(i<<4),buf,W(0x138),0x440);
            STRBUF_Delete((struct U16Vec *)buf);
            buf=(u32)func_02045EC0((struct MsgBank *)W(0x134),0x9c); tmp=(u32)STRBUF_Create(0x20,H(0)); text=(u32)WORDSET_CreateDefault(H(0));
            WORDSET_SetSlotNumber((struct WordSet *)text,0,delta,3,0,1); WORDSET_CopyTaggedText((struct WordSet *)text,(void *)tmp,(void *)buf);
            width=func_0201D304((struct StrObj *)tmp,W(0x138),0);
            PRINTSYS_PrintQueColor(W(0x140),(u32)BMP_WIN_GetBmp((struct Descriptor *)W(0x130)),(s16)(104-width),(s16)y,tmp,W(0x138),0x440);
            STRBUF_Delete((struct U16Vec *)buf); STRBUF_Delete((struct U16Vec *)tmp); WORDSET_DeleteStrbufED04((struct WordSet *)text);
        }
        for(j=0;j<6;j++) {
            x=flag==1 ? 72 : 80;
            buf=(u32)func_02045EC0((struct MsgBank *)W(0x134),0x9b);
            PRINTSYS_PrintQueColor(W(0x140),(u32)BMP_WIN_GetBmp((struct Descriptor *)W(0x130)),x,(s16)(j<<4),buf,W(0x138),0x440);
            STRBUF_Delete((struct U16Vec *)buf);
        }
        p[0xe]=1; break;
    }
    case 1:
        if(PRINTSYS_QUE_IsExistTarget((struct PrintSys *)W(0x140),(void *)((u32)BMP_WIN_GetBmp((struct Descriptor *)W(0x130))))==0) {
            q=W(0x130); BMP_WIN_TransferChars((struct Descriptor *)q); BMP_WIN_MakeScreen((struct Cfg *)q); func_02041B6C(BMP_WIN_GetBgLayer((struct Descriptor *)q)); p[0xe]=2;
        } break;
    case 2:
        if((KEY_GetTrg()&1)||(KEY_GetTrg()&2)||TOUCHPANEL_GetTrg()==1) { GFL_USE_PlaySeDefaultVolume(0x547); p[0xe]=3; }
        break;
    case 3: {
        u16 width;
        u32 delta,buf,tmp,text;
        BMP_FillRect((struct Bmp *)((u32)BMP_WIN_GetBmp((struct Descriptor *)W(0x130))),0x50,0,0x20,0x60,15);
        for(i=0;i<6;i++) {
            delta=func_02017E1C((void *)W(0x38),gPlistStatParamIds[i],0);
            buf=(u32)func_02045EC0((struct MsgBank *)W(0x134),0x9c); tmp=(u32)STRBUF_Create(0x20,H(0)); text=(u32)WORDSET_CreateDefault(H(0));
            WORDSET_SetSlotNumber((struct WordSet *)text,0,delta,3,0,1); WORDSET_CopyTaggedText((struct WordSet *)text,(void *)tmp,(void *)buf);
            width=func_0201D304((struct StrObj *)tmp,W(0x138),0);
            PRINTSYS_PrintQueColor(W(0x140),(u32)BMP_WIN_GetBmp((struct Descriptor *)W(0x130)),(s16)(104-width),(s16)(i<<4),tmp,W(0x138),0x440);
            STRBUF_Delete((struct U16Vec *)buf); STRBUF_Delete((struct U16Vec *)tmp); WORDSET_DeleteStrbufED04((struct WordSet *)text);
        }
        p[0xe]=4; break;
    }
    case 4:
        if(PRINTSYS_QUE_IsExistTarget((struct PrintSys *)W(0x140),(void *)((u32)BMP_WIN_GetBmp((struct Descriptor *)W(0x130))))==0) {
            q=W(0x130); BMP_WIN_TransferChars((struct Descriptor *)q); BMP_WIN_MakeScreen((struct Cfg *)q); func_02041B6C(BMP_WIN_GetBgLayer((struct Descriptor *)q)); p[0xe]=5;
        } break;
    case 5:
        if((KEY_GetTrg()&1)||(KEY_GetTrg()&2)||TOUCHPANEL_GetTrg()==1) {
            p[0xe]=6; GFL_USE_PlaySeDefaultVolume(0x547); BMP_WIN_ClearScreen((struct Descriptor *)W(0x130)); BMP_MENUWORK_DrawWindowBorder((void *)W(0x130),1); BMP_WIN_Delete((struct Descriptor *)W(0x130)); W(0x130)=0;
        } break;
    case 6:
        result=POKE_TOOL_GetLevelUpMove((void *)W(0x38),(u32 *)(S+0x50),H(0)); PLIST_MESSAGE_CloseWindow(p,(u32 *)W(0x150));
        if(result==0) { p[0xe]=7; return; }
        if(result==0xfffe) { p[0xe]=7; return; }
        if(result&0x8000) {
            *(u16 *)(S+0x46)=result-0x8000;
            PLIST_MESSAGE_CreateWordSet((u16 *)p,W(0x150)); PLIST_MESSAGE_SetWordSetPokemon((int)p,W(0x150),0,W(0x38));
            PLIST_MESSAGE_SetWordSetMove((int)p,W(0x150),1,*(u16 *)(S+0x46));
            POKELIST_ShowMessage(p,0x20,0,(int)POKELIST_OpenGiveUpMoveMenu); PLIST_MESSAGE_DestroyWordSet(p,W(0x150));
        } else {
            PLIST_MESSAGE_CreateWordSet((u16 *)p,W(0x150)); PLIST_MESSAGE_SetWordSetPokemon((int)p,W(0x150),0,W(0x38));
            PLIST_MESSAGE_SetWordSetMove((int)p,W(0x150),1,result);
            POKELIST_ShowMessage(p,0x29,1,(int)PLIST_MENU_BeginExitWait); PLIST_MESSAGE_DestroyWordSet(p,W(0x150));
        } break;
    case 7:
        func_02017E1C((void *)W(0x38),5,0);
        if(SHINKA_CHECK_CheckEvolution((void *)T(0),(void *)W(0x38),0,*(u16 *)(S+0x30),S[0x5f],0,H(0))!=0) {
            p[0xc]=19; T(0x3c)=W(0x2c); T(0x40)=9;
        } else {
            T(0x34)=5; T(0x3c)=W(0x2c); T(0x40)=10; POKELIST_CloseMessageIfItemInBag(p);
        } break;
    }
}


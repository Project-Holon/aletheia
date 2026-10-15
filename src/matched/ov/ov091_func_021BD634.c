/*
 * function: PLIST_BATTLE_UpdateTimer
 * address: 0x021BD634
 * packet: pkt_ov091_021BD634
 * region: ov091
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note: minute and second are u8 locals: widening the explicit byte casts
 *   to u32 keeps the size but moves the text spill before outgoing stores.
 * symbols:
 *   STRBUF_Create 0x020457B0 arm
 *   GF_FONT_Create_EC64 0x0201EC64 thumb
 *   func_02045EC0 0x02045EC0 arm
 *   WORDSET_SetSlotNumber 0x0201EFA4 thumb
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   WORDSET_CopyTaggedText 0x0201F250 thumb
 *   func_0201D304 0x0201D304 thumb
 *   PRINTSYS_PrintQueColor 0x0201C724 thumb
 *   WORDSET_DeleteStrbufED04 0x0201ED04 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   POKELIST_ForceSelectionEnd 0x021BA4F8 thumb ov091
 *   PRINTSYS_QUE_IsExistTarget 0x0201C6C4 thumb
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_02061CA4 0x02061CA4 arm
 *   FX_SinCosTable_ 0x020A1B38 data a2
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
struct U16Vec;
struct WordSet;
struct MsgBank;
struct Descriptor;
struct CharBuf;
struct StrObj;
struct PrintSys;
struct Cfg;
extern s16 FX_SinCosTable_[];
extern struct U16Vec *STRBUF_Create(u32,u32);
extern struct WordSet *GF_FONT_Create_EC64(u32);
extern void *func_02045EC0(struct MsgBank *,u32);
extern void WORDSET_SetSlotNumber(struct WordSet *,u32,u32,u32,u32,u32);
extern void *BMP_WIN_GetBmp(struct Descriptor *);
extern void BMP_Clear(struct CharBuf *,u8);
extern void WORDSET_CopyTaggedText(struct WordSet *,void *,void *);
extern u32 func_0201D304(struct StrObj *,u32,u32);
extern void PRINTSYS_PrintQueColor(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 WORDSET_DeleteStrbufED04(struct WordSet *p);
extern void STRBUF_Delete(struct U16Vec *);
extern void POKELIST_ForceSelectionEnd(u8 *);
extern u32 PRINTSYS_QUE_IsExistTarget(struct PrintSys *,void *);
extern void BMP_WIN_TransferChars(struct Descriptor *);
extern void BMP_WIN_MakeScreen(struct Cfg *);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *);
extern void func_02041B6C(u32);
extern int func_02061CA4(void *,u32,u32,int);
#define P(k) (*(void **)(p+(k)))
#define W(k) (*(u32 *)(p+(k)))
#define H(k) (*(u16 *)(p+(k)))
#define T (*(u16 *)((u8 *)P(0x280)+0x60))
void PLIST_BATTLE_UpdateTimer(u8 *p)
{
    u32 width;
    u8 minute;
    u8 second;
    void *text;
    struct U16Vec *buf;
    struct WordSet *words;
    u16 timer;
    struct Descriptor *window;
    u8 amount;
    u8 i;
    u8 red;
    u8 green;
    u8 blue;
    u16 color;
    int value;
    timer=T;
    if(p[0x20d]!=timer) {
        minute=(u8)(timer/60);
        second=(u8)(timer%60);
        buf=STRBUF_Create(32,H(0));
        words=GF_FONT_Create_EC64(H(0));
        if(minute==0) {
            text=func_02045EC0(P(0x134),175);
            WORDSET_SetSlotNumber(words,1,second,2,1,1);
        } else {
            text=func_02045EC0(P(0x134),174);
            WORDSET_SetSlotNumber(words,0,minute,2,1,1);
            WORDSET_SetSlotNumber(words,1,second,2,2,1);
        }
        BMP_Clear(BMP_WIN_GetBmp(P(0x200)),0);
        WORDSET_CopyTaggedText(words,buf,text);
        width=func_0201D304((struct StrObj *)buf,W(0x138),0);
        PRINTSYS_PrintQueColor(P(0x140),(u32)BMP_WIN_GetBmp(P(0x200)),(s16)(36-width),4,(u32)buf,W(0x138),0x3c40);
        WORDSET_DeleteStrbufED04(words);
        STRBUF_Delete(buf);
        STRBUF_Delete(text);
        W(0x208)=1;
        p[0x20d]=T;
    }
    if(T==0) POKELIST_ForceSelectionEnd(p);
    if(W(0x208)==1) {
        if(PRINTSYS_QUE_IsExistTarget(P(0x140),BMP_WIN_GetBmp(P(0x200)))==0) {
            W(0x208)=0;
            window=P(0x200);
            BMP_WIN_TransferChars(window);
            BMP_WIN_MakeScreen((struct Cfg *)window);
            func_02041B6C(BMP_WIN_GetBgLayer(window));
        }
    }
    if(W(0x204)==1) {
        if(PRINTSYS_QUE_IsExistTarget(P(0x140),BMP_WIN_GetBmp(P(0x1fc)))==0) {
            W(0x204)=0;
            window=P(0x1fc);
            BMP_WIN_TransferChars(window);
            BMP_WIN_MakeScreen((struct Cfg *)window);
            func_02041B6C(BMP_WIN_GetBgLayer(window));
        }
    }
    if(T<=10) {
        amount=(FX_SinCosTable_[(((H(0x24e)<<16)/60)>>4)*2+1]+4096)*32/8192;
        for(i=0;i<16;i++) {
            color=*(u16 *)(p+(u32)i*2+0x20e);
            green=(color&0x3e0)>>5;
            blue=(color&0x7c00)>>10;
            red=color&31;
            value=red+amount;
            if(value>31) value=31;
            red=value;
            *(u16 *)(p+(u32)i*2+0x22e)=(blue<<10)|(red|(green<<5));
        }
        func_02061CA4((void *)31,64,(u32)(p+0x22e),32);
        H(0x24e)++;
        if(H(0x24e)>=60) H(0x24e)=0;
    }
}

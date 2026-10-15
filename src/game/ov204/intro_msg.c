/*
 * file:     intro_msg.c
 * unit:     yes
 * function: func_021BF0A0, func_021BF1A4, func_021BF204, func_021BF228, func_021BF23C, func_021BF2D4, func_021BF2E0, func_021BF2F4, func_021BF374, func_021BF384, func_021BF4E8, func_021BF528, func_021BF538, func_021BF55C, func_021BF560, func_021BF580
 * address:  0x021BF0A0
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
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   GFL_USE_SetSeSlotVolume 0x020062BC thumb
 *   GFL_USE_SetSeSlotParams 0x02006268 thumb
 *   KEY_GetTrg 0x020362DC arm
 *   func_02041B6C 0x02041B6C arm
 *   func_02030734 0x02030734 arm
 *   func_020307B0 0x020307B0 arm
 *   site 0x021C0AE4 data a1
 *   GF_FONT_Create_EC64 0x0201EC64 thumb
 *   PRINTSYS_QUE_Create 0x0201C440 thumb
 *   TCBL_Create 0x0203101C arm
 *   func_02049B40 0x02049B40 arm
 *   BMP_MENUWORK_LoadCharAndPltt 0x0201F5BC thumb
 *   GF_FONT_Create 0x0201D7EC thumb
 *   STRBUF_Create 0x020457B0 arm
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   func_02028590 0x02028590 thumb
 *   TIME_ICON_Alloc 0x0202EF60 thumb
 *   APP_KEYCURSOR_Delete 0x02028604 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   GF_FONT_Delete 0x0201D83C thumb
 *   PRINTSYS_PrintStreamDelete 0x0201CE48 thumb
 *   BMP_WIN_Delete 0x020452E8 arm
 *   TCBL_Destroy 0x02031140 arm
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   MSGDATA_Delete 0x02045C04 arm
 *   WORDSET_DeleteStrbufED04 0x0201ED04 thumb
 *   func_02045B38 0x02045B38 arm
 *   TCBL_Main 0x020310C4 arm
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 *   func_02045CAC 0x02045CAC arm
 *   BMP_MENUWORK_DrawWindowBorder 0x0201F7A8 thumb
 *   PRINTSYS_PrintStreamGetState 0x0201CE30 thumb
 *   KEY_GetCont  0x0203630C  arm
 *   TOUCHPANEL_GetCont  0x02035C38  arm
 *   TOUCHPANEL_GetTrg  0x02035C60  arm
 *   MI_CpuFill8 0x02082BCC arm
 *   BMP_MENUWORK_Create 0x0201F81C thumb
 *   BMP_MENUWORK_AddStrItem 0x0201F898 thumb
 *   BMP_MENULIST_Create 0x0201FF30 thumb
 *   func_02020CF8 0x02020CF8 thumb
 *   func_020409B4 0x020409B4 arm
 *   BMP_MENUWORK_DrawWindow 0x0201F73C thumb
 *   func_02020D10 0x02020D10 thumb
 *   BMP_MENULIST_Delete 0x0202020C thumb
 *   BMP_MENUWORK_Delete 0x0201F868 thumb
 *   BMP_MENULIST_Main 0x020200CC thumb
 *   func_020056BC 0x020056BC thumb
 *   TIME_ICON_Start 0x0202EF98 thumb
 *   TIME_ICON_Delete 0x0202F038 thumb
 *   PRINTSYS_PrintStream  0x0201CCE4  thumb  arm9
 *   GF_FONT_SetTextColor  0x0201DD78  thumb  arm9
 *   APP_KEYCURSOR_Update  0x020286C4  thumb  arm9
 *   PRINTSYS_PrintStreamReleasePause  0x0201CE38  thumb  arm9
 *   PRINTSYS_PrintStreamShortWait  0x0201CE5C  thumb  arm9
 *   MSG_SPEED_GetWait  0x02012FFC  thumb  arm9
 *   WORDSET_CopyTaggedText  0x0201F250  thumb  arm9
 */
#include "../../matched/include/Obj01008.h"
#include "../../matched/include/Obj01292.h"
#include "../../matched/include/Obj08384.h"
#include "../../matched/include/Obj14621.h"
#include "../../matched/include/Obj02540.h"
#include "../../matched/include/Obj25385.h"
#include "../../matched/include/Obj25386.h"
#include "../../matched/include/Obj03358.h"
#include "../../matched/include/Obj14622.h"
#include "../../matched/include/Obj10880.h"
#include "../../matched/include/Obj14623.h"
#include "../../matched/include/Obj14624.h"
#include "../../matched/include/Obj25387.h"
#include "../../matched/include/Obj25389.h"
#include "../../matched/include/Obj14625.h"
#include "intro_cmd_shared_types.h"
#include "intro_msg_shared_types.h"

struct Cfg;

struct CharBuf;

struct Descriptor;

struct GfFont;

struct Tcbl;

struct U16Vec;

struct S02031140;

struct Rec3;

struct PrintSys;

struct MsgBank;

struct Ctx;

struct Src;

typedef struct {
    void *arr,*b,*c,*obj;
    u16 count,rows;
    u8 f14,f15,f16;
    u8 f17lo:4,f17hi:4;
    u8 f18lo:4,f18hi:4;
    u8 f19;
    u16 f1Alo:3,f1Amid:4,f1Apad:2,f1Amid2:6,f1Atop:1;
    u32 f1c;
    u16 f20,f22;
    u32 f24;
    void *f28,*f2c,*f30;
} Config;

extern void GFL_USE_PlaySeDefaultVolume(unsigned),GFL_USE_SetSeSlotVolume(int,unsigned),GFL_USE_SetSeSlotParams(int,unsigned,unsigned,unsigned);

extern int TOUCHPANEL_GetTrg(void);

extern u32 KEY_GetTrg(void);

extern void GFL_USE_PlaySeDefaultVolume(u32);

extern void func_02041B6C(u32);

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);

extern u32 func_020307B0(void *p);

extern struct WordSet *GF_FONT_Create_EC64(u32 heap);

extern u32 PRINTSYS_QUE_Create(void *p);

extern struct Tcbl *TCBL_Create(u16 heap, u16 tag, u32 count, u32 workSize);

extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);

extern void BMP_MENUWORK_LoadCharAndPltt(u32 a, u32 b, u32 c, u32 d, u16 e);

extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);

extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);

extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);

extern void *BMP_WIN_GetBmp(struct Descriptor *p);

extern void BMP_Clear(struct CharBuf *buf, u8 value);

extern void BMP_WIN_TransferChars(struct Descriptor *d);

extern void BMP_WIN_MakeScreen(struct Cfg *cfg);

extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);

extern void *func_02028590(u32,u32,u32,u32);

extern struct Obj *TIME_ICON_Alloc(u32 heap);

extern int APP_KEYCURSOR_Delete(int);

extern void STRBUF_Delete(struct U16Vec *);

extern unsigned int GF_FONT_Delete(void *ptr);

extern void PRINTSYS_PrintStreamDelete(struct Rec3 *p);

extern unsigned int BMP_WIN_Delete(struct Descriptor *d);

extern void TCBL_Destroy(struct S02031140 *);

extern void PRINTSYS_QUE_Delete(struct PrintSys *p);

extern unsigned int MSGDATA_Delete(struct Rec *rec);

extern unsigned int WORDSET_DeleteStrbufED04(struct WordSet *p);

extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);

extern void TCBL_Main(struct Tcbl*);

extern u32 PRINTSYS_QUE_Main(struct PrintSys*);

extern signed char MSG_SPEED_GetWait(void);

extern void GF_FONT_SetTextColor(unsigned int, unsigned int, unsigned int);

extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);

extern void WORDSET_CopyTaggedText(struct WordSet *ws, void *dst, void *src);

extern void *PRINTSYS_PrintStream(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned short, unsigned short);

extern void BMP_MENUWORK_DrawWindow(void *, int, int, int);

extern void BMP_MENUWORK_DrawWindowBorder(void*,u32);

extern u32 PRINTSYS_PrintStreamGetState(void *p);

extern void PRINTSYS_PrintStreamShortWait(struct Rec *p, s32 v);

extern void PRINTSYS_PrintStreamReleasePause(void *p);

extern void APP_KEYCURSOR_Update(struct Ctx *ctx, void *p, void *cell);

extern unsigned int KEY_GetCont(void);

extern int TOUCHPANEL_GetCont(void);

extern void *MI_CpuFill8(void *,int,u32);

extern void *BMP_MENUWORK_Create(u32,u32);

extern void BMP_MENUWORK_AddStrItem(struct Slot *table, u32 a, u32 b, u32 tag);

extern struct Obj *BMP_MENULIST_Create(struct Src *src, u16 a, u16 b, u32 heap);

extern void func_02020CF8(struct Obj *p, int heap);

extern void func_020409B4(u32 index);

extern void func_02020D10(u8 *p, u32 v);

extern void BMP_MENULIST_Delete(struct Obj *o, u16 *a, u16 *b);

extern u32 BMP_MENUWORK_Delete(void *p);

extern int BMP_MENULIST_Main(struct Obj *);

extern u32 func_020056BC(void);

extern void TIME_ICON_Start(u8 *,u32,u32,u8,u8);

extern void TIME_ICON_Delete(u8 *);

char *func_021BF0A0(u16 heap);

void func_021BF1A4(char *p);

void func_021BF204(char *p, unsigned a, unsigned short b);

void func_021BF228(u8*p);

void func_021BF23C(char *p, void *a, int flag);

void func_021BF2D4(u8*p);

u32 func_021BF2E0(u8*p);

int func_021BF2F4(char *a);

int *func_021BF374(char *p, int v);

void func_021BF384(char *p,u32 *entries,u32 count,int flag);

void func_021BF4E8(char *p);

void func_021BF528(u8 *p);

int func_021BF538(u8 *p,int *out);

int func_021BF55C(u8 *p);

void func_021BF560(u8 *p);

void func_021BF580(u8 *p);

extern const char site[];

char *func_021BF0A0(u16 heap)
{
    char *p;
    void *obj;
    p=func_02030734(heap,72,1,site,129);
    ((struct Obj01008 *)p)->f0=heap;
    ((struct Obj01008 *)p)->f8=GF_FONT_Create_EC64(heap);
    ((struct Obj01008 *)p)->f4=(void *)PRINTSYS_QUE_Create((void *)heap);
    ((struct Obj01008 *)p)->f18=TCBL_Create(((struct Obj01008 *)p)->f0,((struct Obj01008 *)p)->f0,2,0);
    func_02049B40(23,5,0,320,32,heap);
    BMP_MENUWORK_LoadCharAndPltt(1,7,9,0,heap);
    BMP_MENUWORK_LoadCharAndPltt(1,16,8,1,heap);
    ((struct Obj01008 *)p)->f10=GF_FONT_Create(23,0,1,0,((struct Obj01008 *)p)->f0);
    ((struct Obj01008 *)p)->f3C=STRBUF_Create(1600,((struct Obj01008 *)p)->f0);
    ((struct Obj01008 *)p)->f40=STRBUF_Create(1600,((struct Obj01008 *)p)->f0);
    ((struct Obj01008 *)p)->f38=(void *)BMP_WIN_Create(1,22,13,9,4,10,1);
    BMP_Clear(BMP_WIN_GetBmp(((struct Obj01008 *)p)->f38),0);
    obj=((struct Obj01008 *)p)->f38;
    BMP_WIN_TransferChars(obj);BMP_WIN_MakeScreen(obj);func_02041B6C(BMP_WIN_GetBgLayer(obj));
    ((struct Obj01008 *)p)->f1C=(void *)BMP_WIN_Create(1,1,19,30,4,10,1);
    ((struct Obj01008 *)p)->f20=func_02028590(15,1,1,((struct Obj01008 *)p)->f0);
    ((struct Obj01008 *)p)->f44=TIME_ICON_Alloc(((struct Obj01008 *)p)->f0);
    return p;
}

void func_021BF1A4(char *p)
{
    func_021BF580((u8 *)p);
    APP_KEYCURSOR_Delete(((struct Obj01292 *)p)->f20);
    STRBUF_Delete(*(struct U16Vec * *)&((struct Obj01292 *)p)->f3C);
    STRBUF_Delete(*(struct U16Vec * *)&((struct Obj01292 *)p)->f40);
    GF_FONT_Delete(((struct Obj01292 *)p)->f10);
    if (((struct Obj01292 *)p)->f14 != 0)
        PRINTSYS_PrintStreamDelete((struct Rec3 *)(((struct Obj01292 *)p)->f14));
    BMP_WIN_Delete(*(struct Descriptor * *)&((struct Obj01292 *)p)->f1C);
    if (((struct Obj01292 *)p)->f38)
        BMP_WIN_Delete(*(struct Descriptor * *)&((struct Obj01292 *)p)->f38);
    TCBL_Destroy(*(struct S02031140 * *)&((struct Obj01292 *)p)->f18);
    PRINTSYS_QUE_Delete(((struct Obj01292 *)p)->f4);
    if (((struct Obj01292 *)p)->fC)
        MSGDATA_Delete(((struct Obj01292 *)p)->fC);
    WORDSET_DeleteStrbufED04(((struct Obj01292 *)p)->f8);
    func_020307B0(p);
}

void func_021BF204(char *p, unsigned a, unsigned short b)
{
    if (((struct Obj08384 *)p)->fC != 0)
    {
        MSGDATA_Delete(((struct Obj08384 *)p)->fC);
    }
    ((struct Obj08384 *)p)->fC = func_02045B38(a, 2, b, ((struct Obj08384 *)p)->f0);
}

void func_021BF228(u8*p){TCBL_Main(*(struct Tcbl* *)&((struct Obj14621 *)p)->f18);PRINTSYS_QUE_Main(*(struct PrintSys* *)&((struct Obj14621 *)p)->f4);}

/*
 * Caller consumes 0201CCE4's live r0 result; return declared pointer despite callee's void source.
 */
void func_021BF23C(char *p, void *a, int flag)
{
    unsigned int value = MSG_SPEED_GetWait();
    void *desc = ((struct Obj02540 *)p)->f1C;
    BMP_Clear(BMP_WIN_GetBmp(desc), 15);
    GF_FONT_SetTextColor(1, 2, 15);
    func_02045CAC(((struct Obj02540 *)p)->fC, (unsigned int)a, ((struct Obj02540 *)p)->f3C);
    WORDSET_CopyTaggedText(((struct Obj02540 *)p)->f8, ((struct Obj02540 *)p)->f40, ((struct Obj02540 *)p)->f3C);
    ((struct Obj02540 *)p)->f14 = PRINTSYS_PrintStream((unsigned int)desc, 4, 0, *(unsigned int *)&((struct Obj02540 *)p)->f40, ((struct Obj02540 *)p)->f10, value, ((struct Obj02540 *)p)->f18, 0xFFFF, ((struct Obj02540 *)p)->f0, 15);
    if (flag == 0)
        BMP_MENUWORK_DrawWindow(desc, 1, 7, 9);
    else
        BMP_MENUWORK_DrawWindow(desc, 1, 16, 8);
    BMP_WIN_TransferChars(desc);
    BMP_WIN_MakeScreen(desc);
    func_02041B6C(BMP_WIN_GetBgLayer(desc));
}

void func_021BF2D4(u8*p){BMP_MENUWORK_DrawWindowBorder(*(void* *)&((struct Obj25385 *)p)->f1C,0);}

u32 func_021BF2E0(u8*p){u32 a=((struct Obj25386 *)p)->f14;if(a==0){return 2;}else{return PRINTSYS_PrintStreamGetState((void *)a);}}

int func_021BF2F4(char *a)
{
    if (((struct Obj03358 *)a)->f14 != 0) {
        APP_KEYCURSOR_Update((struct Ctx *)(((struct Obj03358 *)a)->f20), (void *)(((struct Obj03358 *)a)->f14),
                      (void *)(((struct Obj03358 *)a)->f1C));

        switch (PRINTSYS_PrintStreamGetState((void *)(((struct Obj03358 *)a)->f14))) {
        case 2:
            PRINTSYS_PrintStreamDelete((struct Rec3 *)(((struct Obj03358 *)a)->f14));
            ((struct Obj03358 *)a)->f14 = 0;
            return 1;
        case 1:
            if (KEY_GetTrg() == 1 || KEY_GetTrg() == 2
                || TOUCHPANEL_GetTrg() != 0) {
                PRINTSYS_PrintStreamReleasePause((void *)(((struct Obj03358 *)a)->f14));
                GFL_USE_PlaySeDefaultVolume(0x547);
            }
            break;
        case 0:
            if ((KEY_GetCont() & 3) != 0 || TOUCHPANEL_GetCont() != 0)
                PRINTSYS_PrintStreamShortWait((struct Rec *)(((struct Obj03358 *)a)->f14), 0);
            break;
        }
        return 0;
    }
    return 0;
}

int *func_021BF374(char *p, int v)
{
    ((struct Obj14622 *)p)->f30 = v;
    ((struct Obj14622 *)p)->f34 = 0;
    return (int *)(p + 0x30);
}

/*
 * Owner unit_02045C44.c omits func_02045CAC from function:; singleton TU
 * --suggest-split leaves this caller out. the integrator owns that unit.
 * prior fixed-flag ARM9-45CAC.log, using the owner's unit declarations:
 * void func_02045CAC(struct MsgBank *bank, u32 index, void *dest) {
 *   u32 size; struct MsgEntry *e;
 *   if (index >= bank->file->count) { STRBUF_Clear(dest); return; }
 *   func_02046180(bank);
 *   if (bank->resident == 0) {
 *     u32 pos = bank->origin + bank->file->langOff[bank->langIndex];
 *     func_0204960C(bank->stream, pos + (index * 8 + 4));
 *     ARC_TOOL_ReadHandle(bank->stream, 8, &bank->cache); e = &bank->cache;
 *   } else { e = (struct MsgEntry *)((u8 *)bank->base + 4) + index; }
 *   if (bank->resident == 0) {
 *     void *buf; size = e->len * 2;
 *     buf = GFL_HEAP_Alloc((u16)((bank->heapId & 0x7fff) | 0x8000),
 *                       size, 0, MSGDATA_AllocSite, 0xd6);
 *     if (buf != 0) {
 *       func_0204960C(bank->stream, e->off + (bank->origin
 *                     + bank->file->langOff[bank->langIndex]));
 *       ARC_TOOL_ReadHandle(bank->stream, size, buf);
 *       STRBUF_SetChars(dest, buf, e->len); func_020307B0(buf);
 *     }
 *   } else { STRBUF_SetChars(dest, (u8 *)bank->base + e->off, e->len); }
 *   func_02045E04(dest, index);
 * }
 * lever: u16 heap local places its word home at sp+8; u32 swaps it with
 * the entry pointer at sp+12, leaving seven differing concrete bytes.
 */
void func_021BF384(char *p,u32 *entries,u32 count,int flag)
{
    Config config;
    char *state;
    void *obj;
    u16 heap;
    u32 i;
    state=p+36;
    heap=*(u16 *)p;
    obj=*(void **)(p+56);
    MI_CpuFill8(state,0,12);
    *(void **)(state+4)=BMP_MENUWORK_Create(count,heap);
    for(i=0;i<count;i++){
        func_02045CAC(*(void **)(p+12),*(u32 *)((char *)entries+i*8),*(void **)(p+60));
        BMP_MENUWORK_AddStrItem((struct Slot *)((char *)*(void **)(state+4)+i*8),*(u32 *)(p+60),*(u32 *)((char *)entries+i*8+4),heap);
    }
    MI_CpuFill8(&config,0,52);
    config.arr=*(void **)(state+4);config.obj=obj;
    config.count=count;config.rows=5;config.f14=0;config.f15=16;config.f16=0;
    config.f17lo=2;config.f17hi=1;config.f18lo=15;config.f18hi=2;
    config.f1Alo=0;config.f1Amid=0;config.f1Apad=1;config.f1Amid2=0;config.f1Atop=0;
    config.f1c=0;config.f20=16;config.f22=16;config.f24=0;
    config.f28=func_021BF374(p,(int)obj);config.f2c=*(void **)(p+4);config.f30=*(void **)(p+16);
    *(void **)state=BMP_MENULIST_Create((struct Src *)(&config),0,0,heap);
    func_02020CF8(*(void **)state,(u32)heap);
    BMP_WIN_TransferChars(obj);BMP_WIN_MakeScreen(obj);func_020409B4((u8)BMP_WIN_GetBgLayer(obj));
    BMP_MENUWORK_DrawWindow(obj,1,7,9);
    if(flag)func_02020D10(*(void **)state,0);
    else func_02020D10(*(void **)state,1);
}

/*
 * Trailing two bytes are zero alignment padding.
 */
void func_021BF4E8(char *p)
{
    char *block = p + 0x24;
    BMP_MENUWORK_DrawWindowBorder(((struct Obj10880 *)p)->f38, 0);
    BMP_Clear(BMP_WIN_GetBmp(((struct Obj10880 *)p)->f38), 0);
    BMP_WIN_TransferChars(((struct Obj10880 *)p)->f38);
    BMP_MENULIST_Delete(((struct Obj14623 *)block)->f0, 0, 0);
    BMP_MENUWORK_Delete(((struct Obj14623 *)block)->f4);
    MI_CpuFill8(block, 0, 12);
}

void func_021BF528(u8 *p)
{
    u8 *q=p+36;
    ((struct Obj14624 *)q)->f8=BMP_MENULIST_Main(*(struct Obj * *)&((struct Obj14624 *)q)->f0);
}

/*
 * lever: A switch with -1 before -2 preserves the outlined return order.
 */
int func_021BF538(u8 *p,int *out)
{
    int v=((struct Obj25387 *)p)->f2C;
    switch(v){case -1:return 0;case -2:return 2;}
    if(out!=0)*out=v;
    return 1;
}

int func_021BF55C(u8 *p)
{
    return ((struct Obj25389 *)p)->f8;
}

void func_021BF560(u8 *p)
{
    TIME_ICON_Start(*(u8 * *)&((struct Obj14625 *)p)->f44,func_020056BC(),((struct Obj14625 *)p)->f1C,15,16);
}

void func_021BF580(u8 *p)
{
    if(*(u8 * *)&((struct Obj01292 *)p)->f44!=0){TIME_ICON_Delete(*(u8 * *)&((struct Obj01292 *)p)->f44);*(u8 * *)&((struct Obj01292 *)p)->f44=0;}
}

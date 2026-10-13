/*
 * file:     unit_021C5B40.c
 * unit:     yes
 * function: func_021C5B40, func_021C5BE0, func_021C5C00, func_021C5C64, func_021C5C84, func_021C5D68, func_021C5DD8, func_021C5E30, func_021C5E58, func_021C5F44, func_021C5F80, func_021C5FDC, func_021C6028, func_021C6170, func_021C61D0, func_021C61D4, func_021C6230, func_021C6284, func_021C62BC, func_021C62F4, func_021C630C, func_021C6374, func_021C64A8, func_021C657C, func_021C6594, func_021C65A8, func_021C65E4, func_021C660C, func_021C666C, func_021C6688, func_021C66A0, func_021C66B8, func_021C66CC, func_021C670C, func_021C6738, func_021C674C, func_021C675C, func_021C67D4, func_021C6884, func_021C68A0
 * address:  0x021C5B40
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02009050 0x02009050 thumb
 *   func_02008EF8 0x02008EF8 thumb
 *   func_020307B0 0x020307B0 arm
 *   BGWINFRM_HideFrame 0x0202CC70 thumb
 *   BGWINFRM_ShowFrame 0x0202CC58 thumb
 *   BGWINFRM_PutFrame 0x0202CB4C thumb
 *   func_0204B6F4 0x0204B6F4 arm
 *   func_020413B0 0x020413B0 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_020490F4 0x020490F4 arm
 *   func_02008FA4 0x02008FA4 thumb
 *   func_02049658 0x02049658 arm
 *   func_02049B68 0x02049B68 arm
 *   func_020498F4 0x020498F4 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   func_0201C440 0x0201C440 thumb
 *   CLACT_CreateUnit 0x0204B100 arm
 *   PMS_DRAW_Create 0x0202DB0C thumb
 *   PMS_DRAW_SetNullColorPalette 0x0202DE5C thumb
 *   PMS_DRAW_Delete 0x0202DC08 thumb
 *   func_0201C4C0 0x0201C4C0 thumb
 *   CLACT_DeleteUnit 0x0204B1CC arm
 *   BMP_WIN_Init 0x02045088 arm
 *   GF_FONT_Create 0x0201D7EC thumb
 *   TCBL_Create 0x0203101C arm
 *   BMP_WIN_Create 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_020409B4 0x020409B4 arm
 *   g_7A20 0x021C7A20 data
 *   g_7A20b 0x021C7A20 data
 *   TCBL_Destroy 0x02031140 arm
 *   func_020452E8 0x020452E8 arm
 *   GF_FONT_Delete 0x0201D83C thumb
 *   BMP_WIN_Exit 0x020450C8 arm
 *   func_02045EC0 0x02045EC0 arm
 *   STRBUF_Delete 0x02045808 arm
 *   BMP_CreateFromBuffer 0x020436FC arm
 *   func_02008F84 0x02008F84 thumb
 *   STRBUF_SetString 0x02045924 arm
 *   BMP_Blit 0x020439A0 arm
 *   func_02008F9C 0x02008F9C thumb
 *   BGWINFRM_PutBmpWin 0x0202CEBC thumb
 *   BMP_Delete 0x020437AC arm
 *   STRBUF_Create 0x020457B0 arm
 *   func_02012FFC 0x02012FFC thumb
 *   PRINTSYS_PrintStream 0x0201CCE4 thumb
 *   func_0201F250     0x0201F250  thumb
 *   func_0201F73C   0x0201F73C  thumb
 *   func_0201F7A8    0x0201F7A8  thumb
 *   func_02045CAC 0x02045CAC arm
 *   func_02008FC8 0x02008FC8 thumb
 *   PMSI_PARAM_IsEnabled 0x02024450 thumb
 *   PMS_DRAW_Print 0x0202DC48 thumb
 *   func_02008FC0 0x02008FC0 thumb
 *   func_020434DC 0x020434DC arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   func_0204B92C 0x0204B92C arm
 *   d_021C7BBC 0x021C7BBC data ov136 a4
 *   CLACT_DrawSystem  0x0204A600  arm
 *   CLACT_InitSystem   0x0204A48C  arm
 *   CLACT_SetUnitDefaultRenderer   0x0204B270  arm
 *   d_021C78E0 0x021C78E0 data a4
 *   d_021C7BA0 0x021C7BA0 data a4
 *   CLACT_ExitSystem  0x0204A5AC  arm
 *   CLACT_ReleasePalette  0x0204ADA4  arm
 *   CLACT_ReleaseCellAnim  0x0204AFD8  arm
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_DeleteActor  0x0204B3B4  arm
 *   CLACT_SetActorAnimSeq        0x0204B878  arm
 *   func_0204B3DC        0x0204B3DC  arm
 *   func_0204B404 0x0204B404 arm
 *   CLACT_SetActorAnimFrame 0x0204B8C4 arm
 *   func_0204B688  0x0204B688  arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterPalette 0x0204ABF0 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   func_02027698 0x02027698 thumb
 *   func_0202769C 0x0202769C thumb
 *   func_020276A0 0x020276A0 thumb
 *   func_0201BC3C 0x0201BC3C thumb
 *   func_02027618 0x02027618 thumb
 *   func_02027614 0x02027614 thumb
 *   func_0202761C 0x0202761C thumb
 *   func_02027620 0x02027620 thumb
 *   PRINTSYS_QUE_Main            0x0201C4E4  thumb
 *   func_0201C6C4            0x0201C6C4  thumb
 *   BGWINFRM_UpdateMoves 0x0202CD94 thumb
 *   PMS_DRAW_Main  0x0202DBC4  thumb
 *   TCBL_Main            0x020310C4  arm
 *   d_021C7DA8 0x021C7DA8 data a4
 *   PRINTSYS_PrintQueColor  0x0201C724  thumb  arm9
 */
#include "ov136_types.h"
struct MbUnitBCtx3;
struct MbUnitBCtx2;

struct MbUnitBCtx3 {
    void *f0;
    unsigned char f4;
    unsigned char pad_5[487];
    unsigned int f1EC;
};

struct MbUnitBCtx2 {
    short f0;
    short f2;
    unsigned char pad_4[2];
    unsigned short f6;
    void *f8;
    unsigned char pad_C[4];
    unsigned int f10;
    unsigned int f14;
    unsigned int f18;
    unsigned int f1C;
    unsigned char pad_20[12];
    unsigned int f2C;
    unsigned char pad_30[444];
    void *f1EC;
    unsigned char pad_1F0[44];
    unsigned int f21C;
    unsigned int f220;
    unsigned char pad_224[16];
    unsigned int f234;
    unsigned int f238;
    unsigned char pad_23C[24];
    unsigned int f254;
    unsigned int f258;
    unsigned char pad_25C[52];
    void *f290;
};

struct Sub02008F80Obj;
struct WinMgr;
struct Obj;
struct Bank;
struct PmsDraw;
struct PrintSys;
struct Cfg;
struct CharBuf;
struct Descriptor;
struct GfFont;
struct Tcbl;
struct S02031140;
struct StrObj;
struct MsgBank;
struct U16Vec;
struct Bmp;
struct Obj020437AC;
struct Strbuf;
struct WordSet;
struct Sub02008F80Entry;
struct Vec2;
struct Actor;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed char s8;

struct Fade {
    u8 a : 1;
    u8 idx : 7;
    u8 lo : 4;
    u8 hi : 4;
    u8 state;
    u8 count;
    u8 b4;
    u8 b5;
    u8 b6;
    u8 b7;
};

struct Ent {
    u32 w0;
    u8 b4;
    u8 b5;
    u8 b6;
    u8 b7;
    u16 h8;
    u16 pad;
};

struct Slot {
    u32 w;
    u8 id;
    u8 pad[3];
};

typedef enum { SLOT_ZERO = 0 } SlotIndex;

typedef signed short s16;

typedef enum { ACTIVE = 1 } Active;

typedef enum { OFF = 0, ON = 1 } Enable;

typedef signed int     s32;

typedef struct { s16 x, y; u16 value; u8 flag, mode; } Descriptor;

typedef struct { s16 x, y; } Pair;

extern struct Sub02008F80Obj *func_02009050(struct Sub02008F80Obj *arr, u32 unused, int i, u32 heap);
extern int func_02008EF8(const struct Sub02008F80Obj *obj);
extern u32 func_020307B0(void *p);
extern void BGWINFRM_HideFrame(struct WinMgr *mgr, u32 idx);
extern void BGWINFRM_ShowFrame(struct WinMgr *mgr, u32 idx);
extern void BGWINFRM_PutFrame(struct WinMgr *mgr, u32 idx, s8 x, s8 y);
extern void func_0204B6F4(struct Obj *o, u32 v, u32 flag);
extern void func_020413B0(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern void func_02041B6C(u32);
extern void *func_020490F4(u32 id, u32 heap);
extern u8 func_02008FA4(const struct Sub02008F80Obj *obj);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void ARC_TOOL_DeleteHandle(void *);
extern unsigned int func_0201C440(void *p);
extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);
extern struct PmsDraw *PMS_DRAW_Create(u32 a, u32 b, u32 c, u32 d, u8 e0, u8 e1, u16 heap);
extern void PMS_DRAW_SetNullColorPalette(struct PmsDraw *p, u8 v);
extern void PMS_DRAW_Delete(struct Obj *p);
extern void func_0201C4C0(struct PrintSys *p);
extern u32 CLACT_DeleteUnit(struct Bank *bank);
extern void BMP_WIN_Init(u16);
extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);
extern struct Tcbl *TCBL_Create(u16 heap, u16 tag, u32 count, u32 workSize);
extern u32 BMP_WIN_Create(u32 bg, u32 x, u32 y, u32 w, u8 h, u8 pal, u8 base);
extern void *func_02045770(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_020409B4(u32 v);
extern void TCBL_Destroy(struct S02031140 *p);
extern u32 func_020452E8(struct Descriptor *d);
extern u32 GF_FONT_Delete(void *ptr);
extern void BMP_WIN_Exit(void);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern void PRINTSYS_PrintQueColor(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void STRBUF_Delete(struct U16Vec *vec);
extern struct Bmp *BMP_CreateFromBuffer(void *pixels, u32 width, u32 height, u32 depth, u16 heap);
extern u8 *func_02008F84(struct Sub02008F80Obj *obj);
extern void STRBUF_SetString(struct Strbuf *o, const u16 *src);
extern void BMP_Blit(struct Bmp *dst, struct Bmp *src, u32 x, u32 y, int sx, int sy, u32 w, u32 h, u32 key);
extern u8 func_02008F9C(const struct Sub02008F80Obj *obj);
extern void BGWINFRM_PutBmpWin(struct WinMgr *mgr, u32 idx, void *a);
extern void BMP_Delete(struct Obj020437AC *p);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void func_0201EE0C(struct WordSet *p, u32 i, const void *src, u32 n, u32 f, u32 c);
extern signed char func_02012FFC(void);
extern u32 PRINTSYS_PrintStream(u32, u32, u32, u32, u32, u32, u32, u32, u16, u16);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_0201F73C(void *a0, int a1, int a2, int a3);
extern void func_0201F7A8(void *desc, u32 kind);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern struct Sub02008F80Entry *func_02008FC8(struct Sub02008F80Obj *obj, u32 i);
extern int PMSI_PARAM_IsEnabled(const u16 *p);
extern void PMS_DRAW_Print(void *, void *, void *, u8);
extern u16 func_02008FC0(const struct Sub02008F80Obj *obj);
extern void func_020434DC(u32, u32);
extern void BG_SYS_SetSubPlaneVisible(u32, u32);
extern void func_0204B92C(struct Obj *p, u32 v);
extern void CLACT_DrawSystem(void *);
extern void CLACT_InitSystem(const struct Cfg *cfg, u32 arg, u32 heapId);
extern void CLACT_SetUnitDefaultRenderer(struct Bank *bank);
extern void CLACT_ReleaseCellAnim(u32 i);
extern void CLACT_ReleasePalette(u32 i);
extern void CLACT_ExitSystem(void);
extern struct Obj *CLACT_CreateActor(void *owner, u32 i, u32 j, u32 k, const void *position, u16 space, u16 heap);
extern void CLACT_DeleteActor(struct Obj *p);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, unsigned int which);
extern void CLACT_SetActorAnimFrame(struct Obj *p, u32 value);
extern void func_0204B688(struct Actor *actor, u32 value);
extern u32 func_020275E4(void);
extern u32 func_02027698(void);
extern int CLACT_RegisterCharacter(void *, u32, u32, u32, u16);
extern int func_0201BC3C(void);
extern int CLACT_RegisterPalette(void *, u32, u32, u32, u16);
extern u32 func_0202769C(u32);
extern u32 func_020276A0(u32);
extern int CLACT_RegisterCellAnim(void *, u32, u32, u32);
extern u32 func_02027618(void);
extern u32 func_02027614(void);
extern u32 func_0202761C(u32);
extern u32 func_02027620(u32);
extern void BGWINFRM_UpdateMoves(struct WinMgr *mgr);
extern u32 PRINTSYS_QUE_Main(struct PrintSys *ps);
extern u32 func_0201C6C4(struct PrintSys *p, void *v);
extern void TCBL_Main(struct Tcbl *p);
extern void PMS_DRAW_Main(u8 *p);
void func_021C5B40(u8 *p);
void func_021C5BE0(struct MbSeqCtx *p);
void func_021C5C00(u8 *p);
void func_021C5C64(u8 *p);
int func_021C5C84(u8 *p);
void func_021C5D68(u8 *p);
void func_021C5DD8(struct MbSeqCtx *p);
void func_021C5E30(u8 *p);
void func_021C5E58(struct MbSeqCtx *p);
void func_021C5F44(struct MbSeqCtx *p);
void func_021C5F80(void *unused, void *text, u8 *slot, void *owner, int x, int y, u32 mode, u16 color, int align);
void func_021C5FDC(u8 *p, void *bank, int i, u32 message, int x, int y, u32 mode, u16 color, int align);
void func_021C6028(u8 *p, u32 a1, int idx, int sel);
void func_021C6170(struct MbSeqCtx *p);
void func_021C61CC(struct MbUnitBCtx *a0);
void func_021C61D0(struct MbUnitBCtx *a0);
void func_021C61D4(u8 *p, u32 a1);
void func_021C6230(u8 *p);
void func_021C6284(u8 *p);
void func_021C62BC(struct MbSeqCtx *p);
void func_021C62F4(u8 *p);
void func_021C630C(u8 *p, unsigned int i);
void func_021C6374(u8 *p);
void func_021C64A8(u8 *p);
void func_021C657C(struct MbSeqCtx *p);
void func_021C6594(u8 *p);
void func_021C65A8(u8 *p);
void func_021C65E4(struct MbUnitBCtx *p);
void *func_021C660C(u8 *p, const u8 *cfg);
void func_021C666C(u8 *p, int i);
void func_021C6688(u8 *p);
void func_021C66A0(u8 *p, int i, u32 v);
void func_021C66B8(u8 *p, int i, u32 v);
void func_021C66CC(u8 *p, int i, int x, int y);
void func_021C670C(u8 *p, int i, int on);
void func_021C6738(u8 *p);
void func_021C674C(struct MbUnitBCtx *p);
void func_021C675C(u8 *p);
void func_021C67D4(u8 *p);
void func_021C6884(u8 *p);
int func_021C68A0(u8 *p, int *st);
extern const struct Ent g_7A20[];
extern const struct Ent g_7A20b[];
extern const u8 d_021C7BBC[];
extern const u8 d_021C7BA0[];
extern const u8 d_021C78E0[];

void func_021C5B40(u8 *p)
{
    unsigned i;
    u8 *q;
    ((struct MbUnitBCtx *)((struct MbSeqCtx *)p)->f8)->f2FC=0;
    for(i=0;i<20;i++) {
        (*(u8 * *)&((struct MbSeqCtx *)p)->f8)[0x2e8+i]=255;
        *(void **)(*(u8 * *)&((struct MbSeqCtx *)p)->f8+0x298+i*4)=func_02009050(((struct MbSeqCtx *)p)->f0,0,i,102);
        if(func_02008EF8(*(void **)(*(u8 * *)&((struct MbSeqCtx *)p)->f8+0x298+i*4))==1) {
            (*(u8 * *)&((struct MbSeqCtx *)p)->f8)[0x2e8+((struct MbUnitBCtx *)((struct MbSeqCtx *)p)->f8)->f2FC]=i;
            ++((struct MbUnitBCtx *)((struct MbSeqCtx *)p)->f8)->f2FC;
        }
    }
    q=*(u8 * *)&((struct MbSeqCtx *)p)->f8;
    if(((struct MbUnitBCtx *)q)->f2FC==0) ((struct MbUnitBCtx *)q)->f2FE=0;
    else ((struct MbUnitBCtx *)q)->f2FE=(((struct MbUnitBCtx *)q)->f2FC-1)/10;
}

void func_021C5BE0(struct MbSeqCtx *p)
{
    u32 i;
    for (i = 0; i < 0x14; i++)
        func_020307B0(*(void **)(*(u8 * *)&p->f8 + i * 4 + 0x298));
}

void func_021C5C00(u8 *p)
{
    u16 idx;
    u8 *row;
    u16 offset;
    u16 i;
    idx = 0;
    offset = 10 * ((struct MbSeqCtx *)p)->f1C;
    row = *(u8 * *)&((struct MbSeqCtx *)p)->f8+0x2e8+offset;
    offset += 2;
    for (i=0;i<10;i++) {
        if(row[i]==255) BGWINFRM_HideFrame(**(void ** *)&((struct MbSeqCtx *)p)->f8,idx);
        else {
            func_021C6028(p,idx,offset,row[i]);
            BGWINFRM_ShowFrame(**(void ** *)&((struct MbSeqCtx *)p)->f8,idx);
        }
        offset++;
        idx++;
    }
}

void func_021C5C64(u8 *p)
{
    func_021C6028(p, 10, 0x16, p[0x1f]);
    BGWINFRM_PutFrame(**(struct WinMgr ** *)&((struct MbSeqCtx *)p)->f8, 10, 4, 7);
}


int func_021C5C84(u8 *p)
{
    struct Fade *s = (struct Fade *)(*(u8 * *)&((struct MbSeqCtx *)p)->f8 + 0x300);
    switch (s->state) {
    case 0:
        if (s->a == 0) {
            func_0204B6F4((struct Obj *)(*(u32 *)(*(u8 * *)&((struct MbSeqCtx *)p)->f8 + s->idx * 4 + 0x1F0)), s->lo, 1);
        } else {
            func_020413B0(s->idx, s->b4, s->b5, s->b6, s->b7, s->lo);
            func_02041B6C(s->idx);
        }
        s->state++;
        break;
    case 1:
        s->count++;
        if (s->count == 4) {
            if (s->a == 0) {
                func_0204B6F4((struct Obj *)(*(u32 *)(*(u8 * *)&((struct MbSeqCtx *)p)->f8 + s->idx * 4 + 0x1F0)), s->hi, 1);
            } else {
                func_020413B0(s->idx, s->b4, s->b5, s->b6, s->b7, s->hi);
                func_02041B6C(s->idx);
            }
            s->count = 0;
            s->state++;
        }
        break;
    case 2:
        s->count++;
        if (s->count == 2) {
            return 0;
        }
        break;
    }
    return 1;
}

void func_021C5D68(u8 *p)
{
    void *h;
    u8 *q;
    h = func_020490F4(155,102);
    q = (u8 *)func_02008FA4(*(void **)(*(u8 * *)&((struct MbSeqCtx *)p)->f8 + 0x298 + p[31]*4));
    func_02049658(h,(u32)(q+12),5,0,0,1,102);
    func_02049B68(h,(u32)q,4,0,64,102);
    func_020498F4(h,(u32)(q+24),5,0,0,1,102);
    ARC_TOOL_DeleteHandle(h);
}

void func_021C5DD8(struct MbSeqCtx *p)
{
    ((struct MbUnitBCtx *)p->f8)->f36C = (void *)func_0201C440((void *)102);
    ((struct MbUnitBCtx *)p->f8)->f368 = CLACT_CreateUnit(8,2,102);
    ((struct MbUnitBCtx *)p->f8)->f35C = PMS_DRAW_Create((u32)(((struct MbUnitBCtx *)p->f8)->f368),1,(u32)(((struct MbUnitBCtx *)p->f8)->f36C),(u32)(*(void * *)&p->f18),4,4,102);
    PMS_DRAW_SetNullColorPalette(((struct MbUnitBCtx *)p->f8)->f35C,0);
}

void func_021C5E30(u8 *p)
{
    PMS_DRAW_Delete(((struct MbUnitBCtx *)((struct MbSeqCtx *)p)->f8)->f35C);
    func_0201C4C0(((struct MbUnitBCtx *)((struct MbSeqCtx *)p)->f8)->f36C);
    CLACT_DeleteUnit(((struct MbUnitBCtx *)((struct MbSeqCtx *)p)->f8)->f368);
}


/*
 * lever: 021C5EE2 branches to 021C5E9A, after the r6=r4 copy at
 *   021C5E98. The first loop stores zero ids, and a new second loop starts
 *   at zero. Literal zero plus separate loops reproduces that shared r6.
 *   The old j=i inside the loop incorrectly started loop two at 31.
 */
void func_021C5E58(struct MbSeqCtx *p)
{
    u32 i;
    u32 j;
    struct Slot *sl;
    void *t;
    BMP_WIN_Init(0x66);
    *(void * *)&p->f18 = GF_FONT_Create(0x17, 0, 0, 0, 0x66);
    ((struct MbUnitBCtx *)p->f8)->f1CC = TCBL_Create(0x66, 0x66, 0x20, 0x20);
    *(unsigned int *)&((struct MbUnitBCtx *)p->f8)->f1C4 = func_0201C440((void *)0x66);
    for (i = 0; i < 0x20; i++) {
        *(u32 *)(*(u8 * *)&p->f8 + i * 4 + 0x44) = BMP_WIN_Create((u8)g_7A20[i].w0, g_7A20[i].b4, g_7A20[i].b5, g_7A20[i].b6, g_7A20[i].b7, (u8)g_7A20[i].h8, 1);
        sl = (struct Slot *)(*(u8 * *)&p->f8 + 0xC4);
        sl[i].w = *(u32 *)(*(u8 * *)&p->f8 + i * 4 + 0x44);
        sl[i].id = 0;
    }
    for (j = 0; j < 0x16; j++) {
        BMP_Clear(func_02045770(*(void **)(*(u8 * *)&p->f8 + j * 4 + 0x44)), 4);
        BMP_WIN_TransferChars(*(void **)(*(u8 * *)&p->f8 + j * 4 + 0x44));
    }
    t = ((struct MbUnitBCtx *)p->f8)->f44;
    BMP_WIN_TransferChars(t);
    BMP_WIN_MakeScreen(t);
    func_020409B4(func_02045730(t));
    t = ((struct MbUnitBCtx *)p->f8)->f48;
    BMP_WIN_TransferChars(t);
    BMP_WIN_MakeScreen(t);
    func_020409B4(func_02045730(t));
}


void func_021C5F44(struct MbSeqCtx *p)
{
    u32 i;
    func_0201C4C0(((struct MbUnitBCtx *)p->f8)->f1C4);
    TCBL_Destroy((struct S02031140 *)(*(unsigned int *)&((struct MbUnitBCtx *)p->f8)->f1CC));
    for (i = 0; i < 0x20; i++) {
        func_020452E8(*(void **)(*(u8 * *)&p->f8 + i * 4 + 0x44));
    }
    GF_FONT_Delete((void *)(p->f18));
    BMP_WIN_Exit();
}

void func_021C5F80(void *unused, void *text, u8 *slot, void *owner, int x, int y, u32 mode, u16 color, int align)
{
    if (align == 1)
        x -= func_0201D304(text, mode, 0);
    else if (align == 2)
        x -= func_0201D304(text, mode, 0) >> 1;
    PRINTSYS_PrintQueColor(owner, (u32)func_02045770(((struct MbUnitBCtx3 *)slot)->f0), (s16)x, (s16)y, (u32)text, mode, color);
    slot[4] = 1;
}

void func_021C5FDC(u8 *p, void *bank, int i, u32 message, int x, int y, u32 mode, u16 color, int align)
{
    void *text;
    text = func_02045EC0(bank, message);
    func_021C5F80(*(void **)(p + 0x44 + i * 4), text, p + 0xc4 + i * 8, ((struct MbUnitBCtx *)p)->f1C4, x, y, mode, color, align);
    STRBUF_Delete(text);
}


void func_021C6028(u8 *p, u32 a1, int idx, int sel)
{
    void *mon;
    void *b0;
    void *b1;
    void *win;
    u8 *slot;
    u32 i;

    b0 = BMP_CreateFromBuffer(*(u8 * *)&((struct MbSeqCtx *)p)->f8 + 4, 1, 1, 0x20, 0x66);
    b1 = BMP_CreateFromBuffer(*(u8 * *)&((struct MbSeqCtx *)p)->f8 + 0x24, 1, 1, 0x20, 0x66);
    win = *(void **)(*(u8 * *)&((struct MbSeqCtx *)p)->f8 + idx * 4 + 0x44);
    mon = *(void **)(*(u8 * *)&((struct MbSeqCtx *)p)->f8 + sel * 4 + 0x298);
    slot = *(u8 * *)&((struct MbSeqCtx *)p)->f8 + 0xC4 + idx * 8;

    BMP_Clear(b0, 4);
    BMP_Clear(b1, 4);
    STRBUF_SetString(((struct MbUnitBCtx *)((struct MbSeqCtx *)p)->f8)->f1D8, (const u16 *)func_02008F84(mon));
    for (i = 0; i < 8; i++) {
        BMP_Blit(func_02045770(win), b0, 0, 0, i * 8, 0, 8, 8, 0xFFFF);
        BMP_Blit(func_02045770(win), b1, 0, 0, i * 8, 8, 8, 8, 0xFFFF);
    }
    BMP_Clear(func_02045770(win), 4);
    if (func_02008F9C(mon) == 0) {
        func_021C5F80(win, ((struct MbUnitBCtx *)((struct MbSeqCtx *)p)->f8)->f1D8, slot,
                      ((struct MbUnitBCtx *)((struct MbSeqCtx *)p)->f8)->f1C4, 0, 0, ((struct MbSeqCtx *)p)->f18, 0x14C4, 0);
    } else {
        func_021C5F80(win, ((struct MbUnitBCtx *)((struct MbSeqCtx *)p)->f8)->f1D8, slot,
                      ((struct MbUnitBCtx *)((struct MbSeqCtx *)p)->f8)->f1C4, 0, 0, ((struct MbSeqCtx *)p)->f18, 0x1D04, 0);
    }
    BGWINFRM_PutBmpWin(**(void ** *)&((struct MbSeqCtx *)p)->f8, a1, win);
    BMP_Delete(b1);
    BMP_Delete(b0);
}

void func_021C6170(struct MbSeqCtx *p)
{
    void *obj;
    BMP_Clear(func_02045770(((struct MbUnitBCtx *)*(u8 * *)&p->f8)->fAC), 0);
    func_021C5FDC(*(u8 * *)&p->f8, ((struct MbUnitBCtx *)*(u8 * *)&p->f8)->f1D0, 26, 0, 52, 0, p->f18, 0x440, 2);
    obj = ((struct MbUnitBCtx *)*(u8 * *)&p->f8)->fAC;
    BMP_WIN_TransferChars(obj);
    BMP_WIN_MakeScreen(obj);
    func_02041B6C(func_02045730(obj));
}

void func_021C61CC(struct MbUnitBCtx *a0)
{
}

void func_021C61D0(struct MbUnitBCtx *a0)
{
}

void func_021C61D4(u8 *p, u32 a1)
{
    void *entry;
    void *text;
    u32 n;
    entry = *(void **)(*(u8 * *)&((struct MbSeqCtx *)p)->f8 + 0x298 + p[0x1f] * 4);
    text = STRBUF_Create(16, 102);
    func_02008F84(entry);
    STRBUF_SetString(text, (const u16 *)func_02008F84(entry));
    n = func_02008F9C(entry);
    func_0201EE0C(((struct MbUnitBCtx *)((struct MbSeqCtx *)p)->f8)->f1D4, 0, text, n, 1, 2);
    STRBUF_Delete(text);
}


void func_021C6230(u8 *p)
{
    u32 win = *(unsigned int *)&((struct MbUnitBCtx *)((struct MbSeqCtx *)p)->f8)->fA8;
    u32 w2;
    w2 = (u32)func_02045770((struct Descriptor *)win);
    BMP_Clear((struct CharBuf *)w2, 0xf);
    *(unsigned int *)&((struct MbUnitBCtx *)((struct MbSeqCtx *)p)->f8)->f1C8 = PRINTSYS_PrintStream(win, 0, 0, *(unsigned int *)&((struct MbUnitBCtx *)((struct MbSeqCtx *)p)->f8)->f1D8, ((struct MbSeqCtx *)p)->f18, func_02012FFC(), *(unsigned int *)&((struct MbUnitBCtx *)((struct MbSeqCtx *)p)->f8)->f1CC, 0, 0x66, 0xf);
}

void func_021C6284(u8 *p)
{
    void *t;
    func_021C61D4(p, 0);
    t = func_02045EC0(((struct MbUnitBCtx *)((struct MbSeqCtx *)p)->f8)->f1D0, 9);
    func_0201F250(((struct MbUnitBCtx *)((struct MbSeqCtx *)p)->f8)->f1D4, ((struct MbUnitBCtx *)((struct MbSeqCtx *)p)->f8)->f1D8, t);
    STRBUF_Delete(t);
    func_021C6230(p);
}

void func_021C62BC(struct MbSeqCtx *p)
{
    void *q;
    func_0201F73C(((struct MbUnitBCtx *)p->f8)->fA8, 2, 0x3E2, 0xD);
    q = ((struct MbUnitBCtx *)p->f8)->fA8;
    BMP_WIN_TransferChars(q);
    BMP_WIN_MakeScreen(q);
    func_02041B6C(func_02045730(q));
}

void func_021C62F4(u8 *p)
{
    func_0201F7A8(((struct MbUnitBCtx *)((struct MbSeqCtx *)p)->f8)->fA8, 2);
    func_02041B6C(0);
}

void func_021C630C(u8 *p, unsigned int i)
{
    switch (i) {
    case 0: func_02045CAC(((struct MbUnitBCtx *)((struct MbSeqCtx *)p)->f8)->f1D0, 10, ((struct MbUnitBCtx *)((struct MbSeqCtx *)p)->f8)->f1D8); break;
    case 1: func_02045CAC(((struct MbUnitBCtx *)((struct MbSeqCtx *)p)->f8)->f1D0, 11, ((struct MbUnitBCtx *)((struct MbSeqCtx *)p)->f8)->f1D8); break;
    case 2: func_02045CAC(((struct MbUnitBCtx *)((struct MbSeqCtx *)p)->f8)->f1D0, 12, ((struct MbUnitBCtx *)((struct MbSeqCtx *)p)->f8)->f1D8); break;
    case 3: func_02045CAC(((struct MbUnitBCtx *)((struct MbSeqCtx *)p)->f8)->f1D0, 13, ((struct MbUnitBCtx *)((struct MbSeqCtx *)p)->f8)->f1D8); break;
    case 4: func_02045CAC(((struct MbUnitBCtx *)((struct MbSeqCtx *)p)->f8)->f1D0, 14, ((struct MbUnitBCtx *)((struct MbSeqCtx *)p)->f8)->f1D8); break;
    }
    func_021C6230(p);
}


/*
 * note (2026-10-02): byte-correct; only PMSI_PARAM_IsEnabled lacks a witness. Witness filed as
 *   src/matched/arm9/PMSI_PARAM_IsEnabled.c (EXACT). Re-verify after its shard exists, then file EXACT.
 */
void func_021C6374(u8 *p)
{
    u32 i;
    void *mon;
    void *w;

    for (i = 0; i < 3; i++) {
        mon = func_02008FC8(*(void **)(*(u8 * *)&((struct MbSeqCtx *)p)->f8 + p[0x1F] * 4 + 0x298), (u8)i);
        if (PMSI_PARAM_IsEnabled(mon)) {
            PMS_DRAW_Print(((struct MbUnitBCtx *)*(u8 * *)&((struct MbSeqCtx *)p)->f8)->f35C, *(void **)(*(u8 * *)&((struct MbSeqCtx *)p)->f8 + i * 4 + 0xB0), mon, (u8)i);
            w = *(void **)(*(u8 * *)&((struct MbSeqCtx *)p)->f8 + i * 4 + 0xB0);
            BMP_WIN_TransferChars(w);
            BMP_WIN_MakeScreen(w);
            func_02041B6C(func_02045730(w));
        }
    }
    ((struct MbUnitBCtx *)*(u8 * *)&((struct MbSeqCtx *)p)->f8)->f360 = 6;
    ((struct MbUnitBCtx *)*(u8 * *)&((struct MbSeqCtx *)p)->f8)->f362 = 0;
    ((struct MbUnitBCtx *)*(u8 * *)&((struct MbSeqCtx *)p)->f8)->f364 = func_02008FC0(*(void **)(*(u8 * *)&((struct MbSeqCtx *)p)->f8 + p[0x1F] * 4 + 0x298));
    if (((struct MbUnitBCtx *)*(u8 * *)&((struct MbSeqCtx *)p)->f8)->f364 != 0) {
        PMS_DRAW_Print(((struct MbUnitBCtx *)*(u8 * *)&((struct MbSeqCtx *)p)->f8)->f35C, ((struct MbUnitBCtx *)*(u8 * *)&((struct MbSeqCtx *)p)->f8)->fBC, *(u8 * *)&((struct MbSeqCtx *)p)->f8 + 0x360, 3);
    }
    BMP_Clear(func_02045770(((struct MbUnitBCtx *)*(u8 * *)&((struct MbSeqCtx *)p)->f8)->fC0), 0);
    STRBUF_SetString(((struct MbUnitBCtx *)*(u8 * *)&((struct MbSeqCtx *)p)->f8)->f1D8, (const u16 *)func_02008F84(*(void **)(*(u8 * *)&((struct MbSeqCtx *)p)->f8 + p[0x1F] * 4 + 0x298)));
    func_021C5F80(((struct MbUnitBCtx *)*(u8 * *)&((struct MbSeqCtx *)p)->f8)->fC0, ((struct MbUnitBCtx *)*(u8 * *)&((struct MbSeqCtx *)p)->f8)->f1D8, *(u8 * *)&((struct MbSeqCtx *)p)->f8 + 0x1BC,
                  ((struct MbUnitBCtx *)*(u8 * *)&((struct MbSeqCtx *)p)->f8)->f1C4, 0, 2, ((struct MbSeqCtx *)p)->f18, 0x440, 0);
    w = ((struct MbUnitBCtx *)*(u8 * *)&((struct MbSeqCtx *)p)->f8)->fC0;
    BMP_WIN_TransferChars(w);
    BMP_WIN_MakeScreen(w);
    func_02041B6C(func_02045730(w));
}

static inline void activate(void *p)
{
    Active v = ACTIVE;
    func_0204B92C(p, v);
}

/*
 * lever: named q reloaded after the first tail call; explicit if/else
 *   keeps the zero arm first and joins the one arm with the initial path.
 */
void func_021C64A8(u8 *p)
{
    u32 i;
    int k;
    u8 *q;
    func_020434DC(0x10, 1);
    BG_SYS_SetSubPlaneVisible(0x10, 1);
    for (i = 0; i < 8; i++) {
        *(u32 *)(*(u8 **)(p + 8) + i * 4 + 0x210) = 0;
        *(u32 *)(*(u8 **)(p + 8) + i * 4 + 0x230) = 0;
        *(u32 *)(*(u8 **)(p + 8) + i * 4 + 0x250) = 0;
    }
    func_021C6738(*(u8 **)(p + 8));
    func_021C65A8(*(u8 **)(p + 8));
    func_021C67D4(*(u8 **)(p + 8));
    func_021C675C(*(u8 **)(p + 8));
    for (i = 0; i < 8; i++) {
        *(void **)(*(u8 **)(p + 8) + i * 4 + 0x1F0) = func_021C660C(*(u8 **)(p + 8), d_021C7BBC + i * 0x34);
        activate(*(void **)(*(u8 **)(p + 8) + i * 4 + 0x1F0));
    }
    q = *(u8 **)(p + 8);
    if (*(u16 *)(q + 0x2FC) <= 10) {
        func_021C66B8(q, 0, 0);
        q = *(u8 **)(p + 8);
        k = 1;
    } else {
        if (*(u16 *)(p + 0x1C) == 0) k = 0;
        else k = 1;
    }
    func_021C66B8(q, k, 0);
    func_021C66B8(*(u8 **)(p + 8), 4, 0);
    func_021C66B8(*(u8 **)(p + 8), 5, 0);
    func_021C66B8(*(u8 **)(p + 8), 6, 0);
}


/*
 * Addresses are Black-image addresses.
 */
void func_021C657C(struct MbSeqCtx *p)
{
    func_021C6688(p->f8);
    func_021C65E4(p->f8);
    func_021C674C(p->f8);
}

void func_021C6594(u8 *p)
{
    void *q = ((struct MbUnitBCtx *)p)->f1EC;
    if (q != 0) {
        CLACT_DrawSystem(q);
    }
}

void func_021C65A8(u8 *p)
{
    void *bank;

    CLACT_InitSystem((const struct Cfg *)d_021C7BA0, (u32)d_021C78E0, 0x66);
    bank = CLACT_CreateUnit(8, 0, 0x66);
    ((struct MbUnitBCtx2 *)p)->f1EC = bank;
    CLACT_SetUnitDefaultRenderer(bank);
    func_020434DC(0x10, 1);
    BG_SYS_SetSubPlaneVisible(0x10, 1);
}

void func_021C65E4(struct MbUnitBCtx *p)
{
    CLACT_ReleaseCellAnim((u32)(p->f230));
    CLACT_ReleasePalette((u32)(p->f250));
    CLACT_DeleteUnit(p->f1EC);
    CLACT_ExitSystem();
}

/*
 * lever: const descriptor input preserves load and stack-store scheduling.
 */
void *func_021C660C(u8 *p, const u8 *cfg)
{
    Descriptor d;
    d.x = ((struct MbUnitBCtx2 *)cfg)->f0;
    d.y = ((struct MbUnitBCtx2 *)cfg)->f2;
    d.value = ((struct MbUnitBCtx2 *)cfg)->f6;
    d.flag = 0;
    d.mode = ((struct MbUnitBCtx2 *)cfg)->f2C;
    return CLACT_CreateActor((void *)((struct MbUnitBCtx3 *)p)->f1EC, *(u32 *)(p + 0x210 + ((struct MbUnitBCtx2 *)cfg)->f14 * 4), *(u32 *)(p + 0x230 + ((struct MbUnitBCtx2 *)cfg)->f18 * 4), *(u32 *)(p + 0x250 + ((struct MbUnitBCtx2 *)cfg)->f1C * 4), &d, ((struct MbUnitBCtx2 *)cfg)->f10, 102);
}


void func_021C666C(u8 *p, int i)
{
    if (*(u32 *)(p + 0x1f0 + i * 4)) {
        CLACT_DeleteActor(*(void **)(p + 0x1f0 + i * 4));
        *(u32 *)(p + 0x1f0 + i * 4) = 0;
    }
}


void func_021C6688(u8 *p)
{
    u32 i;
    for (i = 0; i < 8; i++)
        func_021C666C(p, i);
}

void func_021C66A0(u8 *p, int i, u32 v)
{
    CLACT_SetActorAnimSeq(*(void **)(p + i * 4 + 0x1F0), (u16)v);
}

void func_021C66B8(u8 *p, int i, u32 v)
{
    func_0204B3DC(*(void **)(p + i * 4 + 0x1F0), v);
}

void func_021C66CC(u8 *p, int i, int x, int y)
{
    Pair v;
    v.x = x;
    v.y = y;
    if (y < 256)
        func_0204B404(*(void **)(p + 0x1f0 + i * 4), (const struct Vec2 *)(&v), 0);
    else
        func_0204B404(*(void **)(p + 0x1f0 + i * 4), (const struct Vec2 *)(&v), 1);
    CLACT_SetActorAnimFrame(*(void **)(p + 0x1f0 + i * 4), 0);
}

void func_021C670C(u8 *p, int i, int on)
{
    if (on == 1) {
        func_0204B688(*(void **)(p + i * 4 + 0x1F0), 1);
    } else {
        func_0204B688(*(void **)(p + i * 4 + 0x1F0), 0);
    }
}

void func_021C6738(u8 *p)
{
    ((struct MbUnitBCtx2 *)p)->f290 = func_020490F4(7, 0x66);
}


void func_021C674C(struct MbUnitBCtx *p)
{
    ARC_TOOL_DeleteHandle(p->f290);
}

void func_021C675C(u8 *p)
{
    void *arc;
    u32 i;
    u32 first;
    arc = func_020490F4(func_020275E4(), 102);
    for (i = 0; i <= 2; i++)
        *(u32 *)(p + 0x210 + i * 4) = CLACT_RegisterCharacter(arc, func_02027698(), 0, 1, 102);
    *(unsigned int *)&((struct MbUnitBCtx *)p)->f230 = CLACT_RegisterPalette(arc, func_0201BC3C(), 1, 0, 102);
    first = func_0202769C(0);
    *(unsigned int *)&((struct MbUnitBCtx *)p)->f250 = CLACT_RegisterCellAnim(arc, first, func_020276A0(0), 102);
    ARC_TOOL_DeleteHandle(arc);
}

/*
 * extent: 021C6882 halfword is alignment padding.
 */
void func_021C67D4(u8 *p)
{
    void *arc;
    u32 first;
    arc = func_020490F4(155, 102);
    ((struct MbUnitBCtx2 *)p)->f21C = CLACT_RegisterCharacter(arc, 44, 1, 0, 102);
    ((struct MbUnitBCtx2 *)p)->f234 = CLACT_RegisterPalette(arc, 47, 0, 0, 102);
    ((struct MbUnitBCtx2 *)p)->f254 = CLACT_RegisterCellAnim(arc, 45, 46, 102);
    ARC_TOOL_DeleteHandle(arc);
    arc = func_020490F4(func_020275E4(), 102);
    ((struct MbUnitBCtx2 *)p)->f220 = CLACT_RegisterCharacter(arc, func_02027618(), 0, 0, 102);
    ((struct MbUnitBCtx2 *)p)->f238 = CLACT_RegisterPalette(arc, func_02027614(), 0, 128, 102);
    first = func_0202761C(0);
    ((struct MbUnitBCtx2 *)p)->f258 = CLACT_RegisterCellAnim(arc, first, func_02027620(0), 102);
    ARC_TOOL_DeleteHandle(arc);
}

void func_021C6884(u8 *p)
{
    func_021C66CC(p, 2, 0xE0, 0xB0);
    func_021C66A0(p, 2, 4);
}

extern int (*const d_021C7DA8[])(u8 *);

int func_021C68A0(u8 *p, int *st)
{
    int i;
    int j;
    *st = d_021C7DA8[*st](p);
    if (*st == 0x1B) {
        return 0;
    }
    if (*(u8 * *)&((struct MbUnitBCtx2 *)p)->f8 != 0) {
        BGWINFRM_UpdateMoves(**(struct WinMgr ** *)&((struct MbUnitBCtx2 *)p)->f8);
        func_021C6594(*(u8 * *)&((struct MbUnitBCtx2 *)p)->f8);
        if (((struct MbUnitBCtx *)((struct MbUnitBCtx2 *)p)->f8)->f1C4 != 0) {
            PRINTSYS_QUE_Main(((struct MbUnitBCtx *)((struct MbUnitBCtx2 *)p)->f8)->f1C4);
            for (i = 0; i < 0x1B; i++) {
                void *h = ((struct MbUnitBCtx *)((struct MbUnitBCtx2 *)p)->f8)->f1C4;
                u8 *e = *(u8 * *)&((struct MbUnitBCtx2 *)p)->f8 + 0xC4 + i * 8;
                if (e[4] != 0) {
                    if (func_0201C6C4(h, func_02045770(((struct MbUnitBCtx3 *)e)->f0)) == 0) {
                        BMP_WIN_TransferChars(((struct MbUnitBCtx3 *)e)->f0);
                        e[4] = 0;
                    }
                }
            }
        }
        if (((struct MbUnitBCtx *)((struct MbUnitBCtx2 *)p)->f8)->f1CC != 0) {
            TCBL_Main(((struct MbUnitBCtx *)((struct MbUnitBCtx2 *)p)->f8)->f1CC);
        }
        if (((struct MbUnitBCtx *)((struct MbUnitBCtx2 *)p)->f8)->f36C != 0) {
            PMS_DRAW_Main(((struct MbUnitBCtx *)((struct MbUnitBCtx2 *)p)->f8)->f35C);
            PRINTSYS_QUE_Main(((struct MbUnitBCtx *)((struct MbUnitBCtx2 *)p)->f8)->f36C);
            for (j = 0x1B; j < 0x20; j++) {
                void *g = ((struct MbUnitBCtx *)((struct MbUnitBCtx2 *)p)->f8)->f1C4;
                u8 *f = *(u8 * *)&((struct MbUnitBCtx2 *)p)->f8 + 0xC4 + j * 8;
                if (f[4] != 0) {
                    if (func_0201C6C4(g, func_02045770(((struct MbUnitBCtx3 *)f)->f0)) == 0) {
                        BMP_WIN_TransferChars(((struct MbUnitBCtx3 *)f)->f0);
                        f[4] = 0;
                    }
                }
            }
        }
    }
    return 1;
}

/*
 * file:     zukan_detail_headbar.c
 * unit:     yes
 * function: ZUKAN_DETAIL_HEADBAR_Create, ZUKAN_DETAIL_HEADBAR_Delete, ZUKAN_DETAIL_HEADBAR_Update, ZUKAN_DETAIL_HEADBAR_SetIconKind, ZUKAN_DETAIL_HEADBAR_GetIconKind, ZUKAN_DETAIL_HEADBAR_SetIconSpecies, ZUKAN_DETAIL_HEADBAR_SetIconForm, ZUKAN_DETAIL_HEADBAR_NoOp, ZUKAN_DETAIL_HEADBAR_CreateWindows, ZUKAN_DETAIL_HEADBAR_DeleteWindows, ZUKAN_DETAIL_HEADBAR_DrawIcon, ZUKAN_DETAIL_HEADBAR_ClearIcon, ZUKAN_DETAIL_HEADBAR_FlushIcon
 * address:  0x021BE710
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from zukan_detail_headbar.c, zukan_detail_page.c, zukan_detail_voice.c, zukan_detail_form.c by tools/splitfile.py.
 *
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_020307B0 0x020307B0  arm
 *   func_020490F4  0x020490F4  arm
 *   ARC_UTIL_UploadPaletteFromHandle  0x02049BDC  arm
 *   func_020413B0  0x020413B0  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   func_02041B6C  0x02041B6C  arm
 *   func_0203FB44 0x0203FB44 arm
 *   PRINTSYS_QUE_Create 0x0201C440 thumb
 *   func_020056A0 0x020056A0 thumb
 *   ZUKAN_DETAIL_HEADBAR_Create 0x021BE710 thumb
 *   ZUKAN_DETAIL_HEADBAR_Delete 0x021BE778 thumb ov208
 *   func_02030EAC 0x02030EAC arm
 *   PRINTSYS_QUE_Clear 0x0201C6EC thumb
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   ZUKAN_DETAIL_HEADBAR_Update 0x021BE7A4 thumb
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 *   func_02040618 0x02040618 arm
 *   func_0204047C 0x0204047C arm
 *   func_02040804 0x02040804 arm
 *   func_02041EE4 0x02041EE4 arm
 *   func_021BE920 0x021BE920 thumb ov208
 *   func_021BE864 0x021BE864 thumb ov208
 *   d_021C8DFC 0x021C8DFC data a1
 *   func_021BE9CC 0x021BE9CC thumb ov208
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_CreateFromArchive 0x0204384C arm
 *   BMP_GetByteSize 0x020437EC arm
 *   BMP_GetPixels 0x020437D4 arm
 *   func_02040B58 0x02040B58 arm
 *   ARC_UTIL_UploadBgPaletteAddFromArchive 0x0204994C arm
 *   func_02045B38 0x02045B38 arm
 *   BMP_CopyPixels        0x02043814  arm
 *   BMP_Delete        0x020437AC  arm
 *   func_02045EC0        0x02045EC0  arm
 *   PRINTSYS_PrintQueColor        0x0201C724  thumb
 *   STRBUF_Delete        0x02045808  arm
 *   data_021C84F4        0x021C84F4  data
 *   PRINTSYS_QUE_IsExistTarget  0x0201C6C4  thumb
 *   func_02040B1C  0x02040B1C  arm
 *   MSGDATA_Delete 0x02045C04 arm
 *   BMP_WIN_Delete 0x020452E8 arm
 *   ZUKAN_DETAIL_HEADBAR_GetIconKind  0x021BE840  thumb  ov208
 *   ZUKAN_DETAIL_HEADBAR_SetIconKind  0x021BE82C  thumb  ov208
 *   ZUKAN_DETAIL_HEADBAR_SetIconSpecies  0x021BE844  thumb  ov208
 *   ZUKAN_DETAIL_HEADBAR_SetIconForm  0x021BE854  thumb  ov208
 */
#include "zukan_detail_types.h"
#include "../../matched/include/Obj05867.h"
#include "zukan_detail_procsys_shared_types.h"
#include "zukan_detail_common_shared_types.h"
#include "zukan_detail_headbar_shared_types.h"

extern u32 func_020307B0(void *p);

extern void ARC_UTIL_UploadPaletteFromHandle(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 a6);

extern void func_020413B0(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);

extern void ARC_TOOL_DeleteHandle(void *h);

extern void func_0203FB44(u32 layer, u32 offset, u32 size);

extern void func_02041EE4(u32 index, u32 a, u32 b);

extern void func_02030EAC(struct Node *n);

extern void PRINTSYS_QUE_Clear(struct PrintSys *p);

extern void PRINTSYS_QUE_Delete(struct PrintSys *p);

struct Ov208Icon_021BE710 { u16 heap,pad2; unsigned f4,f8; int fc; unsigned pad10[2],f18,f1c,f20,f24,f28,f2c,f30; };

struct Ov208Icon_021BE7A4 { u16 heap,pad2; unsigned f4,f8; int fc; unsigned char count,pad11[7]; unsigned f18,f1c,f20,f24,f28,f2c,f30; };

struct Ov208PalTbl {
    u32 v[5];
};

extern void *func_02030734(unsigned,unsigned,int,const char *,unsigned short);

extern void *func_020056A0(unsigned,unsigned,unsigned);

extern void *func_020490F4(unsigned int id, unsigned int heap);

extern void func_02040618(unsigned,unsigned,unsigned);

extern void func_0204047C(int,u16);

extern u32 func_02040804(u32 layer);

extern void func_021BE920(struct Ov208Icon_021BE710 *);

extern void func_021BE864(void *);

extern unsigned PRINTSYS_QUE_Create(void *);

extern void func_021BE9CC(struct Ov208Icon_021BE7A4 *);

extern unsigned PRINTSYS_QUE_Main(struct PrintSys *);

extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);

extern void *BMP_WIN_GetBmp(struct Descriptor *a);

extern void BMP_Clear(struct CharBuf *buf, u8 value);

extern void BMP_WIN_TransferChars(struct Descriptor *a);

extern struct Bmp *BMP_CreateFromArchive(u32 arc, u32 member, u32 heap2, u32 heap);

extern u32 BMP_GetByteSize(const struct Bmp *bmp);

extern void *BMP_GetPixels(const struct Bmp *bmp);

extern u32 func_02040B58(u32 index, const void *src, u32 size);

extern u32 ARC_UTIL_UploadBgPaletteAddFromArchive(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7);

extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);

extern unsigned int MSGDATA_Delete(struct Rec *rec);

extern void BMP_Delete(struct Obj020437AC *p);

extern u32 BMP_WIN_Delete(struct Descriptor *d);

extern void BMP_CopyPixels(struct Bmp *dst, const struct Bmp *src);

extern void *func_02045EC0(struct MsgBank *bank, u32 index);

extern void PRINTSYS_PrintQueColor(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);

extern void STRBUF_Delete(struct U16Vec *vec);

extern u32 PRINTSYS_QUE_IsExistTarget(struct PrintSys *p, void *v);

extern void func_02040B1C(int index, const void *src, u32 size, u32 tile);

extern void func_02041B6C(u32 layer);

extern void PRINTSYS_PrintQueColor(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);

struct Ov208Icon_021BE710 *ZUKAN_DETAIL_HEADBAR_Create(u16 heap,unsigned arg);

void ZUKAN_DETAIL_HEADBAR_Delete(struct Ov208Scene *m);

void ZUKAN_DETAIL_HEADBAR_Update(struct Ov208Icon_021BE7A4 *p);

void ZUKAN_DETAIL_HEADBAR_SetIconKind(struct Ov208Icon_021BE82C *p, int kind);

int ZUKAN_DETAIL_HEADBAR_GetIconKind(struct Ov208Icon_021BE840 *p);

void ZUKAN_DETAIL_HEADBAR_SetIconSpecies(struct Ov208Icon_021BE844 *p);

void ZUKAN_DETAIL_HEADBAR_SetIconForm(struct Ov208Icon_021BE854 *p);

void ZUKAN_DETAIL_HEADBAR_NoOp(void *p);

void ZUKAN_DETAIL_HEADBAR_CreateWindows(struct Ov208Gfx *g);

void ZUKAN_DETAIL_HEADBAR_DeleteWindows(char *p);

void ZUKAN_DETAIL_HEADBAR_DrawIcon(struct Ov208Icon *p);

void ZUKAN_DETAIL_HEADBAR_ClearIcon();

void ZUKAN_DETAIL_HEADBAR_FlushIcon(struct Ov208Icon *p);

extern const char d_021C8DFC[];

extern const struct Ov208PalTbl data_021C84F4;

struct Ov208Icon_021BE710 *ZUKAN_DETAIL_HEADBAR_Create(u16 heap,unsigned arg)
{
    struct Ov208Icon_021BE710 *p=func_02030734(heap,0x34,1,d_021C8DFC,120);
    p->heap=heap;p->f4=arg;p->f8=0;p->fc=5;
    func_02040618(5,3,24);
    func_0204047C(5,0);
    ZUKAN_DETAIL_HEADBAR_CreateWindows((struct Ov208Gfx *)p);
    func_021BE920(p);
    p->f28=(unsigned)func_020056A0((unsigned)func_021BE864,(unsigned)p,1);
    p->f2c=PRINTSYS_QUE_Create((void *)(unsigned)p->heap);
    p->f30=0;
    return p;
}

/*
 * tail: two zero alignment bytes after the function (listing extent is 2 bytes longer).
 */
void ZUKAN_DETAIL_HEADBAR_Delete(struct Ov208Scene *m)
{
    PRINTSYS_QUE_Clear((void *)m->f2c);
    PRINTSYS_QUE_Delete((struct PrintSys *)m->f2c);
    func_02030EAC((struct Node *)m->f28);
    ZUKAN_DETAIL_HEADBAR_ClearIcon(m);
    ZUKAN_DETAIL_HEADBAR_DeleteWindows((char *)m);
    func_020307B0(m);
}

/*
 * matching: direct byte field access avoids a persistent extracted pointer register.
 */
void ZUKAN_DETAIL_HEADBAR_Update(struct Ov208Icon_021BE7A4 *p)
{
    switch(p->f8) {
    case 0: case 2: break;
    case 1:
        if(p->count==0) {
            if((int)func_02040804(5)<=0) {
                func_02041EE4(5,3,0);p->f8=2;
            } else {func_02041EE4(5,5,3);p->count=0;}
        } else --p->count;
        break;
    case 3:
        if(p->count==0) {
            if((int)func_02040804(5)>=24) {
                func_02041EE4(5,3,24);p->f8=0;
            } else {func_02041EE4(5,4,3);p->count=0;}
        } else --p->count;
        break;
    }
    func_021BE9CC(p);
    PRINTSYS_QUE_Main((struct PrintSys *)p->f2c);
}

void ZUKAN_DETAIL_HEADBAR_SetIconKind(struct Ov208Icon_021BE82C *p, int kind)
{
    p->fc = kind;
    ZUKAN_DETAIL_HEADBAR_ClearIcon();
    ZUKAN_DETAIL_HEADBAR_DrawIcon((struct Ov208Icon *)p);
}

int ZUKAN_DETAIL_HEADBAR_GetIconKind(struct Ov208Icon_021BE840 *p)
{
    return p->state;
}

void ZUKAN_DETAIL_HEADBAR_SetIconSpecies(struct Ov208Icon_021BE844 *p)
{
    if (p->state != 2) {
        p->state = 1;
        p->step = 0;
    }
}

void ZUKAN_DETAIL_HEADBAR_SetIconForm(struct Ov208Icon_021BE854 *p)
{
    if (p->state != 0) {
        p->state = 3;
        p->step = 0;
    }
}

void ZUKAN_DETAIL_HEADBAR_NoOp(void *p)
{
}

/*
 * tail: two zero alignment bytes after the function (listing extent is 2 bytes longer).
 */
void ZUKAN_DETAIL_HEADBAR_CreateWindows(struct Ov208Gfx *g)
{
    g->f14 = BMP_WIN_Create(5, 0, 0, 0x10, 1, 13, 0);
    BMP_Clear((struct CharBuf *)((int)BMP_WIN_GetBmp((struct Descriptor *)g->f14)), 0);
    BMP_WIN_TransferChars((struct Descriptor *)g->f14);
    g->f18 = BMP_CreateFromArchive(0x9f, 14, 0, g->heap);
    g->f20 = BMP_GetByteSize(g->f18);
    g->f1c = func_02040B58(5, BMP_GetPixels(g->f18), g->f20);
    ARC_UTIL_UploadBgPaletteAddFromArchive(0x9f, 0x25, 5, 0, g->f1c, 0xc0, 0, g->heap);
    func_020413B0(5, 0, 0, 0x20, 0x18, 13);
    g->f24 = (int)func_02045B38(0, 2, 0xea, g->heap);
}

void ZUKAN_DETAIL_HEADBAR_DeleteWindows(char *p)
{
    MSGDATA_Delete((struct Rec *)(((struct Obj05867 *)p)->f24));
    func_0203FB44(5, ((struct Obj05867 *)p)->f1C, ((struct Obj05867 *)p)->f20);
    BMP_Delete((struct Obj020437AC *)(((struct Obj05867 *)p)->f18));
    BMP_WIN_Delete((struct Descriptor *)(((struct Obj05867 *)p)->f14));
}

void ZUKAN_DETAIL_HEADBAR_DrawIcon(struct Ov208Icon *p)
{
    struct Ov208PalTbl pal;
    void *h;
    u32 s;

    if (p->fc < 0 || p->fc >= 5)
        return;
    h = func_020490F4(0x9f, p->heap);
    pal = data_021C84F4;
    ARC_UTIL_UploadPaletteFromHandle(h, 4, 4, pal.v[p->fc] << 5, 0x1a0, 0x20, p->heap);
    ARC_TOOL_DeleteHandle(h);
    h = BMP_CreateFromArchive(0x9f, 0xe, 0, p->heap);
    BMP_CopyPixels(h, (const struct Bmp *)p->f18);
    BMP_Delete(h);
    s = (u32)func_02045EC0((struct MsgBank *)p->f24, p->fc + 0xb2);
    PRINTSYS_PrintQueColor((void *)p->f2c, p->f18, 0x18, 5, s, p->f4, 0x3dc0);
    STRBUF_Delete((struct U16Vec *)s);
    p->f30 = 1;
    ZUKAN_DETAIL_HEADBAR_FlushIcon(p);
}

void ZUKAN_DETAIL_HEADBAR_ClearIcon()
{
}

void ZUKAN_DETAIL_HEADBAR_FlushIcon(struct Ov208Icon *p)
{
    if (p->f30 != 0 && PRINTSYS_QUE_IsExistTarget((struct PrintSys *)p->f2c, (void *)p->f18) == 0) {
        func_02040B1C(5, BMP_GetPixels((const struct Bmp *)p->f18), p->f20, p->f1c);
        func_02041B6C(5);
        p->f30 = 0;
    }
}

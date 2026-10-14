/*
 * function: ZUKAN_DETAIL_AREA_LoadAreaEntries
 * address:  0x021C1AD4
 * packet:   pkt_ov208_021C1AD4
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ZUKAN_DETAIL_COMMON_GetCurrentEntry  0x021BC3C0  thumb  ov208
 *   ZUKAN_DETAIL_AREA_FreeAreaEntryData  0x021C1F44  thumb  ov208
 *   ZUKAN_DETAIL_AREA_LoadAreaEntryData  0x021C1F28  thumb  ov208
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm
 *   ZUKAN_DETAIL_AREA_DeletePokemonIcon  0x021C0C00  thumb  ov208
 *   ZUKAN_DETAIL_COMMON_GetSource  0x021BC3A4  thumb  ov208
 *   ZUKAN_SAVE_GetFromGameData  0x0200CA1C  thumb
 *   ZUKAN_SAVE_GetViewGenderAndForm  0x0200CC40  thumb
 *   ZUKAN_DETAIL_AREA_CreatePokemonIcon  0x021C0B6C  thumb  ov208
 *   PRINTSYS_QUE_Clear  0x0201C6EC  thumb
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   BMP_Clear  0x02043B5C  arm
 *   func_0201EC64  0x0201EC64  thumb
 *   func_02045EC0  0x02045EC0  arm
 *   STRBUF_Create  0x020457B0  arm
 *   func_0201EE60  0x0201EE60  thumb
 *   func_0201F250  0x0201F250  thumb
 *   STRBUF_Delete  0x02045808  arm
 *   func_0201ED04  0x0201ED04  thumb
 *   PRINTSYS_PrintQueColor  0x0201C724  thumb
 *   func_021C0740  0x021C0740  thumb  ov208
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   ZUKAN_DETAIL_AREA_DrawAreaSetTitle  0x021C1F50  thumb  ov208
 *   CLACT_SetActorAnimSeq  0x0204B878  arm
 */
#include "../include/Obj00081.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u8 f0;
    u8 f1;
    u8 rest[0x3c];
} Entry;

extern u16  ZUKAN_DETAIL_COMMON_GetCurrentEntry(int key);
struct CharBuf;
struct U16Vec;
struct WordSet;
extern void ZUKAN_DETAIL_AREA_FreeAreaEntryData(int a);
extern void *ZUKAN_DETAIL_AREA_LoadAreaEntryData(int a, int b, int c);
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *obj, unsigned int on);
struct MsgBank;
struct PrintSys;
extern void ZUKAN_DETAIL_AREA_DeletePokemonIcon(void *a, void *b);
extern int ZUKAN_DETAIL_COMMON_GetSource(int *p);
extern void *ZUKAN_SAVE_GetFromGameData(void *a);
extern void ZUKAN_SAVE_GetViewGenderAndForm(u8 *p, u16 id, u32 *out1, u32 *out2, u32 *outForm, u16 a5);
extern u32 ZUKAN_DETAIL_AREA_CreatePokemonIcon(u32 *slot, u32 a, u32 b, u32 res, u16 heap, u32 species, u32 form, u32 gender, u32 isEgg, u8 x, u8 y);
extern void PRINTSYS_QUE_Clear(struct PrintSys *p);
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern struct WordSet *func_0201EC64(u32 heap);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void func_0201EE60(struct WordSet *p, u32 i, u16 v);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void STRBUF_Delete(struct U16Vec *vec);
extern u32 func_0201ED04(struct WordSet *p);
extern void PRINTSYS_PrintQueColor(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_021C0740(u16 *heap, u8 *p, int key, u8 i);
extern void BMP_WIN_TransferChars(struct Descriptor *p);
extern void ZUKAN_DETAIL_AREA_DrawAreaSetTitle(u16 *heap, u8 *p, int key);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);

#define W(o) (*(u32 *)(p + (o)))
#define SLOT4C(i) (((u32 *)(p + 0x4c))[i])
#define SLOT5C(i) (((u32 *)(p + 0x5c))[i])

void ZUKAN_DETAIL_AREA_LoadAreaEntries(u16 *heap, u8 *p, int key)
{
    u32 prev;
    u16 id;
    void *win;
    void *str;
    void *buf;
    u32 out1, out2, form;

    prev = W(0x8c);
    id = ZUKAN_DETAIL_COMMON_GetCurrentEntry(key);
    ZUKAN_DETAIL_AREA_FreeAreaEntryData(W(0x94));
    W(0x94) = (u32)ZUKAN_DETAIL_AREA_LoadAreaEntryData(id, *heap, W(0x40c));
    W(0x8c) = ((Entry *)W(0x94))->f0 == 0;
    if (W(0x8c) == 0)
        W(0x90) = ((Entry *)W(0x94))[0].f1 == 0;
    else
        W(0x90) = ((Entry *)W(0x94))[p[0x78]].f1 == 0;

    if (SLOT5C(((struct Obj00081 *)p)->f64) != 0)
        CLACT_SetActorDrawEnable((struct Obj *)SLOT5C(((struct Obj00081 *)p)->f64), 0);
    ((struct Obj00081 *)p)->f64 = (((struct Obj00081 *)p)->f64 + 1) % 2;
    if (SLOT5C(((struct Obj00081 *)p)->f64) != 0) {
        if (SLOT5C(((struct Obj00081 *)p)->f64) != 0)
            ZUKAN_DETAIL_AREA_DeletePokemonIcon((void *)SLOT4C(((struct Obj00081 *)p)->f64), (void *)SLOT5C(((struct Obj00081 *)p)->f64));
        SLOT5C(*(int *)(p + 0x64)) = 0;
    }

    ZUKAN_SAVE_GetViewGenderAndForm(ZUKAN_SAVE_GetFromGameData((void *)ZUKAN_DETAIL_COMMON_GetSource((int *)key)), id, &out1, &out2, &form, *heap);
    SLOT5C(*(int *)(p + 0x64)) = ZUKAN_DETAIL_AREA_CreatePokemonIcon(&SLOT4C(((struct Obj00081 *)p)->f64), W(0x54), W(0x58), W(0),
                                               *heap, id, form, out1, 0, 0x38, 0xb0);
    W(0x24) = 0;
    PRINTSYS_QUE_Clear((struct PrintSys *)W(0x34));
    BMP_Clear(BMP_WIN_GetBmp((struct Descriptor *)W(0x14)), 0);
    win = func_0201EC64(*heap);
    str = func_02045EC0((struct MsgBank *)W(0xc), 0xbd);
    buf = STRBUF_Create(0x40, *heap);
    func_0201EE60(win, 0, id);
    func_0201F250(win, buf, str);
    STRBUF_Delete(str);
    func_0201ED04(win);
    PRINTSYS_PrintQueColor((void *)W(0x34), (u32)BMP_WIN_GetBmp((struct Descriptor *)W(0x14)), 0, 5, (u32)buf, W(4), 0x3c40);
    STRBUF_Delete(buf);
    W(0x24) = 1;
    func_021C0740(heap, p, key, 0);

    if (W(0x8c) == 0) {
        if (prev == 1) {
            W(0x2c) = 0;
            PRINTSYS_QUE_Clear((struct PrintSys *)W(0x3c));
            BMP_Clear(BMP_WIN_GetBmp((struct Descriptor *)W(0x1c)), 0);
            BMP_WIN_TransferChars((struct Descriptor *)W(0x1c));
            CLACT_SetActorDrawEnable((struct Obj *)W(0xbc), 0);
            CLACT_SetActorDrawEnable((struct Obj *)W(0xc4), 0);
            CLACT_SetActorDrawEnable((struct Obj *)W(0xc0), 0);
        }
    } else if (prev == 0) {
        ZUKAN_DETAIL_AREA_DrawAreaSetTitle(heap, p, key);
        CLACT_SetActorDrawEnable((struct Obj *)W(0xbc), 1);
        CLACT_SetActorAnimSeq((struct Obj *)W(0xc4), 2);
        CLACT_SetActorDrawEnable((struct Obj *)W(0xc4), 1);
        CLACT_SetActorAnimSeq((struct Obj *)W(0xc0), 4);
        CLACT_SetActorDrawEnable((struct Obj *)W(0xc0), 1);
    }
}

/*
 * function: BTLV_INPUT_DrawSelectScreenText
 * address: 0x0220558C
 * packet: pkt_ov094_0220558C
 * region: ov094
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * trailing: 022056B2..022056B4 is two-byte alignment padding.
 * blocker (cleared 2026-10-01, arm9 leaf filed): ARM9 0x02021728 lacks an outside witness at +010C.
 * Verified EXACT C copied from ov029_func_021F0DB4.c:
 * int PALANM_GetDefaultWork(char *p, int i) { return *(int *)(p + i * 0x14); }
 * symbols:
 *   WORDSET_CreateDefault 0x0201EC64 thumb
 *   STRBUF_Create 0x020457B0 arm
 *   func_02045EC0 0x02045EC0 arm
 *   GF_FONT_GetTextColor 0x0201DE00 thumb
 *   GF_FONT_SetTextColor 0x0201DD78 thumb
 *   WORDSET_SetSlotNumber 0x0201EFA4 thumb
 *   WORDSET_CopyTaggedText 0x0201F250 thumb
 *   PRINTSYS_Print 0x0201C7A4 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   WORDSET_DeleteStrbufED04 0x0201ED04 thumb
 *   BTLV_EFFECT_GetPalanm 0x021F86E0 thumb ov094
 *   PALANM_GetDefaultWork 0x02021728 thumb
 *   PALANM_CopyToSlot 0x020215BC thumb
 */
#include "../include/Obj02440.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short   s16;
struct PalAnmSlot;
struct WordSet;
extern struct WordSet *WORDSET_CreateDefault(u32 heap);
struct MsgBank;
struct U16Vec;
struct WordSet;
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void GF_FONT_GetTextColor(u8 *, u8 *, u8 *);
extern void GF_FONT_SetTextColor(u32, u32, u32);
extern void WORDSET_SetSlotNumber(u32, u32, u32, u32, u32, u32);
extern void WORDSET_CopyTaggedText(struct WordSet *ws, void *dst, void *src);
extern void PRINTSYS_Print(void *x, s16 y, s16 z, void *s, void *w);
extern void STRBUF_Delete(struct U16Vec *vec);
extern u32 WORDSET_DeleteStrbufED04(struct WordSet *p);
extern int BTLV_EFFECT_GetPalanm(void);
extern int PALANM_GetDefaultWork(char *, int);
extern void PALANM_CopyToSlot(struct PalAnmSlot *slots, const void *src, u32 idx, u32 off, u16 size);
void BTLV_INPUT_DrawSelectScreenText(char *s, const int *b)
{
    int h;
    void *v;
    void *w;
    void *extra;
    u8 c[3];
    h = (int)WORDSET_CreateDefault(((struct Obj02440 *)s)->f240);
    v = STRBUF_Create(8, ((struct Obj02440 *)s)->f240);
    w = func_02045EC0(((struct Obj02440 *)s)->f5C, 6);
    GF_FONT_GetTextColor(&c[2], &c[1], &c[0]);
    GF_FONT_SetTextColor(9, 10, 0);
    WORDSET_SetSlotNumber(h, 0, b[2], 3, 2, 1);
    WORDSET_CopyTaggedText((void *)h, v, w);
    PRINTSYS_Print((void *)(((struct Obj02440 *)s)->f22C), 0x8c, 8, v, (void *)(((struct Obj02440 *)s)->f224));
    if (b[0] != b[1])
        GF_FONT_SetTextColor(7, 8, 0);
    WORDSET_SetSlotNumber(h, 0, b[1], 3, 2, 1);
    WORDSET_CopyTaggedText((void *)h, v, w);
    PRINTSYS_Print((void *)(((struct Obj02440 *)s)->f22C), 0x60, 8, v, (void *)(((struct Obj02440 *)s)->f224));
    GF_FONT_SetTextColor(1, 2, 0);
    extra = func_02045EC0(((struct Obj02440 *)s)->f5C, 7);
    PRINTSYS_Print((void *)(((struct Obj02440 *)s)->f22C), 0x7c, 8, extra, (void *)(((struct Obj02440 *)s)->f224));
    STRBUF_Delete(extra);
    GF_FONT_SetTextColor(c[2], c[1], c[0]);
    WORDSET_DeleteStrbufED04((struct WordSet *)h);
    STRBUF_Delete(w);
    STRBUF_Delete(v);
    PALANM_CopyToSlot((struct PalAnmSlot *)(((struct Obj02440 *)s)->f64), (u16 *)(PALANM_GetDefaultWork((char *)BTLV_EFFECT_GetPalanm(), 1) + 0x40), 1, 0x70, 0x20);
}

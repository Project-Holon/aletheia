/*
 * function: BTLV_INPUT_DrawRunButtonText
 * address:  0x02206728
 * packet:   pkt_ov094_02206728
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   STRBUF_Create  0x020457B0  arm
 *   func_02045EC0  0x02045EC0  arm
 *   STRBUF_Delete  0x02045808  arm
 *   WORDSET_CreateDefault  0x0201EC64  thumb
 *   GF_FONT_GetTextColor  0x0201DE00  thumb
 *   GF_FONT_SetTextColor  0x0201DD78  thumb
 *   WORDSET_SetSlotNumber  0x0201EFA4  thumb
 *   WORDSET_CopyTaggedText  0x0201F250  thumb
 *   PRINTSYS_Print  0x0201C7A4  thumb
 *   WORDSET_Delete  0x0201ED04  thumb
 *   BTLV_INPUT_GetTextBlockSize  0x02204C98  thumb  ov094
 *   BTLV_EFFECT_IsRecordEnabledInComm  0x021F88F4  thumb  ov094
 */
#include "../include/Obj05249.h"
#include "../include/Obj21799.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int BTLV_EFFECT_IsRecordEnabledInComm(void);
typedef signed short   s16;
struct WordSet;
extern struct WordSet *WORDSET_CreateDefault(u32 heap);
struct MsgBank;
struct U16Vec;
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void GF_FONT_GetTextColor(u8 *a, u8 *b, u8 *c);
extern void GF_FONT_SetTextColor(u32 r, u32 g, u32 b);
extern void WORDSET_SetSlotNumber(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void WORDSET_CopyTaggedText(struct WordSet *ws, void *dst, void *src);
struct StrObj;
extern void BTLV_INPUT_GetTextBlockSize(struct StrObj *a, int b, int *outn, int *outq);
extern void PRINTSYS_Print(void *x, s16 y, s16 z, void *s, void *w);
extern u32 WORDSET_Delete(struct WordSet *p);

void BTLV_INPUT_DrawRunButtonText(char *s, char *b)
{
    int h;
    void *v;
    void *w;
    int v18;
    int v14;
    u8 c[3];

    if (BTLV_EFFECT_IsRecordEnabledInComm() == 0)
        return;
    h = (int)WORDSET_CreateDefault(((struct Obj05249 *)s)->f240);
    v = STRBUF_Create(6, ((struct Obj05249 *)s)->f240);
    w = func_02045EC0(((struct Obj05249 *)s)->f5C, 8);
    GF_FONT_GetTextColor(&c[2], &c[1], &c[0]);
    GF_FONT_SetTextColor(1, 2, 0);
    WORDSET_SetSlotNumber((struct WordSet *)h, 0, ((struct Obj21799 *)b)->fC4, 2, 0, 1);
    WORDSET_CopyTaggedText((struct WordSet *)h, v, w);
    BTLV_INPUT_GetTextBlockSize((struct StrObj *)v, ((struct Obj05249 *)s)->f224, &v18, &v14);
    PRINTSYS_Print((void *)(((struct Obj05249 *)s)->f234), 12 - v18 / 2, 0, v, (void *)(((struct Obj05249 *)s)->f224));
    GF_FONT_SetTextColor(c[2], c[1], c[0]);
    WORDSET_Delete((struct WordSet *)h);
    STRBUF_Delete(w);
    STRBUF_Delete(v);
}

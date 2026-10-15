/*
 * function: RESEARCH_GRAPH_PrintSliceLabel
 * address:  0x021BF15C
 * packet:   pkt_ov217_021BF15C
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   RESEARCH_GRAPH_GetLeftCircle 0x021BF76C thumb ov217
 *   RESEARCH_GRAPH_GetGroupValue 0x021BF810 thumb ov217
 *   RESEARCH_GRAPH_GetEntryKey 0x021BF7F4 thumb ov217
 *   RESEARCH_GRAPH_GetEntryValue 0x021BF854 thumb ov217
 *   BgTextLabel_SetVisible 0x021C0FF8 thumb ov217
 *   BgTextLabel_PrintText 0x021C0F78 thumb ov217
 *   CircleGraph_FindSliceIndex 0x021C11C8 thumb ov217
 *   CircleGraph_GetPercentByKey 0x021C11DC thumb ov217
 *   func_02045EC0 0x02045EC0 arm
 *   STRBUF_Create 0x020457B0 arm
 *   STRBUF_Delete 0x02045808 arm
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_0201EE0C 0x0201EE0C thumb
 *   func_0201F250 0x0201F250 thumb
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00021.h"

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
extern u8 *RESEARCH_GRAPH_GetLeftCircle(void *p);
extern u32 RESEARCH_GRAPH_GetGroupValue(void *p);
extern u32 RESEARCH_GRAPH_GetEntryKey(void *p);
struct MsgBank;
struct U16Vec;
struct WordSet;
extern u32 RESEARCH_GRAPH_GetEntryValue(char *p);
extern void BgTextLabel_SetVisible(u8 *p, int visible);
extern void BgTextLabel_PrintText(u8 *p, struct U16Vec *text);
extern u8 CircleGraph_FindSliceIndex(u8 *p, u8 key);
extern u8 CircleGraph_GetPercentByKey(u8 *p, u8 key);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201EE0C(struct WordSet *p, u32 i, const void *src, u32 n, u32 f, u32 c);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
void RESEARCH_GRAPH_PrintSliceLabel(char *p)
{
    u32 t = ((struct Obj00021 *)p)->f354;
    u8 *o = RESEARCH_GRAPH_GetLeftCircle(p);
    u32 k;
    u32 a, b, c;
    void *x, *y, *z;
    if (((struct Obj00021 *)p)->f3C8 == 0 || ((struct Obj00021 *)p)->f3D0 == 1) {
        BgTextLabel_SetVisible((u8 *)t, 0);
        return;
    }
    if (RESEARCH_GRAPH_GetGroupValue(p) == 0) {
        BgTextLabel_SetVisible((u8 *)t, 0);
        return;
    }
    k = RESEARCH_GRAPH_GetEntryKey(p);
    a = CircleGraph_FindSliceIndex(o, (u8)k);

    b = RESEARCH_GRAPH_GetEntryValue(p);
    c = CircleGraph_GetPercentByKey(o, (u8)k);
    x = func_02045EC0(((struct Obj00021 *)p)->fC, 0xd);
    y = func_02045EC0(((struct Obj00021 *)p)->f14, k);
    z = STRBUF_Create(0x80, ((struct Obj00021 *)p)->f4);
    func_0201EFA4(((struct Obj00021 *)p)->f18, 0, a + 1, 2, 1, 1);
    func_0201EE0C(((struct Obj00021 *)p)->f18, 1, y, 0, 1, 2);
    func_0201EFA4(((struct Obj00021 *)p)->f18, 2, b, 5, 1, 1);
    func_0201EFA4(((struct Obj00021 *)p)->f18, 3, c, 3, 1, 1);
    func_0201F250(((struct Obj00021 *)p)->f18, z, x);
    BgTextLabel_PrintText((u8 *)t, z);
    BgTextLabel_SetVisible((u8 *)t, 1);
    STRBUF_Delete(x);
    STRBUF_Delete(z);
    STRBUF_Delete(y);
}

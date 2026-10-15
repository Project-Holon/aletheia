/*
 * function: GFL_NET_ERR_DrawWindow
 * address:  0x020101D4
 * packet:   pkt_02010068
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GFL_NET_ERR_GetMessageId      0x02010158  thumb
 *   gNetErrWork        0x0214617C  data
 *   G2_GetBG1ScrPtr   0x0207DFB4  arm
 *   G2_GetBG1CharPtr  0x0207E24C  arm
 *   MIi_CpuClear16    0x02082A48  arm
 *   BMP_CreateFromVram     0x02043754  arm
 *   WORDSET_CreateDefault     0x0201EC64  thumb
 *   GF_FONT_Create     0x0201D7EC  thumb
 *   func_02045B38     0x02045B38  arm
 *   WORDSET_SetSlotNumber     0x0201EFA4  thumb
 *   func_02045EC0     0x02045EC0  arm
 *   STRBUF_Create     0x020457B0  arm
 *   WORDSET_CopyTaggedText     0x0201F250  thumb
 *   PRINTSYS_PrintColor     0x0201C7D0  thumb
 *   STRBUF_Delete     0x02045808  arm
 *   MSGDATA_Delete     0x02045C04  arm
 *   GF_FONT_Delete     0x0201D83C  thumb
 *   WORDSET_DeleteStrbufED04     0x0201ED04  thumb
 *   BMP_Delete     0x020437AC  arm
 *
 * Draws net_err.c's error window: tiles BG1's screen with a running
 * character index, clears the character block to 0x7777, builds a surface,
 * a window object and a palette, picks the message (0x40 for a1 == 1; the
 * mapped error code from GFL_NET_ERR_GetMessageId or the stored +0x60 code in link
 * modes 1/2/6; else message 1, or 0 unless a0 == 1), prints it and frees
 * everything.  Wave 13 levers (the earlier note stopped 4 bytes long): the
 * non-link arm's message index is the SAME variable as the constant 1 its
 * two calls pass (idx = 1 kept unless a0 != 1), which is what lets 1.1p1
 * hold 1 in r5 for the whole function; the pools were 0x0214617C / 0x7777 /
 * 0x189 / 0x1167; and the last register pair (scr vs x in the fill loop)
 * closed with the permuter's anneal: x declared before arc, pal after y,
 * and the screen pointer received through a named local.
 */
#include "../include/Obj04039.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern u8   gNetErrWork[];

extern u16 *G2_GetBG1ScrPtr(void);
extern u8  *G2_GetBG1CharPtr(void);
extern void MIi_CpuClear16(u16 data, void *dst, u32 size);
typedef signed short   s16;
struct Bmp;
struct GfFont;
struct MsgBank;
struct Obj020437AC;
struct Rec;
struct U16Vec;
struct WordSet;
extern struct Bmp *BMP_CreateFromVram(void *pixels, u32 width, u32 height, u32 depth, u16 heap);
extern struct WordSet *WORDSET_CreateDefault(u32 heap);
extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void WORDSET_SetSlotNumber(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void WORDSET_CopyTaggedText(struct WordSet *ws, void *dst, void *src);
extern void PRINTSYS_PrintColor(void *x, s16 y, s16 z, void *s, void *w, u16 v);
extern void STRBUF_Delete(struct U16Vec *vec);
extern u32 MSGDATA_Delete(struct Rec *rec);
extern u32 GF_FONT_Delete(void *ptr);
extern u32 WORDSET_DeleteStrbufED04(struct WordSet *p);
extern void BMP_Delete(struct Obj020437AC *p);
extern u32 GFL_NET_ERR_GetMessageId(u8 *obj, u32 a);

void GFL_NET_ERR_DrawWindow(u32 a0, u32 a1)
{
    u8 *g = gNetErrWork;
    u16 *scr;
    void *surf;
    void *obj;
    s32 x;
    void *arc;
    u32 idx;
    void *k;
    void *buf;
    s32 y;
    void *pal;
    u16 *res;
    u16 c;

    res = G2_GetBG1ScrPtr();
    scr = res;
    c = 0x20;
    for (y = 4; y < 0x14; y++) {
        for (x = 1; x < 0x1f; x++) {
            scr[y * 0x20 + x] = c;
            c = (u16)(c + 1);
        }
    }
    MIi_CpuClear16(0x7777, G2_GetBG1CharPtr() + 0x400, 0x3c00);
    surf = BMP_CreateFromVram(G2_GetBG1CharPtr() + 0x400, 0x1e, 0x10, 0x20, 1);
    obj = WORDSET_CreateDefault(1);
    pal = GF_FONT_Create(0x17, 0, 0, 0, 1);

    if (a1 == 1) {
        arc = func_02045B38(0, 2, 0xe8, 1);
        idx = 0x40;
    } else {
        u8 m = g[0x59];

        if (m == 1 || m == 2 || m == 6) {
            WORDSET_SetSlotNumber(obj, 0, ((struct Obj04039 *)g)->f48, 5, 2, 1);
            arc = func_02045B38(0, 2, 0xe8, 1);
            if (g[0x5a] != 0) {
                idx = ((struct Obj04039 *)g)->f60;
                g[0x5a] = 0;
            } else {
                idx = GFL_NET_ERR_GetMessageId(g + 0x48, ((struct Obj04039 *)g)->f60);
            }
        } else {
            WORDSET_SetSlotNumber(obj, 0, g[0x58], 5, 2, 1);
            arc = func_02045B38(0, 2, 0x52, 1);
            idx = 1;
            if (a0 != 1) {
                idx = 0;
            }
        }
    }

    k = func_02045EC0(arc, idx);
    buf = STRBUF_Create(0x189, 1);
    WORDSET_CopyTaggedText(obj, buf, k);
    PRINTSYS_PrintColor(surf, 0, 0, buf, pal, 0x1167);
    STRBUF_Delete(buf);
    STRBUF_Delete(k);
    MSGDATA_Delete(arc);
    GF_FONT_Delete(pal);
    WORDSET_DeleteStrbufED04(obj);
    BMP_Delete(surf);
}

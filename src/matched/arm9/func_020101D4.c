/*
 * function: func_020101D4
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
 *   sub_02010158      0x02010158  thumb
 *   g_0214617C        0x0214617C  data
 *   G2_GetBG1ScrPtr   0x0207DFB4  arm
 *   G2_GetBG1CharPtr  0x0207E24C  arm
 *   MIi_CpuClear16    0x02082A48  arm
 *   func_02043754     0x02043754  arm
 *   func_0201EC64     0x0201EC64  thumb
 *   func_0201D7EC     0x0201D7EC  thumb
 *   func_02045B38     0x02045B38  arm
 *   func_0201EFA4     0x0201EFA4  thumb
 *   func_02045EC0     0x02045EC0  arm
 *   func_020457B0     0x020457B0  arm
 *   func_0201F250     0x0201F250  thumb
 *   func_0201C7D0     0x0201C7D0  thumb
 *   func_02045808     0x02045808  arm
 *   func_02045C04     0x02045C04  arm
 *   func_0201D83C     0x0201D83C  thumb
 *   func_0201ED04     0x0201ED04  thumb
 *   func_020437AC     0x020437AC  arm
 *
 * Draws net_err.c's error window: tiles BG1's screen with a running
 * character index, clears the character block to 0x7777, builds a surface,
 * a window object and a palette, picks the message (0x40 for a1 == 1; the
 * mapped error code from sub_02010158 or the stored +0x60 code in link
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

extern u8   g_0214617C[];

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
extern struct Bmp *func_02043754(void *pixels, u32 width, u32 height, u32 depth, u16 heap);
extern struct WordSet *func_0201EC64(u32 heap);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_0201C7D0(void *x, s16 y, s16 z, void *s, void *w, u16 v);
extern void func_02045808(struct U16Vec *vec);
extern u32 func_02045C04(struct Rec *rec);
extern u32 func_0201D83C(void *ptr);
extern u32 func_0201ED04(struct WordSet *p);
extern void func_020437AC(struct Obj020437AC *p);
extern u32 sub_02010158(u8 *obj, u32 a);

void func_020101D4(u32 a0, u32 a1)
{
    u8 *g = g_0214617C;
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
    surf = func_02043754(G2_GetBG1CharPtr() + 0x400, 0x1e, 0x10, 0x20, 1);
    obj = func_0201EC64(1);
    pal = func_0201D7EC(0x17, 0, 0, 0, 1);

    if (a1 == 1) {
        arc = func_02045B38(0, 2, 0xe8, 1);
        idx = 0x40;
    } else {
        u8 m = g[0x59];

        if (m == 1 || m == 2 || m == 6) {
            func_0201EFA4(obj, 0, ((struct Obj04039 *)g)->f48, 5, 2, 1);
            arc = func_02045B38(0, 2, 0xe8, 1);
            if (g[0x5a] != 0) {
                idx = ((struct Obj04039 *)g)->f60;
                g[0x5a] = 0;
            } else {
                idx = sub_02010158(g + 0x48, ((struct Obj04039 *)g)->f60);
            }
        } else {
            func_0201EFA4(obj, 0, g[0x58], 5, 2, 1);
            arc = func_02045B38(0, 2, 0x52, 1);
            idx = 1;
            if (a0 != 1) {
                idx = 0;
            }
        }
    }

    k = func_02045EC0(arc, idx);
    buf = func_020457B0(0x189, 1);
    func_0201F250(obj, buf, k);
    func_0201C7D0(surf, 0, 0, buf, pal, 0x1167);
    func_02045808(buf);
    func_02045808(k);
    func_02045C04(arc);
    func_0201D83C(pal);
    func_0201ED04(obj);
    func_020437AC(surf);
}

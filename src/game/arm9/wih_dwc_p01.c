/*
 * file:     wih_dwc_p01.c
 * unit:     yes
 * function: func_02010158, func_020101D4, func_0201034C, sub_02010360
 * address:  0x02010158
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0202EB0C  0x0202EB0C  thumb
 *   g_0214617C     0x0214617C  data
 *   tbl_0209DEB0   0x0209DEB0  data  a2
 *   tbl_0209DED0   0x0209DED0  data  a2
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
 *   g_021461E0     0x021461E0  data
 *   sWihDwc        0x020A7240  data
 *   sWihDwcFile    0x020A7244  data
 *   func_02034714  0x02034714  arm
 *   func_0203D7C8  0x0203D7C8  arm
 *   func_0205D010  0x0205D010  arm
 *   func_02034AC4  0x02034AC4  arm
 *   func_0217963C  0x0217963C  thumb  ov014
 *   func_0201045C  0x0201045C  thumb
 *   ov015_id       0x0000000F  data
 */
#include "../../matched/include/Obj16724.h"
#include "../../matched/include/Obj04039.h"
#include "../../matched/include/Obj07083.h"

struct Bmp;
struct GfFont;
struct MsgBank;
struct Obj020437AC;
struct Rec;
struct U16Vec;
struct WordSet;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed int     s32;

typedef signed short   s16;

struct WihCtx {
    u8 *f0;         /* +0x00 */
    u8 *f4;         /* +0x04 */
};

extern u32 func_0202EB0C(void);
extern u16 *G2_GetBG1ScrPtr(void);
extern u8  *G2_GetBG1CharPtr(void);
extern void MIi_CpuClear16(u16 data, void *dst, u32 size);
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
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void *func_0203D7C8(u32 heap, u32 size, const char *file, u16 line);
extern u32  func_0205D010(void);
extern int func_02034AC4(int id);
extern void func_0217963C(u32 v);
extern void func_0201045C(const void *src);
u32 sub_02010158(u8 *obj, u32 a);
void func_020101D4(u32 a0, u32 a1);
int func_0201034C(void);
u8 *sub_02010360(int idx, void *heap);
extern u8  g_0214617C[];
extern const u16 tbl_0209DEB0[];
extern const u16 tbl_0209DED0[];
extern struct WihCtx g_021461E0;
extern u8 sWihDwc;
extern u8 sWihDwcFile[];
extern u8 ov015_id[];



/*
 * The error-code mapper of net_err.c: a reason code at obj+0xc (obj is the
 * 16-byte block the module keeps at 0x0214617C+0x48) in 0x3EE..0x3F7 maps to
 * a fixed message id; anything else indexes one of two sixteen-entry u16
 * tables by the module's +0x60 error number, picked by func_0202EB0C().
 * Wave 13: the earlier DIFF note read the pools as 0x0202617C / 0x020109B0 /
 * 0x020109D0; the words are 0x0214617C / 0x0209DEB0 / 0x0209DED0, and the
 * case 0x3F7 arm shares case 0x3EE's block (both table slots 0x12).
 */
u32 sub_02010158(u8 *obj, u32 a)
{
    u32 v;

    switch (((struct Obj16724 *)obj)->fC) {
    case 0x3ee:
    case 0x3f7:
        return 0xd;
    case 0x3f1:
        return 0x28;
    case 0x3f2:
    case 0x3f3:
    case 0x3f4:
    case 0x3f5:
    case 0x3f6:
        return 0xe;
    case 0x3f0:
        return 0x28;
    }
    if (func_0202EB0C() != 0) {
        v = *(u32 *)(g_0214617C + 0x60);
        if (v >= 0x10) {
            return 0xb;
        }
        return tbl_0209DED0[v];
    }
    v = *(u32 *)(g_0214617C + 0x60);
    if (v >= 0x10) {
        return 0xb;
    }
    return tbl_0209DEB0[v];
}



/*
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


int func_0201034C(void){ int t0 = func_020053EC(); int t1 = func_02034F5C((int)t0); int t2 = func_02005BC0((int)t1); int t3 = func_020065FC((int)t2); return t3; }


/*
 * Byte-correct, MATCH-capped.  NOT in the manifest; see src/pending/README.md.
 *
 * note:     rewritten 2026-09-23 (wave 14): every concrete byte right, 11 of
 *           12 relocation sites resolved.
 *
 *           Thumb leaf in ov014 (wih.c): 0x0217963C decodes as
 *           `ldr r1,[pc,#8]; ldr r2,[r1]; ldr r1,[pc,#8]; str r0,[r2,r1];
 *           bx lr`, a setter of word +0x1E88 of the object behind 0x021797A8
 *           (the same shape as the labelled func_02179628 just before it,
 *           which sets +0x1E84).  asm/overlays/ov014.s prints it as .word
 *           data, so attest_overlay_label() has no label to accept.  SEED
 *           REQUEST for the integrator: `ov014 0x0217963C thumb`, evidence
 *           the bl at arm9 0x020103B6 (this function) and 0x020103FE
 *           (func_020103E4).  Once seeded, 0x020103FE is an outside witness
 *           for this file and 0x020103B6 for func_020103E4: both go EXACT
 *           with no C change.
 *
 * wih_dwc.c constructor: allocates the 0x328-byte object (line 0x49), stores
 * the index at +0x310, allocates a second buffer sized by func_0205D010
 * (line 0x4C) into +0x300, registers func_0201045C as the ov014 receive
 * callback, publishes the object in the global and copies the global's
 * second word into +0x304.  func_020103E4 is its destructor.
 * Two readings corrected from the previous file: the pool word is
 * 0x021461E0 (not 0x020461E0), and 0x0201045D is the Thumb address of
 * func_0201045C, a function pointer, not data.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/sub_02010360.c \
 *       --func sub_02010360 --addr 0x02010360 --thumb
 */
u8 *sub_02010360(int idx, void *heap)
{
    u8 *p;

    if (idx > 4) {
        func_02034714((const char *)(&sWihDwc), 0, (const char *)(&sWihDwc));
    }
    if (g_021461E0.f0 != 0) {
        func_02034714((const char *)(&sWihDwc), 0, (const char *)(&sWihDwc));
    }
    p = func_0203D7C8((u32)heap, 0x328, (const char *)sWihDwcFile, 0x49);
    ((struct Obj07083 *)p)->f310 = idx;
    *(u8 * *)&((struct Obj07083 *)p)->f300 = func_0203D7C8((u32)heap, func_0205D010(), (const char *)sWihDwcFile, 0x4C);
    func_0217963C((u32)func_0201045C);
    g_021461E0.f0 = p;
    *(u8 * *)&((struct Obj07083 *)p)->f304 = g_021461E0.f4;
    func_02034AC4((int)ov015_id);
    return p;
}

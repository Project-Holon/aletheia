/*
 * function: func_021BEB18
 * address: 0x021BEB18
 * packet: pkt_ov208_021BEB18
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: MATCH
 * 2026-10-05 (D5-03): MATCH. Byte-correct except the five calls to the ov093 callees 0x021B9E68,
 *   0x021BA7C8, 0x021BA374 (no witness label; ov093 below 0x021D4000, pengy). Fixes: the colour loop
 *   calls are func_02040618(i, 0, 0) and (i, 3, 0) (the draft passed i; the image keeps the 0 in r7, which
 *   is why ctx left r7), the first 9E68 call passes (2, 0, 1), locals v54 before v50 before w, the
 *   021BDAD0 test written `!= 2` first, and case 4 writes `*state = 5` in both arms.
 * 2026-10-04 (wD2 lane19): also tried ctx as a one-field struct by value and as u32 with casts: no change (frame 0x74/0x78 vs 0x70,
 *   ctx still in r7). Residue unchanged: image stores ctx back to [sp,#0x88] at entry and keeps state at [sp,#0x34], r7 free.
 * 2026-10-05 (wave D4 lane 02): frame layout check: image has v40 at sp+0x40, v44 0x44, w 0x48, v50 0x50,
 *   v54 0x54, tbl 0x58 (frame 0x70). Ours puts two spilled constant temps (0x17+0xfd and 0xf5+0x27, the
 *   msg field offsets) at 0x40/0x44 because ctx holds r7, so everything shifts by 8 (frame 0x78). Tried:
 *   both state and ctx `*volatile` (882 bytes, worse). Root residue is still ctx kept in r7 instead of its
 *   home slot. Also blocked: func_021B9E68, func_021BA7C8, func_021BA374 have no label (ov093 low, pengy).
 * symbols:
 *   func_021BC3B4 0x021BC3B4 thumb
 *   func_021BC3B8 0x021BC3B8 thumb
 *   func_0201D7EC 0x0201D7EC thumb
 *   func_02045B38 0x02045B38 arm
 *   func_02040618 0x02040618 arm
 *   func_020414AC 0x020414AC arm
 *   func_021BDAD0 0x021BDAD0 thumb
 *   func_021BC3BC 0x021BC3BC thumb
 *   func_021BDAAC 0x021BDAAC thumb
 *   func_021BDAD4 0x021BDAD4 thumb
 *   func_021BDBB8 0x021BDBB8 thumb
 *   func_021BDC48 0x021BDC48 thumb
 *   func_021BC3A4 0x021BC3A4 thumb
 *   func_02012BF8 0x02012BF8 thumb
 *   func_021BDC14 0x021BDC14 thumb
 *   func_021BE840 0x021BE840 thumb
 *   func_021BE82C 0x021BE82C thumb
 *   func_021BE844 0x021BE844 thumb
 *   func_021BF308 0x021BF308 thumb
 *   func_0200CA1C 0x0200CA1C thumb
 *   func_021BC3A8 0x021BC3A8 thumb
 *   func_021BCF4C 0x021BCF4C thumb
 *   func_0200CA70 0x0200CA70 thumb
 *   func_021BF4FC 0x021BF4FC thumb
 *   func_021BC3B0 0x021BC3B0 thumb
 *   func_021B9E68 0x021B9E68 thumb ov093
 *   func_021BA7C8 0x021BA7C8 thumb ov093
 *   func_021BF4C4 0x021BF4C4 thumb
 *   func_021BF5B8 0x021BF5B8 thumb
 *   func_021BF620 0x021BF620 thumb
 *   func_021BC4D8 0x021BC4D8 thumb
 *   func_021BC4C8 0x021BC4C8 thumb
 *   func_021BDBA0 0x021BDBA0 thumb
 *   func_021BC4E4 0x021BC4E4 thumb
 *   func_021BE854 0x021BE854 thumb
 *   func_021BDAE8 0x021BDAE8 thumb
 *   func_021BEFA0 0x021BEFA0 thumb
 *   func_021BF088 0x021BF088 thumb
 *   func_021BF450 0x021BF450 thumb
 *   func_021BA374 0x021BA374 thumb ov093
 *   func_021BF664 0x021BF664 thumb
 *   func_021BC46C 0x021BC46C thumb
 * 2026-10-02 (lane C2-01): control flow, callees and frame layout recovered (tbl[6] at sp+0x58 gives the 0x70 frame);
 * the six-state task body is complete. Still DIFF in register allocation: the image keeps the stack argument ctx in
 * its home slot [sp,#0x88] (reloaded at every use, stored back once at entry) and state in [sp,#0x34], leaving r7
 * free for hoisted constants (0x17 and 0xf5 bases in the font/message setup). Here ctx lands in r7 and the setup
 * spills those constants. Tried: int *volatile ctx (state then takes r7).
 * Also unresolved: func_021B9E68, func_021BA7C8, func_021BA374 (ov093 below 0x021D4000, not ours).
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Ov208Blend;
struct Ov208Scn {
    u16 pad0; u16 pad2;
    void *f4; void *f8;
    struct Ov208Blend *fc; struct Ov208Blend *f10;
    int f14; int f18;
    char pad1c[0x94 - 0x1c];
    int f94;
    char pad98[0x110 - 0x98];
    void *font; void *msg0; void *msg1; void *msg2;
};
struct Ov208Heap { u16 heap; };
extern void *func_021BC3B4(int *ctx);
extern void *func_021BC3B8(int *ctx);
extern void *func_0201D7EC(int a, int b, int c, int d, u32 heap);
extern void *func_02045B38(int a, int b, int c, u32 heap);
extern void func_02040618(u8 a, u8 b, u8 c);
extern void func_020414AC(u8 a);
extern int func_021BDAD0(void *s);
extern u16 func_021BC3BC(int *ctx);
extern void func_021BDAAC(void *s, u32 a, u32 b, u32 c);
extern void func_021BDAD4(void *s, int a);
extern void func_021BDBB8(void *s, u32 a);
extern void func_021BDC48(void *s, u32 a);
extern int func_021BC3A4(int *ctx);
extern int func_02012BF8(int a, int b);
extern void func_021BDC14(void *s, int a);
extern int func_021BE840(void *s);
extern void func_021BE82C(void *s, int a);
extern void func_021BE844(void *s);
extern void func_021BF308(struct Ov208Heap *h, struct Ov208Scn *p, int *ctx);
extern void *func_0200CA1C(int a);
extern int func_021BC3A8(int *ctx);
extern int func_021BCF4C(int a);
extern int func_0200CA70(void *a);
extern void func_021BF4FC(struct Ov208Heap *h, struct Ov208Scn *p, int *ctx, u16 *o1, u16 *o2, u16 *o3, u16 *o4, u32 *o5, u32 *o6, u32 *o7);
extern int func_021BC3B0(int *ctx);
extern void *func_021B9E68(u32 a, u16 b, u16 c, u32 d, u16 e, u32 f, u32 g, u32 h, u32 i, u32 j, u8 k, u32 l, u32 m, u32 n, void *o, void *p, void *q);
extern void func_021BA7C8(void *p);
extern void func_021BF4C4(struct Ov208Heap *h, struct Ov208Scn *p, int *ctx, u32 *tbl);
extern void func_021BF5B8(struct Ov208Heap *h, struct Ov208Scn *p, int *ctx);
extern void func_021BF620(struct Ov208Heap *h, struct Ov208Scn *p, int *ctx);
extern void func_021BC4D8(struct Ov208Blend *b);
extern int func_021BC4C8(struct Ov208Blend *b);
extern void func_021BDBA0(void *s);
extern void func_021BC4E4(struct Ov208Blend *b);
extern void func_021BE854(void *s);
extern void func_021BDAE8(void *s, int a);
extern int func_021BEFA0(struct Ov208Heap *h, struct Ov208Scn *p, int *ctx);
extern void func_021BF088(struct Ov208Heap *h, struct Ov208Scn *p, int *ctx);
extern void func_021BF450(struct Ov208Heap *h, struct Ov208Scn *p, int *ctx);
extern void func_021BA374(void *p);
extern void func_021BF664(struct Ov208Heap *h, struct Ov208Scn *p, int *ctx);
extern void func_021BC46C(struct Ov208Blend *a, struct Ov208Blend *b);
int func_021BEB18(void *unused, int *state, struct Ov208Heap *h, struct Ov208Scn *p, int *ctx)
{
    void *scn = func_021BC3B4(ctx);
    void *icon = func_021BC3B8(ctx);
    int v40;
    int v44;
    u32 v54;
    u32 v50;
    u16 w[4];
    u32 tbl[6];
    u8 i;
    int t;
    switch (*state) {
    case 0:
        *state = 1;
        p->font = func_0201D7EC(0x17, 0, 1, 0, h->heap);
        p->msg0 = func_02045B38(1, 2, 0x104, h->heap);
        p->msg1 = func_02045B38(1, 2, 0xf5, h->heap);
        p->msg2 = func_02045B38(1, 2, 0x10c, h->heap);
        for (i = 0; i <= 7; i++) {
            if (i != 1 && i != 5) {
                func_02040618(i, 0, 0);
                func_02040618(i, 3, 0);
                func_020414AC(i);
            }
        }
        if (func_021BDAD0(scn) != 2) {
            func_021BDAAC(scn, 0, 0, func_021BC3BC(ctx) > 1);
            func_021BDAD4(scn, 0);
        } else {
            func_021BDBB8(scn, 0);
        }
        func_021BDC48(scn, 0);
        func_021BDC14(scn, func_02012BF8(func_021BC3A4(ctx), 0x11));
        if (func_021BE840(icon) != 2) {
            func_021BE82C(icon, 0);
            func_021BE844(icon);
        }
        func_021BF308(h, p, ctx);
        t = (int)func_0200CA1C(func_021BC3A4(ctx));
        v40 = func_021BCF4C(func_021BC3A8(ctx));
        v44 = func_0200CA70((void *)t);
        func_021BF4FC(h, p, ctx, &w[3], &w[2], &w[1], &w[0], &v54, &v50, tbl);
        p->f4 = func_021B9E68(h->heap, w[3], w[2], w[1], w[0], v54, v44, v50, 2, 0, 1, v40, (u32)p->font, func_021BC3B0(ctx), p->msg0, p->msg1, p->msg2);
        p->f8 = func_021B9E68(h->heap, w[3], w[2], w[1], w[0], v54, v44, v50, 2, 1, 1, v40, (u32)p->font, func_021BC3B0(ctx), p->msg0, p->msg1, p->msg2);
        func_021BA7C8(p->f8);
        func_021BF4C4(h, p, ctx, tbl);
        func_021BF5B8(h, p, ctx);
        func_021BF620(h, p, ctx);
        break;
    case 1:
        *state = 2;
        func_021BC4D8(p->fc);
        func_021BC4D8(p->f10);
        break;
    case 2:
        if (func_021BC4C8(p->fc) == 0 && func_021BDAD0(scn) == 2 && func_021BE840(icon) == 2) {
            func_021BDBA0(scn);
            func_021BDC48(scn, 1);
            *state = 3;
        }
        break;
    case 3:
        if (p->f14 != 0) {
            *state = 4;
            func_021BC4E4(p->fc);
            func_021BC4E4(p->f10);
            func_021BE854(icon);
            if (p->f14 == 2)
                func_021BDAE8(scn, 0);
        } else if (p->f18 != 0) {
            if (func_021BEFA0(h, p, ctx) == 0)
                func_021BF088(h, p, ctx);
        }
        break;
    case 4:
        if (func_021BC4C8(p->fc) == 0 && func_021BC4C8(p->f10) == 0 && func_021BE840(icon) == 0) {
            if (p->f14 == 2) {
                if (func_021BDAD0(scn) == 0)
                    *state = 5;
            } else {
                *state = 5;
            }
        }
        break;
    case 5:
        return 1;
    }
    if (*state >= 2) {
        func_021BF450(h, p, ctx);
        func_021BA374(p->f4);
        func_021BA374(p->f8);
        if (p->f94 == 6)
            func_021BF664(h, p, ctx);
    }
    func_021BC46C(p->fc, p->f10);
    return 0;
}

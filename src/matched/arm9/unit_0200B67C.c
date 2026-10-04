/*
 * unit:     yes
 * address:  0x0200B67C
 * packet:   pkt_0200B67C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: func_0200B67C, func_0200B6E0
 *
 * 264 bytes, 0x0200B67C..0x0200B784, 2 functions, both labelled.  Every
 * concrete byte reproduces.
 *
 * What held it open, and what closed it.  Two call targets have exactly one
 * caller in the whole image and that caller is here:
 *
 *   0x02007324  reached only from 0x0200B6A6, inside func_0200B67C
 *   0x0200B7D8  reached only from 0x0200B71A, inside func_0200B6E0
 *
 * Shrinking the range to one function keeps the call that needs the witness in
 * it, which is the limit `docs/MATCHING.md` states for the cut remedy, so no
 * image class could carry either site.  Both are now `matched`:
 * 0x02007324 is src/matched/unit_02007324.c and 0x0200B7D8 is
 * src/matched/unit_0200B7D8.c, two EXACT entries proved byte for byte against
 * the original over ranges this file does not touch.  Pulling either function
 * across the boundary into this range is no longer needed, and would have been
 * wrong anyway: the two belong to different original files.
 *
 * alias: inside "battle_rec.c"; the two steps of the record-save state machine
 * that func_0200B4E0 and func_0200B5CC read back.
 *
 * Three things cost time here.
 *
 *  - func_02012EBC is declared with **one** parameter, not four.  The call
 *    leaves r1 through r3 holding this function's own second, third and fourth
 *    arguments, which reads like a four-argument call and is not one: declaring
 *    four parameters keeps `b` live from the entry and the whole of
 *    func_0200B6E0's case 0 is then allocated the other way round, with the two
 *    sub-record pointers sharing registers with `b` instead of with `a`.  Seven
 *    bytes, and none of them in the arithmetic.  src/matched/unit_0200C9EC.c
 *    declares the same extern with one parameter.
 *  - inside case 0 the two sub-record pointers have to be assigned
 *    `q = &p->unk80;` first and `r = &p->unkC4;` second.  The second assignment
 *    is the last use of `p`, so it takes over `p`'s register and the first one
 *    gets the copy; writing them the other way round swaps which of the two is
 *    the `adds rD, rP, #0` and is five bytes.
 *  - the state word is read with `switch (*state)` over the constants 0 and 1,
 *    which is the `cmp #0` / `beq` / `cmp #1` / `beq` / `b` chain the original
 *    has; an `if` / `else if` inverts the first test.
 *
 * symbols:
 *   func_0203F1FC  0x0203F1FC  arm
 *   gObj_0214616C  0x0214616C  data
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u16 func_0203F1FC(const void *src, u32 size);

struct QRec {
    u16 unk00[0x0C];
    u8  unk18[0x0C];
    u16 unk24;
    u16 unk26;
    u16 unk28;
    u8  unk2A;
    u8  unk2B;
    u8  unk2C[0x0C];
    u8  unk38[8];
    u16 unk40;
    u16 unk42;
};

struct RecC4 {
    u8  unk0000[0x17D8];
    u16 unk17D8;
    u16 unk17DA;
    u16 unk17DC;
    u16 unk17DE;
};

struct BattleRec {
    u8  unk00[0x80];
    struct QRec unk80;
    struct RecC4 unkC4;
};

extern struct BattleRec *gObj_0214616C;

struct Big;
struct Sub02007324Ctrl;
extern void *func_02012EBC(struct Big *p);
extern void func_02007324(struct Sub02007324Ctrl *ctrl, u32 id, u32 heap, u32 a, u32 b);
extern void  func_02012E4C(u8 *a, u32 c);
extern int func_02012E7C(char *p, int a1);
extern void func_0200734C(struct Sub02007324Ctrl *ctrl, u32 id);
extern void  func_0200BA44(struct RecC4 *p);
extern void  func_0200B908(void *a, u32 b, u32 c);
extern void  func_0200B7D8(void *h, struct QRec *q, const struct RecC4 *src,
                           u32 mode, u32 e);

u32 func_0200B67C(void *a, struct BattleRec *b, u32 c, u16 *state, u16 e)
{
    void *h = func_02012EBC(a);
    u32 r;

    switch (*state) {
    case 0:
        func_02007324(h, c, e, (u32)gObj_0214616C, 0x2000);
        func_02012E4C(a, c);
        (*state)++;
        break;
    case 1:
        r = func_02012E7C(a, c);
        if (r == 2 || r == 3) {
            func_0200734C(h, c);
            return r;
        }
        break;
    }
    return 0;
}

u32 func_0200B6E0(void *a, u16 b, u32 c, u32 d, u32 e, u16 *state, u16 *sub)
{
    void *h;
    struct BattleRec *p;
    struct QRec *q;
    struct RecC4 *r;
    u16 v;

    h = func_02012EBC(a);

    switch (*state) {
    case 0:
        p = gObj_0214616C;
        if (p == 0) {
            return 3;
        }
        q = &p->unk80;
        r = &p->unkC4;
        func_0200B7D8(h, q, r, c, d);
        q->unk28 = 0xE281;
        q->unk40 = func_0203F1FC(q, 0x38);
        r->unk17D8 = 0xE281;
        func_0200BA44(r);
        v = r->unk17DC;
        func_0200B908(r, 0x17DC, v + ((v ^ 0xFFFF) << 16));
        *sub = 0;
        (*state)++;
        break;
    case 1:
        return func_0200B67C(a, gObj_0214616C, e, sub, b);
    }
    return 0;
}

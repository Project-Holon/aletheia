/*
 * function: BMP_MENULIST_PrintItem
 * address:  0x02020408
 * packet:   pkt_02020408
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02045770  0x02045770  arm
 *   func_0201C724  0x0201C724  thumb
 *   func_0201C7D0  0x0201C7D0  thumb
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BMP_MENULIST_PrintItem.c \
 *       --func BMP_MENULIST_PrintItem --addr 0x02020408 --thumb
 *
 * Print one item's text into the menu window.  f38top selects the override
 * colours at +0x34/+0x35 (set by unit_02020268's func_02020298) over the
 * list's own at +0x17/+0x18; sel picks func_0201C724 (which also marks the
 * target dirty) over func_0201C7D0.  Closed in wave 13; the 2026-09-21 note
 * (docs/notes/BMP_MENULIST_PrintItem.c.txt) had it at 314 of 338 bytes.
 *
 * The packed colour is a 5:5:5 triple built by a masking macro,
 *     ((l & 0x1f) << 10) | ((s & 0x1f) << 5) | (b & 0x1f)
 * over the 4-bit nibbles: mwcc turns each mask-then-shift into the
 * `<< 27 / >> 17` and `<< 27 / >> 22` pairs and keeps the bare `ands 0x1f`
 * on the unshifted term, which is exactly the "5-bit destination over a
 * 4-bit source" shape the note described.  No 5-bit bitfield struct needed.
 *
 * THE IMAGE'S FOURTH ARM (f38top clear, sel == 0) READS THE OVERRIDE BYTES
 * +0x34/+0x35, not +0x17/+0x18 like the third arm.  That is what the bytes
 * say, and the C reproduces it; it reads like a copy-paste slip in the
 * original.  EXACT* only because the extent includes 2 bytes of padding.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Target {
    u32 win;
    u8  dirty;
};

struct Obj {
    void *arr;
    u32 unk04;
    u32 unk08;
    u32 unk0C;
    u16 count;
    u16 rows;
    u8 f14;
    u8 f15;
    u8 f16;
    u8 f17lo : 4;
    u8 f17hi : 4;
    u8 f18lo : 4;
    u8 f18hi : 4;
    u8 f19;
    u8 pad1A[0x28 - 0x1A];
    struct Target *f28;
    u32 f2C;
    u32 f30;
    u8 f34lo : 4;
    u8 f34hi : 4;
    u8 f35lo : 4;
    u8 f35hi : 4;
    u8 f36;
    u8 f37;
    u8 f38 : 7;
    u8 f38top : 1;
};

#define COLOR(l, s, b) ((u16)((((l) & 0x1f) << 10) | (((s) & 0x1f) << 5) | ((b) & 0x1f)))

struct Descriptor;
extern void *func_02045770(struct Descriptor *win);
extern void func_0201C724(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_0201C7D0(u32 bmp, u32 x, u32 y, const void *text, u32 f, u16 color);

void BMP_MENULIST_PrintItem(struct Obj *obj, const void *text, u32 x, u32 y, u32 sel)
{
    if (text == 0)
        return;
    if (obj->f38top) {
        if (sel) {
            u32 a = obj->f2C;
            struct Target *t = obj->f28;
            func_0201C724((void *)a, (u32)func_02045770((struct Descriptor *)t->win), x, y, (u32)text, obj->f30,
                          COLOR(obj->f34lo, obj->f35lo, obj->f34hi));
            t->dirty = 1;
        } else {
            func_0201C7D0((u32)func_02045770((struct Descriptor *)obj->f28->win), x, y, text, obj->f30,
                          COLOR(obj->f34lo, obj->f35lo, obj->f34hi));
        }
    } else {
        if (sel) {
            u32 a = obj->f2C;
            struct Target *t = obj->f28;
            func_0201C724((void *)a, (u32)func_02045770((struct Descriptor *)t->win), x, y, (u32)text, obj->f30,
                          COLOR(obj->f17hi, obj->f18hi, obj->f18lo));
            t->dirty = 1;
        } else {
            func_0201C7D0((u32)func_02045770((struct Descriptor *)obj->f28->win), x, y, text, obj->f30,
                          COLOR(obj->f34lo, obj->f35lo, obj->f34hi));
        }
    }
}

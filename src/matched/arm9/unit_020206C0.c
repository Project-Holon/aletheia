/*
 * unit:     yes
 * function: BMP_MENULIST_DrawCursor, BMP_MENULIST_EraseCursor
 * address:  0x020206C0
 * packet:   pkt_02020408
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02045770  0x02045770  arm
 *   func_02043AF4  0x02043AF4  arm
 *   BMP_CURSOR_Draw  0x02020D5C  thumb
 *
 * The two redraw entry points of the menu-cursor block, BMP_MENULIST_DrawCursor and
 * BMP_MENULIST_EraseCursor, folded into one translation unit so 0x020206C0..0x0202077E
 * reproduces end to end.  Both dispatch on the same one-bit field at the top
 * of the u16 at +0x1A through a four-entry PC-relative halfword table whose
 * cases 1..3 are empty arms; the empty arms are what make the table exist
 * (docs/idioms/empty-switch-arms-are-what-make-the-table.md).
 *
 * Both pass the same derived byte, f17lo + <row> * (u8)(f22 + f1Amid), to
 * their callee; in BMP_MENULIST_DrawCursor the row is the cursor's own f42 and the
 * value must be bound to a named local computed BEFORE the switch (as must
 * f16), or the compiler sinks both into the case-0 arm and the function is
 * four bytes short.  In BMP_MENULIST_EraseCursor the row is the function's second
 * argument and the same value is an inline argument, scheduled per site
 * (docs/idioms/an-inline-call-argument-is-scheduled-per-site-a-local-is-not.md).
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

struct Obj {
    void *arr;
    void *unk04;
    void *unk08;
    void *unk0C;
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
    u16 f1Alo : 3;
    u16 f1Amid : 4;
    u16 f1Amid2 : 8;
    u16 f1Atop : 1;
    u8 pad1C[0x20 - 0x1C];
    u16 f20;
    u16 f22;
    u8 pad24[0x28 - 0x24];
    void *f28;
    void *f2C;
    void *f30;
    u8 pad34[0x3C - 0x34];
    void *f3C;
    u16 f40;
    u16 f42;
};

struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
struct Bmp;
struct Desc;
struct Handle;
extern void func_02043AF4(struct Bmp *b, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6);
extern void BMP_CURSOR_Draw(struct Desc *d, u32 x, u32 y, struct Handle *h, void *dst, u32 f);

void BMP_MENULIST_DrawCursor(struct Obj *obj)
{
    u8 a = obj->f17lo;
    u8 b = obj->f16;
    u8 v = (u8)(a + obj->f42 * (u8)(obj->f22 + obj->f1Amid));

    switch (obj->f1Atop) {
    case 0:
        BMP_CURSOR_Draw(obj->f3C, b, v, obj->f28, obj->f2C, (u32)obj->f30);
        break;
    case 1:
    case 2:
    case 3:
        break;
    }
}

void BMP_MENULIST_EraseCursor(struct Obj *obj, u32 n)
{
    switch (obj->f1Atop) {
    case 0:
        func_02043AF4((struct Bmp *)((u32)func_02045770((struct Descriptor *)obj->unk0C)),
                      obj->f16,
                      (s16)(u16)(obj->f17lo + n * (u8)(obj->f22 + obj->f1Amid)),
                      obj->f20,
                      obj->f22,
                      obj->f18lo);
        break;
    case 1:
    case 2:
    case 3:
        break;
    }
}

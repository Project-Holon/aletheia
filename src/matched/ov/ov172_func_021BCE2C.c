/*
 * function: func_021BCE2C
 * address:  0x021BCE2C
 * packet:   pkt_ov172_021BCE2C
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_0204B404  0x0204B404  arm
 *   func_0204B878  0x0204B878  arm
 *
 * Places the three cursor sprites (+0x8, +0xc, +0x10) on list row idx relative to the scroll offset at +4: hidden when no row is selected (+0x18 == 0xff) or the row is off screen; the third sprite shows only when the selected entry's flag at +0x1f0 is set, animated from the row's cell at +0x50.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned long u32;

struct SpritePos {
    s16 x;
    s16 y;
};

struct Obj;
extern void func_0204B3DC(struct Obj *spr, unsigned int on);
extern void func_0204B404(u32 spr, struct SpritePos *pos, int n);
extern void func_0204B878(u32 spr, int anim);

void func_021BCE2C(void *ctx, char *list, char *cur, int idx)
{
    struct SpritePos pos;
    s16 y;

    if (*(u8 *)(cur + 0x18) == 0xff) {
        func_0204B3DC((struct Obj *)*(u32 *)(cur + 8), 0);
        func_0204B3DC((struct Obj *)*(u32 *)(cur + 0xc), 0);
        func_0204B3DC((struct Obj *)*(u32 *)(cur + 0x10), 0);
        return;
    }
    y = idx * 32 - *(u16 *)(list + 4);
    if (y >= -32 && y <= 0xa0) {
        pos.x = 0x80;
        pos.y = y + 0x10;
        func_0204B404(*(u32 *)(cur + 8), &pos, 1);
        func_0204B3DC((struct Obj *)*(u32 *)(cur + 8), 1);
        pos.x = 0x12;
        func_0204B404(*(u32 *)(cur + 0xc), &pos, 1);
        func_0204B3DC((struct Obj *)*(u32 *)(cur + 0xc), 1);
        pos.x = 0xc8;
        func_0204B404(*(u32 *)(cur + 0x10), &pos, 1);
        if (*(u32 *)(list + *(u8 *)(cur + 0x18) * 0x24 + 0x1f0) == 1) {
            func_0204B878(*(u32 *)(list + idx * 0x1c + 0x50), 0x12);
            func_0204B3DC((struct Obj *)*(u32 *)(cur + 0x10), 1);
        } else {
            func_0204B3DC((struct Obj *)*(u32 *)(cur + 0x10), 0);
        }
        return;
    }
    func_0204B3DC((struct Obj *)*(u32 *)(cur + 8), 0);
    func_0204B3DC((struct Obj *)*(u32 *)(cur + 0xc), 0);
    func_0204B3DC((struct Obj *)*(u32 *)(cur + 0x10), 0);
}

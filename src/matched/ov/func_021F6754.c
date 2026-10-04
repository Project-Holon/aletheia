/*
 * function: func_021F6754
 * address:  0x021F6754
 * packet:   pkt_021F6754
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   DC_FlushRange  0x020862F0  arm
 *   GX_LoadOBJ     0x0207E780  arm
 *   func_0204B6F4  0x0204B6F4  arm
 *   func_020307B0  0x020307B0  arm
 *
 * Deferred icon upload (installed at +0xEBC by func_021F68A4): for each
 * of the 30 icon records at +0xEB8 that has a sprite (+8), flush and
 * load its 0x200 pixel bytes to its OBJ VRAM offset and set the sprite's
 * palette; then free the record block.
 */

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct {
    u32 vram;
    u32 pal;
    u32 spr;
    u8 pixels[0x200];
} IconRec;

typedef struct {
    u8 pad0[0xEB8];
    IconRec *icons;
} Work;

extern void DC_FlushRange(void *p, u32 size);
extern void GX_LoadOBJ(const void *src, u32 offset, u32 size);
struct Obj;
extern void func_0204B6F4(struct Obj *o, u32 v, u32 flag);
extern void func_020307B0(void *p);

void func_021F6754(Work *p)
{
    int i;
    IconRec *e;

    e = p->icons;
    for (i = 0; i < 30; i++, e++) {
        if (e->spr != 0) {
            DC_FlushRange(e->pixels, 0x200);
            GX_LoadOBJ(e->pixels, e->vram, 0x200);
            func_0204B6F4((struct Obj *)e->spr, (u8)e->pal, 1);
        }
    }
    func_020307B0(p->icons);
}

/*
 * function: func_021C5B34
 * address:  0x021C5B34
 * packet:   pkt_ov111_021C5B34
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0207E468  0x0207E468  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u8 pad0[0xC];
    u16 *data;
} PlttData;

typedef struct {
    u8 pad0[0x31EC];
    PlttData *pltt;
    int frame;
} Work;

extern void func_0207E468(const void *src, u32 offset, u32 size);

void func_021C5B34(Work *p)
{
    u16 *pal = p->pltt->data;

    p->frame++;
    if (p->frame > 8) {
        p->frame = 0;
    }
    if (p->frame == 0) {
        func_0207E468(pal + 3, 6, 4);
    } else if (p->frame == 4) {
        func_0207E468(pal + 5, 6, 4);
    }
}

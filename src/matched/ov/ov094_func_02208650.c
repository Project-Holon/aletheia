/*
 * function: func_02208650
 * address:  0x02208650
 * packet:   pkt_ov094_02208650
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef unsigned char u8;
typedef struct { int w[9]; } Struct36;
typedef struct { void *f0; char p4[0x6f - 4]; u8 f6f; } E;
typedef struct { char p0[0x14]; char *f14; } O;
extern void func_0204B7C8(void *, Struct36 *);
extern void func_02082A60(const void *, void *, int);

void func_02208650(O *o, E *e)
{
    Struct36 buf;
    int off;
    enum { VRAM_BASE = 0x06400000 } vram;

    off = 0x360;
    if (e->f6f == 0)
        off = 0x660;
    func_0204B7C8(e->f0, &buf);
    vram = VRAM_BASE;
    func_02082A60(o->f14 + off, (void *)(vram + 0x120 + buf.w[1]), 0x20);
}

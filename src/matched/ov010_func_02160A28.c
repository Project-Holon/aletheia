/*
 * function: func_02160A28
 * address:  0x02160A28
 * packet:   pkt_ov010_02160A28
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Clears a 0x14-byte record and fills it from five arguments.
 *
 * symbols:
 *   MI_CpuFill8  0x02082BCC  arm
 */

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct Rect {
    u32 x;
    u32 y;
    u32 w;
    u32 h;
    u32 tag;
} Rect;

extern void MI_CpuFill8(void *dst, u8 val, u32 size);

void func_02160A28(Rect *r, u32 tag, u32 x, u32 y, u32 w, u32 h)
{
    MI_CpuFill8(r, 0, sizeof(Rect));
    r->x = x;
    r->w = w;
    r->y = y;
    r->h = h;
    r->tag = tag;
}

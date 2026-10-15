/*
 * function: WF2DMAP_CMDQ_Pop
 * address:  0x021C5F80
 * packet:   pkt_021C5F80
 * region:   ov127
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   _u32_div_f  0x0209C2B0  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u16 x;
    u16 y;
} Entry;

typedef struct {
    Entry *data;
    u32    count;
    u16    r;
    u16    w;
} S;

extern u32 _u32_div_f(u32 a, u32 b);

int WF2DMAP_CMDQ_Pop(S *a, Entry *out)
{
    if (a->w == a->r)
        return 0;
    *out = a->data[a->r];
    a->r = (a->r + 1) % a->count;
    return 1;
}

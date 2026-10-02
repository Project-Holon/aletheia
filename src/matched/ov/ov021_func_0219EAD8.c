/*
 * function: func_0219EAD8
 * address:  0x0219EAD8
 * packet:   pkt_ov021_0219EAD8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * The source pointer is const: that lets mwcc load s->h above the store of w.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

typedef struct {
    u16 x, y, w, h;
} Rect;

typedef struct {
    u32 head;
    Rect r;
} Obj;

void func_0219EAD8(Obj *p, const Rect *s)
{
    p->r = *s;
}

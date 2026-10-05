/*
 * function: func_02162CE8
 * address:  0x02162CE8
 * packet:   pkt_ov010_02162CE8
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Unlabelled leaf (push {r3, r4} with no lr), reached through the ov010
 * tail-call thunk func_02162A64.  Blocker of ov061 func_021F388C.
 * The const on both pointers keeps the first ldrsh ahead of the base
 * copy; the lsrs needs the u32 casts.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

typedef struct {
    int a;
    int b;
    int c;
} V3;

typedef struct {
    s16 x;
    s16 y;
    s16 z;
    u16 w;
    u16 h;
} Box;

typedef struct {
    u8 pad[8];
    Box box;
} Obj;

void func_02162CE8(const Obj *p, V3 *out)
{
    const Box *b = &p->box;

    out->a = b->x << 12;
    out->b = b->y << 12;
    out->c = b->z << 12;
    if (b->w > 1) {
        out->a += ((u32)b->w >> 1) << 16;
    } else if (b->h > 1) {
        out->c += ((u32)b->h >> 1) << 16;
    }
}

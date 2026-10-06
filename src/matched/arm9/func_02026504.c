/*
 * unit:     no
 * function: func_02026504
 * address:  0x02026504
 * packet:   pkt_02026504
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02012B58  0x02012B58  thumb
 *   func_02012944  0x02012944  thumb
 *   func_02012950  0x02012950  thumb
 *   func_020084BC  0x020084BC  thumb
 *   func_02008500  0x02008500  thumb
 *   func_02008550  0x02008550  thumb
 *
 * Push one entry onto the six-slot ring buffer that func_020261E4 built at
 * +0x3c of the sprite object (0xc bytes per slot, write cursor at +0x85,
 * fill count at +0x84).  Each of the two handle arguments is resolved
 * against the owner's current id: equal to it means the "self" handle
 * (func_02012944), otherwise the by-id lookup (func_02012950).  If either
 * handle is busy (func_020084BC == 1) the whole push is abandoned before
 * anything is written.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Slot {
    u16 f00;
    u8  f02;
    u8  b0 : 1;
    u8  b1 : 1;
    u8  b2 : 1;
    u8  b3 : 5;
    u32 f04;
    u32 f08;
};

struct Ring {
    struct Slot slot[6];
    u8 count;
    u8 cursor;
};

struct Obj {
    u32 owner;
    u8  pad04[0x3c - 4];
    struct Ring ring;
};

struct BigObj;
extern u8 func_02012B58(const struct BigObj *p);
struct Rec44;
struct Sub24;
extern u8 *func_02012944(void *p);
extern struct Rec44 *func_02012950(struct Sub24 *p, u32 i);
extern int func_020084BC(const u16 *values);
extern void func_02008500(void *a, void *b);
struct Sub0200852CObj;
extern u8 func_02008550(const struct Sub0200852CObj *obj);

void func_02026504(struct Obj *o, u32 id0, u32 id1, u32 v)
{
    struct Ring *r;
    u32 h0;
    u32 h1;
    struct Slot *s;

    r = &o->ring;
    if (id0 == func_02012B58((void *)o->owner)) {
        h0 = (u32)func_02012944((void *)o->owner);
    } else {
        h0 = (u32)func_02012950((void *)o->owner, id0);
    }
    if (id1 == func_02012B58((void *)o->owner)) {
        h1 = (u32)func_02012944((void *)o->owner);
    } else {
        h1 = (u32)func_02012950((void *)o->owner, id1);
    }
    if (func_020084BC((const u16 *)h0) == 1) {
        return;
    }
    if (func_020084BC((const u16 *)h1) == 1) {
        return;
    }
    s = &r->slot[r->cursor];
    if (s->b0 == 1) {
        r->count = (u8)(r->count + 1);
    }
    s->f02 = (u8)id0;
    s->f00 = (u16)v;
    s->b0 = 1;
    func_02008500((void *)h0, (void *)s->f04);
    s->b1 = (u8)(u32)func_02008550((const struct Sub0200852CObj *)h0);
    func_02008500((void *)h1, (void *)s->f08);
    s->b2 = (u8)(u32)func_02008550((const struct Sub0200852CObj *)h1);
    r->cursor = (u8)(r->cursor + 1);
    if (r->cursor >= 6) {
        r->cursor = 0;
    }
    if (r->count >= 6) {
        r->count = 0;
    }
}

/*
 * function: func_021BD904
 * address:  0x021BD904
 * packet:   pkt_ov021_021BD904
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02012134  0x02012134  thumb
 *   func_0202B580  0x0202B580  thumb
 *   func_0202B434  0x0202B434  thumb
 *   func_0202B438  0x0202B438  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u32 x0;
    u32 x4;
    u8 pad8[0x10];
    u16 h18;
    u8 pad1a[6];
    u16 h20;
} Ent;

typedef struct {
    u32 x0;
    u32 x4;
    Ent *e;
} Obj;

extern u32 func_02012134(u32 a);
extern void *func_0202B580(u32 a);
extern u32 func_0202B434(u8 *p);
extern u32 func_0202B438(u8 *p, u32 id);

int func_021BD904(Obj *o)
{
    Ent *e = o->e;
    void *s = func_0202B580(func_02012134(e->x4));

    if (func_0202B434(s) && func_0202B438(s, e->h18) && func_0202B438(s, e->h20)) {
        return 1;
    }
    return 0;
}

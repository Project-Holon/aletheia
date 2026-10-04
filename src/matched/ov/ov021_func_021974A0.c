/*
 * function: func_021974A0
 * address:  0x021974A0
 * packet:   pkt_ov021_021974A0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204B3B4  0x0204B3B4  arm
 *   func_0204ADA4  0x0204ADA4  arm
 *   func_0204A8D4  0x0204A8D4  arm
 *   func_0204AFD8  0x0204AFD8  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

typedef struct Obj {
    u8 pad[0x270];
    void *c[6];
    u32 x288;
    void *b[2];
    void *a[5];
} Obj;
extern void func_0204B3B4(struct Obj *p);
extern void func_0204ADA4(u32 i);
extern void func_0204A8D4(u32 i);
extern void func_0204AFD8(u32 i);

void func_021974A0(Obj *o)
{
    int i;

    for (i = 0; i < 5; i++) {
        if (o->a[i] != 0) {
            func_0204B3B4(o->a[i]);
            o->a[i] = 0;
        }
    }
    for (i = 0; i < 2; i++) {
        if (o->b[i] != 0) {
            func_0204B3B4(o->b[i]);
            o->b[i] = 0;
        }
    }
    for (i = 0; i < 2; i++) {
        if (o->c[i] != 0) {
            func_0204ADA4((u32)o->c[i]);
        }
    }
    for (; i < 4; i++) {
        if (o->c[i] != 0) {
            func_0204A8D4((u32)o->c[i]);
        }
    }
    for (; i < 6; i++) {
        if (o->c[i] != 0) {
            func_0204AFD8((u32)o->c[i]);
        }
    }
}

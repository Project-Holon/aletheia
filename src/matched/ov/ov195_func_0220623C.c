/*
 * function: func_0220623C
 * address:  0x0220623C
 * packet:   pkt_0220623C
 * region:   ov195
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02015EA0 0x02015EA0 thumb
 *   func_02015BA4 0x02015BA4 thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Owner {
    u8 pad00[0x4c];
    void *sys;
    void *obj[2];
} Owner;

extern void func_02015EA0(void *obj);
extern void func_02015BA4(void *sys, void *obj);

void func_0220623C(Owner *o)
{
    u8 i;

    for (i = 0; i < 2; i++) {
        if (o->obj[i] != 0) {
            func_02015EA0(o->obj[i]);
            func_02015BA4(o->sys, o->obj[i]);
        }
    }
}

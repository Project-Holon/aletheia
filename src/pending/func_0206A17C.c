/*
 * function: func_0206A17C
 * address:  0x0206A17C
 * packet:   pkt_0206A12C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

typedef unsigned short u16;

typedef struct Struct0206A17C {
    char pad[0x2c];
    void *ptr2c;
    char pad30[2];
    u16 flags32;
} Struct0206A17C;

void *func_0206A17C(Struct0206A17C *r0)
{
    void *res;
    r0->flags32 &= ~1;
    res = r0->ptr2c;
    r0->ptr2c = 0;
    return res;
}

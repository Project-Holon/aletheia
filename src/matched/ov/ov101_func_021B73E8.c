/*
 * function: func_021B73E8
 * address:  0x021B73E8
 * packet:   pkt_021B73E8
 * region:   ov101
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Frees the seven pointers in the array at offset 8 of the argument.
 *
 * symbols:
 *   func_0204B3B4  0x0204B3B4  arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Obj;
void func_0204B3B4(struct Obj *p);

void func_021B73E8(void *p)
{
    int i;

    for (i = 0; i < 7; i++) {
        if (*(void **)((char *)p + i * 4 + 8))
            func_0204B3B4(*(void **)((char *)p + i * 4 + 8));
    }
}

/*
 * function: func_0202C3C4
 * address:  0x0202C3C4
 * packet:   pkt_0202C3C4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   sub_0202C548  0x0202C548  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Obj0202C360 {
    u32   unk00;
    u16   shorts[9];
    u8    unk16;
    u8    pad17;
    void *words[9];
};

extern u32 sub_0202C548(void *p);

void func_0202C3C4(struct Obj0202C360 *p)
{
    int i;

    for (i = 0; i < 9; i++) {
        sub_0202C548(p->words[i]);
        p->words[i] = 0;
    }
}

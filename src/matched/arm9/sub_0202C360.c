/*
 * function: ISS_SWITCH_SET_Init
 * address:  0x0202C360
 * packet:   pkt_0202C360
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Obj0202C360 {
    u32 unk00;
    u16 shorts[9];
    u8  unk16;
    u8  pad17;
    u32 words[9];
};

void ISS_SWITCH_SET_Init(struct Obj0202C360 *p)
{
    int i;

    p->unk00 = 0;
    p->unk16 = 0;

    for (i = 0; i < 9; i++) {
        p->shorts[i] = 0;
    }

    for (i = 0; i < 9; i++) {
        p->words[i] = 0;
    }
}

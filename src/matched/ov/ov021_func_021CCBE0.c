/*
 * function: func_021CCBE0
 * address:  0x021CCBE0
 * packet:   pkt_ov021_021CCBE0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204B3DC  0x0204B3DC  arm
 */

typedef unsigned char u8;

typedef unsigned int   u32;
struct Obj;
extern void func_0204B3DC(struct Obj *p, u32 v);

void func_021CCBE0(u8 *s, int flag)
{
    int i;

    for (i = 0; i < 6; i++) {
        if (*(void **)(s + i * 4 + 0x1c) != 0)
            func_0204B3DC(*(void **)(s + i * 4 + 0x1c), 0);
        if (*(void **)(s + i * 4 + 0x34) != 0)
            func_0204B3DC(*(void **)(s + i * 4 + 0x34), 0);
    }
    if (flag == 0) {
        for (i = 0; i < 6; i++) {
            if (*(void **)(s + i * 4 + 0x1c) != 0)
                func_0204B3DC(*(void **)(s + i * 4 + 0x1c), 1);
        }
    } else if (flag == 1) {
        for (i = 0; i < 6; i++) {
            if (*(void **)(s + i * 4 + 0x34) != 0)
                func_0204B3DC(*(void **)(s + i * 4 + 0x34), 1);
        }
    }
}

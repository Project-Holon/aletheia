/*
 * function: func_021BB9DC
 * address:  0x021BB9DC
 * packet:   pkt_ov088_021BB9DC
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_0200C308  0x0200C308  thumb
 */

typedef unsigned char u8;

typedef unsigned int   u32;
struct Blk34;
struct Obj;
extern void func_0204B3DC(struct Obj *p, u32 v);
extern u8 func_0200C308(struct Blk34 *p, u32 i);

void func_021BB9DC(char *p, int flag)
{
    unsigned i;
    if (flag == 0) {
        for (i = 0; i <= 5; i++)
            func_0204B3DC(*(void **)(p + 0x1c + i * 4), flag);
        return;
    }
    func_0204B3DC(*(void **)(p + 0x1c), 1);
    for (i = 0; i < 8; i++) {
        u8 c = *(u8 *)(p + 0x120 + i);
        if (c == 8)
            return;
        if (c == 3) {
            if (func_0200C308(*(void **)(p + 8), 1) == 1)
                func_0204B3DC(*(void **)(p + 0x24), 1);
        } else if (c == 4) {
            if (func_0200C308(*(void **)(p + 8), 2) == 1)
                func_0204B3DC(*(void **)(p + 0x28), 1);
        } else if (c == 7) {
            if (func_0200C308(*(void **)(p + 8), 3) == 1)
                func_0204B3DC(*(void **)(p + 0x2c), 1);
        } else if (c == 5) {
            func_0204B3DC(*(void **)(p + 0x30), 1);
        }
    }
}

/*
 * function: ov208_func_021C5248
 * address:  0x021C5248
 * packet:   pkt_ov208_021C5248
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02016380  0x02016380  thumb
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Ov208Turn {
    int side;
    u8 *scene;
    u8  count;
    u8  pad9[3];
    int done;
};

extern void func_02016380(u32 obj);

void ov208_func_021C5248(struct Ov208Turn *t)
{
    u8 *scene = t->scene;

    t->count++;
    if (t->count >= 2)
        t->done = 1;
    func_02016380(*(u32 *)(scene + t->side * 0x44 + 0xc));
}

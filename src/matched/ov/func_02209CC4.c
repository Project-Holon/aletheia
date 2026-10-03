/*
 * function: func_02209CC4
 * address:  0x02209CC4
 * packet:   pkt_02209CC4
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204B3DC   0x0204B3DC  arm
 */

typedef unsigned int u32;

typedef struct {
    u32 f00;
    u32 f04;
    u32 f08;
    u32 f0c;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1c;
    u32 f20;
    u32 f24;
    u32 f28;
} S09CC4;

struct Obj;
extern void func_0204B3DC(struct Obj *p, u32 v);

void func_02209CC4(int a0, S09CC4 *p)
{
    if (p->f04 == 0)
        return;
    if (p->f28 == 0)
        return;
    if (--p->f24 != 0)
        return;
    func_0204B3DC((void *)p->f04, 0);
    p->f28 = 0;
}

/*
 * function: func_02064140
 * address:  0x02064140
 * packet:   pkt_020640DC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02064150    0x02064150  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct O02064140 {
    u32 unk0;
};

extern void func_02064150(void *o);

void func_02064140(struct O02064140 *o, u32 a)
{
    o->unk0 = a;
    func_02064150(o);
}

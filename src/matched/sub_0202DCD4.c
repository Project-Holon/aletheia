/*
 * function: func_0202DCD4
 * address:  0x0202DCD4
 * packet:   pkt_0202DCD4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   sub_0202DCC4  0x0202DCC4  thumb
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Rec0202DCC4 {
    u8  pad[0x18];
    u32 unk18_0 : 1;
    u32 unk18_1 : 1;
    u32 unk18_2 : 1;
    u32 unk18_3 : 29;
    u8  tail[0xC];
};

struct Obj0202DCC4 {
    u8 pad[0xC];
    struct Rec0202DCC4 *unk0C;
};

extern u32 sub_0202DCC4(const struct Obj0202DCC4 *p, u32 i);

void func_0202DCD4(struct Obj0202DCC4 *p, u32 i, u32 val)
{
    if (sub_0202DCC4(p, i) != 0) {
        p->unk0C[i].unk18_2 = val;
    }
}

/*
 * function: func_0202DCFC
 * address:  0x0202DCFC
 * packet:   pkt_0202DCD4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   sub_0204B688  0x0204B688  arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Actor;

struct Rec0202DCC4 {
    u8            pad00[8];
    struct Actor *actors[2];
    u8            pad10[8];
    u32           unk18;
    u8            tail[0xC];
};

struct Obj0202DCC4 {
    u8 pad[0xC];
    struct Rec0202DCC4 *unk0C;
};

extern void sub_0204B688(struct Actor *actor, u32 val);

void func_0202DCFC(struct Obj0202DCC4 *p, u32 i, u32 val)
{
    int k;

    for (k = 0; k < 2; k++) {
        sub_0204B688(p->unk0C[i].actors[k], val);
    }
}

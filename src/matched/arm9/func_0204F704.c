/*
 * function: func_0204F704
 * address:  0x0204F704
 * packet:   pkt_0204F704
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * note:     2026-10-12 lane HF0: hidden function filed.
 * symbols:
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Obj {
    u8 pad_0[8];
    u32 f8;
};
struct Ent {
    u8  pad_00[0x18];
    u16 f0 : 5;
    u16 f1 : 4;
    u16 f2 : 1;
    u16 f3 : 6;
    u8  pad_1a[2];
};

u32 func_0204F704(u8 *a0, int i)
{
    struct Ent *e = &((struct Ent *)((struct Obj *)a0)->f8)[i];

    return e->f2;
}

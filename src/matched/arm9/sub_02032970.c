/*
 * function: sub_02032970
 * address:  0x02032970
 * packet:   pkt_020328E0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02034F84  0x02034F84  arm
 *
 * savedata.c.  Opens a new backup generation: clears the two status bytes
 * and the two counters, remembers the generation the write is going to
 * carry in +0x10 and bumps the running generation in +0x28, then, when the
 * caller asked for it, raises the "busy" flag through the setter veneer at
 * 0x02034F84.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02032970.c  *       --func sub_02032970 --addr 0x02032970 --cc 1.1p1 --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

struct SaveBackup {
    u8 pad00[0x10];
    u32 unk10;
    u32 unk14;
    u8 unk18;
    u8 unk19;
    u8 pad1A[2];
    u8 unk1C;
    u8 pad1D[11];
    u32 unk28;
    u8 pad2C[4];
    u32 unk30;
    u32 unk34;
    u8 pad38[0x10C];
    u32 unk144;
};

extern void func_02034F84(u32 bit);

void sub_02032970(struct SaveBackup *p, u32 flag)
{
    u32 gen;

    p->unk18 = 0;
    p->unk14 = 0;
    p->unk19 = 0;
    gen = p->unk28;
    p->unk28 = gen + 1;
    p->unk144 = 0;
    p->unk10 = gen;

    if (flag == 1) {
        func_02034F84(1);
    }
}

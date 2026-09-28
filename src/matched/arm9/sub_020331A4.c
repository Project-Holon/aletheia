/*
 * function: sub_020331A4
 * address:  0x020331A4
 * packet:   pkt_020328E0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02034FB8  0x02034FB8  arm
 *
 * savedata.c.  The completion callback of a backup write: on result 3 the
 * generation counter is rolled back to the one the write carried, on any
 * other result the failure byte at +0x1C is raised instead, and either way
 * the "busy" flag is dropped through the veneer at 0x02034FB8 when the
 * caller asked for it.  The two arms share one epilogue, which is why they
 * are written as an if/else over predicated stores rather than two
 * statements.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_020331A4.c  *       --func sub_020331A4 --addr 0x020331A4 --cc 1.1p1 --arm
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

extern void func_02034FB8(u32 bit);

void sub_020331A4(struct SaveBackup *p, u32 result, u32 flag)
{
    if (result == 3) {
        p->unk28 = p->unk10;
    } else {
        p->unk1C = 1;
    }

    if (flag == 1) {
        func_02034FB8(1);
    }
}

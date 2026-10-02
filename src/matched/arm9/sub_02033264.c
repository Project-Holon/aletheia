/*
 * function: sub_02033264
 * address:  0x02033264
 * packet:   pkt_020328E0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02033B68  0x02033B68  arm
 *   func_02033BAC  0x02033BAC  arm
 *
 * savedata.c.  Bumps the halfword counter that sits at the head of one of
 * the records inside the staging buffer and answers the new value.  The
 * closing `ldrh` is not a redundant reload: reloading the halfword is one
 * instruction where truncating the incremented value in a register would
 * be two, so the compiler reads the store back rather than masking.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02033264.c \n *       --func sub_02033264 --addr 0x02033264 --cc 1.1p1 --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct SaveBackup {
    u8 pad00[0x2C];
    u32 unk2C;
    u32 unk30;
    u32 unk34;
    u8 pad38[0x108];
    u32 unk140;
};

extern u32 func_02033B68(u32 table, u32 i);
extern u32 func_02033BAC(u32 table, u32 id);

u16 sub_02033264(struct SaveBackup *p, u32 id)
{
    u32 base;
    u32 off;
    u16 *q;

    base = func_02033B68(p->unk2C, id);
    off = func_02033BAC(p->unk2C, id);
    q = (u16 *)(p->unk34 + (base + off));
    *q = *q + 1;
    return *q;
}

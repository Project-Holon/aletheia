/*
 * function: func_0204D70C
 * address: 0x0204D70C
 * packet: pkt_arm9_0204D70C
 * region: arm9
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: arm
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/arm9/clact_p11.c and filed here.
 */

typedef unsigned int u32;
typedef unsigned char  u8;
typedef unsigned short u16;

typedef struct {
    u16 count;
    u16 pad_02;
    u8 *items;
} ClactTbl;

typedef struct {
    u32 tag;
    u32 pad_04;
    ClactTbl tbl;
} ClactBlk;

typedef struct {
    u8 pad_00[0x10];
    ClactBlk *blk10;
    ClactBlk *blk14;
} ClactInner;

typedef struct {
    u32 pad_00;
    ClactInner *f04;
    ClactInner *f08;
    u8 pad_0c[0x70 - 0x0c];
    ClactInner *f70;
    ClactInner *f74;
} ClactObj;

ClactTbl *func_0204D70C(ClactObj *o);

ClactTbl *func_0204D70C(ClactObj *o)
{
    ClactBlk *b = o->f70->blk10;
    if (b == 0 || b->tag != 0x55434154) {
        b = 0;
    }
    return b != 0 ? &b->tbl : 0;
}

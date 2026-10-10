/*
 * function: func_0204D750
 * address: 0x0204D750
 * packet: pkt_arm9_0204D750
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

u16 func_0204D750(ClactObj *o);

u16 func_0204D750(ClactObj *o)
{
    return *(u16 *)o->f08;
}

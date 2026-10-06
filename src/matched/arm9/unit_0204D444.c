/*
 * unit:     yes
 * function: sub_0204D444
 * address:  0x0204D444
 * packet:   pkt_0204CA74
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   gUnk_020A1394  0x020A1394  data
 *   sub_0204D444   0x0204D444  arm
 *   sub_0204D460   0x0204D460  arm
 *   sub_0204D468   0x0204D468  arm
 *   sub_0204D470   0x0204D470  arm
 *
 * The same shape as src/matched/unit_0204D410.c one row over: the thunk
 * dispatches on the object's kind through row 1 of the handler table at
 * 0x020A1394, and the three row-1 handlers are again the +0xc pointer
 * adjustment.  Three unlabelled leaves folded into the unit with the thunk.
 *
 * The base is attested `literal` by the pool word at 0x0204D490, outside
 * this range; see src/matched/func_0204D324.c for the row map.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0204D444.c \
 *       --addr 0x0204D444 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Obj {
    u32 type;
    u8  pad_04[8];
    u8  unk_0c;
};

typedef void *(*DispatchFn)(struct Obj *o);

extern DispatchFn const gUnk_020A1394[][3];

struct Node;

struct Node *sub_0204D444(struct Obj *o)
{
    return gUnk_020A1394[1][o->type](o);
}

void *sub_0204D460(struct Obj *o)
{
    return &o->unk_0c;
}

void *sub_0204D468(struct Obj *o)
{
    return &o->unk_0c;
}

void *sub_0204D470(struct Obj *o)
{
    return &o->unk_0c;
}

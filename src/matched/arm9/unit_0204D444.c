/*
 * unit:     yes
 * function: CLACT_GetAnimObject
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
 *   g_ClactAnimFuncTable  0x020A1394  data
 *   CLACT_GetAnimObject   0x0204D444  arm
 *   CLACT_GetCellAnimObject   0x0204D460  arm
 *   CLACT_GetMultiCellAnimObject   0x0204D468  arm
 *   CLACT_GetVramAnimObject   0x0204D470  arm
 *
 * The same shape as src/matched/unit_0204D410.c one row over: the thunk
 * dispatches on the object's kind through row 1 of the handler table at
 * 0x020A1394, and the three row-1 handlers are again the +0xc pointer
 * adjustment.  Three unlabelled leaves folded into the unit with the thunk.
 *
 * The base is attested `literal` by the pool word at 0x0204D490, outside
 * this range; see src/matched/CLACT_SetAnimSeq.c for the row map.
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

extern DispatchFn const g_ClactAnimFuncTable[][3];

struct Node;

struct Node *CLACT_GetAnimObject(struct Obj *o)
{
    return g_ClactAnimFuncTable[1][o->type](o);
}

void *CLACT_GetCellAnimObject(struct Obj *o)
{
    return &o->unk_0c;
}

void *CLACT_GetMultiCellAnimObject(struct Obj *o)
{
    return &o->unk_0c;
}

void *CLACT_GetVramAnimObject(struct Obj *o)
{
    return &o->unk_0c;
}

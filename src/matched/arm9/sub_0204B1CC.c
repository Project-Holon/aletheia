/*
 * function: CLACT_DeleteUnit
 * address:  0x0204B1CC
 * packet:   pkt_0204B0C8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   CLACT_UnlinkUnit  0x0204BC40  arm
 *   CLACT_DeleteActor   0x0204B3B4  arm
 *   sub_020307B0   0x020307B0  arm
 *
 * The inverse of src/matched/CLACT_CreateUnit.c: quiesce the cell-actor bank,
 * tear down every live actor record, then free the record array and the bank
 * header.  An actor counts as live when its first word (the resource handle
 * src/matched/CLACT_DeleteActor.c hands back) is non-null.
 *
 * `bank->count` is re-read on every iteration because CLACT_DeleteActor is opaque
 * to the compiler, so the bound has to stay the field access in the `for`
 * condition rather than a local; the entry test at the top is the compiler's
 * own loop rotation of that same read, not a separate guard.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/CLACT_DeleteUnit.c \
 *       --func CLACT_DeleteUnit --addr 0x0204B1CC --cc 1.1p1 --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;

struct Actor {
    void *unk_00;
    u8    pad_04[0xe0];
};

struct Bank {
    struct Actor *actors;
    u8            pad_04[8];
    u16           count;
    u8            pad_0e[0x0a];
};

extern void CLACT_UnlinkUnit(struct Bank *bank);
struct Obj;
extern void CLACT_DeleteActor(struct Obj *p);
typedef unsigned int   u32;
extern u32 sub_020307B0(void *p);

u32 CLACT_DeleteUnit(struct Bank *bank)
{
    int i;

    CLACT_UnlinkUnit(bank);

    for (i = 0; i < bank->count; i++) {
        if (bank->actors[i].unk_00 != 0) {
            CLACT_DeleteActor((struct Obj *)(&bank->actors[i]));
        }
    }

    sub_020307B0(bank->actors);
    return sub_020307B0(bank);
}

/*
 * unit:     no
 * function: CLACT_DeleteActor
 * address:  0x0204B3B4
 * packet:   pkt_0204B0C8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   CLACT_UnlinkActor  0x0204CA30  arm
 *   CLACT_ExitAnimCtl  0x0204D104  arm
 *   CLACT_ClearActor  0x0204CAE4  arm
 *
 * Tear-down for the 0x0204Bxxx object: hand the handle at +8 and the owner
 * to CLACT_UnlinkActor, run the embedded sub-object at +0x68 through
 * CLACT_ExitAnimCtl, then CLACT_ClearActor on the owner.
 *
 * This file was parked at MATCH on the PC24 site at +0x18: this is
 * 0x0204D104's only caller image-wide, and 0x0204D104 was itself stuck
 * because its handler table 0x020A13D0 appears in no other literal pool.
 * 0x020A13D0 is row 5 of the one array based at 0x020A1394, which is pooled
 * at 0x0204D490; src/matched/CLACT_ExitAnimCtl.c is now EXACT and attests this
 * site `matched`.  The C here is unchanged.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/CLACT_DeleteActor.c  *       --func CLACT_DeleteActor --addr 0x0204B3B4 --cc 1.1p1 --arm
 */
typedef unsigned char u8;

struct Obj {
    u8   pad_00[8];
    void *unk_08;
    u8   pad_0c[0x5c];
    u8   unk_68;
};

struct Dispatchable;
struct Mgr;
struct Node;
extern void CLACT_UnlinkActor(struct Mgr *m, struct Node *l);
extern void CLACT_ExitAnimCtl(struct Dispatchable *p);
extern void CLACT_ClearActor(struct Obj *owner);

void CLACT_DeleteActor(struct Obj *p)
{
    CLACT_UnlinkActor(p->unk_08, (struct Node *)p);
    CLACT_ExitAnimCtl((struct Dispatchable *)(&p->unk_68));
    CLACT_ClearActor(p);
}

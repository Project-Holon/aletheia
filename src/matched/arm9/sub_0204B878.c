/*
 * unit:     no
 * function: CLACT_SetActorAnimSeq
 * address:  0x0204B878
 * packet:   pkt_0204B84C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   CLACT_SetAnimSeq  0x0204D324  arm
 *   CLACT_StartActorAnim  0x0204B95C  arm
 *
 * Stores a 16-bit value at +0x5a of the object, then runs the sub-object at
 * +0x68 through CLACT_SetAnimSeq and re-runs the owner through CLACT_StartActorAnim.
 * The same +0x68 sub-object is the one CLACT_DeleteActor hands to CLACT_ExitAnimCtl.
 *
 * This file was parked at MATCH: CLACT_SetActorAnimSeq is 0x0204D324's only caller
 * image-wide, so the PC24 site at +0x10 could only ever be attested by an
 * EXACT entry for 0x0204D324 itself, and that function looked unattestable
 * in turn because its handler-table pool word 0x020A13B8 appears in no
 * other literal pool.  It is not a table address: it is row 3 of the one
 * eight-by-three array based at 0x020A1394, which is pooled at 0x0204D490
 * as well.  src/matched/CLACT_SetAnimSeq.c carries the reasoning; with that
 * entry EXACT this site resolves `matched` and nothing here changed.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/CLACT_SetActorAnimSeq.c  *       --func CLACT_SetActorAnimSeq --addr 0x0204B878 --cc 1.1p1 --arm
 */
typedef unsigned char  u8;
typedef unsigned short u16;

struct Obj {
    u8  pad_00[0x5a];
    u16 unk_5a;
    u8  pad_5c[0x0c];
    u8  unk_68;
};

typedef unsigned int   u32;
struct Obj0204D324;
extern void CLACT_SetAnimSeq(struct Obj0204D324 *obj, u32 arg);
struct Actor;
extern void CLACT_StartActorAnim(struct Actor *a);

void CLACT_SetActorAnimSeq(struct Obj *p, u16 value)
{
    p->unk_5a = value;
    CLACT_SetAnimSeq((struct Obj0204D324 *)(&p->unk_68), value);
    CLACT_StartActorAnim((struct Actor *)p);
}

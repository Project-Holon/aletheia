/*
 * unit:     no
 * function: sub_0204B3B4
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
 *   func_0204CA30  0x0204CA30  arm
 *   func_0204D104  0x0204D104  arm
 *   func_0204CAE4  0x0204CAE4  arm
 *
 * Tear-down for the 0x0204Bxxx object: hand the handle at +8 and the owner
 * to func_0204CA30, run the embedded sub-object at +0x68 through
 * func_0204D104, then func_0204CAE4 on the owner.
 *
 * This file was parked at MATCH on the PC24 site at +0x18: this is
 * 0x0204D104's only caller image-wide, and 0x0204D104 was itself stuck
 * because its handler table 0x020A13D0 appears in no other literal pool.
 * 0x020A13D0 is row 5 of the one array based at 0x020A1394, which is pooled
 * at 0x0204D490; src/matched/sub_0204D104.c is now EXACT and attests this
 * site `matched`.  The C here is unchanged.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0204B3B4.c  *       --func sub_0204B3B4 --addr 0x0204B3B4 --cc 1.1p1 --arm
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
extern void func_0204CA30(struct Mgr *m, struct Node *l);
extern void func_0204D104(struct Dispatchable *p);
extern void func_0204CAE4(struct Obj *owner);

void sub_0204B3B4(struct Obj *p)
{
    func_0204CA30(p->unk_08, (struct Node *)p);
    func_0204D104((struct Dispatchable *)(&p->unk_68));
    func_0204CAE4(p);
}

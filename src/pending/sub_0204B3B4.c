/*
 * function: sub_0204B3B4
 * address:  0x0204B3B4
 * packet:   pkt_0204B0C8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
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
 * Blocked at MATCH: every concrete byte is right, but the PC24 site at
 * +0x18 (func_0204D104) has no witness.  This is 0x0204D104's only caller
 * image-wide, so `label` is out; `--suggest-split` confirms the site is
 * uncuttable and recommends exactly the partition taken here, this function
 * left out and 0x0204B3DC..0x0204B454 kept as unit_0204B3DC.c.  The last
 * route, an EXACT entry for 0x0204D104 as a `matched` witness, is closed
 * too: that function is byte-correct in src/pending/sub_0204D104.c but its
 * own handler table 0x020A13D0 appears in no other literal pool.  Needs a
 * second caller of 0x0204D104, most likely from an overlay.
 */

typedef unsigned char u8;

struct Obj {
    u8   pad_00[8];
    void *unk_08;
    u8   pad_0c[0x5c];
    u8   unk_68;
};

extern void func_0204CA30(void *handle, struct Obj *owner);
extern void func_0204D104(void *sub);
extern void func_0204CAE4(struct Obj *owner);

void sub_0204B3B4(struct Obj *p)
{
    func_0204CA30(p->unk_08, p);
    func_0204D104(&p->unk_68);
    func_0204CAE4(p);
}

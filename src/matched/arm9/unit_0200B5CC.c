/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
 * unit:     yes
 * address:  0x0200B5CC
 * packet:   pkt_0200B448
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: func_0200B5CC
 *
 * 176 bytes, 0x0200B5CC..0x0200B67C, one function, which carries a label in
 * the generated listing.
 *
 * alias: inside "battle_rec.c".  The same classification func_0200B4E0 does,
 * over a record the save system already holds rather than one just read, and
 * with a `func_020072A4` release on every path instead of only on entry.  See
 * src/matched/unit_0200B4E0.c for why the two are separate files. *
 * symbols:
 *   gObj_0214616C  0x0214616C  data
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct RecC4 {
    u8  unk0000[0x17DC];
    u16 unk17DC;
    u8  unk17DE[2];
};

struct BattleRec {
    u8  unk00[0x80];
    u8  unk80[0x44];
    struct RecC4 unkC4;
};

extern u32  func_020072CC(void *save, u32 id, u32 heap, void *buf, u32 size);
extern void func_020072A4(void *save, u32 id);
extern void func_0200B900(void *a, u32 b, u32 c);
extern u32  func_0200725C(void *save, u32 id, u32 heap);
extern struct BattleRec *func_020073D8(void *save, u32 id, u32 c);
extern u32  func_0200B888(void *a, void *b);
extern u32  func_0200B8AC(void *a, void *b);
extern void func_0200B448(struct BattleRec *p);
extern void func_0200B400(u32 heap);
extern struct BattleRec *func_0200B3DC(u32 heap);
extern struct BattleRec *gObj_0214616C;

u32 func_0200B5CC(void *a, u32 heap, u32 *dp, u32 id)
{
    struct BattleRec *p;
    struct RecC4 *r;
    u16 v;

    *dp = func_0200725C(a, id, heap);
    p = func_020073D8(a, id, 0);
    if (*dp == 0) {
        *dp = 0;
        func_020072A4(a, id);
        return 0;
    }
    if (*dp != 1) {
        *dp = 3;
        func_020072A4(a, id);
        return 0;
    }
    r = &p->unkC4;
    v = r->unk17DC;
    func_0200B900(r, 0x17DC, v + ((v ^ 0xFFFF) << 16));
    if (func_0200B888(a, p) == 1) {
        *dp = 0;
        func_020072A4(a, id);
        return 0;
    }
    if (func_0200B8AC(a, p) == 0) {
        *dp = 2;
        func_020072A4(a, id);
        return 0;
    }
    *dp = 1;
    func_020072A4(a, id);
    return 1;
}

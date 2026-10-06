/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
 * unit:     yes
 * address:  0x0200B394
 * packet:   pkt_0200ADB8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: func_0200B394, func_0200B3A4, func_0200B3A8, func_0200B3AC,
 *           func_0200B3B0, func_0200B3C8, func_0200B3DC
 *
 * symbols:
 *   func_0200B3DC_File  0x020A71C4  data
 *
 * 108 bytes, 0x0200B394..0x0200B400, 7 functions, four of which carry no
 * label in the generated listing.
 *
 * alias: 0x020A71C4 spells "battle_rec.c", the third original source file
 * name recovered by this project, attested by the `string` class off the
 * terminator of "regulation.c" at 0x020A71C2.  The constructor at 0x0200B3DC
 * allocates 0x2000 bytes at line 0x67 and hands them to func_0200B448, which
 * is the first function of the next packet.
 *
 * Near miss, and the reason this unit starts at 0x0200B394 rather than
 * 0x0200B37C: func_0200B37C, 24 bytes, which writes -1 into the first word
 * and then fills a 32-entry array with 0..31.  The original carries one more
 * instruction than any spelling tried here, an `adds r2, r3, #0` that copies
 * the loop counter before the body and lets the increment be scheduled ahead
 * of the store, and it initialises the counter before the -1 store rather
 * than after.  Five loop spellings (for, while, do/while, a separate value
 * variable, a hoisted array pointer) all produce the same eleven
 * instructions in the other order, so the difference is a register the
 * original had a reason to spend and this source does not give it.  Nineteen
 * bytes differ and the size is right to the padding.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void  func_02082A90(void *dest, const void *src, u32 size);
struct BattleRec;
struct Sub020071CCCtrl;
extern void *func_020071CC(struct Sub020071CCCtrl *ctrl, u32 id);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
struct Struct_0200B37C;
extern void func_0200B37C(struct Struct_0200B37C *p);
extern void func_0200B448(struct BattleRec *p);
extern const char func_0200B3DC_File[];

struct Rec94 {
    s32 unk00;
    s32 unk04[32];
    u8  unk84[0x10];
};

s32 *func_0200B394(struct Rec94 *p, s32 value)
{
    func_0200B37C((struct Struct_0200B37C *)p);
    p->unk00 = value;
    return p->unk04;
}

s32 *func_0200B3A4(struct Rec94 *p)
{
    return p->unk04;
}

u8 *func_0200B3A8(struct Rec94 *p, u32 a1)
{
    return p->unk84;
}

s32 func_0200B3AC(struct Rec94 *p)
{
    return p->unk00;
}

void func_0200B3B0(struct Rec94 *dest, void *sys)
{
    func_02082A90(dest, func_020071CC(sys, 0x30), sizeof(struct Rec94));
}

void func_0200B3C8(void *sys, const struct Rec94 *src)
{
    func_02082A90(func_020071CC(sys, 0x30), src, sizeof(struct Rec94));
}

void *func_0200B3DC(u32 heap)
{
    void *p = func_02030734(heap, 0x2000, 1, func_0200B3DC_File, 0x67);

    func_0200B448(p);
    return p;
}

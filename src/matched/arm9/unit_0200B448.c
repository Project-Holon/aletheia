/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
 * unit:     yes
 * address:  0x0200B448
 * packet:   pkt_0200B448
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: func_0200B448, func_0200B45C, func_0200B480, func_0200B490,
 *           func_0200B4B8
 *
 * 152 bytes, 0x0200B448..0x0200B4E0, 5 functions, three of which carry no
 * label in the generated listing.
 *
 * alias: this continues "battle_rec.c"; func_0200B448 is the buffer clear the
 * constructor func_0200B3DC calls, and the object is the 0x18A4-byte record
 * at 0x0214616C that src/matched/unit_0200B400.c allocates and
 * src/matched/unit_0200B938.c publishes.
 *
 * Two things are worth recording.
 *
 *  - func_0200B490 and func_0200B4B8 are the same four instructions of
 *    checksum arithmetic as func_0200B938, but as **tail calls**, and that
 *    changes the callee's arity.  A tail call needs r3 for the branch target,
 *    so the fourth argument func_0200B938 passes cannot be passed here: the
 *    `ldrh r3` that loads the halfword is overwritten by the `ldr r3, [pc]`
 *    that loads func_0200B900's address.  The callee is therefore declared
 *    with three parameters in this file and with four in
 *    src/matched/unit_0200B900.c, and both are right, because nothing in
 *    func_0200B900 reads its arguments.  A four-argument call here compiles
 *    to `push {r3, lr}` / `bl` / `pop` and is eight bytes longer.
 *  - the length 0x17DC is reached as `subs r1, #0xc4` off the 0x18A0 the
 *    halfword load already needed, and 0x18A0 itself is a pool word rather
 *    than a `movs`, so the file spends one pool word where func_0200B938
 *    spends none for the same value.  That is a consequence of the tail call
 *    having no register to spare, not of the source.
 *
 * symbols:
 *   MIi_CpuClear32  0x02082A7C  arm
 *   func_0203F2FC   0x0203F2FC  arm
 *   gObj_0214616C   0x0214616C  data
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void MIi_CpuClear32(u32 data, void *dest, u32 size);
extern u32 func_0203F2FC(const u8 *p, u32 len);
extern void func_0200B900(void *a, u32 b, u32 c);
extern void func_0200B908(void *a, u32 b, u32 c);

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

extern struct BattleRec *gObj_0214616C;

void func_0200B448(struct BattleRec *p)
{
    MIi_CpuClear32(0, p, sizeof(struct BattleRec));
}

u32 func_0200B45C(void)
{
    if (func_0203F2FC((const u8 *)(&gObj_0214616C->unkC4), sizeof(gObj_0214616C->unkC4))
        != 0) {
        return 1;
    }
    return 0;
}

void func_0200B480(void)
{
    func_0200B448(gObj_0214616C);
}

void func_0200B490(void)
{
    u16 v = gObj_0214616C->unkC4.unk17DC;

    func_0200B900(&gObj_0214616C->unkC4, 0x17DC, v + ((v ^ 0xFFFF) << 16));
}

void func_0200B4B8(void)
{
    u16 v = gObj_0214616C->unkC4.unk17DC;

    func_0200B908(&gObj_0214616C->unkC4, 0x17DC, v + ((v ^ 0xFFFF) << 16));
}

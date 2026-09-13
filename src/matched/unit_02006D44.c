/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/000_02004000.s.
 *
 * unit:     yes
 * address:  0x02006D44
 * packet:   pkt_020064F4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: sub_02006D44, sub_02006D64, sub_02006D94
 *
 * symbols:
 *   sub_02006D44_Ptr  0x02146164  data
 *   func_020307B0     0x020307B0  arm
 *   PM_SetAmp         0x0208BEF0  arm
 *
 * The tail of "snd_mic.c": the teardown of the microphone object and the two
 * functions that own the counter at +0x20.  The object is the one
 * src/matched/unit_02006DAC.c and src/matched/sub_02006E2C.c reach through
 * the same pointer at 0x02146164: seven words of MICAutoParam at +0, a flag
 * word at +0x1C, the packed word at +0x20 and the sampling buffer at +0x24,
 * which is 0x28 bytes and is exactly what the constructor at 0x02006CBC
 * allocates and clears.
 *
 * The word at +0x20 is two unsigned bitfields, one bit at bit 0 and thirty
 * one bits at bit 1, and all three functions here turn on that declaration:
 *
 *  - sub_02006D94 reads the wide field with a bare `lsrs r0, r0, #1` and no
 *    mask, which is only correct because the field runs to the top of the
 *    word.  A plain u32 shifted by hand gives the same instruction here but
 *    not in sub_02006D64;
 *  - sub_02006D64 writes it back with `movs r0, #1` / `ands r2, r0` /
 *    `lsrs r0, r1, #1` / `adds` / `lsls r0, r0, #1` / `orrs r0, r2`, which is
 *    the read modify write of a bitfield that has to preserve bit 0.  Written
 *    as `w = (w & 1) | ((((w >> 1) + n) << 1))` this compiler materialises the
 *    mask differently and reorders the two halves;
 *  - sub_02006D64 tests bit 0 with `lsls #0x1f` / `lsrs #0x1f`, the one bit
 *    case of docs/idioms/shift-pair-with-no-matching-type-is-a-bitfield.md.
 *
 * The range starts at 0x02006D44 rather than earlier because 0x02006D3C is
 * four bytes of ARM: `ldr pc, [pc, #-4]` over the pointer word at 0x02006D40,
 * a linker veneer, which no compiler input produces.  What is left out below
 * it is recorded in the header of src/matched/unit_02006B20.c.
 */

typedef unsigned int u32;

struct Sub02006D44Obj {
    u32   unk00[7];
    u32   unk1C;
    u32   unk20_0 : 1;
    u32   unk20_1 : 31;
    void *unk24;
};

extern struct Sub02006D44Obj *sub_02006D44_Ptr;

extern void func_020307B0(void *p);
extern void PM_SetAmp(u32 on);

u32 sub_02006D94(void);

void sub_02006D44(void)
{
    PM_SetAmp(0);
    func_020307B0(sub_02006D44_Ptr->unk24);
    func_020307B0(sub_02006D44_Ptr);
}

void sub_02006D64(u32 n)
{
    struct Sub02006D44Obj *obj = sub_02006D44_Ptr;

    if (obj->unk20_0) {
        if (sub_02006D94() == 0) {
            obj->unk20_1 += n;
        }
    }
}

u32 sub_02006D94(void)
{
    if (sub_02006D44_Ptr->unk20_1 > 0xB4) {
        return 1;
    }
    return 0;
}

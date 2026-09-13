/*
 * A second whole translation unit, chosen because it contains literal pools
 * and a padding gap, which the accessor run at 0x0200852C does not.  Written
 * from the disassembly in asm/arm9/src/001_02007664.s.
 *
 * unit:     yes
 * address:  0x020084BC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 * function: sub_020084BC, sub_020084D4, sub_020084E4, sub_020084F4,
 *           sub_020084F8, sub_02008500, sub_02008510
 *
 * 0x020084BC..0x0200852C, 112 bytes, seven functions.  Three of the seven have
 * no label in the generated listing because they have no register-saving
 * prologue; they are recovered here by reading the bytes.
 *
 * This range ends exactly where unit_0200852C.c begins, so the two files
 * together cover 0x020084BC..0x0200857C, 190 contiguous bytes and 23
 * functions, with no gap and no overlap.  They are almost certainly two
 * halves of one original source file; they are kept as two files only so that
 * the relocation-free half can carry an EXACT verdict rather than a MATCH.
 *
 * What this unit adds over unit_0200852C.c:
 *
 *   - two literal pools, one per function that needs one, each sitting at the
 *     end of its own function rather than at the end of the unit.
 *   - the same address, 0x0201F41C, is loaded by two different functions in
 *     the unit and is stored twice, once in each pool.  The compiler does not
 *     share a literal between two functions of the same translation unit
 *     even when they are adjacent and the value is identical.  That is the
 *     original image's own evidence for per-function pooling, independent of
 *     anything this project compiles.
 *   - a two-byte 0x00 gap after the empty function at 0x020084F4, which is
 *     the linker's inter-section fill.
 *
 * The verdict is MATCH rather than EXACT only because the three pool words are
 * ABS32 relocations against functions the project has not named.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_020084BC.c \
 *       --addr 0x020084BC --thumb
 */

typedef unsigned short u16;
typedef unsigned int   u32;

extern u32   sub_0201F41C(void *dst, u32 value, u32 size);
extern u32   sub_02045A38(void *dst, u32 value, u32 size);
extern void  sub_02045924(void *a, void *b);
extern void *sub_020457B0(u32 size, u16 tag);

/* "Are all eight halfwords zero".  blt rather than blo makes the counter a
 * signed int, and the early return inside the loop is what puts the
 * `movs r0, #0; bx lr` pair in the middle of the body rather than after it. */
int sub_020084BC(const u16 *values)
{
    int i;
    for (i = 0; i < 8; i++) {
        if (values[i] != 0) {
            return 0;
        }
    }
    return 1;
}

/* Two argument-swapping tail calls.  The `ldr r3, <pool>; bx r3` shape is what
 * -interworking produces for a tail call to an extern whose instruction set
 * the compiler cannot see; 0x0201F41C is Thumb (the pool word is odd) and
 * 0x02045A38 is ARM (it is even), and the same code covers both. */
u32 sub_020084D4(u32 value, void *dst)
{
    return sub_0201F41C(dst, value, 8);
}

u32 sub_020084E4(u32 value, void *dst)
{
    return sub_02045A38(dst, value, 8);
}

void sub_020084F4(void)
{
}

u32 sub_020084F8(void *dst, u32 value, u32 size)
{
    return sub_0201F41C(dst, value, size);
}

/* The argument swap survives into a tail call here too, but this one is 16
 * bytes rather than 12: the extra `adds` is the third scratch register the
 * swap needs when only two arguments are live. */
void sub_02008500(void *a, void *b)
{
    sub_02045924(b, a);
}

/* Allocate an eight-byte object and hand it to the pair above.  The
 * `lsls #16` / `lsrs #16` on the incoming tag is the conversion to u16 at the
 * call, not a u16 parameter: a u16 parameter is truncated by the caller. */
void *sub_02008510(void *a, int tag)
{
    void *p = sub_020457B0(8, (u16)tag);
    sub_02008500(a, p);
    return p;
}

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
 * status:   EXACT
 *
 * symbols:
 *   sub_0201F41C        0x0201F41C  thumb
 *   STRBUF_SetString        0x02045924  arm
 *   STRBUF_ToChars        0x02045A38  arm
 *   STRBUF_Create        0x020457B0  arm
 * function: MYSTATUS_IsNameEmpty, MYSTATUS_CopyName, MYSTATUS_NameFromStrbuf, MYSTATUS_GetName,
 *           MYSTATUS_CopyNameChars, MYSTATUS_NameToStrbuf, MYSTATUS_CreateNameStrbuf
 *
 * 0x020084BC..0x0200852C, 112 bytes, seven functions.  Three of the seven had
 * no label in the generated listing because they have no register-saving
 * prologue; they were recovered here by reading the bytes, and two of them
 * (0x020084D4 and 0x020084E4) are now seeded from layout/function_starts.txt
 * on the strength of the overlay calls that reach them, so the listing shows
 * them as code too.
 *
 * This range ends exactly where unit_0200852C.c begins, so the two files
 * together cover 0x020084BC..0x0200857C, 190 contiguous bytes and 23
 * functions, with no gap and no overlap.  They are almost certainly two
 * halves of one original source file, and both are EXACT.
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
 * All six relocations resolve: the four pool words are ABS32 against
 * functions the listings label and other code calls directly, the blx is a
 * THM_CALL the compiler emitted as a plain bl (it cannot see that
 * func_020457B0 is ARM) and match.py rewrites to BLX exactly as the linker
 * would, and the bl to MYSTATUS_NameToStrbuf is internal to this unit and follows
 * from where the unit is placed.  So the verdict is EXACT.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_020084BC.c \
 *       --addr 0x020084BC --thumb
 */

typedef unsigned short u16;
typedef unsigned int   u32;

extern u32   sub_0201F41C(void *dst, u32 value, u32 size);
struct Strbuf;
struct U16Vec;
extern void STRBUF_ToChars(struct U16Vec *vec, u16 *out, u32 n);
extern void STRBUF_SetString(struct Strbuf *o, const u16 *src);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);

/* "Are all eight halfwords zero".  blt rather than blo makes the counter a
 * signed int, and the early return inside the loop is what puts the
 * `movs r0, #0; bx lr` pair in the middle of the body rather than after it. */
int MYSTATUS_IsNameEmpty(const u16 *values)
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
u32 MYSTATUS_CopyName(u32 value, void *dst)
{
    return sub_0201F41C(dst, value, 8);
}

void MYSTATUS_NameFromStrbuf(u16 *out, struct U16Vec *vec)
{
    STRBUF_ToChars(vec, out, 8);
}

const void *MYSTATUS_GetName(const void *p)
{
    return p;
}

u32 MYSTATUS_CopyNameChars(void *dst, u32 value, u32 size)
{
    return sub_0201F41C(dst, value, size);
}

/* The argument swap survives into a tail call here too, but this one is 16
 * bytes rather than 12: the extra `adds` is the third scratch register the
 * swap needs when only two arguments are live. */
void MYSTATUS_NameToStrbuf(void *a, void *b)
{
    STRBUF_SetString(b, a);
}

/* Allocate an eight-byte object and hand it to the pair above.  The
 * `lsls #16` / `lsrs #16` on the incoming tag is the conversion to u16 at the
 * call, not a u16 parameter: a u16 parameter is truncated by the caller. */
void *MYSTATUS_CreateNameStrbuf(void *a, int tag)
{
    void *p = STRBUF_Create(8, (u16)tag);
    MYSTATUS_NameToStrbuf(a, p);
    return p;
}

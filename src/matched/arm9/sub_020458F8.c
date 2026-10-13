/*
 * unit:     no
 * address:  0x020458F8
 * packet:   pkt_020452E8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * function: STRBUF_GetLength
 *
 * Reads the used-slot count of a u16-array object (see
 * src/matched/STRBUF_Create.c for the layout). A relocation-free leaf; it
 * is the public reader for the field STRBUF_Truncate and STRBUF_Copy write
 * directly.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/STRBUF_GetLength.c  *       --func STRBUF_GetLength --addr 0x020458F8 --cc 1.1p1 --arm
 */

typedef unsigned short u16;
typedef unsigned int u32;

/*
 * The object's tail is one u16 array based at +0x8, not a scalar stamp
 * followed by a separate entry array: STRBUF_Truncate indexes it from zero
 * with `add r3, r0, r1, lsl #1` / `strh r2, [r3, #8]`, and STRBUF_Copy
 * copies (used + 1) halfwords starting at +0x8. Slot 0 is the stamp
 * STRBUF_Create seeds from g_020A7E7C; slots 1.. are the payload.
 */
struct U16Vec {
    u16 capacity;
    u16 used;
    u32 magic;
    u16 slots[1];
};

u16 STRBUF_GetLength(struct U16Vec *vec)
{
    return vec->used;
}

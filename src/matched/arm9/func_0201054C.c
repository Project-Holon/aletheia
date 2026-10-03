/*
 * function: func_0201054C
 * address:  0x0201054C
 * packet:   pkt_0201045C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Three gates on one object then `return 1`.  All three false paths share the
 * single `return 0` at the bottom, which is what puts the `bne`/`beq` on the
 * shared epilogue instead of inlining two `movs r0, #0`: the source is a nest
 * of three `if`s with one `return 1` inside and one `return 0` after them.
 * The compare is against the 8 bytes at 0x020A7250, a cast address constant
 * (no relocation), and `func_0203EFC8` is a memcmp-shaped helper whose zero
 * means equal.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0201054C.c \
 *       --func func_0201054C --addr 0x0201054C --cc 1.1p1 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;

typedef signed int     s32;
typedef unsigned int   u32;
extern s32 func_0203EFC8(const u8 *a, const u8 *b, u32 n);

int func_0201054C(const u8 *obj)
{
    if (*(const u16 *)(obj + 0xa) == 8) {
        if (func_0203EFC8((const void *)0x020A7250, obj + 0xc, 8) != 0) {
            if ((*(const u16 *)(obj + 0x2c) & 0x10) == 0) {
                return 1;
            }
        }
    }
    return 0;
}

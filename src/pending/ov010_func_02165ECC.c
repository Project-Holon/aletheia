/*
 * function: func_02165ECC
 * address:  0x02165ECC
 * packet:   pkt_ov010_02165ECC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * Clear a string buffer and copy the 11-character text at +0x34 into it;
 * the type switch that follows has no effect left in it.
 *
 * DIFF, size-exact (98 of 98 bytes; 2026-09-28 tree_ov010_4): the arms
 * must `return` for the switch to survive, and `if (type == 47)` in the
 * default gives the lone `cmp #0x2f`. Left: the image dispatches as a
 * switch-tree node (`cmp r1, #0x26; bgt cmp47; subs #0x10; bmi exit`, value
 * kept in r1), this C as one range check (`subs; cmp #0x16; bhi`). Writing
 * case 47 as a case widens the table to 0x10..0x2F. Notes:
 * docs/notes/pkt_ov010_02165ECC.c.txt.
 *
 * symbols:
 *   func_0204581C  0x0204581C  arm
 *   func_02045994  0x02045994  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef short s16;

extern void func_0204581C(void *buf);
extern void func_02045994(void *buf, const u16 *src, u32 n);

typedef struct Rec {
    u8 pad00[0x30];
    u16 type;           /* 0x30 */
    u8 pad32[2];
    u16 text[11];       /* 0x34 */
} Rec;

void func_02165ECC(Rec *r, void *buf)
{
    func_0204581C(buf);
    func_02045994(buf, r->text, 11);
    switch (r->type) {
    case 16:
    case 17:
    case 18:
    case 19:
    case 20:
    case 21:
    case 22:
    case 23:
    case 24:
    case 25:
    case 26:
    case 27:
    case 28:
    case 29:
    case 30:
    case 31:
    case 32:
    case 33:
    case 34:
    case 35:
    case 36:
    case 37:
    case 38:
        return;
    default:
        if (r->type == 47)
            return;
    }
}

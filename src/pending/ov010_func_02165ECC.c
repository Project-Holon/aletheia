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
 * DIFF (26 of 98 bytes): the original keeps an empty switch on the type
 * (a 0x10..0x26 table whose every entry, and every value above 0x26, lands on
 * a lone `cmp r1, #0x2f` before the return). Every empty-arm spelling tried
 * (break, return, dead local, empty inline call, goto) is deleted whole or
 * widens the table to 0x10..0x2F. Seed: no permuter run.
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
        break;
    case 47:
        break;
    }
}

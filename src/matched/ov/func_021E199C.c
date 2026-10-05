/*
 * function: func_021E199C
 * address:  0x021E199C
 * packet:   pkt_021DFA3C
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021E199C   0x021E199C  thumb  ov093
 *   func_021E1AA4   0x021E1AA4  thumb  ov093
 * Wrapper family member; the body is the hand-checked shape of the family's first instance with only the member's constants substituted, per the family uniformity assertion in o36/report.md.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

typedef struct { u32 f0; u8 pad[60]; } E64;

void func_021E199C(int a, int b, int c, int d) { func_021E1AA4(b, c, d, 2, 2 << 12); }


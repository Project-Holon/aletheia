/*
 * function: func_021C8494
 * address:  0x021C8494
 * packet:   pkt_021C7EC4
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021C8494   0x021C8494  thumb  ov093
 *   func_021BFF60   0x021BFF60  thumb  ov093
 *   func_021B9934   0x021B9934  thumb  ov093
 * Wrapper family member; the body is the hand-checked shape of the family's first instance with only the member's constants substituted, per the family uniformity assertion in o36/report.md.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

typedef struct { u32 f0; u8 pad[60]; } E64;

extern int func_021B9934(char *p, int i);
extern void func_021BFF60(u8 *p, u8 *a, int z);

void func_021C8494(u8 *p, int i) { func_021BFF60(p, (u8 *)func_021B9934(*(char **)(p + 8), i), 1); }


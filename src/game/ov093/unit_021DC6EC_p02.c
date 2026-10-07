/*
 * file:     unit_021DC6EC_p02.c
 * unit:     yes
 * function: func_021DC820, func_021DC844
 * address:  0x021DC820
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021D70AC 0x021D70AC thumb ov093
 *   func_021B9A40 0x021B9A40 thumb ov093
 *   func_021D775C 0x021D775C thumb ov093
 *   func_021D7320 0x021D7320 thumb ov093
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

struct QS { u8 pad[12]; u32 v; };

extern u8 func_021D70AC(u8 *);
extern u8 func_021B9A40(unsigned int);
extern int func_021D775C(int);
extern void func_021D7320(struct QS *, u32);
int func_021DC820(u8 *a, int b, int c, int d, u16 e, u8 f);
void func_021DC844(struct QS *a, int b, int c);

/*
 * lever: scalar u16/u8 stack inputs; named result preserves cmp operand order.
 */
int func_021DC820(u8 *a, int b, int c, int d, u16 e, u8 f) { u8 result; if (c == 2) { result = func_021B9A40(func_021D70AC(a)); if (result != f && e <= 3) return 1; } return 0; }

/*
 * interface: second payload of func_021D7320 is the unchanged callback word.
 */
void func_021DC844(struct QS *a, int b, int c) { if (c == func_021D775C(3)) func_021D7320(a, (u32)func_021DC820); }

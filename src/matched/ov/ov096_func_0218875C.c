/*
 * function: func_0218875C
 * address:  0x0218875C
 * packet:   pkt_ov096_0218875C
 * region:   ov096
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Two levers closed this: (1) the third argument's zero is an enum-typed
 *   value (`typedef enum { Z0 } E; z = Z0;`) so mwcc does not fold
 *   `(v >> 24) | (z << 8)`; the operand order must put the shift second so
 *   its register is the accumulator (`lsls r2` + `orrs r2,r4`).  (2) the
 *   twice-called helper is 0x0201134C, not the 0x02011324 the old name
 *   implied.
 * symbols:
 *   func_0218A0F4  0x0218A0F4  thumb  ov096
 *   func_0201134C  0x0201134C  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

typedef enum { Z0 } E;

struct Cursor;
extern u32 func_0201134C(struct Cursor *p);
extern u32 func_0203F0A8(void);
extern int func_0218A0F4(u8 *a, int op, int x, int y, int z);

int func_0218875C(struct Cursor *a, int unused, int c) {
    u8 *p;
    u32 v;
    int r;
    E z;
    p = (u8 *)func_0201134C(a);
    r = (int)func_0201134C(a);
    v = func_0203F0A8();
    z = Z0;
    return func_0218A0F4((u8 *)a, c, ((v >> 24) | (z << 8)), (int)p, r);
}

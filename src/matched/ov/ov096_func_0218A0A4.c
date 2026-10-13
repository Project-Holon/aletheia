/*
 * function: func_0218A0A4
 * address:  0x0218A0A4
 * packet:   pkt_ov096_0218A0A4
 * region:   ov096
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   VM_GetU32  0x0201134C  thumb
 *   func_0218A0F4  0x0218A0F4  thumb  ov096
 *   func_0218A160  0x0218A160  thumb  ov096
 *   func_0218A2FC  0x0218A2FC  thumb  ov096
 *   func_021D59B4  0x021D59B4  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

struct Cursor;
extern u32 VM_GetU32(struct Cursor *p);
extern int func_0218A0F4(u8 *, int, int, int, int);
extern u8 func_0218A160(u8 *p, int k);
extern u8 *func_0218A2FC(u8 *p, u8 i);
extern int func_021D59B4(u8 *p, int k);

int func_0218A0A4(struct Cursor *a, u8 *b, int c)
{
    int t;
    int n;
    u8 s;
    t = VM_GetU32(a);
    n = VM_GetU32(a);
    s = func_0218A160(b, t);
    func_021D59B4(func_0218A2FC(b, s), 8);
    return func_0218A0F4((u8 *)a, c, s, func_021D59B4(func_0218A2FC(b, s), 10), n);
}

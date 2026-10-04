/*
 * function: func_02188BB0
 * address:  0x02188BB0
 * packet:   pkt_ov096_02188BB0
 * region:   ov096
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Lever: b is a pointer to a Conn struct (fields fbc, fc4) so the b+0xbc
 *   address is not CSE'd across the calls (the original re-adds it each time);
 *   func_0218A378's second parameter is int (no truncation before the bl).
 * symbols:
 *   func_0201134C  0x0201134C  thumb
 *   func_020113B0  0x020113B0  thumb
 *   func_0218A378  0x0218A378  thumb  ov096
 *   func_021D5448  0x021D5448  thumb  ov093
 *   func_021D54C0  0x021D54C0  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u8 pad00[0xbc];
    u8 *fbc;
    u8 padC0[4];
    int fc4;
} Conn;

extern int func_0201134C(int);
struct Cur;
struct QG;
extern void func_020113B0(struct Cur *c, u32 v);
extern int func_0218A378(Conn *, int, int);
extern u8 func_021D5448(struct QG *p);
extern u16 func_021D54C0(u8 *p, int i);

int func_02188BB0(int a, Conn *b)
{
    int m;
    int i;

    m = func_0201134C(a);
    for (i = 0; i < func_021D5448((struct QG *)b->fbc); i++) {
        if (func_0218A378(b, func_021D54C0(b->fbc, (u8)i), 3) != 0)
            break;
    }
    if (i < func_021D5448((struct QG *)b->fbc))
        func_020113B0((struct Cur *)a, *(int *)(a + 0x14) + m);
    return b->fc4;
}

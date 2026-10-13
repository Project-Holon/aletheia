/*
 * function: func_021596B4
 * address: 0x021596B4
 * packet: pkt_ov010_021596B4
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * prototype: 020113B4's matched ARM9 unit copies the full-word second
 * input unchanged into +0x14; original caller supplies a cursor address.
 * Pointer declaration preserves that payload and matches the fixed flags.
 * symbols:
 *   d_021705DC 0x021705DC data ov010
 *   VM_Call  0x020113B4  thumb  arm9
 */
typedef unsigned char u8;
struct P { int _0[3]; u8 _p[2]; u8 e; u8 _f[5]; u8 *cur; };
struct Cursor;
extern unsigned int func_0201134C(struct Cursor *p);
typedef unsigned int   u32;
struct Ring;
extern void VM_Call(struct Ring *r, u32 v);
extern u8 d_021705DC[][3];
int func_021596B4(struct P *p)
{
    u8 *q = p->cur;
    u8 c = *q;
    int n;
    p->cur = q + 1;
    n = func_0201134C((struct Cursor *)p);
    if (d_021705DC[c][p->e] == 1)
        VM_Call((struct Ring *)p, (u32)(p->cur + n));
    return 0;
}

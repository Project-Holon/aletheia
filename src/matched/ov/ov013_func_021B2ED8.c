/*
 * function: func_021B2ED8
 * address: 0x021B2ED8
 * packet: pkt_ov013_021B2ED8
 * region: ov013
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: arm
 * status: EXACT
 * lever: fill call takes data, p and b; r1/r2 stay live across the guards.
 * symbols:
 *   d_021B4C24 0x021B4C24 data a4
 *   func_02082AC0 0x02082AC0 arm
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct E { struct E *next; u8 pad[0x474]; } E;
typedef struct { E *cur; E *buf; } G;
extern G d_021B4C24;
extern void func_02082AC0(int, void *, u32);
int func_021B2ED8(E *a, u32 b)
{
    u32 i;
    u32 n;
    E *p;
    n = b / 0x478;
    p = a;
    d_021B4C24.buf = p;
    if (n < 4 || n > 0x48) return 0;
    if (p == 0) return 0;
    if ((u32)p & 0x1f) {
        d_021B4C24.buf = 0;
        return 0;
    }
    i = 0;
    func_02082AC0(i, p, b);
    for (i = 0; i < n - 1; i++)
        d_021B4C24.buf[i].next = &d_021B4C24.buf[i + 1];
    (d_021B4C24.buf + n)[-1].next = 0;
    d_021B4C24.cur = d_021B4C24.buf;
    return 1;
}

/*
 * function: func_021D6724
 * address: 0x021D6724
 * packet: pkt_ov175_021D6724
 * region: ov175
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two-byte alignment padding at 021D6786.
 * symbols:
 *   func_0200DFD8 0x0200DFD8 thumb
 */
typedef unsigned int u32;
extern u32 func_0200DFD8(u32,u32,u32);
void func_021D6724(u32 *p, u32 *q)
{
    u32 *r = (u32 *)q[16];
    if (r[0] == 0) {
        p[10] = func_0200DFD8(r[4], ((u32 *)r[2])[1] + 5, 1);
        r = (u32 *)q[16];
        p[11] = func_0200DFD8(r[4], ((u32 *)r[2])[1] + 5, 2);
        r = (u32 *)q[16];
        p[13] = func_0200DFD8(r[4], ((u32 *)r[2])[1] + 5, 0);
    } else {
        p[10] = func_0200DFD8(r[4], ((u32 *)r[2])[1], 1);
        r = (u32 *)q[16];
        p[11] = func_0200DFD8(r[4], ((u32 *)r[2])[1], 2);
    }
}

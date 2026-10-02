/*
 * function: func_021B6EA8
 * address: 0x021B6EA8
 * packet: pkt_ov172_021B6EA8
 * region: ov172
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 */
typedef unsigned short u16;
typedef unsigned int u32;
void func_021B6EA8(void *p, u16 v)
{
    u16 *h = (u16 *)p;
    h[2] = v;
    h[3] = v + 5;
    if (h[3] >= h[1])
        h[3] -= h[1];
}

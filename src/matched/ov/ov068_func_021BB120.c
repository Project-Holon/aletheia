/*
 * function: func_021BB120
 * address: 0x021BB120
 * packet: pkt_ov068_021BB120
 * region: ov068
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 */
typedef unsigned char u8;
typedef void (*Callback)(void *, void *, int);
void func_021BB120(u8 *p)
{
    if (*(int *)(p + 4) == 0)
        (*(Callback *)p)(p, p + 8, *(int *)(p + 12));
}

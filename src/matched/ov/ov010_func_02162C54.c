/*
 * function: func_02162C54
 * address: 0x02162C54
 * packet: pkt_ov010_02162C54
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: case 0 falls through into default at the final shared return.
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
int func_02162C54(u8 *p)
{
    switch (p[4]) {
    case 1: return 0;
    case 2: return 1;
    case 3: return 2;
    case 4: return 3;
    case 0:
    default: return 1;
    }
}

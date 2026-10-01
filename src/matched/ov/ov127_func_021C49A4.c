/*
 * function: func_021C49A4
 * address: 0x021C49A4
 * packet: pkt_ov127_021C49A4
 * region: ov127
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two zero alignment bytes at 0x021C49FE follow the return.
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
int func_021C49A4(u8 *p, unsigned int i)
{
    switch (i) {
    case 0: return *(s16 *)(p + 4);
    case 1: return *(s16 *)(p + 6);
    case 2: return *(s16 *)(p + 8);
    case 3: return *(s16 *)(p + 10);
    case 4: return *(u16 *)(p + 12);
    case 5: return p[21];
    case 6: return p[20];
    case 7: return *(u16 *)(p + 14);
    case 8: return *(u16 *)(p + 16);
    case 9: return *(u16 *)(p + 18);
    case 10: return *(u16 *)(p + 22);
    default: return (int)p;
    }
}

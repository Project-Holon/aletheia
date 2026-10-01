/*
 * function: func_021BE32C
 * address: 0x021BE32C
 * packet: pkt_ov208_021BE32C
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * trailing: 021BE376..021BE378 is two-byte zero alignment padding.
 */
unsigned func_021BE32C(unsigned n)
{
    switch(n) {
    case 0: break;
    case 6: case 15: return 6;
    case 7: case 16: return 5;
    case 8: case 17: return 4;
    case 9: case 18: return 3;
    default: break;
    }
    return 9;
}

/*
 * function: MUSICAL_MCSS_IsModeSupportedC
 * address: 0x021F5064
 * packet: pkt_ov112_021F5064
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 */
typedef unsigned char u8;
int MUSICAL_MCSS_IsModeSupportedC(u8 *p, int mode)
{
    switch (mode) {
    case 0: case 1: if (p[8] == 0) return 1; break;
    case 2: if (p[8] == 1) return 1; break;
    case 3: if ((u8)(p[8] + 254) <= 1) return 1; break;
    case 4: if (p[8] == 4) return 1; break;
    case 5: if (p[8] == 5) return 1; break;
    case 6: case 7: if (p[8] == 6) return 1; break;
    case 8: return 0;
    }
    return 0;
}

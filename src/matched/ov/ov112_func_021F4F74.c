/*
 * function: MUSICAL_MCSS_SetModeA
 * address: 0x021F4F74
 * packet: pkt_ov112_021F4F74
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 */
typedef unsigned short u16;
int MUSICAL_MCSS_SetModeA(u16 *p, int mode)
{
    switch (mode) {
    case 0: case 1: if (p[3] & 1) return 1; break;
    case 2: if (p[3] & 2) return 1; break;
    case 3: if (p[3] & 4) return 1; break;
    case 4: if (p[3] & 8) return 1; break;
    case 5: if (p[3] & 16) return 1; break;
    case 6: if (p[3] & 32) return 1; break;
    case 7: case 8: if (p[3] & 64) return 1; break;
    case 9: return 0;
    }
    return 0;
}

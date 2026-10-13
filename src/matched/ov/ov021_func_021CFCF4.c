/*
 * function: SCRCMD_GetPartnerCandidateHistoryIndex
 * address:  0x021CFCF4
 * packet:   pkt_ov021_021CFCF4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Tbl021CFCF4 {
    u8 f0;
    u8 n;
    u8 pad2[6];
    u8 v[5];
} Tbl021CFCF4;

u8 SCRCMD_GetPartnerCandidateHistoryIndex(Tbl021CFCF4 *p, u32 i)
{
    u8 r = 0xff;

    if (i < 5 && i < p->n) {
        r = p->v[i];
    }
    return r;
}

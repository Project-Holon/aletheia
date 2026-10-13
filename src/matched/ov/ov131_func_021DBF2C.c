/*
 * function: P_STA_RIBBON_GetRibbonInfo
 * address: 0x021DBF2C
 * packet: pkt_ov131_021DBF2C
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   P_STA_RIBBON_InfoTable 0x021DC2F8 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Entry { u32 a; u16 b, c, d, e; u8 f; u8 pad[3]; };
extern const struct Entry P_STA_RIBBON_InfoTable[];
u32 P_STA_RIBBON_GetRibbonInfo(u32 i, u32 field)
{
    switch (field) {
    case 0: return P_STA_RIBBON_InfoTable[i].a;
    case 1: return P_STA_RIBBON_InfoTable[i].b;
    case 2: return P_STA_RIBBON_InfoTable[i].c;
    case 3: return P_STA_RIBBON_InfoTable[i].d;
    case 4: return P_STA_RIBBON_InfoTable[i].e;
    case 5: return P_STA_RIBBON_InfoTable[i].f;
    default: return 0;
    }
}

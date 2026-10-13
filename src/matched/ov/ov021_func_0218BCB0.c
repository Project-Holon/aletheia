/*
 * function: FIELD_BUILDMODEL_GetModelAnimKind
 * address:  0x0218BCB0
 * packet:   pkt_ov021_0218BCB0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   gBuildModelAnimKindTable     0x021D3DC4  data  a4
 */

typedef struct {
    unsigned char b[16];
} Tbl;

extern const Tbl gBuildModelAnimKindTable;

unsigned char FIELD_BUILDMODEL_GetModelAnimKind(unsigned short *p)
{
    Tbl t = gBuildModelAnimKindTable;
    if (p[1] >= 16)
        return 0;
    return t.b[p[1]];
}

/*
 * function: FIELD_BBD_COLOR_Load
 * address:  0x021CD204
 * packet:   pkt_ov021_021CD204
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Forwards to ARC_TOOL_ReadHandleMember with the holder's archive, the caller's argument and the holder's +4 field.
 *
 * symbols:
 *   ARC_TOOL_ReadHandleMember  0x0204932C  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

typedef struct {
    void *arc;
    u32 f4;
} Holder;

struct ArcFile;
extern void ARC_TOOL_ReadHandleMember(struct ArcFile *arc, u32 member, void *dst);

void FIELD_BBD_COLOR_Load(Holder *h, u32 a)
{
    ARC_TOOL_ReadHandleMember(h->arc, a, &h->f4);
}

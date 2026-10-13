/*
 * unit:     yes
 * address:  0x0201ADA4
 * packet:   pkt_0201A5FC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: POKE_PERSONAL_LoadData
 *
 * symbols:
 *   _pPersonalArc  0x0214652C  data
 *   ARC_TOOL_GetHandleMemberOffset  0x02049578  arm
 *   ARC_TOOL_ReadHandle  0x020495F4  arm
 *   POKE_PERSONAL_GetFormDataId  0x0201AFD4  thumb
 *
 * A three-parameter wrapper: calls POKE_PERSONAL_GetFormDataId(a, b) (0x0201AFD4, still
 * open) and threads its result through two handler calls keyed off a static
 * handle at 0x0214652C, then hands the third parameter off to a third
 * handler with a literal id of 0x3C.  Kept as its own file rather than
 * merged with the neighbouring POKE_PERSONAL_LoadDataDirect/POKE_PERSONAL_Create
 * (src/matched/unit_0201ADD0.c) because both of those call POKE_PERSONAL_GetFormDataId as
 * well; one range holding all three calls has none of them attested and
 * caps at MATCH (docs/idioms/split-a-unit-so-two-call-sites-attest-each-other.md).
 * With this function alone, the other two callers are outside the range and
 * carry the `label` evidence.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201ADA4.c \
 *       --addr 0x0201ADA4 --thumb
 */

typedef unsigned int u32;

struct ArcFile;
extern u32 POKE_PERSONAL_GetFormDataId(u32 a, int b);
extern u32 ARC_TOOL_GetHandleMemberOffset(struct ArcFile *handle, u32 x);
extern void *func_0204960C(void *handle, void *x);
struct ArcFile;
extern void ARC_TOOL_ReadHandle(struct ArcFile *arc, u32 size, void *dst);
extern void *_pPersonalArc;

void POKE_PERSONAL_LoadData(u32 a, int b, void *c)
{
    u32 r = POKE_PERSONAL_GetFormDataId(a, b);

    r = ARC_TOOL_GetHandleMemberOffset(_pPersonalArc, r);
    func_0204960C(_pPersonalArc, (void *)r);
    ARC_TOOL_ReadHandle(_pPersonalArc, 0x3C, c);
}

/*
 * function: FIELD_FK_DEMO_IsBuildAnimeDone
 * address: 0x021F3918
 * packet: pkt_ov056_021F3918
 * region: ov056
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   FIELD_BUILDMODEL_TryOpenNodeSlot 0x0218C8B0 thumb ov021
 */
extern int FIELD_BUILDMODEL_TryOpenNodeSlot(void *,int);
int FIELD_FK_DEMO_IsBuildAnimeDone(void **p) { if (*p) return FIELD_BUILDMODEL_TryOpenNodeSlot(*p,0); return 1; }

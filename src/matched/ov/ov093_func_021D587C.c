/*
 * function: BTL_POKEPARAM_RemapStatId
 * address: 0x021D587C
 * packet: pkt_ov093_021D587C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_FIELD_IsStaticSlotInUse 0x021EF948 thumb ov093
 */
extern int BTL_FIELD_IsStaticSlotInUse(int);
int BTL_POKEPARAM_RemapStatId(void *p, int k)
{
    switch(k) {
    case 9: if (BTL_FIELD_IsStaticSlotInUse(6)) k = 11; break;
    case 11: if (BTL_FIELD_IsStaticSlotInUse(6)) k = 9; break;
    }
    return k;
}

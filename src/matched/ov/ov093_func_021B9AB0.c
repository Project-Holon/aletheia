/*
 * function: BTL_SLOT_GetRotateSrcIndex
 * address: 0x021B9AB0
 * packet: pkt_ov093_021B9AB0
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 */
int BTL_SLOT_GetRotateSrcIndex(int x)
{
    switch (x) {
    case 2: return 1;
    case 3: return 2;
    default: return 0;
    }
}

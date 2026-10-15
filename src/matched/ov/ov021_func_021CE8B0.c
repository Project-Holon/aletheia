/*
 * function: COMM_ENTRY_MENU_UpdateMemberName
 * address:  0x021CE8B0
 * packet:   pkt_ov021_021CE8B0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GF_STANDARD_CompareBytes  0x0203EFC8  arm
 *   COMM_ENTRY_MENU_PrintMemberName  0x021CE934  thumb  ov021
 *   MI_CpuCopy8  0x02082D44  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;

extern int GF_STANDARD_CompareBytes(const void *a, const void *b, int n);
extern void COMM_ENTRY_MENU_PrintMemberName(u8 *p, u8 *e, u8 i);
extern void MI_CpuCopy8(void *src, void *dst, int n);

void COMM_ENTRY_MENU_UpdateMemberName(u8 *p, u8 *e, int i)
{
    u8 *t;

    t = p + 0x55a;
    if (GF_STANDARD_CompareBytes(e + 0x23, t + i * 6, 6)) {
        COMM_ENTRY_MENU_PrintMemberName(p, e, i);
        MI_CpuCopy8(e + 0x23, t + i * 6, 6);
    }
}

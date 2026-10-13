/*
 * function: COMM_ENTRY_MENU_RefreshNames
 * address:  0x021CE9A0
 * packet:   pkt_ov021_021CE9A0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   COMM_ENTRY_MENU_EraseMemberName  0x021CE984  thumb  ov021
 *   COMM_ENTRY_MENU_PrintMemberName  0x021CE934  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void COMM_ENTRY_MENU_EraseMemberName(u32 *p, u32 n);
extern void COMM_ENTRY_MENU_PrintMemberName(u8 *p, u8 *q, u32 c);

void COMM_ENTRY_MENU_RefreshNames(u8 *p)
{
    int i;

    if (p[0x518] != 0) {
        p[0x518] = 0;
        for (i = 0; i < 4; i++) {
            COMM_ENTRY_MENU_EraseMemberName((u32 *)p, i);
            if (p[0x514] & (1 << i))
                COMM_ENTRY_MENU_PrintMemberName(p, p + 0x494 + i * 32, (u8)i);
        }
    }
}

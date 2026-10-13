/*
 * function: COMM_ENTRY_MENU_ClearMemberName
 * address:  0x021CE8F4
 * packet:   pkt_ov021_021CE8F4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0203EFC8  0x0203EFC8  arm
 *   COMM_ENTRY_MENU_EraseMemberName  0x021CE984  thumb  ov021
 *   MI_CpuCopy8  0x02082D44  arm
 *   gCommEntryEmptyMac  0x021DB470  data  a4
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef struct { u8 b[6]; } Mac;

typedef signed int     s32;
typedef unsigned int   u32;
extern s32 func_0203EFC8(const u8 *a, const u8 *b, u32 n);
extern void COMM_ENTRY_MENU_EraseMemberName(u32 *p, u32 n);
extern void MI_CpuCopy8(void *src, void *dst, int n);
extern u8 gCommEntryEmptyMac[];

void COMM_ENTRY_MENU_ClearMemberName(u8 *p, u8 *e, int i)
{
    if (func_0203EFC8(p + 0x55a + i * 6, gCommEntryEmptyMac, 6)) {
        COMM_ENTRY_MENU_EraseMemberName((u32 *)p, i);
        MI_CpuCopy8(gCommEntryEmptyMac, ((Mac *)(p + 0x55a))[i].b, 6);
    }
}

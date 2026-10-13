/*
 * function: BTL_CLIENT_StepAddFieldSlotHolder
 * address: 0x021D3B88
 * packet: pkt_ov093_021D3B88
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT* (two bytes alignment padding)
 * symbols:
 *   BTL_FIELD_AddSlotHolder 0x021EFAD8 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct { u32 v; } Slot;
extern int BTL_FIELD_AddSlotHolder(char *a, u32 b, u32 c);
int BTL_CLIENT_StepAddFieldSlotHolder(u32 *a, int *b, u32 *c)
{
    BTL_FIELD_AddSlotHolder((char *)a[13], c[0], (u8)c[1]);
    return 1;
}

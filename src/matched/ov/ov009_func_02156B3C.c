/*
 * function: DWC_RAP_OnNewClient
 * address: 0x02156B3C
 * packet: pkt_ov009_02156B3C
 * region: ov009
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   g_021A8264 0x021A8264 data ov009 a4
 * Extent follower 02156B68 already has its own matched file.
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef void (*Callback)(u16, int);
extern u8 *g_021A8264;
void DWC_RAP_OnNewClient(int a)
{
    *(int *)(g_021A8264 + 0x774) = a;
    if (*(Callback *)(g_021A8264 + 0x29c) != 0)
        (*(Callback *)(g_021A8264 + 0x29c))((u16)a, *(int *)(g_021A8264 + 0x2a0));
}

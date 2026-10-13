/*
 * function: func_021762C0
 * address: 0x021762C0
 * packet: pkt_ov011_021762C0
 * region: ov011
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   INTRUDE_COMM_SetWordSetPlayerName 0x02176280 thumb ov011
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u8 bit : 1; } Flag;
extern void INTRUDE_COMM_SetWordSetPlayerName(void *win, u32 slot, void *src, u32 size, u16 heap, u32 a);
void func_021762C0(void *win, u32 slot, u8 *src, u16 heap)
{
    INTRUDE_COMM_SetWordSetPlayerName(win, slot, src, 8, heap, ((Flag *)(src + 0x11))->bit);
}

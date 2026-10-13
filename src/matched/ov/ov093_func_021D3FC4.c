/*
 * function: BTL_CLIENT_UnlockCounter
 * address: 0x021D3FC4
 * packet: pkt_ov093_021D3FC4
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * match-note: Clearing the unsigned-char bitfield emits bics #0x10;
 * raw p[2] &= ~0x10 emits ands #0xef and was four bytes out.
 * extent: Ten bytes of code, two zero padding bytes at 021D3FCE, then
 * existing matched BTL_CLIENT_DisableCounter at 021D3FD0; no follower included.
 */
typedef unsigned char u8;
typedef struct { u8 pad[2]; u8 low:4,flag:1,rest:3; } Flags;
void BTL_CLIENT_UnlockCounter(Flags *p)
{
    p->flag = 0;
}

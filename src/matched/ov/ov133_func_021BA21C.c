/*
 * function: DUP_FITTING_ITEM_ElemSetPos
 * address: 0x021BA21C
 * packet: pkt_ov133_021BA21C
 * region: ov133
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct {u32 a,b;} Pair;
void DUP_FITTING_ITEM_ElemSetPos(u8 *p, const u8 *src)
{
    *(Pair *)(p+16)=*(const Pair *)src;
}

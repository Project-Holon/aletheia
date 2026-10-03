/*
 * function: func_021BA22C
 * address: 0x021BA22C
 * packet: pkt_ov133_021BA22C
 * region: ov133
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct {u32 a,b;} Pair;
void func_021BA22C(u8 *p, const u8 *src)
{
    *(Pair *)(p+36)=*(const Pair *)src;
}

/*
 * function: BTLV_SCU_AppendMessageArg
 * address:  0x021EAF50
 * packet:   pkt_ov093_021EAF50
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct L {
    u16 id;
    u8 k;
    u8 kind : 4;
    u8 n : 4;
    u32 v[8];
};
void BTLV_SCU_AppendMessageArg(struct L *p, u32 val)
{
    u32 n = p->n;
    if (n < 8) {
        p->n = n + 1;
        p->v[n] = val;
    }
}

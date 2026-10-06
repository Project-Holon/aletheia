/*
 * function: func_021EAF18
 * address:  0x021EAF18
 * packet:   pkt_ov093_021EAF18
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
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
void func_021EAF18(struct L *p, int kind, int id)
{
    u32 i;
    for (i = 0; i < 8; i++)
        p->v[i] = 0;
    p->n = 0;
    p->id = id;
    p->kind = kind;
    p->k = 0x50;
}

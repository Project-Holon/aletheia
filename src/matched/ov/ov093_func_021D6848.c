/*
 * function: func_021D6848
 * address: 0x021D6848
 * packet: pkt_ov093_021D6848
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
struct Rec {u16 a,b,c,d;};
void func_021D6848(u8 *p, struct Rec *r)
{
    u8 n;
    u8 k = p[0x1ef];
    u32 i;
    u8 *q;
    n = (p + 0x1ec)[k];
    if (n == 6) {
        for (i = 0; i < 5; i++) {
            q = p + k * 0x30 + i * 8;
            *(u16 *)(q + 0x15c) = *(u16 *)(q + 0x164);
            *(u16 *)(q + 0x15e) = *(u16 *)(q + 0x166);
            *(u16 *)(q + 0x160) = *(u16 *)(q + 0x168);
            *(u16 *)(q + 0x162) = *(u16 *)(q + 0x16a);
        }
        n--;
    }
    q = p + k * 0x30 + n * 8;
    *(u16 *)(q + 0x15c) = r->a;
    *(u16 *)(q + 0x15e) = r->b;
    *(u16 *)(q + 0x160) = r->c;
    *(u16 *)(q + 0x162) = r->d;
    if ((p + 0x1ec)[k] < 6) (p + 0x1ec)[k]++;
}

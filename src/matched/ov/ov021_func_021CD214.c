/*
 * function: func_021CD214
 * address:  0x021CD214
 * packet:   pkt_ov021_021CD214
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0207CDB8  0x0207CDB8  arm
 *   func_0204ED4C  0x0204ED4C  arm
 *   func_0204ED80  0x0204ED80  arm
 *   func_0204ED8C  0x0204ED8C  arm
 *   func_0204ED98  0x0204ED98  arm
 *   func_0204EDA4  0x0204EDA4  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;

extern void func_0207CDB8(u16 *a, u16 *b);
extern void func_0204ED4C(void *o, u16 *v);
extern void func_0204ED80(void *o, u16 *v);
extern void func_0204ED8C(void *o, u16 *v);
extern void func_0204ED98(void *o, u16 *v);
extern void func_0204EDA4(void *o, u16 *v);

void func_021CD214(u8 *s, void *o)
{
    u16 v[3];
    u16 c[4];

    v[0] = *(int *)(s + 4);
    v[1] = *(int *)(s + 8);
    v[2] = *(int *)(s + 0xc);
    func_0207CDB8(v, v);
    func_0204ED4C(o, v);
    c[3] = *(u16 *)(s + 0x10) | (*(u16 *)(s + 0x12) << 5) | (*(u16 *)(s + 0x14) << 10);
    func_0204ED80(o, &c[3]);
    c[2] = *(u16 *)(s + 0x16) | (*(u16 *)(s + 0x18) << 5) | (*(u16 *)(s + 0x1a) << 10);
    func_0204ED8C(o, &c[2]);
    c[1] = *(u16 *)(s + 0x1c) | (*(u16 *)(s + 0x1e) << 5) | (*(u16 *)(s + 0x20) << 10);
    func_0204ED98(o, &c[1]);
    c[0] = *(u16 *)(s + 0x22) | (*(u16 *)(s + 0x24) << 5) | (*(u16 *)(s + 0x26) << 10);
    func_0204EDA4(o, &c[0]);
}

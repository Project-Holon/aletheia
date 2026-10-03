/*
 * function: func_021C4AF4
 * address: 0x021C4AF4
 * packet: pkt_ov208_021C4AF4
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201C6EC 0x0201C6EC thumb
 *   func_0201C4C0 0x0201C4C0 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Ov208Menu {
    u8  pad0[0x568];
    u32 slot[5];
    u32 print[5];
};
extern void func_0201C6EC(u32 print);
extern void func_0201C4C0(u32 print);
void func_021C4AF4(u16 *heap, struct Ov208Menu *p)
{
    u8 i;
    for (i = 0; i < 5; i++) {
        p->slot[i] = 0;
        func_0201C6EC(p->print[i]);
        func_0201C4C0(p->print[i]);
    }
}

/*
 * function: func_021C4AC4
 * address: 0x021C4AC4
 * packet: pkt_ov208_021C4AC4
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201C440 0x0201C440 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Ov208Menu {
    u8  pad0[0x568];
    u32 slot[5];
    u32 print[5];
};
extern u32 func_0201C440(void *p);
void func_021C4AC4(u16 *heap, struct Ov208Menu *p)
{
    u8 i;
    for (i = 0; i < 5; i++) {
        p->print[i] = func_0201C440((void *)(*heap));
        p->slot[i] = 0;
    }
}

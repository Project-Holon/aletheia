/*
 * function: func_021BC828
 * address: 0x021BC828
 * packet: pkt_ov110_021BC828
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02040618 0x02040618 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern void func_02040618(u8, u8, int);
void func_021BC828(void *unused, u8 *p)
{
    if (*(u16 *)(p+0x14)) {
        *(int *)(p+8) += *(int *)(p+0x10);
        func_02040618(*(int *)p, *(int *)(p+4), *(int *)(p+8)>>12);
        --*(u16 *)(p+0x14);
    } else {
        func_02040618(*(int *)p, *(int *)(p+4), *(int *)(p+0xc));
    }
}

/*
 * function: func_021C4B88
 * address: 0x021C4B88
 * packet: pkt_ov136_021C4B88
 * region: ov136
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: p[0x18] >> 1 promotes to signed int before the u8 argument;
 * an unsigned cast drops the narrowing shift pair, a bitfield shifts 24/25.
 * symbols:
 *   func_021C44FC 0x021C44FC thumb ov136
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021C44FC(u8 *);
struct Chan02021FD8;
extern void func_02021FD8(struct Chan02021FD8 *p, u32 idx, u32 c, u32 count, u8 weight, u16 color);
void func_021C4B88(void *unused, u8 *p)
{
    u8 old;
    u8 direction;
    if (*(u32 *)(p + 0x10) != 0 || p[0xA] == 0) return;
    if (p[0x1B] != p[0x1A]) {
        func_021C44FC(p);
        p[0x1B] = p[0x1A];
    }
    func_02021FD8(*(void **)(p + 0x38), 0, (u16)(p[0x1A] + 33), 1, p[0x18] >> 1, 0x7FFF);
    direction = p[0x19];
    old = p[0x18];
    if (direction != 0) {
        p[0x18] = old - 1;
        if (old == 1) p[0x19] = direction ^ 1;
    } else {
        p[0x18] = old + 1;
        if (old == 24) p[0x19] = direction ^ 1;
    }
}

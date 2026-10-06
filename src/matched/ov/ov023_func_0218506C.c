/*
 * function: func_0218506C
 * address: 0x0218506C
 * packet: pkt_ov023_0218506C
 * region: ov023
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0204B528 0x0204B528 arm
 */
typedef unsigned short u16;
typedef struct { u16 x, y; } Pt;
struct Actor;
struct Pt;
extern void func_0204B528(struct Actor *actor, const struct Pt *src);
void func_0218506C(void *actor, int x, int y)
{
    Pt p;
    p.x = x;
    p.y = y - 8;
    func_0204B528(actor, (const struct Pt *)(&p));
}

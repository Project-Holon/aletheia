/*
 * function: BTL_SERVER_FLOW_BeginHandExScope
 * address:  0x021CC8D8
 * packet:   pkt_ov093_021CC8D8
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

struct Lock {
    u32 a : 10;
    u32 b : 9;
    u32 c : 9;
    u32 d : 1;
    u32 e : 1;
    u32 f : 1;
    u32 g : 1;
};
struct Lock BTL_SERVER_FLOW_BeginHandExScope(struct Lock *p, int line)
{
    struct Lock old = *p;
    p->a = 0;
    p->c = p->b;
    p->e = 0;
    p->d = 0;
    p->f = 0;
    return old;
}

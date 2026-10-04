/*
 * function: func_021ED108
 * address:  0x021ED108
 * packet:   pkt_ov170_021ED108
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204B570 0x0204B570 arm
 *   func_0204B588 0x0204B588 arm
 */

typedef unsigned int   u32;
struct Actor;
struct Pt;
extern void func_0204B588(struct Actor *actor, const struct Pt *src);
extern void func_0204B570(struct Actor *actor, u32 value);

#define HND(p) (*(int *)((p) + 0x9E9C))

void func_021ED108(char *p, int on)
{
    unsigned short s[2];
    if (on == 1) {
        func_0204B570((struct Actor *)HND(p), 1);
        s[0] = 0xC;
        s[1] = 0xC;
        func_0204B588((struct Actor *)HND(p), (const struct Pt *)s);
    } else {
        s[0] = 0;
        s[1] = 0;
        func_0204B588((struct Actor *)HND(p), (const struct Pt *)s);
        func_0204B570((struct Actor *)HND(p), 0);
    }
}

/*
 * function: func_021BA7C8
 * address: 0x021BA7C8
 * packet: pkt_ov206_021BA7C8
 * region: ov206
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02040588 0x02040588 arm
 *   func_02041EE4 0x02041EE4 arm
 *   func_021BBE34 0x021BBE34 thumb ov206
 */
typedef struct { char pad[0x44]; int state; char pad48[4]; unsigned char a,b,c; } State;
extern void func_02040588(int, int);
extern void func_02041EE4(int, int, int);
extern void func_021BBE34(State *, int);
void func_021BA7C8(State *p)
{
    if (!p->state) {
        p->state = 1;
        func_02040588(p->a, 0);
        func_02040588(p->b, 0);
        func_02041EE4(p->c, 3, -256);
        func_021BBE34(p, p->state == 0);
    }
}

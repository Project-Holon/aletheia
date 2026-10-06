/*
 * function: func_021BA814
 * address: 0x021BA814
 * packet: pkt_ov206_021BA814
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
typedef struct { char pad[0x44]; int state; char pad48[4]; unsigned char a,b,c; char pad4f[0x1b4-0x4f]; int delta; } State;
typedef unsigned int   u32;
extern void func_02040588(u32 which, unsigned char enable);
extern void func_02041EE4(u32 index, u32 a, u32 b);
struct S;
extern void func_021BBE34(struct S *p, int v);
void func_021BA814(State *p)
{
    if (p->state) {
        p->state = 0;
        func_02040588(p->a, 1);
        func_02040588(p->b, 1);
        func_02041EE4(p->c, 3, -p->delta);
        func_021BBE34((struct S *)p, p->state == 0);
    }
}

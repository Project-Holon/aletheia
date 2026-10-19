/*
 * function: ZUKAN_INFO_Show
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
 *   BG_SYS_ChangeScroll 0x02041EE4 arm
 *   ZUKAN_INFO_SetSlotDrawEnable 0x021BBE34 thumb ov206
 */
typedef struct { char pad[0x44]; int state; char pad48[4]; unsigned char a,b,c; } State;
typedef unsigned int   u32;
extern void func_02040588(unsigned char which, unsigned char enable);
extern void BG_SYS_ChangeScroll(u32 index, u32 a, u32 b);
struct S;
extern void ZUKAN_INFO_SetSlotDrawEnable(struct S *p, int v);
void ZUKAN_INFO_Show(State *p)
{
    if (!p->state) {
        p->state = 1;
        func_02040588(p->a, 0);
        func_02040588(p->b, 0);
        BG_SYS_ChangeScroll(p->c, 3, -256);
        ZUKAN_INFO_SetSlotDrawEnable((struct S *)p, p->state == 0);
    }
}

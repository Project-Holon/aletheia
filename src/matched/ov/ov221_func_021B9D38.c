/*
 * function: func_021B9D38
 * address: 0x021B9D38
 * packet: pkt_ov221_021B9D38
 * region: ov221
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02040804 0x02040804 arm
 *   func_02041EE4 0x02041EE4 arm
 *   func_0204B454 0x0204B454 arm
 *   func_0204B404 0x0204B404 arm
 */
struct Obj;
struct Vec2 { short x,y; };
extern unsigned func_02040804(unsigned);
extern void func_02041EE4(unsigned,unsigned,unsigned);
struct Actor;
struct PtS;
extern void func_0204B454(struct Actor *, struct PtS *, unsigned int);
extern void func_0204B404(struct Obj *,const struct Vec2 *,unsigned);
void func_021B9D38(unsigned char *p)
{
    int amount;
    if(*(unsigned *)(*(unsigned char **)(p+4)+4)!=0) return;
    amount=func_02040804(1);
    if(!amount) return;
    if(p[0x44]==0) {
        struct Vec2 pair;
        if(amount>=2) amount=2;
        func_02041EE4(1,5,amount);
        func_02041EE4(2,5,amount);
        func_0204B454((struct Actor *)*(struct Obj **)(p+0x54),(struct PtS *)&pair,0);
        pair.y+=(short)amount;
        func_0204B404(*(struct Obj **)(p+0x54),&pair,0);
        p[0x44]=0;
        return;
    }
    p[0x44]--;
}

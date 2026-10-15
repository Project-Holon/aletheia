/*
 * function: ZUKAN_SEARCH_SCREEN_Update
 * address: 0x021BC7A0
 * packet: pkt_ov211_021BC7A0
 * region: ov211
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   sound 0x020061E4 thumb
 *   setup 0x02041EE4 arm
 *   adjust 0x02041FB0 arm
 *   tick 0x021BC890 thumb ov211
 *   transition 0x0202208C thumb
 *   idle 0x020221A4 thumb
 */
typedef unsigned char u8;
typedef unsigned int u32;
struct Owner { u32 pad[2]; u32 state; };
struct Object { struct Owner *owner; u8 pad[6]; u8 timer,state; };
extern void sound(int);
extern void setup(u32,u32,u32);
extern void adjust(u32,u32,u32);
extern void tick(void);
extern void transition(void *,u32,u32,u32,u32,u32,u32);
extern u32 idle(void);
int ZUKAN_SEARCH_SCREEN_Update(struct Object *p)
{
    switch(p->state) {
    case 0:
        if(p->timer == 26) {
            sound(1597);
            p->timer=0;
            p->state++;
        } else {
            setup(3,5,8); setup(1,5,8); setup(2,5,8); setup(5,5,8);
            p->timer++;
        }
        break;
    case 1:
        if(p->timer == 32) {
            sound(1598);
            adjust(3,9,128); adjust(3,12,120); adjust(7,9,128); adjust(7,12,96);
            p->timer=0;
            p->state++;
        } else { p->timer++; }
        break;
    case 2:
        tick();
        if(p->timer == 4) {
            transition(0,0,0,0,6,4,126);
            p->timer=0;
            p->state++;
        } else { p->timer++; }
        break;
    case 3:
        tick();
        if(idle() == 1) {
            p->owner->state=2;
            return 1;
        }
        break;
    }
    return 5;
}

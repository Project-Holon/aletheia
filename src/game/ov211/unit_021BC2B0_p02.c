/*
 * file:     unit_021BC2B0_p02.c
 * unit:     yes
 * function: func_021BC5B0, func_021BC670, func_021BC6CC, func_021BC6F8, func_021BC70C, func_021BC720, func_021BC7A0
 * address:  0x021BC5B0
 * region:   ov211
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02012EBC 0x02012EBC thumb
 *   func_0200725C 0x0200725C thumb
 *   func_020073D8 0x020073D8 thumb
 *   func_0200E8D8 0x0200E8D8 thumb
 *   func_0200E8CC 0x0200E8CC thumb
 *   func_0200E8D0 0x0200E8D0 thumb
 *   func_02040B1C 0x02040B1C arm
 *   func_02040E78 0x02040E78 arm
 *   func_020862F0 0x020862F0 arm
 *   func_0207F308 0x0207F308 arm
 *   func_0207F394 0x0207F394 arm
 *   func_0207F428 0x0207F428 arm
 *   func_0207F5B0 0x0207F5B0 arm
 *   func_0207F5C8 0x0207F5C8 arm
 *   func_0207F65C 0x0207F65C arm
 *   func_020072A4 0x020072A4 thumb
 *   func_02043534 0x02043534 arm
 *   func_020435F4 0x020435F4 arm
 *   func_0204363C 0x0204363C arm
 *   func_021BC2B0 0x021BC2B0 thumb ov211
 *   func_021BC318 0x021BC318 thumb ov211
 *   func_021BC474 0x021BC474 thumb ov211
 *   func_0203D34C 0x0203D34C arm
 *   func_02043598 0x02043598 arm
 *   func_021BC2F4 0x021BC2F4 thumb ov211
 *   func_021C93A8 0x021C93A8 thumb ov212
 *   func_021BC30C 0x021BC30C thumb ov211
 *   func_021BC43C 0x021BC43C thumb ov211
 *   func_020221A4 0x020221A4 thumb
 *   func_02035C38   0x02035C38  arm
 *   func_020355D8   0x020355D8  arm
 *   func_020362DC   0x020362DC  arm
 *   func_021C93C4   0x021C93C4  thumb ov212
 *   sound 0x020061E4 thumb
 *   setup 0x02041EE4 arm
 *   adjust 0x02041FB0 arm
 *   tick 0x021BC890 thumb ov211
 *   transition 0x0202208C thumb
 *   idle 0x020221A4 thumb
 */
#include "../../matched/include/Obj10925.h"
#include "../../matched/include/Obj06700.h"

struct Big;
struct Ctrl;
struct Sub020073D8Ctrl;
struct Sub020072A4Ctrl;
struct Object;
typedef unsigned u32_021BC5B0;

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int   u32_021BC720;

typedef unsigned int u32_021BC7A0;

struct Owner { u32_021BC7A0 pad[2]; u32_021BC7A0 state; };

struct Object { struct Owner *owner; u8 pad[6]; u8 timer,state; };

extern void *func_02012EBC(struct Big *);
extern u32_021BC5B0 func_0200725C(struct Ctrl *,u32_021BC5B0,u32_021BC5B0);
extern void *func_020073D8(struct Sub020073D8Ctrl *,u32_021BC5B0,u32_021BC5B0);
extern u32_021BC5B0 func_0200E8D8(const void *obj);
extern void *func_0200E8CC(void *),*func_0200E8D0(void *);
extern void func_02040B1C(int index, const void *src, u32_021BC5B0 size, u32_021BC5B0 tile);
extern void func_02040E78(u32_021BC5B0,void *,u32_021BC5B0,u32_021BC5B0);
extern void func_020862F0(void *,unsigned long);
extern void func_0207F308(void),func_0207F394(const void *,u32_021BC5B0,u32_021BC5B0),func_0207F428(void);
extern void func_0207F5B0(void),func_0207F5C8(const void *,u32_021BC5B0,u32_021BC5B0),func_0207F65C(void);
extern void func_020072A4(struct Sub020072A4Ctrl *,u32_021BC5B0);
extern void func_02043534(unsigned),func_020435F4(unsigned),func_0204363C(unsigned);
extern void func_021BC2B0(void);
extern void func_021BC318(void);
extern void func_021BC474(struct Object *p);
extern void func_0203D34C(unsigned,unsigned),func_02043598(unsigned,unsigned);
extern void func_021BC2F4(unsigned char *p);
extern void func_021C93A8(unsigned);
extern void func_021BC30C(unsigned char *),func_021BC43C(void),func_02043534(unsigned),func_020435F4(unsigned);
extern unsigned func_020221A4(void);
extern int  func_02035C38(void);
extern void func_020355D8(u8 v);
extern u32_021BC720 func_020362DC(void);
extern void func_021C93C4(u32_021BC720 heap);
extern void sound(int);
extern void setup(u32_021BC7A0,u32_021BC7A0,u32_021BC7A0);
extern void adjust(u32_021BC7A0,u32_021BC7A0,u32_021BC7A0);
extern void tick(void);
extern void transition(void *,u32_021BC7A0,u32_021BC7A0,u32_021BC7A0,u32_021BC7A0,u32_021BC7A0,u32_021BC7A0);
extern u32_021BC7A0 idle(void);
void func_021BC5B0(char *p);
int func_021BC670(char *p);
int func_021BC6CC(unsigned char *p);
int func_021BC6F8(void);
int func_021BC70C(void);
int func_021BC720(char *p);
int func_021BC7A0(struct Object *p);

/*
 * prototype: 0725C third parameter widened from matched u8: original
 * supplies full pooled 0x807E, without truncation. 073D8 legacy void
 * leaves a pointer in r0 consumed immediately by E8D8; preserve it.
 */
void func_021BC5B0(char *p)
{
    void *save,*block,*tiles,*palette;
    save=func_02012EBC(*(struct Big **)*(char * *)&((struct Obj10925 *)p)->f0);
    if(func_0200725C(save,7,0x807e)==1){
        block=func_020073D8(save,7,0);
        if(block!=0&&func_0200E8D8(block)==1){
            tiles=func_0200E8CC(block);
            palette=func_0200E8D0(block);
            func_02040B1C(1,tiles,0x6000,0);
            func_02040E78(1,palette,0x200,0);
            func_02040E78(5,palette,0x200,0);
            func_020862F0(palette,0x200);
            func_0207F308();
            func_0207F394(palette,0x4000,0x200);
            func_0207F394(palette,0x6000,0x200);
            func_0207F428();
            func_0207F5B0();
            func_0207F5C8(palette,0x4000,0x200);
            func_0207F5C8(palette,0x6000,0x200);
            func_0207F65C();
        }
    }
    func_020072A4(save,7);
}

/*
 * volatile: hardware halfword stores to 04000050 at 021BC684 and
 * 04001050 at 021BC688; original clears display blend controls.
 */
int func_021BC670(char *p)
{
    func_02043534(0);func_020435F4(0);
    *(volatile unsigned short *)0x04000050=0;
    *(volatile unsigned short *)0x04001050=0;
    func_0204363C(0);func_021BC2B0();func_021BC318();
    func_021BC474((struct Object *)p);func_021BC5B0(p);
    func_0203D34C(1,126);func_02043598(16,1);
    func_021BC2F4((unsigned char *)p);func_021C93A8(126);
    return 2;
}

int func_021BC6CC(unsigned char *p){func_021BC30C(p);func_021BC43C();*(volatile unsigned short *)0x04000050=0;*(volatile unsigned short *)0x04001050=0;func_02043534(0);func_020435F4(0);return 6;}

int func_021BC6F8(void){if(func_020221A4()==1)return 4;return 2;}

int func_021BC70C(void){if(func_020221A4()==1)return 1;return 3;}


int func_021BC720(char *p)
{
    u32_021BC720 v = 1;

    if (((struct Obj06700 *)p)->f8 == 0x12C)
        return 5;
    ((struct Obj06700 *)p)->f8 = ((struct Obj06700 *)p)->f8 + 1;
    if (func_02035C38() == 1) {
        func_020355D8(1);
        return 5;
    }
    if (func_020362DC() & 1) {
        func_020355D8(0);
        return 5;
    }
    if (func_020362DC() & 2) {
        func_020355D8(0);
        v = 0;
        *(u32_021BC720 *)(((struct Obj06700 *)p)->f0 + 8) = v;
        func_021C93C4(0x7E);
        return 3;
    }
    if (func_020362DC() & 0x400) {
        func_020355D8(0);
        *(u32_021BC720 *)(((struct Obj06700 *)p)->f0 + 8) = v;
        func_021C93C4(0x7E);
        return 3;
    }
    return 4;
}

int func_021BC7A0(struct Object *p)
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

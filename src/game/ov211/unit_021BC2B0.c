/*
 * file:     unit_021BC2B0.c
 * unit:     yes
 * function: func_021BC2B0, func_021BC2D8, func_021BC2F4, func_021BC30C, func_021BC318, func_021BC43C, func_021BC474, func_021BC5B0, func_021BC670, func_021BC6CC, func_021BC6F8, func_021BC70C, func_021BC720, func_021BC7A0
 * address:  0x021BC2B0
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
 *   func_0204335C 0x0204335C arm
 *   func_020433E0 0x020433E0 arm
 *   d_021BC990    0x021BC990 data ov211
 *   func_020419E4 0x020419E4 arm
 *   SDK_AUTOLOAD_MAIN_TWL_START 0x02FE0000 data
 *   func_020056A0 0x020056A0 thumb
 *   func_02030EAC 0x02030EAC arm
 *   func_0203F8F4 0x0203F8F4 arm
 *   func_0203FC28 0x0203FC28 arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_020414EC 0x020414EC arm
 *   func_02040B94 0x02040B94 arm
 *   func_02041570 0x02041570 arm
 *   func_020434DC 0x020434DC arm
 *   func_02043598 0x02043598 arm
 *   d_021BC8C8 0x021BC8C8 data a4
 *   d_021BC910 0x021BC910 data a4
 *   d_021BC930 0x021BC930 data a4
 *   d_021BC950 0x021BC950 data a4
 *   d_021BC970 0x021BC970 data a4
 *   d_021BC8F0 0x021BC8F0 data a4
 *   func_020403F4 0x020403F4 arm
 *   func_0203F9B4 0x0203F9B4 arm
 *   open 0x020490F4 arm
 *   kind 0x02008550 thumb
 *   palette 0x02049B68 arm
 *   screen 0x02049658 arm
 *   tiles 0x020498F4 arm
 *   close 0x02049238 arm
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
 *   func_0203D34C 0x0203D34C arm
 *   func_021C93A8 0x021C93A8 thumb ov212
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
#include "../../matched/include/Obj25638.h"
#include "../../matched/include/Obj06700.h"

struct DispVram;
struct Node;
struct BgTemplate;
struct DispConfig;
struct Big;
struct Ctrl;
struct Sub020073D8Ctrl;
struct Sub020072A4Ctrl;
struct Object_021BC5B0;
typedef struct
{
    int v[12];
} S021BC2B0;

typedef unsigned int   u32;

typedef unsigned short u16;

typedef struct Config16 { u32 words[4]; } Config16;

typedef struct Config32 { u32 words[8]; } Config32;

typedef unsigned char  u8;

struct Object_021BC2B0 { struct Owner_021BC2B0 *owner; };

struct Owner_021BC2B0 { u32 pad; void *context; };

typedef unsigned u32_021BC5B0;

typedef unsigned int   u32_021BC720;

typedef unsigned int u32_021BC7A0;

struct Owner_021BC5B0 { u32_021BC7A0 pad[2]; u32_021BC7A0 state; };

struct Object_021BC5B0 { struct Owner_021BC5B0 *owner; u8 pad[6]; u8 timer,state; };

extern void func_0204335C(u32 keep);
extern void func_020433E0(const struct DispVram *c);
extern void func_020419E4(void);
extern void *func_020056A0(unsigned,unsigned,unsigned);
extern void func_02030EAC(struct Node *);
extern void func_0203F8F4(u16);
extern void func_0203FC28(struct DispConfig *cfg);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_020414EC(u32);
extern void func_02040B94(u8 layer, u32 size, u32 offset, u32 heapId);
extern void func_02041570(int, u16);
extern void func_020434DC(u32, u32);
extern void func_02043598(u32, u32);
extern void func_020434DC(unsigned,unsigned),func_02043598(unsigned,unsigned),func_020403F4(unsigned),func_0203F9B4(void);
extern void *open(u32,u16);
extern int kind(void *);
extern void palette(void *,u32,u32,u32,u32,u16);
extern void screen(void *,u32,u32,u32,u32,u32,u16);
extern void tiles(void *,u32,u32,u32,u32,u32,u16);
extern void close(void *);
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
void func_021BC2B0(void);
void func_021BC2D8(void);
void func_021BC2F4(unsigned char *p);
void func_021BC30C(unsigned char *p);
void func_021BC318(void);
void func_021BC43C(void);
void func_021BC474(struct Object_021BC2B0 *p);
void func_021BC5B0(char *p);
int func_021BC670(char *p);
int func_021BC6CC(unsigned char *p);
int func_021BC6F8(void);
int func_021BC70C(void);
int func_021BC720(char *p);
int func_021BC7A0(struct Object_021BC5B0 *p);
extern S021BC2B0 d_021BC990;
extern unsigned char SDK_AUTOLOAD_MAIN_TWL_START[];
extern const Config16 d_021BC8C8;
extern const Config32 d_021BC910, d_021BC930, d_021BC950, d_021BC970, d_021BC8F0;



void func_021BC2B0(void)
{
    S021BC2B0 buf = d_021BC990;
    func_0204335C(0);
    func_020433E0((const struct DispVram *)(&buf));
}


void func_021BC2D8(void){func_020419E4();*(unsigned *)((unsigned)SDK_AUTOLOAD_MAIN_TWL_START+0x3FF8)|=1;}


void func_021BC2F4(unsigned char *p){((struct Obj10925 *)p)->f4=func_020056A0((unsigned)func_021BC2D8,(unsigned)p,0);}


void func_021BC30C(unsigned char *p){func_02030EAC(*(struct Node * *)&((struct Obj25638 *)p)->f4);}


void func_021BC318(void)
{
    Config16 a;
    Config32 b, c, d, e, f;
    func_0203F8F4(0x7e);
    a = d_021BC8C8;
    func_0203FC28((struct DispConfig *)(&a));
    b = d_021BC910;
    func_0203FCA0(3, (const struct BgTemplate *)(&b), 2);
    func_020414EC(3);
    c = d_021BC930;
    func_0203FCA0(1, (const struct BgTemplate *)(&c), 0);
    func_02040B94(1, 0x20, 0x7fe0, 0x807e);
    func_02041570(1, 0x3ff);
    d = d_021BC950;
    func_0203FCA0(2, (const struct BgTemplate *)(&d), 0);
    func_020414EC(2);
    e = d_021BC970;
    func_0203FCA0(7, (const struct BgTemplate *)(&e), 2);
    func_020414EC(7);
    f = d_021BC8F0;
    func_0203FCA0(5, (const struct BgTemplate *)(&f), 0);
    func_020414EC(5);
    func_020434DC(14, 1);
    func_02043598(10, 1);
}


void func_021BC43C(void){func_020434DC(14,0);func_02043598(10,0);func_020403F4(5);func_020403F4(7);func_020403F4(2);func_020403F4(1);func_020403F4(3);func_0203F9B4();}


void func_021BC474(struct Object_021BC2B0 *p)
{
    void *arc;
    arc=open(159,0x807E);
    if(kind(p->owner->context)==0) {
        palette(arc,102,2,0x4000,0,126);
        palette(arc,102,2,0x6000,0,126);
        palette(arc,102,6,0x4000,0,126);
        palette(arc,102,6,0x6000,0,126);
    } else {
        palette(arc,103,2,0x4000,0,126);
        palette(arc,103,2,0x6000,0,126);
        palette(arc,103,6,0x4000,0,126);
        palette(arc,103,6,0x6000,0,126);
    }
    screen(arc,105,2,0,0,0,126);
    screen(arc,105,5,0,0,0,126);
    tiles(arc,108,3,0,0,0,126);
    tiles(arc,111,1,0,0,0,126);
    tiles(arc,110,2,0,0,0,126);
    tiles(arc,112,7,0,0,0,126);
    tiles(arc,109,5,0,0,0,126);
    close(arc);
}


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
    func_021BC474((struct Object_021BC2B0 *)((struct Object_021BC5B0 *)p));func_021BC5B0(p);
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


int func_021BC7A0(struct Object_021BC5B0 *p)
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

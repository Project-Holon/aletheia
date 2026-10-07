/*
 * file:     unit_021BC2B0_p01.c
 * unit:     yes
 * function: func_021BC2B0, func_021BC2D8, func_021BC2F4, func_021BC30C, func_021BC318, func_021BC43C, func_021BC474
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
 */
#include "../../matched/include/Obj10925.h"
#include "../../matched/include/Obj25638.h"

struct DispVram;
struct Node;
struct BgTemplate;
struct DispConfig;
typedef struct
{
    int v[12];
} S021BC2B0;

typedef unsigned int   u32;

typedef unsigned short u16;

typedef struct Config16 { u32 words[4]; } Config16;

typedef struct Config32 { u32 words[8]; } Config32;

typedef unsigned char  u8;

struct Object { struct Owner *owner; };

struct Owner { u32 pad; void *context; };

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
void func_021BC2B0(void);
void func_021BC2D8(void);
void func_021BC2F4(unsigned char *p);
void func_021BC30C(unsigned char *p);
void func_021BC318(void);
void func_021BC43C(void);
void func_021BC474(struct Object *p);
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

void func_021BC474(struct Object *p)
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

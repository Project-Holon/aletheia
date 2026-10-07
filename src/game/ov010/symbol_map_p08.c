/*
 * file:     symbol_map_p08.c
 * unit:     yes
 * function: func_021672D0, func_021672E4, func_021672F8, func_0216730C
 * address:  0x021672D0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02012EC0  0x02012EC0  thumb
 *   func_0200C0E8  0x0200C0E8  thumb
 *   func_0200C224  0x0200C224  thumb
 *   func_0200C1DC  0x0200C1DC  thumb
 *   func_0200C1C4  0x0200C1C4  thumb
 */
#include "../../matched/include/Obj17729.h"
#include "../../matched/include/Obj17730.h"
#include "../../matched/include/Obj17731.h"

struct Big;
struct Blk34;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern void *func_02012EC0(struct Big *p);
extern void *func_0200C0E8(void *sys);
extern u8 func_0200C224(struct Blk34 *p);
extern u32 func_0200C1DC(struct Blk34 *p);
extern u32 func_0200C1C4(struct Blk34 *p);
int func_021672D0(int a0);
int func_021672E4(int a0);
int func_021672F8(int a0);
int func_0216730C(unsigned int n);


int func_021672D0(int a0)
{
    void *big;
    void *sys;


a0 = ((struct Obj17729 *)a0)->f8;
    big = func_02012EC0((struct Big *)a0);
loc_021672D8:
    sys = func_0200C0E8(big);
loc_021672DC:
    a0 = func_0200C224(sys);
loc_021672E0:
    return a0;}


int func_021672E4(int a0)
{
    void *big;
    void *sys;


a0 = ((struct Obj17730 *)a0)->f8;
    big = func_02012EC0((struct Big *)a0);
loc_021672EC:
    sys = func_0200C0E8(big);
loc_021672F0:
    a0 = func_0200C1DC(sys);
loc_021672F4:
    return a0;}


int func_021672F8(int a0)
{
    void *big;
    void *sys;


a0 = ((struct Obj17731 *)a0)->f8;
    big = func_02012EC0((struct Big *)a0);
loc_02167300:
    sys = func_0200C0E8(big);
loc_02167304:
    a0 = func_0200C1C4(sys);
loc_02167308:
    return a0;}

int func_0216730C(unsigned int n)
{
    switch (n) {
    case 0:
        return 0x174;
    case 1:
        return 0x175;
    case 2:
        return 0x176;
    case 3:
        return 0x177;
    case 4:
        return 0x178;
    case 5:
        return 0x179;
    }
    return 0;
}

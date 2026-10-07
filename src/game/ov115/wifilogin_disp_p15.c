/*
 * file:     wifilogin_disp_p15.c
 * unit:     yes
 * function: func_021D61FC, func_021D625C, func_021D6274
 * address:  0x021D61FC
 * region:   ov115
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0203CF04 0x0203CF04 arm
 *   func_0203D0D0 0x0203D0D0 arm
 *   func_0203C968 0x0203C968 arm
 *   func_0203CA04 0x0203CA04 arm
 *   func_0203CDBC 0x0203CDBC arm
 *   func_0203CEAC 0x0203CEAC arm
 *   func_021D6134 0x021D6134 thumb ov115
 *   func_021D6328 0x021D6328 thumb ov115
 *   func_021D5C24 0x021D5C24 thumb ov115
 *   func_021D6294 0x021D6294 thumb ov115
 */
#include "../../matched/include/Obj22608.h"
#include "../../matched/include/Obj22609.h"

typedef unsigned int u32;

typedef unsigned char  u8;

extern u32 func_0200FB24(void);
extern void func_0200FBA0(void);
extern void func_0203CF04(void);
extern void func_0203D0D0(void);
extern void func_0203C968(void);
extern void func_0203CA04(void);
extern int func_0203CDBC(void);
extern int func_0203CEAC(int a0);
extern void func_021D6134(void *a0, int a1, int a2);
extern void func_021D6328(u8 *p);
extern void func_021D5C24(void *,int);
extern void func_021D6294(u8 *);
void func_021D61FC(void *p);
void func_021D625C(u8 *p);
void func_021D6274(u8 *p);

void func_021D61FC(void *p) {
    if (func_0200FB24()) {
        func_0203CF04(); func_0203D0D0(); func_0203C968(); func_0203CA04(); func_0200FBA0();
    }
    if (func_0203CDBC()) {
        func_021D6134(p,(int)((void (*)(void))func_021D6274),0x1bf);
        return;
    }
    if (func_0203CEAC((int)func_021D6328)) func_021D6134(p,(int)((void (*)(void))func_021D625C),0x1c7);
}

void func_021D625C(u8 *p) { if(((struct Obj22608 *)p)->f18)func_021D6134(p,(int)func_021D6274,0x1d8); }

void func_021D6274(u8 *p) { func_021D5C24(((struct Obj22609 *)p)->f8,27);func_021D6134(p,(int)func_021D6294,0x1e6); }

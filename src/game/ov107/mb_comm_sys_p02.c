/*
 * file:     mb_comm_sys_p02.c
 * unit:     yes
 * function: func_021EF080, func_021EF0D0
 * address:  0x021EF080
 * region:   ov107
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204B1CC 0x0204B1CC arm
 *   func_0204A5AC 0x0204A5AC arm
 *   func_020403F4 0x020403F4 arm
 *   func_020450C8 0x020450C8 arm
 *   func_0203F9B4 0x0203F9B4 arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_02040588 0x02040588 arm
 *   func_020414AC 0x020414AC arm
 *   func_020409B4 0x020409B4 arm
 */
#include "../../matched/include/Obj00979.h"

struct Bank;
struct Obj;
struct BgTemplate;
typedef unsigned int   u32;

typedef unsigned char u8;

typedef unsigned short u16;

extern void func_0204B3B4(struct Obj *p);
extern u32 func_0204B1CC(struct Bank *bank);
extern void func_0204A5AC(void);
extern void func_020403F4(unsigned);
extern void func_020450C8(void);
extern void func_0203F9B4(void);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_02040588(u32 which, unsigned char enable);
extern void func_020414AC(u32);
extern void func_020409B4(u32);
void func_021EF080(char *p);
void func_021EF0D0(u32 a,u32 b,u32 c);

/*
 * extent: two bytes of alignment padding follow the return.
 */
void func_021EF080(char *p) {
 func_0204B3B4(((struct Obj00979 *)p)->f7C);
 func_0204B1CC(((struct Obj00979 *)p)->f6C);
 func_0204A5AC();
 func_020403F4(0);func_020403F4(1);func_020403F4(2);func_020403F4(3);
 func_020403F4(7);func_020403F4(6);func_020403F4(5);func_020403F4(4);
 func_020450C8();func_0203F9B4();
}

void func_021EF0D0(u32 a,u32 b,u32 c) { func_0203FCA0(b,(const struct BgTemplate *)a,c);func_02040588(b,1);func_020414AC(b);func_020409B4(b); }

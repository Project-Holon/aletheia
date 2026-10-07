/*
 * file:     egg_demo_view_p05.c
 * unit:     yes
 * function: func_021F6EEC, func_021F6EF8, func_021F6F18
 * address:  0x021F6EEC
 * region:   ov215
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02046BE0 0x02046BE0 arm
 *   func_02047CFC 0x02047CFC arm
 *   func_02047E54 0x02047E54 arm
 */
#include "../../matched/include/Obj25763.h"
#include "../../matched/include/Obj00317.h"
#include "../../matched/include/Obj04636.h"

struct Util;
struct Rec;
typedef unsigned short u16;

extern void func_02046BE0(unsigned,unsigned);
extern struct Util *func_02047CFC(u16,u16,u16);
extern void func_02047E54(struct Rec *);
void func_021F6EEC(char *p);
void func_021F6EF8(char *p);
void func_021F6F18(char *p);

/*
 * leaf: sole overlay blocker of 021F67E0; store and return, pool ends 021F6EF8.
 */
void func_021F6EEC(char *p){((struct Obj25763 *)p)->f4814=1;}

void func_021F6EF8(char *p){unsigned z=0;func_02046BE0(1,z);*(struct Util * *)&((struct Obj00317 *)p)->f48=func_02047CFC(4,1,((struct Obj00317 *)p)->f0);((struct Obj00317 *)p)->f50=z;}

void func_021F6F18(char *p){func_02047E54(*(struct Rec * *)&((struct Obj04636 *)p)->f48);}

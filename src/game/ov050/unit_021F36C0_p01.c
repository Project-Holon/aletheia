/*
 * file:     unit_021F36C0_p01.c
 * unit:     yes
 * function: func_021F36C0, func_021F36EC
 * address:  0x021F36C0
 * region:   ov050
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02188C84 0x02188C84 thumb ov021
 *   func_02189764 0x02189764 thumb ov021
 *   func_021F383C 0x021F383C thumb ov050
 *   func_021F3890 0x021F3890 thumb ov050
 *   func_021897BC 0x021897BC thumb ov021
 *   func_021F3894 0x021F3894 thumb ov050
 *   func_021897A0 0x021897A0 thumb ov021
 */
#include "../../matched/include/Obj20550.h"

extern unsigned short func_02188C84(unsigned char *);
extern void *func_02189764(unsigned char *, int, int, int);
extern void func_021F383C(int, int);
extern void func_021F3890(void *, unsigned char *);
extern int *func_021897BC(char *, int);
extern void func_021F3894(int *, char *);
extern void func_021897A0(unsigned char *, int);
void func_021F36C0(unsigned char *p);
void func_021F36EC(char *p);

void func_021F36C0(unsigned char *p) { unsigned short h; void *q; h=func_02188C84(p); q=func_02189764(p,1,h,2); ((struct Obj20550 *)q)->f0=h; func_021F383C((int)q,(int)p); func_021F3890(q,p); }

void func_021F36EC(char *p) { func_021F3894(func_021897BC(p,1),p); func_021897A0((unsigned char *)p,1); }

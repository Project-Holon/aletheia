/*
 * file:     unit_021BF050_p18.c
 * unit:     yes
 * function: func_021C16EC, func_021C1724
 * address:  0x021C16EC
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021BA928 0x021BA928 thumb ov099
 *   func_021BA8EC 0x021BA8EC thumb ov099
 *   func_020399A8 0x020399A8 arm
 *   func_02039CB4 0x02039CB4 arm
 *   func_0203D7B0 0x0203D7B0 arm
 *   func_0203D7BC 0x0203D7BC arm
 *   func_021BA828 0x021BA828 thumb ov099
 */
#include "../../matched/include/Obj00008.h"

struct Entry;
struct Link;
typedef unsigned char u8;

typedef unsigned int u32;

extern int func_021BA928(void *);
extern void func_021BA8EC(char *);
extern struct Entry *func_020399A8(void);
extern unsigned int func_02039CB4(struct Link *, unsigned int, unsigned int);
extern void func_0203D7B0(u8 a0);
extern void func_0203D7BC(u8 a0);
extern void func_021BA828(char *);
int func_021C16EC(char *p,int ret);
int func_021C1724(char *p, int ret);

/*
 * Extent remainder: two-byte alignment padding.
 */
int func_021C16EC(char *p,int ret){if(!func_021BA928(p))return ret;if(--((struct Obj00008 *)p)->f1E0==0){((struct Obj00008 *)p)->f1D0=0;((struct Obj00008 *)p)->f1CC=26;func_021BA8EC(p);}return ret;}

int func_021C1724(char *p, int ret)
{
    if (func_02039CB4((struct Link *)func_020399A8(), 16, 10) == 0) return ret;
    func_0203D7B0(0);
    func_0203D7BC(1);
    if (func_021BA928(p) != 0) {
        func_021BA828(p);
        ((struct Obj00008 *)p)->f1CC = 54;
    }
    return ret;
}

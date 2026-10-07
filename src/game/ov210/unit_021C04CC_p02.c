/*
 * file:     unit_021C04CC_p02.c
 * unit:     yes
 * function: func_021C0608, func_021C0660
 * address:  0x021C0608
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021BEC60 0x021BEC60 thumb ov210
 *   func_021BCEF0 0x021BCEF0 thumb ov210
 *   func_021BF7B0 0x021BF7B0 thumb ov210
 *   func_021BFBF8 0x021BFBF8 thumb ov210
 *   func_021BF728 0x021BF728 thumb ov210
 */
#include "../../matched/include/Obj04620.h"

typedef unsigned int   u32;

typedef unsigned char  u8;

extern void func_021BEC60(int p, int *a, u32 b);
extern u32 func_021BCEF0(u32 a, u32 b);
extern void func_021BF7B0(char *,int,int,int);
extern void func_021BFBF8(int p, int v);
extern void func_021BF728(u8 *p, int a);
void func_021C0608(char *p,int index,void *data,int value,int flag);
void func_021C065C(void);
void func_021C0660(int p, int v);

/*
 * trailing: unit aligns the bx-lr follower at 021C065C after zero pad
 * 021C065A; two additional zero alignment bytes at 021C065E follow the unit.
 */
void func_021C0608(char *p,int index,void *data,int value,int flag)
{
    func_021BEC60((int)p,data,(*(unsigned *)(p+484+index*4)));
    if(index==func_021BCEF0((u32)p,(unsigned char)(*(char **)(*(char * *)&((struct Obj04620 *)p)->f0+8))[3]))func_021BF7B0(p,0,value,flag);
    if(index==func_021BCEF0((u32)p,(unsigned char)(*(char **)(*(char * *)&((struct Obj04620 *)p)->f0+8))[4]))func_021BF7B0(p,1,value,flag);
}

void func_021C065C(void){}


/*
 * Addresses are Black-image addresses.
 */
void func_021C0660(int p, int v)
{
    func_021BFBF8(p, (signed char)(-v));
    func_021BF728((u8 *)p, 1);
}

/*
 * file:     chihou_zukan_award_p03.c
 * unit:     yes
 * function: func_021B9DAC, func_021B9DD4
 * address:  0x021B9DAC
 * region:   ov221
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02040804 0x02040804 arm
 *   func_020434DC 0x020434DC arm
 *   func_0207DC44 0x0207DC44 arm
 *   func_0207DD24 0x0207DD24 arm
 *   func_02046A94 0x02046A94 arm
 *   func_02046BE0 0x02046BE0 arm
 *   d_021BA200 0x021BA200 data a2
 */
#include "../../matched/include/Obj26069.h"
#include "../../matched/include/Obj26070.h"

#define REG3D (*(volatile unsigned short *)0x04000060)
typedef enum Bool { BOOL_FALSE=0,BOOL_TRUE=1 } Bool;

typedef enum { SHADING1 = 1 } GXShading;

typedef int BOOL;

typedef unsigned short u16;

typedef unsigned int   u32;

extern unsigned func_02040804(unsigned);
extern void func_020434DC(unsigned, unsigned);
extern void func_0207DC44(BOOL,int,int,int);
extern void func_0207DD24(unsigned short,int,int,int,BOOL);
extern void func_02046A94(u32 idx, const u16 *src);
extern void func_02046BE0(unsigned,unsigned);
Bool func_021B9DAC(char *p);
void func_021B9DD4(void);
extern const unsigned short d_021BA200[][4];

Bool func_021B9DAC(char *p){int flag;Bool result;if(((struct Obj26070 *)(*(char * *)&((struct Obj26069 *)p)->f4))->f4)return BOOL_TRUE;flag=1;if(func_02040804(1))flag=0;result=BOOL_FALSE;if(flag)result=BOOL_TRUE;return result;}

static inline void Shading(GXShading mode) { REG3D=(unsigned short)((REG3D & ~0x3002)|(mode<<1)); }

static inline void AntiAlias(BOOL enable) { if(enable) REG3D=(unsigned short)((REG3D & ~0x3000)|0x10); else REG3D &= (unsigned short)~0x3010; }

static inline void AlphaTest(BOOL enable,int ref) { if(enable) { REG3D=(unsigned short)((REG3D & ~0x3000)|4); *(volatile unsigned short *)0x04000340=ref; } else REG3D &= (unsigned short)~0x3004; }

static inline void AlphaBlend(BOOL enable) { if(enable) REG3D=(unsigned short)((REG3D & ~0x3000)|8); else REG3D &= (unsigned short)~0x3008; }

static inline void EdgeMarking(BOOL enable) { if(enable) REG3D=(unsigned short)((REG3D & ~0x3000)|0x20); else REG3D &= (unsigned short)~0x3020; }

void func_021B9DD4(void)
{
    unsigned i;
    func_020434DC(1,1);
    *(volatile unsigned short *)0x04000008 = *(volatile unsigned short *)0x04000008 & ~3;
    Shading(SHADING1);
    AntiAlias(0);
    AlphaTest(0,0);
    AlphaBlend(1);
    EdgeMarking(0);
    func_0207DC44(0,0,0,0);
    func_0207DD24(0,0,0x7FFF,63,0);
    *(volatile unsigned *)0x04000580=0xBFFF0000;
    for(i=0;i<4;i++) func_02046A94((unsigned char)i,d_021BA200[i]);
    func_02046BE0(0,0);
}

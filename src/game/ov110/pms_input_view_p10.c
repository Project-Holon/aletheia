/*
 * file:     pms_input_view_p10.c
 * unit:     yes
 * function: func_021BAF7C, func_021BAFAC, func_021BAFDC
 * address:  0x021BAF7C
 * region:   ov110
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
#include "../../matched/include/Obj10274.h"
#include "../../matched/include/Obj08000.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

void func_021BAF7C(unsigned p,int v);
int func_021BAFAC(u32 p);
u8 func_021BAFDC(u8 *p);

void func_021BAF7C(unsigned p,int v) { int n; *(u16 *)(p+((struct Obj10274 *)p)->fAF0*2+0xad4)=v; n=((struct Obj10274 *)p)->fAF0+1; if(n>12) n=12; else if(n<0) n=0; ((struct Obj10274 *)p)->fAF0=n; }

int func_021BAFAC(u32 p) { if (((struct Obj08000 *)p)->fAF0==0) return 0; if (((struct Obj08000 *)p)->fAEC==255) --((struct Obj08000 *)p)->fAF0; *(u16 *)(p+((struct Obj08000 *)p)->fAF0*2+0xad4)=255; return 1; }


/*
 * Byte accessor: p[0xaf0].
 */
u8 func_021BAFDC(u8 *p)
{
    return p[0xaf0];
}

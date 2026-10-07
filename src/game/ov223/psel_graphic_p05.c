/*
 * file:     psel_graphic_p05.c
 * unit:     yes
 * function: func_021BC5AC, func_021BC5E4
 * address:  0x021BC5AC
 * region:   ov223
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021BC9B0 0x021BC9B0 data a4
 *   func_020403F4 0x020403F4 arm
 *   func_020450C8 0x020450C8 arm
 *   func_0203F9B4 0x0203F9B4 arm
 *   func_02082BCC 0x02082BCC arm
 */
typedef unsigned int   u32;

extern void func_020403F4(u32 i);
extern void func_020450C8(void);
extern void func_0203F9B4(void);
extern void func_02082BCC(void *,int,int);
void func_021BC5AC(void *p);
void func_021BC5E4(void *a0);
extern unsigned char d_021BC9B0[];

void func_021BC5AC(void *p){unsigned i;for(i=0;i<7;i++)func_020403F4((unsigned char)(*(unsigned *)(d_021BC9B0+i*44)));func_020450C8();func_0203F9B4();func_02082BCC(p,0,4);}

void func_021BC5E4(void *a0){}

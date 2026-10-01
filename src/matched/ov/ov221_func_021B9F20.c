/*
 * function: func_021B9F20
 * address: 0x021B9F20
 * packet: pkt_ov221_021B9F20
 * region: ov221
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: 021B9F46..021B9F60 display registers
 * symbols:
 *   func_02030EAC 0x02030EAC arm
 *   func_021BA130 0x021BA130 thumb ov221
 *   func_021BA094 0x021BA094 thumb ov221
 *   func_021BA010 0x021BA010 thumb ov221
 *   func_0201DD68 0x0201DD68 thumb
 *   func_02082BCC 0x02082BCC arm
 *   func_020307B0 0x020307B0 arm
 */

typedef unsigned short u16;
typedef unsigned int u32;
extern void func_02030EAC(void*);
extern int func_021BA130(int*);
extern void func_021BA094(char*);
extern void func_021BA010(void*);
extern void func_0201DD68(void);
extern void func_02082BCC(void*,int,u32);
extern void func_020307B0(void*);
/* volatile accesses: display cleanup, original 021B9F46..021B9F60. */
void func_021B9F20(char*p)
{
 func_02030EAC(*(void**)(p+12));
 func_021BA130((int*)(p+8));
 func_021BA094(p+4);
 func_021BA010(p);
 func_0201DD68();
 *(volatile u16*)0x04000050=0;
 *(volatile u16*)0x04001050=0;
 *(volatile u32*)0x04000000 &= ~0xe000u;
 *(volatile u32*)0x04001000 &= ~0xe000u;
 func_02082BCC(p,0,16);
 func_020307B0(p);
}

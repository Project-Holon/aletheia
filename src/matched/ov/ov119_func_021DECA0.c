/*
 * function: func_021DECA0
 * address: 0x021DECA0
 * packet: pkt_ov119_021DECA0
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021E4000 0x021E4000 thumb ov119
 *   func_021DF7D0 0x021DF7D0 thumb ov119
 *   func_021DF8E0 0x021DF8E0 thumb ov119
 *   func_021E64B8 0x021E64B8 thumb ov119
 *   func_021DD588 0x021DD588 thumb ov119
 *   func_021E4570 0x021E4570 thumb ov119
 *   func_021DD9DC 0x021DD9DC thumb ov119
 *   func_021E4888 0x021E4888 thumb ov119
 *   func_021DD528 0x021DD528 thumb ov119
 *   func_02041570 0x02041570 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   func_021B6558 0x021B6558 thumb ov067
 *   TOUCHBAR_SetButtonEnabled 0x021B6548 thumb ov067
 *   func_021E24E8 0x021E24E8 thumb ov119
 *   func_021E6B90 0x021E6B90 thumb ov119
 *   WIPE_SYS_Start 0x0202208C thumb
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021DEC4C 0x021DEC4C thumb ov119
 */
#include "../include/Obj00001.h"
typedef unsigned short u16;
typedef unsigned int   u32;
extern void func_021E4000(char *p);
extern void func_021DF7D0(void *);
extern void func_021DF8E0(void *);
extern void func_021E64B8(void *);
extern void func_021DD588(char *p);
extern void func_021E4570(char *p);
extern void func_021DD9DC(unsigned char *);
extern void func_021E4888(char *p);
extern void func_021DD528(char *,int);
extern void func_02041570(int channel, u16 val);
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *p, unsigned int v);
extern void func_021B6558(unsigned char *p, unsigned int id, unsigned int v);
extern int TOUCHBAR_SetButtonEnabled(unsigned char *p, unsigned int id, int v);
extern void func_021E24E8(char *p, int a1);
extern void func_021E6B90(char *p);
extern void WIPE_SYS_Start(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
extern void func_021D8E84(void *,int);
extern void func_021DEC4C(void *);
void func_021DECA0(char *p) {
 func_021E4000(p);func_021DF7D0(p);func_021DF8E0(p);func_021E64B8(p);func_021DD588(p);func_021E4570(p);func_021DD9DC((unsigned char *)p);func_021E4888(p);
 func_021DD528(p,1);func_02041570(6,0);CLACT_SetActorDrawEnable((struct Obj *)*(int *)&((struct Obj00001 *)p)->fF04,0);
 func_021B6558((unsigned char *)(*(int *)&((struct Obj00001 *)p)->f9C0),1,1);TOUCHBAR_SetButtonEnabled((unsigned char *)(*(int *)&((struct Obj00001 *)p)->f9C0),1,0);func_021E24E8(p,6);
 ((struct Obj00001 *)p)->f108C=0;((struct Obj00001 *)p)->f1084=1;func_021E6B90(p);
 WIPE_SYS_Start(0,1,1,0,6,1,((struct Obj00001 *)p)->f5F4);func_021D8E84(p,(int)func_021DEC4C);
}

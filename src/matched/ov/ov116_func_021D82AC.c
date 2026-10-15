/*
 * unit: yes
 * function: WIFI_BSUBWAY_GRAPHIC_Delete, WIFI_BSUBWAY_GRAPHIC_OnRedraw
 * address: 0x021D82AC
 * packet: pkt_ov116_021D82AC
 * region: ov116
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030EAC 0x02030EAC arm
 *   WIFI_BSUBWAY_GRAPHIC_TeardownBg 0x021D8364 thumb ov116
 *   func_0201DD68 0x0201DD68 thumb
 *   MI_CpuFill8 0x02082BCC arm
 *   func_020307B0 0x020307B0 arm
 *   WIFI_BSUBWAY_GRAPHIC_Draw 0x021D839C thumb ov116
 * volatile: hardware registers 0x04000050, 0x04001050, 0x04000000, 0x04001000 are read/written at 021D8244..021D8258 or 021D82C4..021D82DA.
 */
#include "../include/Obj22633.h"
struct Node;
extern void func_02030EAC(struct Node *n);
extern void WIFI_BSUBWAY_GRAPHIC_TeardownBg(void *);
extern void func_0201DD68(void);
extern void MI_CpuFill8(void *,int,int);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
extern void WIFI_BSUBWAY_GRAPHIC_Draw(void *);
void WIFI_BSUBWAY_GRAPHIC_Delete(void *p) {
 func_02030EAC(((struct Obj22633 *)p)->fC); WIFI_BSUBWAY_GRAPHIC_TeardownBg(p); func_0201DD68();
 *(volatile unsigned short *)0x04000050=0;
 *(volatile unsigned short *)0x04001050=0;
 *(volatile unsigned *)0x04000000 &= 0xffff1fff;
 *(volatile unsigned *)0x04001000 &= 0xffff1fff;

 MI_CpuFill8(p,0,16); func_020307B0(p);
}
void WIFI_BSUBWAY_GRAPHIC_OnRedraw(void *a,void *b) {WIFI_BSUBWAY_GRAPHIC_Draw(b);}

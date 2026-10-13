/*
 * function: func_021B67C4
 * address: 0x021B67C4
 * packet: pkt_ov180_021B67C4
 * region: ov180
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PARTICLE_StartEffect 0x020515B4 arm
 *   d_021B80CC 0x021B80CC data a4
 */
#include "../include/Obj24485.h"
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef struct {int a,b,c;} Triple;
extern Triple d_021B80CC;
extern int PARTICLE_StartEffect(void *p, int b, int c);
void func_021B67C4(char *p,int a){Triple v;v=d_021B80CC;PARTICLE_StartEffect(((struct Obj24485 *)p)->f28,a,(int)((int *)&v));}

/*
 * function: func_021B6760
 * address: 0x021B6760
 * packet: pkt_ov101_021B6760
 * region: ov101
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B6508 0x021B6508 thumb ov101
 *   func_020307B0 0x020307B0 arm
 *   MI_CpuFill8 0x02082BCC arm
 */
typedef unsigned int   u32;
extern void func_021B6508(u32 p, u32 a);
extern u32 func_020307B0(void *p);
extern void MI_CpuFill8(void *,int,unsigned);
void func_021B6760(int *p) { func_021B6508((u32)((int *)p[0]),0x1000); func_020307B0((void *)p[10]); func_020307B0((void *)p[11]); func_020307B0((void *)p[12]); MI_CpuFill8(p,0,0x34); }

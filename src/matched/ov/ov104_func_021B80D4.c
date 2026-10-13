/*
 * function: func_021B80D4
 * address: 0x021B80D4
 * packet: pkt_ov104_021B80D4
 * region: ov104
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MI_CpuFill8 0x02082BCC arm
 *   func_021B7968 0x021B7968 thumb ov104
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void MI_CpuFill8(void *,int,int);
extern int func_021B7968(u8 *,int);
void func_021B80D4(int *p, u8 *q, int a2) { int i; MI_CpuFill8(p,0,0x1c); for(i=0;i<3;i++) *p=func_021B7968(q,i+0x1f); }

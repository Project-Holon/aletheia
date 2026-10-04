/*
 * function: func_021F376C
 * address: 0x021F376C
 * packet: pkt_ov048_021F376C
 * region: ov048
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021897BC 0x021897BC thumb ov021
 *   func_021F4784 0x021F4784 thumb ov048
 *   func_02188D2C 0x02188D2C thumb ov021
 *   func_021BE580 0x021BE580 thumb ov021
 *   d_021F50C0 0x021F50C0 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int *func_021897BC(char *,int);
extern void func_021F4784(unsigned char *p, int c);
extern int func_02188D2C(int *p);
extern void func_021BE580(void *);
extern int d_021F50C0;
void func_021F376C(char *a) { int *p; p=func_021897BC(a,0); func_021F4784((void *)p[5],d_021F50C0); func_021BE580((void *)func_02188D2C((int *)((u32)a))); }

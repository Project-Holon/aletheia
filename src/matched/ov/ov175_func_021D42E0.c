/*
 * function: func_021D42E0
 * address: 0x021D42E0
 * packet: pkt_ov175_021D42E0
 * region: ov175
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02034714 0x02034714 arm
 *   d_021E2C74 0x021E2C74 data a4
 *   d_021E2C80 0x021E2C80 data a4
 *   d_021E2DE0 0x021E2DE0 data
 */
typedef int (*Callback)(int,int,int *,int);
typedef struct { Callback create,other,close; } Table;
extern const Table d_021E2C74,d_021E2C80;extern const char d_021E2DE0[];extern void func_02034714(const char *,unsigned,const char *);
int func_021D42E0(int a,int b,int *p,int d) {switch(((int *)p[2])[2]) {case 1:return d_021E2C74.other(a,b,p,d);case 0:return d_021E2C80.other(a,b,p,d);default:func_02034714(d_021E2DE0,0,d_021E2DE0);return 0;}}

/*
 * function: func_0216A358
 * address: 0x0216A358
 * packet: pkt_ov010_0216A358
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02011400 0x02011400 thumb
 *   func_0216A390 0x0216A390 thumb ov010
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u8 func_02011400(int row, int col);
extern void func_0216A390(int,int);
int func_0216A358(int a,int b,u32 *p,int c) { u32 hi; u32 lo; int result; hi=func_02011400(c,3); lo=func_02011400(c,0); result=0; if (!(*p < hi && *p >= lo)) { func_0216A390(a,b); result=1; } return result; }

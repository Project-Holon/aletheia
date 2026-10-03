/*
 * function: func_021DA138
 * address: 0x021DA138
 * packet: pkt_ov123_021DA138
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020362DC 0x020362DC arm
 *   func_021D97B0 0x021D97B0 thumb ov123
 *   func_02009448 0x02009448 thumb
 *   func_020092E0 0x020092E0 thumb
 *   func_021DA110 0x021DA110 thumb ov123
 *   func_021DA034 0x021DA034 thumb ov123
 */
typedef unsigned char u8;
extern unsigned int func_020362DC(void);
extern void func_021D97B0(char *);
struct Sub02009448Obj;
extern struct Sub02009448Obj *func_02009448(void *sys);
extern void func_020092E0(void *,int);
extern void func_021DA110(char *);
extern void func_021DA034(char *,int,int);
void func_021DA138(char *p) { if(func_020362DC()) { func_021D97B0(*(char **)(p+0x10)); func_020092E0(func_02009448(*(void **)(p+0x1c)),1); func_021DA034(p,(int)func_021DA110,0x11a); } }

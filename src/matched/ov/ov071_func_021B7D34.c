/*
 * function: func_021B7D34
 * address: 0x021B7D34
 * packet: pkt_ov071_021B7D34
 * region: ov071
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0201C6B4 0x0201C6B4 thumb
 *   func_02043534 0x02043534 arm
 *   func_021B7E24 0x021B7E24 thumb ov071
 *   func_021B6EEC 0x021B6EEC thumb ov071
 *   func_021B7D98 0x021B7D98 thumb ov071
 *   func_020315D4 0x020315D4 arm
 */

typedef unsigned int   u32;
struct PrintSys;
struct S020315D4;
extern u32 func_0201C6B4(const struct PrintSys *p);
extern void func_02043534(unsigned);
extern void func_021B7E24(void **);
extern void func_021B6EEC(void **p);
extern void func_021B7D98(void);
extern void func_020315D4(struct S020315D4 *p);
int func_021B7D34(void *a,int b,char *c,void **d) { if(func_0201C6B4(*(void **)(*(char **)(c+4)+8))==0) return 0; func_02043534(8); func_021B7E24(d); func_021B6EEC(d); func_021B7D98(); func_020315D4(a); return 1; }

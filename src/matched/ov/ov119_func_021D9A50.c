/*
 * function: func_021D9A50
 * address: 0x021D9A50
 * packet: pkt_ov119_021D9A50
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020279E8 0x020279E8 thumb
 *   func_02027A04 0x02027A04 thumb
 *   func_021E12F8 0x021E12F8 thumb ov119
 *   func_021E1098 0x021E1098 thumb ov119
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021D9750 0x021D9750 thumb ov119
 *   func_021D99F4 0x021D99F4 thumb ov119
 *   func_021DADAC 0x021DADAC thumb ov119
 *   func_0202208C 0x0202208C thumb
 */
typedef unsigned short u16;
extern int func_020279E8(int);
extern int func_02027A04(int);
extern void func_021E12F8(void *);
extern void func_021E1098(void *);
extern void func_021D8E84(void *,int);
extern void func_021D9750(void *);
extern void func_021D99F4(void *);
extern void func_021DADAC(void *);
extern void func_0202208C(int,int,int,int,int,int,int);
void func_021D9A50(char *p) { int v; if(func_020279E8(*(int *)(p+0x64c))) {v=func_02027A04(*(int *)(p+0x64c));func_021E12F8(p);func_021E1098(p);*(int *)(p+0x64c)=0;switch(v) {case 0:func_021D8E84(p,(int)func_021D9750);return;case 1:func_0202208C(3,0,0,0,6,1,*(u16 *)(p+0x5f4));func_021D8E84(p,(int)func_021D99F4);return;case 2:func_021D8E84(p,(int)func_021DADAC);return;} } }

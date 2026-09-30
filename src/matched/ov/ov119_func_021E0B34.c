/*
 * function: func_021E0B34
 * address: 0x021E0B34
 * packet: pkt_ov119_021E0B34
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021E10D8 0x021E10D8 thumb ov119
 *   func_02045CAC 0x02045CAC arm
 *   func_0201F5DC 0x0201F5DC thumb
 *   func_021E1024 0x021E1024 thumb ov119
 *   func_021E1030 0x021E1030 thumb ov119
 *   func_021DFD30 0x021DFD30 thumb ov119
 *   func_02040588 0x02040588 arm
 *   func_0203D34C 0x0203D34C arm
 *   func_0204E720 0x0204E720 arm
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021E0BA4 0x021E0BA4 thumb ov119
 */
typedef unsigned short u16;
extern void func_021E10D8(void *);
extern void func_02045CAC(int,int,int);
extern int func_0201F5DC(int,int,int,int);
extern void func_021E1024(void *);
extern void func_021E1030(void *);
extern void func_021DFD30(void *,int);
extern void func_02040588(int,int);
extern void func_0203D34C(int,int);
extern void func_0204E720(int,int,int,int);
extern void func_021D8E84(void *,int);
extern void func_021E0BA4(void *);
void func_021E0B34(char *p) {func_021E10D8(p);func_02045CAC(*(int *)(p+0x720),50,*(int *)(p+0x738));*(int *)(p+0x644)=func_0201F5DC(6,15,0,*(u16 *)(p+0x5f4));func_021E1024(p);func_021E1030(p);func_021DFD30(p,0);func_02040588(6,1);func_0203D34C(1,*(u16 *)(p+0x5f4));func_0204E720(3,16,0,2);func_021D8E84(p,(int)func_021E0BA4);}

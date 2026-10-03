/*
 * function: func_021B6F34
 * address: 0x021B6F34
 * packet: pkt_ov180_021B6F34
 * region: ov180
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * trailing: zero halfword alignment padding at 0x021B6F7E.
 * symbols:
 *   func_0204363C 0x0204363C arm
 *   func_021B61D4 0x021B61D4 thumb ov180
 *   func_021B6224 0x021B6224 thumb ov180
 *   func_021B6254 0x021B6254 thumb ov180
 *   func_021B6360 0x021B6360 thumb ov180
 *   func_021B66A0 0x021B66A0 thumb ov180
 *   func_021B68A8 0x021B68A8 thumb ov180
 *   func_021B7318 0x021B7318 thumb ov180
 *   func_021B7D80 0x021B7D80 thumb ov180
 *   func_021B6170 0x021B6170 thumb ov180
 *   func_021B7210 0x021B7210 thumb ov180
 */
typedef unsigned int   u32;
extern void func_0204363C(u32 swap);
extern void func_021B61D4(int);
extern void func_021B6224(void);
extern void func_021B6254(void);
extern void func_021B6360(void);
extern void func_021B66A0(char *);
extern void func_021B68A8(char *);
extern void func_021B7318(char *,int);
extern void func_021B7D80(char *);
extern void func_021B6170(char *);
extern int func_021B7210(char *,int);
int func_021B6F34(char *p) {
    func_0204363C(0); func_021B61D4(1); func_021B6224(); func_021B6254(); func_021B6360();
    func_021B66A0(p); func_021B68A8(p); func_021B7318(p,1); func_021B7D80(p); func_021B6170(p);
    *(int *)(p+8)=2;
    return func_021B7210(p,8);
}

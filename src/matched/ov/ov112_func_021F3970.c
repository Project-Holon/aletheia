/*
 * function: func_021F3970
 * address: 0x021F3970
 * packet: pkt_ov112_021F3970
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020221A4 0x020221A4 thumb
 *   func_0207D534 0x0207D534 arm
 *   func_0207D63C 0x0207D63C arm
 *   func_021F4300 0x021F4300 thumb ov112
 *   func_021F3BF0 0x021F3BF0 thumb ov112
 *   func_021F3AE0 0x021F3AE0 thumb ov112
 *   func_02030EAC 0x02030EAC arm
 *   func_02034A5C 0x02034A5C arm
 *   func_020307B0 0x020307B0 arm
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 *   ov_abs_84 0x00000084 data
 */
typedef unsigned char u8;
extern u8 ov_abs_84[];
extern unsigned func_020221A4(void);
extern void func_0207D534(void *,int);
extern void func_0207D63C(void *,int,int,int,int);
extern void func_021F4300(u8 *);
extern void func_021F3BF0(u8 *);
extern void func_021F3AE0(void *);
extern void func_02030EAC(void *);
extern void func_02034A5C(int);
extern void func_020307B0(void *);
extern void func_020315D4(void *);
extern void func_020306F0(void *);
int func_021F3970(void *owner,void *arg,int flag,u8 *p) {
    if (!func_020221A4()) return 0;
    func_0207D534((void *)0x0400006c,-16);
    func_0207D534((void *)0x0400106c,-16);
    func_0207D63C((void *)0x04000050,0,0,31,31);
    func_021F4300(*(u8 **)(p+16));
    func_021F3BF0(*(u8 **)(p+12));
    func_021F3AE0(p);
    func_02030EAC(*(void **)(p+4));
    if (*(int *)(*(u8 **)(p+8)+4)==1) func_02034A5C((int)ov_abs_84);
    if (flag==0) {
        func_020307B0(*(void **)(*(u8 **)(p+8)+8));
        func_020307B0(*(void **)(p+8));
        func_02034A5C((int)ov_abs_84);
    }
    func_020315D4(owner);
    func_020306F0((void *)74);
    return 1;
}

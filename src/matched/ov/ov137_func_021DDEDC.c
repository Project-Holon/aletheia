/*
 * function: func_021DDEDC
 * address: 0x021DDEDC
 * packet: pkt_ov137_021DDEDC
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020399A8 0x020399A8 arm
 *   func_02039CB4 0x02039CB4 arm
 *   func_021DE37C 0x021DE37C thumb ov137
 *   func_0203D7B0 0x0203D7B0 arm
 *   func_0202208C 0x0202208C thumb
 *   func_021DD924 0x021DD924 thumb ov137
 */
typedef unsigned short u16;
extern void *func_020399A8(void);
extern int func_02039CB4(void *, int, int);
extern unsigned func_021DE37C(char *);
extern void func_0203D7B0(int);
extern void func_0202208C(int,int,int,int,int,int,int);
extern void func_021DD924(char *);
int func_021DDEDC(char *p, int state) {
    if (func_02039CB4(func_020399A8(), 0xcf, 0x28) != 0 ||
        *(unsigned *)(p + 0x4814) != (func_021DE37C(p) ^ *(unsigned *)(p + 0x480c))) {
        func_0203D7B0(0);
        func_0202208C(0,0,0,0,0x10,1,0x72);
        state = 3;
    }
    func_021DD924(p);
    return state;
}

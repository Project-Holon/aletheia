/*
 * function: func_021DD79C
 * address: 0x021DD79C
 * packet: pkt_ov137_021DD79C
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02039338 0x02039338 arm
 *   func_0203D7B0 0x0203D7B0 arm
 *   func_021DCF50 0x021DCF50 thumb ov137
 *   func_021841A4 0x021841A4 thumb ov022
 *   func_021DE4B4 0x021DE4B4 thumb ov137
 *   func_021DD93C 0x021DD93C thumb ov137
 */
typedef unsigned short u16;
extern u16 func_02039338(void);
extern void func_0203D7B0(int);
extern void *func_021DCF50(void *);
extern unsigned func_021841A4(void *);
extern void func_021DE4B4(char *, int, int);
extern void func_021DD93C(char *, int);
int func_021DD79C(char *p, int state) {
    if (func_02039338() == 0) {
        int zero = 0;
        func_0203D7B0(0);
        if (func_021841A4(func_021DCF50(p)) >= 2)
            func_021DE4B4(p, 2, zero);
    } else {
        func_0203D7B0(1);
        func_021DE4B4(p, 8, 0);
    }
    func_021DD93C(p, 3);
    return state;
}

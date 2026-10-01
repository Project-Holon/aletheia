/*
 * function: func_021DDD80
 * address: 0x021DDD80
 * packet: pkt_ov137_021DDD80
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021DE354 0x021DE354 thumb ov137
 *   func_021DE7F4 0x021DE7F4 thumb ov137
 *   func_020061E4 0x020061E4 thumb
 *   func_021DD924 0x021DD924 thumb ov137
 *   func_0201FEBC 0x0201FEBC thumb
 *   func_021DCF50 0x021DCF50 thumb ov137
 *   func_02184134 0x02184134 thumb ov022
 *   func_021DCBC4 0x021DCBC4 thumb ov137
 *   func_02184180 0x02184180 thumb ov022
 *   func_0201F02C 0x0201F02C thumb
 */
typedef unsigned short u16;
typedef signed short s16;
extern unsigned func_021DE354(char *);
extern unsigned func_021DE7F4(void);
extern void func_020061E4(int);
extern void func_021DD924(char *);
extern unsigned func_0201FEBC(void *);
extern void *func_021DCF50(void *);
extern void func_02184134(void *);
extern int func_021DCBC4(void *, int, void *, int);
extern void *func_02184180(void *, int);
extern void func_0201F02C(void *, int, void *);
int func_021DDD80(char *p, int state) {
    char *q = *(char **)(p+0x10);
    unsigned result;
    if (*(unsigned *)(q+0x2c) != func_021DE354(p) || *(unsigned *)(q+0x30) != 0) {
        if (func_021DE7F4() & 0xc3) func_020061E4(0x54c);
        func_021DD924(p);
        return state;
    }
    result = func_0201FEBC(*(void **)(p+0xe8));
    if (result != -1) {
        if (result == -2) {
            *(int *)(p+0x118) = 0;
            func_02184134(func_021DCF50(p));
        } else {
            *(int *)(p+0x118) = 0xd;
            func_021DCBC4(*(void **)(p+0x10), 0x2802, 0, 0);
            func_0201F02C(*(void **)(p+0x3c), 0, func_02184180(func_021DCF50(p), 0));
        }
        *(void **)(p+0xe8) = 0;
    }
    func_021DD924(p);
    return state;
}

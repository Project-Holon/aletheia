/*
 * function: func_021DDBE8
 * address: 0x021DDBE8
 * packet: pkt_ov137_021DDBE8
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
 *   func_02039338 0x02039338 arm
 */
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int   u32;
typedef unsigned char  u8;
extern int func_021DE354(void *p);
extern unsigned func_021DE7F4(void);
extern void func_020061E4(u32 a);
extern void func_021DD924(char *);
extern u32 func_0201FEBC(u8 *p);
extern void *func_021DCF50(void *);
extern void func_02184134(u8 *p);
extern u16 func_02039338(void);
int func_021DDBE8(char *p, int state) {
    char *q = *(char **)(p+0x10);
    unsigned result;
    if (*(unsigned *)(q+0x2c) != func_021DE354(p) || *(unsigned *)(q+0x30) != 0) {
        if (func_021DE7F4() & 0xc3) func_020061E4(0x548);
        func_021DD924(p);
        return state;
    }
    result = func_0201FEBC(*(void **)(p+0xe8));
    if (result != -1) {
        if (result == -2) {
            func_02184134(func_021DCF50(p));
            *(int *)(p+0x118) = 0;
        } else {
            if (func_02039338() == 0) {
                *(int *)(p+0x118) = 0x18;
                *(unsigned char *)(p+0x4812) = func_021DE354(p);
            }
        }
        *(void **)(p+0xe8) = 0;
    }
    func_021DD924(p);
    return state;
}

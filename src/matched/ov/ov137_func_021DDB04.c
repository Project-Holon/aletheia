/*
 * function: func_021DDB04
 * address: 0x021DDB04
 * packet: pkt_ov137_021DDB04
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: 021DDB46 store then 021DDB48 re-read of s16 field at 0x4820
 * symbols:
 *   func_021DCF50 0x021DCF50 thumb ov137
 *   func_021841A4 0x021841A4 thumb ov022
 *   func_021DE354 0x021DE354 thumb ov137
 *   func_021DD924 0x021DD924 thumb ov137
 *   func_02082BCC 0x02082BCC arm
 *   func_02039338 0x02039338 arm
 *   func_021DCBC4 0x021DCBC4 thumb ov137
 */
typedef unsigned short u16;
typedef signed short s16;
extern void *func_021DCF50(void *);
extern unsigned func_021841A4(void *);
extern unsigned func_021DE354(char *);
extern void func_021DD924(char *);
extern void func_02082BCC(void *, int, unsigned);
extern int func_02039338(void);
extern int func_021DCBC4(void *, int, void *, int);
int func_021DDB04(char *p, int state) {
    unsigned char buf[4];
    if (*(u16 *)(*(char **)(p+0x10)+0x38) != func_021841A4(func_021DCF50(p)) ||
        *(u16 *)(*(char **)(p+0x10)+0x38) != func_021DE354(p)) {
        *(s16 *)(p+0x4820) = 0;
        *(int *)(p+0x118) = 8;
        func_021DD924(p);
        return state;
    }
    ++*(volatile s16 *)(p+0x4820);
    if (*(volatile s16 *)(p+0x4820) > 30) {
        int zero = 0;
        func_02082BCC(buf, 0, 4);
        buf[2] = 1;
        buf[0] = func_02039338();
        func_021DCBC4(*(void **)(p+0x10), 0x2801, buf, 4);
        *(s16 *)(p+0x4820) = zero;
        *(int *)(p+0x118) = 9;
    }
    func_021DD924(p);
    return state;
}

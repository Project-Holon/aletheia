/*
 * function: func_021DD80C
 * address: 0x021DD80C
 * packet: pkt_ov137_021DD80C
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021DE7F4 0x021DE7F4 thumb ov137
 *   func_02039338 0x02039338 arm
 *   func_021DE354 0x021DE354 thumb ov137
 *   func_021DCF50 0x021DCF50 thumb ov137
 *   func_02184114 0x02184114 thumb ov022
 *   func_021841A4 0x021841A4 thumb ov022
 *   func_02184134 0x02184134 thumb ov022
 *   func_020061E4 0x020061E4 thumb
 *   func_021DE4B4 0x021DE4B4 thumb ov137
 *   func_021DD93C 0x021DD93C thumb ov137
 */
extern unsigned func_021DE7F4(void);
typedef unsigned short u16;
typedef unsigned int   u32;
typedef unsigned char  u8;
extern u16 func_02039338(void);
extern int func_021DE354(void *p);
extern void *func_021DCF50(void *);
extern int func_02184114(unsigned char *p);
extern int func_021841A4(unsigned char *p);
extern void func_02184134(u8 *p);
extern void func_020061E4(u32 a);
extern void func_021DE4B4(char *,int,int);
extern void func_021DD93C(char *,int);
void func_021DD80C(char *p) {
    char *q;
    if (func_021DE7F4()&1) {
        if (func_02039338()==0) {
            q=*(char **)(p+0x10);
            if (*(unsigned *)(q+0x2c)==func_021DE354(p) && *(unsigned *)(q+0x30)==0) {
                if (func_02184114(func_021DCF50(p))) {
                    func_020061E4(0x54c);
                    func_021DE4B4(p,3,0);
                    func_021DD93C(p,22);
                }
            } else func_020061E4(0x548);
        }
    } else if (func_021DE7F4()&2) {
        if (func_02039338()!=0) {
            if (*(unsigned *)(*(char **)(p+0x10)+0x28)==0) {
                func_021DE4B4(p,4,0);
                func_021DD93C(p,4);
            } else func_020061E4(0x548);
        } else {
            q=*(char **)(p+0x10);
            if (*(unsigned *)(q+0x2c)==func_021841A4(func_021DCF50(p)) && *(unsigned *)(q+0x30)==0) {
                if (func_02184114(func_021DCF50(p))) {
                    func_021DE4B4(p,4,0);
                    func_021DD93C(p,4);
                    func_020061E4(0x551);
                }
            } else func_020061E4(0x548);
        }
    } else {
        if (*(unsigned *)(p+0x4808)==0 && func_02039338()==0 &&
            *(unsigned *)(*(char **)(p+0x10)+0x2c)==func_021841A4(func_021DCF50(p)))
            func_02184134(func_021DCF50(p));
    }
}

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
#include "../include/Obj03303.h"
#include "../include/Obj23720.h"
#include "../include/Obj23721.h"
typedef unsigned short u16;
typedef signed short s16;
extern void *func_021DCF50(void *);
typedef unsigned int   u32;
extern int func_021841A4(unsigned char *p);
extern int func_021DE354(void *p);
extern void func_021DD924(char *);
extern void func_02082BCC(void *, int, unsigned);
extern u16 func_02039338(void);
extern void func_021DCBC4(void *p, u32 a, const void *b, u32 c);
int func_021DDB04(char *p, int state) {
    unsigned char buf[4];
    if (((struct Obj23720 *)(*(char * *)&((struct Obj03303 *)p)->f10))->f38 != func_021841A4(func_021DCF50(p)) ||
        ((struct Obj23721 *)(*(char * *)&((struct Obj03303 *)p)->f10))->f38 != func_021DE354(p)) {
        ((struct Obj03303 *)p)->f4820 = 0;
        ((struct Obj03303 *)p)->f118 = 8;
        func_021DD924(p);
        return state;
    }
    ++*(volatile s16 *)&((struct Obj03303 *)p)->f4820;
    if (*(volatile s16 *)&((struct Obj03303 *)p)->f4820 > 30) {
        int zero = 0;
        func_02082BCC(buf, 0, 4);
        buf[2] = 1;
        buf[0] = func_02039338();
        func_021DCBC4(((struct Obj03303 *)p)->f10, 0x2801, buf, 4);
        ((struct Obj03303 *)p)->f4820 = zero;
        ((struct Obj03303 *)p)->f118 = 9;
    }
    func_021DD924(p);
    return state;
}

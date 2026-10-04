/*
 * function: func_021DDE94
 * address: 0x021DDE94
 * packet: pkt_ov137_021DDE94
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020399A8 0x020399A8 arm
 *   func_021DE37C 0x021DE37C thumb ov137
 *   func_0203A424 0x0203A424 arm
 *   func_021DD924 0x021DD924 thumb ov137
 */
#include "../include/Obj08212.h"
typedef unsigned short u16;
struct Entry;
extern struct Entry *func_020399A8(void);
extern unsigned func_021DE37C(void *p);
extern void func_0203A424(void *, int, int, u16);
extern void func_021DD924(char *);
int func_021DDE94(char *p, int state) {
    func_020399A8();
    ((struct Obj08212 *)p)->f4814 = ((struct Obj08212 *)p)->f480C ^ func_021DE37C(p);
    func_0203A424(func_020399A8(), 0xcf, 0x28, ((struct Obj08212 *)p)->f4814);
    ((struct Obj08212 *)p)->f118 = 0x10;
    func_021DD924(p);
    return state;
}

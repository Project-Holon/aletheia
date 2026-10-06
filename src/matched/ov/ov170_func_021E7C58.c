/*
 * function: func_021E7C58
 * address: 0x021E7C58
 * packet: pkt_ov170_021E7C58
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021DF040 0x021DF040 thumb ov170
 *   func_021EE364 0x021EE364 thumb ov170
 *   func_021EF670 0x021EF670 thumb ov170
 *   func_021ECB20 0x021ECB20 thumb ov170
 *   func_021E22B8 0x021E22B8 thumb ov170
 */
#include "../include/Obj00000.h"
#include "../include/Obj23913.h"
extern void func_021DF040(char *p);
extern void func_021EE364(char **p, int idx, int v);
extern void func_021EF670(char *w);
extern void func_021ECB20(char *p, int f, int c);
extern int func_021E22B8(int p);
#define WORK(p) (*(char **)((p) + 0x2C))
#define STEP(p) (*(int *)(WORK(p) + 0xA194))
int func_021E7C58(unsigned char *p)
{
    func_021DF040((char *)p);
    switch (((struct Obj23913 *)(*(char * *)&((struct Obj00000 *)p)->f0))->f24) {
    case 1:
        func_021EE364((char **)p, 2, 0x1E);
        *(int *)(WORK(p) + 0xA168) = 0x1E;
        *(int *)(WORK(p) + 0xA198) = 0x2C;
        break;
    case 2:
        func_021EF670(WORK(p));
        func_021EE364((char **)p, 3, 0x1E);
        *(int *)(WORK(p) + 0xA168) = 0x1E;
        *(int *)(WORK(p) + 0xA198) = 0x11;
        break;
    case 3:
        func_021ECB20((char *)p, 0x81, 1);
        func_021EF670(WORK(p));
        func_021EE364((char **)p, 7, 0x1E);
        *(int *)(WORK(p) + 0xA168) = 0x1E;
        *(int *)(WORK(p) + 0xA198) = 0x39;
        break;
    case 4:
        func_021EF670(WORK(p));
        func_021EE364((char **)p, 0xD, 0x1E);
        *(int *)(WORK(p) + 0xA168) = 0x1E;
        *(int *)(WORK(p) + 0xA198) = 0x23;
        break;
    case 0:
        break;
    }
    return func_021E22B8((int)p);
}

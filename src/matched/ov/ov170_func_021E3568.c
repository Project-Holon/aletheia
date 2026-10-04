/*
 * function: func_021E3568
 * address: 0x021E3568
 * packet: pkt_ov170_021E3568
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021E2094 0x021E2094 thumb ov170
 *   func_020260F0 0x020260F0 thumb
 *   func_021EC000 0x021EC000 thumb ov170
 *   func_021EBA5C 0x021EBA5C thumb ov170
 *   func_021DD14C 0x021DD14C thumb ov170
 *   func_021EF770 0x021EF770 thumb ov170
 *   func_021EF670 0x021EF670 thumb ov170
 *   func_021EF68C 0x021EF68C thumb ov170
 */
#include "../include/Obj00000.h"
#include "../include/Obj23894.h"
struct WinMgr;
extern int func_021E2094(char *);
typedef unsigned int   u32;
struct Sound;
extern u32 func_020260F0(struct Sound *obj);
extern void func_021EC000(char *, int, int);
extern void func_021EBA5C(char *, int);
extern void func_021DD14C(unsigned char *);
extern int func_021EF770(struct WinMgr *mgr);
extern void func_021EF670(char *);
extern void func_021EF68C(char *);
#define W(p) (*(char **)((p) + 0x2C))
int func_021E3568(unsigned char *p)
{
    int n;
    if (func_021E2094((char *)p) == 6)
        return 0x18;
    if (func_020260F0(*(void **)(W(p) + 0x70)) == 1)
        func_021EC000(W(p), 4, 1);
    if ((unsigned char)W(p)[0xA173] == 5)
        n = 0x1B;
    else
        n = 0x18;
    func_021EBA5C(W(p), n);
    func_021DD14C(p);
    if (((struct Obj23894 *)(*(char * *)&((struct Obj00000 *)p)->f0))->f24 == 2) {
        if (func_021EF770(*(struct WinMgr **)(W(p) + 0x74)) == 1)
            func_021EF670(W(p));
        else
            func_021EF68C(W(p));
    }
    W(p)[0xA173] = 0;
    return ((struct Obj00000 *)p)->f28;
}

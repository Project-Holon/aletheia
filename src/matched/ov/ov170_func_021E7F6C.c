/*
 * function: func_021E7F6C
 * address: 0x021E7F6C
 * packet: pkt_ov170_021E7F6C
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021EE364 0x021EE364 thumb ov170
 *   func_021ED888 0x021ED888 thumb ov170
 *   func_021ED55C 0x021ED55C thumb ov170
 *   func_021EBA5C 0x021EBA5C thumb ov170
 *   func_021DD14C 0x021DD14C thumb ov170
 *   func_021ECB20 0x021ECB20 thumb ov170
 *   func_021EF6CC 0x021EF6CC thumb ov170
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   func_021E8FC0 0x021E8FC0 thumb ov170
 *   func_021E01A8 0x021E01A8 thumb ov170
 *   func_021E8F50 0x021E8F50 thumb ov170
 */
#include "../include/Obj00000.h"
#include "../include/Obj23927.h"
struct WinMgr;
extern void func_021EE364(char **p, int idx, int v);
extern void func_021ED888(char *w, int a);
extern void func_021ED55C(char **p, int flag);
extern void func_021EBA5C(char *w, int v);
extern void func_021DD14C(char *p);
extern void func_021ECB20(char *p, int f, int c);
extern void func_021EF6CC(struct WinMgr *mgr);
extern void GFL_USE_PlaySeDefaultVolume(unsigned se);
extern int func_021E8FC0(char *p, int a, int b);
extern int func_021E01A8(char *p);
extern int func_021E8F50(char *p, int v);
#define WORK(p) (*(char **)((p) + 0x2C))
#define STEP(p) (*(int *)(WORK(p) + 0xA194))
int func_021E7F6C(unsigned char *p)
{
    switch (((struct Obj23927 *)(*(char * *)&((struct Obj00000 *)p)->f0))->f24) {
    case 0:
        func_021EE364((char **)p, 0, 10);
        break;
    case 1:
        func_021ED888(WORK(p), 1);
        func_021EE364((char **)p, 2, 0x25);
        break;
    case 2:
    default:
        if (p[0x16] < 0x1E) {
            func_021ED888(WORK(p), 1);
            func_021EE364((char **)p, 3, 0x27);
        } else {
            func_021EE364((char **)p, 5, 0xC);
        }
        break;
    }
    func_021ED55C((char **)p, 0);
    func_021EBA5C(WORK(p), 0x18);
    func_021DD14C((char *)p);
    if (p[0x16] < 0x1E)
        func_021ECB20((char *)p, 1, 0);
    func_021ECB20((char *)p, 2, 0);
    func_021EF6CC(*(struct WinMgr **)(WORK(p) + 0x74));
    GFL_USE_PlaySeDefaultVolume(0x669);
    return func_021E8FC0((char *)p, (int)((int (*)(unsigned char *))func_021E01A8), func_021E8F50((char *)p, 0xE));
}

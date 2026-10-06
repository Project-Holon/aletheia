/*
 * function: func_021E8950
 * address: 0x021E8950
 * packet: pkt_ov170_021E8950
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Return from func_021EA858 is used despite its legacy void declaration.
 * symbols:
 *   func_021ED55C 0x021ED55C thumb ov170
 *   func_021EBA5C 0x021EBA5C thumb ov170
 *   func_021DD14C 0x021DD14C thumb ov170
 *   func_021EE008 0x021EE008 thumb ov170
 *   func_020061E4 0x020061E4 thumb
 *   func_021EA858 0x021EA858 thumb ov170
 *   func_021ED888 0x021ED888 thumb ov170
 *   func_021EE038 0x021EE038 thumb ov170
 *   func_021ED508 0x021ED508 thumb ov170
 *   func_021ECB20 0x021ECB20 thumb ov170
 *   func_021EF670 0x021EF670 thumb ov170
 *   func_021EE364 0x021EE364 thumb ov170
 */
#include "../include/Obj00000.h"
#include "../include/Obj23935.h"
#include "../include/Obj23936.h"
#include "../include/Obj23937.h"
#include "../include/Obj23938.h"
typedef unsigned char u8;
extern void func_021ED55C(char **p, int flag);
extern void func_021EBA5C(char *, int);
extern void func_021DD14C(char *);
extern void func_021EE008(char *, int, int);
extern void func_020061E4(unsigned);
extern int func_021EA858(char *, int);
extern void func_021ED888(char *, int);
extern void func_021EE038(char *, int, int, int);
extern void func_021ED508(unsigned char *p, int a, int b);
extern void func_021ECB20(char *, int, int);
extern void func_021EF670(char *);
extern void func_021EE364(char **p, int idx, int v);
#define W (*(char **)(p + 0x2c))
#define S (*(int *)(W + 0xA194))
int func_021E8950(char *p)
{
    switch (S) {
    case 0:
        *(u8 *)(W + 0xA17A) = 0;
        func_021ED55C((char **)p, 0);
        func_021EBA5C(W, 25);
        func_021DD14C(p);
        func_021EE008(p, 0, 0);
        func_020061E4(0x669);
        S++;
        return func_021EA858(p, 0x62);
    case 1:
        S = 0;
        func_021ED888(W, 1);
        func_021EE038(p, 0, 0, 1);
        func_021ED508((unsigned char *)p, 14, 1);
        if (((struct Obj23935 *)(*(char * *)&((struct Obj00000 *)p)->f0))->f24 == 2) {
            func_021ECB20(p, 1, 0);
            func_021EF670(W);
            func_021EE364((char **)p, 3, 30);
            return 17;
        } else if (((struct Obj23936 *)(*(char * *)&((struct Obj00000 *)p)->f0))->f24 == 1) {
            func_021ECB20(p, 1, 0);
            func_021EE364((char **)p, 2, 30);
            return 44;
        } else if (((struct Obj23937 *)(*(char * *)&((struct Obj00000 *)p)->f0))->f24 == 3) {
            func_021ECB20(p, 0x81, 1);
            func_021EF670(W);
            func_021EE364((char **)p, 7, 30);
            return 57;
        } else if (((struct Obj23938 *)(*(char * *)&((struct Obj00000 *)p)->f0))->f24 == 4) {
            func_021ECB20(p, 1, 0);
            func_021EF670(W);
            func_021EE364((char **)p, 13, 30);
            return 35;
        }
    }
    return 0x62;
}

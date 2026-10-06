/*
 * function: func_021E3B50
 * address: 0x021E3B50
 * packet: pkt_ov170_021E3B50
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021DF0BC 0x021DF0BC thumb ov170
 *   func_021DD14C 0x021DD14C thumb ov170
 *   func_021EC000 0x021EC000 thumb ov170
 *   func_021EF3A0 0x021EF3A0 thumb ov170
 *   func_020061E4 0x020061E4 thumb
 *   func_021E8FC0 0x021E8FC0 thumb ov170
 *   func_021E01B0 0x021E01B0 thumb ov170
 *   func_021ED888 0x021ED888 thumb ov170
 *   func_021EF670 0x021EF670 thumb ov170
 *   func_021ECB20 0x021ECB20 thumb ov170
 *   func_021EE364 0x021EE364 thumb ov170
 */
#include "../include/Obj00000.h"
#include "../include/Obj23897.h"
struct WinMgr;
extern void func_020061E4(unsigned);
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Sound;
struct Struct_02025CD0;
extern void func_020260E4(struct Sound *obj, u8 sel);
extern void func_020260F4(struct Struct_02025CD0 *obj, u32 state);
extern u8 func_020355C4(void);
extern unsigned func_0201AA18(void *);
extern void func_021DD14C(char *p);
extern void func_021DF0BC(unsigned char *);
extern void func_021DEFEC(char *p, int b);
extern void func_021EBA5C(char *, int);
extern void func_021ED6E4(char **p, int v);
extern void func_021EE3E4(char **, unsigned);
extern void func_021ED55C(char **, int);
extern void func_021ED508(unsigned char *, int, int);
extern void func_021ED888(char *, int);
extern void func_021EF670(char *);
extern void func_021EF68C(char *);
extern int func_021EF480(struct WinMgr *mgr);
extern void func_021EF3A0(struct WinMgr *mgr);
extern void func_021EF34C(struct WinMgr *mgr);
extern void func_021EF36C(struct WinMgr *mgr);
extern void func_021EF57C(struct WinMgr *mgr);
extern void func_021EC000(char *, int, int);
extern u32 func_021EBFEC(char *p, int i);
extern void func_021ED108(char *, int);
extern void func_021EA878(unsigned char *, int);
extern void func_021EBCB4(unsigned char *, int, int);
extern void func_021ECB20(char *p, int f, int c);
extern void func_021EC5A0(char **p, int flag);
extern void func_021EE364(char **p, int idx, int v);
extern int func_021EA83C(char *p, int a);
extern int func_021E8F50(char *p, int v);
extern int func_021E8FC0(char *p, int a, int b);
extern int func_021E0190(char *p);
extern int func_021E01B0(unsigned char *);
extern void func_021EBC58(unsigned char *, int, int, int);
#define WORK(p) (*(char **)((p) + 0x2c))
#define OBJ(p) (*(void **)(WORK(p) + 0x70))
#define MGR(p) (*(struct WinMgr **)(WORK(p) + 0x74))
#define STEP(p) (*(int *)(WORK(p) + 0xa194))
int func_021E3B50(unsigned char *p)
{
    switch (STEP(p)) {
    case 0:
        func_021DF0BC(p);
        func_021DD14C((char *)p);
        func_021EC000(WORK(p), 4, 0);
        func_021EF3A0(MGR(p));
        func_020061E4(0x669);
        STEP(p)++;
        return func_021E8FC0((char *)p, (int)func_021E01B0, 0x1c);
    case 1:
        STEP(p) = 0;
        func_021ED888(WORK(p), 1);
        func_021EF670(WORK(p));
        if (((struct Obj23897 *)(*(char * *)&((struct Obj00000 *)p)->f0))->f24 == 3) {
            func_021ECB20((char *)p, 0x81, 1);
            func_021EE364((char **)p, 7, 0x21);
            return 0x39;
        } else {
            func_021ECB20((char *)p, 1, 0);
            func_021EE364((char **)p, 3, 0x21);
            return 0x11;
        }
    }
    return 0x1c;
}

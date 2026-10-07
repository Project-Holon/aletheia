/*
 * file:     box2_seq_p18.c
 * unit:     yes
 * function: func_021E7C58, func_021E7D04, func_021E7D3C, func_021E7D64, func_021E7E54, func_021E7F6C, func_021E8014, func_021E8024, func_021E8188, func_021E81D0
 * address:  0x021E7C58
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021DF040 0x021DF040 thumb ov170
 *   func_021EE364 0x021EE364 thumb ov170
 *   func_021EF670 0x021EF670 thumb ov170
 *   func_021ECB20 0x021ECB20 thumb ov170
 *   func_021E22B8 0x021E22B8 thumb ov170
 *   func_021E95F8 0x021E95F8 thumb ov170
 *   func_021E96E8 0x021E96E8 thumb ov170
 *   func_021E9848 0x021E9848 thumb ov170
 *   func_021EBB64  0x021EBB64  thumb  ov170
 *   func_021E8F50  0x021E8F50  thumb  ov170
 *   func_021EC000 0x021EC000 thumb ov170
 *   func_021ED508 0x021ED508 thumb ov170
 *   func_021EBA5C 0x021EBA5C thumb ov170
 *   func_021DD14C 0x021DD14C thumb ov170
 *   func_021EF57C 0x021EF57C thumb ov170
 *   func_021E8FC0 0x021E8FC0 thumb ov170
 *   func_021E0190 0x021E0190 thumb ov170
 *   func_021DD25C 0x021DD25C thumb ov170
 *   func_021DF110 0x021DF110 thumb ov170
 *   func_021EF6A8 0x021EF6A8 thumb ov170
 *   func_020061E4 0x020061E4 thumb
 *   func_021E01A8 0x021E01A8 thumb ov170
 *   func_021ED888 0x021ED888 thumb ov170
 *   func_021ECB60 0x021ECB60 thumb ov170
 *   func_021EBBBC 0x021EBBBC thumb ov170
 *   func_02025DE8 0x02025DE8 thumb
 *   func_021EA908 0x021EA908 thumb ov170
 *   func_021DD2B4 0x021DD2B4 thumb ov170
 *   func_021DF11C 0x021DF11C thumb ov170
 *   func_021E94AC 0x021E94AC thumb ov170
 *   func_021E8FD0 0x021E8FD0 thumb ov170
 *   func_021ED55C 0x021ED55C thumb ov170
 *   func_021EF6CC 0x021EF6CC thumb ov170
 *   func_020307B0  0x020307B0  arm  arm9
 *   func_021DD694 0x021DD694 thumb ov170
 *   func_021EBBC8 0x021EBBC8 thumb ov170
 *   func_0201AB28 0x0201AB28 thumb
 *   func_02017E1C 0x02017E1C thumb
 *   func_0202136C 0x0202136C thumb
 *   func_021EBC58 0x021EBC58 thumb ov170
 *   func_021DD2D0 0x021DD2D0 thumb ov170
 *   func_02017E88 0x02017E88 thumb
 *   func_021E8FE8 0x021E8FE8 thumb ov170
 *   func_021DE7C8 0x021DE7C8 thumb ov170
 *   func_021EC994 0x021EC994 thumb ov170
 *   func_021ECA24 0x021ECA24 thumb ov170
 *   func_021DE7B4 0x021DE7B4 thumb ov170
 *   func_021DD314 0x021DD314 thumb
 *   func_021EDAB0 0x021EDAB0 thumb
 *   func_021EDB34 0x021EDB34 thumb
 *   func_020260E4 0x020260E4 thumb
 *   func_021EE3E4 0x021EE3E4 thumb
 *   func_021EA1C0 0x021EA1C0 thumb
 *   func_021E002C 0x021E002C thumb
 *   func_021EA1E8 0x021EA1E8 thumb
 *   func_021DEFEC 0x021DEFEC thumb
 *   func_021EF68C 0x021EF68C thumb
 */
#include "../../matched/include/Obj00000.h"
#include "../../matched/include/Obj23913.h"
#include "../../matched/include/Obj23914.h"
#include "../../matched/include/Obj23915.h"
#include "../../matched/include/Obj23916.h"
#include "../../matched/include/Obj23917.h"
#include "../../matched/include/Obj23918.h"
#include "../../matched/include/Obj23919.h"
#include "../../matched/include/Obj23920.h"
#include "../../matched/include/Obj23921.h"
#include "../../matched/include/Obj23922.h"
#include "../../matched/include/Obj23923.h"
#include "../../matched/include/Obj23924.h"
#include "../../matched/include/Obj23925.h"
#include "../../matched/include/Obj23926.h"
#include "../../matched/include/Obj23927.h"
#include "../../matched/include/Obj18466.h"
#include "../../matched/include/Obj18467.h"
#include "../../matched/include/Obj23928.h"

#define WORK(p) (*(char **)((p) + 0x2C))
#define STEP(p) (*(int *)(WORK(p) + 0xA194))
#define W (*(char **)(p + 0x2c))
#define S (*(int *)(W + 0xA194))
#define SLOT(p) (*(char **)(WORK(p) + 0xA190))
#define OBJ(p) (*(void **)(WORK(p) + 0x70))
#define STATE(p) (*(int *)((p) + 0x28))
#define MODE(p) (*(int *)(*(char **)(p) + 0x24))
struct WinMgr;
struct Sound;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern void func_021DF040(char *p);
extern void func_021EE364(char **p, int idx, int v);
extern void func_021EF670(char *w);
extern void func_021ECB20(char *p, int f, int c);
extern int func_021E22B8(int p);
extern int func_021E95F8(u8 *);
extern int func_021E96E8(u8 *);
extern int func_021E9848(u8 *);
extern void func_021EBB64(unsigned char *p, unsigned v, int i);
extern int func_021E8F50(char *p, int v);
extern void func_021EC000(char *, int, int);
extern void func_021ED508(u8 *, int, int);
extern void func_021EBA5C(char *, int);
extern void func_021DD14C(char *p);
extern void func_021EF57C(struct WinMgr *mgr);
extern int func_021E8FC0(char *p, int a, int b);
extern int func_021E0190(char *p);
extern unsigned func_021DD25C(void ***, unsigned short, int, unsigned, unsigned);
extern void func_021DF110(char *p, int b);
extern void func_021EF6A8(struct WinMgr *mgr);
extern void func_020061E4(unsigned);
extern int func_021E01A8(char *p);
extern void func_021ED888(char *, int);
extern void func_021ECB60(char *, int, int);
extern void func_021EBBBC(char *p, int b);
extern int func_02025DE8(struct Sound *obj);
extern void func_021EA908(int p, int bit);
extern void func_021DD2B4(int a, int b, int c, int d, int e);
extern void func_021DF11C(char *p, int b);
extern int func_021E94AC(u8 *, int, int);
extern int func_021E8FD0(char *p, int a);
extern void func_021ED55C(char **p, int flag);
extern void func_021EF6CC(struct WinMgr *mgr);
extern u32 func_020307B0(void *p);
extern int func_021DD694(void ***, unsigned);
extern void func_021EBBC8(u8 *, unsigned, int);
extern void *func_0201AB28(void *, unsigned);
extern unsigned func_02017E1C(void *, unsigned, unsigned);
extern unsigned func_0202136C(u16);
extern void func_021EBC58(u8 *, int, int, int);
extern int func_021DD2D0(void ***, int, unsigned);
extern unsigned func_02017E88(void *, unsigned, unsigned);
extern int func_021E8FE8(u8 *, int);
extern int func_021DE7C8(unsigned char *p);
extern int func_021EC994(char *p);
extern void func_021ECA24(int *p);
extern void func_021DE7B4(char *p);
extern void func_021DD314(char **p, int a, unsigned b);
extern void func_021EDAB0(char *p, int i);
extern void func_021EDB34(char *p, int a);
extern void func_020260E4(struct Sound *obj, u8 sel);
extern void func_021EE3E4(char **p, unsigned idx);
extern void func_021EA1C0(void *p);
extern int func_021E002C(unsigned char *p);
extern void func_021EA1E8(char *p);
extern void func_021DEFEC(char *p, int b);
extern void func_021EF68C(char *w);
int func_021E7C58(unsigned char *p);
int func_021E7D04(u8 *p);
void func_021E7D3C(char *p);
int func_021E7D64(u8 *p);
int func_021E7E54(u8 *p);
int func_021E7F6C(unsigned char *p);
int func_021E8014(char *p);
int func_021E8024(char *p);
int func_021E8188(unsigned char *p);
int func_021E81D0(unsigned char *p);

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

int func_021E7D04(u8 *p){switch(((struct Obj23914 *)(*(char * *)&((struct Obj00000 *)p)->f0))->f24){case 2:((struct Obj23915 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->fA198=func_021E95F8(p);break;case 3:((struct Obj23916 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->fA198=func_021E96E8(p);break;case 4:((struct Obj23917 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->fA198=func_021E9848(p);break;}return func_021E22B8((int)p);}

/*
 * candidate func_021E7D3C: state machine step
 */
void func_021E7D3C(char *p)
{
    int v;
    func_021EBB64((unsigned char *)((int)p), ((struct Obj00000 *)p)->f10, 0x18);
    v = *(int *)(*(int *)&((struct Obj00000 *)p)->f0 + 0x24);
    if (v == 3)
        ((struct Obj00000 *)p)->f28 = 0x3c;
    else
        ((struct Obj00000 *)p)->f28 = 0xe;
    func_021E8F50((char *)((int)p), 6);
}

int func_021E7D64(u8 *p)
{
    switch (((struct Obj23918 *)(*(u8 * *)&((struct Obj00000 *)p)->f2C))->fA194) {
    case 0:
        func_021EC000(*(char * *)&((struct Obj00000 *)p)->f2C, 4, 0);
        func_021ED508(p, 14, 0);
        func_021EBA5C(*(char * *)&((struct Obj00000 *)p)->f2C, 24);
        func_021DD14C((char *)p);
        func_021EF57C(*(struct WinMgr * *)&((struct Obj23919 *)(*(u8 * *)&((struct Obj00000 *)p)->f2C))->f74);
        (((struct Obj23920 *)(*(u8 * *)&((struct Obj00000 *)p)->f2C))->fA194)++;
        return func_021E8FC0((char *)p, (int)func_021E0190, 85);
    case 1:
        ((struct Obj23921 *)(*(u8 * *)&((struct Obj00000 *)p)->f2C))->fA174 = func_021DD25C((void ***)p, p[22], p[20], 11, 0);
        func_021DF110((char *)p, ((struct Obj23922 *)(*(u8 * *)&((struct Obj00000 *)p)->f2C))->fA174);
        func_021EF6A8(*(struct WinMgr * *)&((struct Obj23923 *)(*(u8 * *)&((struct Obj00000 *)p)->f2C))->f74);
        func_020061E4(0x669);
        (((struct Obj23924 *)(*(u8 * *)&((struct Obj00000 *)p)->f2C))->fA194)++;
        return func_021E8FC0((char *)p, (int)((int (*)(u8 *))func_021E01A8), 85);
    case 2:
        func_021EE364((char **)p, 9, 0);
        func_021ED888(*(char * *)&((struct Obj00000 *)p)->f2C, 0);
        func_021ECB20((char *)p, 1, 1);
        func_021ECB20((char *)p, 2, 1);
        func_021ECB60(*(char * *)&((struct Obj00000 *)p)->f2C, p[22], 0);
        func_021EBBBC((char *)p, 24);
        return func_021E8F50((char *)p, 86);
    }
    return 85;
}

int func_021E7E54(u8 *p)
{
    u8 mask;
    switch ((unsigned)func_02025DE8(((struct Obj23925 *)(*(u8 * *)&((struct Obj00000 *)p)->f2C))->f70)) {
    case 0:
        func_020061E4(0x54c);
        func_021EA908((int)p, 0);
        break;
    case 1:
        func_020061E4(0x54c);
        func_021EA908((int)p, 1);
        break;
    case 2:
        func_020061E4(0x54c);
        func_021EA908((int)p, 2);
        break;
    case 3:
        func_020061E4(0x54c);
        func_021EA908((int)p, 3);
        break;
    case 4:
        func_020061E4(0x54c);
        func_021EA908((int)p, 4);
        break;
    case 5:
        func_020061E4(0x54c);
        func_021EA908((int)p, 5);
        break;
    case 6:
        mask = ((struct Obj23926 *)(*(u8 * *)&((struct Obj00000 *)p)->f2C))->fA174;
        func_021DD2B4((int)p, p[22], p[20], 11, mask);
        func_021DF11C((char *)p, (unsigned)mask);
        func_020061E4(0x54c);
        return func_021E94AC(p, 0, 87);
    case 7:
        func_020061E4(0x551);
        return func_021E94AC(p, 1, 87);
    case (unsigned)-2:
        func_020061E4(0x551);
        return func_021E94AC(p, 1, 87);
    case (unsigned)-3:
        func_020061E4(0x548);
        return func_021E8FD0((char *)p, 88);
    case (unsigned)-4:
        func_020061E4(0x548);
        break;
    }
    return 86;
}

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
    func_020061E4(0x669);
    return func_021E8FC0((char *)p, (int)((int (*)(unsigned char *))func_021E01A8), func_021E8F50((char *)p, 0xE));
}


/*
 * Forward and then return a status constant.
 */
int func_021E8014(char *p)
{
    func_020307B0(((struct Obj18467 *)(*(char * *)&((struct Obj18466 *)p)->f2C))->f60);
    return 0x56;
}

int func_021E8024(char *p)
{
    unsigned slot;
    switch (S) {
    case 0:
        func_021EC000(W, 4, 0);
        func_021ED508((unsigned char *)p, 14, 0);
        func_021EF57C(*(struct WinMgr **)(W + 0x74));
        S++;
        return func_021E8FC0(p, (int)func_021E0190, 0x59);
    case 1:
        if (((struct Obj00000 *)p)->f16 >= 30) {
            func_021ECB20(p, 2, 1);
            func_021ECB60(W, ((struct Obj00000 *)p)->f16, 0);
            slot = ((struct Obj00000 *)p)->f16 - 30;
            if (func_021DD694((void ***)p, slot) == 0) {
                func_020061E4(0x557);
                func_021EBBC8((u8 *)p, 6, 24);
                *(u8 *)(W + 0xA170) = 1;
                ((struct Obj00000 *)p)->f28 = 14;
                return func_021E8F50(p, 6);
            }
            if (func_0202136C(func_02017E1C(func_0201AB28(((struct Obj23928 *)(*(char * *)&((struct Obj00000 *)p)->f0))->f8, slot), 6, 0)) == 1) {
                func_020061E4(0x557);
                func_021EBC58((u8 *)p, 0, 5, 24);
                *(u8 *)(W + 0xA170) = 1;
                ((struct Obj00000 *)p)->f28 = 14;
                return func_021E8F50(p, 6);
            }
        } else {
            func_021ED888(W, 0);
            func_021ECB20(p, 1, 1);
            func_021ECB60(W, ((struct Obj00000 *)p)->f16, 0);
        }
        if (func_02017E88((void *)func_021DD2D0((void ***)p, ((struct Obj00000 *)p)->f14, ((struct Obj00000 *)p)->f16), 0x4c, 0) != 0) {
            func_020061E4(0x557);
            func_021EBBC8((u8 *)p, 3, 24);
            *(u8 *)(W + 0xA170) = 1;
            ((struct Obj00000 *)p)->f28 = 14;
            return func_021E8F50(p, 6);
        }
        func_021EBBC8((u8 *)p, 0, 24);
        return func_021E8F50(p, func_021E8FE8((u8 *)p, 1));
    }
    return 0x59;
}

int func_021E8188(unsigned char *p)
{
    func_021DE7C8(p);
    if (func_021EC994(SLOT(p)) == 0) {
        if (((unsigned char *)SLOT(p))[6] != 0)
            return func_021E8F50((char *)p, 0x5C);
        func_021ECA24((int *)SLOT(p));
        func_021DE7B4((char *)p);
        return func_021E8F50((char *)p, 0x5B);
    }
    return 0x5A;
}


/*
 * Four-step machine on the work word at 0xA194 for releasing a Pokemon:
 * two confirmation messages, then the release itself (box slot in place,
 * party slot with a fade), then the view is restored.
 */
int func_021E81D0(unsigned char *p)
{
    switch (STEP(p)) {
    case 0:
        func_021EBBC8(p, 1, 0x18);
        STATE(p) = 0x5B;
        STEP(p)++;
        return 6;
    case 1:
        func_021EBBC8(p, 2, 0x18);
        STATE(p) = 0x5B;
        STEP(p)++;
        return 6;
    case 2:
        func_021DD314((char **)p, p[0x14], p[0x16]);
        func_021EBA5C(WORK(p), 0x18);
        func_021DD14C((char *)p);
        func_021DF040((char *)p);
        if (p[0x16] < 0x1E) {
            func_021EDAB0((char *)p, p[0x14]);
            func_021EDB34((char *)p, p[0x14]);
            if (MODE(p) == 1) {
                STATE(p) = 0x2C;
            } else {
                STATE(p) = 0x11;
                func_021EF670(WORK(p));
            }
            func_020260E4(OBJ(p), p[0x16]);
            func_021EE3E4((char **)p, p[0x16]);
            func_021ED55C((char **)p, 1);
            func_021ED888(WORK(p), 1);
            func_021ECB20((char *)p, 1, 0);
            func_021ED508(p, 0xE, 1);
            p[0x16] = 0xFF;
            STEP(p) = 0;
            return STATE(p);
        }
        func_021EA1C0(p);
        p[0x1A] = 1;
        func_021ECB20((char *)p, 2, 0);
        STEP(p)++;
        return func_021E8FC0((char *)p, (int)func_021E002C, 0x5B);
    case 3:
        STEP(p) = 0;
        func_021EA1E8((char *)p);
        func_021DEFEC((char *)p, p[0x16]);
        func_020260E4(OBJ(p), p[0x16] - 0x1E);
        func_021EE3E4((char **)p, p[0x16] - 0x1E);
        func_021ED55C((char **)p, 1);
        p[0x16] = 0xFF;
        if (MODE(p) == 0)
            return 0x31;
        func_021ED508(p, 0xE, 1);
        func_021EF68C(WORK(p));
        return 0x1B;
    }
    return 0x5B;
}

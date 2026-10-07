/*
 * file:     box2_seq_p12.c
 * unit:     yes
 * function: func_021E5914, func_021E594C, func_021E5AD4, func_021E5C5C, func_021E5DD8
 * address:  0x021E5914
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
 *   func_021EE3E4  0x021EE3E4  thumb  ov170
 *   func_021ED55C  0x021ED55C  thumb  ov170
 *   func_021EBA5C  0x021EBA5C  thumb  ov170
 *   func_021DD14C  0x021DD14C  thumb  ov170
 *   func_021EF57C 0x021EF57C thumb
 *   func_021E8FC0 0x021E8FC0 thumb
 *   func_021E0190 0x021E0190 thumb
 *   func_021EA8CC 0x021EA8CC thumb
 *   func_021ECB84 0x021ECB84 thumb
 *   func_021EC768 0x021EC768 thumb
 *   func_021E0778 0x021E0778 thumb
 *   func_020061E4 0x020061E4 thumb
 *   func_021ED6E4 0x021ED6E4 thumb
 *   func_021EBBC8 0x021EBBC8 thumb
 *   func_021EBC58 0x021EBC58 thumb
 *   func_021EF3A0 0x021EF3A0 thumb
 *   func_021E01B0 0x021E01B0 thumb
 *   func_021EE520 0x021EE520 thumb
 *   func_021E066C 0x021E066C thumb
 *   func_020307B0 0x020307B0 arm
 *   func_021ED888 0x021ED888 thumb
 *   func_021EE038 0x021EE038 thumb
 *   func_021EE364 0x021EE364 thumb
 *   func_02025DE8 0x02025DE8 thumb
 *   func_0203633C 0x0203633C arm
 *   func_021DD238 0x021DD238 thumb
 *   func_020260E4 0x020260E4 thumb
 *   func_020077B8 0x020077B8 thumb
 *   func_020076D0 0x020076D0 thumb
 *   func_021E8F50 0x021E8F50 thumb
 *   func_021E9C94 0x021E9C94 thumb
 *   func_021E9CE0 0x021E9CE0 thumb
 *   func_021E954C 0x021E954C thumb
 *   func_021EE544 0x021EE544 thumb
 *   func_021EF36C 0x021EF36C thumb
 *   func_021EA1C0 0x021EA1C0 thumb
 *   func_021E087C 0x021E087C thumb
 *   func_021EC000 0x021EC000 thumb
 *   func_021E09E0 0x021E09E0 thumb
 *   func_021DD530 0x021DD530 thumb
 *   func_021EA1E8 0x021EA1E8 thumb
 *   func_021DF040 0x021DF040 thumb
 *   func_021ECB20 0x021ECB20 thumb
 *   func_021DEFEC 0x021DEFEC thumb
 */
#include "../../matched/include/Obj00000.h"

#define WORK(p) (*(char **)((p) + 0x2C))
#define MGR(p) (*(struct WinMgr **)(WORK(p) + 0x74))
#define STEP(p) (*(int *)(WORK(p) + 0xA194))
#define STATE(p) (*(int *)((p) + 0x28))
#define LIST(p) (*(void **)(WORK(p) + 0x70))
#define TOP(p) (*(char **)(p))
#define HELD(p) (*(unsigned char *)(WORK(p) + 0xA17E))
struct Sound;
struct WinMgr;
typedef unsigned char  u8;

typedef unsigned int   u32;

typedef unsigned short u16;

extern void func_020260E4(struct Sound *obj, u8 sel);
extern void func_021EE3E4(char **p, unsigned idx);
extern void func_021ED55C(char **p, int flag);
extern void func_021EBA5C(char *p, int i);
extern void func_021DD14C(char *);
extern void func_021EF57C(struct WinMgr *mgr);
extern int func_021E8FC0(char *p, int a, int b);
extern int func_021E0190(char *p);
extern int func_021EA8CC(unsigned char *p);
extern void func_021ECB84(char *w, unsigned i);
extern void func_021EC768(char *p, unsigned i, int flag);
extern int func_021E0778(unsigned char *p);
extern void func_020061E4(unsigned se);
extern void func_021ED6E4(char **p, int v);
extern void func_021EBBC8(unsigned char *p, unsigned kind, int i);
extern void func_021EBC58(unsigned char *p, int sel, int kind, int i);
extern void func_021EF3A0(struct WinMgr *mgr);
extern int func_021E01B0(unsigned char *p);
extern void func_021EE520(char *p, unsigned idx);
extern int func_021E066C(char *p);
extern u32 func_020307B0(void *p);
extern void func_021ED888(char *w, int a);
extern void func_021EE038(char *p, int a, int b, int c);
extern void func_021EE364(char **p, int idx, int v);
extern int func_02025DE8(struct Sound *obj);
extern unsigned int func_0203633C(void);
extern void func_021DD238(char *p);
extern int func_020077B8(void *save, u32 box);
extern int func_020076D0(void *save, int *pbox, int *pslot);
extern int func_021E8F50(char *p, int v);
extern int func_021E9C94(char *p, int a, int n);
extern int func_021E9CE0(char *p, int a, int n);
extern int func_021E954C(unsigned char *p, int id, int lo, int arg);
extern void func_021EE544(char *p, unsigned int i);
extern void func_021EF36C(struct WinMgr *mgr);
extern void func_021EA1C0(void *p);
extern int func_021E087C(unsigned char *p);
extern void func_021EC000(char *w, int i, int v);
extern int func_021E09E0(char *p);
extern void func_021DD530(unsigned char *p);
extern void func_021EA1E8(char *p);
extern void func_021DF040(char *p);
extern void func_021ECB20(char *p, int f, int c);
extern void func_021DEFEC(char *p, int b);
int func_021E5914(char *p);
int func_021E594C(unsigned char *p);
int func_021E5AD4(unsigned char *p);
int func_021E5C5C(unsigned char *p);
int func_021E5DD8(u8 *p);

/*
 * Refresh the tag-derived index, re-key, arm, retag 0x18, forward,
 *   and report 0x31.
 */
int func_021E5914(char *p)
{
    func_020260E4((struct Sound *)(*(int *)(*(int *)&((struct Obj00000 *)p)->f2C + 0x70)),
                  (unsigned char)(((struct Obj00000 *)p)->f16 - 0x1e));
    func_021EE3E4((char **)p, ((struct Obj00000 *)p)->f16 - 0x1e);
    func_021ED55C((char **)p, 1);
    func_021EBA5C((char *)(*(int *)&((struct Obj00000 *)p)->f2C), 0x18);
    func_021DD14C(p);
    return 0x31;
}


/*
 * Five-step machine on the work word at 0xA194: fade out, confirm the
 * party slot (or back out to state 0x33), fade, swap, then reopen.
 */
int func_021E594C(unsigned char *p)
{
    switch (STEP(p)) {
    case 0:
        func_021EF57C(MGR(p));
        func_021ED55C((char **)p, 0);
        func_021EBA5C(WORK(p), 0x18);
        func_021DD14C((char *)p);
        STEP(p)++;
        return func_021E8FC0((char *)p, (int)func_021E0190, 0x34);
    case 1:
        switch (func_021EA8CC(p)) {
        case 0:
            p[0x18] = 1;
            func_021ECB84(WORK(p), p[0x16]);
            func_021EC768(WORK(p), 0x24, 0);
            func_021ED55C((char **)p, 1);
            func_021EE3E4((char **)p, p[0x16] - 0x1E);
            STEP(p)++;
            return func_021E8FC0((char *)p, (int)func_021E0778, 0x34);
        case 1:
            func_020061E4(0x557);
            func_021ED6E4((char **)p, 0);
            func_021EBBC8(p, 6, 0x18);
            STATE(p) = 0x33;
            STEP(p) = 0;
            return 6;
        case 2:
            func_020061E4(0x557);
            func_021ED6E4((char **)p, 0);
            func_021EBC58(p, 0, 5, 0x18);
            STATE(p) = 0x33;
            STEP(p) = 0;
            return 6;
        }
        break;
    case 2:
        func_020061E4(0x669);
        func_021EF3A0(MGR(p));
        STEP(p)++;
        return func_021E8FC0((char *)p, (int)func_021E01B0, 0x34);
    case 3:
        func_021EE520((char *)p, p[0x16] - 0x1E);
        STEP(p)++;
        return func_021E8FC0((char *)p, (int)func_021E066C, 0x34);
    case 4:
        func_020307B0(*(void **)(WORK(p) + 0x60));
        func_021ED888(WORK(p), 1);
        func_021EBC58(p, 0, 3, 0x1A);
        func_021EE038((char *)p, 0, 1, 1);
        func_021EE364((char **)p, 1, 0);
        STEP(p) = 0;
        return 0x35;
    }
    return 0x34;
}


/*
 * Party list input: L and R page the list when nothing is picked; a pick
 * of the first two rows opens the slot (or refuses it), the others page,
 * jump or cancel.
 */
int func_021E5AD4(unsigned char *p)
{
    unsigned r;
    unsigned b, a;

    r = func_02025DE8(LIST(p));
    if (r == (unsigned)-1) {
        if (func_0203633C() & 0x200) {
            func_021DD238((char *)p);
            r = 2;
        } else if (func_0203633C() & 0x100) {
            func_021DD238((char *)p);
            r = 3;
        }
    }
    switch (r) {
    case 0:
    case 1:
        func_020260E4(LIST(p), 0);
        if (func_020077B8(*(void **)(TOP(p) + 4), p[0x14]) == 0) {
            func_020061E4(0x557);
            func_021EBC58(p, 0, 4, 0x18);
            STATE(p) = 0x37;
            return 6;
        }
        a = p[0x14];
        b = 0;
        func_020076D0(*(void **)(TOP(p) + 4), (int *)(&a), (int *)(&b));
        *(unsigned char *)(WORK(p) + 0xA17E) = b;
        p[0x1A] = 0;
        p[0x17] = p[0x14];
        func_020061E4(0x54C);
        return func_021E8F50((char *)p, 0x36);
    case 2:
        func_020260E4(LIST(p), 0);
    case (unsigned)-6:
        func_020061E4(0x548);
        return func_021E9C94((char *)p, 0, 0x35);
    case 3:
        func_020260E4(LIST(p), 0);
    case (unsigned)-5:
        func_020061E4(0x548);
        return func_021E9CE0((char *)p, 0, 0x35);
    case 4:
    case (unsigned)-2:
        func_020061E4(0x551);
        *(unsigned char *)(WORK(p) + 0xA17E) = 0xFF;
        p[0x17] = p[0x14];
        p[0x1A] = 1;
        return func_021E954C(p, 6, 9, func_021E8F50((char *)p, 0x36));
    case (unsigned)-4:
        func_020061E4(0x548);
        break;
    case (unsigned)-8:
    case (unsigned)-7:
    case (unsigned)-3:
    case (unsigned)-1:
        break;
    }
    return 0x35;
}


/*
 * Eight-step machine on the work word at 0xA194 for the party swap:
 * fade, take the slot (from the held box slot at 0xA17E if any), fade
 * back and restore the box view.
 */
int func_021E5C5C(unsigned char *p)
{
    switch (STEP(p)) {
    case 0:
        if (HELD(p) == 0xFF) {
            func_021EE544((char *)p, p[0x16]);
            STEP(p) = 1;
        } else {
            func_021EE544((char *)p, HELD(p));
            STEP(p) = 4;
        }
        func_021ED888(WORK(p), 0);
        func_021EBA5C(WORK(p), 0x18);
        func_021DD14C((char *)p);
        return func_021E8FC0((char *)p, (int)func_021E066C, 0x36);
    case 1:
        func_020307B0(*(void **)(WORK(p) + 0x60));
        func_020061E4(0x669);
        func_021EF36C(MGR(p));
        STEP(p) = 2;
        return func_021E8FC0((char *)p, (int)func_021E01B0, 0x36);
    case 2:
        func_021EA1C0(p);
        STEP(p) = 6;
        return func_021E8FC0((char *)p, (int)func_021E087C, 0x36);
    case 3:
        func_020061E4(0x669);
        func_021EC000(WORK(p), 4, 0);
        func_021EF36C(MGR(p));
        STEP(p) = 7;
        return func_021E8FC0((char *)p, (int)func_021E01B0, 0x36);
    case 4:
        func_020307B0(*(void **)(WORK(p) + 0x60));
        func_021EA1C0(p);
        func_021ED6E4((char **)p, 0);
        STEP(p) = 5;
        return func_021E8FC0((char *)p, (int)func_021E09E0, 0x36);
    case 5:
        func_021DD530(p);
        func_021EA1E8((char *)p);
        func_021DF040((char *)p);
        func_021ECB20((char *)p, 1, 1);
        func_021ECB20((char *)p, 2, 0);
        STEP(p) = 3;
        break;
    case 6:
        func_021EA1E8((char *)p);
    case 7:
        p[0x18] = 0;
        func_021ED6E4((char **)p, 0);
        func_021EE038((char *)p, 0, 0, 1);
        func_021EE364((char **)p, 0, p[0x16] - 0x1E);
        func_021DEFEC((char *)p, p[0x16]);
        STEP(p) = 0;
        return 0x31;
    }
    return 0x36;
}

int func_021E5DD8(u8 *p){func_021EBA5C(*(char * *)&((struct Obj00000 *)p)->f2C,24);func_021DD14C((char *)p);func_021EBC58(p,0,3,26);func_021EE038((char *)p,0,1,1);return 53;}

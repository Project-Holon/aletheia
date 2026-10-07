/*
 * function: func_021E3C88
 * address:  0x021E3C88
 * packet:   pkt_ov170_021E3C88
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020260E0 0x020260E0 thumb
 *   func_021EF480 0x021EF480 thumb
 *   func_021DEFEC 0x021DEFEC thumb
 *   func_021EBA5C 0x021EBA5C thumb
 *   func_021DD14C 0x021DD14C thumb
 *   func_021EF68C 0x021EF68C thumb
 *   func_021ED6E4 0x021ED6E4 thumb
 *   func_021ED55C 0x021ED55C thumb
 *   func_021EF57C 0x021EF57C thumb
 *   func_021E8FC0 0x021E8FC0 thumb
 *   func_021E0190 0x021E0190 thumb
 *   func_021E01B0 0x021E01B0 thumb
 *   func_020061E4 0x020061E4 thumb
 *   func_021EBD78 0x021EBD78 thumb
 *   func_021EF3D8 0x021EF3D8 thumb
 *   func_021EF35C 0x021EF35C thumb
 *   func_021EF36C 0x021EF36C thumb
 *   func_021EC5A0 0x021EC5A0 thumb
 *   func_021ECB20 0x021ECB20 thumb
 *   func_021ED888 0x021ED888 thumb
 *   func_021EE038 0x021EE038 thumb
 *   func_021EE364 0x021EE364 thumb
 *   func_021ED544 0x021ED544 thumb
 *   func_021DD25C 0x021DD25C thumb
 *   func_021EF680 0x021EF680 thumb
 *   func_021EF69C 0x021EF69C thumb
 *   func_02026124 0x02026124 thumb
 *   func_021ED508 0x021ED508 thumb
 *   func_021ECB84 0x021ECB84 thumb
 *   func_021EA0BC 0x021EA0BC thumb
 *
 * Three-step state machine on the work word at 0xA194: restore the cursor,
 * close the prompt, then redraw the box.  The dispatch and the step-1
 * increment read the work pointer through a local loaded once at the top; with
 * the macro on both, the 0xA194 offset is CSEd into the increment and takes r4.
 */
#include "../../../matched/include/Obj14266.h"

struct WinMgr;
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Sound;
extern u8 func_020260E0(struct Sound *obj);
extern int func_021EF480(struct WinMgr *mgr);
extern void func_021DEFEC(char *p, int b);
extern void func_021EBA5C(char *w, int v);
extern void func_021DD14C(char *p);
extern void func_021EF68C(char *w);
extern void func_021ED6E4(char **p, int v);
extern void func_021ED55C(char **p, int flag);
extern void func_021EF57C(struct WinMgr *mgr);
extern int func_021E8FC0(char *p, int a, int b);
extern int func_021E0190(char *p);
extern int func_021E01B0(unsigned char *p);
extern void func_020061E4(unsigned se);
extern void func_021EBD78(char *p, int b);
extern void func_021EF3D8(struct WinMgr *mgr);
extern void func_021EF35C(struct WinMgr *mgr);
extern void func_021EF36C(struct WinMgr *mgr);
extern void func_021EC5A0(char **p, int flag);
extern void func_021ECB20(char *p, int f, int c);
extern void func_021ED888(char *w, int a);
extern void func_021EE038(char *p, int a, int b, int c);
extern void func_021EE364(char **p, int idx, int v);
extern void func_021ED544(char *p, int b);
extern unsigned func_021DD25C(void ***p, unsigned short a, int box, unsigned id, unsigned v);
extern void func_021EF680(char *w);
extern void func_021EF69C(char *w);
extern void func_02026124(struct Sound *obj, u32 idx);
extern void func_021ED508(unsigned char *p, int a, int b);
extern void func_021ECB84(char *w, unsigned i);
extern int func_021EA0BC(unsigned char *p, unsigned char i);

typedef struct {
    unsigned char lo : 4;
    unsigned char hi : 4;
} Nib;

#define WORK(p) (*(char **)((p) + 0x2C))
#define OBJ(p) (*(void **)(WORK(p) + 0x70))
#define MGR(p) (*(struct WinMgr **)(WORK(p) + 0x74))
#define STEP(p) (*(int *)(WORK(p) + 0xA194))
#define STATE(p) (*(int *)((p) + 0x28))
#define NIB(p) ((Nib *)((p) + 0x1C))
#define TOP(p) (*(char **)(p))

int func_021E3C88(unsigned char *p)
{
    char *w = WORK(p);
    switch (((struct Obj14266 *)w)->fA194) {
    case 0:
        if (NIB(p)->lo == 1) {
            p[0x17] = 0xFF;
            p[0x16] = func_020260E0(OBJ(p));
            if (func_021EF480(MGR(p)) == 1) {
                if (p[0x16] >= 6)
                    p[0x16] = 0x1E;
                else
                    p[0x16] += 0x1E;
            } else if (p[0x16] >= 0x1E) {
                p[0x16] = 0;
            }
            func_021DEFEC((char *)p, p[0x16]);
        } else {
            if (func_021EF480(MGR(p)) == 1)
                p[0x17] = 0xFF;
            else
                p[0x17] = p[0x14];
            func_021EBA5C(WORK(p), 0x18);
            func_021DD14C((char *)p);
            func_021EF68C(WORK(p));
            func_021ED6E4((char **)p, 0);
        }
        func_021ED55C((char **)p, 0);
        func_021EF57C(MGR(p));
        STEP(p)++;
        return func_021E8FC0((char *)p, (int)func_021E0190, 0x1F);
    case 1:
        if (*(int *)(TOP(p) + 0x24) == 4 && *(int *)(TOP(p) + 0x14) == 1) {
            func_020061E4(0x557);
            func_021EBD78((char *)p, 0);
            NIB(p)->lo = 0;
            STEP(p) = 0;
            STATE(p) = 0x2B;
            return 6;
        }
        (((struct Obj14266 *)w)->fA194)++;
        if (func_021EF480(MGR(p)) == 1) {
            func_021EF3D8(MGR(p));
        } else {
            func_021EF35C(MGR(p));
            func_021EF36C(MGR(p));
            func_021EC5A0((char **)p, 0);
        }
        func_020061E4(0x669);
        return func_021E8FC0((char *)p, (int)func_021E01B0, 0x1F);
    case 2:
        func_021ECB20((char *)p, 1, 0);
        func_021ED888(WORK(p), 1);
        func_021EE038((char *)p, 0, 1, 0);
        func_021EE364((char **)p, 6, p[0x16]);
        func_021ED544((char *)p, 6);
        *(int *)(WORK(p) + 0xA168) = p[0x16];
        STEP(p) = 0;
        if (NIB(p)->lo == 1) {
            if (func_021DD25C((void ***)p, p[0x16], p[0x14], 0xA9, 0) == 0)
                func_021EE038((char *)p, 0, 1, 2);
            if (*(int *)(TOP(p) + 0x24) == 4) {
                func_021EF680(WORK(p));
                func_021EF69C(WORK(p));
                func_02026124(OBJ(p), 0x27);
            }
            func_021ED508(p, 0xD, 1);
            return 0x20;
        }
        if (NIB(p)->lo == 2)
            func_021ED508(p, 0xD, 1);
        else
            func_021ED508(p, 0xE, 1);
        func_021ECB84(WORK(p), p[0x16]);
        return func_021EA0BC(p, p[0x16]);
    }
    return 0x1F;
}

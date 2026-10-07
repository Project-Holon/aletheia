/*
 * file:     btlv_effvm_p59.c
 * unit:     yes
 * function: func_021FF0F8, func_021FF134
 * address:  0x021FF0F8
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_022019F4  0x022019F4  thumb  ov094
 *   func_02015BA4  0x02015BA4  thumb
 *   func_02030EE8  0x02030EE8  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02030EAC  0x02030EAC  arm
 */
#include "../../matched/include/Obj12218.h"

struct S02030EE8;
struct Node;
typedef struct {
    void *h;                /* 0x00 */
    char pad04[0x24];
    void *task;             /* 0x28 */
    char pad2c[0x30];
} Entry;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry e[14];            /* 0x008 */
} Work;

typedef unsigned int   u32;

extern int func_022019F4(char *p, int key);
extern void func_02015BA4(void *obj, void *h);
extern u32 func_02030EE8(struct S02030EE8 *p);
extern u32 func_020307B0(void *p);
extern void func_02030EAC(struct Node *n);
void func_021FF0F8(Work *w, int key);
void func_021FF134(char *p, int a, int b);


void func_021FF0F8(Work *w, int key)
{
    int idx = func_022019F4((char *)w, key);

    func_02015BA4(w->obj, w->e[idx].h);
    w->e[idx].h = 0;
    if (w->e[idx].task != 0) {
        func_020307B0((void *)func_02030EE8(w->e[idx].task));
        func_02030EAC(w->e[idx].task);
        w->e[idx].task = 0;
    }
}


/*
 * lane O10 candidate
 */
void func_021FF134(char *p, int a, int b)
{
    ((struct Obj12218 *)p)->f538 = a;
    ((struct Obj12218 *)p)->f53C = b;
}

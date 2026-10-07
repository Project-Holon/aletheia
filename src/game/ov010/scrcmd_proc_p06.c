/*
 * file:     scrcmd_proc_p06.c
 * unit:     yes
 * function: func_0215C63C, func_0215C69C, func_0215C6F0
 * address:  0x0215C63C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_02158FB4  0x02158FB4  thumb  ov010
 *   func_02030734  0x02030734  arm
 *   func_020120B4  0x020120B4  thumb
 *   func_020113D0  0x020113D0  thumb
 *   d_021728F0     0x021728F0  data  a1
 *   func_02158FB8  0x02158FB8  thumb  ov010
 *   func_020120F0  0x020120F0  thumb
 *   func_020307B0  0x020307B0  arm
 *   func_02158FBC  0x02158FBC  thumb  ov010
 */
#include "../../matched/include/Obj00005.h"

struct IcaAnime;
struct Ctx;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct ProcHandoff {
    void *work;         /* 0x00 */
    u32 arg1;           /* 0x04 */
    u32 arg0;           /* 0x08 */
} ProcHandoff;

extern void *func_0215A5DC(void *vm);
extern void *func_0215A5F4(void *vm);
extern void *func_02158FB4(void *p);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_020120B4(struct IcaAnime *p, u32 id, void *a, void *b);
extern void func_020113D0(char *p, int val);
extern u32 func_02158FB8(void *p);
extern u32 func_020120F0(const struct Ctx *p);
extern u32 func_020307B0(void *p);
extern int func_02158FBC();
void func_0215C63C(void *c, void *vm, u32 ovId, const void *proc, void *work, u32 arg0, u32 arg1);
int func_0215C69C(int a0, int a1);
int func_0215C6F0(int a0, int a1);
extern const char d_021728F0[];


/*
 * Starts a child process from an overlay on behalf of a script command:
 * allocates the 12-byte hand-off record (work pointer and two words),
 * launches the process over the work with func_020120B4, parks the record in the
 * script's slot and waits on func_0215C69C.
 */
void func_0215C63C(void *c, void *vm, u32 ovId, const void *proc, void *work, u32 arg0, u32 arg1)
{
    void *sys;
    void **slot;
    ProcHandoff *h;

    sys = func_0215A5DC(vm);
    slot = func_02158FB4(func_0215A5F4(vm));
    h = func_02030734(4, sizeof(ProcHandoff), 1, d_021728F0, 0x8B);
    h->work = work;
    h->arg1 = arg1;
    h->arg0 = arg0;
    func_020120B4(sys, ovId, (void *)proc, work);
    *slot = h;
    func_020113D0(c, (int)func_0215C69C);
}


int func_0215C69C(int a0, int a1)
{
    int t4;
    int t5;
    void *t6;

t4 = a1 + 0;
a0 = t4 + 0;
    t6 = func_0215A5DC((void *)a0);
loc_0215C6A6:
a0 = t4 + 0;
    a0 = (int)func_0215A5F4((void *)a0); /* int-typed on purpose: pointer local changes codegen */
loc_0215C6AE:
t4 = a0 + 0;
    a0 = func_02158FB8((void *)a0);
loc_0215C6B4:
t5 = a0 + 0;
    a0 = func_020120F0(t6);
loc_0215C6BC:
    if (a0 == 0) goto loc_0215C6C4;
loc_0215C6C0:
a0 = 0;
    return a0;
loc_0215C6C4:
a1 = *(int *)&((struct Obj00005 *)t5)->f8;
    if (a1 == 0) goto loc_0215C6D0;
loc_0215C6CA:
a0 = t5 + 0;
    a0 = ((int (*)())a1)(a0);
loc_0215C6CE:
    goto loc_0215C6E4;
loc_0215C6D0:
a0 = *(int *)&((struct Obj00005 *)((char *)t5))->f0;
    if (a0 == 0) goto loc_0215C6DA;
loc_0215C6D6:
    func_020307B0((void *)a0);
loc_0215C6DA:
a0 = *(int *)&((struct Obj00005 *)t5)->f4;
    if (a0 == 0) goto loc_0215C6E4;
loc_0215C6E0:
    func_020307B0((void *)a0);
loc_0215C6E4:
a0 = t4 + 0;
    a0 = func_02158FBC(a0);
loc_0215C6EA:
a0 = 1;
    return a0;}


int func_0215C6F0(int a0, int a1)
{
    void *v0;

a0 = a1 + 0;
    v0 = func_0215A5F4((void *)a0);
loc_0215C6F8:
    a0 = func_02158FBC(v0);
loc_0215C6FC:
a0 = 1;
    return a0;}

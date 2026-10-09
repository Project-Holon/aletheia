/*
 * file:     script_work_p04.c
 * unit:     yes
 * function: func_021590D4, func_021590F4, func_021590FC, func_02159104, func_0215910C, func_02159114, func_0215911C, func_02159124, func_02159130, func_02159144, func_02159168, func_02159190, func_02159198, func_021591B4, func_02159204, func_02159240, func_02159244, func_02159248, func_02159254, func_02159260, func_02159284, func_0215929C, func_021592A8, func_021592C0
 * address:  0x021590D4
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
 *   func_02158FD0 0x02158FD0 thumb ov010
 *   func_02082A60 0x02082A60 arm
 *   func_020307B0 0x020307B0 arm
 *   d_02172BA0 0x02172BA0 data a4
 *   func_02082A7C 0x02082A7C arm
 *   d_021705F0     0x021705F0  data  ov010
 *   func_0215A5F4 0x0215A5F4 thumb ov010
 *   func_0215A5DC 0x0215A5DC thumb ov010
 *   func_020122C0 0x020122C0 thumb
 *   func_020124E8 0x020124E8 thumb
 *   func_02011290  0x02011290  thumb
 *   func_0215A690  0x0215A690  thumb  ov010
 *   func_0215A684   0x0215A684  thumb  ov010
 *   func_02011330   0x02011330  thumb
 *   func_020113D0   0x020113D0  thumb
 *   func_0201134C  0x0201134C  thumb
 *   func_020113B4  0x020113B4  thumb
 *   func_020113C4  0x020113C4  thumb
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_02011398  0x02011398  thumb
 */
#include "../../matched/include/Obj17639.h"
#include "../../matched/include/Obj17640.h"
#include "../../matched/include/Obj18756.h"
#include "../../matched/include/Obj18757.h"
#include "../../matched/include/Obj17641.h"
#include "../../matched/include/Obj17642.h"
#include "../../matched/include/Obj00005.h"

struct Desc;
struct Obj;
struct S;
struct ScriptVm;
struct Stream;
struct Ring;
typedef unsigned int   u32;

typedef unsigned char  u8;

typedef unsigned short u16;

typedef signed short   s16;

typedef enum { BIT = 1 } Mask;

typedef int (*Fn)(int *, int *);

struct S { int _0, _4, _8; int c; int idx; int n; };

typedef struct TaskWork { void *system; void *vm; void *owner; int c; int idx; int n; } TaskWork;

extern int func_02158FD0(int a0, u32 a1, int a2);
extern void func_02082A60(const void *, void *, unsigned int);
extern u32 func_020307B0(void *p);
extern void func_02082A7C(int, void *, int);
extern void *func_0215A5F4(void *p);
extern void *func_0215A5DC(void *a0);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern struct ScriptVm *func_02011290(struct ScriptVm *vm);
extern int func_0215A690(char *);
extern u16 func_02011330(struct Stream *s);
extern void func_0215A684(int *p, unsigned short v);
extern void func_020113D0(char *p, int val);
extern int func_0201134C();
extern int func_020113B4();
extern u32 func_020113C4(struct Ring *r);
extern void *func_0215A5E4(void *a0);
extern unsigned int func_02159B10(void *, void *);
extern u32 func_02011398(struct Ring *r);
void func_021590D4(void *a, void *b, int a2);
/* * generated: lane O24 (ov010 leaf/wrapper sweep) * * Shifted-index word-field setter, same shape as its getter partner. * * Addresses are Black-image addresses. --region ov010 is required: this * address is only ov010 in the overlay that defines it. * * Verified with: * python tools/match.py one --src src/matched/func_021590F4.c \ * --func func_021590F4 --addr 0x021590F4 --region ov010 --cc dsi/1.1p1 --thumb */ void func_021590F4(void *p, u32 v);
/* * generated: lane O24 (ov010 leaf/wrapper sweep) * * Shifted-index word-field getter: the field table sits at a byte offset built from a small constant shifted left, so the leaf folds it to one immediate. * * Addresses are Black-image addresses. --region ov010 is required: this * address is only ov010 in the overlay that defines it. * * Verified with: * python tools/match.py one --src src/matched/func_021590FC.c \ * --func func_021590FC --addr 0x021590FC --region ov010 --cc dsi/1.1p1 --thumb */ u32 func_021590FC(void *p);
/* * Store of a word at +0x140. * Addresses are Black-image addresses. */ void func_02159104(u8 *p, u32 v);
/* * Unlabelled leaf, blocker of ov021 func_021D1A54/021D1A74/021D1AB0: reads the word at +0x140. * Overlay choice, ov009 and ov010 share this window; ov009 holds ARM code here, * ov010 holds this Thumb routine, and the ov021 callers already name ov010 * (ov010 is the overlay resident with ov021). * * Addresses are Black-image addresses. */ u32 func_0215910C(void *p);
/* * generated: lane O24 (ov010 leaf/wrapper sweep) * * Shifted-index word-field setter, same shape as its getter partner. * * Addresses are Black-image addresses. --region ov010 is required: this * address is only ov010 in the overlay that defines it. * * Verified with: * python tools/match.py one --src src/matched/func_02159114.c \ * --func func_02159114 --addr 0x02159114 --region ov010 --cc dsi/1.1p1 --thumb */ void *func_02159114(void *p, u32 v);
/* * generated: lane O24 (ov010 leaf/wrapper sweep) * * Shifted-index word-field getter: the field table sits at a byte offset built from a small constant shifted left, so the leaf folds it to one immediate. * * Addresses are Black-image addresses. --region ov010 is required: this * address is only ov010 in the overlay that defines it. * * Verified with: * python tools/match.py one --src src/matched/func_0215911C.c \ * --func func_0215911C --addr 0x0215911C --region ov010 --cc dsi/1.1p1 --thumb */ u32 func_0215911C(void *p);
char *func_02159124(char *p, int i);
void func_02159130(void);
/* * Input evidence: ov010 callers 0215F278/02164946 pass 11/7; * ov021 flag setters pass fixed IDs 0..13 (e.g. 021B5316 passes 0, * 021AEE1E passes 13). No traced setter call supplies a negative ID. * These primary paths make 1 << n defined; no new bound is assumed. */ void func_02159144(int n);
/* * lever: enum-typed BIT keeps the shifted mask opaque; plain int folds * the complement to mvns and shortens the body by four bytes. * Input evidence: ov010 sites 0215F298/021649D6/02164A14 pass 11/7/7; * ov021 flag clearers pass fixed IDs 0..13 (021B52D8 passes 0, * 021AF03A passes 13; 021B10C8 forwards its saved literal 3). * On these traced paths n is nonnegative and below 14 before the shift. */ void func_02159168(int n);
/* * generated: lane O24 (ov010 leaf/wrapper sweep) * * Tail call through a pool word and `bx r3`: a two-instruction * thunk into func_02159198, the shape of the arm9 copy. * (docs/idioms/tail-call-is-a-pool-word-and-bx.md) * * Addresses are Black-image addresses. --region ov010 is required: this * address is only ov010 in the overlay that defines it. * * Verified with: * python tools/match.py one --src src/matched/func_02159190.c \ * --func func_02159190 --addr 0x02159190 --region ov010 --cc dsi/1.1p1 --thumb */ int func_02159190(int a0);
/* * Input evidence: direct callers are 0215914C, 02159170, 021591D0. * Set/clear callers use fixed nonnegative IDs 0..13; the 02159190 tail * forwarder has constant-ID callers in ov010/ov021/ov082 (021F5756: 3). * The task caller's index starts at zero (0215922E), advances by one * (021591EA), and sees a NULL callback at table index 14 (02170628) * before the test call. Its fourteen callbacks leave task+0x10 alone; * state updates use only task+0x0c. Thus shifted IDs are 0..13 on the * traced primary paths; no invented guard or domain was added. */ int func_02159198(int n);
/* * volatile: 0x021591F2 re-reads idx after the store at 0x021591EC. */ int func_021591B4(int a, int b, struct S *p);
void *func_02159204(void *vm);
/* * generated: lane O24 (ov010 leaf/wrapper sweep) * * Constant leaf: `movs r0, #N; bx lr`. * * Addresses are Black-image addresses. --region ov010 is required: this * address is only ov010 in the overlay that defines it. * * Verified with: * python tools/match.py one --src src/matched/func_02159240.c \ * --func func_02159240 --addr 0x02159240 --region ov010 --cc dsi/1.1p1 --thumb */ int func_02159240(void);
/* * generated: lane O24 (ov010 leaf/wrapper sweep) * * Constant leaf: `movs r0, #N; bx lr`. * * Addresses are Black-image addresses. --region ov010 is required: this * address is only ov010 in the overlay that defines it. * * Verified with: * python tools/match.py one --src src/matched/func_02159244.c \ * --func func_02159244 --addr 0x02159244 --region ov010 --cc dsi/1.1p1 --thumb */ int func_02159244(void);
int func_02159248(struct ScriptVm *a0);
/* * Recursive MATCH unblocker: tail-call thunk at the pool word 0x0215A691 * (func_0215A690). Matched so the ABS32 site in func_02159260 attests as * `matched`. */ void func_02159254(char *a0, char *a1);
/* * Unblocked by matching func_02159254 (ov010, EXACT; itself unblocked by * func_0215A690). The ABS32 pool word +0x20 now attests as `matched`. * * Registers the second argument under the key the first argument yields, * and installs the in-overlay handler the pool names. */ int func_02159260(void *a0, void *a1);
int func_02159284(int a0, int a1, int a2);
int func_0215929C(struct Ring *a0);
int func_021592A8(int a0, int a1);
int func_021592C0(int a0, int a1);
extern int d_02172BA0;
extern Fn d_021705F0[];



void func_021590D4(void *a, void *b, int a2)
{
    void *p = (void *)func_02158FD0((int)a, 0x8020, a2);
    func_02082A60(b, p, 0x7e);
    func_020307B0(b);
}




/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Shifted-index word-field setter, same shape as its getter partner.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021590F4.c \
 *       --func func_021590F4 --addr 0x021590F4 --region ov010 --cc dsi/1.1p1 --thumb
 */
void func_021590F4(void *p, u32 v) { ((struct Obj17639 *)p)->f13C = v; }




/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Shifted-index word-field getter: the field table sits at a byte offset built from a small constant shifted left, so the leaf folds it to one immediate.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021590FC.c \
 *       --func func_021590FC --addr 0x021590FC --region ov010 --cc dsi/1.1p1 --thumb
 */
u32 func_021590FC(void *p) { return ((struct Obj17640 *)p)->f13C; }




/*
 * Store of a word at +0x140.
 * Addresses are Black-image addresses.
 */
void func_02159104(u8 *p, u32 v)
{
    ((struct Obj18756 *)p)->f140 = v;
}




/*
 * Unlabelled leaf, blocker of ov021 func_021D1A54/021D1A74/021D1AB0: reads the word at +0x140.
 * Overlay choice, ov009 and ov010 share this window; ov009 holds ARM code here,
 * ov010 holds this Thumb routine, and the ov021 callers already name ov010
 * (ov010 is the overlay resident with ov021).
 *
 * Addresses are Black-image addresses.
 */
u32 func_0215910C(void *p)
{
    return ((struct Obj18757 *)p)->f140;
}




/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Shifted-index word-field setter, same shape as its getter partner.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02159114.c \
 *       --func func_02159114 --addr 0x02159114 --region ov010 --cc dsi/1.1p1 --thumb
 */
void *func_02159114(void *p, u32 v) { ((struct Obj17641 *)p)->f144 = v;  return p; }




/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Shifted-index word-field getter: the field table sits at a byte offset built from a small constant shifted left, so the leaf folds it to one immediate.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0215911C.c \
 *       --func func_0215911C --addr 0x0215911C --region ov010 --cc dsi/1.1p1 --thumb
 */
u32 func_0215911C(void *p) { return ((struct Obj17642 *)p)->f144; }


char *func_02159124(char *p, int i)
{
    return p + 0x44 + i * 0x1c;
}


void func_02159130(void)
{
    func_02082A7C(0, &d_02172BA0, 4);
}


/*
 * Input evidence: ov010 callers 0215F278/02164946 pass 11/7;
 * ov021 flag setters pass fixed IDs 0..13 (e.g. 021B5316 passes 0,
 * 021AEE1E passes 13). No traced setter call supplies a negative ID.
 * These primary paths make 1 << n defined; no new bound is assumed.
 */
void func_02159144(int n)
{
    if (n < 14 && !func_02159198(n)) d_02172BA0 |= 1 << n;
}


/*
 * lever: enum-typed BIT keeps the shifted mask opaque; plain int folds
 * the complement to mvns and shortens the body by four bytes.
 * Input evidence: ov010 sites 0215F298/021649D6/02164A14 pass 11/7/7;
 * ov021 flag clearers pass fixed IDs 0..13 (021B52D8 passes 0,
 * 021AF03A passes 13; 021B10C8 forwards its saved literal 3).
 * On these traced paths n is nonnegative and below 14 before the shift.
 */
void func_02159168(int n)
{
    if (n < 14 && func_02159198(n)) {
        Mask bit = BIT;
        d_02172BA0 &= (bit << n) ^ -1;
    }
}



/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Tail call through a pool word and `bx r3`: a two-instruction
 * thunk into func_02159198, the shape of the arm9 copy.
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md)
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02159190.c \
 *       --func func_02159190 --addr 0x02159190 --region ov010 --cc dsi/1.1p1 --thumb
 */
int func_02159190(int a0)
{

    return func_02159198(a0);
}


/*
 * Input evidence: direct callers are 0215914C, 02159170, 021591D0.
 * Set/clear callers use fixed nonnegative IDs 0..13; the 02159190 tail
 * forwarder has constant-ID callers in ov010/ov021/ov082 (021F5756: 3).
 * The task caller's index starts at zero (0215922E), advances by one
 * (021591EA), and sees a NULL callback at table index 14 (02170628)
 * before the test call. Its fourteen callbacks leave task+0x10 alone;
 * state updates use only task+0x0c. Thus shifted IDs are 0..13 on the
 * traced primary paths; no invented guard or domain was added.
 */
int func_02159198(int n)
{
    if (n >= 14) return 0;
    if ((d_02172BA0 >> n) & 1) return 1;
    return 0;
}



/*
 * volatile: 0x021591F2 re-reads idx after the store at 0x021591EC.
 */
int func_021591B4(int a, int b, struct S *p)
{
    int *pc = &p->c;
    int *pi = &p->idx;
    do {
        Fn fn = d_021705F0[p->idx];
        if (fn == 0)
            return 1;
        if (func_02159198(p->idx)) {
            if (fn((int *)p, pc)) {
                (*pi)++;
                p->c = 0;
            } else {
                return 0;
            }
        } else {
            (*pi)++;
            p->c = 0;
        }
    } while (*(volatile int *)&p->idx < p->n);
    return 1;
}


void *func_02159204(void *vm)
{
    void *owner = func_0215A5F4(vm);
    void *system = func_0215A5DC(vm);
    void *task = func_020122C0(system, 0, (void *)func_021591B4, sizeof(TaskWork));
    TaskWork *p = func_020124E8(task);
    p->system = system;
    p->vm = vm;
    p->owner = owner;
    p->idx = 0;
    p->c = 0;
    p->n = 15;
    return task;
}



/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Constant leaf: `movs r0, #N; bx lr`.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02159240.c \
 *       --func func_02159240 --addr 0x02159240 --region ov010 --cc dsi/1.1p1 --thumb
 */
int func_02159240(void) { return 0; }



/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Constant leaf: `movs r0, #N; bx lr`.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02159244.c \
 *       --func func_02159244 --addr 0x02159244 --region ov010 --cc dsi/1.1p1 --thumb
 */
int func_02159244(void) { return 0; }



int func_02159248(struct ScriptVm *a0)
{

    a0 = (struct ScriptVm *)func_02011290(a0);
loc_0215924E:
a0 = (struct ScriptVm *)1;
    return (int)a0;}



/*
 * Recursive MATCH unblocker: tail-call thunk at the pool word 0x0215A691
 * (func_0215A690). Matched so the ABS32 site in func_02159260 attests as
 * `matched`.
 */
void func_02159254(char *a0, char *a1)
{
    func_0215A690(a1);
    (void)a0;
}



/*
 * Unblocked by matching func_02159254 (ov010, EXACT; itself unblocked by
 * func_0215A690). The ABS32 pool word +0x20 now attests as `matched`.
 *
 * Registers the second argument under the key the first argument yields,
 * and installs the in-overlay handler the pool names.
 */
int func_02159260(void *a0, void *a1)
{
    func_0215A684(a1, func_02011330(a0));
    func_020113D0(a0, (int)func_02159254);

    return 1;
}



int func_02159284(int a0, int a1, int a2)
{
    int t4;

t4 = a0 + 0;
    a0 = func_0201134C(a0);
loc_0215928C:
a2 = a0 + 0;
a1 = *(int *)&((struct Obj00005 *)t4)->f14;
a0 = t4 + 0;
a1 = a1 + a2;
    a0 = func_020113B4(a0, a1, a2);
loc_02159298:
a0 = 0;
    return a0;}



int func_0215929C(struct Ring *a0)
{

    a0 = (struct Ring *)func_020113C4(a0);
loc_021592A2:
a0 = 0;
    return (int)a0;}



int func_021592A8(int a0, int a1)
{
    int t4;
    int t5;
    void *v0;

t4 = a1 + 0;
t5 = a0 + 0;
a0 = t4 + 0;
    v0 = func_0215A5E4((void *)a0);
loc_021592B4:
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = func_02159B10((void *)a0, (void *)a1);
loc_021592BC:
a0 = 0;
    return a0;}



int func_021592C0(int a0, int a1)
{
    int t4;
    int t5;

t5 = a0 + 0;
t4 = a1 + 0;
    a0 = func_02011398((struct Ring *)a0);
loc_021592CA:
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = func_02159B10((void *)a0, (void *)a1);
loc_021592D2:
a0 = 0;
    return a0;}

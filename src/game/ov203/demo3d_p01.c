/*
 * file:     demo3d_p01.c
 * unit:     yes
 * function: func_021BDA40, func_021BDB20
 * address:  0x021BDA40
 * region:   ov203
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02034AC4 0x02034AC4 arm
 *   func_0203064C 0x0203064C arm
 *   func_0203159C 0x0203159C arm
 *   func_02082BCC 0x02082BCC arm
 *   func_021BDDD8 0x021BDDD8 thumb ov203
 *   func_02045B38 0x02045B38 arm
 *   func_0201C440 0x0201C440 thumb
 *   func_02040588 0x02040588 arm
 *   func_020434DC 0x020434DC arm
 *   func_02043598 0x02043598 arm
 *   func_021BE160 0x021BE160 thumb ov203
 *   func_021BDCC0 0x021BDCC0 thumb ov203
 *   func_021BE62C 0x021BE62C thumb ov203
 *   func_021BE948 0x021BE948 thumb ov203
 *   func_021BDC20 0x021BDC20 thumb ov203
 *   ov067_id 0x00000043 data a1
 *   func_02045C04 0x02045C04 arm
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 *   func_02034A5C 0x02034A5C arm
 *   func_021BDD18 0x021BDD18 thumb ov203
 *   func_021BE4B4 0x021BE4B4 thumb ov203
 *   func_021BDE98 0x021BDE98 thumb ov203
 */
#include "../../matched/include/Obj06663.h"
#include "../../matched/include/Obj06664.h"

struct Obj0203159C;
struct MsgBank;
struct Cfg;
struct Ctx;
struct PrintSys;
struct Rec;
struct S020315D4;
typedef unsigned char u8;

typedef unsigned short u16;

typedef struct Work { u16 heap, pad; void *arg; int state; void *view, *str, *msg, *model, *ctx; int tail[3]; } Work;

typedef unsigned int   u32;

extern int func_02034AC4(int);
extern void func_0203064C(unsigned, unsigned, unsigned);
extern void *func_0203159C(struct Obj0203159C *obj, unsigned int size, unsigned int heap);
extern void func_02082BCC(void *, int, unsigned);
extern void *func_021BDDD8(unsigned, void *, unsigned);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern unsigned func_0201C440(void *);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_020434DC(unsigned, unsigned);
extern void func_02043598(unsigned, unsigned);
extern struct Ctx *func_021BE160(void *owner, struct Cfg *cfg, u16 heap);
extern void *func_021BDCC0(int, void *, void *, unsigned);
extern u32 func_021BE62C(char *p);
extern void func_021BE948(void *, int, u8 *, u8 *);
extern int func_021BDC20(u8, unsigned, unsigned);
extern void func_02023F98(u32 mask);
extern void func_021BDD18(char *);
extern u32 func_02045C04(struct Rec *rec);
extern void func_0201C4C0(struct PrintSys *p);
extern void func_021BE4B4(char *ctx);
extern void func_021BDE98(char *ctx);
extern void func_020315D4(struct S020315D4 *p);
extern void func_020306F0(u32 heap);
extern void func_02034A5C(int);
int func_021BDA40(void *manager, int unused, u8 *p);
int func_021BDB20(void *a, void *b, void *c, char *work);
extern const char ov067_id[];

int func_021BDA40(void *manager, int unused, u8 *p)
{
    Work *w;
    u8 width, height;
    int delta;
    unsigned one = 1;
    unsigned heap = 0x6c;
    func_02034AC4((int)ov067_id);
    func_0203064C(1, 0x6c, 0x130000);
    w = func_0203159C(manager, sizeof(Work), 0x6c);
    func_02082BCC(w, 0, sizeof(Work));
    w->heap = heap;
    w->arg = p;
    w->view = func_021BDDD8(1, ((struct Obj06663 *)p)->f4, w->heap);
    w->msg = func_02045B38(0, 2, 0x41, w->heap);
    w->str = (void *)func_0201C440((void *)w->heap);
    func_02040588(6, 0);
    func_02040588(4, 0);
    func_02040588(3, 0);
    func_02040588(2, 0);
    func_02040588(1, 0);
    func_020434DC(0x10, 0);
    func_02043598(0x10, 0);
    w->model = func_021BE160(w->view, (struct Cfg *)p, w->heap);
    w->ctx = func_021BDCC0(*(int *)&((struct Obj06663 *)p)->f4, w->view, w->model, w->heap);
    delta = func_021BE62C(w->model) - ((struct Obj06663 *)p)->f8;
    func_021BE948(((struct Obj06663 *)p)->f4, 0, &width, &height);
    if (delta > height) func_021BDC20(*(unsigned *)&((struct Obj06663 *)p)->f4, one, w->heap);
    return 1;
}

int func_021BDB20(void *a, void *b, void *c, char *work)
{
    func_02023F98(3);
    func_021BDD18(*(char * *)&((struct Obj06664 *)work)->f1C);
    func_02045C04(((struct Obj06664 *)work)->f14);
    func_0201C4C0(((struct Obj06664 *)work)->f10);
    func_021BE4B4(((struct Obj06664 *)work)->f18);
    func_021BDE98(((struct Obj06664 *)work)->fC);
    func_020315D4(a);
    func_020306F0(0x6c);
    func_02034A5C((int)ov067_id);
    return 1;
}

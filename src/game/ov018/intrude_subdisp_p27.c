/*
 * file:     intrude_subdisp_p27.c
 * unit:     yes
 * function: func_0218111C, func_02181140, func_021811E4
 * address:  0x0218111C
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0201232C  0x0201232C  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_02082D44  0x02082D44  arm
 *   func_020124E4  0x020124E4  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_02012138  0x02012138  thumb
 *   func_02158344  0x02158344  thumb ov010
 *   func_02012944  0x02012944  thumb
 *   func_0201F02C  0x0201F02C  thumb
 *   func_0201F184  0x0201F184  thumb
 *   func_0217F3C4  0x0217F3C4  thumb ov018
 *   func_0217F40C  0x0217F40C  thumb ov018
 *   func_0217F420  0x0217F420  thumb ov018
 *   func_0217FE38  0x0217FE38  thumb ov018
 *   d_0218389A     0x0218389A  data ov018 a2
 *   func_0218123C  0x0218123C  thumb  ov018
 */
#include "../../matched/include/Obj05940.h"
#include "../../matched/include/Obj05941.h"

struct Obj;
struct Ctx;
struct WordSet;
typedef unsigned int u32;

typedef struct {
    void *unk_00;
    u32 unk_04;
    u32 unk_08;
    void *unk_0c;
    void *unk_10;
} Obj;

typedef unsigned char  u8;

typedef unsigned short u16;

typedef signed int     s32;

typedef struct {
    u8 pad00[0x40];
    u8 f40;
    u8 pad41[0x17];
    u16 f58;
} Ov018Src;

extern void func_0201232C(char *p, int a1, int a2);
extern void *func_020124E8(struct Obj *p);
extern void func_02082D44(const void *, void *, u32);
void *func_020124E4(struct Obj *p);
void *func_020120F4(const struct Ctx *p);
unsigned int func_02012138(const struct Ctx *x);
int func_02158344(int a0);
u8 *func_02012944(void *p);
void func_0201F02C(struct WordSet *p, u32 i, void *a);
void func_0201F184(struct WordSet *p, u32 i, s32 v);
void func_0217F3C4(u8 *p, int a);
int func_0217F40C(u8 *p);
int func_0217F420(void);
void func_0217FE38(void *m, u8 *obj);
void func_0218123C(void);
void func_0218111C(Obj *task, const void *src);
int func_02181140(int x, int *st, u8 *obj);
void func_021811E4(void *a, Ov018Src *src);
extern u16 d_0218389A[];


/*
 * Callback pointer is copied unchanged by func_0201232C into task +4;
 * its legacy int parameter represents the same full-word payload.
 */
void func_0218111C(Obj *task, const void *src)
{
    void *dst;

    func_0201232C((char *)task, (int)func_02181140, 0xA0);
    dst = func_020124E8((struct Obj *)task);
    func_02082D44(src, dst, 0x98);
}


int func_02181140(int x, int *st, u8 *obj)
{
    int v = (int)func_020124E4((struct Obj *)x);
    void *m;

    m = (void *)func_02158344((int)func_02012138((const struct Ctx *)v));
    switch (*st) {
    case 0:
        func_0201F02C((struct WordSet *)(((struct Obj05940 *)obj)->f10), 0, (void *)((int)(obj + 0x78)));
        func_0201F02C((struct WordSet *)(((struct Obj05940 *)obj)->f10), 1, func_02012944(func_020120F4((const struct Ctx *)v)));
        func_0201F184((struct WordSet *)(((struct Obj05940 *)obj)->f10), 2, ((struct Obj05940 *)obj)->f58);
        func_0217F3C4(obj + 0x10, d_0218389A[obj[0x42]]);
        *st = *st + 1;
        break;
    case 1:
        if (func_0217F40C(obj + 0x10) == 1) {
            *st = 2;
        }
        break;
    case 2:
        if (func_0217F420() == 1) {
            *st = 3;
        }
        break;
    case 3:
        func_0217FE38(m, obj);
        return 1;
    }
    return 0;
}


void func_021811E4(void *a, Ov018Src *src)
{
    void *r;
    u8 *t;

    r = func_020124E4(a);
    func_0201232C(a, (int)func_0218123C, 0xB0);
    t = func_020124E8(a);
    func_02082D44(src, t, 0x98);
    ((struct Obj05941 *)t)->fA4 = 0;
    ((struct Obj05941 *)t)->f9C = r;
    t[0xA0] = src->f40;
    t[0xA1] = src->f58;
    t[0xA2] = 2;
}

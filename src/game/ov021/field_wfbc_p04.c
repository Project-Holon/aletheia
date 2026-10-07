/*
 * file:     field_wfbc_p04.c
 * unit:     yes
 * function: func_02193B68, func_02193BC4
 * address:  0x02193B68
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02193EB4  0x02193EB4  thumb  ov021
 *   func_02193F34  0x02193F34  thumb  ov021
 *   func_0200846C  0x0200846C  thumb
 *   func_020084A0  0x020084A0  thumb
 *   func_020084D4  0x020084D4  thumb
 *   func_0200852C  0x0200852C  thumb
 *   func_0201F02C  0x0201F02C  thumb
 *   func_020307B0  0x020307B0  arm
 *   func_02193EFC  0x02193EFC  thumb  ov021
 *   func_02186764  0x02186764  thumb
 *   func_02193EE8  0x02193EE8  thumb  ov021
 */
#include "../../matched/include/Obj19617.h"

struct V;
struct E50;
struct Sub0200852CObj;
struct WordSet;
typedef unsigned short u16;

typedef unsigned int   u32;

typedef unsigned char  u8;

typedef signed short   s16;

typedef signed char    s8;

extern void func_02193EB4(struct V *v);
extern struct E50 *func_02193F34(struct V *v, u32 key);
extern void *func_0200846C(int a0);
extern void func_020084A0(struct Sub0200852CObj *);
extern u32 func_020084D4(u32 value, void *dst);
extern void func_0200852C(struct Sub0200852CObj *obj, u32 value);
extern void func_0201F02C(struct WordSet *p, u32 i, void *a);
extern u32 func_020307B0(void *p);
extern void func_02186764(u8 *);
extern void func_02193EE8(struct V *v);
extern u8 *func_02193EFC(void *, u32);
void func_02193B68(void *a, int b, int c, int d, u16 e);
void func_02193BC4(void *a, u32 b);


void func_02193B68(void *a, int b, int c, int d, u16 e)
{
    char *q;
    int h;

    func_02193EB4(a);
    q = (char *)func_02193F34(a, c);
    h = (int)func_0200846C((u16)((e & 0x7fff) | 0x8000));
    func_020084A0((struct Sub0200852CObj *)h);
    func_020084D4(h, q + 0x38);
    func_0200852C((struct Sub0200852CObj *)h, ((struct Obj19617 *)q)->f48);
    func_0201F02C((struct WordSet *)b, d, (void *)h);
    func_020307B0((void *)h);
}


/*
 * Promoted from src/pending/: the blocker this file named is filed.
 * func_02186764 (0x02186764) is a matched manifest entry, so the `matched`
 * class attests the bl site here and every concrete byte plus every
 * relocation field reproduces.
 *
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
void func_02193BC4(void *a, u32 b)
{
func_02193EB4(a);
func_02186764((func_02193EFC(a, b) + 52));
func_02193EE8(a);
}

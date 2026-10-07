/*
 * file:     field_wfbc_data_local_p12.c
 * unit:     yes
 * function: func_0218741C, func_0218748C, func_02187508
 * address:  0x0218741C
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02045CAC  0x02045CAC  arm
 *   func_0201F250  0x0201F250  thumb
 *   func_0219129C  0x0219129C  thumb  ov021
 *   d_02187E04     0x02187E04  data  ov020  a2
 *   func_02191388  0x02191388  thumb  ov021
 *   func_020362DC  0x020362DC  arm
 *   func_02190BE4  0x02190BE4  thumb  ov021
 *   func_02190C78  0x02190C78  thumb  ov021
 *   func_021909BC  0x021909BC  thumb  ov021
 *   func_021912D8  0x021912D8  thumb  ov021
 *   func_021912F8  0x021912F8  thumb  ov021
 */
#include "../../matched/include/Obj00128.h"

struct Ent;
struct MsgBank;
struct WordSet;
struct Handle;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int   u32;

extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern struct Ent *func_0219129C(u8 *base, int idx, u32 c, u32 d, u32 f, u32 g);
extern u32 func_02191388(u32 *a);
extern u32 func_020362DC(void);
extern u32 *func_02190BE4(u16 *a, u32 b);
extern int func_02190C78(struct Handle *h);
extern int func_021909BC(void *a);
extern int func_021912D8(u32 a);
extern int func_021912F8(int);
void func_0218741C(char *p, int a1, int *out, int a3);
void func_0218748C(char *p, int a1, int *out, int a3, u16 a4);
int func_02187508(char *p);
extern u16 d_02187E04[];


void func_0218741C(char *p, int a1, int *out, int a3)
{
    int i;

    func_02045CAC((struct MsgBank *)(((struct Obj00128 *)p)->f18),
                  (u16)(a1 + (d_02187E04[(*(u16 **)(p + 0x48))[1]] + ((struct Obj00128 *)p)->f4C * 8)),
                  (void *)(((struct Obj00128 *)p)->f24));
    func_0201F250((struct WordSet *)(((struct Obj00128 *)p)->f1C), (void *)(((struct Obj00128 *)p)->f20), (void *)(((struct Obj00128 *)p)->f24));
    i = 0;
    *(int *)&((struct Obj00128 *)p)->f10 = (int)func_0219129C((u8 *)(((struct Obj00128 *)p)->fC), 2, (u32)(p + 0x34), ((struct Obj00128 *)p)->f20, i, i);
    *out = 0x10;
    ((struct Obj00128 *)p)->f4E = a3;
    ((struct Obj00128 *)p)->f52 = 0;
    ((struct Obj00128 *)p)->f54 = 1;
    ((struct Obj00128 *)p)->f55 = 0;
}


void func_0218748C(char *p, int a1, int *out, int a3, u16 a4)
{
    int i;

    func_02045CAC((struct MsgBank *)(((struct Obj00128 *)p)->f18),
                  (u16)(a1 + (d_02187E04[(*(u16 **)(p + 0x48))[1]] + ((struct Obj00128 *)p)->f4C * 8)),
                  (void *)(((struct Obj00128 *)p)->f24));
    func_0201F250((struct WordSet *)(((struct Obj00128 *)p)->f1C), (void *)(((struct Obj00128 *)p)->f20), (void *)(((struct Obj00128 *)p)->f24));
    i = 0;
    *(int *)&((struct Obj00128 *)p)->f10 = (int)func_0219129C((u8 *)(((struct Obj00128 *)p)->fC), 2, (u32)(p + 0x34), ((struct Obj00128 *)p)->f20, i, i);
    *out = 0x10;
    ((struct Obj00128 *)p)->f4E = a3;
    ((struct Obj00128 *)p)->f50 = a4;
    ((struct Obj00128 *)p)->f52 = 0;
    ((struct Obj00128 *)p)->f54 = 1;
    ((struct Obj00128 *)p)->f55 = 1;
}


int func_02187508(char *p)
{
    int r;

    switch (((struct Obj00128 *)p)->f52) {
    case 0:
        if (func_02191388((u32 *)(*(int *)&((struct Obj00128 *)p)->f10)) == 0)
            break;
        ((struct Obj00128 *)p)->f52 = ((struct Obj00128 *)p)->f52 + 1;
        break;
    case 1:
        if ((func_020362DC() & 0xf3) == 0)
            break;
        if (((struct Obj00128 *)p)->f55 == 0)
            ((struct Obj00128 *)p)->f52 = 4;
        else
            ((struct Obj00128 *)p)->f52 = 2;
        break;
    case 2:
        *(int *)&((struct Obj00128 *)p)->f14 = (int)func_02190BE4((u16 *)(((struct Obj00128 *)p)->fC), 0);
        ((struct Obj00128 *)p)->f52 = ((struct Obj00128 *)p)->f52 + 1;
        break;
    case 3:
        r = func_02190C78((struct Handle *)(*(int *)&((struct Obj00128 *)p)->f14));
        if (r == 2)
            break;
        if (r == 0)
            ((struct Obj00128 *)p)->f54 = 1;
        else
            ((struct Obj00128 *)p)->f54 = 0;
        ((struct Obj00128 *)p)->f52 = 4;
        func_021909BC((void *)(*(int *)&((struct Obj00128 *)p)->f14));
        *(int *)&((struct Obj00128 *)p)->f14 = 0;
        break;
    case 4:
        func_021912D8(*(int *)&((struct Obj00128 *)p)->f10);
        ((struct Obj00128 *)p)->f52 = ((struct Obj00128 *)p)->f52 + 1;
        break;
    case 5:
        if (func_021912F8(*(int *)&((struct Obj00128 *)p)->f10) != 0) {
            *(int *)&((struct Obj00128 *)p)->f10 = 0;
            return 1;
        }
        break;
    }
    return 0;
}

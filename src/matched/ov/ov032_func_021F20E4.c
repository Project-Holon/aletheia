/*
 * function: func_021F20E4
 * address:  0x021F20E4
 * packet:   pkt_ov032_021F20E4
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F20E4 0x021F20E4 thumb
 *   func_0201C6C4 0x0201C6C4 thumb
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_02045770 0x02045770 arm
 *   func_02041B6C 0x02041B6C arm
 *   TCBL_DeleteTask 0x02031194 arm
 */
#include "../include/Obj06136.h"
#include "../include/Obj06137.h"
#include "../include/Obj20448.h"

typedef unsigned char u8;
typedef unsigned int u32;

struct Cfg;
struct Descriptor;
struct PrintSys;
extern u32 func_0201C6C4(struct PrintSys *p, void *v);
struct Descriptor;
extern void BMP_WIN_TransferChars(struct Descriptor *a);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void *func_02045770(struct Descriptor *p);
extern void func_02041B6C(u32 bit);
struct TcblNode;
extern void TCBL_DeleteTask(struct TcblNode *n);

void func_021F20E4(void *task, char *q)
{
    u8 *s;
    u32 v;
    int *r;

    v = ((struct Obj20448 *)(*(char * *)&((struct Obj06136 *)q)->f8))->fB4;
    s = *(u8 * *)&((struct Obj06136 *)q)->f4 + 8;
    if (s[4] != 0) {
        if (func_0201C6C4((struct PrintSys *)v, (void *)((u32)func_02045770((struct Descriptor *)((struct Obj06137 *)s)->f0))) == 0) {
            BMP_WIN_TransferChars((struct Descriptor *)((struct Obj06137 *)s)->f0);
            s[4] = 0;
        }
    }
    if (s[4] == 0) {
        BMP_WIN_MakeScreen((struct Cfg *)(**(u32 * *)&((struct Obj06136 *)q)->f4));
        func_02041B6C(func_02045730((struct Descriptor *)(**(u32 * *)&((struct Obj06136 *)q)->f4)));
        r = *(int * *)&((struct Obj06136 *)q)->fC;
        if (r != 0)
            (*r)--;
        TCBL_DeleteTask(task);
    }
}

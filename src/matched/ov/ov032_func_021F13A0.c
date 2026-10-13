/*
 * function: func_021F13A0
 * address:  0x021F13A0
 * packet:   pkt_ov032_021F13A0
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F13A0 0x021F13A0 thumb
 *   func_021F0F44 0x021F0F44 thumb
 *   func_021F0F30 0x021F0F30 thumb
 *   func_021F1144 0x021F1144 thumb
 *   func_021F1418 0x021F1418 thumb
 *   TCBL_AddTask 0x020311B8 arm
 *   TCBL_GetWork 0x02031290 arm
 *   MI_CpuFill8 0x02082BCC arm
 */
#include "../include/Obj00007.h"
#include "../include/Obj06134.h"

typedef unsigned char u8;
typedef unsigned int u32;

extern char *func_021F0F44(char *this, u8 id);
extern void func_021F0F30(char *e, int a, int b);
extern void func_021F1144(u8 *p, u8 *q, void *r, int mode, int skip, int t);
struct S02030FB4;
extern void func_021F1418(void *h, u8 *t);
extern void *TCBL_AddTask(u32 a, void *fn, u32 sz, u32 a3);
extern void *TCBL_GetWork(struct S02030FB4 *p);
extern void MI_CpuFill8(void *p, int v, int n);

void func_021F13A0(char *this, int a, int b, int c, int s)
{
    char *e;
    u8 *r;

    e = func_021F0F44(this, 0xff);
    if (e != 0) {
        r = TCBL_GetWork(TCBL_AddTask(*(u32 *)&((struct Obj00007 *)this)->fA0, (void *)func_021F1418, 0x18, 0));
        MI_CpuFill8(r, 0, 0x18);
        *(char * *)&((struct Obj06134 *)r)->fC = this;
        r[1] = c;
        *(char * *)&((struct Obj06134 *)r)->f8 = e;
        ((struct Obj06134 *)r)->f4 = s;
        *(int * *)&((struct Obj06134 *)r)->f14 = (int *)(this + 0xa8);
        ((struct Obj00007 *)this)->fA8 = ((struct Obj00007 *)this)->fA8 + 1;
        func_021F0F30(e, b, 0);
        func_021F1144((u8 *)this, (u8 *)e, (void *)a, s, 0, (int)(r + 0x10));
    }
}

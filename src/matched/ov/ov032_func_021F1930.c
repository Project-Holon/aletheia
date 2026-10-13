/*
 * function: func_021F1930
 * address:  0x021F1930
 * packet:   pkt_ov032_021F1930
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F1930 0x021F1930 thumb
 *   func_021F0B80 0x021F0B80 thumb
 *   func_021F178C 0x021F178C thumb
 *   func_021F0BA8 0x021F0BA8 thumb
 *   TCBL_DeleteTask 0x02031194 arm
 */
#include "../include/Obj02751.h"
#include "../include/Obj20431.h"

typedef unsigned char u8;
typedef unsigned int u32;

extern void func_021F0B80(char *p, void *t, unsigned a);
extern void func_021F178C(char *this, u8 a, int *p);
extern int func_021F0BA8(u8 *s);
struct TcblNode;
extern void TCBL_DeleteTask(struct TcblNode *n);

void func_021F1930(void *task, u8 *s)
{
    if (((struct Obj02751 *)s)->f4 != 0)
        return;
    switch (s[0]) {
    case 0:
        func_021F0B80(*(char * *)&((struct Obj02751 *)s)->f8, (void *)(((struct Obj20431 *)(*(char * *)&((struct Obj02751 *)s)->f8))->f120), (unsigned int)(s + 4));
        s[0]++;
        return;
    case 1:
        func_021F178C(*(char * *)&((struct Obj02751 *)s)->f8, 0, (int *)(s + 4));
        s[0]++;
        return;
    case 2:
        if (func_021F0BA8(s + 1) != 0) {
            func_021F178C(*(char * *)&((struct Obj02751 *)s)->f8, 1, (int *)(s + 4));
            s[0]++;
        }
        return;
    default:
        (**(int * *)&((struct Obj02751 *)s)->fC)--;
        TCBL_DeleteTask(task);
        return;
    }
}

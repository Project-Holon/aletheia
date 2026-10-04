/*
 * function: func_021BD768
 * address: 0x021BD768
 * packet: pkt_ov216_021BD768
 * region: ov216
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BD668 0x021BD668 thumb ov216
 *   func_021BD73C 0x021BD73C thumb ov216
 *   sub_02031194 0x02031194 arm
 */
#include "../include/Obj03375.h"
typedef unsigned char u8;
struct TcblNode;
extern void func_021BD668(char *owner, int direction, int *counter);
extern int func_021BD73C(char *);
extern void sub_02031194(struct TcblNode *);
void func_021BD768(struct TcblNode *task, void *data)
{
    char *p = data;
    switch (((struct Obj03375 *)p)->f0) {
    case 0:
        func_021BD668(((struct Obj03375 *)p)->f8, 0, (int *)(p + 4));
        ++((struct Obj03375 *)p)->f0;
        break;
    case 1:
        if (((struct Obj03375 *)p)->f4 == 0)
            ++((struct Obj03375 *)p)->f0;
        break;
    case 2:
        if (func_021BD73C(p) == 0) {
            func_021BD668(((struct Obj03375 *)p)->f8, 1, (int *)(p + 4));
            ++((struct Obj03375 *)p)->f0;
        }
        break;
    case 3:
        if (((struct Obj03375 *)p)->f4 != 0)
            break;
    default:
        --**(int * *)&((struct Obj03375 *)p)->fC;
        sub_02031194(task);
        break;
    }
}

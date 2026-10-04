/*
 * function: func_021F1EAC
 * address:  0x021F1EAC
 * packet:   pkt_ov032_021F1EAC
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F1EAC 0x021F1EAC thumb
 *   func_021F1080 0x021F1080 thumb
 *   func_021F0ED0 0x021F0ED0 thumb
 *   func_02031194 0x02031194 arm
 */
#include "../include/Obj02113.h"
#include "../include/Obj20437.h"
#include "../include/Obj20438.h"

typedef unsigned char u8;
typedef unsigned int u32;

extern void func_021F1080(char *p, char *q, int r, int t);
extern void func_021F0ED0(char *q, int a);
struct TcblNode;
extern void func_02031194(struct TcblNode *n);

void func_021F1EAC(void *task, u8 *s)
{
    if (s[0] == 0) {
        u8 c = s[1];
        s[1] = c - 1;
        if (c != 0)
            return;
        if (((struct Obj02113 *)s)->fC == 1 || ((struct Obj02113 *)s)->fC == 0x18 || ((struct Obj02113 *)s)->fC == 0x31) {
            func_021F1080((char *)(((struct Obj02113 *)s)->f10), (char *)(*(u32 *)&((struct Obj02113 *)s)->f8), 1, 0);
            s[0]++;
            return;
        }
    } else {
        if (((struct Obj20437 *)(*(char * *)&((struct Obj02113 *)s)->f8))->f2C != 0)
            return;
    }
    ((struct Obj20438 *)(*(char * *)&((struct Obj02113 *)s)->f8))->f30 = 0;
    func_021F0ED0(*(char * *)&((struct Obj02113 *)s)->f8, 0);
    func_02031194(task);
}

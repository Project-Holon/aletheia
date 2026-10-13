/*
 * function: func_021BDAD8
 * address:  0x021BDAD8
 * packet:   pkt_021BDAD8
 * region:   ov216
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02045770  0x02045770  arm
 *   func_0201C6C4  0x0201C6C4  thumb
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   TCBL_DeleteTask  0x02031194  arm
 */
#include "../include/Obj06711.h"
#include "../include/Obj25799.h"

typedef unsigned char u8;

struct Descriptor;
extern void *func_02045770(struct Descriptor *x);
typedef unsigned int   u32;
struct PrintSys;
struct TcblNode;
extern u32 func_0201C6C4(struct PrintSys *p, void *v);
extern void BMP_WIN_TransferChars(struct Descriptor *x);
extern void TCBL_DeleteTask(struct TcblNode *n);

void func_021BDAD8(int a, int **b)
{
    u8   *s = (u8 *)b[0] + 8;
    int   q = ((struct Obj25799 *)((char *)b[1]))->f12C;

    if (s[4]) {
        if (func_0201C6C4((struct PrintSys *)q, (void *)((int)func_02045770((struct Descriptor *)((struct Obj06711 *)s)->f0))) == 0) {
            BMP_WIN_TransferChars((struct Descriptor *)((struct Obj06711 *)s)->f0);
            s[4] = 0;
        }
    }
    if (s[4] == 0) {
        if (b[2])
            --*(int *)b[2];
        TCBL_DeleteTask((struct TcblNode *)a);
    }
}

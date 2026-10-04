/*
 * function: func_021FA758
 * address: 0x021FA758
 * packet: pkt_ov186_021FA758
 * region: ov186
 * status: EXACT
 * symbols:
 *   func_021FAEE4 0x021FAEE4 thumb
 *   func_021FAD18 0x021FAD18 thumb
 *   func_021FAD74 0x021FAD74 thumb
 *   func_021FD73C 0x021FD73C thumb
 *   func_021FA920 0x021FA920 thumb
 */
#include "../include/Obj06629.h"
typedef unsigned char  u8;
extern void func_021FAEE4(char *p, int *out);
extern void func_021FAD18(char *ctx, int mode, const int *target);
extern int func_021FAD74(char *ctx);
extern void func_021FD73C(int *p, int v);
extern void func_021FA920(int *task, int *state, u8 *ctx);
void func_021FA758(void *p, int *state, unsigned char *ctx)
{
    int i, ready;
    int values[2];
    switch (*state) {
    case 0:
        for (i = 0; i < ctx[0x39]; i++) {
            func_021FAEE4(*(char * *)&((struct Obj06629 *)ctx)->f40 + i * 0x44, values);
            values[1] = 0xe0;
            func_021FAD18(*(char * *)&((struct Obj06629 *)ctx)->f40 + i * 0x44, 4, values);
        }
        *state = 1;
        break;
    case 1:
        ready = 1;
        for (i = 0; i < ctx[0x39]; i++)
            ready &= func_021FAD74(*(char * *)&((struct Obj06629 *)ctx)->f40 + i * 0x44);
        if (ready) *state = 2;
        break;
    case 2: func_021FD73C(p, (int)func_021FA920); break;
    }
}

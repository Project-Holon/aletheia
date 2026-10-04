/*
 * function: func_0217B594
 * address: 0x0217B594
 * packet: pkt_ov176_0217B594
 * region: ov176
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 *   func_0217D398 0x0217D398 thumb ov176
 *   func_0217D434 0x0217D434 thumb ov176
 *   func_0217D44C 0x0217D44C thumb ov176
 *   func_0217D410 0x0217D410 thumb ov176
 *   func_021E8AA0 0x021E8AA0 thumb ov177
 *   func_0217B4A0 0x0217B4A0 thumb ov176
 */
#include "../include/Obj02221.h"
typedef struct { int mode; int a,b,c,d,e,f,g; } Config;
extern void func_02082BCC(void *,int,int);
extern int func_0217D398(Config *,int);
extern void func_0217D434(int *p);
extern int func_0217D44C(int *p);
extern void func_0217D410(int *p);
extern void func_021E8AA0(int *p, int v);
extern void func_0217B4A0(int p, unsigned *state, int *q);
void func_0217B594(int p, int *state, char *q)
{
    Config config;
    switch (*state) {
    case 0:
        func_02082BCC(&config, 0, 32);
        config.mode = 0;
        config.a = ((struct Obj02221 *)q)->f18;
        config.b = ((struct Obj02221 *)q)->f1C;
        config.c = ((struct Obj02221 *)q)->f20;
        config.d = ((struct Obj02221 *)q)->f24;
        config.e = ((struct Obj02221 *)q)->f28;
        config.f = ((struct Obj02221 *)q)->f2C;
        config.g = ((struct Obj02221 *)q)->f30;
        ((struct Obj02221 *)q)->f38 = func_0217D398(&config, ((struct Obj02221 *)q)->f34);
        (*state)++;
        break;
    case 1:
        func_0217D434((int *)(((struct Obj02221 *)q)->f38));
        if (func_0217D44C((int *)(((struct Obj02221 *)q)->f38))) (*state)++;
        break;
    case 2:
        func_0217D410((int *)(((struct Obj02221 *)q)->f38));
        func_021E8AA0((int *)p, (int)func_0217B4A0);
        break;
    }
}

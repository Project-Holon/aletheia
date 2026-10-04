/*
 * function: func_021E7BD0
 * address: 0x021E7BD0
 * packet: pkt_ov170_021E7BD0
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021DEF98 0x021DEF98 thumb ov170
 *   func_021DEFEC 0x021DEFEC thumb ov170
 *   func_021ED544 0x021ED544 thumb ov170
 *   func_021ED508 0x021ED508 thumb ov170
 *   func_021E9968 0x021E9968 thumb ov170
 *   func_021E9938 0x021E9938 thumb ov170
 *   func_021E99B0 0x021E99B0 thumb ov170
 *   func_021E9B74 0x021E9B74 thumb ov170
 *   func_021E22B8 0x021E22B8 thumb ov170
 */
#include "../include/Obj00000.h"
#include "../include/Obj23912.h"
extern void func_021DEF98(unsigned char *p, int a, int b);
extern void func_021DEFEC(unsigned char *p, int b);
extern void func_021ED544(unsigned char *p, int b);
extern void func_021ED508(unsigned char *p, int a, int b);
extern int func_021E9968(unsigned char *p);
extern int func_021E9938(unsigned char *p);
extern int func_021E99B0(unsigned char *p);
extern int func_021E9B74(unsigned char *p);
extern int func_021E22B8(int p);
#define WORK(p) (*(char **)((p) + 0x2C))
#define STEP(p) (*(int *)(WORK(p) + 0xA194))
typedef struct { unsigned char pad[0x1C]; unsigned char lo:4; unsigned char hi:4; } Flags;
int func_021E7BD0(unsigned char *p)
{
    if (p[0x17] != 0xFF)
        func_021DEF98(p, p[0x17], p[0x16]);
    else
        func_021DEFEC(p, p[0x16]);
    func_021ED544(p, 6);
    if (((Flags *)p)->lo == 0)
        func_021ED508(p, 0xE, 1);
    else
        func_021ED508(p, 0xD, 1);
    switch (((struct Obj23912 *)(*(char * *)&((struct Obj00000 *)p)->f0))->f24) {
    case 0:
        *(int *)(WORK(p) + 0xA198) = func_021E9968(p);
        break;
    case 1:
        *(int *)(WORK(p) + 0xA198) = func_021E9938(p);
        break;
    case 2:
        *(int *)(WORK(p) + 0xA198) = func_021E99B0(p);
        break;
    case 4:
        *(int *)(WORK(p) + 0xA198) = func_021E9B74(p);
        break;
    case 3:
        break;
    }
    return func_021E22B8((int)p);
}

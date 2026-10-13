/*
 * function: func_021F1B94
 * address:  0x021F1B94
 * packet:   pkt_ov032_021F1B94
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F1B94 0x021F1B94 thumb
 *   d_021F352C 0x021F352C data ov032 a1
 *   func_021F0A98 0x021F0A98 thumb ov032
 *   func_021F0B80 0x021F0B80 thumb ov032
 *   func_021F178C 0x021F178C thumb ov032
 *   func_021F029C 0x021F029C thumb ov032
 *   func_021F0C04 0x021F0C04 thumb ov032
 *   func_021F0B64 0x021F0B64 thumb ov032
 *   func_021F0E04 0x021F0E04 thumb ov032
 *   func_021F0C70 0x021F0C70 thumb ov032
 *   func_021F253C 0x021F253C thumb ov032
 *   func_021F0D38 0x021F0D38 thumb ov032
 *   func_021F0CF8 0x021F0CF8 thumb ov032
 *   func_021F0B10 0x021F0B10 thumb ov032
 *   func_021F05E8 0x021F05E8 thumb ov032
 *   TCBL_DeleteTask 0x02031194 arm
 */
#include "../include/Obj00007.h"
#include "../include/Obj01037.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u8 d_021F352C[];
struct TcblNode;
extern void func_021F0A98(char *p, unsigned a);
extern void func_021F0B80(char *p, void *t, unsigned a);
extern void func_021F178C(char *p, u8 a, int *s);
extern void func_021F029C(char *p, int a);
extern void func_021F0C04(char *p, int flag);
extern void func_021F0B64(char *p);
extern void func_021F0E04(char *p, unsigned a);
extern int func_021F0C70(char *p, int flag);
extern void func_021F253C(char *p, int v);
extern void func_021F0D38(char *p);
extern int func_021F0CF8(char *p, int i);
extern void func_021F0B10(char *p, int a, int b);
extern void func_021F05E8(u8 *p, int a, u32 b);
extern void TCBL_DeleteTask(struct TcblNode *n);

void func_021F1B94(void *h, u8 *t)
{
    char *p;
    int r;

    p = *(char * *)&((struct Obj01037 *)t)->f1C;
    if (((struct Obj01037 *)t)->f8 > 0)
        return;
    switch (t[0]) {
    case 0:
        func_021F0A98(p, d_021F352C[t[3]]);
        func_021F0B80(p, (void *)(*(u32 *)&((struct Obj00007 *)p)->f11C), (unsigned int)((int *)(t + 8)));
        t[0]++;
        break;
    case 1:
        func_021F178C(p, 0, (int *)(t + 8));
        t[0]++;
        break;
    case 2:
        func_021F029C(p, 1);
        func_021F0C04(p, 0);
        func_021F0B64(p);
        func_021F0E04(p, 0);
        t[0]++;
        break;
    case 3:
        r = func_021F0C70(p, 0);
        if (r < 0)
            break;
        t[5] = r;
        switch (t[5]) {
        case 0:
            func_021F253C(p, 6);
            t[0] = 3;
            break;
        case 1:
            p[0x7f] = ((struct Obj01037 *)t)->fC;
            func_021F253C(p, 5);
            t[0] = 4;
            break;
        case 2:
            t[0] = 5;
            break;
        }
        break;
    case 4:
        if (*(u8 *)&((struct Obj00007 *)p)->f7F != 0x30) {
            p[0x7f] = 0x30;
            t[0] = 3;
            break;
        }
        func_021F0D38(p);
        t[0] = 6;
        break;
    case 5:
        if (func_021F0CF8(p, t[5]) == 0)
            break;
        t[0]++;
        break;
    case 6:
        func_021F0B10(p, 1, (int)((int *)(t + 8)));
        func_021F0E04(p, 1);
        func_021F178C(p, 1, (int *)(t + 8));
        t[0]++;
        break;
    default:
        func_021F05E8((u8 *)p, 4, 0);
        func_021F029C(p, 0);
        (**(int * *)&((struct Obj01037 *)t)->f20)--;
        TCBL_DeleteTask(h);
        break;
    }
}

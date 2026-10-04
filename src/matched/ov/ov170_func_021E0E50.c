/*
 * function: func_021E0E50
 * address: 0x021E0E50
 * packet: pkt_ov170_021E0E50
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021EC01C 0x021EC01C thumb ov170
 *   func_021ED108 0x021ED108 thumb ov170
 *   func_021EBFA8 0x021EBFA8 thumb ov170
 *   func_021EC000 0x021EC000 thumb ov170
 *   func_021E066C 0x021E066C thumb ov170
 *   func_021E0190 0x021E0190 thumb ov170
 */
#include "../include/Obj08235.h"
extern int func_021EC01C(char *w, int i);
extern void func_021ED108(char *w, int on);
extern void func_021EBFA8(char *w, int i, int v);
extern void func_021EC000(char *w, int i, int v);
extern int func_021E066C(char *p);
extern int func_021E0190(char *p);
#define WORK(p) (*(char **)((p) + 0x2C))
int func_021E0E50(char *p)
{
    char *s;
    int a;
    int b;
    s = WORK(p) + 0x58;
    switch (((struct Obj08235 *)s)->fC) {
    case 0:
        if (func_021EC01C(WORK(p), 10) == 1) {
            func_021ED108(WORK(p), 1);
            func_021EBFA8(WORK(p), 10, 2);
        }
        (((struct Obj08235 *)s)->fC)++;
    case 1:
        a = func_021E066C(p);
        b = func_021E0190(p);
        if (a == 0 && b == 0)
            (((struct Obj08235 *)s)->fC)++;
        break;
    case 2:
        if (func_021EC01C(WORK(p), 10) == 1) {
            func_021ED108(WORK(p), 0);
            func_021EC000(WORK(p), 10, 0);
        }
        ((struct Obj08235 *)s)->fC = 0;
        return 0;
    }
    return 1;
}

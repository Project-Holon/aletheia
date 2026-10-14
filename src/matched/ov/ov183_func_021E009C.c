/*
 * function: func_021E009C
 * address: 0x021E009C
 * packet: pkt_ov183_021E009C
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * lever: Repeat the reset store in both result arms, with return 1 shared after them; hoisting the store removes the branch at 0x021E00C8.
 * symbols:
 *   BR_POKESEARCH_Main 0x021FFC9C thumb ov186
 *   BR_POKESEARCH_GetResult 0x021FFE90 thumb ov186
 *   func_021E03B0 0x021E03B0 thumb ov183
 */
#include "../include/Obj00277.h"
#include "../include/Obj00351.h"
typedef unsigned short u16;
extern int BR_POKESEARCH_Main(char *);
extern int BR_POKESEARCH_GetResult(int *, u16 *);
extern void func_021E03B0(char *, char *, int);
int func_021E009C(char *p, char *q)
{
    u16 out;
    int result;
    BR_POKESEARCH_Main(*(char * *)&((struct Obj00277 *)p)->f1C);
    result = BR_POKESEARCH_GetResult(*(int * *)&((struct Obj00277 *)p)->f1C, &out);
    if (result) {
        if (result == 2) {
            ((struct Obj00351 *)q)->f14 = out;
            func_021E03B0(p, q, 1);
            ((struct Obj00277 *)p)->f50 = 0;
        } else {
            ((struct Obj00277 *)p)->f50 = 0;
        }
        return 1;
    }
    return 0;
}

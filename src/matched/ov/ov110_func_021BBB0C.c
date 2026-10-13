/*
 * function: func_021BBB0C
 * address: 0x021BBB0C
 * packet: pkt_ov110_021BBB0C
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BAC4C 0x021BAC4C thumb ov110
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   PRINTSYS_QUE_IsExistTarget 0x0201C6C4 thumb
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   func_021BC7DC 0x021BC7DC thumb ov110
 *   func_02040588 0x02040588 arm
 */
#include "../include/Obj05289.h"
typedef unsigned char u8;
extern unsigned func_021BAC4C(u8 *);
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
typedef unsigned int   u32;
struct PrintSys;
extern u32 PRINTSYS_QUE_IsExistTarget(struct PrintSys *p, void *v);
struct Descriptor;
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern int func_021BC7DC(u8 *p);
extern void func_02040588(unsigned char which, unsigned char enable);
int func_021BBB0C(u8 *p, int a)
{
    unsigned owner;
    int ready;
    int result;
    owner = func_021BAC4C(*(u8 * *)&((struct Obj05289 *)p)->f0);
    ready = 1;
    if (a) {
        if (p[0xa0]) {
            if (PRINTSYS_QUE_IsExistTarget((struct PrintSys *)owner, (void *)((unsigned)BMP_WIN_GetBmp(((struct Obj05289 *)p)->f9C))) == 0) {
                BMP_WIN_TransferChars(((struct Obj05289 *)p)->f9C);
                p[0xa0] = 0;
            }
        }
        ready = p[0xa0] == 0 ? 1 : 0;
    }
    result = func_021BC7DC(p + 0x38);
    if (ready && result) {
        if (a == 0) func_02040588(6, 0);
        return 1;
    }
    return 0;
}

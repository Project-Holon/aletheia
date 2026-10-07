/*
 * function: func_021FCE64
 * address: 0x021FCE64
 * packet: pkt_ov135_021FCE64
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   tbl_02203D14 0x02203D14 data a4
 *   func_021F4EA0 0x021F4EA0 thumb ov135
 *   func_021F4FF4 0x021F4FF4 thumb ov135
 *   func_021FFD1C 0x021FFD1C thumb ov135
 */
#include "../../../matched/include/Obj06515.h"
typedef signed short s16;
extern int (*const tbl_02203D14[])(void *);
extern void func_021F4EA0(void *, int, int);
extern void func_021F4FF4(unsigned, unsigned, unsigned);
extern void func_021FFD1C(void *, int, int);
int func_021FCE64(char *p)
{
    int r;
    int i;
    r = tbl_02203D14[*(int *)(p + 0x28)](p);
    for (i = 0; i < 8; i++) {
        func_021F4EA0(*(void **)(p + i * 4 + 0xd0c), *(s16 *)(p + i * 4 + 0xec4), *(s16 *)(p + i * 4 + 0xec6) + ((struct Obj06515 *)p)->fD3C + 0x20);
    }
    func_021F4FF4(((struct Obj06515 *)p)->fD08, 0xd0, 0x3a - ((struct Obj06515 *)p)->fD3C);
    func_021FFD1C(p, ((struct Obj06515 *)p)->fD4, ((struct Obj06515 *)p)->fD3C);
    return r;
}

/*
 * function: func_021BA4AC
 * address: 0x021BA4AC
 * packet: pkt_ov181_021BA4AC
 * region: ov181
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045CAC 0x02045CAC arm
 *   func_0201D304 0x0201D304 thumb
 *   func_0201C7D0 0x0201C7D0 thumb
 *   d_021BAB40 0x021BAB40 data a2
 */
#include "../include/Obj01071.h"
#include "../include/Obj06590.h"
typedef unsigned int   u32;
struct MsgBank;
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
struct StrObj;
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern void func_0201C7D0(void *, short, short, void *, void *, unsigned short);
extern const unsigned short d_021BAB40[];
void func_021BA4AC(char *p, unsigned char *q, void *s, int y)
{
    int x;
    unsigned w;
    func_02045CAC(((struct Obj06590 *)p)->fB0, ((struct Obj01071 *)q)->f0, ((struct Obj06590 *)p)->fB4);
    if (((struct Obj01071 *)q)->fA == 0) {
        x = ((struct Obj01071 *)q)->fC + ((struct Obj01071 *)q)->fE;
    } else if (((struct Obj01071 *)q)->fA == 1) {
        w = func_0201D304(((struct Obj06590 *)p)->fB4, (u32)(*(void **)(p + q[9] * 4 + 0xa8)), 0);
        x = ((struct Obj01071 *)q)->fC + ((struct Obj01071 *)q)->fE - w;
    } else if (((struct Obj01071 *)q)->fA == 2) {
        w = func_0201D304(((struct Obj06590 *)p)->fB4, (u32)(*(void **)(p + q[9] * 4 + 0xa8)), 0);
        x = ((struct Obj01071 *)q)->fC + ((struct Obj01071 *)q)->fE - w / 2;
    }
    func_0201C7D0(s, x, y, ((struct Obj06590 *)p)->fB4, *(void **)(p + q[9] * 4 + 0xa8), d_021BAB40[q[8]]);
}

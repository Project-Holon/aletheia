/*
 * function: func_021C2CB0
 * address: 0x021C2CB0
 * packet: pkt_ov217_021C2CB0
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * Tail: 021C2CEE..021C2CF0 is two zero alignment bytes.
 * Callee 02021F64's legacy Rgb555 aggregate input reads only its low
 * stack halfword; scalar u16 preserves the original caller's str word.
 * symbols:
 *   PALANM_BlendColors 0x02021F64 thumb
 *   func_021C2A28 0x021C2A28 thumb ov217
 *   func_021C2D88 0x021C2D88 thumb ov217
 */
#include "../include/Obj00115.h"
struct Rgb555 {
    unsigned short r : 5;
    unsigned short g : 5;
    unsigned short b : 5;
    unsigned short pad : 1;
};
extern void PALANM_BlendColors(unsigned short *, unsigned short *, unsigned int, int, unsigned short);
extern void func_021C2A28(void *);
extern int func_021C2D88(char *);
void func_021C2CB0(char *p)
{
    int weight = ((((struct Obj00115 *)p)->f1C >> 2) & 1) == 0 ? 0 : 9;
    PALANM_BlendColors(*(unsigned short * *)&((struct Obj00115 *)p)->fC, *(unsigned short * *)&((struct Obj00115 *)p)->f8, ((struct Obj00115 *)p)->f10, weight, ((struct Obj00115 *)p)->f12);
    if (++((struct Obj00115 *)p)->f1C > 20) {
        func_021C2A28(p);
        func_021C2D88(p);
    }
}

/*
 * function: func_021DC720
 * address: 0x021DC720
 * packet: pkt_ov119_021DC720
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: 021DC726 reads hardware DISPCNT 0x04001000 before updating it.
 * symbols:
 *   func_021E64B8 0x021E64B8 thumb ov119
 *   func_021E3230 0x021E3230 thumb ov119
 *   func_021DD588 0x021DD588 thumb ov119
 *   func_021DF8E0 0x021DF8E0 thumb ov119
 *   func_021DD9DC 0x021DD9DC thumb ov119
 *   func_021E4570 0x021E4570 thumb ov119
 *   func_021E36D8 0x021E36D8 thumb ov119
 *   func_021E69A4 0x021E69A4 thumb ov119
 *   func_021DF7D0 0x021DF7D0 thumb ov119
 *   func_021E2680 0x021E2680 thumb ov119
 *   func_021E4888 0x021E4888 thumb ov119
 *   func_021E2438 0x021E2438 thumb ov119
 *   func_021B639C 0x021B639C thumb ov067
 *   func_021E48E0 0x021E48E0 thumb ov119
 *   func_0204B1CC 0x0204B1CC arm
 *   func_021E11A8 0x021E11A8 thumb ov119
 *   func_021DD174 0x021DD174 thumb ov119
 *   func_021E293C 0x021E293C thumb ov119
 *   func_021E3F08 0x021E3F08 thumb ov119
 *   func_021E4000 0x021E4000 thumb ov119
 *   func_021E57A4 0x021E57A4 thumb ov119
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj10357.h"
extern void func_021E64B8(void *),func_021E3230(void *),func_021DD588(void *),func_021DF8E0(void *),func_021E4570(void *);
extern void func_021DD9DC(unsigned char *),func_021E36D8(void *,int),func_021E69A4(char *),func_021DF7D0(void *),func_021E2680(char *),func_021E4888(char *),func_021E2438(char *,int);
extern void func_021B639C(void *),func_021E48E0(char *),func_0204B1CC(void *),func_021E11A8(char *),func_021DD174(char *),func_021E293C(void *,int),func_021E3F08(char *),func_021E4000(char *),func_021E57A4(int),func_020307B0(void *);
#define P(o) (*(void **)(p+(o)))
void func_021DC720(char *p)
{
    int i;
    *(volatile unsigned *)0x04001000 &= ~0xe000;
    func_021E64B8(p);func_021E3230(p);func_021DD588(p);func_021DF8E0(p);func_021DD9DC((unsigned char *)p);func_021E4570(p);
    func_021E36D8(p,1);func_021E69A4(p);func_021DF7D0(p);func_021E2680(p);func_021E4888(p);
    func_021E2438(p,0);func_021E2438(p,1);
    if(P(0x9c0)) {func_021B639C(P(0x9c0));P(0x9c0)=0;}
    func_021E48E0(p);
    if(P(0x9c4)) {func_0204B1CC(P(0x9c4));P(0x9c4)=0;}
    func_021E11A8(p);func_021DD174(p);
    func_021E293C(p,0);func_021E293C(p,1);func_021E3F08(p);func_021E4000(p);func_021E57A4((int)p);
    if(P(0x818)) {func_020307B0(P(0x818));P(0x818)=0;}
    for(i=0;i<4;i++) {
        char *q=p+i*4;
        if(((struct Obj10357 *)q)->f85C) {func_020307B0(((struct Obj10357 *)q)->f85C);((struct Obj10357 *)q)->f85C=0;}
    }
}

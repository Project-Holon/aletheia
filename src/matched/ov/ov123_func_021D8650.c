/*
 * function: func_021D8650
 * address: 0x021D8650
 * packet: pkt_ov123_021D8650
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D6EE0 0x021D6EE0 thumb ov123
 *   func_021D83A4 0x021D83A4 thumb ov123
 *   func_021D85C4 0x021D85C4 thumb ov123
 *   func_021D8624 0x021D8624 thumb ov123
 *   func_021D8448 0x021D8448 thumb ov123
 *   func_021D8958 0x021D8958 thumb ov123
 *   func_021D6FF0 0x021D6FF0 thumb ov123
 *   func_021D8520 0x021D8520 thumb ov123
 */
#include "../include/Obj00063.h"
#include "../include/Obj22971.h"
#include "../include/Obj22972.h"
#include "../include/Obj22973.h"
typedef unsigned char u8;
typedef unsigned int   u32;
extern void func_021D6EE0(u8 *p, u32 v, int unused);
extern void func_021D83A4(char *);
extern void func_021D85C4(char *);
extern void func_021D8624(char *);
extern void func_021D8448(char *);
extern void func_021D8958(char *);
extern void func_021D6FF0(char *);
extern void func_021D8520(char *);
void func_021D8650(char *p,int x,int *q)
{
    int state;
    switch (*q) {
    case 0:
        state=((struct Obj22971 *)(*(char * *)&((struct Obj00063 *)p)->f20))->f1C8;
        switch (state) {
        case 0:
            if (x==0) func_021D6EE0((u8 *)p,(int)func_021D83A4,0x774);
            else if (x==3) func_021D6EE0((u8 *)p,(int)func_021D83A4,0x777);
            else if (x==1) func_021D6EE0((u8 *)p,(int)func_021D85C4,0x77b);
            else if (x==2) func_021D6EE0((u8 *)p,(int)func_021D8624,0x77f);
            else if (x==4) func_021D6EE0((u8 *)p,(int)func_021D83A4,0x782);
            else func_021D6EE0((u8 *)p,(int)func_021D83A4,0x787);
            break;
        case 3:
            if (((struct Obj00063 *)p)->fAF==0) func_021D6EE0((u8 *)p,(int)func_021D8448,0x78c);
            else func_021D6EE0((u8 *)p,(int)func_021D8958,0x78f);
            break;
        }
        break;
    case 5:
        if (((struct Obj22972 *)(*(char * *)&((struct Obj00063 *)p)->f20))->f1C8==3)
            func_021D6EE0((u8 *)p,(int)func_021D8958,0x797);
        else {
            ((struct Obj00063 *)p)->f80=*q;
            func_021D6EE0((u8 *)p,(int)func_021D6FF0,0x79b);
        }
        break;
    case 8:
        switch (((struct Obj22973 *)(*(char * *)&((struct Obj00063 *)p)->f20))->f1C8) {
        case 0: func_021D6EE0((u8 *)p,(int)func_021D83A4,0x7a2); break;
        case 3: func_021D6EE0((u8 *)p,(int)func_021D8520,0x7a6); break;
        }
        break;
    default:
        ((struct Obj00063 *)p)->f80=*q;
        func_021D6EE0((u8 *)p,(int)func_021D6FF0,0x7ac);
        break;
    }
}

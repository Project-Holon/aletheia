/*
 * function: func_021D61F0
 * address: 0x021D61F0
 * packet: pkt_ov175_021D61F0
 * region: ov175
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   MI_CpuFill8 0x02082BCC arm
 *   MI_CpuCopy8 0x02082D44 arm
 *   func_021DCB58 0x021DCB58 thumb ov175
 *   func_021DCC28 0x021DCC28 thumb ov175
 *   func_021E8AA8 0x021E8AA8 thumb ov177
 */
#include "../include/Obj03317.h"
#include "../include/Obj24227.h"
typedef unsigned int u32;
extern void MI_CpuFill8(void *,int,int);
extern void MI_CpuCopy8(const void *,void *,int);
extern void func_021DCB58(char *p, void *q, int mode);
typedef unsigned char  u8;
extern int func_021DCC28(char *p, u8 *out);
extern void func_021E8AA8(int a);
void func_021D61F0(u32 sys,int *state,char *p)
{
    char *base=*(char * *)&((struct Obj24227 *)(*(char * *)&((struct Obj03317 *)p)->f40))->f14;
    int result;
    switch(*state) {
    case 0:
        ((struct Obj03317 *)p)->fE0=0;
        MI_CpuFill8(p+0x44,0,0x9c);
        (*state)++;
        break;
    case 1:
        func_021DCB58(((struct Obj03317 *)p)->f30,base+0xd4,1);
        (*state)++;
        break;
    case 2:
        result=func_021DCC28(((struct Obj03317 *)p)->f30,(u8 *)(p+0x44));
        if(result==1) *state=3;
        else if(result==2) { ((struct Obj03317 *)p)->f3C=2; *state=4; }
        else if(result==3) { ((struct Obj03317 *)p)->f3C=3; *state=4; }
        break;
    case 3:
        if(((struct Obj03317 *)p)->f44==0) {
            MI_CpuCopy8(p+0x60,base+0x54,0x80);
            ((struct Obj03317 *)p)->f3C=0; *state=4;
        } else { ((struct Obj03317 *)p)->f3C=1; *state=4; }
        break;
    case 4: func_021E8AA8(sys); break;
    }
}

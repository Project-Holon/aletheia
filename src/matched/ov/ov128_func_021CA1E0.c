/*
 * function: func_021CA1E0
 * address: 0x021CA1E0
 * packet: pkt_ov128_021CA1E0
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021CA124 0x021CA124 thumb ov128
 * Extent ends with two bytes of zero alignment padding.
 */
#include "../include/Obj00774.h"

typedef unsigned int   u32;
extern void func_021CA124(u32 a, u32 b);
int func_021CA1E0(char *p)  {
    switch(((struct Obj00774 *)p)->f8)  {
        case 0: func_021CA124((u32)(((struct Obj00774 *)p)->f0),1);
        ((struct Obj00774 *)p)->fA=0;
        (((struct Obj00774 *)p)->f8)++;
        break;
        case 1: (((struct Obj00774 *)p)->fA)++;
        if(((struct Obj00774 *)p)->fA==4)  {
            func_021CA124((u32)(((struct Obj00774 *)p)->f0),2);
            ((struct Obj00774 *)p)->fA=0;
            (((struct Obj00774 *)p)->f8)++;
        }
        break;
        case 2: (((struct Obj00774 *)p)->fA)++;
        if(((struct Obj00774 *)p)->fA==4)  {
            func_021CA124((u32)(((struct Obj00774 *)p)->f0),1);
            ((struct Obj00774 *)p)->fA=0;
            (((struct Obj00774 *)p)->f8)++;
        }
        break;
        case 3: (((struct Obj00774 *)p)->fA)++;
        if(((struct Obj00774 *)p)->fA==4)  {
            func_021CA124((u32)(((struct Obj00774 *)p)->f0),2);
            ((struct Obj00774 *)p)->fA=0;
            (((struct Obj00774 *)p)->f8)++;
        }
        break;
        case 4: (((struct Obj00774 *)p)->fA)++;
        if(((struct Obj00774 *)p)->fA==4)  {
            ((struct Obj00774 *)p)->f8=0;
            ((struct Obj00774 *)p)->fA=0;
            return 0;
        }
        break;
    }
    return 1;
}

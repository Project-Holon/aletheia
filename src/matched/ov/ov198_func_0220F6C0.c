/*
 * function: func_0220F6C0
 * address: 0x0220F6C0
 * packet: pkt_ov198_0220F6C0
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02021ED8 0x02021ED8 thumb
 *   func_02211958 0x02211958 thumb ov198
 *   func_02210A4C 0x02210A4C thumb ov198
 *   func_02211128 0x02211128 thumb ov198
 *   func_02211970 0x02211970 thumb ov198
 *   func_0220B760 0x0220B760 thumb ov198
 *   func_02211944 0x02211944 thumb ov198
 *   func_0220F7C4 0x0220F7C4 thumb ov198
 */
#include "../include/Obj04601.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern u32 func_02021ED8(const char *);
extern u32 func_02211958(u8 **);
extern int func_02210A4C(u8 *);
extern int func_02211128(u8 *,u8 *,u8 *,int);
extern void func_02211970(u8 **,u32);
extern void func_0220B760(u8 *,u32);
extern void func_02211944(u8 **);
extern int func_0220F7C4(u8 *);
int func_0220F6C0(u8 *p)
{
    u8 pair[2];
    if(func_02021ED8(*(char * *)&((struct Obj04601 *)p)->f1D8)!=0) return 3;
    if(func_02211958((u8 **)p)==1) return 31;
    if(func_02210A4C(p)==1) {
        if((*(u8 **)p)[32]==6) {
            if((*(u8 **)p)[31]==2) {
                if(func_02211128(p,pair+1,pair,1)==1) {
                    if(pair[1]<pair[0]) (*(u8 * *)&((struct Obj04601 *)p)->f0+pair[1])[72]=255;
                    else (*(u8 * *)&((struct Obj04601 *)p)->f0+pair[0])[72]=255;
                    p[0x2499]=pair[1];
                    p[0x249a]=pair[0];
                    p[0x1e98]=0;
                    func_02211970((u8 **)p,1362);
                    return 9;
                }
            } else if((*(u8 **)p)[31]!=1) {
                func_02211970((u8 **)p,1362);
                func_0220B760(p,6);
                func_02211944((u8 **)p);
                return 31;
            }
        } else {
            func_02211970((u8 **)p,1357);
            func_0220B760(p,(*(u8 **)p)[32]);
            if((*(u8 **)p)[31]==3) return func_0220F7C4(p);
            ((struct Obj04601 *)p)->f217C=12;
            return 29;
        }
    }
    return 3;
}

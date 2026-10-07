/*
 * function: func_021FCFE0,func_021FD094,func_021FD0A8
 * address: 0x021FCFE0
 * packet: pkt_ov186_021FCFE0
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * unit: yes
 * status: EXACT
 * followers: unlabelled store-free accessors 021FD094 and 021FD0A8 included; final 2-byte alignment outside TU length.
 * symbols:
 *   func_021FD860 0x021FD860 thumb ov186
 *   d_02200B0C 0x02200B0C data a4
 */
#include "../../../matched/include/Obj01283.h"
#include "../../../matched/include/Obj14466.h"
#include "../../../matched/include/Obj24840.h"
typedef unsigned short u16;
typedef unsigned int u32;
struct Pair { int x,y; };
extern const struct Pair d_02200B0C[];
extern void func_021FD860(int,int,const struct Pair *);
int func_021FCFE0(char *p,int step)
{
    int count,changed,half;
    count=((struct Obj01283 *)p)->f44;
    changed=0;
    half=(count-1)/2+(count-1)%2;
    if(step>0) {
        if(half==((struct Obj01283 *)p)->f40 && (u32)(((struct Obj01283 *)p)->f42+count)<((struct Obj01283 *)p)->f4) {
            ((struct Obj01283 *)p)->f42+=(u16)step;changed=1;
        } else if((u32)(((struct Obj01283 *)p)->f42+((struct Obj01283 *)p)->f40)<((struct Obj01283 *)p)->f4-1) {
            ((struct Obj01283 *)p)->f40+=(u16)step;changed=1;
        }
    } else if(step<0) {
        if(half==((struct Obj01283 *)p)->f40 && ((struct Obj01283 *)p)->f42) {
            ((struct Obj01283 *)p)->f42+=(u16)step;changed=1;
        } else if(((struct Obj01283 *)p)->f40) {
            ((struct Obj01283 *)p)->f40+=(u16)step;changed=1;
        }
    }
    if(changed && ((struct Obj01283 *)p)->f1C) func_021FD860(((struct Obj01283 *)p)->f1C,5,&d_02200B0C[((struct Obj01283 *)p)->f40]);
    return changed;
}
int func_021FD094(char *p) { return ((struct Obj14466 *)p)->f4>=((struct Obj14466 *)p)->f44; }
int func_021FD0A8(char *p) { return ((struct Obj24840 *)p)->f4>1; }

/*
 * function: func_021FD550
 * address: 0x021FD550
 * packet: pkt_ov132_021FD550
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * follower: two-byte zero alignment padding at 021FD5E2.
 * symbols:
 *   func_021FCEA8 0x021FCEA8 thumb ov132
 *   func_021FD5E4 0x021FD5E4 thumb ov132
 */
#include "../include/Obj02196.h"
#include "../include/Obj23286.h"
#include "../include/Obj23287.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern int func_021FCEA8(void *,int,u32,int);
extern int func_021FD5E4(char *p, u32 i);
void func_021FD550(char *p)
{
    if(((struct Obj02196 *)p)->f150==1) {
        switch(*(u32 *)&((struct Obj02196 *)p)->f17C) {
        case 0: break;
        case 1:
            if(func_021FCEA8(p,7,((struct Obj23286 *)(*(char * *)&((struct Obj02196 *)p)->f140))->f2C,0xff)==1) ((struct Obj02196 *)p)->f17C=2;
            break;
        case 2: break;
        case 3:
            if(func_021FD5E4(p,((struct Obj02196 *)p)->f14C)==1) {
                ((struct Obj02196 *)p)->f154=1;
                ((struct Obj02196 *)p)->f17C=4;
            }
            break;
        case 4:
            if(((struct Obj02196 *)p)->f154==0) {
                if((u32)(((struct Obj02196 *)p)->f14C*0x3800)>=((struct Obj23287 *)(*(char * *)&((struct Obj02196 *)p)->f140))->f2C) ((struct Obj02196 *)p)->f150=0;
                else ((struct Obj02196 *)p)->f17C=3;
            }
            break;
        }
    }
}

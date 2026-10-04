/*
 * function: func_021DD774
 * address: 0x021DD774
 * packet: pkt_ov171_021DD774
 * region: ov171
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: Access the far halfwords as struct members; cache only the guard value, and retain field updates and reads.
 * symbols:
 *   func_021DE5F4 0x021DE5F4 thumb ov171
 *   func_021DE608 0x021DE608 thumb ov171
 *   func_021DE684 0x021DE684 thumb ov171
 */
#include "../include/Obj00142.h"
typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef struct { char pad[0xb10]; s16 previous; char gap[10]; s16 current; } Angle;
extern int func_021DE5F4(char *);
extern void func_021DE608(char *,int,int);
extern void func_021DE684(char *);
int func_021DD774(char *p) {
    int base;
    unsigned i;
    Angle *a;
    int angle;
    base=func_021DE5F4(p);
    if (((struct Obj00142 *)p)->fC62==0) {
        for(i=0;i<*(u16 *)(p+((struct Obj00142 *)p)->fC5E*0xbc+0xc4);i++) {
            a=(Angle *)(p+i*2);
            a->previous=a->current;
            func_021DE608(p,base+i,a->previous);
        }
        func_021DE684(p);
        return 0;
    } else {
        for(i=0;i<*(u16 *)(p+((struct Obj00142 *)p)->fC5E*0xbc+0xc4);i++) {
            a=(Angle *)(p+i*2);
            a->previous+=((struct Obj00142 *)p)->fC61;
            angle=a->previous;
            if (angle<0) a->previous+=360;
            else if (angle>=360) a->previous-=360;
            func_021DE608(p,base+i,a->previous);
        }
        func_021DE684(p);
        (((struct Obj00142 *)p)->fC62)--;
        return 1;
    }
}

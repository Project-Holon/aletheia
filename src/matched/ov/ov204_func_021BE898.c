/*
 * function: func_021BE898
 * address: 0x021BE898
 * packet: pkt_ov204_021BE898
 * region: ov204
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: load the case-2 object once before q[1]'s comparison and reuse
 *   it in both arms; repeated arm loads gave 220 bytes/80 different.
 * symbols:
 *   func_021BFAE8 0x021BFAE8 thumb ov204
 *   func_021BFB2C 0x021BFB2C thumb ov204
 *   func_020362DC 0x020362DC arm
 *   func_020061E4 0x020061E4 thumb
 *   func_0200854C 0x0200854C thumb
 */
#include "../include/Obj03920.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_021BFAE8(char *,u32);
extern int func_021BFB2C(char *);
extern u32 func_020362DC(void);
extern void func_020061E4(u32);
struct Sub0200852CObj;
extern void func_0200854C(struct Sub0200852CObj *obj, u8 value);
int func_021BE898(char *p,u32 *q)
{
    void *obj;
    switch (*q) {
    case 0:
        func_021BFAE8(*(char * *)&((struct Obj03920 *)p)->fC,0);
        *q=4;
        break;
    case 1:
        if (func_020362DC()&16) {
            if (q[1]!=1) {
                func_020061E4(0x548);
                func_021BFAE8(*(char * *)&((struct Obj03920 *)p)->fC,2);
                q[1]=1;
                *q=4;
            }
        } else if (func_020362DC()&32) {
            if (q[1]!=0) {
                func_020061E4(0x548);
                func_021BFAE8(*(char * *)&((struct Obj03920 *)p)->fC,1);
                q[1]=0;
                *q=4;
            }
        } else if (func_020362DC()&1) {
            func_020061E4(0x54D);
            (*q)++;
        }
        break;
    case 2:
        obj=**(void ** *)&((struct Obj03920 *)p)->f4;
        if (q[1]==0) {
            func_0200854C(obj,0);
            func_021BFAE8(*(char * *)&((struct Obj03920 *)p)->fC,3);
        } else {
            func_0200854C(obj,1);
            func_021BFAE8(*(char * *)&((struct Obj03920 *)p)->fC,4);
        }
        (*q)++;
        break;
    case 3:
        if (func_021BFB2C(*(char * *)&((struct Obj03920 *)p)->fC)!=0) return 1;
        break;
    case 4:
        if (func_021BFB2C(*(char * *)&((struct Obj03920 *)p)->fC)!=0) *q=1;
        break;
    }
    return 0;
}

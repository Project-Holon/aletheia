/*
 * function: DEMO3D_CMDSYS_Seek
 * address: 0x021BF964
 * packet: pkt_ov203_021BF964
 * region: ov203
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BE990 0x021BE990 thumb ov203
 *   DEMO3D_CMDSYS_Dispatch 0x021BF9B8 thumb ov203
 */
#include "../include/Obj10867.h"
typedef struct { int kind;unsigned limit;int values[8]; } Record;
typedef unsigned int   u32;
extern u32 func_021BE990(u32 id);
extern void DEMO3D_CMDSYS_Dispatch(unsigned a, unsigned b, char *p);
int DEMO3D_CMDSYS_Seek(char *p,char *owner,int *index)
{
    Record *r;
    int i;
    r=(Record *)func_021BE990(((struct Obj10867 *)owner)->f78);
    for(i=0;i<9999;i++) {
        if(r[i].kind==18) return 1;
        if(r[i].limit==-1) DEMO3D_CMDSYS_Dispatch((unsigned int)p,(unsigned int)owner,(char *)(&r[i]));
        else if(r[i].limit>=((struct Obj10867 *)owner)->f7C) {*index=i;return 0;}
    }
    return 0;
}

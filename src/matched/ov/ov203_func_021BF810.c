/*
 * function: DEMO3D_CMDSYS_Delete
 * address: 0x021BF810
 * packet: pkt_ov203_021BF810
 * region: ov203
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   DEMO3D_DATA_GetRecordField 0x021BE9A4 thumb ov203
 *   DEMO3D_CMDSYS_Dispatch 0x021BF9B8 thumb ov203
 *   TCBL_Main 0x020310C4 arm
 *   DEMO3D_CMDSYS_Release 0x021BF924 thumb ov203
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj02250.h"
typedef struct { int kind;int values[9]; } Record;
typedef unsigned int   u32;
struct Tcbl;
extern u32 DEMO3D_DATA_GetRecordField(u32 id);
extern void DEMO3D_CMDSYS_Dispatch(unsigned a, unsigned b, char *p);
extern void TCBL_Main(struct Tcbl *p);
extern void DEMO3D_CMDSYS_Release(char *);
extern u32 func_020307B0(void *p);
void DEMO3D_CMDSYS_Delete(char *p)
{
    Record *r;
    int owner,i;
    owner=((struct Obj02250 *)p)->f1C;r=(Record *)DEMO3D_DATA_GetRecordField(((struct Obj02250 *)p)->f4);
    for(i=0;i<9999;i++,r++) {
        if(r->kind==18) break;
        DEMO3D_CMDSYS_Dispatch((unsigned int)p,owner,(char *)r);
    }
    ((struct Obj02250 *)p)->fC=1;
    TCBL_Main(((struct Obj02250 *)p)->f20);DEMO3D_CMDSYS_Release(p);func_020307B0(p);
}

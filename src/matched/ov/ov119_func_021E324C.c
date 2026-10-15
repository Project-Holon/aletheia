/*
 * function: POKETRADE_3D_AddUnit
 * address: 0x021E324C
 * packet: pkt_ov119_021E324C
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   G3D_UTIL_AddUnit 0x02047E88 arm
 *   func_02048A18 0x02048A18 arm
 *   G3D_SYSTEM_GetObjectAnimeCount 0x0204779C arm
 *   G3D_SYSTEM_EnableObjectAnime 0x020477A4 arm
 *   gG3dUnitTable 0x021E7B3C data a4
 */
#include "../include/Obj03779.h"
typedef unsigned short u16;
typedef struct {int a,b,c; u16 d,e;} Entry;
extern const Entry gG3dUnitTable[];
extern u16 G3D_UTIL_AddUnit(void *,const Entry *);
typedef unsigned int   u32;
typedef unsigned char  u8;
extern u32 func_02048A18(u8 *a0, int i);
extern int G3D_SYSTEM_GetObjectAnimeCount(int *p);
struct G3dSys;
extern u32 G3D_SYSTEM_EnableObjectAnime(struct G3dSys *sys, u32 idx);
void POKETRADE_3D_AddUnit(char *p,int n) {
    void *q;
    int i,count;
    if(gG3dUnitTable[n].d) ((struct Obj03779 *)p)->f824=G3D_UTIL_AddUnit(((struct Obj03779 *)p)->f820,&gG3dUnitTable[n]);
    else ((struct Obj03779 *)p)->f824=0xffff;
    if(((struct Obj03779 *)p)->f824!=0xffff) {
        q=(void *)func_02048A18(((struct Obj03779 *)p)->f820,((struct Obj03779 *)p)->f824);
        count=G3D_SYSTEM_GetObjectAnimeCount(q);
        for(i=0;i<count;i++) G3D_SYSTEM_EnableObjectAnime(q,(u16)i);
    }
    *(int *)&((struct Obj03779 *)p)->f109C=n;
}

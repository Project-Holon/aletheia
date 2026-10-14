/*
 * function: GURU2_MAIN_AddCenterUnit
 * address: 0x021E04E0
 * packet: pkt_ov137_021E04E0
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: Enum zero preserves its early definition; halfword stores use literal zero to avoid truncation.
 * symbols:
 *   G3D_UTIL_AddUnit 0x02047E88 arm
 *   gGuru2PlayerUnitSetupTable 0x021E20EC data a4
 *   gGuru2PlayerUnitHeightTable 0x021E1DE8 data a4
 */
#include "../include/Obj02499.h"
#include "../include/Obj10625.h"
#include "../include/Obj23775.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct { int x,y,z; } Vec;
typedef struct { int a[4]; } Descriptor;
extern const Descriptor gGuru2PlayerUnitSetupTable[];
extern const int gGuru2PlayerUnitHeightTable[];
extern int G3D_UTIL_AddUnit(void *,const void *);
void GURU2_MAIN_AddCenterUnit(u8 *p)
{
    int index;
    enum { ZERO } zero;
    u8 *s;
    index=((struct Obj23775 *)(*(u8 * *)&((struct Obj10625 *)p)->fD8))->f8;
    s=p+224;
    ((struct Obj02499 *)s)->fBC=G3D_UTIL_AddUnit(((struct Obj10625 *)p)->fAF4,&gGuru2PlayerUnitSetupTable[index-2]);
    zero=0;
    ((struct Obj02499 *)s)->f44=gGuru2PlayerUnitHeightTable[index];
    ((struct Obj02499 *)s)->f18=4096;
    ((struct Obj02499 *)s)->f1C=4096;
    ((struct Obj02499 *)s)->f20=4096;
    ((struct Obj02499 *)s)->f4C=0;
    ((struct Obj02499 *)s)->f4E=0;
    ((struct Obj02499 *)s)->f50=0;
    ((struct Obj02499 *)s)->f3C=zero;
    ((struct Obj10625 *)p)->fE0=zero;
    ((struct Obj02499 *)s)->f4=-147456;
    ((struct Obj02499 *)s)->f8=zero;
    *(Vec *)(s+12)=*(Vec *)s;
}

/*
 * function: FLDMMDL_G3DOBJ_Create
 * address:  0x0219D448
 * packet:   pkt_ov021_0219D448
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_SysGetHeapId  0x0216D4F8  thumb  ov010
 *   FLDMMDL_SysGetMmdlMax  0x0216D4F0  thumb  ov010
 *   FLDMMDL_SysSetG3dObjCont  0x0216D524  thumb  ov010
 *   func_02030734  0x02030734  arm
 *   FLDMMDL_G3DOBJ_InitResTable  0x0219D4AC  thumb  ov021
 *   d_021DDD80     0x021DDD80  data ov021 a4
 */
#include "../include/Obj04226.h"

typedef unsigned short u16;
typedef unsigned int   u32;
typedef unsigned char  u8;
extern u32 FLDMMDL_SysGetHeapId(u8 *p);
extern u16 FLDMMDL_SysGetMmdlMax(void *p);
extern void FLDMMDL_SysSetG3dObjCont(void *p, void *v);
extern void *func_02030734(unsigned int, unsigned int, int, const char *, unsigned short);
extern void FLDMMDL_G3DOBJ_InitResTable(int *obj, int a);
extern unsigned char d_021DDD80[];

void FLDMMDL_G3DOBJ_Create(int a, int b)
{
    int h;
    int *p;

    h = FLDMMDL_SysGetHeapId((u8 *)a);
    p = (int *)func_02030734(h, 0x10, 1, (const char *)d_021DDD80, 0x48);
    p[0] = a;
    p[1] = b;
    ((struct Obj04226 *)p)->f8 = FLDMMDL_SysGetMmdlMax((void *)a);
    FLDMMDL_G3DOBJ_InitResTable(p, h);
    FLDMMDL_SysSetG3dObjCont((void *)a, p);
}

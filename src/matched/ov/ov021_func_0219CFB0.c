/*
 * function: FLDMMDL_BLACT_ReserveActor
 * address:  0x0219CFB0
 * packet:   pkt_ov021_0219CFB0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_SysGetMmdlMax  0x0216D4F0  thumb  ov010
 *   FLDMMDL_GetObjCodeParamBlActRes  0x0216E3C8  thumb  ov010
 *   FLDMMDL_BLACT_FindRes  0x0219CBD4  thumb  ov021
 *   FLDMMDL_BLACT_ReserveRes  0x0219CD68  thumb  ov021
 *   FLDMMDL_BLACT_FindReservedRes  0x0219CF00  thumb  ov021
 */
#include "../include/Obj01353.h"
#include "../include/Obj03118.h"

typedef struct { int a; int b; int c; } S3;

typedef unsigned short u16;
typedef unsigned int   u32;
typedef unsigned char  u8;
extern u16 FLDMMDL_SysGetMmdlMax(void *p);
extern void *FLDMMDL_GetObjCodeParamBlActRes(void *p);
extern int FLDMMDL_BLACT_FindRes(u32 a, u32 b, u32 c, u32 d);
extern void FLDMMDL_BLACT_ReserveRes(u8 *o, u16 a, u8 b, u8 c, u16 d, u32 e);
extern int FLDMMDL_BLACT_FindReservedRes(int *, unsigned int, unsigned short *);

void FLDMMDL_BLACT_ReserveActor(int *obj, int a1, unsigned char *src, int a3, int a5, int a6, S3 *a7)
{
    unsigned int i;
    unsigned int n;
    int *p;
    unsigned short v[2];
    unsigned short *t;

    i = 0;
    n = FLDMMDL_SysGetMmdlMax((void *)obj[4]);
    p = *(int **)(obj[7] + 0x14);
    for (; i < n; i++, p += 10) {
        if (p[0] == 0) {
            *((unsigned char *)p + 0xd) = 0;
            p[1] = a1;
            p[0] = a3;
            ((struct Obj01353 *)p)->f8 = ((struct Obj03118 *)src)->f0;
            *((unsigned char *)p + 0xa) = src[7];
            *((unsigned char *)p + 0xb) = src[8];
            *((unsigned char *)p + 0xc) = src[9];
            FLDMMDL_BLACT_FindRes((u32)obj, ((struct Obj01353 *)p)->f8, (u32)(&v[1]), (u32)(&v[0]));
            if (v[1] == 0xFFFF && FLDMMDL_BLACT_FindReservedRes(obj, ((struct Obj01353 *)p)->f8, &v[0]) == 0) {
                t = FLDMMDL_GetObjCodeParamBlActRes(src);
                v[0] = 1;
                FLDMMDL_BLACT_ReserveRes((u8 *)obj, ((struct Obj01353 *)p)->f8, *((unsigned char *)p + 0xa),
                              *((unsigned char *)p + 0xb), *t, 1);
            }
            p[5] = a5;
            p[6] = a6;
            if (a7 != 0) {
                *(S3 *)(p + 7) = *a7;
            }
            *((unsigned char *)p + 0xd) = 1;
            return;
        }
    }
}

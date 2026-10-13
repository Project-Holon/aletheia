/*
 * function: SOUND_OBJ_Create
 * address:  0x021C4D14
 * packet:   pkt_ov021_021C4D14
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * ISS_3DS_SYS_IsSourceActive and ISS_3DS_SYS_StartSource are witnessed by src/matched/arm9/.
 *
 * symbols:
 *   FIELDMAP_GetHeapId  0x02188C84  thumb  ov021
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb  ov021
 *   GAMESYSTEM_GetIssSystem  0x02012134  thumb
 *   func_0202B57C  0x0202B57C  thumb
 *   func_02030734  0x02030734  arm
 *   ISS_3DS_SYS_IsSourceActive  0x0202B928  thumb
 *   ISS_3DS_SYS_StartSource  0x0202B920  thumb
 *   gSoundObjFileName     0x021DE48C  data  a4
 */
#include "../include/Obj01507.h"

typedef unsigned short u16;

extern int gSoundObjFileName;

typedef unsigned int   u32;
typedef unsigned char  u8;
extern u16 FIELDMAP_GetHeapId(u8 *p);
extern void *FIELDMAP_GetGameSystem(void *p);
extern u32 GAMESYSTEM_GetIssSystem(u32 *p);
extern u32 func_0202B57C(void *obj);
extern void *func_02030734(unsigned int a, unsigned int b, int c, const char *d, u16 e);
extern int ISS_3DS_SYS_IsSourceActive(int a, int b);
extern void ISS_3DS_SYS_StartSource(void *m, int i, int a, int b);

void *SOUND_OBJ_Create(int a, int b, int c, int d, int e)
{
    int n = FIELDMAP_GetHeapId((u8 *)a);
    int r;
    int *p;

    r = func_0202B57C((void *)GAMESYSTEM_GetIssSystem((u32 *)FIELDMAP_GetGameSystem((void *)a)));
    p = (int *)func_02030734(n, 0x18, 0, (const char *)&gSoundObjFileName, 0x3c);
    ((struct Obj01507 *)p)->f0 = n;
    p[1] = a;
    p[2] = r;
    p[3] = c;
    p[4] = 0;
    p[5] = b;
    if (ISS_3DS_SYS_IsSourceActive(r, c) == 0) {
        ISS_3DS_SYS_StartSource((void *)r, c, d, e);
    }
    return p;
}

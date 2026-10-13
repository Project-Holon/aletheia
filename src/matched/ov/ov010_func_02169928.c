/*
 * function: FIELD_G3D_MAP_InitRenderObj
 * address:  0x02169928
 * packet:   pkt_ov010_02169928
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   G3D_SYSTEM_GetResourceFile  0x02046F48  arm
 *   NNS_G3dGetMdlSet  0x0206E954  arm
 *   NNS_G3dGetTex  0x0206E964  arm
 *   NNS_G3dBindMdlTex  0x0206A2CC  arm
 *   NNS_G3dBindMdlPltt  0x0206A4AC  arm
 *   NNS_G3dRenderObjInit  0x02069D14  arm
 */
#include "../include/Obj12388.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Tagged;
extern void *G3D_SYSTEM_GetResourceFile(struct Tagged *p);
extern int NNS_G3dGetMdlSet(int p0);
extern unsigned char *NNS_G3dGetTex(unsigned char *p);
extern void NNS_G3dBindMdlTex(void *a, void *b);
extern void NNS_G3dBindMdlPltt(void *a, void *b);
extern void NNS_G3dRenderObjInit(void *a, void *b);

static inline u32 *Get(u8 *r, u32 idx)
{
    u8 *h;

    h = r + 8;
    if (h != 0 && idx < r[9])
        return (u32 *)(h + ((struct Obj12388 *)r)->fE + 4 + idx * 4);
    return 0;
}

void FIELD_G3D_MAP_InitRenderObj(void *a, void *b, void *c)
{
    u8 *r;
    u32 *q;
    u8 *res;
    void *m;
    void *y;

    res = G3D_SYSTEM_GetResourceFile(b);
    y = G3D_SYSTEM_GetResourceFile(c);
    m = 0;
    r = (u8 *)NNS_G3dGetMdlSet((int)res);
    if (r != 0 && (q = Get(r, 0)) != 0)
        res = r + *q;
    else
        res = 0;
    if (y != 0)
        m = NNS_G3dGetTex(y);
    if (m != 0) {
        NNS_G3dBindMdlTex(res, m);
        NNS_G3dBindMdlPltt(res, m);
    }
    NNS_G3dRenderObjInit(a, res);
}

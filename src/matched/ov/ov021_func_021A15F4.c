/*
 * function: FIELD_3DBG_DrawBillboard
 * address:  0x021A15F4
 * packet:   pkt_ov021_021A15F4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_3DBG_IsTextureLoaded  0x021A1780  thumb  ov021
 *   FIELD_3DBG_CalcQuadGeometry  0x021A1784  thumb  ov021
 *   FIELD_3DBG_SetPolygonAttr  0x021A1934  thumb  ov021
 *   FIELD_3DBG_SetTextureParams  0x021A195C  thumb  ov021
 *   FIELD_3DBG_DrawQuad  0x021A1848  thumb  ov021
 *   func_0206DB80  0x0206DB80  arm
 *   func_0207D8C4  0x0207D8C4  arm
 *   g_DefaultProjectionMtx     0x02148B54  data  a4
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;
typedef struct { u32 w[16]; } S64;
extern S64 g_DefaultProjectionMtx;
typedef unsigned char  u8;
extern u32 FIELD_3DBG_IsTextureLoaded(u8 *p);
extern void FIELD_3DBG_CalcQuadGeometry(u32 *, u32 *, u32 *, S64 *);
typedef signed int     s32;
extern void FIELD_3DBG_SetPolygonAttr(u8 *p);
extern void FIELD_3DBG_SetTextureParams(u32 *);
extern void FIELD_3DBG_DrawQuad(const s32 *a);
extern void func_0206DB80(void);
extern void func_0207D8C4(S64 *);

void FIELD_3DBG_DrawBillboard(u32 *p)
{
    S64 buf;
    volatile u32 *r;
    if (p != 0 && p[2] != 0 && FIELD_3DBG_IsTextureLoaded((u8 *)(p + 8)) != 0) {
        func_0206DB80();
        *(volatile u32 *)0x04000440 = 0;
        buf = g_DefaultProjectionMtx;
        func_0207D8C4(&buf);
        r = (volatile u32 *)0x04000440;
        r[0] = 2;
        r[5] = 0;
        r[1] = 0;
        FIELD_3DBG_CalcQuadGeometry(p + 11, p, p + 8, &buf);
        FIELD_3DBG_SetPolygonAttr((u8 *)p);
        FIELD_3DBG_SetTextureParams(p);
        FIELD_3DBG_DrawQuad((const s32 *)(p + 11));
        r[2] = 1;
    }
}

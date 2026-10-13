/*
 * function: FLDMMDL_InitWithHeader
 * address:  0x0216D040
 * packet:   pkt_ov010_0216D040
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FLDMMDL_SetHeaderParams  0x0216CFC4  thumb  ov010
 *   FLDMMDL_GetEventWorkObjCode  0x0216E3D8  thumb  ov010
 *   FLDMMDL_SetObjCode  0x0216D594  thumb  ov010
 *   FLDMMDL_LoadMmdlObjCodeParam  0x0216E39C  thumb  ov010
 *   FLDMMDL_SetHeaderPos  0x0216D02C  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;

extern int FLDMMDL_SetHeaderParams(int a0, int a1);
extern u32 FLDMMDL_GetEventWorkObjCode(u32 a, u32 b);
extern void FLDMMDL_SetObjCode(void *p, u32 v);
extern void FLDMMDL_LoadMmdlObjCodeParam(int a0, int a1, int a2);
extern void FLDMMDL_SetHeaderPos(int a, u8 *p);

void FLDMMDL_InitWithHeader(u8 *o, u16 *r, u32 b, u32 c)
{
    u32 id;
    s8 *p;

    FLDMMDL_SetHeaderParams((int)o, (int)r);
    id = FLDMMDL_GetEventWorkObjCode(b, r[1]);
    FLDMMDL_SetObjCode(o, id);
    FLDMMDL_LoadMmdlObjCodeParam(c, id, (int)o);
    p = (s8 *)(o + 0xe4);
    if (id == 0xb9) {
        o[0x7c] = r[7];
        o[0x7d] = r[8];
        if (o[0x7c] == 0)
            o[0x7c] += 1;
        if (o[0x7d] == 0)
            o[0x7d] += 1;
    } else {
        o[0x7c] = ((u8 *)p)[0xb];
        o[0x7d] = ((u8 *)p)[0xc];
    }
    o[0x7e] = p[0xd];
    o[0x7f] = p[0xe];
    o[0x80] = p[0xf];
    FLDMMDL_SetHeaderPos((int)o, (u8 *)r);
}

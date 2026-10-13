/*
 * function: FLDMMDL_BLACT_AddCachedRes
 * address:  0x0219C680
 * packet:   pkt_ov021_0219C680
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_SysGetBlActCont  0x0216D520  thumb  ov010
 *   FLDMMDL_GetCachedObjCodeCount  0x0216E2E0  thumb  ov010
 *   FLDMMDL_GetCachedObjCodeParam  0x0216E2AC  thumb  ov010
 *   FLDMMDL_BLACT_AddResObjCodeParam  0x0219CB64  thumb  ov021
 *
 * Formerly MATCH on unwitnessed callees; their matched entries now witness them.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 FLDMMDL_SysGetBlActCont(void *p);
extern u16 FLDMMDL_GetCachedObjCodeCount(void *p);
extern void FLDMMDL_GetCachedObjCodeParam(u32, int, u8 *);
extern void FLDMMDL_BLACT_AddResObjCodeParam(u32, u8 *, u32);

void FLDMMDL_BLACT_AddCachedRes(u32 a)
{
    u8 buf[28];
    u32 s = FLDMMDL_SysGetBlActCont((void *)a);
    int n = FLDMMDL_GetCachedObjCodeCount((void *)a);
    int i;
    for (i = 0; i < n; i++) {
        FLDMMDL_GetCachedObjCodeParam(a, i, buf);
        FLDMMDL_BLACT_AddResObjCodeParam(s, buf, 0);
    }
}

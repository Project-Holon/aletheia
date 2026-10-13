/*
 * function: FLDMMDL_BLACT_AddResByCode
 * address:  0x0219C658
 * packet:   pkt_ov021_0219C658
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_SysGetBlActCont  0x0216D520  thumb  ov010
 *   FLDMMDL_LoadObjCodeParam  0x0216E2E8  thumb  ov010
 *   FLDMMDL_BLACT_AddResObjCodeParam  0x0219CB64  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 FLDMMDL_SysGetBlActCont(void *p);
struct Record;
extern void FLDMMDL_LoadObjCodeParam(const char *ctx, u32 id, struct Record *out);
extern void FLDMMDL_BLACT_AddResObjCodeParam(u32, u8 *, u32);

void FLDMMDL_BLACT_AddResByCode(u32 a, u32 b)
{
    u8 buf[28];
    u32 s = FLDMMDL_SysGetBlActCont((void *)a);
    FLDMMDL_LoadObjCodeParam((const char *)a, b, (struct Record *)buf);
    FLDMMDL_BLACT_AddResObjCodeParam(s, buf, 0);
}

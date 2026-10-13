/*
 * function: UNION_CHARA_DeleteSlot
 * address:  0x0217B054
 * packet:   pkt_ov019_0217B054
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201210C  0x0201210C  thumb
 *   UNION_CHARA_GetMmdl  0x0217AFB0  thumb  ov019
 *   FIELDMAP_GetUnionEff  0x02188CE0  thumb  ov021
 *   UNION_EFF_DeleteIcon  0x0217F958  thumb  ov019
 *   FLDMMDL_DeleteMmdl  0x0216CF2C  thumb  ov010
 *   MI_CpuFill8    0x02082BCC  arm
 */

struct Ctx;
extern void *func_0201210C(const struct Ctx *p);
typedef unsigned int   u32;
typedef unsigned char  u8;
extern void *UNION_CHARA_GetMmdl(void **a, u8 *b, u8 *c);
extern u32 FIELDMAP_GetUnionEff(u8 *p);
extern void UNION_EFF_DeleteIcon(char *p, u32 key);
extern void FLDMMDL_DeleteMmdl(void *);
extern void MI_CpuFill8(void *p, int v, int n);

void UNION_CHARA_DeleteSlot(void **a, int b, void *c)
{
    void *h;
    void *r;

    h = func_0201210C(((void **)a[0])[3]);
    r = UNION_CHARA_GetMmdl(a, (u8 *)b, c);
    if (h != 0 && r != 0)
        UNION_EFF_DeleteIcon((char *)FIELDMAP_GetUnionEff(h), (u32)r);
    FLDMMDL_DeleteMmdl(r);
    MI_CpuFill8(c, 0, 12);
}

/*
 * function: func_021F37B8
 * address:  0x021F37B8
 * packet:   pkt_ov060_021F37B8
 * region:   ov060
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   FIELDMAP_GetCommonWork  0x021897BC  thumb  ov021
 *   FIELDMAP_GetExpObj  0x02188D2C  thumb  ov021
 *   GIMMICK60_ShowEffect  0x021F399C  thumb  ov060
 */

extern int *FIELDMAP_GetCommonWork(char *p, int idx);
extern int FIELDMAP_GetExpObj(int *p);
typedef struct { int a, b, c; } V;
extern void GIMMICK60_ShowEffect(unsigned char *o, void *p, V *v);

void func_021F37B8(char *p, V *v)
{
    unsigned char *o;
    void *s;
    o = (unsigned char *)FIELDMAP_GetCommonWork(p, 0);
    s = (void *)FIELDMAP_GetExpObj((int *)p);
    GIMMICK60_ShowEffect(o, s, v);
}

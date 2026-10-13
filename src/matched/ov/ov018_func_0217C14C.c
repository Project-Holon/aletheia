/*
 * function: INTRUDE_FIELD_AddMarkerMmdl
 * address:  0x0217C14C
 * packet:   pkt_ov018_0217C14C
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELDMAP_GetMmdlSys  0x02188C7C  thumb  ov021
 *   FIELDMAP_GetZoneId  0x02188C9C  thumb  ov021
 *   FLDMMDL_AddMmdl  0x0216CE60  thumb  ov010
 *   INTRUDE_FIELD_gMarkerMmdlHeader     0x021835D4  data   a4
 */

typedef unsigned short u16;

typedef struct {
    u16 h0;
    u16 h2;
    int w4;
} T;

typedef struct {
    int w[7];
    T t;
} S;

extern void *FIELDMAP_GetMmdlSys(unsigned char *p);
typedef unsigned char  u8;
extern u16 FIELDMAP_GetZoneId(u8 *p);
extern void FLDMMDL_AddMmdl(int a, int b, int c);
extern const S INTRUDE_FIELD_gMarkerMmdlHeader;

void INTRUDE_FIELD_AddMarkerMmdl(int a0, u16 a1, u16 a2, int a3)
{
    void *v;
    int c;
    S s;
    T *t;

    v = FIELDMAP_GetMmdlSys((void *)a0);
    c = FIELDMAP_GetZoneId((u8 *)a0);
    s = INTRUDE_FIELD_gMarkerMmdlHeader;
    t = &s.t;
    t->h0 = a1;
    t->h2 = a2;
    t->w4 = a3;
    FLDMMDL_AddMmdl((int)v, (int)(&s), c);
}

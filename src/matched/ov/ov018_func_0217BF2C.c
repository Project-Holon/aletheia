/*
 * function: INTRUDE_FIELD_AddMmdl
 * address:  0x0217BF2C
 * packet:   pkt_ov018_0217BF2C
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
 *   INTRUDE_FIELD_gMmdlHeaderTemplate     0x02182B6C  data   a4
 */

typedef unsigned short u16;

typedef struct { u16 a, b; int c; } Sub;

typedef struct {
    u16 f00, f02;
    u16 pad04[3];
    u16 f0a;
    u16 pad0c[8];
    Sub s;
} Buf;

extern void *FIELDMAP_GetMmdlSys(unsigned char *p);
typedef unsigned char  u8;
extern u16 FIELDMAP_GetZoneId(u8 *p);
extern void FLDMMDL_AddMmdl(int a, int b, int c);
extern const Buf INTRUDE_FIELD_gMmdlHeaderTemplate;

void INTRUDE_FIELD_AddMmdl(int a, u16 b, u16 c, int d, u16 e, u16 f, u16 g)
{
    Buf buf;
    void *h;
    int k;
    Sub *q;

    h = FIELDMAP_GetMmdlSys((void *)a);
    k = FIELDMAP_GetZoneId((u8 *)a);
    buf = INTRUDE_FIELD_gMmdlHeaderTemplate;
    buf.f00 = g;
    buf.f02 = e;
    buf.f0a = f;
    q = &buf.s;
    q->a = b;
    q->b = c;
    q->c = d;
    FLDMMDL_AddMmdl((int)h, (int)(&buf), k);
}

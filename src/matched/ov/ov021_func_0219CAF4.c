/*
 * function: FLDMMDL_BLACT_DeleteAllRes
 * address:  0x0219CAF4
 * packet:   pkt_ov021_0219CAF4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_BLACT_DeleteRes  0x0219CB98  thumb  ov021
 *   FLDMMDL_BLACT_FreeResTable  0x0219CA34  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
typedef struct { u16 a; u16 b; u16 c; u16 pad; } Ent;
typedef struct { int n; Ent *e; } Tbl;
extern void FLDMMDL_BLACT_DeleteRes(u8 *, u16);
extern void FLDMMDL_BLACT_FreeResTable(u8 *p);

void FLDMMDL_BLACT_DeleteAllRes(u8 *s)
{
    int i;
    Ent *e = ((Tbl *)(s + 0x14))->e;
    i = 0;
    do {
        if (e->a != 0xFFFF) {
            FLDMMDL_BLACT_DeleteRes(s, e->a);
        }
        i++;
        e++;
    } while (i < ((Tbl *)(s + 0x14))->n);
    FLDMMDL_BLACT_FreeResTable((u8 *)(s + 0x14));
}

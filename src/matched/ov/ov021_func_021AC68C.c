/*
 * function: FLDEFF_GRASS_Create
 * address:  0x021AC68C
 * packet:   pkt_ov021_021AC68C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021DE070  0x021DE070  data
 *   FLDEFF_GRASS_CreateSlots  0x021AC6D4  thumb  ov021
 *   FIELDMAP_GetGroundBbdAct  0x02188C90  thumb  ov021
 *   FIELD_EFFECT_GetFieldMap  0x021ABE14  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

typedef struct P { u32 f0; u32 f4; u32 w[4]; } P;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 FIELD_EFFECT_GetFieldMap(u8 *p);
extern u32 FIELDMAP_GetGroundBbdAct(u8 *p);
extern void FLDEFF_GRASS_CreateSlots(u32 *p);
extern char d_021DE070[];

P *FLDEFF_GRASS_Create(int a, int heap)
{
    P *p;

    p = (P *)func_02030734(heap, 0x18, 1, d_021DE070, 0x6c);
    p->f0 = a;
    p->f4 = FIELDMAP_GetGroundBbdAct((u8 *)FIELD_EFFECT_GetFieldMap((u8 *)a));
    FLDEFF_GRASS_CreateSlots((u32 *)p);
    return p;
}

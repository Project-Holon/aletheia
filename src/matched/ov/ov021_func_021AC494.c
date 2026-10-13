/*
 * function: FLDEFF_KEMURI_Create
 * address:  0x021AC494
 * packet:   pkt_ov021_021AC494
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021DE038  0x021DE038  data
 *   FLDEFF_KEMURI_LoadResource  0x021AC4CC  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

typedef struct P { u32 f0; u32 f4; } P;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void FLDEFF_KEMURI_LoadResource(u32 *a);
extern char d_021DE038[];

P *FLDEFF_KEMURI_Create(u32 a, int heap)
{
    P *p;

    p = (P *)func_02030734(heap, 8, 1, d_021DE038, 0x52);
    p->f0 = a;
    FLDEFF_KEMURI_LoadResource((u32 *)p);
    return p;
}

/*
 * function: FLDEFF_ENCOUNT_Create
 * address:  0x021AD7B4
 * packet:   pkt_ov021_021AD7B4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   sFldeffEncountFileName  0x021DE0E8  data
 *   FLDEFF_ENCOUNT_LoadKind  0x021AD7E4  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

typedef struct P { u32 f0; } P;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void FLDEFF_ENCOUNT_LoadKind(int *a, u32 b);
extern char sFldeffEncountFileName[];

P *FLDEFF_ENCOUNT_Create(u32 a, int heap, u32 c)
{
    P *p;

    p = (P *)func_02030734(heap, 0x98, 1, sFldeffEncountFileName, 0x11e);
    p->f0 = a;
    FLDEFF_ENCOUNT_LoadKind((int *)p, c);
    return p;
}

/*
 * function: FLDEFF_NAMIPOKE_SPLASH_Create
 * address:  0x021AD3D4
 * packet:   pkt_ov021_021AD3D4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   sFldeffNamipokeFileName  0x021DE080  data
 *   FLDEFF_NAMIPOKE_SPLASH_LoadResources  0x021AD410  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

typedef struct P { u32 f0; } P;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void FLDEFF_NAMIPOKE_SPLASH_LoadResources(u32 *a);
extern char sFldeffNamipokeFileName[];

P *FLDEFF_NAMIPOKE_SPLASH_Create(u32 a, int heap)
{
    P *p;

    p = (P *)func_02030734(heap, 0x10, 1, sFldeffNamipokeFileName, 0x3cf);
    p->f0 = a;
    FLDEFF_NAMIPOKE_SPLASH_LoadResources((u32 *)p);
    return p;
}

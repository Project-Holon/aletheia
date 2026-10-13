/*
 * function: FLDEFF_SPLASH_CreateModelRes
 * address:  0x021C4B28
 * packet:   pkt_ov021_021C4B28
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Allocates the 8-byte record and initialises it.
 *
 * symbols:
 *   FLDEFF_SPLASH_LoadModel  0x021C4B64  thumb  ov021
 *   gFldeffSplashFileName     0x021DE47C  data  ov021
 */

typedef unsigned int u32;

typedef struct {
    void *owner;
    u32 f4;
} R;

typedef unsigned short u16;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
struct P;
extern void FLDEFF_SPLASH_LoadModel(struct P *p);
extern char gFldeffSplashFileName[];

R *FLDEFF_SPLASH_CreateModelRes(void *owner, u32 heap)
{
    R *r = func_02030734(heap, 8, 1, gFldeffSplashFileName, 0x163);

    r->owner = owner;
    FLDEFF_SPLASH_LoadModel((struct P *)r);
    return r;
}

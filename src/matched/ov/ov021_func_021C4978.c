/*
 * function: FLDEFF_SPLASH_CreateBoardRes
 * address:  0x021C4978
 * packet:   pkt_ov021_021C4978
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Allocates the 0xC-byte field-object record (second kind) and initialises
 * it.
 *
 * symbols:
 *   FIELD_EFFECT_GetFieldMap  0x021ABE14  thumb  ov021
 *   FIELDMAP_GetGroundBbdAct  0x02188C90  thumb  ov021
 *   FLDEFF_SPLASH_LoadBoardImage  0x021C49C0  thumb  ov021
 *   gFldeffSplashFileName     0x021DE47C  data  ov021
 */

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct {
    void *owner;
    u32 obj;
    u32 f8;
} R;

typedef unsigned short u16;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 FIELD_EFFECT_GetFieldMap(u8 *p);
extern u32 FIELDMAP_GetGroundBbdAct(u8 *p);
struct P;
extern void FLDEFF_SPLASH_LoadBoardImage(struct P *p);
extern char gFldeffSplashFileName[];

R *FLDEFF_SPLASH_CreateBoardRes(u8 *owner, u32 heap)
{
    R *r = func_02030734(heap, 0xC, 1, gFldeffSplashFileName, 0x7D);

    r->owner = owner;
    r->obj = FIELDMAP_GetGroundBbdAct((u8 *)FIELD_EFFECT_GetFieldMap(owner));
    FLDEFF_SPLASH_LoadBoardImage((struct P *)r);
    return r;
}

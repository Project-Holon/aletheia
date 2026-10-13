/*
 * function: PLACE_NAME_LETTER_UpdateOamPos
 * address:  0x021BD5D4
 * packet:   pkt_ov021_021BD5D4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   _ffix          0x0209C494  arm
 *   PLACE_NAME_LETTER_GetMotion  0x021BD304  thumb  ov021
 *   BMP_OAM_SetPos  0x0202590C  thumb  arm9
 */

typedef struct {
    float f0;
    float f4;
} Q;

typedef struct {
    char pad[0xC];
    void *fC;
} Obj;

typedef unsigned char  u8;
extern u8 *PLACE_NAME_LETTER_GetMotion(u8 *p);
extern void BMP_OAM_SetPos(void *a, int b, int c);

void PLACE_NAME_LETTER_UpdateOamPos(Obj *p)
{
    Q *q = (Q *)PLACE_NAME_LETTER_GetMotion((u8 *)p);
    int x = (int)q->f0;
    int y = (int)q->f4;

    BMP_OAM_SetPos(p->fC, x, y);
}

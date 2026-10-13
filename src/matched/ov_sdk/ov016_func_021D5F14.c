/*
 * function: DWCi_FNTlClear
 * address:  0x021D5F14
 * packet:   pkt_ov016_021D5F14
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
*/

typedef struct {
    void *pad;
    void (*pfnClear)(void *cnv, int color);
} CharFmt;

typedef struct {
    unsigned char chr0[0x14];
    CharFmt *pFmt;
} Canvas;

void DWCi_FNTlClear(Canvas *cnv, int color)
{
    cnv->pFmt->pfnClear(cnv, color);
}

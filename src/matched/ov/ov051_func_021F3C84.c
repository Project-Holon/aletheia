/*
 * function: FIELD_GIMMICK_D06_GetSlideSteps
 * address: 0x021F3C84
 * packet: pkt_ov051_021F3C84
 * region: ov051
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   FIELD_GIMMICK_D06_ScanSlide 0x021F3BC4 thumb ov051
 */

extern int FIELD_GIMMICK_D06_ScanSlide(int *, int *, int, unsigned short, unsigned int *);
int FIELD_GIMMICK_D06_GetSlideSteps(int *a, int *b, int c) { unsigned int out; FIELD_GIMMICK_D06_ScanSlide(a,b,c,32,&out); return out; }

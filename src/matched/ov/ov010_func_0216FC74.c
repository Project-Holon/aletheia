/*
 * function: TEXT_TEXTURE_PrintToClearedBitmap
 * address: 0x0216FC74
 * packet: pkt_ov010_0216FC74
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   TEXT_TEXTURE_ClearBitmap 0x0216FC50 thumb ov010
 *   PRINTSYS_PrintColor 0x0201C7D0 thumb
 */
typedef signed short s16;
typedef unsigned short u16;
extern void TEXT_TEXTURE_ClearBitmap(void *);
extern void PRINTSYS_PrintColor(void *,s16,s16,void *,void *,u16);
void TEXT_TEXTURE_PrintToClearedBitmap(void *a, u16 b, u16 c, u16 d, void *e, void *f) { TEXT_TEXTURE_ClearBitmap(e); PRINTSYS_PrintColor(e,b,c,a,f,d); }

/*
 * function: BOX2_SEQ_DrawSpriteEntry
 * address: 0x021EAF20
 * packet: pkt_ov170_021EAF20
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * trailing: two-byte zero alignment padding at 0x021EAFBA.
 * symbols:
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BOX2_SEQ_PrintTextWinEx 0x021EAC28 thumb ov170
 *   BOX2_SEQ_PrintTextWin 0x021EABD0 thumb ov170
 *   BOX2_SEQ_MakeScreen 0x021EABA0 thumb ov170
 *   BOX2_SEQ_SetDirtyBit 0x021EAAE4 thumb ov170
 */
#include "../include/Obj08243.h"
typedef unsigned char  u8;
struct CharBuf;
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void BOX2_SEQ_PrintTextWinEx(char *, int, void *, unsigned, int, int, unsigned, unsigned short);
extern void BOX2_SEQ_PrintTextWin(unsigned char *w, int i, void *bank, unsigned idx, int x, int y, unsigned font, unsigned short color);
extern void BOX2_SEQ_MakeScreen(void **);
extern void BOX2_SEQ_SetDirtyBit(unsigned char *p, unsigned i);
typedef struct { unsigned char pad[18]; unsigned char low : 7; unsigned char flag : 1; unsigned char kind : 4; unsigned char enabled : 1; unsigned char rest : 3; } Entry;
void BOX2_SEQ_DrawSpriteEntry(char *p, Entry *e, unsigned i)
{
    BMP_Clear(BMP_WIN_GetBmp(*(void **)(p + 0x94 + i * 8)), 0);
    if (!e->flag && e->enabled == 1) {
        if (e->kind == 0) {
            BOX2_SEQ_PrintTextWin((unsigned char *)p, i, ((struct Obj08243 *)p)->f80, 95, 0, 0, ((struct Obj08243 *)p)->f78, 0x14c0);
        } else if (e->kind == 1) {
            BOX2_SEQ_PrintTextWin((unsigned char *)p, i, ((struct Obj08243 *)p)->f80, 96, 0, 0, ((struct Obj08243 *)p)->f78, 0xc80);
        } else {
            BOX2_SEQ_SetDirtyBit((unsigned char *)p, i); return;
        }
    } else {
        BOX2_SEQ_SetDirtyBit((unsigned char *)p, i); return;
    }
    BOX2_SEQ_MakeScreen((void **)(p + 0x94 + i * 8));
}

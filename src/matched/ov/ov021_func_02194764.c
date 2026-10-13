/*
 * function: TALKMSGWIN_Draw
 * address:  0x02194764
 * packet:   pkt_ov021_02194764
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   NNS_G3dGeFlushBuffer  0x0206DB80  arm
 *   TALKMSGWIN_SetupCamera  0x021953D4  thumb  ov021
 *   TALKMSGWIN_DrawEntry  0x02194CE8  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

typedef struct { u16 kind; u8 f2; u8 rest[97]; } Ent;
typedef struct { u8 pad[0x18]; Ent ents[32]; } Top;
extern void NNS_G3dGeFlushBuffer(void);
extern void TALKMSGWIN_SetupCamera(u8 *p, int m);
extern void TALKMSGWIN_DrawEntry(int a, u16 *b);

void TALKMSGWIN_Draw(Top *a)
{
    int i;

    NNS_G3dGeFlushBuffer();
    TALKMSGWIN_SetupCamera((u8 *)a, 1);
    for (i = 0; i < 32; i++) {
        if (a->ents[i].f2 == 0) {
            TALKMSGWIN_DrawEntry((int)a, (u16 *)(&a->ents[i]));
        }
    }
}

/*
 * function: FIELD_MSGBG_ClearPlainWin
 * address:  0x021915EC
 * packet:   pkt_ov021_021915EC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BG_SYS_PushTile  0x020409B4  arm  arm9
 *   BMP_Clear  0x02043B5C  arm  arm9
 *   BMP_WIN_GetBmp  0x02045770  arm  arm9
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef short          s16;

typedef struct Fx {
    u16 f00;
    u16 f02;
    u16 f04;
    u16 f06;
} Fx;

typedef struct R {
    u32 f00;
    u32 f04;
    u32 f08;
    Fx *f0c;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1c;
    void *f20;
    u32 f24;
    u16 f28;
} R;

struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *a);
struct CharBuf;
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void BG_SYS_PushTile(u32 a);

void FIELD_MSGBG_ClearPlainWin(R *r)
{
    BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)r->f18)), 0xFF);
    BG_SYS_PushTile((u8)r->f0c->f02);
}

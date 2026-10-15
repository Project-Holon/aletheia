/*
 * function: PMS_DRAW_ClearElem
 * address:  0x0202E38C
 * packet:   pkt_0202E0E0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   BMP_Clear  0x02043B5C  arm
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   BMP_WIN_ClearScreen  0x020456F8  arm
 *   BMP_WIN_GetBgLayer  0x02045730  arm
 *   BG_SYS_PushTile  0x020409B4  arm
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/PMS_DRAW_ClearElem.c \
 *       --func PMS_DRAW_ClearElem --addr 0x0202E38C --cc 1.1p1 --thumb
 */

typedef unsigned int u32;

struct Obj0202E38C {
    u32 f00;
    u32 f04;
    u32 f08[2];
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1c;
    u32 f20[2];
};

struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *a);
typedef unsigned char  u8;
struct CharBuf;
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void BMP_WIN_TransferChars(struct Descriptor *a);
extern void BMP_WIN_ClearScreen(struct Descriptor *d);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern void BG_SYS_PushTile(u32 index);
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *a, unsigned int b);

void PMS_DRAW_ClearElem(struct Obj0202E38C *obj, u32 a1)
{
    u32 h;
    int i;

    BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)obj->f00)), 0);
    if (a1 != 0) {
        BMP_WIN_TransferChars((struct Descriptor *)obj->f00);
        h = obj->f00;
        BMP_WIN_ClearScreen((struct Descriptor *)h);
        BG_SYS_PushTile(BMP_WIN_GetBgLayer((struct Descriptor *)h));
    }
    for (i = 0; i < 2; i++) {
        CLACT_SetActorDrawEnable((struct Obj *)obj->f08[i], 0);
        obj->f20[i] = 0;
    }
    obj->f10 = 0;
    obj->f14 = 0;
    obj->f18 &= ~1;
    obj->f18 &= ~2;
}

/*
 * function: ZUKAN_DETAIL_FORM_UpdateState
 * address:  0x021C5D64
 * packet:   pkt_ov208_021C5D64
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ZUKAN_DETAIL_COMMON_GetWorkPtr  0x021BC3B4  thumb
 *   ZUKAN_DETAIL_FORM_HandleTouchArrows  0x021C6760  thumb
 *   ov208_func_021C526C  0x021C526C  thumb
 *   ov208_func_021C5B00  0x021C5B00  thumb
 *   ov208_func_021C51D4  0x021C51D4  thumb
 *   ov208_func_021C7448  0x021C7448  thumb
 *   ZUKAN_DETAIL_FORM_HandleStateEvent  0x021C5F34  thumb
 *   KEY_GetTrg  0x020362DC  arm
 *   TOUCHPANEL_GetPointTrg  0x02035D20  arm
 *   ov208_func_021C7CE8  0x021C7CE8  thumb
 *   ZUKAN_DETAIL_FORM_PlaceSideModels  0x021C7534  thumb
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   UI_SetInputMode  0x020355D8  arm
 *   ov208_func_021BDC48  0x021BDC48  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Ov208Mdl {
    u32 obj;
    u32 f4;
    u8  pos[0x3c];
};

extern int ZUKAN_DETAIL_COMMON_GetWorkPtr(int *p);
extern u32  ZUKAN_DETAIL_FORM_HandleTouchArrows(u16 *heap, u8 *p, int key);
extern void ov208_func_021C526C(u16 *heap, u8 *p, int key);
extern void ov208_func_021C5B00(u16 *heap, u8 *p, int key);
extern void ov208_func_021C51D4(struct Ov208Mdl *m);
extern void ov208_func_021C7448(u16 *heap, u8 *p, int key);
extern void ZUKAN_DETAIL_FORM_HandleStateEvent(u16 *heap, u8 *p, int key, int ev);
extern u32  KEY_GetTrg(void);
extern u32 TOUCHPANEL_GetPointTrg(u32 *outA, u32 *outB);
extern void ov208_func_021C7CE8(u16 *heap, u8 *p, int key);
extern void ZUKAN_DETAIL_FORM_PlaceSideModels(u16 *heap, u8 *p, int key);
extern void GFL_USE_PlaySeDefaultVolume(u32 se);
extern void UI_SetInputMode(int v);
extern void ov208_func_021BDC48(void *scene, u32 on);

#define W(o) (*(u32 *)(p + (o)))
#define H(o) (*(u16 *)(p + (o)))
#define MDL(i) ((struct Ov208Mdl *)(p + 0xc) + (i))

void ZUKAN_DETAIL_FORM_UpdateState(u16 *heap, u8 *p, int key)
{
    u32 x;
    u32 y;
    void *scene;
    int touch;
    int ok;
    u32 r;
    u8 i;

    scene = (void *)ZUKAN_DETAIL_COMMON_GetWorkPtr((int *)key);
    switch (W(0x6b8)) {
    case 0:
        if (W(0x6b4) == 0)
            break;
        r = ZUKAN_DETAIL_FORM_HandleTouchArrows(heap, p, key);
        if (r != 5) {
            switch (r) {
            case 0:
                ov208_func_021C526C(heap, p, key);
                return;
            case 1:
                ov208_func_021C5B00(heap, p, key);
                for (i = 0; i < 4; i++)
                    ov208_func_021C51D4(MDL(i));
                return;
            case 2:
                W(0x6c8) = 1;
                ov208_func_021C7448(heap, p, key);
                ZUKAN_DETAIL_FORM_HandleStateEvent(heap, p, key, 1);
                return;
            case 3:
                W(0x6c8) = 0;
                ov208_func_021C7448(heap, p, key);
                ZUKAN_DETAIL_FORM_HandleStateEvent(heap, p, key, 1);
                return;
            }
        } else {
            ok = 0;
            if (KEY_GetTrg() & 1) {
                ok = 1;
                touch = 0;
            } else if (TOUCHPANEL_GetPointTrg(&x, &y) != 0 && y < 0xa8) {
                ok = 1;
                touch = 1;
            }
            if (ok != 0 && H(0x548) >= 2) {
                if ((W(0x124) != 0 && MDL(2)->obj == 0) || (W(0x124) == 0 && MDL(3)->obj == 0)) {
                    ov208_func_021C7CE8(heap, p, key);
                    W(0x6c8) = 1;
                    ZUKAN_DETAIL_FORM_PlaceSideModels(heap, p, key);
                }
                ZUKAN_DETAIL_FORM_HandleStateEvent(heap, p, key, 2);
                GFL_USE_PlaySeDefaultVolume(0x54c);
                UI_SetInputMode(touch);
                ov208_func_021BDC48(scene, 0);
                return;
            }
        }
        break;
    case 4:
        if (W(0x6b4) == 0 || W(0x69c) != 0)
            break;
        r = ZUKAN_DETAIL_FORM_HandleTouchArrows(heap, p, key);
        if (r != 5) {
            switch (r) {
            case 0:
                ov208_func_021C526C(heap, p, key);
                return;
            case 1:
                ov208_func_021C5B00(heap, p, key);
                for (i = 0; i < 4; i++)
                    ov208_func_021C51D4(MDL(i));
                break;
            default:
                return;
            }
        }
        break;
    }
}

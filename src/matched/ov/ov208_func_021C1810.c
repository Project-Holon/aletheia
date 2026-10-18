/*
 * function: ZUKAN_DETAIL_AREA_UpdateMode
 * address:  0x021C1810
 * packet:   pkt_ov208_021C1810
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   ov208_func_021C1920  0x021C1920  thumb  ov208
 *   ov208_func_021C1FE0  0x021C1FE0  thumb  ov208
 *   ZUKAN_DETAIL_AREA_FinishHideOverlay  0x021C2090  thumb  ov208
 *   ov208_func_021C20C0  0x021C20C0  thumb  ov208
 *   ov208_func_021C21D0  0x021C21D0  thumb  ov208
 *   ZUKAN_DETAIL_AREA_RequestBlendRestore  0x021C2228  thumb  ov208
 *   ZUKAN_DETAIL_AREA_NoOpOverlay  0x021C2234  thumb  ov208
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef short          s16;
typedef int            s32;

extern void ov208_func_021C1920(u16 *heap, u8 *p, int key, int mode);
extern void ov208_func_021C1FE0(u16 *heap, u8 *p, int key);
extern void ZUKAN_DETAIL_AREA_FinishHideOverlay(u16 *heap, u8 *p, int key);
extern void ov208_func_021C20C0(u16 *heap, u8 *p, int key);
extern void ov208_func_021C21D0(u16 *heap, u8 *p, int key);
extern void ZUKAN_DETAIL_AREA_RequestBlendRestore(u16 *heap, u8 *p, int key);
extern void ZUKAN_DETAIL_AREA_NoOpOverlay(u16 *heap, u8 *p, int key);

#define W(o) (*(u32 *)(p + (o)))

void ZUKAN_DETAIL_AREA_UpdateMode(u16 *heap, u8 *p, int key)
{
    switch (W(0x6c)) {
    case 1:
        ov208_func_021C1920(heap, p, key, 2);
        break;
    case 2:
        ov208_func_021C1920(heap, p, key, 5);
        break;
    case 3:
        switch (W(0x84)) {
        case 1:
            ov208_func_021C1FE0(heap, p, key);
            W(0x84) = 2;
            break;
        case 2:
            ZUKAN_DETAIL_AREA_FinishHideOverlay(heap, p, key);
            W(0x84) = 3;
            break;
        case 3:
            ov208_func_021C20C0(heap, p, key);
            W(0x84) = 0;
            ov208_func_021C1920(heap, p, key, 0);
            break;
        }
        break;
    case 4:
        switch (W(0x84)) {
        case 1:
            ov208_func_021C21D0(heap, p, key);
            W(0x84) = 2;
            break;
        case 2:
            ZUKAN_DETAIL_AREA_RequestBlendRestore(heap, p, key);
            W(0x84) = 3;
            break;
        case 3:
            ZUKAN_DETAIL_AREA_NoOpOverlay(heap, p, key);
            W(0x84) = 0;
            break;
        }
        break;
    case 6:
        ov208_func_021C1920(heap, p, key, 7);
        break;
    case 7:
        ov208_func_021C1920(heap, p, key, 0);
        break;
    case 8:
        switch (W(0x84)) {
        case 1:
            ov208_func_021C1FE0(heap, p, key);
            W(0x84) = 2;
            break;
        case 2:
            ZUKAN_DETAIL_AREA_FinishHideOverlay(heap, p, key);
            W(0x84) = 3;
            break;
        case 3:
            ov208_func_021C20C0(heap, p, key);
            W(0x84) = 0;
            ov208_func_021C1920(heap, p, key, 5);
            break;
        }
        break;
    }
}

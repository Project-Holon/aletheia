/*
 * function: func_021B9674
 * address: 0x021B9674
 * packet: pkt_ov223_021B9674
 * region: ov223
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   FADE_Start 0x0204E720 arm
 *   func_020355D8 0x020355D8 arm
 *   FADE_SetSpeed 0x0204E6F4 arm
 *   func_020315D4 0x020315D4 arm
 *   GFL_HEAP_DeleteChecked 0x020306F0 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;
extern void FADE_Start(u32 a, s32 b, s32 c, s32 d);
extern void func_020355D8(u32 v);
struct S020315D4;
extern void FADE_SetSpeed(s32 a);
extern void func_020315D4(struct S020315D4 *p);
extern void GFL_HEAP_DeleteChecked(unsigned int heap);
int func_021B9674(void *a, int unused1, int unused2, u8 *ctx)
{
    u16 v;
    FADE_Start(0xC, 0x10, 0x10, 0);
    func_020355D8(*(u32 *)(ctx + 8));
    FADE_SetSpeed(*(u32 *)(ctx + 0x874));
    switch (*(u32 *)(ctx + 0x228)) {
    case 0:
        ***(u16 ***)(ctx + 4) = 0;
        break;
    case 1:
        v = 1;
    st:
        ***(u16 ***)(ctx + 4) = v;
        break;
    case 2:
        v = 2;
        goto st;
    default:
        ***(u16 ***)(ctx + 4) = 0;
        break;
    }
    *(u32 *)(*(u8 **)(ctx + 4) + 4) = *(u32 *)(ctx + 0x228);
    func_020315D4(a);
    GFL_HEAP_DeleteChecked(0x87);
    return 1;
}

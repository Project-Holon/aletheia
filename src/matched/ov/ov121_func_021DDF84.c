/*
 * function: MYSTERY_ALBUM_ResetIntro
 * address: 0x021DDF84
 * packet: pkt_ov121_021DDF84
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * blocker: SDK-owned G2_ChangeBlendAlpha (ARM ov121 021DDC30) and
 *   G2S_ChangeBlendAlpha (ARM ov121 021DDC44) lack code witnesses.
 *   sdk/TwlSDK/include/nitro/gx/g2.h static inline definitions match the
 *   ARM bodies (orr r0,r0,r1,lsl #8; strh to 04000052 / 04001052).
 *   Parent confirmed the integrator ownership despite their absence from SDK union.
 * extent: unlabelled boolean accessor MYSTERY_ALBUM_IsIntroIdle at 0x021DE014 follows.
 * symbols:
 *   func_021DC024 0x021DC024 thumb ov121
 *   func_0204B84C 0x0204B84C arm
 *   CLACT_GetPaletteVramAddress 0x0204AEF4 arm
 *   MYSTERY_ALBUM_SetBlendMain 0x021DDC30 arm ov121
 *   MYSTERY_ALBUM_SetBlendSub 0x021DDC44 arm ov121
 *   func_02082A48 0x02082A48 arm
 *   func_02082A60 0x02082A60 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern int func_021DC024(void *);
extern void func_0204B84C(void *,u8);
typedef unsigned int   u32;
extern int CLACT_GetPaletteVramAddress(u32 idx, u32 alternate);
extern void MYSTERY_ALBUM_SetBlendMain(int,int);
extern void MYSTERY_ALBUM_SetBlendSub(int,int);
extern void func_02082A48(int,void *,int);
extern void func_02082A60(void *,const void *,int);
void MYSTERY_ALBUM_ResetIntro(char *p)
{
    char *palette;
    void (*blend)(int,int);
    if (func_021DC024(p)==1) {
        *(u16 *)(p+0xdc)=0;
        *(u16 *)(p+0xde)=0;
        func_0204B84C(*(void **)(*(char **)(p+0x11c)+0x20),*(unsigned *)(*(char **)(p+0x11c)+0x8c));
        if (*(int *)(*(char **)(p+0x11c)+0x84)) {
            palette=(char *)(CLACT_GetPaletteVramAddress((u32)(*(void **)(*(char **)(p+0x11c)+0x10)),*(int *)(*(char **)(p+0x11c)+0x98))+0x05000200);
            blend=MYSTERY_ALBUM_SetBlendMain;
        } else {
            palette=(char *)(CLACT_GetPaletteVramAddress((u32)(*(void **)(*(char **)(p+0x11c)+0x10)),*(int *)(*(char **)(p+0x11c)+0x98))+0x05000600);
            blend=MYSTERY_ALBUM_SetBlendSub;
        }
        blend(2,12);
        func_02082A48(0,*(char **)(p+0x11c)+0x44,32);
        func_02082A60(*(char **)(p+0x11c)+0x44,palette,32);
    }
}

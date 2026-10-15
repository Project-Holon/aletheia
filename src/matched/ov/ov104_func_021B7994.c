/*
 * function: IRC_RHYTHM_InitBackgrounds
 * address: 0x021B7994
 * packet: pkt_ov104_021B7994
 * region: ov104
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * prototype: Observed byte truncations require u8 extern arguments at all three BG calls.
 * prototype: Incoming heap is u16, forwarded unchanged to narrow stack arguments.
 * symbols:
 *   BG_SYS_Create 0x0203F8F4 arm
 *   BMP_WIN_Init 0x02045088 arm
 *   func_0203FC28 0x0203FC28 arm
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   func_020414AC 0x020414AC arm
 *   func_02040588 0x02040588 arm
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   BG_SYS_Init 0x02040C14 arm
 *   func_02049740 0x02049740 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   func_02049B40 0x02049B40 arm
 *   sRhythmDisplayConfig 0x021B8F30 data ov104
 *   sRhythmBackgroundLayers 0x021B8F5C data
 *   sRhythmBackgroundTemplates 0x021B8FB4 data
 *   sRhythmBackgroundTypes 0x021B8F40 data ov104
 */
#include "../include/Obj22217.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef enum { BG0=0 } BgId;
struct DispConfig;
struct BgTemplate { u8 bytes[32]; };
extern struct DispConfig sRhythmDisplayConfig;
extern const u32 sRhythmBackgroundLayers[];
extern const struct BgTemplate sRhythmBackgroundTemplates[];
extern const u32 sRhythmBackgroundTypes[];
extern void BG_SYS_Create(u16);
extern void BMP_WIN_Init(u16);
extern void func_0203FC28(struct DispConfig *);
extern void BG_SYS_InitBgLayer(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_020414AC(u8);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void BG_SYS_Init(u32,u32,u32,u32);
extern u32 func_02049740(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u16 flags);
extern void ARC_TOOL_DeleteHandle(void *);
extern void func_02049B40(u32,u32,u32,u32,u32,u16);
void IRC_RHYTHM_InitBackgrounds(void *p,u16 heap) {
 int i; BgId bg; void *archive;
 BG_SYS_Create(heap);
 BMP_WIN_Init(heap);
 func_0203FC28(&sRhythmDisplayConfig);
 for(i=0;i<7;i++) {
  bg=sRhythmBackgroundLayers[i];
  BG_SYS_InitBgLayer((u8)bg,&sRhythmBackgroundTemplates[i],(u8)sRhythmBackgroundTypes[i]);
  func_020414AC(bg);
  func_02040588(bg,1);
 }
 archive=func_020490F4(0x5e,heap);
 func_02049B68((void *)((u32)archive),1,0,0,0,heap);
 func_02049B68((void *)((u32)archive),1,4,0,0,heap);
 func_02049658((void *)((u32)archive),0x24,1,0,0,0,heap);
 func_02049658((void *)((u32)archive),0,6,0,0,0,heap);
 func_02049658((void *)((u32)archive),0x30,4,0,0,0,heap);
 func_020498F4((void *)((u32)archive),0x25,1,0,0,0,heap);
 func_020498F4((void *)((u32)archive),4,6,0,0,0,heap);
 func_020498F4((void *)((u32)archive),0x2f,4,0,0,0,heap);
 BG_SYS_Init(5,0,1,0);
 ((struct Obj22217 *)p)->f0=func_02049740((void *)((u32)archive),0x31,5,0,0,heap);
 ARC_TOOL_DeleteHandle(archive);
 func_02049B40(0x17,5,0,0x1a0,0x20,heap);
 BG_SYS_Init(2,0,1,0);
}

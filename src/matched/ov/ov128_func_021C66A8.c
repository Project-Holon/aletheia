/*
 * function: Wf2dmapFriend_InitBg
 * address: 0x021C66A8
 * packet: pkt_ov128_021C66A8
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * calls: Heap arguments are full-width here: the caller does not truncate.
 * symbols:
 *   BG_SYS_Create 0x0203F8F4 arm
 *   BG_SYS_SetGraphicsMode 0x0203FC28 arm
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   BG_SYS_InitRun 0x02040B94 arm
 *   BG_SYS_ClearLayer 0x0204152C arm
 *   func_02040588 0x02040588 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   gWf2dmapDispConfig 0x021CA664 data a4
 *   gWf2dmapBgTemplates 0x021CA718 data a4
 */
#include "../include/Obj04504.h"
typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct {u32 a,b,c,d;} DispConfig;
extern const DispConfig gWf2dmapDispConfig;
extern const u8 gWf2dmapBgTemplates[][32];
extern void BG_SYS_Create(u32);
struct BgTemplate;
struct DispConfig;
extern void BG_SYS_SetGraphicsMode(struct DispConfig *cfg);
extern void BG_SYS_InitBgLayer(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void BG_SYS_InitRun(u8,u32,u32,u32);
extern void BG_SYS_ClearLayer(int channel, u16 val);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_02049B68(void *,u32,u32,u32,u32,u32);
extern void func_02049658(void *,u32,u32,u32,u32,u32,u32);
extern void func_020498F4(void *,u32,u32,u32,u32,u32,u32);
void Wf2dmapFriend_InitBg(char *p,int heap)
{
    DispConfig config;
    int i;
    BG_SYS_Create(heap);
    config=gWf2dmapDispConfig;
    BG_SYS_SetGraphicsMode((struct DispConfig *)(&config));
    for(i=0;i<5;i++) {
        BG_SYS_InitBgLayer((u8)i,(const struct BgTemplate *)gWf2dmapBgTemplates[i],0);
        BG_SYS_InitRun(i,32,0,heap);
        BG_SYS_ClearLayer((u8)i,0);
        func_02040588(i,1);
    }
    func_02049B68(((struct Obj04504 *)p)->f8,0,0,0,192,heap);
    func_02049B68(((struct Obj04504 *)p)->f8,0,4,0,192,heap);
    func_02049658(((struct Obj04504 *)p)->f8,3,0,0,0,0,heap);
    func_02049658(((struct Obj04504 *)p)->f8,3,2,0,0,0,heap);
    func_02049658(((struct Obj04504 *)p)->f8,3,4,0,0,0,heap);
    func_020498F4(((struct Obj04504 *)p)->f8,5,0,0,0,0,heap);
    func_020498F4(((struct Obj04504 *)p)->f8,14,4,0,0,0,heap);
}

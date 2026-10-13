/*
 * function: WIFICLUBACTOR_Exit
 * address:  0x021B9670
 * packet:   pkt_ov099_021B9670
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C5F30  0x021C5F30  thumb  ov127
 *   WIFICLUBACTOR_ExitLayer  0x021B9DB0  thumb  ov099
 *   WIFICLUBACTOR_ExitBlink  0x021BA648  thumb  ov099
 *   WIFICLUBACTOR_FreeAllActors  0x021B9B80  thumb  ov099
 *   WIFICLUBACTOR_ExitSpriteManager  0x021B9D5C  thumb  ov099
 *   func_021C48C0  0x021C48C0  thumb  ov127
 *   func_021C47E4  0x021C47E4  thumb  ov127
 *   WIFICLUBACTOR_ExitSprites  0x021B9DD4  thumb  ov099
 *   WIFICLUBACTOR_NoOpExit  0x021B9E08  thumb  ov099
 *   MI_CpuFill8  0x02082BCC  arm
 */
#include "../include/Obj07938.h"

typedef unsigned char  u8;
extern void func_021C5F30(u8 *p);
extern void WIFICLUBACTOR_ExitLayer(char *p);
extern void WIFICLUBACTOR_ExitBlink(int unused, void *p);
extern void WIFICLUBACTOR_FreeAllActors(char *p);
extern void WIFICLUBACTOR_ExitSpriteManager(char *p);
extern void func_021C48C0(u8 *p);
extern void func_021C47E4(u8 *p);
extern void WIFICLUBACTOR_ExitSprites(void *a);
extern void WIFICLUBACTOR_NoOpExit(int);
extern void MI_CpuFill8(void *p, int v, int n);

void WIFICLUBACTOR_Exit(char *p)
{
    func_021C5F30((u8 *)(((struct Obj07938 *)p)->f59C));
    WIFICLUBACTOR_ExitLayer(p);
    WIFICLUBACTOR_ExitBlink((int)p, p + 0x574);
    WIFICLUBACTOR_FreeAllActors(p);
    WIFICLUBACTOR_ExitSpriteManager(p);
    func_021C48C0((u8 *)(((struct Obj07938 *)p)->f58C));
    func_021C47E4((u8 *)(((struct Obj07938 *)p)->f588));
    WIFICLUBACTOR_ExitSprites(p + 0x14);
    WIFICLUBACTOR_NoOpExit(((struct Obj07938 *)p)->f10);
    MI_CpuFill8(p, 0, 0x5a0);
}

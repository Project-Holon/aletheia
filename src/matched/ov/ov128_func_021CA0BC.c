/*
 * function: func_021CA0BC
 * address: 0x021CA0BC
 * packet: pkt_ov128_021CA0BC
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BLINK_PALANM_Create 0x0202E940 thumb
 *   BLINK_PALANM_LoadPalettes 0x0202E9AC thumb
 */
#include "../include/Obj03812.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct CodeIn;
extern struct CodeIn *BLINK_PALANM_Create(u16 a0, u16 a1, u32 a2, u16 heap);
extern void BLINK_PALANM_LoadPalettes(struct CodeIn *p, u8 *a1, u32 a2, u32 a3, u32 a4);
void func_021CA0BC(u8 *p,u16 heap)
{
    ((struct Obj03812 *)p)->f184=BLINK_PALANM_Create(48,16,0,heap);
    BLINK_PALANM_LoadPalettes(((struct Obj03812 *)p)->f184,*(u8 * *)&((struct Obj03812 *)p)->f8,0,32,48);
    ((struct Obj03812 *)p)->f188=BLINK_PALANM_Create(16,16,0xfffe,heap);
    BLINK_PALANM_LoadPalettes(((struct Obj03812 *)p)->f188,*(u8 * *)&((struct Obj03812 *)p)->f8,2,0,16);
}

/*
 * function: func_021F5518
 * address: 0x021F5518
 * packet: pkt_ov112_021F5518
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two zero alignment bytes at021F55F6 before existing021F55F8.
 * lever: keep D30 result wide until the byte-width D58 call argument.
 * prototype: empty hook185F4 retains original r0 input; D58 byte second argument is original result truncation at5518+1e/+20.
 * symbols:
 *   POKE_TOOL_GetBoxParam 0x020185F4 thumb
 *   func_02019D30 0x02019D30 thumb
 *   func_02019D58 0x02019D58 thumb
 *   POKEGRA_GetCbrArcIndex 0x0202D09C thumb
 *   func_0202D0D4 0x0202D0D4 thumb
 *   POKEGRA_GetCelArcIndex 0x0202D110 thumb
 *   POKEGRA_GetAnmArcIndex 0x0202D144 thumb
 *   POKEGRA_GetMCelArcIndex 0x0202D178 thumb
 *   POKEGRA_GetMAnmArcIndex 0x0202D1AC thumb
 *   POKEGRA_GetNcecArcIndex 0x0202D1E0 thumb
 */
#include "../include/Obj04459.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *POKE_TOOL_GetBoxParam(void *p);
extern u32 func_02019D30(u32, u32);
extern int func_02019D58(u16 a, int b);
extern int POKEGRA_GetCbrArcIndex(u32,u32,u32,u32,u32,u32,u32);
extern int func_0202D0D4(u32,u32,u32,u32,u32,u32,u32);
extern int POKEGRA_GetCelArcIndex(u32,u32,u32,u32,u32,u32,u32);
extern int POKEGRA_GetAnmArcIndex(u32,u32,u32,u32,u32,u32,u32);
extern int POKEGRA_GetMCelArcIndex(u32,u32,u32,u32,u32,u32,u32);
extern int POKEGRA_GetMAnmArcIndex(u32,u32,u32,u32,u32,u32,u32);
extern int POKEGRA_GetNcecArcIndex(u32,u32,u32,u32,u32,u32,u32);
void func_021F5518(u8 *p, u32 *out, u32 k)
{
    u32 a, c, d, flag;
    int b;
    u32 n;
    POKE_TOOL_GetBoxParam(((struct Obj04459 *)p)->f4);
    a = ((struct Obj04459 *)p)->f8;
    n = func_02019D30(a, p[11]);
    c = p[10];
    d = p[12];
    flag = 0;
    b = func_02019D58(((struct Obj04459 *)p)->f8, (u8)n);
    if (k == 1) flag = 1;
    out[0] = 52;
    out[1] = POKEGRA_GetCbrArcIndex(out[0],a,b,c,d,flag,0);
    out[2] = func_0202D0D4(out[0],a,b,c,d,flag,0);
    out[3] = POKEGRA_GetCelArcIndex(out[0],a,b,c,d,flag,0);
    out[4] = POKEGRA_GetAnmArcIndex(out[0],a,b,c,d,flag,0);
    out[5] = POKEGRA_GetMCelArcIndex(out[0],a,b,c,d,flag,0);
    out[6] = POKEGRA_GetMAnmArcIndex(out[0],a,b,c,d,flag,0);
    out[7] = POKEGRA_GetNcecArcIndex(out[0],a,b,c,d,flag,0);
    out[8] = ((struct Obj04459 *)p)->f10;
}

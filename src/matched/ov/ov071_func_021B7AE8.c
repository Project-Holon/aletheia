/*
 * function: MONOLITH_TOOL_SLOT_SELECT_MoveCursor
 * address: 0x021B7AE8
 * packet: pkt_ov071_021B7AE8
 * region: ov071
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021BA8A0 0x021BA8A0 data a4
 *   func_0204B404 0x0204B404 arm
 */
typedef unsigned short u16;
extern const struct Pair { int x, y; } d_021BA8A0[];
typedef unsigned int   u32;
struct Obj;
struct Vec2;
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
void MONOLITH_TOOL_SLOT_SELECT_MoveCursor(void **p,int i) { u16 t[2];t[0]=d_021BA8A0[i].x;t[1]=d_021BA8A0[i].y;func_0204B404(p[31],(const struct Vec2 *)t,1);}

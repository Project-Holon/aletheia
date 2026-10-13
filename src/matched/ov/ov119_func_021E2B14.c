/*
 * function: func_021E2B14
 * address: 0x021E2B14
 * packet: pkt_ov119_021E2B14
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02048BC4 0x02048BC4 arm
 *   func_02048C58 0x02048C58 arm
 *   G3D_SYSTEM_SetProjection 0x02046858 arm
 *   d_021E799C 0x021E799C data a4
 *   d_021F4560 0x021F4560 data a4
 *   d_021E7B1C 0x021E7B1C data a4
 *   d_020A1DF8 0x020A1DF8 data a2
 */
typedef struct {int a,b,c,d,e,f,g,h;} Config;
extern const Config d_021E7B1C;
extern char d_021E799C[];
extern void *d_021F4560;
extern short d_020A1DF8[];
typedef unsigned int   u32;
struct LightSet;
struct LightSlot;
extern struct LightSlot *func_02048BC4(const struct LightSet *s, u32 heap);
struct LightSlot;
extern void func_02048C58(struct LightSlot *slots);
extern void G3D_SYSTEM_SetProjection(const u32 *src);
void func_021E2B14(int a) {
    Config c;
    d_021F4560=func_02048BC4((const struct LightSet *)d_021E799C,a);
    func_02048C58(d_021F4560);
    c=d_021E7B1C;
    c.b=d_020A1DF8[12]; c.c=d_020A1DF8[13];
    G3D_SYSTEM_SetProjection((const u32 *)(&c));
}

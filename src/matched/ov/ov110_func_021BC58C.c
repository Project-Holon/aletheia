/*
 * function: func_021BC58C
 * address: 0x021BC58C
 * packet: pkt_ov110_021BC58C
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BC564 0x021BC564 thumb ov110
 *   func_02045770 0x02045770 arm
 *   func_02043AF4 0x02043AF4 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef struct { s16 x, y; } Vec2;
extern void func_021BC564(s16 *p, s16 *out);
struct Bmp;
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
extern void func_02043AF4(struct Bmp *b, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6);
void func_021BC58C(void *p, const Vec2 *a)
{
    Vec2 pos;
    func_021BC564((s16 *)a, (s16 *)(&pos));
    func_02043AF4(func_02045770(p), pos.x, pos.y, 0x60, 16, 14);
}

/*
 * function: func_021BE0F4
 * address: 0x021BE0F4
 * packet: pkt_ov203_021BE0F4
 * region: ov203
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: twin of ov204_func_021BE03C.c (3D setup, texSize 2, plttSize 4,
 * light set 0x021BFB48); u8 heap parameter.
 * symbols:
 *   func_02046440 0x02046440 arm
 *   func_02048BC4 0x02048BC4 arm
 *   func_02048C58 0x02048C58 arm
 *   func_021BDD40 0x021BDD40 thumb ov203
 *   d_021BFB48 0x021BFB48 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
struct LightSet; struct LightSlot;
extern void func_02046440(u32 texMode, u32 texSize, u32 plttMode, u32 plttSize,
                          u16 fifoSize, s16 heap, void (*setup)(void));
extern struct LightSlot *func_02048BC4(const struct LightSet *s, u32 heap);
extern void func_02048C58(struct LightSlot *slots);
extern void func_021BDD40(void);
extern const struct LightSet d_021BFB48;
void func_021BE0F4(char *p, u8 heap)
{
    func_02046440(0, 2, 0, 4, 0, heap, func_021BDD40);
    *(struct LightSlot **)(p + 4) = func_02048BC4(&d_021BFB48, heap);
    func_02048C58(*(struct LightSlot **)(p + 4));
}

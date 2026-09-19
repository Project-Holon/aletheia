/*
 * function: sub_02010360
 * address:  0x02010360
 * packet:   pkt_02010360
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * blocking: label/overlay 0x0217963C (no witness outside range, ov009|ov014 ambiguous);
 *           data 0x020461E0 and ov_id_0F are literal-only.
 *
 * symbols:
 *   func_02034714  0x02034714  arm
 *   func_0203D7C8  0x0203D7C8  arm
 *   func_0205D010  0x0205D010  arm
 *   func_02034AC4  0x02034AC4  arm
 *   func_0217963C  0x0217963C  thumb
 *   g020A7240      0x020A7240  data
 *   g020A7244      0x020A7244  data
 *   g020461E0      0x020461E0  data
 *   g0201045D      0x0201045D  data
 *   ov_id_0F       0x0000000F  data
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void  func_02034714(void *a, int b, void *c);
extern u8   *func_0203D7C8(void *a, int b, void *c, int d);
extern int   func_0205D010(void);
extern void  func_02034AC4(void *id);
extern void  func_0217963C(void *a);
extern u8    g020A7240[];
extern u8    g020A7244[];
extern u8    g020461E0[];
extern u8    g0201045D[];
extern u8    ov_id_0F[];

u8 *sub_02010360(int idx, void *a1)
{
    u8 *p;

    if (idx > 4) {
        func_02034714(g020A7240, 0, g020A7240);
    }
    if (*(void **)g020461E0 != 0) {
        func_02034714(g020A7240, 0, g020A7240);
    }
    p = func_0203D7C8(a1, 0x328, g020A7244, 0x49);
    *(u16 *)(p + 0x310) = (u16)idx;
    *(u32 *)(p + 0x300) = (u32)func_0203D7C8(a1, func_0205D010(), g020A7244, 0x4c);
    func_0217963C(g0201045D);
    *(u8 **)g020461E0 = p;
    *(u32 *)(p + 0x304) = *(u32 *)(g020461E0 + 4);
    func_02034AC4(ov_id_0F);
    return p;
}

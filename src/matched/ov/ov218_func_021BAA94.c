/*
 * function: func_021BAA94
 * address: 0x021BAA94
 * packet: pkt_ov218_021BAA94
 * region: ov218
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * prototype: heap stack arguments preserve original raw r4 stores; widen the legacy46440 signed-halfword sixth and48A24 halfword twelfth parameters, because caller has no truncation.
 * symbols:
 *   G3D_SYSTEM_Init 0x02046440 arm
 *   G3D_CAMERA_Create 0x02048A24 arm
 *   func_021BA7A4 0x021BA7A4 thumb ov218
 *   d_021BAE94 0x021BAE94 data a4
 *   d_021BAE88 0x021BAE88 data a4
 *   d_021BAEA0 0x021BAEA0 data a4
 *   d_020A1EB8 0x020A1EB8 data a2
 */
typedef struct Vec3 { unsigned x, y, z; } Vec3;
extern const Vec3 d_021BAE94, d_021BAE88, d_021BAEA0;
extern const short d_020A1EB8[];
extern void func_021BA7A4(void);
extern void G3D_SYSTEM_Init(unsigned, unsigned, unsigned, unsigned, unsigned short, unsigned, void (*)(void));
extern unsigned *G3D_CAMERA_Create(unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, const Vec3 *, const Vec3 *, const Vec3 *, unsigned);
void func_021BAA94(unsigned **out, unsigned heap)
{
    G3D_SYSTEM_Init(0, 1, 0, 1, 0, heap, func_021BA7A4);
    *out = G3D_CAMERA_Create(0, d_020A1EB8[6], d_020A1EB8[7], 5461, 0, 4096, 4194304, 0, &d_021BAE94, &d_021BAE88, &d_021BAEA0, heap);
}

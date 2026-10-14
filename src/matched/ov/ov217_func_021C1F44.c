/*
 * function: CircleGraph_ProjectToScreen
 * address:  0x021C1F44
 * packet:   pkt_ov217_021C1F44
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0206DF3C  0x0206DF3C  arm
 *   _fflt          0x0209BDBC  arm
 *   _ffix          0x0209C494  arm
 *   _fadd          0x0209C95C  arm
 *   _fsub          0x0209CB8C  arm
 *   _fdiv          0x0209CE10  arm
 *   _fmul          0x0209C77C  arm
 *   _fgr           0x0209BBB0  arm
 */

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { s32 x; s32 y; s32 z; } VecFx32;

extern void func_0206DF3C(const VecFx32 *pos, s32 *px, s32 *py);

#define FX_FX32_TO_F32(x) ((f32)((x) / 4096.0f))
#define FX32_CONST(x) ((s32)(((x) > 0) ? ((x) * 4096.0f + 0.5f) : ((x) * 4096.0f - 0.5f)))

void CircleGraph_ProjectToScreen(const s16 *p, s32 *px, s32 *py)
{
    VecFx32 v;
    v.x = FX32_CONST(FX_FX32_TO_F32(p[0]));
    v.y = FX32_CONST(FX_FX32_TO_F32(p[1]));
    v.z = FX32_CONST(FX_FX32_TO_F32(p[2]));
    func_0206DF3C(&v, px, py);
}

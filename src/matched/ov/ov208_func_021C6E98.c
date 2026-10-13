/*
 * function: ov208_func_021C6E98
 * address:  0x021C6E98
 * packet:   pkt_ov208_021C6E98
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Four models ease between their pose 3 and pose 4 positions while 0x6C0 runs
 * to 0x8000, with a sine bob in y (+16 for the first pair, -16 for the second).
 * The entry fields go through byte-pointer arithmetic, not a struct array: the
 * image keeps `sel * 16` but rebuilds `p + sel * 16` for the species load. The
 * shiny flag is a ternary statement into a local, which keeps the forms load
 * first; passed straight as `!= 0` the flag is evaluated before the forms.
 *
 * symbols:
 *   ov208_func_021C5F34  0x021C5F34  thumb  ov208
 *   func_021C80AC        0x021C80AC  thumb
 *   func_021C80CC        0x021C80CC  thumb
 *   MCSS_SetPosition        0x02015C48  thumb
 *   func_021C50F8        0x021C50F8  thumb
 *   func_021C7D80        0x021C7D80  thumb
 *   func_021C5CF0        0x021C5CF0  thumb
 *   func_021C4E54        0x021C4E54  thumb
 *   func_021C4EAC        0x021C4EAC  thumb
 *   ov208_func_021C6A10  0x021C6A10  thumb  ov208
 *   func_021BC3C0        0x021BC3C0  thumb
 *   func_021BC3A4        0x021BC3A4  thumb
 *   ZUKAN_SAVE_GetFromGameData        0x0200CA1C  thumb
 *   ZUKAN_SAVE_UpdateViewFlags        0x0200CA98  thumb
 *   FX_SinCosTable_         0x020A1B38  data
 *   _fflt                0x0209BDBC  arm
 *   _fdiv                0x0209CE10  arm
 *   _fgr                 0x0209BBB0  arm
 *   _fmul                0x0209C77C  arm
 *   _fadd                0x0209C95C  arm
 *   _fsub                0x0209CB8C  arm
 *   _ffix                0x0209C494  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed int     fx32;

typedef struct {
    fx32 x;
    fx32 y;
    fx32 z;
} Vec;

typedef struct {
    float x;
    float y;
    float z;
} VecF;

extern void ov208_func_021C5F34(void *a0, u8 *p, void *ctx, int ev);
extern void func_021C80AC(int a, int b, int c);
extern void func_021C80CC(void *u, int k, VecF *v);
extern void MCSS_SetPosition(void *p, u32 *src);
extern void func_021C50F8(u32 obj, Vec *out);
extern void func_021C7D80(void *a0, u8 *p, void *ctx);
extern void func_021C5CF0(void *a0, u8 *p, void *ctx);
extern void func_021C4E54(void *a0, u8 *p, void *ctx);
extern void func_021C4EAC(void *a0, u8 *p, void *ctx);
extern void ov208_func_021C6A10(void *a0, u8 *p, void *ctx);
extern u16  func_021BC3C0(void *ctx);
struct Blk37;
extern int func_021BC3A4(int *p);
extern void *ZUKAN_SAVE_GetFromGameData(void *a);
extern void ZUKAN_SAVE_UpdateViewFlags(struct Blk37 *p, u16 id, u32 sel, u32 alt, u32 form);
extern s16  FX_SinCosTable_[];

#define W(o) (*(u32 *)(p + (o)))
#define I(o) (*(int *)(p + (o)))
#define H(o) (*(u16 *)(p + (o)))

#define FX_F32_TO_FX32(x) ((fx32)(((x) > 0) ? \
                                  ((x) * (1 << 12) + 0.5f) : \
                                  ((x) * (1 << 12) - 0.5f)))

void ov208_func_021C6E98(void *a0, u8 *p, void *ctx)
{
    Vec u;
    VecF a;
    VecF b;
    Vec v;
    VecF c;
    VecF d;
    Vec w;
    float t;
    float x;
    float y;
    int idx;
    u16 id;
    void *obj;
    u32 f;
    u32 sh;

    if (I(0x6bc) == 1) {
        I(0x6c0) += 0x400;
        if (I(0x6c0) >= 0x8000) {
            I(0x6c0) = 0x8000;
            I(0x6bc) = 0;
            ov208_func_021C5F34(a0, p, ctx, 4);
            if (H(0x548) >= 2) {
                if (W(0x94) != 0) {
                    func_021C80AC((int)(p + 0x94), 1, (int)(&u));
                    MCSS_SetPosition((void *)W(0x94), (u32 *)(&u));
                }
                if (W(0xd8) != 0) {
                    func_021C80AC((int)(p + 0xd8), 1, (int)(&u));
                    MCSS_SetPosition((void *)W(0xd8), (u32 *)(&u));
                }
                idx = W(0x124) != 0 ? 2 : 3;
                func_021C50F8(*(u32 *)(p + idx * 0x44 + 0xc), &u);
                if (W(0xc) != 0) {
                    func_021C80AC((int)(p + 0xc), 2, (int)(&u));
                    MCSS_SetPosition((void *)W(0xc), (u32 *)(&u));
                }
                if (W(0x50) != 0) {
                    func_021C80AC((int)(p + 0x50), 2, (int)(&u));
                    MCSS_SetPosition((void *)W(0x50), (u32 *)(&u));
                }
                func_021C7D80(a0, p, ctx);
                func_021C5CF0(a0, p, ctx);
                func_021C4E54(a0, p, ctx);
                func_021C4EAC(a0, p, ctx);
                ov208_func_021C6A10(a0, p, ctx);
                id = func_021BC3C0(ctx);
                obj = ZUKAN_SAVE_GetFromGameData((void *)func_021BC3A4(ctx));
                f = *(p + H(0x54e) * 16 + 0x152);
                sh = *(p + H(0x54e) * 16 + 0x153) != 0 ? 1 : 0;
                ZUKAN_SAVE_UpdateViewFlags(obj, id, f, sh, *(u16 *)(p + H(0x54e) * 16 + 0x154));
                if (H(0x548) >= 3)
                    W(0x698) = 1;
            }
        } else {
            t = FX_SinCosTable_[(I(0x6c0) >> 4) * 2] / 4096.0f;
            if (W(0xc) != 0) {
                func_021C80CC(p + 0xc, 3, &a);
                func_021C80CC(p + 0xc, 4, &b);
                x = a.x + I(0x6c0) * (b.x - a.x) / 32768.0f;
                y = a.y + 16.0f * t;
                v.x = FX_F32_TO_FX32(x);
                v.y = FX_F32_TO_FX32(y);
                v.z = FX_F32_TO_FX32(a.z);
                MCSS_SetPosition((void *)W(0xc), (u32 *)(&v));
            }
            if (W(0x50) != 0) {
                func_021C80CC(p + 0x50, 3, &a);
                func_021C80CC(p + 0x50, 4, &b);
                x = a.x + I(0x6c0) * (b.x - a.x) / 32768.0f;
                y = a.y + 16.0f * t;
                v.x = FX_F32_TO_FX32(x);
                v.y = FX_F32_TO_FX32(y);
                v.z = FX_F32_TO_FX32(a.z);
                MCSS_SetPosition((void *)W(0x50), (u32 *)(&v));
            }
            if (W(0x94) != 0) {
                func_021C80CC(p + 0x94, 3, &c);
                func_021C80CC(p + 0x94, 4, &d);
                x = d.x + I(0x6c0) * (c.x - d.x) / 32768.0f;
                y = d.y + -16.0f * t;
                w.x = FX_F32_TO_FX32(x);
                w.y = FX_F32_TO_FX32(y);
                w.z = FX_F32_TO_FX32(d.z);
                MCSS_SetPosition((void *)W(0x94), (u32 *)(&w));
            }
            if (W(0xd8) != 0) {
                func_021C80CC(p + 0xd8, 3, &c);
                func_021C80CC(p + 0xd8, 4, &d);
                x = d.x + I(0x6c0) * (c.x - d.x) / 32768.0f;
                y = d.y + -16.0f * t;
                w.x = FX_F32_TO_FX32(x);
                w.y = FX_F32_TO_FX32(y);
                w.z = FX_F32_TO_FX32(d.z);
                MCSS_SetPosition((void *)W(0xd8), (u32 *)(&w));
            }
        }
    }
}

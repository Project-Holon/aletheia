/*
 * function: func_021C6F30
 * address:  0x021C6F30
 * packet:   pkt_ov021_021C6F30
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_02188C58  0x02188C58  thumb
 *   func_0218ED54  0x0218ED54  thumb
 *   func_0218E138  0x0218E138  thumb
 *   func_0218E13C  0x0218E13C  thumb
 *   func_0218ED58  0x0218ED58  thumb
 *   _fgr           0x0209BBB0  arm
 *   _ffltu         0x0209BE04  arm
 *   _fflt          0x0209BDBC  arm
 *   _ffix          0x0209C494  arm
 *   _fmul          0x0209C77C  arm
 *   _fadd          0x0209C95C  arm
 *   _fsub          0x0209CB8C  arm
 *   _fdiv          0x0209CE10  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;
typedef int fx32;
typedef float f32;

typedef struct {
    void *f0;
    u8 f4;
    u8 pad5;
    u16 f6;
    u16 f8;
    u16 padA;
    fx32 fC;
    fx32 f10;
} Work;

extern void *func_02188C58(void *o);
extern fx32 func_0218ED54(void *o);
extern u32 func_0218E138(void *o);
extern void func_0218E13C(void *o, u32 v);
extern void func_0218ED58(void *o, fx32 v);

#define FX_FX32_TO_F32(x) ((f32)((x) / 4096.0f))
#define FX_F32_TO_FX32(x) ((fx32)(((x) > 0) ? ((x) * 4096.0f + .5f) : ((x) * 4096.0f - .5f)))

int func_021C6F30(Work *w)
{
    void *o;
    u32 save;
    f32 t;
    f32 a;
    f32 b;
    f32 v;

    o = func_02188C58(w->f0);
    switch (w->f4) {
    case 0:
        w->fC = func_0218ED54(o);
        w->f4++;
        break;
    case 1:
        w->f6++;
        save = func_0218E138(o);
        func_0218E13C(o, 0);
        t = (f32)w->f6 / (f32)w->f8;
        a = FX_FX32_TO_F32(w->fC);
        b = FX_FX32_TO_F32(w->f10);
        v = (1.0f - t) * a + t * b;
        func_0218ED58(o, FX_F32_TO_FX32(v));
        func_0218E13C(o, save);
        if (w->f8 <= w->f6)
            return 1;
        break;
    }
    return 0;
}

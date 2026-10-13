/*
 * function: G3D_SYSTEM_SetProjection
 * address:  0x02046858
 * packet:   pkt_02046858
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   _G3dSystem     0x02146A5C  data
 *   SCREENTEX_ProjectionMatrix     0x02148B54  data
 *   g_renderState     0x02148B4C  data
 *   func_0207C408  0x0207C408  arm
 *   func_0207C1D0  0x0207C1D0  arm
 *   func_0207C554  0x0207C554  arm
 *
 * Store an eight-word projection setup into the context (+0x1C mode,
 * +0x20..+0x38 parameters), then program it through one of three setup
 * calls selected by the mode; a zero +0x38 is replaced by 0x1000.  Every
 * arm clears bits 0x50 of g_renderState[0x3F] and returns on its own.
 *
 * Closed in wave 11.  What the older notes were missing:
 *   - the register-block pointer is taken into a named local (`hw`)
 *     BEFORE the dispatch; it is what lives in r4 across each call, which
 *     is why the image pushes r4 and can use it as the second prologue
 *     temporary (without it the push is {r3, lr} and the pipelined stores
 *     alternate ip/r3);
 *   - +0x38 selects between two calls per mode (0x1000 when zero, the
 *     field itself otherwise), not an OR with 0x1000;
 *   - mode 0 passes seven arguments (no +0x2C), modes 1 and 2 eight.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct G3dCtx {
    u8  pad_00[0x1c];
    u32 mode;
    u32 f20;
    u32 f24;
    u32 f28;
    u32 f2c;
    u32 f30;
    u32 f34;
    u32 f38;
};

extern struct G3dCtx *_G3dSystem;
extern u8  SCREENTEX_ProjectionMatrix[];
extern u32 g_renderState[];

extern void func_0207C408(u32 a0, u32 a1, u32 a2, u32 a3, u32 s0, u32 s1, void *s2);
extern void func_0207C1D0(u32 a0, u32 a1, u32 a2, u32 a3, u32 s0, u32 s1, u32 s2, void *s3);
extern void func_0207C554(u32 a0, u32 a1, u32 a2, u32 a3, u32 s0, u32 s1, u32 s2, void *s3);

void G3D_SYSTEM_SetProjection(const u32 *src)
{
    u32 *hw;

    _G3dSystem->mode = src[0];
    _G3dSystem->f20 = src[1];
    _G3dSystem->f24 = src[2];
    _G3dSystem->f28 = src[3];
    _G3dSystem->f2c = src[4];
    _G3dSystem->f30 = src[5];
    _G3dSystem->f34 = src[6];
    _G3dSystem->f38 = src[7];
    hw = g_renderState;

    switch (_G3dSystem->mode) {
    case 0:
        if (_G3dSystem->f38 == 0) {
            func_0207C408(_G3dSystem->f20, _G3dSystem->f24, _G3dSystem->f28, _G3dSystem->f30,
                _G3dSystem->f34, 0x1000, SCREENTEX_ProjectionMatrix);
            hw[0x3F] &= ~0x50u;
            return;
        }
        func_0207C408(_G3dSystem->f20, _G3dSystem->f24, _G3dSystem->f28, _G3dSystem->f30,
            _G3dSystem->f34, _G3dSystem->f38, SCREENTEX_ProjectionMatrix);
        hw[0x3F] &= ~0x50u;
        return;
    case 1:
        if (_G3dSystem->f38 == 0) {
            func_0207C1D0(_G3dSystem->f20, _G3dSystem->f24, _G3dSystem->f28, _G3dSystem->f2c,
                _G3dSystem->f30, _G3dSystem->f34, 0x1000, SCREENTEX_ProjectionMatrix);
            hw[0x3F] &= ~0x50u;
            return;
        }
        func_0207C1D0(_G3dSystem->f20, _G3dSystem->f24, _G3dSystem->f28, _G3dSystem->f2c,
            _G3dSystem->f30, _G3dSystem->f34, _G3dSystem->f38, SCREENTEX_ProjectionMatrix);
        hw[0x3F] &= ~0x50u;
        return;
    case 2:
        if (_G3dSystem->f38 == 0) {
            func_0207C554(_G3dSystem->f20, _G3dSystem->f24, _G3dSystem->f28, _G3dSystem->f2c,
                _G3dSystem->f30, _G3dSystem->f34, 0x1000, SCREENTEX_ProjectionMatrix);
            hw[0x3F] &= ~0x50u;
            return;
        }
        func_0207C554(_G3dSystem->f20, _G3dSystem->f24, _G3dSystem->f28, _G3dSystem->f2c,
            _G3dSystem->f30, _G3dSystem->f34, _G3dSystem->f38, SCREENTEX_ProjectionMatrix);
        hw[0x3F] &= ~0x50u;
        return;
    }
}

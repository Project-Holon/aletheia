/*
 * function: ISS_ZONE_SYS_StepFade
 * address:  0x0202BFF0
 * packet:   pkt_0202BFF0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   _ffltu  0x0209BE04  arm
 *   _fdiv   0x0209CE10  arm
 *   _fmul   0x0209C77C  arm
 *   _fsub   0x0209CB8C  arm
 *   _f2s    0x0209C494  arm
 *   GFL_USE_SetBgmTrackVolume  0x02005F24  thumb
 *
 * The record's active window: while +0x12 exceeds the running +0x14 counter,
 * bump the counter and push a percentage to the +0xe and +0x10 gauges
 * (GFL_USE_SetBgmTrackVolume).  The two gauges differ only in the numerator: the first
 * scales the counter, the second the counter brought round by one.
 *
 * Each gauge id is bound to a local before the counter is stored and before
 * the division, which is what keeps it in the callee-saved r4 across the five
 * soft-float calls; read at the call site it is reloaded instead and the
 * frame loses a register and its numbering shifts.  Both arms re-read the two
 * u16 fields rather than sharing a computed quotient, which is why each is
 * loaded and converted twice.
 *
 * The counter bump is the one spelling that matters: `o->f14 = o->f14 + 1;`
 * compiles the same increment but lands the guard's two u16 loads in the
 * opposite r0/r1 pair (and so the `adds` that follows them), four concrete
 * bytes away from the original, while `o->f14 += 1;` reproduces it.  See
 * docs/idioms/a-compound-assignment-on-a-field-flips-the-guards-register-pair.md.
 *
 * The soft-float helpers are MSL/runtime.a's; this front end names them
 * _ffltu, _fdiv, _fmul, _fsub and _f2s, which is what the relocations carry.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ISS_ZONE_SYS_StepFade.c \
 *       --func ISS_ZONE_SYS_StepFade --addr 0x0202BFF0 --thumb --cc 1.1p1
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Obj {
    u32 pad0;
    u32 pad4;
    u32 pad8;
    u8  padc[2];
    u16 fxe;
    u16 f10;
    u16 f12;
    u16 f14;
};

extern void GFL_USE_SetBgmTrackVolume(u32 a0, u32 a1);
extern float _ffltu(u32 v);
extern float _fdiv(float a, float b);
extern float _fmul(float a, float b);
extern float _fsub(float a, float b);
extern int   _f2s(float a);

void ISS_ZONE_SYS_StepFade(struct Obj *o)
{
    u16 id;

    if (o->f12 <= o->f14) {
        return;
    }
    id = o->fxe;
    o->f14 += 1;
    if (id != 0) {
        GFL_USE_SetBgmTrackVolume(id, _f2s(_fmul(127.0f,
                                      _fdiv(_ffltu(o->f14),
                                            _ffltu(o->f12)))));
    }
    id = o->f10;
    if (id != 0) {
        GFL_USE_SetBgmTrackVolume(id, _f2s(_fmul(127.0f,
                                      _fsub(1.0f,
                                            _fdiv(_ffltu(o->f14),
                                                  _ffltu(o->f12))))));
    }
}

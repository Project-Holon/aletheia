/*
 * function: func_02184680
 * address:  0x02184680
 * packet:   pkt_ov168_02184680
 * region:   ov168
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 * note (2026-10-05, wD7 lane16): still 8 bytes. Callee prototypes compared with the matched callers (no
 *   u16/int clue). The e load sinks to the last slot before the call in ours; no new form tried changed it.
 * note (2026-10-05, wD6 lane20): still 8 bytes. Tried: a3/e as one by-value struct {x, y} split over
 *   r3 and the stack (192 bytes worse, the struct is spilled with push {r0-r3}). Observation: the e load
 *   always sits just before the first call, as if it had no use before the call; the original
 *   keeps it in the param-copy order r7, r6, r5, r4.
 * note (2026-10-05, wave D5 lane 13): still DIFF, same 4 lines (stack arg e load after the pool
 *   ldr). Tried: the two conversions through a static inline toFx(int) helper; the task store
 *   nested as the argument of func_02030EE8; a2 as a struct pointer with a task field at
 *   +0x2C (void * arg). No change in any. The prologue order r7, r6, r5(e), pool, r4(a2)
 *   is a scheduler order; no source shape found that raises the e load above the pool load.
 * note (2026-10-05, wD4 lane17): still DIFF, 4 lines (stack arg e load placed after the pool ldr and movs r3). Not repeated: the earlier tries. Observation: the original emits the param copies in colour order r7,r6,r5,r4; ours defers the e load. No source lever found.
 *
 *
 * 2026-10-04 note (wave D2 lane 15): DIFF, 4 mismatching lines, the whole function body is
 * otherwise byte-identical (256 bytes, 19/19 relocations). Residue: prologue order. Original
 * loads the stack arg e into r5 (`ldr r5,[sp,#0x18]`) before the func_02184780 pool load,
 * ours emits it after `movs r3,#0` (the pool ldr, adds r4,r2 and movs r3 are shifted up by one
 * slot). Found: FX_F32_TO_FX32 macro on int (as ov021_func_0218F460), FX_MUL with an `int c`
 * temp for each trig call (evaluates the trig call before reading f, as the original does).
 * Tried, no change: const int e, local copy of e before/after the call, u32 e, declaration
 * order of o/t/c, u32 * typed a2.
 *
 * symbols:
 *   func_02030DA8  0x02030DA8  arm
 *   func_02030EE8  0x02030EE8  arm
 *   func_0203F5FC  0x0203F5FC  arm
 *   func_0204B550  0x0204B550  arm
 *   func_02184780  0x02184780  thumb  ov168
 *   _ll_mul        0x0209C054  arm
 *   _fflt          0x0209BDBC  arm
 *   _fadd          0x0209C95C  arm
 *   _fsub          0x0209CB8C  arm
 *   _ffix          0x0209C494  arm
 */
typedef unsigned short u16;
typedef unsigned int u32;
typedef int fx32;
typedef long long fx64;

typedef struct {
    u32 handle;
    u32 timer;
    fx32 x;
    fx32 y;
    fx32 z0;
    fx32 vx;
    fx32 vy;
    fx32 w0;
    fx32 w1;
    fx32 w2;
    u32 h;
    u32 task;
} Obj;

extern u32 func_02030DA8(int owner, void (*fn)(), int arg, int n);
extern Obj *func_02030EE8(u32 task);
extern int func_0203F5FC(u16 angle);
extern void func_0204B550(u32 handle, int v, int axis);
extern void func_02184780();

#define FX_F32_TO_FX32(x) \
    ((int)(((x) > 0) ? (x) * 4096 + 0.5f : (x) * 4096 - 0.5f))
#define FX_MUL(a, b) ((fx32)(((fx64)(a) * (b) + 0x800) >> 12))

void func_02184680(int a0, u32 handle, int a2, int a3, int e, int f, u32 g, u32 h, u32 i)
{
    Obj *o;
    u32 t;
    int c;

    t = func_02030DA8(a0, func_02184780, a2, 0);
    ((u32 *)a2)[0x2c / 4] = t;
    o = func_02030EE8(t);
    o->handle = handle;
    o->timer = i;
    o->x = FX_F32_TO_FX32(a3);
    o->y = FX_F32_TO_FX32(e);
    o->z0 = 0;
    c = func_0203F5FC(g + 0x5a);
    o->vx = FX_MUL(f, c);
    c = func_0203F5FC(g);
    o->vy = -FX_MUL(f, c);
    o->w0 = 0;
    o->w1 = 0;
    o->w2 = 0x6000;
    o->h = h;
    func_0204B550(o->handle, a3, 0);
    func_0204B550(o->handle, e, 1);
}

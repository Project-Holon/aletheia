/*
 * function: func_02184680
 * address:  0x02184680
 * packet:   pkt_ov168_02184680
 * region:   ov168
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note (2026-10-05, wD9r lane41): closed by the parameter width. x and y (a3, e) are s16, and
 *   CLACT_SetActorPosAxis takes an s16 second argument as in the matched sibling ov168 02184780. With an s16
 *   stack parameter the y load stays with the entry parameter copies (ldr r5,[sp,#0x18] before the
 *   pool load); an int parameter sinks it to the end of the entry block.
 * symbols:
 *   func_02030DA8  0x02030DA8  arm
 *   TCBL_IsDeletePending  0x02030EE8  arm
 *   func_0203F5FC  0x0203F5FC  arm
 *   CLACT_SetActorPosAxis  0x0204B550  arm
 *   func_02184780  0x02184780  thumb  ov168
 *   _ll_mul        0x0209C054  arm
 *   _fflt          0x0209BDBC  arm
 *   _fadd          0x0209C95C  arm
 *   _fsub          0x0209CB8C  arm
 *   _ffix          0x0209C494  arm
 */
typedef signed short s16;
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
struct S02030EE8;
extern u32 TCBL_IsDeletePending(struct S02030EE8 *p);
extern int func_0203F5FC(u32 x);
struct Actor;
extern void CLACT_SetActorPosAxis(struct Actor *actor, signed short value, u32 axis);
extern void func_02184780(void *task, int *p);

#define FX_F32_TO_FX32(x) \
    ((int)(((x) > 0) ? (x) * 4096 + 0.5f : (x) * 4096 - 0.5f))
#define FX_MUL(a, b) ((fx32)(((fx64)(a) * (b) + 0x800) >> 12))

void func_02184680(int a0, u32 handle, int a2, s16 a3, s16 e, int f, u32 g, u32 h, u32 i)
{
    Obj *o;
    u32 t;
    int c;

    t = func_02030DA8(a0, func_02184780, a2, 0);
    ((u32 *)a2)[0x2c / 4] = t;
    o = (Obj *)TCBL_IsDeletePending((struct S02030EE8 *)t);
    o->handle = handle;
    o->timer = i;
    o->x = FX_F32_TO_FX32(a3);
    o->y = FX_F32_TO_FX32(e);
    o->z0 = 0;
    c = func_0203F5FC((u16)(g + 0x5a));
    o->vx = FX_MUL(f, c);
    c = func_0203F5FC((u16)g);
    o->vy = -FX_MUL(f, c);
    o->w0 = 0;
    o->w1 = 0;
    o->w2 = 0x6000;
    o->h = h;
    CLACT_SetActorPosAxis((struct Actor *)o->handle, a3, 0);
    CLACT_SetActorPosAxis((struct Actor *)o->handle, e, 1);
}

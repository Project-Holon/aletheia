/*
 * function: func_0216CB48
 * address:  0x0216CB48
 * packet:   pkt_ov010_0216CB48
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The third parameter is u8: with it declared int the body is byte-identical
 * except that the w->owner store and the next call's argument move swap
 * places (4 bytes); the u8 spill to [sp,#8] changes nothing visible but the
 * schedule.  Found by tools/permuter.py --types.  The call to arm9
 * 0x0202435C (an unlabelled two-slot wrapper) is attested by its shard.
 *
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_02188C54  0x02188C54  thumb  ov021
 *   sub_020122C0   0x020122C0  thumb
 *   sub_020124E8   0x020124E8  thumb
 *   func_02012964  0x02012964  thumb
 *   func_0216DEE0  0x0216DEE0  thumb  ov010
 *   func_0216DE94  0x0216DE94  thumb  ov010
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_021B0A40  0x021B0A40  thumb  ov021
 *   func_02188C58  0x02188C58  thumb  ov021
 *   func_0218EC2C  0x0218EC2C  thumb  ov021
 *   func_021B09D8  0x021B09D8  thumb  ov021
 *   func_02012EBC  0x02012EBC  thumb
 *   func_020071CC  0x020071CC  thumb
 *   func_0200DF58  0x0200DF58  thumb
 *   func_0202435C  0x0202435C  thumb
 *   func_020307B0  0x020307B0  arm
 *   func_021B09EC  0x021B09EC  thumb  ov021
 *   func_0219129C  0x0219129C  thumb  ov021
 *   func_0216CAF4  0x0216CAF4  thumb  ov010
 *
 * evidence: 0x0202435C is an unlabelled ARM9 thunk ("ldr r3, =func_02024368; movs r2, #2; bx r3") that the
 * prologue sweep misses; its start is seeded in layout/function_starts.txt
 * from the raw bl sites elsewhere in the image (ov069 0x021BA21A, ov093 0x021D1894, ov010 0x02168138), so the call
 * attests as `label`.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef int            s32;
typedef s32            fx32;

typedef struct VecFx32 {
    fx32 x;
    fx32 y;
    fx32 z;
} VecFx32;

typedef struct Work {
    void   *owner;      /* 0x00 */
    u32     field04;    /* 0x04 */
    VecFx32 pos;        /* 0x08 */
    u32     field14;    /* 0x14 */
    void   *field18;    /* 0x18 */
} Work;

extern void *func_020120F4(void *p);
extern void *func_0201210C(void *p);
extern void *func_02188C54(void *p);
extern void *sub_020122C0(void *owner, int a, void (*cb)(void), u32 size);
extern Work *sub_020124E8(void *d);
extern void *func_02012964(void *p);
extern void *func_0216DEE0(void *a0);
extern void *func_0216DE94(void *p, int a);
extern void  func_0216D88C(void *a, VecFx32 *out);
extern void *func_021B0A40(void *a, VecFx32 *pos);
extern void *func_02188C58(void *p);
extern void *func_0218EC2C(void *p);
extern void  func_021B09D8(VecFx32 *pos, VecFx32 *out, void *a, void *b, void *c);
extern void *func_02012EBC(void *p);
extern void *func_020071CC(void *sys, u32 id);
extern u8   *func_0200DF58(void *p, int a);
extern void *func_0202435C(void *p, int a);
extern void  func_020307B0(void *p);
extern void  func_021B09EC(void *p, s32 *a, s32 *b);
extern u32   func_0219129C(void *a, s32 b, VecFx32 *pos, void *c, int d, s32 e);
extern void  func_0216CAF4(void);

void *func_0216CB48(void *owner, int idx, u8 arg)
{
    void *sys;
    void *anm;
    void *ctx;
    void *task;
    Work *w;
    void *mdl;
    void *m2;
    void *cam;
    VecFx32 ofs;
    s32 b;
    s32 c;
    u8 *tbl;

    sys = func_020120F4(owner);
    anm = func_0201210C(owner);
    ctx = func_02188C54(anm);
    task = sub_020122C0(owner, 0, func_0216CAF4, sizeof(Work));
    w = sub_020124E8(task);
    w->owner = owner;
    mdl = func_02012964(sys);
    m2 = func_0216DEE0(mdl);
    func_0216D88C(func_0216DE94(mdl, arg), &w->pos);
    mdl = func_021B0A40(m2, &w->pos);
    cam = func_02188C58(anm);
    func_021B09D8(&w->pos, &ofs, func_0218EC2C(cam), cam, mdl);
    w->pos.x += ofs.x;
    w->pos.y += ofs.y;
    w->pos.z += ofs.z;
    tbl = func_0200DF58(func_020071CC(func_02012EBC(sys), 0x3b), 4);
    w->field18 = func_0202435C(tbl + idx * 0x22 + 0x18, 4);
    func_020307B0(tbl);
    func_021B09EC(mdl, &b, &c);
    w->field14 = func_0219129C(ctx, b, &w->pos, w->field18, 0, c);
    return task;
}

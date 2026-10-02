/*
 * function: func_0216C2FC
 * address:  0x0216C2FC
 * packet:   pkt_ov010_0216C2FC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Seven-state proc of a field event in ov010: animate the actor until it
 * lands on the grid, push the result screen with a fixed Param, then
 * settle the ov050 gimmick and drop the object back to the ground height.
 * First draft; the 0x021F37xx callees are declared ov050, the only
 * overlay that labels all six.
 *
 * symbols:
 *   func_02188D2C  0x02188D2C  thumb  ov021
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_020114D0  0x020114D0  thumb
 *   func_02011558  0x02011558  thumb
 *   func_0216C270  0x0216C270  thumb  ov010
 *   func_0216C280  0x0216C280  thumb  ov010
 *   func_0216C2A4  0x0216C2A4  thumb  ov010
 *   func_02163E58  0x02163E58  thumb  ov010
 *   func_0218F0A8  0x0218F0A8  thumb  ov021
 *   func_0218F0E8  0x0218F0E8  thumb  ov021
 *   func_021F3714  0x021F3714  thumb  ov050
 *   func_021F37B8  0x021F37B8  thumb  ov050
 *   func_021F3758  0x021F3758  thumb  ov050
 *   func_021F3808  0x021F3808  thumb  ov050
 *   func_021F3744  0x021F3744  thumb  ov050
 *   func_021F3788  0x021F3788  thumb  ov050
 *   func_021BE92C  0x021BE92C  thumb
 *   func_021D2D50  0x021D2D50  thumb
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_021A3038  0x021A3038  thumb  ov021
 *   func_021A3044  0x021A3044  thumb  ov021
 *   func_02006148  0x02006148  thumb
 *   func_020061F8  0x020061F8  thumb
 *   func_020061E4  0x020061E4  thumb
 *   func_02012374  0x02012374  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;
typedef s32 fx32;

typedef struct VecFx32 {
    fx32 x;
    fx32 y;
    fx32 z;
} VecFx32;

typedef struct Param {
    u16 f00;            /* 0x00 */
    u16 f02;            /* 0x02 */
    u16 f04;            /* 0x04 */
    u16 f06;            /* 0x06 */
    u16 f08;            /* 0x08 */
    u16 f0a;            /* 0x0A */
    u16 f0c;            /* 0x0C */
    u8 f0e;             /* 0x0E */
    u8 f0f;             /* 0x0F */
    u32 f10;            /* 0x10 */
    u32 f14;            /* 0x14 */
} Param;

typedef struct Work {
    u16 f00;            /* 0x00 */
    void *sys;          /* 0x04 */
    void *field;        /* 0x08 */
    void *f0c;          /* 0x0C */
    void *anim;         /* 0x10 */
} Work;

extern void *func_02188D2C(void *field);
extern void *func_02188CB4(void *field);
extern void *func_020114D0(u32 heap, u32 a1, u32 a2);
extern void func_02011558(void *anim);
extern int func_0216C270(Work *w);
extern void *func_0216C280(Work *w);
extern void func_0216C2A4(Work *w);
extern void func_02163E58(u32 a, VecFx32 *v, fx32 *y);
extern void func_0218F0A8(void *p);
extern int func_0218F0E8(void *p);
extern void func_021F3714(void *field);
extern void func_021F37B8(void *field);
extern int func_021F3758(void *field);
extern int func_021F3808(void *field);
extern void func_021F3744(void *field);
extern void func_021F3788(void *field);
extern void *func_021BE92C(void *sys, void *proc, u32 a, u32 b, u32 c, u32 d, u32 e);
extern void *func_021D2D50(void *sys, Param *p);
extern void *func_021A3074(void *q);
extern void func_021A3038(void *q, VecFx32 *v);
extern void func_021A3044(void *q, const VecFx32 *v);
extern u32 func_02006148(u32 id);
extern void func_020061F8(int i);
extern void func_020061E4(u32 se);
extern void func_02012374(void *evt, void *task);

int func_0216C2FC(void *evt, u32 *state, Work *w)
{
    Param p;
    VecFx32 v;
    fx32 y;
    int done;
    void *q;
    void *a;

    func_02188D2C(w->field);
    switch (*state) {
    case 0:
        w->anim = func_020114D0(w->f00, 0x9D, 0x19);
        func_0216C280(w);
        func_0216C2A4(w);
        func_0218F0A8(w->f0c);
        (*state)++;
        break;
    case 1:
        if (func_0218F0E8(w->f0c) == 0)
            (*state)++;
        break;
    case 2:
        func_021F3714(w->field);
        func_021F37B8(w->field);
        func_02012374(evt, func_021BE92C(w->sys, w->field, 0, 0, 1, 0, 0));
        (*state)++;
        break;
    case 3:
        done = func_0216C270(w);
        if (done == 0) {
            func_0216C280(w);
            func_0216C2A4(w);
        }
        if (done != 0) {
            func_02011558(w->anim);
            func_020061F8(func_02006148(1953));
            func_020061E4(1775);
            p.f00 = 2;
            p.f02 = 0;
            p.f10 = 3;
            p.f0f = 2;
            p.f0e = 2;
            p.f14 = 0;
            p.f04 = 0;
            p.f06 = 1;
            p.f08 = 0;
            p.f0a = 0;
            p.f0c = 2;
            func_02012374(evt, func_021D2D50(w->sys, &p));
            (*state)++;
        }
        break;
    case 4:
        if (func_021F3758(w->field) && func_021F3808(w->field)) {
            func_021F3744(w->field);
            func_021F3788(w->field);
            (*state)++;
        }
        break;
    case 5:
        q = func_02188CB4(w->field);
        a = func_021A3074(q);
        func_021A3038(q, &v);
        func_02163E58(a, &v, &y);
        v.y = y;
        func_021A3044(q, &v);
        (*state)++;
        break;
    case 6:
        return 1;
    }
    return 0;
}

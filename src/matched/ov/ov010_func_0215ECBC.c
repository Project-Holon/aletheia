/*
 * function: func_0215ECBC
 * address:  0x0215ECBC
 * packet:   pkt_ov010_0215ECBC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Three-state sequence step: state 0 opens message 0x2718, state 1 waits
 * for an object to go idle then starts sound 0x94, state 2 waits for a
 * status of 3. Returns 1 when finished.
 *
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_0201296C  0x0201296C  thumb
 *   func_02012B38  0x02012B38  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_02189A10  0x02189A10  thumb  ov021
 *   func_021C7FBC  0x021C7FBC  thumb  ov021
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_02158780  0x02158780  thumb  ov010
 *   func_02159058  0x02159058  thumb  ov010
 *   func_02014468  0x02014468  thumb
 *   func_02014464  0x02014464  thumb
 *   func_02165534  0x02165534  thumb  ov010
 *   func_021C7E50  0x021C7E50  thumb  ov021
 *   func_02014470  0x02014470  thumb
 *   func_0201446C  0x0201446C  thumb
 *   func_021C7E54  0x021C7E54  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Arg {
    u8 pad00[8];
    void *f08;          /* 0x08 */
    u16 f0c;            /* 0x0C */
} Arg;

extern void *func_020120F4(void *p);
extern void func_0201296C(void *p);
extern void *func_02012B38(void *p);
extern void *func_0201210C(void *p);
extern void *func_02189A10(void *p);
extern void *func_021C7FBC(void *p);
extern u32 func_02188C84(void *p);
extern void *func_02158780(void *a, u32 id, u32 b, u32 c, u32 d);
extern void func_02159058(void *p, u32 a, u32 b, u32 c, u32 d);
extern int func_02014468(void *p);
extern void func_02014464(void *p, int v);
extern void func_02165534(int se);
extern void func_021C7E50(void *p, u16 v);
extern u32 func_02014470(void *p);
extern void func_0201446C(void *p, u32 v);
extern u16 func_021C7E54(void *p);

int func_0215ECBC(void *a0, int *state, Arg *arg)
{
    void *obj;
    void *obj2;
    void *ctl;
    u32 d;
    void *msg;
    void *o;
    u16 id;

    obj = func_020120F4(arg->f08);
    func_0201296C(obj);
    obj2 = func_02012B38(obj);
    ctl = func_021C7FBC(func_02189A10(func_0201210C(arg->f08)));
    d = func_02188C84(func_0201210C(arg->f08));

    switch (*state) {
    case 0:
        id = arg->f0c;
        msg = func_02158780(a0, 0x2718, 0, 0, d);
        func_02159058(msg, id, 0, 0, 0);
        (*state)++;
        break;
    case 1:
        if (func_02014468(obj2) == 0) {
            o = func_02012B38(obj);
            func_02014464(obj2, 1);
            func_02165534(0x94);
            func_021C7E50(ctl, 1);
            func_0201446C(o, (func_02014470(o) & ~1) | 2);
        } else {
            return 1;
        }
        (*state)++;
        break;
    case 2:
        if (func_021C7E54(ctl) == 3) {
            return 1;
        }
        break;
    }
    return 0;
}

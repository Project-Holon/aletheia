/*
 * function: func_0217BAB4
 * address:  0x0217BAB4
 * packet:   pkt_ov018_0217BAB4
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_020120F8  0x020120F8  thumb
 *   func_02012AC8  0x02012AC8  thumb
 *   func_02012AE4  0x02012AE4  thumb
 *   func_02012138  0x02012138  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_02026454  0x02026454  thumb
 *   func_02013D5C  0x02013D5C  thumb
 *   func_02175E90  0x02175E90  thumb  ov011
 *   func_021A3038  0x021A3038  thumb  ov021
 *   func_020120D8  0x020120D8  thumb
 *   func_021A3044  0x021A3044  thumb  ov021
 *   func_02175274  0x02175274  thumb  ov011
 *   func_02039338  0x02039338  arm
 *   func_02175710  0x02175710  thumb  ov011
 *   func_02161FEC  0x02161FEC  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct { u16 f : 3; u16 g : 13; } Fh;
typedef struct { int x, y, z; } Vec;

struct Ctx;
extern u8 *func_020120F8(const struct Ctx *p);
struct Rec44;
extern u16 func_02012AC8(const struct Rec44 *p);
extern void func_02012AE4(int);
typedef unsigned int   u32;
extern u32 func_02012138(const struct Ctx *p);
extern void *func_020120F4(const struct Ctx *p);
extern int func_02026454(int);
extern u32 func_02013D5C(u32 id);
extern int func_02175E90(void *p, u8 *q);
struct VecFx32;
extern void func_021A3038(unsigned char *, struct VecFx32 *);
extern int func_020120D8(char *p);
extern void func_021A3044(void *, Vec *);
extern void func_02175274(u8 *, int);
extern u16 func_02039338(void);
extern void func_02175710(u8 *o, u32 v);
extern void func_02161FEC(u8 *, u8);

void func_0217BAB4(int a0, void *a1, void *a2, u8 *p)
{
    int x;
    int idx;
    Vec cur;
    Vec tmp;
    int flag;
    int prev;
    int limit;
    int sys;

    x = (int)func_020120F8(a1);
    sys = func_02012AC8((const struct Rec44 *)x);
    func_02012AE4(x);
    x = func_02012138(a1);
    flag = 0;
    func_020120F4(a1);
    if (func_02026454(x) != 2)
        return;
    if (p == 0)
        return;
    if (func_02013D5C(sys) == 0)
        return;
    if (p[0x902] < 2)
        return;
    if (func_02175E90(p, p + 0x1AC) == 1)
        return;
    func_021A3038(a2, (struct VecFx32 *)&cur);
    tmp = cur;
    x = cur.x;
    prev = ((Fh *)(p + 0x86))->f;
    limit = (p[0x901] + 1) << 22;
    if (x < 0) {
        tmp.x = limit + x;
        flag = 1;
    } else if (x > limit) {
        tmp.x = x - limit;
        flag = 1;
    }
    if (flag == 1) {
        x = tmp.x;
        if (func_020120D8(a1) == 1) {
            tmp = cur;
            flag = 0;
        }
    }
    idx = x / 0x400000;
    if (flag == 1) {
        func_021A3044(a2, &tmp);
        func_02175274(p, tmp.x);
    }
    idx += func_02039338();
    if (idx > p[0x901])
        idx -= p[0x901] + 1;
    if (prev == idx)
        return;
    func_02175710(p, idx);
    p[0x900] = 1;
    func_02161FEC(p + 0x35C, idx);
}

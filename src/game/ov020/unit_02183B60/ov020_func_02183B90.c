/*
 * function: func_02183B90
 * address:  0x02183B90
 * packet:   pkt_ov020_02183B90
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_0208068C  0x0208068C  arm
 *   func_02082AC0  0x02082AC0  arm
 *   func_02080B98  0x02080B98  arm
 *   func_0202E888  0x0202E888  thumb
 *   sub_0202E8CC   0x0202E8CC  thumb
 *   func_02012984  0x02012984  thumb
 *   func_02187808  0x02187808  thumb  ov020
 *   func_02012374  0x02012374  thumb
 *   func_02161B90  0x02161B90  thumb  ov010
 *   func_02183D68  0x02183D68  thumb  ov020
 *   func_0201235C  0x0201235C  thumb
 */

typedef unsigned short u16;
typedef unsigned int   u32;

typedef unsigned char  u8;
struct BigObj;
struct Ctx;
struct Evt;
struct S0201235C;
extern void *func_020120F4(const struct Ctx *p);
extern void func_0208068C(int a);
extern void func_02082AC0(int v, u32 a, u32 b);
extern void func_02080B98(void);
extern int func_0202E888(void);
typedef signed int     s32;
extern u8 sub_0202E8CC(s32 a, s32 b);
extern u8 func_02012984(const struct BigObj *p);
extern int func_02187808(int a, int b, int c);
extern void func_02012374(struct Evt *evt, struct Evt **out);
extern void *func_02161B90(void *p, void *a1, int kind, int sub, int flag);
extern int func_02183D68(int a, int b);
extern void func_0201235C(struct S0201235C *o, u32 *out);

int func_02183B90(int a, int *state, int *p)
{
    int w = p[0];
    int s = (int)func_020120F4((const struct Ctx *)w);
    int r;
    int t;

    switch (*state) {
    case 0:
        func_0208068C(0x1ff);
        func_02082AC0(0, 0x1a << 22, 0x29 << 14);
        func_02080B98();
        (*state)++;
        break;
    case 1:
        sub_0202E8CC(s, (u16)func_0202E888());
        t = func_02012984((const struct BigObj *)s);
        r = func_02187808(w, t, t);
        func_02012374((struct Evt *)a, (struct Evt **)r);
        (*state)++;
        break;
    case 2:
        r = (int)func_02161B90((void *)w, (void *)a, 5, 0, 1);
        func_02012374((struct Evt *)a, (struct Evt **)r);
        (*state)++;
        break;
    case 3:
        func_0201235C((struct S0201235C *)a, (u32 *)func_02183D68(w, p[1]));
        break;
    }
    return 0;
}

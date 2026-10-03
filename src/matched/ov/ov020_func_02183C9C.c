/*
 * function: func_02183C9C
 * address:  0x02183C9C
 * packet:   pkt_ov020_02183C9C
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Byte-correct (202 bytes + 2 padding). The one unresolved site is
 * +005E THM_CALL func_02029DF4: an unlabelled arm9 Thumb thunk
 * (ldr r3,[pc,#0]; bx r3; .word 0x02029EB5), so no label and no
 * outside witness. It is Ilias's arm9 leaf, verified EXACT at
 * 0x02029DF4 (region arm9, thumb, dsi/1.1p1 -O4,p) as:
 *     extern int func_02029EB4(u32 a, int b, u32 c);   (0x02029EB4 thumb)
 *     int func_02029DF4(u32 a, int b, u32 c)
 *     { return func_02029EB4(a, b, c); }
 * Once that leaf is filed in an arm9 shard this caller resolves as
 * `matched` and goes EXACT. The same call caps the twin
 * src/matched/ov/ov012_func_021743A4.c, which `one` now reports MATCH.
 *
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_0201296C  0x0201296C  thumb
 *   func_02158A10  0x02158A10  thumb  ov010
 *   func_02185A68  0x02185A68  thumb  ov020
 *   func_021857C0  0x021857C0  thumb  ov020
 *   func_02012984  0x02012984  thumb
 *   func_02029DF4  0x02029DF4  thumb
 *   func_020298A0  0x020298A0  thumb
 *   func_02012374  0x02012374  thumb
 *   func_020145FC  0x020145FC  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_021BE92C  0x021BE92C  thumb  ov021
 *   func_02188D20  0x02188D20  thumb  ov021
 *   func_021BC578  0x021BC578  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef short          s16;
typedef unsigned int   u32;

typedef struct Arg {
    u32 f0;
    u8  pad4[4];
    u8  f8[4];
    s16 fC;
} Arg;

extern u32   func_020120F4(u32 a);
extern void  func_0201296C(u32 a);
extern void  func_02158A10(u32 a, int b);
extern void  func_02185A68(u32 a, u16 b);
extern void  func_021857C0(u32 a, void *b);
extern u32   func_02012984(u32 a);
extern int   func_02029DF4(u32 a, int b, u32 c);
extern void *func_020298A0(u32 a, int b, int c, int d);
struct Ctx;
struct Evt;
extern void func_02012374(struct Evt *evt, struct Evt **out);
extern void *func_020145FC(u32 a);
extern void *func_0201210C(const struct Ctx *p);
extern void *func_021BE92C(u32 a0, void *a1, int a2, int a3, int a4, int a5, int a6);
extern u32 func_02188D20(u8 *p);
extern void  func_021BC578(u32 a, int b);

int func_02183C9C(void *obj, int *state, Arg *arg)
{
    u32 x = arg->f0;
    u32 t = func_020120F4(x);
    void *w;

    func_0201296C(t);
    switch (*state) {
    case 0:
        func_02158A10(x, 1);
        func_02185A68(x, arg->fC);
        func_021857C0(x, arg->f8);
        (*state)++;
        break;
    case 1:
        func_02012374(obj, func_020298A0(x, func_02029DF4(t, arg->fC, func_02012984(t)), 0, 0x3c));
        (*state)++;
        break;
    case 2:
        func_02012374(obj, func_020145FC(x));
        (*state)++;
        break;
    case 3:
        func_02012374(obj, func_021BE92C(x, func_0201210C((void *)x), 1, 0, 1, 0, 0));
        (*state)++;
        break;
    case 4:
        w = func_0201210C((void *)x);
        if (func_02188D20(w) != 0)
            func_021BC578(func_02188D20(w), arg->fC);
        return 1;
    }
    return 0;
}

/*
 * file:     unit_02183B60_p01.c
 * unit:     yes
 * function: func_02183C34, func_02183C58, func_02183C9C, func_02183D68
 * address:  0x02183C34
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020122C0 0x020122C0 thumb
 *   func_020124E8 0x020124E8 thumb
 *   func_02183B90 0x02183B90 thumb ov020
 *   func_020120F4  0x020120F4  thumb
 *   func_020127C4  0x020127C4  thumb
 *   func_02012944  0x02012944  thumb
 *   func_021860D4  0x021860D4  thumb  ov020
 *   func_02161D64  0x02161D64  thumb  ov010
 *   func_020127F0  0x020127F0  thumb
 *   func_02161F14  0x02161F14  thumb  ov010
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
 *   func_02014264  0x02014264  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_02008B08  0x02008B08  thumb
 *   func_02008B20  0x02008B20  thumb
 *   func_02021444  0x02021444  thumb
 *   func_02185F6C  0x02185F6C  thumb  ov020
 *   func_0208068C  0x0208068C  arm
 *   func_02082AC0  0x02082AC0  arm
 *   func_02080B98  0x02080B98  arm
 */
struct Desc;
struct Obj;
struct Ctx;
struct BigObj;
struct Evt;
struct Big;
struct Sub02008AECObj;
struct Arg;
typedef struct { void *owner; void *input; } Work;

typedef unsigned int   u32;

typedef unsigned short u16;

typedef unsigned char  u8;

typedef short          s16;

typedef struct Arg {
    u32 f0;
    u8  pad4[4];
    u8  f8[4];
    s16 fC;
} Arg;

extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern int func_02183B90(int a, int *state, int *p);
extern void *func_020120F4(const struct Ctx *p);
extern u8 *func_020127C4(void *p);
extern u8 *func_02012944(void *p);
extern void func_021860D4(u16 *p, int a1, int id);
extern int func_02161D64(int a0);
extern int func_020127F0(int a);
extern void func_02161F14(u16 *out, u8 *in, int c);
extern u32 func_0201296C(const struct BigObj *p);
extern void func_02158A10(int a, int b);
extern void func_02185A68(void *a, int b);
extern void func_021857C0(void *a, int b);
extern u8 func_02012984(const struct BigObj *p);
extern unsigned int func_02029DF4(void *a, unsigned int id, unsigned int which);
extern void *func_020298A0(void *a, u32 b, u32 c, u32 d);
extern void func_02012374(struct Evt *evt, struct Evt **out);
extern int func_020145FC(int a0);
extern void *func_0201210C(const struct Ctx *p);
extern int func_021BE92C(void *a, int b, int sel, int d, int e, u8 f, u8 g);
extern u32 func_02188D20(u8 *p);
extern void func_021BC578(void *p, int v);
extern void func_02014264(void *p);
extern void *func_02012EBC(struct Big *p);
extern struct Sub02008AECObj *func_02008B08(void *sys);
extern void func_02008B20(struct Sub02008AECObj *obj);
extern void func_02021444(void);
extern void func_02185F6C(int a);
extern void func_0208068C(int a);
extern void func_02082AC0(int v, u32 a, u32 b);
extern void func_02080B98(void);
void *func_02183C34(void *owner, void *input);
void func_02183C58(int a);
int func_02183C9C(void *obj, int *state, Arg *arg);
int func_02183D68(int a);

void *func_02183C34(void *owner, void *input)
{
    void *task;
    Work *w;
    task = func_020122C0(owner, 0, (void *)func_02183B90, sizeof(Work));
    w = func_020124E8(task);
    w->owner = owner;
    w->input = input;
    return task;
}


void func_02183C58(int a)
{
    int w = (int)func_020120F4((const struct Ctx *)a);
    int r5 = (int)func_020127C4((void *)w);

    func_021860D4((u16 *)r5, (int)func_02012944((void *)w), 1);
    func_02161D64((int)func_020127C4((void *)w));
    r5 = func_020127F0(w);
    func_02161F14((u16 *)r5, (u8 *)func_020127C4((void *)w), 1);
}


/*
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
 */
int func_02183C9C(void *obj, int *state, Arg *arg)
{
    u32 x = arg->f0;
    u32 t = (u32)func_020120F4((const struct Ctx *)x);
    void *w;

    func_0201296C((const struct BigObj *)t);
    switch (*state) {
    case 0:
        func_02158A10(x, 1);
        func_02185A68((void *)x, (u16)arg->fC);
        func_021857C0((void *)x, (int)arg->f8);
        (*state)++;
        break;
    case 1:
        func_02012374(obj, func_020298A0((void *)x, func_02029DF4((void *)t, arg->fC, func_02012984((const struct BigObj *)t)), 0, 0x3c));
        (*state)++;
        break;
    case 2:
        func_02012374(obj, (struct Evt **)func_020145FC(x));
        (*state)++;
        break;
    case 3:
        func_02012374(obj, (struct Evt **)func_021BE92C((void *)x, (int)func_0201210C((void *)x), 1, 0, 1, 0, 0));
        (*state)++;
        break;
    case 4:
        w = func_0201210C((void *)x);
        if (func_02188D20(w) != 0)
            func_021BC578((void *)func_02188D20(w), arg->fC);
        return 1;
    }
    return 0;
}


int func_02183D68(int a)
{
    int r6 = (int)func_020122C0((void *)a, 0, func_02183C9C, 0x24);
    int *r4 = func_020124E8((struct Obj *)r6);

    r4[0] = a;
    r4[1] = (int)func_020120F4((const struct Ctx *)a);
    func_02014264(r4 + 2);
    func_02183C58(a);
    func_02008B20(func_02008B08(func_02012EBC((struct Big *)r4[1])));
    func_02021444();
    func_02185F6C(r4[1]);
    func_0208068C(0x1ff);
    func_02082AC0(0, 0x1a << 22, 0x29 << 14);
    func_02080B98();
    return r6;
}

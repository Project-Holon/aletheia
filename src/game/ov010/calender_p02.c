/*
 * file:     calender_p02.c
 * unit:     yes
 * function: func_0216459C, func_021645C0, func_021645E0, func_02164654
 * address:  0x0216459C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02012AC8  0x02012AC8  thumb
 *   func_02013E04  0x02013E04  thumb
 *   func_021C5C64  0x021C5C64  thumb  ov021
 *   func_02013D20   0x02013D20  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_02012138  0x02012138  thumb
 *   func_0215870C  0x0215870C  thumb ov010
 *   func_02188C7C  0x02188C7C  thumb ov021
 *   func_02188BF8  0x02188BF8  thumb ov021
 *   func_02188CB4  0x02188CB4  thumb ov021
 *   func_021A2F54  0x021A2F54  thumb ov021
 *   func_021A34F8  0x021A34F8  thumb ov021
 *   func_020122C0 0x020122C0 thumb
 *   func_020124E8 0x020124E8 thumb
 */
struct Rec44;
struct Ctx;
struct Obj00020;
struct Desc;
struct Obj;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct { void *p; u32 n; } Work;

extern u16 func_02012AC8(const struct Rec44 *p);
extern u32 func_02013E04(u32 id);
extern int func_021C5C64(u32 unused, u32 a, u32 *out);
extern u32 func_02013D20(u32 id);
extern void *func_0201210C(const struct Ctx *p);
extern u32 func_02012138(const struct Ctx *p);
extern int func_0215870C(void *p, int b);
extern void *func_02188C7C(u8 *p);
extern u32 func_02188BF8(u8 *a);
extern void *func_02188CB4(struct Obj00020 *p);
extern int   func_021A2F54(u8 *p);
extern int   func_021A34F8(u8 *p);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
int func_0216459C(int a0, int a1, int a2);
int func_021645C0(void *a0, void *a1, void *a2);
int func_021645E0(void *unused, int *st, int *w);
void *func_02164654(void *unused, void *a);


/*
 * unblocked: 0x021C5C64 is ov021's func_021C5C64 across the co-resident
 *   ov010/ov021 field-VM pair; the `ov021` token on the symbols line picks
 *   that overlay and the site resolves `label`.
 */
int func_0216459C(int a0, int a1, int a2)
{
    int t4;
    int t5;

t5 = a0 + 0;
a0 = a2 + 0;
t4 = a1 + 0;
    a0 = func_02012AC8((const struct Rec44 *)a0);
loc_021645A8:
    a0 = func_02013E04(a0);
loc_021645AC:
    if (a0 != 0) goto loc_021645B4;
loc_021645B0:
a0 = 0;
    return a0;
loc_021645B4:
a0 = t5 + 0;
a1 = t4 + 0;
a2 = 0;
    a0 = func_021C5C64(a0, a1, (u32 *)a2);
loc_021645BE:
    return a0;}


/*
 * Size the third argument through the arm9 helper, bail when the arm9
 * status is set, otherwise copy it out.
 */
int func_021645C0(void *a0, void *a1, void *a2)
{
    int r = func_02012AC8(a2);

    if (func_02013D20(r) != 0)
        return 0;

    return func_02013E04(r);
}


/*
 * Three-step wait state machine on *st; step 0 also counts frames in w[1].
 *
 * Addresses are Black-image addresses.
 */
int func_021645E0(void *unused, int *st, int *w)
{
    int r;
    u8 *h = func_0201210C((void *)w[0]);
    func_02188C7C(h);
    switch (*st) {
    case 0:
        r = func_02012138((const struct Ctx *)w[0]);
        w[1]++;
        if (func_0215870C((void *)r, w[1]) == 1 && (u32)w[1] < 0x1e) {
            break;
        }
        func_02188BF8(h);
        (*st)++;
        /* fall through */
    case 1:
        if (func_021A2F54((u8 *)func_02188CB4((struct Obj00020 *)h)) == 1) {
            (*st)++;
        }
        break;
    case 2:
        if (func_021A34F8((u8 *)func_02188CB4((struct Obj00020 *)h)) == 1) {
            return 1;
        }
        break;
    }
    return 0;
}

void *func_02164654(void *unused, void *a) { void *task; Work *w; int zero=0; task=func_020122C0(a,0,(void *)func_021645E0,8); w=func_020124E8(task); w->p=a; w->n=zero; return task; }

/*
 * file:     unit_021F36C0_p03.c
 * unit:     yes
 * function: func_021F3850, func_021F3870, func_021F3880, func_021F3938, func_021F3950, func_021F399C
 * address:  0x021F3850
 * region:   ov060
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021BE4B4  0x021BE4B4  thumb  ov203
 *   _s32_div_f  0x0209C0A4  arm
 *   func_02012B80  0x02012B80  thumb
 *   func_02012B58  0x02012B58  thumb
 *   func_02012B40  0x02012B40  thumb
 *   func_020127B8  0x020127B8  thumb
 *   func_020127AC  0x020127AC  thumb
 *   func_0200BDF8  0x0200BDF8  thumb
 *   func_0200BDFC  0x0200BDFC  thumb
 *   func_021BE480  0x021BE480  thumb  ov021
 *   func_02026454  0x02026454  thumb
 *   func_02026474  0x02026474  thumb
 *   func_021BE700  0x021BE700  thumb  ov021
 *   func_021BE674  0x021BE674  thumb  ov021
 *   func_021BE6B8  0x021BE6B8  thumb  ov021
 *   func_021BE6B0  0x021BE6B0  thumb  ov021
 *   func_021BE6CC  0x021BE6CC  thumb  ov021
 */
struct BigObj;
struct Rec1B0;
struct SaveBlock;
typedef unsigned short u16;

typedef unsigned int   u32;

typedef unsigned char u8;

typedef struct {
    int a;
    int b;
    int c;
} V;

extern void func_021BE4B4(char *ctx, int b, int c, u32 d);
extern u8 func_02012B80(const struct BigObj *p);
extern u8 func_02012B58(const struct BigObj *p);
extern u8 func_02012B40(const struct BigObj *p);
extern void *func_020127B8(void *p);
extern void *func_020127AC(struct SaveBlock *p, u32 idx);
extern u16 func_0200BDF8(struct Rec1B0 *p);
extern u16 func_0200BDFC(struct Rec1B0 *p);
extern V *func_021BE480(void *p, int i, u16 j);
extern unsigned int func_02026454(void *p);
extern u32 func_02026474(void *obj);
extern void func_021BE700(void *p, int i, int j, int k, int flag);
extern u8 *func_021BE674(void *p, int i, int j, u16 k);
extern void func_021BE6B8(u8 *p, int v);
extern void func_021BE6B0(u8 *p, int v);
extern void func_021BE6CC(int a, int b, int c, int d, int e);
void func_021F3850(char *p);
int func_021F3870(int x);
u8 func_021F3880(void *a, void *b, void *unused);
void *func_021F3938(void *p);
void func_021F3950(void *unused, void *p);
void func_021F399C(u8 *o, void *p, V *v);


void func_021F3850(char *p)
{
    int i;

    for (i = 0; i < 0x14; i++) {
        func_021BE4B4(p, 0, (u16)i, 1);
    }
}

int func_021F3870(int x)
{
    int r = x / 3;

    if (r > 9) {
        r = 9;
    }
    return r;
}


u8 func_021F3880(void *a, void *b, void *unused)
{
    int r6;
    int r4;
    int r5;
    int r7;
    int e;
    V *p;

    r6 = func_02012B80(a);
    r4 = r6 - func_02012B58(a);
    if (r4 < 0) {
        r4 += func_02012B40(a);
    }
    if (r6 == func_02012B58(a)) {
        e = (int)func_020127B8(a);
    } else {
        e = (int)func_020127AC(a, r6);
    }
    r7 = e;
    r5 = func_021F3870(func_0200BDF8((struct Rec1B0 *)r7));
    r7 = func_021F3870(func_0200BDFC((struct Rec1B0 *)r7));
    p = func_021BE480(b, 0, r5 + 10);
    r4 = (r4 << 22) + 0x1F8000;
    p->a = r4;
    p->b = 0x20000;
    p->c = 0x1B8000;
    p = func_021BE480(b, 0, r7);
    p->a = r4;
    p->b = 0x20000;
    p->c = 0x1B8000;
    func_021BE4B4(b, 0, (u16)(r5 + 10), 0);
    func_021BE4B4(b, 0, (u16)r7, 0);
    return r6;
}


void *func_021F3938(void *p)
{
    if (func_02026454(p) == 2) {
        return (void *)func_02026474(p);
    }
    return 0;
}


void func_021F3950(void *unused, void *p)
{
    int i;
    u8 *e;

    func_021BE4B4(p, 0, 0x14, 1);
    for (i = 0; i < 3; i++) {
        func_021BE700(p, 0, 0x14, (u16)i, 1);
        e = func_021BE674(p, 0, 0x14, (u16)i);
        func_021BE6B8(e, 0);
        func_021BE6B0(e, 0);
    }
}


void func_021F399C(u8 *o, void *p, V *v)
{
    int i;

    func_021BE4B4(p, 0, 0x14, 0);
    for (i = 0; i < 3; i++) {
        func_021BE6CC((int)p, 0, 0x14, (u16)i, 0);
    }
    *func_021BE480(p, 0, 0x14) = *v;
    o[1] = 1;
}

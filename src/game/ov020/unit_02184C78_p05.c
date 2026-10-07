/*
 * file:     unit_02184C78_p05.c
 * unit:     yes
 * function: func_0218571C, func_02185758, func_02185788
 * address:  0x0218571C
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
 *   func_020120F4 0x020120F4 thumb
 *   func_020122C0 0x020122C0 thumb
 *   func_020124E8 0x020124E8 thumb
 *   func_02012914 0x02012914 thumb
 *   func_02159FA8 0x02159FA8 thumb ov010
 *   func_02185694 0x02185694 thumb ov020
 *   func_021625FC 0x021625FC thumb ov010
 *   func_02014204 0x02014204 thumb
 */
struct BigObj;
struct Ctx;
struct Desc;
struct Obj;
struct t;
typedef struct { void *owner; void *object; unsigned char payload[0x1c]; } Work;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef struct { int kind; u16 h4, h6, h8, ha; int c, d, e, f; } Record;

typedef unsigned char  u8;

extern void *func_020120F4(const struct Ctx *p);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern u16 func_02012914(const struct BigObj *p);
extern void func_02159FA8(int a, int b);
extern int func_02185694(int a0, int *st, int *p);
extern int func_021625FC(const u8 *q, int *out, int id, int k);
extern void func_02014204(struct t *p, int id);
void *func_0218571C(void *owner);
int func_02185758(int value);
void func_02185788(void *p, Record *source, Record *dest);

void *func_0218571C(void *owner)
{
    void *task;
    Work *w;
    func_020120F4(owner);
    task = func_020122C0(owner, 0, (void *)func_02185694, sizeof(Work));
    w = func_020124E8(task);
    w->owner = owner;
    w->object = func_020120F4(owner);
    func_02159FA8(func_02012914(w->object), (int)w->payload);
    return task;
}

int func_02185758(int value)
{
    switch (value) {
    case 0:
    case 1:
    default: return 0;
    case 3: return 0x4000;
    case 2: return 0x8000;
    case 4: return 0xc000;
    }
}

void func_02185788(void *p, Record *source, Record *dest)
{
    if (source->kind == 1) {
        *dest = *source;
    } else {
        if (func_021625FC(p, (int *)dest, source->h6, source->ha) == 0) {
            func_02014204((struct t *)dest, source->h4);
        }
    }
}

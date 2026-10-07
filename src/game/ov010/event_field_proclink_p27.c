/*
 * file:     event_field_proclink_p27.c
 * unit:     yes
 * function: func_02161B90, func_02161BF8
 * address:  0x02161B90
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
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_02082BCC  0x02082BCC  arm
 *   func_02012138  0x02012138  thumb
 *   func_02161CDC  0x02161CDC  thumb  ov010
 *   func_02161D18  0x02161D18  thumb  ov010
 *   func_0216570C  0x0216570C  thumb  ov010
 *   func_02012144  0x02012144  thumb
 *   func_0201213C  0x0201213C  thumb
 *   func_02026454  0x02026454  thumb
 *   func_02026400  0x02026400  thumb
 *   func_020120B4  0x020120B4  thumb
 *   func_020120F0  0x020120F0  thumb
 *   d_021BFB3C     0x021BFB3C  data  ov203
 *   ov203_id       0x000000CB  data
 */
struct Desc;
struct Obj;
struct Ctx;
struct Comm;
struct IcaAnime;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct Node {
    void *f00;          /* 0x00 */
    void *f04;          /* 0x04 */
    u8 f08[0x1C];       /* 0x08 */
} Node;

typedef struct Obj {
    void *f00;          /* 0x00 */
    void *f04;          /* 0x04 */
    u8 f08[0x18];       /* 0x08 */
    u32 f20;            /* 0x20 */
} Obj;

extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern void func_02082BCC(void *p, int v, int n);
extern unsigned int func_02012138(const struct Ctx *p);
extern void func_02161CDC(void *a, void *b, u8 c, u8 d);
extern void func_02161D18(int a, int b, u8 c, u8 d);
extern void func_0216570C(void);
extern u8 func_02012144(const struct Ctx *p);
extern void func_0201213C(struct Ctx *p, u32 v);
extern u32 func_02026454(void *obj);
extern void func_02026400(struct Comm *p);
extern void func_020120B4(struct IcaAnime *p, u32 id, void *a, void *b);
extern u32 func_020120F0(const struct Ctx *p);
void *func_02161B90(void *p, void *a1, int kind, int sub, int flag);
int func_02161BF8(void *a0, int *state, Obj *o);
extern u8 d_021BFB3C[];
extern u8 ov203_id[];


void *func_02161B90(void *p, void *a1, int kind, int sub, int flag)
{
    void *h;
    Node *n;

    h = func_020122C0(p, a1, func_02161BF8, 0x24);
    n = func_020124E8(h);
    func_02082BCC(n, 0, 0x24);
    n->f00 = p;
    n->f04 = (void *)func_02012138(p);
    if (flag != 0)
        func_02161CDC(n->f08, p, kind, sub);
    else
        func_02161D18((int)n->f08, (int)p, kind, sub);
    if (kind == 3)
        func_0216570C();
    return h;
}


int func_02161BF8(void *a0, int *state, Obj *o)
{
    switch (*state) {
    case 0:
        o->f20 = func_02012144(o->f00);
        func_0201213C(o->f00, 1);
        if (func_02026454(o->f04) == 0) {
            *state = *state + 2;
        } else {
            func_02026400(o->f04);
            *state = *state + 1;
        }
        break;
    case 1:
        if (func_02026454(o->f04) == 0)
            *state = *state + 1;
        break;
    case 2:
        func_020120B4(o->f00, (u32)ov203_id, d_021BFB3C, o->f08);
        *state = *state + 1;
        break;
    case 3:
        if (func_020120F0(o->f00) == 0) {
            func_0201213C(o->f00, o->f20);
            return 1;
        }
        break;
    }
    return 0;
}

/*
 * file:     field_effect_p51.c
 * unit:     yes
 * function: func_021ABF48, func_021ABF68, func_021ABFA8, func_021ABFC0
 * address:  0x021ABF48
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021D8F60  0x021D8F60  data  a4
 *   func_02030CB0  0x02030CB0  arm
 *   func_02030734  0x02030734  arm
 *   func_02030CBC  0x02030CBC  arm
 *   func_021ABFFC  0x021ABFFC  thumb
 *   d_021DE018  0x021DE018  data  a4
 *   func_021AC0A0  0x021AC0A0  thumb
 *   func_021AC03C  0x021AC03C  thumb
 *   func_02030DA4  0x02030DA4  arm
 *   func_020307B0  0x020307B0  arm
 */
struct Ctx;
typedef unsigned short u16;

typedef struct {
    int f0;
    int f4;
} E;

typedef struct T_021ABF48 T_021ABF48;

typedef struct {
    int id;
    int (*f4)(T_021ABF48 *t, u16 h);
    void (*f8)(T_021ABF48 *t, int v);
} D;

struct T_021ABF48 {
    int f0;
    u16 h4;
    u16 pad6;
    int pad8[2];
    E *f10;
};

typedef struct {
    int f0;
    u16 h4;
    u16 pad6;
    int pad8[3];
    u16 h14;
    u16 pad16;
    void *f18;
    int f1c;
    int f20;
} T_021ABF68;

typedef unsigned int   u32;

typedef struct {
    int f0;
    u16 h4;
    u16 pad6;
    int pad8[3];
    u16 h14;
    u16 pad16;
    void *f18;
    int f1c;
    int f20;
} T_021ABFA8;

typedef struct {
    int f0;
    u16 h4;
    u16 pad6;
    int pad8[3];
    u16 h14;
    u16 pad16;
    void *f18;
    int f1c;
    int f20;
} T_021ABFC0;

extern u32 func_02030CB0(u32 idx);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern struct Ctx *func_02030CBC(u32 capacity, struct Ctx *c);
extern char *func_021ABFFC(u16 heap, int b, int cnt);
extern void func_021AC0A0(int a, int b, int c, int d, int e, int f);
extern void func_021AC03C(int a);
extern void func_02030DA4(int a);
extern u32 func_020307B0(void *p);
D *func_021ABF48(int id);
void func_021ABF68(T_021ABF68 *t, int n);
void func_021ABFA8(T_021ABFA8 *t, int b, int c, int d, int e, int f);
void func_021ABFC0(T_021ABFC0 *t);
extern D d_021D8F60[];
extern char d_021DE018[];


D *func_021ABF48(int id)
{
    int i;
    D *d = d_021D8F60;
    for (i = 0; i < 0x18; i++) {
        if (d->id == id) {
            return d;
        }
        d++;
    }
    return d;
}


void func_021ABF68(T_021ABF68 *t, int n)
{
    t->h14 = n;
    t->f18 = func_02030734(t->h4, func_02030CB0(n), 0, d_021DE018, 0x1db);
    t->f1c = (int)func_02030CBC(n, t->f18);
    t->f20 = (int)func_021ABFFC(t->h4, t->f1c, n);
}


void func_021ABFA8(T_021ABFA8 *t, int b, int c, int d, int e, int f)
{
    func_021AC0A0(t->f20, b, c, d, e, f);
}


void func_021ABFC0(T_021ABFC0 *t)
{
    if (t->f20 != 0) {
        func_021AC03C(t->f20);
        func_02030DA4(t->f1c);
        func_020307B0(t->f18);
    }
}

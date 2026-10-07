/*
 * file:     unit_02175C40_p02.c
 * unit:     yes
 * function: func_02175DCC, func_02175DE4, func_02175E30, func_02175E90
 * address:  0x02175DCC
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02175B14 0x02175B14 thumb ov011
 *   func_02026478  0x02026478  thumb
 *   func_02012B58  0x02012B58  thumb
 *   func_020127B8  0x020127B8  thumb
 *   func_02012950  0x02012950  thumb
 *   func_02008530  0x02008530  thumb
 *   func_021584F4  0x021584F4  thumb  ov010
 *   func_02175DA8 0x02175DA8 thumb ov011
 */
struct BigObj;
struct Rec44;
struct Sub0200852CObj;
struct Sub24;
typedef unsigned char u8;

typedef unsigned int u32;

typedef struct { u8 pad[0x7c]; u32 value:4; u32 rest:28; } Bits;

typedef struct {
    u32 w0;
    u8  pad04[0x30];
    u8  f34[3];
    u8  f37;
} Blk;

typedef struct {
    u8 v : 6;
} Bf6;

typedef struct {
    u32 w0;
    u32 slot : 4;
} Rec;

extern int func_02175B14(u8 *p);
extern u32 func_02026478(void *obj);
extern u8 func_02012B58(const struct BigObj *p);
extern void *func_020127B8(void *p);
extern struct Rec44 *func_02012950(struct Sub24 *p, u32 i);
extern u32 func_02008530(const struct Sub0200852CObj *obj);
extern int func_021584F4(int a0, int a1);
extern int func_02175DA8(u8 *);
int func_02175DCC(void *p);
int func_02175DE4(void *p, u8 *a1);
void func_02175E30(void *a, u8 *b, Rec *c);
int func_02175E90(void *p, u8 *q);

int func_02175DCC(void *p)
{
    if (func_02175B14(p) == 0) return 6;
    return ((Bits *)p)->value;
}


int func_02175DE4(void *p, u8 *a1)
{
    Blk *b;
    int sv;
    int i;

    sv = func_02026478(((void **)p)[1]);
    b = (Blk *)((char *)p + 0x258);
    if (b->f37 == 1) {
        return 0;
    }
    for (i = 0; i < 3; i++) {
        if (b->f34[i] == func_02012B58((const struct BigObj *)sv)) {
            u32 v = (b->w0 << 10) >> 25;
            if (v > 0x14) {
                return 1;
            }
            return v;
        }
    }
    return 0;
}


void func_02175E30(void *a, u8 *b, Rec *c)
{
    u8 *d;
    u32 v;
    int r;
    int t;

    d = func_020127B8(a);
    t = (int)func_02012950(a, ((u8 *)c)[0x34]);
    v = ((Bf6 *)(b + ((u8 *)c)[0x34] * 0x1c + 0xa7))->v;
    r = func_021584F4((u8)v, func_02008530((const struct Sub0200852CObj *)t));
    if (r == 0x14) {
        *(u8 *)((u8 *)(d + c->slot) + 6) = 1;
    } else if (r == 0x15) {
        *(u8 *)((u8 *)(d + c->slot) + 6) = 2;
    }
}

/*
 * interface: DE4 source declares one argument; original E90 visibly sets r1, preserved here.
 */
int func_02175E90(void *p, u8 *q)
{
    if (func_02175DA8(q) == 0) return 0;
    if (func_02175DE4(p, q) > 0) return 1;
    return 0;
}

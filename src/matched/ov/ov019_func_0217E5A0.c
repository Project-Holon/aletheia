/*
 * function: func_0217E5A0
 * address:  0x0217E5A0
 * packet:   pkt_ov019_0217E5A0
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0217BB20  0x0217BB20  thumb  ov019
 *   func_0217F074  0x0217F074  thumb  ov019
 *   func_0217F1EC  0x0217F1EC  thumb  ov019
 *   func_0217F210  0x0217F210  thumb  ov019
 *   func_0217B8E4  0x0217B8E4  thumb  ov019
 *   func_0217422C  0x0217422C  thumb  ov012
 *   func_02174268  0x02174268  thumb  ov012
 *   func_0201292C  0x0201292C  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200873C  0x0200873C  thumb
 *   func_020084F4  0x020084F4  thumb
 *   func_02008550  0x02008550  thumb
 *   func_020399A8  0x020399A8  arm
 *   func_0203D1A4  0x0203D1A4  arm
 *   func_0203D1B4  0x0203D1B4  arm
 *   func_02039C68  0x02039C68  arm
 *   func_02039CB4  0x02039CB4  arm
 *   func_02030734  0x02030734  arm
 *   func_020307B0  0x020307B0  arm
 *   d_021807E8     0x021807E8  data  a4
 */

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    int f0;
    int f4;
    int f8;
} Sys;

typedef struct {
    int f68;
    int f6c;
    u8 f70;
} Ent;

typedef struct {
    int f0;
    void *f4;
    int f8;
    int fc;
    int f10;
    int f14;
    u8 pad18[0x34 - 0x18];
    int f34;
    u8 pad38[0x60 - 0x38];
    u16 f60;
    u8 pad62[0x64 - 0x62];
    int f64;
    Ent ent[3];
    int f8c;
    int f90;
    u8 pad94[0xc0 - 0x94];
    int *fc0;
} Req;

int func_0217BB20(u8 *w);
typedef unsigned int   u32;
void func_0217F074(void *p);
u32 func_0217F1EC(u8 *p);
void func_0217F210(u8 *p, int a, u32 b);
int func_0217B8E4(u8 *w, int v);
void func_0217422C(u8 *w, int b, Req *c);
int func_02174268(u8 *w);
struct Big;
struct BigObj;
struct Link;
struct Sub02008700Obj;
void *func_0201292C(const struct BigObj *p);
void *func_02012EBC(struct Big *p);
struct Sub02008700Obj *func_0200873C(void *sys);
int func_020084F4(u8 *a);
u8 func_02008550(u8 *a);
struct Entry;
struct Entry *func_020399A8(void);
u32 func_0203D1A4(struct Link *p);
int func_0203D1B4(void);
struct Link;
void func_02039C68(struct Link *a, unsigned int b, unsigned int c);
unsigned int func_02039CB4(struct Link *a, unsigned int b, unsigned int c);
void *func_02030734(u32 heap, u32 size, int clear, const char *site, u16 tag);
void func_020307B0(void *a);
extern int d_021807E8[];

int func_0217E5A0(u8 *w, u8 *obj, int a2, u8 *state)
{
    u8 *p;
    int idx;
    int msg;
    Req *q;
    int i;
    int cnt;
    int k;

    p = *(u8 **)(w + 0x355C);
    idx = func_0203D1A4((struct Link *)((int)func_020399A8()));
    if (*state < 3 && func_0217BB20(w) == 1) {
        func_0217F074(w);
        return 1;
    }
    switch (*state) {
    case 0:
        if (func_0217F1EC(w) != 1)
            break;
        switch (obj[0x2d]) {
        default:
            msg = 0x117;
            break;
        case 6:
        case 7:
        case 22:
        case 23:
            msg = 0x118;
            break;
        case 20:
        case 21:
            msg = 0x11b;
            break;
        case 10:
        case 11:
        case 18:
        case 19:
            msg = 0x119;
            break;
        case 14:
        case 15:
            msg = 0x11a;
            break;
        }
        func_0217F210(w, a2, msg);
        (*state)++;
        break;
    case 1:
        if (func_0217F1EC(w) == 1) {
            func_02039C68((struct Link *)func_020399A8(), 0x11, 0x14);
            (*state)++;
        }
        break;
    case 2:
        if (func_02039CB4((struct Link *)func_020399A8(), 0x11, 0x14) == 1) {
            func_0217F074(w);
            (*state)++;
        }
        break;
    case 3:
        q = func_02030734(0x41, 0xc4, 1, (const char *)d_021807E8, 0x10c4);
        q->f0 = ((int *)(p + 0x148))[idx];
        q->f4 = func_0201292C((const struct BigObj *)((*(Sys **)w)->f8));
        q->fc = (int)func_0200873C(func_02012EBC((struct Big *)((*(Sys **)w)->f8)));
        q->f34 = 0x1a;
        q->f14 = *(int *)(w + 0x352C);
        q->fc0 = func_02030734(0x41, 0x70, 1, (const char *)d_021807E8, 0x10ce);
        cnt = 0;
        for (i = 0; i < func_0203D1B4(); i++) {
            if (i == idx)
                continue;
            if ((p[idx + 0x15c] & 1) == (p[i + 0x15c] & 1))
                k = 0;
            else
                k = ++cnt;
            q->ent[k].f68 = ((int *)(p + 0x148))[i];
            q->ent[k].f6c = func_020084F4(p + 0x18 + i * 0x2c);
            q->ent[k].f70 = func_02008550(p + 0x18 + i * 0x2c);
        }
        switch (obj[0x2d]) {
        case 20:
        case 21:
        case 22:
        case 23:
            q->f64 = 2;
            break;
        default:
            q->f64 = 1;
            break;
        }
        q->f8c = 1;
        q->f90 = 0;
        q->f60 = 0;
        *(Req **)(w + 0x3558) = q;
        func_0217422C(w, 0x1a, q);
        (*state)++;
        break;
    case 4:
        if (func_02174268(w) == 1)
            break;
        func_020307B0((*(Req **)(w + 0x3558))->fc0);
        func_020307B0(*(Req **)(w + 0x3558));
        *(Req **)(w + 0x3558) = 0;
        func_0217B8E4(w, 0x2c);
        return 1;
    }
    return 0;
}

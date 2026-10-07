/*
 * file:     unit_0217AE20_p03.c
 * unit:     yes
 * function: func_0217B1D0, func_0217B264
 * address:  0x0217B1D0
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   memcmp        0x0203EFC8  arm
 *   memset        0x02082BCC  arm
 *   func_02012114 0x02012114  thumb
 *   func_0201210C 0x0201210C  thumb
 *   func_02188CE0 0x02188CE0  thumb  ov021
 *   func_0217AED4 0x0217AED4  thumb  ov019
 *   func_02012964 0x02012964  thumb
 *   func_0216DE94 0x0216DE94  thumb  ov010
 *   func_0217F93C 0x0217F93C  thumb  ov019
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200ED48  0x0200ED48  thumb
 *   func_0201283C  0x0201283C  thumb
 *   MI_CpuFill8    0x02082BCC  arm
 *   func_0217B054  0x0217B054  thumb  ov019
 *   func_0217B098  0x0217B098  thumb  ov019
 *   func_0217B370  0x0217B370  thumb  ov019
 *   func_0217B3EC  0x0217B3EC  thumb  ov019
 */
struct Ctx;
struct BigObj;
struct Big;
struct ent;
struct obj;
typedef unsigned char u8;

struct sub {
    u8 mac[6];
    u8 pad;
    u8 : 1;
    u8 f : 1;
    u8 : 6;
};

struct ent {
    u8 pad0[0x28];
    struct sub s[5];
    u8 pad1[0x20];
    int p[5];
};

struct inner {
    int pad0[2];
    int f8;
    int fc;
};

struct obj {
    struct inner *in;
};

typedef unsigned int   u32;

typedef unsigned short u16;

typedef struct Entry {
    u8   pad0[7];
    u8   f7_lo : 4;
    u8   active : 1;
    u8   f7_hi : 3;
    u8   pad8[0x6C - 8];
    u16  h6C;
    u16  pad6E;
    void *slots[5];
    u8   pad84[8];
} Entry;

extern int memcmp(const void *a, const void *b, int n);
extern void memset(void *p, int v, int n);
extern unsigned int func_02012114(const struct Ctx *p);
extern void *func_0201210C(const struct Ctx *p);
extern u32 func_02188CE0(u8 *p);
extern u16 func_0217AED4(u8 *a, u8 *b);
extern u32 func_02012964(const struct BigObj *p);
extern void *func_0216DE94(void *map, u32 id);
extern void func_0217F93C(int, int);
extern void *func_02012EBC(struct Big *p);
extern void *func_0200ED48(void *p);
extern u32 func_0201283C(const struct BigObj *p);
extern void  MI_CpuFill8(void *dst, u8 val, u32 size);
extern void  func_0217B054(u8 *w, Entry *e, void *p);
extern void  func_0217B098(u8 *w, u32 a, u32 b, u32 c, Entry *e);
extern int func_0217B370(char *base, unsigned char *p, int r2);
extern int func_0217B3EC(char *base, char *p);
int func_0217B1D0(struct obj *o, struct ent *e);
void func_0217B264(u8 *w, void *sys, void *q);


int func_0217B1D0(struct obj *o, struct ent *e)
{
    int i;
    int v;
    int t;
    int r;

    for (i = 0; i < 5; i++) {
        v = e->p[i];
        if (v == 0 || e->s[i].f != 1) {
            continue;
        }
        if (memcmp(e->s[i].mac, (char *)o + 0x28a4, 6) != 0) {
            continue;
        }
        if (func_02012114((const struct Ctx *)o->in->fc) == 1) {
            t = func_02188CE0(func_0201210C((void *)o->in->fc));
            if (t != 0) {
                r = func_0217AED4((u8 *)e, (u8 *)v);
                r = (int)func_0216DE94((void *)func_02012964((const struct BigObj *)o->in->f8), r);
                if (r != 0) {
                    func_0217F93C(t, r);
                }
            }
        }
        memset((char *)o + 0x28a4, 0, 6);
        return 1;
    }
    return 0;
}


/*
 * Addresses are Black-image addresses.
 */
void func_0217B264(u8 *w, void *sys, void *q)
{
    int i;
    int flag;
    u32 a;
    u32 b;
    u32 c;
    Entry *e;
    u8 buf[6] = {0, 0, 0, 0, 0, 0};

    flag = 0;
    a = (u32)func_0200ED48(func_02012EBC(sys));
    b = func_0201283C(sys);
    c = func_02188CE0(q);
    func_02012964(sys);
    if (memcmp(buf, w + 0x28A4, 6) != 0) {
        flag = 1;
    }
    e = (Entry *)(w + 0x2910);
    for (i = 0; i < 10; i++, e++) {
        if (e->active == 1) {
            int cnt;
            int j;
            void *p;

            func_0217B3EC((char *)w, (char *)e);
            func_0217B098(w, a, b, c, e);
            if (flag == 1) {
                if (func_0217B1D0((struct obj *)w, (struct ent *)e) == 1) {
                    flag = 0;
                }
            }
            cnt = 0;
            for (j = 0; j < 5; j++) {
                p = e->slots[j];
                if (p != 0) {
                    if (func_0217B370((char *)w, p, (int)q) == 0) {
                        func_0217B054(w, e, p);
                        e->slots[j] = 0;
                        cnt++;
                    }
                } else {
                    cnt++;
                }
            }
            if (cnt >= 5 && e->h6C == 0) {
                MI_CpuFill8(e, 0, sizeof(Entry));
            }
        }
    }
    MI_CpuFill8(w + 0x28A4, 0, 6);
}

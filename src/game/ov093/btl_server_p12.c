/*
 * file:     btl_server_p12.c
 * unit:     yes
 * function: func_021BB4E0, func_021BB56C, func_021BB570, func_021BB5FC, func_021BB628, func_021BB650, func_021BB6A8, func_021BB718, func_021BB724, func_021BB768, func_021BB798, func_021BB7D0, func_021BB7FC, func_021BB828, func_021BB830
 * address:  0x021BB4E0
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021EE9B4  0x021EE9B4  thumb  ov093
 *   func_021EE9E4  0x021EE9E4  thumb  ov093
 *   func_021BBB60  0x021BBB60  thumb  ov093
 *   func_021BBC34  0x021BBC34  thumb  ov093
 *   func_021BBC44  0x021BBC44  thumb  ov093
 *   func_021BBD80  0x021BBD80  thumb  ov093
 *   func_021BBD8C  0x021BBD8C  thumb  ov093
 *   func_021BBD20  0x021BBD20  thumb  ov093
 *   func_021BBD2C  0x021BBD2C  thumb  ov093
 *   func_0203EFC8  0x0203EFC8  arm
 *   func_021EE8B4 0x021EE8B4 thumb ov093
 *   func_021EE8D8 0x021EE8D8 thumb ov093
 *   func_021EEB64  0x021EEB64  thumb  ov093
 *   func_021EE8F4  0x021EE8F4  thumb  ov093
 *   func_021EE96C  0x021EE96C  thumb  ov093
 *   func_021EEAE8  0x021EEAE8  thumb  ov093
 *   func_021EEB00  0x021EEB00  thumb  ov093
 *   func_021EEAFC  0x021EEAFC  thumb  ov093
 *   func_021EEB70 0x021EEB70 thumb ov093
 *   func_021EEB2C 0x021EEB2C thumb ov093
 *   func_021EEAD0 0x021EEAD0 thumb ov093
 */
#include "../../matched/include/Obj03190.h"

struct QW;
typedef unsigned char u8;

typedef unsigned int u32;

typedef struct {
    u8 pad0[0x68];
    u8 rd[0x4c];      /* 0x68 */
    u32 tab[4][3];    /* 0xb4 */
    u8 cnt[4];        /* 0xe4 */
} Obj;

typedef signed int     s32;

typedef struct { u32 h; u32 x[2]; } E;

typedef struct { u32 w; } W;

typedef struct { W v[3]; } D;

typedef struct {
    u8 pad0[0x14];
    E e[4];
    u8 pad1[0x70];
    D d[4];
    u8 c[4];
} P;

typedef unsigned short u16;

typedef signed char s8;

typedef signed short s16;

extern void func_021EE9B4(u8 *, void *, u8);
extern int func_021EE9E4(u8 *p, u32 *pos, u8 *a, u8 *b, u32 *dst);
extern int func_021BBB60(u8 *);
extern void func_021BBC34(u8 *);
extern int func_021BBC44(u8 *, int);
extern void func_021BBD80(u8 *);
extern int func_021BBD8C(u8 *, int);
extern void func_021BBD20(u8 *);
extern int func_021BBD2C(u8 *, int);
extern s32 func_0203EFC8(const u8 *a, const u8 *b, u32 n);
extern void func_021EE8B4(u8 *, int);
extern u8 *func_021EE8D8(u8 *p, u32 *out, int flag);
extern u32 func_021EEB64(struct QW *p, u32 *out);
extern void func_021EE8F4(u8 *p, u8 idx, const void *src, u32 n);
extern u32 func_021EE96C(u8 *p, int a, int b);
extern void func_021EEAE8(void);
extern void func_021EEB00(u32, int, int, int);
extern void func_021EEAFC(void);
extern void func_021EEB70(u32);
extern int func_021EEB2C(u32);
extern void func_021EEAD0(u8 *p);
void func_021BB4E0(Obj *p, void *src, u8 n);
void func_021BB56C(void *p);
int func_021BB570(u8 *p, int sel, void *data, u32 n);
int func_021BB5FC(u8 *p, int b);
int func_021BB628(u8 *p, int a, int b);
int func_021BB650(u8 *p, int a, int b, int c);
void func_021BB6A8(P *p);
void func_021BB718(int a, int b);
void func_021BB724(u8 *p, int a, int b, int c);
void func_021BB768(u8 *p, int a, u32 i, int b, int c);
int func_021BB798(u8 *p);
void func_021BB7D0(const u8 *p);
void func_021BB7FC(const u8 *p);
void func_021BB828(u8 *p);
int func_021BB830(u8 *p);


void func_021BB4E0(Obj *p, void *src, u8 n)
{
    u8 i;
    u8 type;
    u8 count;
    int idx;
    u32 buf[3];

    idx = 0;
    for (i = 0; i < 4; i++)
        p->cnt[i] = 0;
    func_021EE9B4(p->rd, src, n);
    while (func_021EE9E4(p->rd, (u32 *)(&idx), &type, &count, buf) != 0) {
        for (i = 0; i < count; i++)
            p->tab[type][i] = buf[i];
        p->cnt[type] = count;
    }
}

void func_021BB56C(void *p)
{
}


int func_021BB570(u8 *p, int sel, void *data, u32 n)
{
    u32 *s = *(u32 * *)&((struct Obj03190 *)p)->fCB0;

    s[0] = 0;
    s[1] = 0;
    switch (sel) {
    case 4:
        func_021BBB60(*(u8 * *)&((struct Obj03190 *)p)->f44);
        break;
    case 1:
        func_021BBC34(*(u8 * *)&((struct Obj03190 *)p)->f44);
        func_021BBC44(*(u8 * *)&((struct Obj03190 *)p)->f44, (int)(p + 0xb4));
        break;
    case 2:
        func_021BBD80(*(u8 * *)&((struct Obj03190 *)p)->f44);
        func_021BBD8C(*(u8 * *)&((struct Obj03190 *)p)->f44, (int)(p + 0xb4));
        break;
    case 3:
        func_021BBD20(*(u8 * *)&((struct Obj03190 *)p)->f44);
        func_021BBD2C(*(u8 * *)&((struct Obj03190 *)p)->f44, (int)(p + 0xb4));
        break;
    }
    s = *(u32 * *)&((struct Obj03190 *)p)->fCB0;
    if (s[0] == n && func_0203EFC8((const u8 *)(s + 2), data, n) == 0)
        return 0;
    return 1;
}

int func_021BB5FC(u8 *p, int b)
{
 int n;
 int r;
 func_021EE8B4(p + 0x68, 1);
 r = (int)func_021EE8D8(p + 0x68, (u32 *)(&n), b);
 func_021BB724(p, 10, r, n);
 return 1;
}

/*
 * interface: func_021BB650's matched source declares void and an integer
 * fourth payload. Its original forwards that full word into EE96C r2;
 * EE96C stores the output count through r2 only on its nonzero return path
 * (021EE998), returns base+4 or zero, and BB650 leaves that r0 live.
 * This caller passes &n in r3 and reads r0, so its extern preserves both.
 */
int func_021BB628(u8 *p, int a, int b)
{
 int n;
 int r;
 r = func_021BB650(p, a, b, (int)(&n));
 if (r != 0) {
  func_021BB724(p, 10, r, n);
  return 1;
 }
 return 0;
}


int func_021BB650(u8 *p, int a, int b, int c)
{
    u32 i;
    u32 v;

    func_021EE8B4(p + 0x68, b);
    for (i = 0; i < 4; i++) {
        if (p[i * 12 + 0x1f] != 0xff) {
            u32 r = func_021EEB64((struct QW *)(*(u32 *)(p + i * 12 + 0x14)), &v);

            func_021EE8F4(p + 0x68, i, (const void *)r, (v << 22) >> 24);
        }
    }
    return func_021EE96C(p + 0x68, a, c);
}


/*
 * note 2026-10-05 (final push G6L5): closed by copying each word through a one-word struct
 *   (`typedef struct { u32 w; } W;`, source cursor `W *s`, destination element type W, so
 *   `p->d[i].v[j] = *s++;` is a struct assignment). The word-copy path creates the load before
 *   the destination address, which gives the walking source in r2 with j in r0, cnt in r1 and
 *   the load in r6. Plain `u32 *s` with `*s++` (every spelling) gave j=r1, cnt=r2, s=r3, load r0
 *   (51 bytes); indexed `s[j]` gave `ldr r6,[r2,r4]` (1 byte). Same shape in both lang c99 and c.
 */
void func_021BB6A8(P *p)
{
    u32 i;
    u32 j;
    u32 n;
    u32 cnt;
    W *s;
    E *e;

    for (i = 0; i < 4; i++) {
        e = &p->e[i];
        p->c[i] = 0;
        if (func_021BB830((u8 *)e) != 0) {
            s = (W *)func_021EEB64((void *)e->h, &n);
            cnt = n >> 2;
            for (j = 0; j < cnt; j++) {
                p->d[i].v[j] = *s++;
                p->c[i]++;
            }
        }
    }
}


void func_021BB718(int a, int b)
{
    func_021BB724((u8 *)a, b, 0, 0);
}


void func_021BB724(u8 *p, int a, int b, int c)
{
    int i;
    u8 *q;

    func_021EEAE8();
    i = 0;
    q = p + 0x14;
    for (; i < 4; i++) {
        if (func_021BB830(q + i * 12) != 0)
            func_021EEB00(*(u32 *)(p + 0x14 + i * 12), a, b, c);
    }
    func_021EEAFC();
}

void func_021BB768(u8 *p, int a, u32 i, int b, int c) {
    u8 *q;
    q = (u8 *)((u32)p + 20);
    if (func_021BB830((u8 *)((u32)q+i*12))) {
        func_021EEB70(*(u32 *)((u32)q+i*12));
        func_021EEB00(*(u32 *)((u32)q+i*12),a,b,c);
    }
}

int func_021BB798(u8 *p) {
    int result;
    int i;
    u8 *q;
    result = 1; i = 0; q = p+20;
    for (; i < 4; i++) {
        if (func_021BB830(q+i*12)) {
            if (!func_021EEB2C(*(u32 *)((p+i*12)+20))) result = 0;
        }
    }
    return result;
}

void func_021BB7D0(const u8 *p) {
    int i;
    i = 0;
    for (; i < 4; i++) {
        if (func_021BB830((u8 *)(p+20+i*12))) func_021EEB70(*(const u32 *)((p+i*12)+20));
    }
}

void func_021BB7FC(const u8 *p) {
    int i;
    i = 0;
    for (; i < 4; i++) {
        if (func_021BB830((u8 *)(p+20+i*12))) func_021EEAD0((u8 *)(*(const u32 *)((p+i*12)+20)));
    }
}


/*
 * store constant 0xff at #0xb
 */
void func_021BB828(u8 *p)
{
    *(u8 *)&p[0xb] = 0xff;
}

int func_021BB830(u8 *p) { if (p[11] != 255) return 1; return 0; }

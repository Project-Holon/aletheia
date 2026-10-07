/*
 * file:     unit_021F36C0.c
 * unit:     yes
 * function: func_021F36C0, func_021F38AC, func_021F38F4, func_021F3934, func_021F394C, func_021F395C
 * address:  0x021F36C0
 * region:   ov036
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0203F4E4  0x0203F4E4  arm
 *   func_021F3980  0x021F3980  thumb  ov036
 *   d_021F3AD4     0x021F3AD4  data  a4
 *   d_021F3B4C     0x021F3B4C  data  a4
 *   d_021F3A98     0x021F3A98  data  a4
 *   d_021F3BEC     0x021F3BEC  data  a4
 *   func_020056EC 0x020056EC thumb
 */
struct RtcDate;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct {
    u32 year;
    u32 month;
    u32 day;
    u32 week;
} RTCDate;

typedef struct {
    u8 slot[15];
    u8 order[15];
    u8 count;
    u8 max;
    u8 a[7];
    u8 b[2];
    u8 c[10];
} Deck;

typedef struct {
    int id;
    int sub;
    int a;
    int type;
    int c;
    int d;
    int e;
} Ent;

typedef struct {
    u8 pad0[6];
    u16 f6;
    u8 pad8[4];
    Ent ent[15];
    u8 c0;
    u8 c1;
    u8 c2;
    u8 c3;
} W;

typedef struct {
    int a;
    int b;
} P8;

typedef struct {
    int a;
    int b;
    int c;
    int d;
} P16;

typedef struct {
    int a;
    int b;
    int c;
} P12;

extern void func_0203F4E4(struct RtcDate *date);
extern int func_021F3980(u8 *p);
extern u32 func_020056EC(u32 range);
void func_021F36C0(W *w);
void func_021F38AC(int n, int m, unsigned char *buf, unsigned char *out);
void func_021F38F4(unsigned char *p);
int func_021F3934(u8 *p, int v);
int func_021F394C(u8 *p, int i);
int func_021F395C(unsigned char *p, int idx);
extern const P8 d_021F3AD4[];
extern const P16 d_021F3B4C[];
extern const P12 d_021F3A98[];
extern const P12 d_021F3BEC[];


void func_021F36C0(W *w)
{
    RTCDate date;
    Deck d;
    u8 ta[10];
    u8 tc[15];
    u8 tb[5];
    int v;
    u8 i;
    int n;
    int cnt;
    u8 s;
    u8 x;
    u8 y;

    func_0203F4E4((struct RtcDate *)(&date));
    switch (date.week) {
    case 1:
        v = 4;
        break;
    case 2:
        v = 3;
        break;
    case 3:
        v = 4;
        break;
    case 4:
        v = 5;
        break;
    case 5:
        v = 4;
        break;
    case 6:
        v = 6;
        break;
    case 0:
        v = 7;
        break;
    default:
        v = 0;
        break;
    }
    w->f6 = v;
    func_021F38F4((unsigned char *)(&d));
    if (func_021F3980((u8 *)(&d)) == 0)
        func_021F38F4((unsigned char *)(&d));
    func_021F38AC(10, v, ta, d.a);
    func_021F38AC(5, 2, tb, d.b);
    func_021F38AC(15, 15 - (v + 2), tc, d.c);
    for (i = 0; i < v; i++) {
        s = d.order[i];
        if (d_021F3AD4[s].a == 0)
            w->c0++;
        else
            w->c1++;
        if (d_021F3AD4[s].b == 0)
            w->c2++;
        else
            w->c3++;
    }
    n = 0;
    for (i = 0; i < v; i++) {
        y = d.order[n];
        x = d.a[i];
        w->ent[y].id = x;
        w->ent[y].sub = d_021F3B4C[x].b;
        w->ent[y].a = d_021F3B4C[x].a;
        w->ent[y].type = 0;
        w->ent[y].c = d_021F3B4C[x].c;
        w->ent[y].d = d_021F3B4C[x].d;
        n++;
    }
    for (i = 0; i < 2; i++) {
        y = d.order[n];
        x = d.b[i];
        w->ent[y].id = i;
        w->ent[y].sub = 0;
        w->ent[y].a = d_021F3A98[x].a;
        w->ent[y].type = 2;
        w->ent[y].c = d_021F3A98[x].b;
        w->ent[y].d = d_021F3A98[x].c;
        n++;
    }
    cnt = 15u - (v + 2);
    for (i = 0; i < cnt; i++) {
        y = d.order[n];
        x = d.c[i];
        w->ent[y].id = i;
        w->ent[y].sub = 0;
        w->ent[y].a = d_021F3BEC[x].a;
        w->ent[y].type = 1;
        w->ent[y].c = d_021F3BEC[x].b;
        w->ent[y].d = d_021F3BEC[x].c;
        n++;
    }
}


void func_021F38AC(int n, int m, unsigned char *buf, unsigned char *out)
{
    unsigned char i;
    unsigned char j;
    unsigned char k;

    for (i = 0; i < n; i++)
        buf[i] = i;
    for (j = 0; j < m; j++) {
        k = func_020056EC(n);
        out[j] = buf[k];
        buf[k] = buf[n - 1];
        n--;
    }
}

void func_021F38F4(unsigned char *p)
{
    int i;
    int j;

    p[0x1f] = 14;
    p[0x1e] = 0;
    for (i = 0; i < 15; i++) {
        p[i] = i;
        p[i + 0xf] = 0;
    }
    for (j = 0; j < 7; j++)
        p[0x20 + j] = j;
    for (i = 0; i < 2; i++)
        p[0x27 + i] = i;
    for (i = 0; i < 10; i++)
        p[0x29 + i] = i;
}

int func_021F3934(u8 *p, int v)
{
    int i;
    for (i = 0; i < 15; i++) {
        if (p[i] == v) return i;
    }
    return -1;
}

int func_021F394C(u8 *p, int i)
{
    if (i > p[0x1f]) return -1;
    return p[i];
}

int func_021F395C(unsigned char *p, int idx)
{
    if (idx > p[0x1f])
        return 0;
    if (idx < 0)
        return 0;
    p[idx] = p[p[0x1f]];
    if (p[0x1f] != 0)
        p[0x1f] = p[0x1f] - 1;
    return 1;
}

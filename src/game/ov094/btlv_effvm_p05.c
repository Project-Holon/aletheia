/*
 * file:     btlv_effvm_p05.c
 * unit:     yes
 * function: func_021F723C, func_021F73A4, func_021F73F0, func_021F745C
 * address:  0x021F723C
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021F9220 0x021F9220 thumb ov094
 *   func_021F9260 0x021F9260 thumb ov094
 *   func_02048AFC 0x02048AFC arm
 *   func_02048B44 0x02048B44 arm
 *   func_02048AD0 0x02048AD0 arm
 *   func_02048AE8  0x02048AE8  arm
 *   func_02048B30  0x02048B30  arm
 *   func_0207CFB8  0x0207CFB8  arm
 *   func_0207CBD0  0x0207CBD0  arm
 *   sub_02030734   0x02030734  arm
 *   d_0220AC90     0x0220AC90  data   ov094  a1
 *   func_021B86C8 0x021B86C8 thumb ov093
 *   func_021B8FE4 0x021B8FE4 thumb ov093
 *   func_021B8FF4 0x021B8FF4 thumb ov093
 *   func_021B9000 0x021B9000 thumb ov093
 *   func_021BA020 0x021BA020 thumb ov093
 *   func_021B904C 0x021B904C thumb ov093
 *   func_021B8588 0x021B8588 thumb ov093
 *   func_021B86B8 0x021B86B8 thumb ov093
 *   func_021B8714 0x021B8714 thumb ov093
 */
struct Light;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct {
    int w[4];
} Q;

typedef struct {
    int f0;
    int f4;
    Q q;            /* 0x08 */
    u16 h[4];       /* 0x18 */
    int f20;
    int f24;
    int f28;
} Obj;

extern void func_021F9220(int *, int *, int *, int *);
extern int func_021F9260(void *, void *);
extern void func_02048AFC(int, int *);
extern void func_02048B44(int, int *);
extern void func_02048AD0(struct Light *l);
extern void func_02048AE8(int, int *);
extern void func_02048B30(int, int *);
extern int func_0207CFB8(int, int);
extern int func_0207CBD0(int *);
extern void *sub_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern int func_021B86C8(unsigned char **p);
extern u8 func_021B8FE4(u8 *p);
extern u8 func_021B8FF4(u8 *);
extern u8 func_021B9000(u8 *p);
extern u16 func_021BA020(char *, int);
extern u8 func_021B904C(u8 *p, int k);
extern u32 func_021B8588(void **p);
extern void *func_021B86B8(void ***);
extern char *func_021B8714(char **);
void func_021F723C(int *p);
void func_021F73A4(int *p);
Obj *func_021F73F0(int a, int b, Q *q, int c, u16 *h, int e, int f, u16 heap);
void *func_021F745C(u8 *p, int a, u16 heap);
extern const char d_0220AC90[];


void func_021F723C(int *p)
{
    int a[3];
    int b[3];
    int ret = 1;
    int n;
    if (p[5] == 0) return;
    if (p[27] == 0) {
        p[27] = p[28];
        if (p[29] != 0) {
            if (--p[29] == 0) {
                n = p[18] >> 1; if (n) p[18] = n;
                n = p[19] >> 1; if (n) p[19] = n;
                n = p[20] >> 1; if (n) p[20] = n;
                n = p[21] >> 1; if (n) p[21] = n;
                n = p[22] >> 1; if (n) p[22] = n;
                n = p[23] >> 1; if (n) p[23] = n;
            }
        }
        if (p[5] & 1) {
            func_021F9220(&p[6], &p[18], &p[12], &ret);
            func_021F9220(&p[7], &p[19], &p[13], &ret);
            func_021F9220(&p[8], &p[20], &p[14], &ret);
            if (ret == 1) p[5] &= ~1;
        }
        if (p[5] & 2) {
            func_021F9220(&p[9], &p[21], &p[15], &ret);
            func_021F9220(&p[10], &p[22], &p[16], &ret);
            func_021F9220(&p[11], &p[23], &p[17], &ret);
            if (ret == 1) p[5] &= ~2;
        }
        if (p[5] & 4) {
            ret = func_021F9260(&p[30], &p[24]);
            if (ret == 1) p[5] &= ~4;
        }
        a[0] = p[6] + p[24];
        a[1] = p[7] + p[25];
        a[2] = p[8] + p[26];
        b[0] = p[9] + p[24];
        b[1] = p[10] + p[25];
        b[2] = p[11] + p[26];
        func_02048AFC(p[1], a);
        func_02048B44(p[1], b);
        func_02048AD0((struct Light *)p[1]);
        func_021F73A4(p);
    } else {
        p[27]--;
    }
}


void func_021F73A4(int *p)
{
    int a[3];
    int b[3];
    func_02048AE8(p[1], a);
    func_02048B30(p[1], b);
    a[0] -= b[0];
    a[1] -= b[1];
    a[2] -= b[2];
    p[2] = func_0207CFB8(a[1], a[2]);
    p[3] = func_0207CFB8(a[2], a[0]);
    p[4] = func_0207CBD0(a);
}


Obj *func_021F73F0(int a, int b, Q *q, int c, u16 *h, int e, int f, u16 heap)
{
    Obj *o;
    int i = 0;

    o = sub_02030734((u16)((heap & 0x7fff) | 0x8000), 0x2c, 0, d_0220AC90, 0xca);
    o->f0 = a;
    o->f4 = b;
    o->q = *q;
    o->f20 = c;
    o->f24 = f;
    o->f28 = e;
    for (; i < 4; i++)
        o->h[i] = h[i];
    return o;
}


void *func_021F745C(u8 *p, int a, u16 heap)
{
    u16 h[4];
    unsigned int i;
    int side, idx, other;
    int mode, type;
    Q *q;
    for (i = 0; i < 4; i++) h[i] = 0;
    if (func_021B86C8((unsigned char **)p) == 1) {
        side = func_021B8FE4(p);
        idx = func_021B8FF4(p);
        other = func_021B9000(p);
        h[side * 2] = func_021BA020((char *)p, idx);
        if (other != 4) h[(side ^ 1) * 2] = func_021BA020((char *)p, other);
        h[1] = func_021BA020((char *)p, func_021B904C(p, 0));
        h[3] = func_021BA020((char *)p, func_021B904C(p, 1));
    } else {
        h[0] = func_021BA020((char *)p, func_021B8FF4(p));
        h[1] = func_021BA020((char *)p, func_021B904C(p, 0));
        h[2] = 0;
        h[3] = 0;
    }
    mode = func_021B8588((void **)p);
    type = (int)func_021B86B8((void ***)p);
    q = (Q *)func_021B8714((char **)p);
    return func_021F73F0(mode, type, q, func_021B86C8((unsigned char **)p), h, (int)p, a, heap);
}

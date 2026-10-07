/*
 * file:     btlv_effvm_p91.c
 * unit:     yes
 * function: func_02203040, func_022030F0
 * address:  0x02203040
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
 *   d_0220A598     0x0220A598  data   a4
 *   func_02209A7C  0x02209A7C  thumb  ov094
 *   func_02209B60  0x02209B60  thumb  ov094
 *   func_02209C2C  0x02209C2C  thumb  ov094
 *   func_02206B30  0x02206B30  thumb  ov094
 *   sec_0220A380   0x0220A380  data
 *   d_0220A380     0x0220A380  data
 *   d_0220AE98     0x0220AE98  data
 *   d_0220AEA4     0x0220AEA4  data
 *   func_02021ED8  0x02021ED8  thumb
 *   func_020362DC  0x020362DC  arm
 *   func_021F8168  0x021F8168  thumb  ov094
 *   func_02021848  0x02021848  thumb
 *   func_02206B74  0x02206B74  thumb  ov094
 *   func_02204B0C  0x02204B0C  thumb  ov094
 *   func_02035C08  0x02035C08  arm
 *   func_021D6D54  0x021D6D54  thumb  ov093
 *   func_02206140  0x02206140  thumb  ov094
 *   func_0203630C  0x0203630C  arm
 *   func_02206BAC  0x02206BAC  thumb  ov094
 *   func_02206908  0x02206908  thumb  ov094
 *   func_02206B90  0x02206B90  thumb  ov094
 *   func_02206B58  0x02206B58  thumb  ov094
 *   func_02206578  0x02206578  thumb  ov094
 */
struct R5;
typedef unsigned short u16;

typedef struct Main_02203040 {
    unsigned char pad00[0x60];
    int f60;
    int f64;
    unsigned int f0b : 1;
    unsigned int st : 3;
    unsigned int pad4 : 11;
    unsigned int mode : 2;
    unsigned int pad17 : 6;
    unsigned int a : 4;
    unsigned int b : 4;
    unsigned int top : 1;
    unsigned char pad6C[0x240 - 0x6C];
    u16 h240;
} Main_02203040;

typedef struct Pair {
    int x;
    int y;
} Pair;

typedef struct Tbl {
    Pair p[3];
} Tbl;

typedef unsigned char u8;

typedef unsigned int u32;

typedef struct Main_022030F0 {
    void *owner;
    unsigned char pad04[0x58 - 4];
    int f58;
    unsigned char pad5c[0x64 - 0x5c];
    int f64;
    u32 b0 : 1;
    u32 lo : 4;
    u32 f5 : 4;
    u32 mid : 10;
    u32 mode : 2;
    u32 hi : 10;
    u32 b31 : 1;
    u32 f6c;
    int f70;
    unsigned char pad74[0x220 - 0x74];
    int f220;
    unsigned char pad224[0x242 - 0x224];
    u8 tbl[3][8];
    u8 b25a[8];
    u8 b262[4];
    unsigned char pad266[0x27c - 0x266];
    int f27c;
    unsigned char pad280[0x2a4 - 0x280];
    void *f2a4[3];
} Main_022030F0;

typedef struct Desc {
    void *a;
    void *b;
    const int *c;
} Desc;

/* The rodata objects at 0x0220A380..0x0220A3B4 are one section to the compiler: loads go
 * through the section base (sec_0220A380 + field) and addresses taken get their own words;
 * the 3-byte object at the section start is a second name at the same address. */
typedef struct Sec {
    u8 b0[3];
    u8 key[3];
    u8 pal[3][2];
    u8 mode[3][2];
    u16 h[5];
    Desc da;
    Desc db;
} Sec;

extern int func_02209A7C(int a, int b, int c);
extern int func_02209B60(int h, int x, int y, int k, int m, int n);
extern int func_02209C2C(int h);
extern void func_02206B30(char *p);
extern u32 func_02021ED8(const char *ptr);
extern u32 func_020362DC(void);
extern void func_021F8168(void);
extern void func_02021848(int a, int b, u16 c, int d, int e, int f, int g, void *h);
extern void func_02206B74(char *p);
extern void func_02204B0C(Main_022030F0 *m, int c);
extern int func_02035C08(const void *p);
extern int func_021D6D54(struct R5 *p);
extern int func_02206140(Main_022030F0 *m, const Desc *d, void *t, const u8 *k, int a, int b);
extern unsigned int func_0203630C(void);
extern void func_02206BAC(char *p);
extern int func_02206908(char *p, char *q, int i);
extern void func_02206B90(char *p);
extern void func_02206B58(char *p);
extern int func_02206578(char *s, int a, int b);
int func_02203040(Main_02203040 *m);
int func_022030F0(Main_022030F0 *m, u8 *key, int *out);
extern const Tbl d_0220A598;
extern const Sec sec_0220A380;
extern const u8 d_0220A380[3];
extern void *const d_0220AE98[];
extern void *const d_0220AEA4[];


int func_02203040(Main_02203040 *m)
{
    int r = 0;
    Tbl t;

    switch (m->a) {
    case 0:
        t = d_0220A598;
        if (m->f60 == 0)
            m->f60 = func_02209A7C(m->f64, 0xb, m->h240);
        if (func_02209B60(m->f60, t.p[m->b].x, t.p[m->b].y, 2, 7, 0x10) != 0) {
            m->a = m->a + 1;
            m->b = m->b + 1;
        }
        break;
    case 1:
        r = func_02209C2C(m->f60);
        if (r == 1)
            func_02206B30((char *)m);
        break;
    }
    return r;
}


int func_022030F0(Main_022030F0 *m, u8 *key, int *out)
{
    int i;
    int a;
    u32 held;
    int r;

    if (m->b0 || func_02021ED8((const char *)m->f64) != 0 || m->b31)
        return 0;
    if (func_020362DC() & 8)
        func_021F8168();
    if (m->f70 != -1) {
        i = m->f70 & 0xFFFF7FFF;
        if (i < 5) {
            if (i < 4 && m->f220 == 1)
                m->f70 = 7;
            *out = m->f70;
            *key = sec_0220A380.key[m->mode];
            m->f70 = -1;
            m->f6c &= ~2;
            func_02021848(m->f64, 2, 0x3e00, 0, 0, 0, 0, m->owner);
            func_02021848(m->f64, 8, 0x700, 0, 0, 0, 0, m->owner);
            return 1;
        }
        m->f5 = 0;
        m->tbl[m->f27c][m->f58] = 0;
        m->f6c &= ~2;
        func_02206B74((char *)m);
        func_02204B0C(m, i);
        m->f70 = -1;
        return 0;
    }
    if (m->f220 == 1) {
        a = func_02035C08(sec_0220A380.db.a);
        i = func_02206140(m, &sec_0220A380.db, d_0220AE98[m->mode], 0, a, func_021D6D54(m->f2a4[m->mode]));
    } else {
        a = func_02035C08(sec_0220A380.da.a);
        i = func_02206140(m, &sec_0220A380.da, d_0220AEA4[m->mode], d_0220A380, a, func_021D6D54(m->f2a4[m->mode]));
    }
    if (i != -1) {
        held = func_0203630C();
        if (m->b25a[i] == 0 && !(held & 0x200)) {
            if (m->b262[i] != 0)
                func_02206BAC((char *)m);
            i = -1;
        } else if (i > 4 && m->b25a[i] == 0) {
            i = -1;
        } else if (i < 4 && (held & 0x200) && (func_021D6D54(m->f2a4[m->mode]) == 1 || m->f220 == 1)) {
            i = -1;
        } else if (i < 4 && (held & 0x200) && m->b262[i] == 0) {
            i = -1;
        }
    }
    if (i != -1) {
        if (m->f220 == 1) {
            r = func_02206908((char *)m, (char *)(&sec_0220A380.db), i);
            if (r == 0 && !(m->f6c << 30 >> 31)) {
                m->tbl[m->f27c][m->f58] = i;
                func_02206B90((char *)m);
            } else if (r == 1 && !(m->f6c << 30 >> 31)) {
                func_02206B58((char *)m);
            }
            i = func_02206578((char *)m, i, sec_0220A380.db.c[i]);
        } else {
            r = func_02206908((char *)m, (char *)(&sec_0220A380.da), i);
            if (r == 0 && !(m->f6c << 30 >> 31)) {
                m->tbl[m->f27c][m->f58] = i;
                func_02206B90((char *)m);
            } else if (r == 1 && !(m->f6c << 30 >> 31)) {
                func_02206B58((char *)m);
            }
            i = func_02206578((char *)m, i, sec_0220A380.da.c[i]);
        }
    }
    if (i != -1)
        return 1;
    return 0;
}

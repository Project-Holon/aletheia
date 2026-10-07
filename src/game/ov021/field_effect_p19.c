/*
 * file:     field_effect_p19.c
 * unit:     yes
 * function: func_021AAAF0, func_021AAB1C
 * address:  0x021AAAF0
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
 *   func_02012A38  0x02012A38  thumb
 *   func_021ADB4C  0x021ADB4C  thumb
 *   func_021ADB5C  0x021ADB5C  thumb
 */
struct BigObj;
typedef unsigned char u8;

typedef unsigned short u16;

typedef struct {
    u8 pad[0x1d];
    u8 lo : 4;
    u8 mid : 2;
    u8 hi : 2;
} T;

typedef struct {
    char pad[0x5b4];
    int f5b4;
} D;

typedef struct {
    int pad[2];
    int f8;
    int fc;
    D *f10;
} S;

typedef unsigned int   u32;

extern unsigned int func_02012A38(const struct BigObj *p);
extern void func_021ADB4C(u32 a, int v);
extern void func_021ADB5C(int a, int b);
void func_021AAAF0(S *s, int b);
void func_021AAB1C(S *s, int b);


void func_021AAAF0(S *s, int b)
{
    T *t = (T *)func_02012A38((const struct BigObj *)s->f8);
    D *d = s->f10;
    if (t->lo && d->f5b4 != 0) {
        func_021ADB4C(d->f5b4, b);
    }
}


void func_021AAB1C(S *s, int b)
{
    T *t = (T *)func_02012A38((const struct BigObj *)s->f8);
    D *d = s->f10;
    if (t->lo && d->f5b4 != 0) {
        func_021ADB5C(d->f5b4, b);
    }
}

/*
 * file:     unit_02173658_p04.c
 * unit:     yes
 * function: func_02173A04, func_02173A2C, func_02173AB4
 * address:  0x02173A04
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
 *   func_021753D0 0x021753D0 thumb ov011
 *   func_021736D8  0x021736D8  thumb ov011
 *   func_02082BCC  0x02082BCC  arm
 *   func_020399A8  0x020399A8  arm
 *   func_0203D3F8  0x0203D3F8  arm
 *   func_021754E8 0x021754E8 thumb ov011
 */
struct Entry;
typedef unsigned char u8;

typedef unsigned int u32;

typedef struct Rec { u32 words[14]; } Rec;

typedef struct T {
    int w[13];
} T;

typedef struct B {
    unsigned char a;
    unsigned char b;
    short pad;
    T t;
} B;

int func_021753D0(u8 *p, int i, u8 v);
int func_021736D8(void);
void func_02082BCC(void *p, int v, int n);
struct Entry *func_020399A8(void);
u32 func_0203D3F8(u32 entry, u32 sendID, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);
void func_021754E8(u8 *p, int a, int b, int c);
void func_02173A04(int a, int b, Rec *c, u8 *d);
int func_02173A2C(unsigned char *p, int b, T *c, int d);
void func_02173AB4(int a, int b, u8 *c, u8 *d);


void func_02173A04(int a, int b, Rec *c, u8 *d)
{
    if (func_021753D0(d, a, ((u8 *)c)[1]) == 1) *(Rec *)(d + 0x11c) = *c;
}


int func_02173A2C(unsigned char *p, int b, T *c, int d)
{
    B buf;
    int r;

    if (func_021736D8() == 0) {
        return 0;
    }
    if (p[0x944] == 0) {
        p[0x944]++;
    }
    func_02082BCC(&buf, 0, 0x38);
    buf.a = d;
    buf.t = *c;
    buf.b = p[0x944];
    r = func_0203D3F8((int)func_020399A8(), (unsigned char)b, 0x207, 0x38, (u32)(&buf), 0, 0, 0);
    if (r == 1) {
        p[0x158] = p[0x944];
        p[0x159] = p[0x944];
    }
    return r;
}


void func_02173AB4(int a, int b, u8 *c, u8 *d)
{
    u8 v;
    v = c[1];
    if (v == d[0x159]) func_021754E8((u8 *)((int)d), a, c[0], v);
    else (d + a)[0x948] = v;
}

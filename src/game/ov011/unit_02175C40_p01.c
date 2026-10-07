/*
 * file:     unit_02175C40_p01.c
 * unit:     yes
 * function: func_02175C40, func_02175C58, func_02175C78, func_02175C88, func_02175CF4, func_02175D20, func_02175D34, func_02175D7C, func_02175DA8
 * address:  0x02175C40
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
 *   func_0203EFC8  0x0203EFC8  arm
 *   func_021756A4 0x021756A4 thumb ov011
 */
typedef unsigned char u8;

typedef struct { u8 pad[0x1a5]; u8 low:5; u8 value:2; u8 high:1; } Bits_02175C40;

typedef struct { u8 pad[0x1a5]; u8 low:5; u8 value:2; u8 high:1; } Bits_02175C58;

typedef unsigned int  u32;

typedef struct Rec_02175C88 {
    u32 w[13];
} Rec_02175C88;

typedef signed int     s32;

typedef struct Rec_02175D34 {
    u32 w[11];
    u8  f2c;
    u8  pad2d[7];
} Rec_02175D34;

typedef struct { u32 words[15]; } Rec_02175D7C;

typedef struct { u8 pad[0x1a5]; u8 flag:1; u8 rest:7; } Bits_02175D7C;

typedef struct { u8 pad[0x1a5]; u8 flag:1; u8 rest:7; } Bits_02175DA8;

typedef struct { u8 pad[0x2c]; u8 value; } Rec_02175DA8;

extern s32 func_0203EFC8(const u8 *a, const u8 *b, u32 n);
extern u8 func_021756A4(char *);
int func_02175C40(void *p);
void func_02175C58(void *p, int v);
int func_02175C78(u8 *p, void *b, int c);
int func_02175C88(u8 *a, Rec_02175C88 *b, int c);
int func_02175CF4(char *p, u8 *q);
void func_02175D20(u8 *p);
void func_02175D2C(u8 *p, u8 v);
void func_02175D34(void *unused, u8 *b);
void func_02175D7C(void *unused, u8 *p, Rec_02175D7C *q);
int func_02175DA8(u8 *p);

int func_02175C40(void *p)
{
    int v;
    v = ((Bits_02175C40 *)p)->value;
    func_02175C58(p, 0);
    return v;
}

void func_02175C58(void *p, int v)
{
    ((Bits_02175C58 *)p)->value = v;
}

int func_02175C78(u8 *p, void *b, int c)
{
    if (p[0xe0] == 4) return 0;
    return 3;
}


int func_02175C88(u8 *a, Rec_02175C88 *b, int c)
{
    Rec_02175C88 *dst;
    int r;

    dst = (Rec_02175C88 *)(a + 0xac);
    if (func_0203EFC8(a + 0x78, (const u8 *)b, 0x30) != 0) {
        (a + c)[0x197] = 2;
        return 0;
    }
    r = func_02175C78(a, b, c);
    if (r == 3) {
        (a + c)[0x197] = 2;
        return 0;
    }
    *dst = *b;
    ((u8 *)dst + r)[0x34] = c;
    (a + c)[0x197] = 1;
    a[0x19b] = 1;
    return 1;
}

/*
 * extent: Two alignment bytes at 02175D1E before D20.
 * note: Outer non-one guard returns the original byte, including values beyond boolean.
 */
int func_02175CF4(char *p, u8 *q)
{
    int v;
    v = q[0x1a4];
    if (v == 1) {
        if (func_02175DA8(q) == 1 && func_021756A4(p) == 1) return 1;
        return 0;
    }
    return v;
}

/*
 * extent: store-return follower at 02175D2C, claimed by root for this unit.
 */
void func_02175D20(u8 *p)
{
    p[0x1a4] = 0;
}

void func_02175D2C(u8 *p, u8 v)
{
    p[0x1a4] = v;
}


void func_02175D34(void *unused, u8 *b)
{
    Rec_02175D34 *src;
    Rec_02175D34 *dst;

    src = (Rec_02175D34 *)(b + 0x78);
    dst = (Rec_02175D34 *)(b + 0xac);
    if (src->f2c != 4 && dst->f2c == 4) {
        *dst = *src;
        ((u8 *)dst)[0x37] = 1;
        b[0x19b] = 1;
        b[0x19c] = 0;
    }
}

void func_02175D7C(void *unused, u8 *p, Rec_02175D7C *q)
{
    *(Rec_02175D7C *)(p + 0xac) = *q;
    ((Bits_02175D7C *)p)->flag = 1;
}

int func_02175DA8(u8 *p)
{
    Rec_02175DA8 *r;
    r = (Rec_02175DA8 *)(p + 0xac);
    if (((Bits_02175DA8 *)p)->flag == 1 && r->value != 4) return 1;
    return 0;
}

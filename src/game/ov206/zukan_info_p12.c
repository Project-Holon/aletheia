/*
 * file:     zukan_info_p12.c
 * unit:     yes
 * function: func_021BC008, func_021BC0AC, func_021BC0B0, func_021BC0B4, func_021BC0B8, func_021BC0CC, func_021BC0E0
 * address:  0x021BC008
 * region:   ov206
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02045808 0x02045808 arm
 *   func_0201AE14 0x0201AE14 thumb
 *   func_02045C04 0x02045C04 arm
 *   func_02049238 0x02049238 arm
 */
struct Rec;
struct U16Vec;
typedef unsigned char u8;

typedef struct S {
    char pad0[0x1b8];
    void *g[3];
    void *w[7];
    void *objs[35];
    void *x;
    void *a[16];
} S;

typedef unsigned int   u32;

typedef signed char s8;

typedef unsigned short u16;

typedef signed short s16;

typedef signed int s32;

extern void func_02045808(struct U16Vec *vec);
extern void func_0201AE14(void *);
extern u32 func_02045C04(struct Rec *rec);
extern void func_02049238(void *);
void func_021BC008(S *p);
u32 func_021BC0AC(void);
int func_021BC0B0(int v);
int func_021BC0B4(int a0);
int func_021BC0B8(int v);
int func_021BC0CC(int v);
u32 func_021BC0E0(void);

void func_021BC008(S *p)
{
    u8 i;
    for (i = 0; i < 16; i++)
        func_02045808(p->a[i]);
    if (p->x != 0)
        func_0201AE14(p->x);
    for (i = 0; i < 35; i++) {
        switch (i) {
        case 1:
            if (p->g[0] == 0)
                func_02045C04(p->objs[i]);
            break;
        case 2:
            if (p->g[1] == 0)
                func_02045C04(p->objs[i]);
            break;
        case 3:
            if (p->g[2] == 0)
                func_02045C04(p->objs[i]);
            break;
        default:
            func_02045C04(p->objs[i]);
            break;
        }
    }
    for (i = 0; i < 7; i++)
        func_02049238(p->w[i]);
}

u32 func_021BC0AC(void)
{
    return 0xa7;
}

int func_021BC0B0(int v)
{
    return v + 5;
}

int func_021BC0B4(int a0)
{
    return 0;
}


int func_021BC0B8(int v)
{
    if (v <= 0x1ED)
        return 2;
    else
        return 4;
}


int func_021BC0CC(int v)
{
    if (v <= 0x1ED)
        return 1;
    else
        return 3;
}

u32 func_021BC0E0(void)
{
    return 0xe9;
}

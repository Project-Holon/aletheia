/*
 * file:     field_msgbg_p19.c
 * unit:     yes
 * function: func_0218C1A4, func_0218C1C4, func_0218C23C, func_0218C290, func_0218C2E4, func_0218C350, func_0218C388
 * address:  0x0218C1A4
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
 *   func_02047910  0x02047910  arm
 *   func_020478B8  0x020478B8  arm
 *   func_0204784C  0x0204784C  arm
 *   func_0218BCAC  0x0218BCAC  thumb  ov021
 *   func_020477A4  0x020477A4  arm
 *   func_02047804  0x02047804  arm
 *   func_02047790  0x02047790  arm
 *   func_02047674  0x02047674  arm
 *   func_020477D4  0x020477D4  arm
 */
struct AnmCtl;
struct G3dSys;
struct Owner;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed int     s32;

typedef struct {
    int h;
    int f4;
    int arr[4];
} S;

int func_02047910(void *a, int idx, int amount);
extern int func_020478B8(void *a, int idx, int amount);
extern u32 func_0204784C(struct AnmCtl *c, u16 idx, s32 *frame);
extern u8 *func_0218BCAC(u8 *p);
extern u32 func_020477A4(struct G3dSys *sys, u32 idx);
extern u32 func_02047804(struct AnmCtl *c, u16 idx);
extern int func_02047790(int *p, int i);
extern int func_02047674(int p);
int func_020477D4(struct Owner *owner, u32 index);
void func_0218C1A4(int unused, int *s);
void func_0218C1C4(u32 unused, u32 *st);
void func_0218C23C(u32 *st, int n);
void func_0218C290(u32 *st, int n);
void func_0218C2E4(u32 *st, int n);
void func_0218C350(u32 *st, int n);
void func_0218C388(S *p);


void func_0218C1A4(int unused, int *s)
{
    int i;
    for (i = 0; i < 4; i++)
        func_02047910((void *)(*s), (unsigned short)i, 0x1000);
}


/*
 * Per-slot state machine step over four slots.
 *
 * Addresses are Black-image addresses.
 */
void func_0218C1C4(u32 unused, u32 *st)
{
    int i;

    for (i = 0; i < 4; i++) {
        switch (st[2 + i]) {
        case 0:
        case 2:
            break;
        case 3:
            if (func_020478B8((void *)st[0], (u16)i, 0x1000) == 0)
                st[2 + i] = 2;
            break;
        case 4:
            if (func_020478B8((void *)st[0], (u16)i, -0x1000) == 0) {
                func_0204784C((struct AnmCtl *)st[0], (u16)i, 0);
                st[2 + i] = 2;
            }
            break;
        case 1:
            func_02047910((void *)st[0], (u16)i, 0x1000);
            break;
        }
    }
}


/*
 * Starts a group of slots and marks them state 3.
 *
 * Addresses are Black-image addresses.
 */
void func_0218C23C(u32 *st, int n)
{
    u8 *q = func_0218BCAC(*(u8 **)st[1]);
    int base = q[2] * n;
    int i;

    for (i = 0; i < q[2]; i++) {
        func_020477A4((struct G3dSys *)st[0], (u16)(base + i));
        func_02047804((struct AnmCtl *)st[0], base + i);
        (st + base)[2 + i] = 3;
    }
}


/*
 * Starts a group of slots and marks them state 1.
 *
 * Addresses are Black-image addresses.
 */
void func_0218C290(u32 *st, int n)
{
    u8 *q = func_0218BCAC(*(u8 **)st[1]);
    int base = q[2] * n;
    int i;

    for (i = 0; i < q[2]; i++) {
        func_020477A4((struct G3dSys *)st[0], (u16)(base + i));
        func_02047804((struct AnmCtl *)st[0], base + i);
        (st + base)[2 + i] = 1;
    }
}


/*
 * Starts a group of slots, sets a parameter, marks them state 4.
 *
 * Addresses are Black-image addresses.
 */
void func_0218C2E4(u32 *st, int n)
{
    u8 *q = func_0218BCAC(*(u8 **)st[1]);
    int base = q[2] * n;
    int i;
    int v;

    for (i = 0; i < q[2]; i++) {
        func_020477A4((struct G3dSys *)st[0], (u16)(base + i));
        v = *(u16 *)(*(u8 **)(func_02047674((int)func_02047790((int *)st[0], (u16)(base + i))) + 8) + 4) << 12;
        func_0204784C((struct AnmCtl *)st[0], base + i, &v);
        (st + base)[2 + i] = 4;
    }
}


void func_0218C350(u32 *st, int n)
{
    u8 *q = func_0218BCAC(*(u8 **)st[1]);
    int base = q[2] * n;
    int i;

    for (i = 0; i < q[2]; i++) {
        if ((st + base)[2 + i] != 0)
            (st + base)[2 + i] = 2;
    }
}


void func_0218C388(S *p)
{
    int i;
    for (i = 0; i < 4; i++) {
        if (p->arr[i] != 0) {
            func_020477D4((struct Owner *)p->h, (unsigned short)i);
            p->arr[i] = 0;
        }
    }
}

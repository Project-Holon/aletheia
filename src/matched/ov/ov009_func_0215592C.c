/*
 * function: func_0215592C
 * address:  0x0215592C
 * packet:   pkt_ov009_0215592C
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021A8264     0x021A8264  data  ov009  a4
 *   func_02155B68  0x02155B68  thumb  ov009
 *   func_021554C8  0x021554C8  thumb  ov009
 *   func_02155374  0x02155374  thumb  ov009
 *   func_0216B65C  0x0216B65C  arm
 *   func_02155904  0x02155904  thumb  ov009
 *   func_0203D798  0x0203D798  arm
 *   func_02156344  0x02156344  thumb  ov009
 *   func_02155F58  0x02155F58  thumb  ov009
 *   func_021561C0  0x021561C0  thumb  ov009
 */
#include "../include/Obj18649.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    char pad[0x32c];
    u8 kind[0x754 - 0x32c];  /* 0x32c */
    int state;          /* 0x754 */
    int err;            /* 0x758 */
    int mode;           /* 0x75c */
    int f760;           /* 0x760 */
    char pad1[0x76c - 0x764];
    int f76c;           /* 0x76c */
    int idx;            /* 0x770 */
    int f774;           /* 0x774 */
    char pad2[0x782 - 0x778];
    short s782;         /* 0x782 */
    char pad3[0x794 - 0x784];
    u16 h794;           /* 0x794 */
} G;

extern G *d_021A8264;
void func_02155B68(void);
int func_021554C8(void);
void func_02155374(int);
int func_0216B65C(void);
void func_02155904(void);
void *func_0203D798(void);
void func_02156344(u16);
int func_02155F58(void);
int func_021561C0(void);

static inline int SetErr(int e)
{
    d_021A8264->err = e;
    return e;
}

int func_0215592C(int a)
{
    func_02155B68();
    switch (d_021A8264->state) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
        return func_021554C8();
    case 7:
        if (a != 0)
            func_02155374(8);
        if (d_021A8264->mode == 2 && d_021A8264->idx >= 0
            && d_021A8264->kind[d_021A8264->idx] != 6)
            func_02155374(12);
        break;
    case 8:
    case 12:
        func_0216B65C();
        func_02155904();
        break;
    case 9: {
        u8 *p = func_0203D798();
        if (d_021A8264->s782 != 0)
            func_02156344(((struct Obj18649 *)p)->f56);
        d_021A8264->h794 = 0;
        func_02155374(10);
        return SetErr(1000);
    }
    case 11:
        func_02155374(6);
        d_021A8264->f760 = 0;
        d_021A8264->f774 = -1;
        return SetErr(0x3e9);
    case 13:
        func_02155374(6);
        d_021A8264->f760 = 0;
        d_021A8264->f774 = -1;
        return SetErr(0x3ea);
    case 14:
        return func_02155F58();
    case 18:
        if (d_021A8264->f76c == 0) {
            func_0216B65C();
            func_02155374(0x13);
            break;
        }
    case 6: {
        int r = func_021561C0();
        if (r == 0)
            return SetErr(0x3ef);
        return r;
    }
    }
    return func_021561C0();
}

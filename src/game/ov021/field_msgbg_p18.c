/*
 * file:     field_msgbg_p18.c
 * unit:     yes
 * function: func_0218C08C, func_0218C0D8
 * address:  0x0218C08C
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
 *   func_020477A4  0x020477A4  arm
 *   func_02047804  0x02047804  arm
 *   func_0218BCAC  0x0218BCAC  thumb  ov021
 *   func_0218BD24  0x0218BD24  thumb  ov021
 *   func_0204779C  0x0204779C  arm
 *   func_02047790  0x02047790  arm
 *   func_0204762C  0x0204762C  arm
 *   func_02047788  0x02047788  arm
 *   func_02047738  0x02047738  arm
 *   func_02047504  0x02047504  arm
 */
struct G3dSys;
struct AnmCtl;
struct Rec;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

extern u32 func_020477A4(struct G3dSys *sys, u32 idx);
extern u32 func_02047804(struct AnmCtl *c, u16 idx);
extern u8 *func_0218BCAC(u8 *p);
extern u8 func_0218BD24(u8 *p);
extern int func_0204779C(int *p);
extern int func_02047790(int *p, int i);
extern void func_0204762C(struct Rec *p);
extern int func_02047788(int *p);
extern void func_02047738(struct Rec *p);
extern void func_02047504(struct Rec *p);
void func_0218C08C(u8 *a, void **b);
void func_0218C0D8(void **s);


void func_0218C08C(u8 *a, void **b)
{
    int i;
    u32 m;

    func_0218BCAC(*(void **)b[1]);
    m = func_0218BD24(a + 8);
    for (i = 0; i < 4; i++) {
        if (i != m) {
            b[2 + i] = 0;
        } else {
            func_020477A4(b[0], (u16)i);
            func_02047804(b[0], i);
            b[2 + i] = (void *)1;
        }
    }
}


void func_0218C0D8(void **s)
{
    int n;
    int i;
    void *r;

    if (s[0] != 0) {
        n = func_0204779C(s[0]);
        for (i = 0; i < n; i++) {
            void *o = (void *)func_02047790(s[0], (u16)i);
            if (o != 0)
                func_0204762C(o);
        }
        r = (void *)func_02047788(s[0]);
        func_02047738(s[0]);
        s[0] = 0;
        s[1] = 0;
        func_02047504(r);
    }
}

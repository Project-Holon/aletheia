/*
 * file:     fldmmdl_blact_p33.c
 * unit:     yes
 * function: func_0219EF44, func_0219EF6C, func_0219EF7C
 * address:  0x0219EF44
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
 *   func_02030734  0x02030734  arm
 *   func_0219EF14  0x0219EF14  thumb  ov021
 *   d_021DDE08     0x021DDE08  data
 *   func_0219EFFC  0x0219EFFC  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 *   func_0204A298  0x0204A298  arm
 *   func_0209C2B0  0x0209C2B0  arm
 */
typedef unsigned char  u8;

typedef unsigned short u16;

typedef signed short   s16;

typedef unsigned int   u32;

typedef signed int     s32;

struct S {
    u32 *f0;
    u32 f4;
    u16 h8;
    u16 hA;
    u16 hC;
    u16 hE;
    u8  pad10[8];
    u32 f18;
    u32 f1c;
    u32 f20;
    u32 f24;
    u8  pad28[12];
    u32 f34;
};

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_0219EF14(u8 *p);
extern int func_0219EFFC(u32 a);
extern u32 func_020307B0(void *p);
extern int func_0204A298(int a0, int a1, int a2, int a3, u32 *out);
extern u32 func_0209C2B0(u32, u32);
u8 *func_0219EF44(u32 heap);
void func_0219EF6C(u8 *p);
void func_0219EF7C(struct S *p, u32 b, u32 c);
extern char d_021DDE08[];


/*
 * Addresses are Black-image addresses.
 */
u8 *func_0219EF44(u32 heap)
{
    u8 *p = (u8 *)func_02030734((u16)heap, 0x38, 1, d_021DDE08, 0xC0);
    func_0219EF14(p + 8);
    return p;
}


/*
 * Pattern-generated from the ov021 family.
 *
 * Addresses are Black-image addresses.
 */
void func_0219EF6C(u8 *p)
{
    func_0219EFFC((u32)p);
    func_020307B0(p);
}


void func_0219EF7C(struct S *p, u32 b, u32 c)
{
    u32 loc;
    p->f0 = (u32 *)func_0204A298(0x4f, b, 0, (u16)c, &loc);
    p->f4 = loc;
    p->f18 = (u32)p->f0 + p->f0[2];
    p->h8 = func_0209C2B0(p->f0[3] - p->f0[2], 0x70);
    p->f1c = (u32)p->f0 + p->f0[3];
    p->hA = func_0209C2B0(p->f0[4] - p->f0[3], 0x48);
    p->f20 = (u32)p->f0 + p->f0[4];
    p->hC = func_0209C2B0(p->f0[5] - p->f0[4], 0x24);
    p->f24 = (u32)p->f0 + p->f0[5];
    p->hE = func_0209C2B0(p->f0[6] - p->f0[5], 0x24);
    p->f34 = *(u32 *)((u8 *)p->f0 + p->f0[1]);
}

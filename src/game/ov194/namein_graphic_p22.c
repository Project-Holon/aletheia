/*
 * file:     namein_graphic_p22.c
 * unit:     yes
 * function: func_021F4D14, func_021F4D20, func_021F4D34, func_021F4D3C, func_021F4D78, func_021F4D94, func_021F4D9C, func_021F4DA0, func_021F4DA4
 * address:  0x021F4D14
 * region:   ov194
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021F5798 0x021F5798 data a4
 *   func_020307B0  0x020307B0  arm  ov194
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed short   s16;

typedef signed char    s8;

extern void func_0204A648(void);
extern int func_0204A1BC(int a0, int a1, int a2, int a3);
extern u32 func_020307B0(void *p);
extern void *func_02030734(u32, u32, int, const char *, u16);
extern void func_02082BCC(void *, u32, u32);
void func_021F4D14(u8 *a0);
u32 func_021F4D1C(const u32 *p);
int func_021F4D20(u32 a, u32 b);
void func_021F4D34(void *p);
u32 *func_021F4D3C(u32 heap);
void func_021F4D78(u8 *p);
u32 func_021F4D94(const u8 *p, u32 i);
u16 func_021F4D9C(const u16 *p);
u16 func_021F4DA0(const u16 *p);
u32 func_021F4DA4(u8 *p, u16 a, u16 b);
extern const char d_021F5798[];

void func_021F4D14(u8 *a0) { func_0204A648(); }

/*
 * extent: lead tail-call stub followed by unlabelled load-and-return at 021F4D1C.
 */
u32 func_021F4D1C(const u32 *p) { return *p; }


/*
 * Addresses are Black-image addresses.
 */
int func_021F4D20(u32 a, u32 b)
{
    return func_0204A1BC(0x77, a, 0, b);
}

void func_021F4D34(void *p) { func_020307B0(p); }

/*
 * evidence: caller consumes 021F4D20 r0; full forwarder leaves 0204A1BC allocation result live despite own void declaration.
 */
u32 *func_021F4D3C(u32 heap)
{
    u32 *p;
    int i = 0;
    p = func_02030734(heap, 20, 0, d_021F5798, 147);
    func_02082BCC(p, 0, 20);
    for (; i < 5; i++)
        p[i] = func_021F4D20(i, heap);
    return p;
}


void func_021F4D78(u8 *p)
{
    int i;

    for (i = 0; i < 5; i++) {
        func_021F4D34((void *)(*(u32 *)(p + i * 4)));
    }
    func_020307B0(p);
}

u32 func_021F4D94(const u8 *p, u32 i) { return *(const u32 *)(p + i * 4); }

u16 func_021F4D9C(const u16 *p) { return *p; }

u16 func_021F4DA0(const u16 *p) { return p[1]; }


u32 func_021F4DA4(u8 *p, u16 a, u16 b)
{
    return *(u16 *)(p + ((a + b * func_021F4D9C((const u16 *)p)) << 1) + 4);
}

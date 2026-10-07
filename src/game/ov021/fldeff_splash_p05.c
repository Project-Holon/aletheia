/*
 * file:     fldeff_splash_p05.c
 * unit:     yes
 * function: func_021C4B50, func_021C4B64
 * address:  0x021C4B50
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
 *   func_021C4BC4  0x021C4BC4  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 *   func_021ABE18  0x021ABE18  thumb  ov021
 *   func_021ABE24  0x021ABE24  thumb  ov021
 *   func_021C6AE0  0x021C6AE0  thumb  ov021
 *   func_021C6AF0  0x021C6AF0  thumb  ov021
 *   func_021C6AF8  0x021C6AF8  thumb  ov021
 *   func_021C6AFC  0x021C6AFC  thumb  ov021
 *   func_021C6574  0x021C6574  thumb  ov021
 *   func_021C6590  0x021C6590  thumb  ov021
 *   func_021C67D8  0x021C67D8  thumb  ov021
 */
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed int     s32;

typedef struct P { u32 f0; u16 h4; u16 h6; } P;

extern void func_021C4BC4(void *p);
extern u32 func_020307B0(void *p);
extern u32 func_021ABE18(unsigned char *p);
extern u32 func_021ABE24(u8 *p);
extern void func_021C6AE0(u32 a);
extern int func_021C6AF0(u32 a, u32 b, u32 c);
extern void func_021C6AF8(u32 *a, u32 b);
extern void func_021C6AFC(u32 *a, u32 b);
extern int func_021C6574(u32 a, u32 b, u32 c);
extern u16 func_021C6590(u32 a, u32 b, u32 c, u32 d);
extern void func_021C67D8(u32 a, u32 b, u32 c);
void func_021C4B50(u32 a, u8 *p);
void func_021C4B64(P *p);


/*
 * Pattern-generated from the ov021 family.
 *
 * Addresses are Black-image addresses.
 */
void func_021C4B50(u32 a, u8 *p)
{
    func_021C4BC4(p);
    func_020307B0(p);
}


void func_021C4B64(P *p)
{
    u32 buf[9];
    u32 x = func_021ABE18((unsigned char *)p->f0);
    u32 y = func_021ABE24((u8 *)p->f0);

    func_021C6AE0((u32)buf);
    func_021C6AF0((u32)buf, y, 0x5f);
    func_021C6AF8(buf, y);
    func_021C6AFC(buf, 0x6a);
    p->h4 = func_021C6574(x, (u32)buf, 0);
    p->h6 = func_021C6590(x, p->h4, 0, 0);
    func_021C67D8(x, p->h6, 1);
}

/*
 * file:     fldeff_namipoke_p06.c
 * unit:     yes
 * function: func_021AD3D4, func_021AD3FC, func_021AD410
 * address:  0x021AD3D4
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
 *   d_021DE080  0x021DE080  data
 *   func_021AD530  0x021AD530  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 *   func_021ABE18  0x021ABE18  thumb  ov021
 *   func_021ABE24  0x021ABE24  thumb  ov021
 *   func_021C6AE0  0x021C6AE0  thumb  ov021
 *   func_021C6AF0  0x021C6AF0  thumb  ov021
 *   func_021C6AF8  0x021C6AF8  thumb  ov021
 *   func_021C6AFC  0x021C6AFC  thumb  ov021
 *   func_021C6574  0x021C6574  thumb  ov021
 */
struct X;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

typedef struct P { u32 f0; } P;

typedef signed int     s32;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_021AD530(struct X *x);
extern u32 func_020307B0(void *p);
extern u32 func_021ABE18(u8 *p);
extern u32 func_021ABE24(u8 *p);
extern void func_021C6AE0(u32 *a);
extern int func_021C6AF0(u32 a, u32 b, u32 c);
extern void func_021C6AF8(u32 *p, u32 v);
extern void func_021C6AFC(u32 a, u32 b);
extern int func_021C6574(u32 a, u32 b, u32 c);
P *func_021AD3D4(u32 a, int heap);
void func_021AD3FC(u32 a, u8 *p);
void func_021AD410(u32 *a);
extern char d_021DE080[];


P *func_021AD3D4(u32 a, int heap)
{
    P *p;

    p = (P *)func_02030734(heap, 0x10, 1, d_021DE080, 0x3cf);
    p->f0 = a;
    func_021AD410((u32 *)p);
    return p;
}


/*
 * Pattern-generated from the ov021 family.
 *
 * Addresses are Black-image addresses.
 */
void func_021AD3FC(u32 a, u8 *p)
{
    func_021AD530((struct X *)p);
    func_020307B0(p);
}


/*
 * Addresses are Black-image addresses.
 *
 * The buffer handle p is assigned after the func_021ABE24 call, but the
 * first func_021C6AE0 call takes the buffer itself, so a call lies between
 * the assignment and the first read of p. That keeps p a register variable
 * (r7) instead of a rematerialised address, and the repeated 0 argument is
 * rebuilt per call. See docs/idioms/a-call-between-a-buffer-handle-and-its-first-read-keeps-it-in-a-register.md.
 */
void func_021AD410(u32 *a)
{
    u32 buf[9];
    u16 *h = (u16 *)a;
    u32 r6;
    u32 r4;
    u32 p;
    r6 = func_021ABE18((u8 *)a[0]);
    r4 = func_021ABE24((u8 *)a[0]);
    p = (u32)buf;
    func_021C6AE0(buf);
    func_021C6AF0(p, r4, 0x37);
    func_021C6AF8((u32 *)p, r4);
    func_021C6AFC(p, 0x80);
    func_021C6AFC(p, 0x6c);
    h[2] = func_021C6574(r6, p, 0);
    func_021C6AE0(buf);
    func_021C6AF0(p, r4, 0x3a);
    func_021C6AF8((u32 *)p, r4);
    func_021C6AFC(p, 0x6f);
    func_021C6AFC(p, 0x63);
    h[3] = func_021C6574(r6, p, 0);
    func_021C6AE0(buf);
    func_021C6AF0(p, r4, 0x39);
    func_021C6AF8((u32 *)p, r4);
    func_021C6AFC(p, 0x6e);
    func_021C6AFC(p, 0x62);
    h[5] = func_021C6574(r6, p, 0);
    func_021C6AE0(buf);
    func_021C6AF0(p, r4, 0x3b);
    func_021C6AF8((u32 *)p, r4);
    func_021C6AFC(p, 0x70);
    func_021C6AFC(p, 0x64);
    h[4] = func_021C6574(r6, p, 0);
    func_021C6AE0(buf);
    func_021C6AF0(p, r4, 0x38);
    func_021C6AF8((u32 *)p, r4);
    func_021C6AFC(p, 0x6d);
    func_021C6AFC(p, 0x61);
    h[6] = func_021C6574(r6, p, 0);
}

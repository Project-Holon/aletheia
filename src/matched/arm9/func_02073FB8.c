/*
 * function: func_02073FB8
 * address:  0x02073FB8
 * packet:   pkt_020737C0
 * status:   EXACT
 * isa:      arm
 * compiler: ../2.0/sp2
 * symbols:
 *   ptr_0214EA50   0x0214EA50  data
 *   func_020788D8  0x020788D8  arm
 *   func_020788AC  0x020788AC  arm
 *   func_020789A4  0x020789A4  arm
 *   func_02074048  0x02074048  arm
 *
 * The archive open path.  The second parameter is the archive's path string
 * (the only caller, GFL_USE_InitSound, loads 0x020A7010 into r1) and it is
 * forwarded untouched to func_020788D8(&c->f7c, path), which moves r1 into r0
 * for its own lookup.  Keeping r1 live across the four zero stores is what
 * parks the zero in ip; the earlier DIFF (docs/notes/pkt_02073F3C.c.txt) had
 * func_020788D8 as one-argument and the path as dead.
 */
typedef unsigned char u8;
typedef unsigned int  u32;

struct Pair { u32 a; u32 b; };

struct Ctx {
    u8  pad00[0x30];
    u32 f30;
    u8  f34[0x48];
    struct Pair f7c;
    u8  pad84[4];
    u32 f88;
    u32 f8c;
    u32 f90;
    u32 f94;
};

extern struct Ctx *ptr_0214EA50;
extern u32  func_020788D8(struct Pair *p, const char *path);
extern void func_020788AC(void *p);
extern u32  func_020789A4(void *p, struct Pair v);
extern u32  func_02074048(struct Ctx *c, u32 a, u32 b);

u32 func_02073FB8(struct Ctx *c, const char *path, u32 a, u32 b)
{
    c->f90 = 0;
    c->f88 = 0;
    c->f8c = 0;
    c->f94 = 0;
    if (func_020788D8(&c->f7c, path) == 0) return 0;
    func_020788AC(c->f34);
    if (func_020789A4(c->f34, c->f7c) == 0) return 0;
    c->f30 = 1;
    if (func_02074048(c, a, b) == 0) return 0;
    ptr_0214EA50 = c;
    return 1;
}

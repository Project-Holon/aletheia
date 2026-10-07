/*
 * file:     union_comm_p02.c
 * unit:     yes
 * function: func_02172C4C, func_02172C78, func_02172C98
 * address:  0x02172C4C
 * region:   ov012
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02172BC0 0x02172BC0 thumb ov012
 *   func_0203CBAC 0x0203CBAC arm
 *   d_02175380 0x02175380 data ov012 a4
 *   func_0203D0FC 0x0203D0FC arm
 *   func_0203D8C4  0x0203D8C4  arm
 */
struct Req;
typedef unsigned char u8;

typedef unsigned int u32;

typedef struct Work { u8 b[0x3570]; } Work;

extern Work *func_02172BC0(u32 a);
extern void func_0203CBAC(struct Req *req, u32 a2, u32 a3);
extern void func_0203D0FC(int a);
extern void func_0203D8C4(u32 a);
Work *func_02172C4C(void *unused, u32 a);
int func_02172C78(void *a, void *b, u8 *p);
void func_02172C98(u8 *p);
extern char d_02175380[];

Work *func_02172C4C(void *unused, u32 a) { Work *p; p = func_02172BC0(a); p->b[0x3560] = 1; func_0203CBAC((struct Req *)d_02175380, (u32)func_02172C98, (u32)p); return p; }

/*
 * extent: existing matched follower ov012_func_02172C98.c
 */
int func_02172C78(void *a, void *b, u8 *p) { if (p[0x3560] >= 2) { p[0x3560] = 3; func_0203D0FC(0); return 1; } return 0; }


/*
 * note:     unlabelled callback leaf (a .word run in the listing); passed as
 *           a function pointer (pool words 0x02172C74 and 0x02172E44).
 */
void func_02172C98(u8 *p)
{
    p[0x3560] = 2;
    func_0203D8C4(0);
}

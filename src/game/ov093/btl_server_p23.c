/*
 * file:     btl_server_p23.c
 * unit:     yes
 * function: func_021BD1D0, func_021BD1E0, func_021BD200
 * address:  0x021BD1D0
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021BCA08   0x021BCA08  thumb
 *   func_021BD264  0x021BD264  thumb  ov093
 *   func_021BD274  0x021BD274  thumb  ov093
 *   func_021BD284  0x021BD284  thumb  ov093
 *   func_021BD294  0x021BD294  thumb  ov093
 *   func_021BD2A4  0x021BD2A4  thumb  ov093
 *   func_021D5440  0x021D5440  thumb  ov093
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

struct Unk021BD1E0 {
    u16 f0;
    u8 f2;
    u8 f3;
    u8 f4;
    u8 b0 : 1;
    u8 b1 : 1;
    u8 rest : 6;
};

struct Unk021BD200 {
    u16 f0;
    u8 f2;
    u8 f3;
    u8 f4;
    u8 b0 : 1;
    u8 b1 : 1;
    u8 rest : 6;
};

extern u8 *func_021BCA08(u8 *p, u8 x);
extern u8 func_021D5440(u8 *p);
extern int func_021BD264(int t);
extern u8 func_021BD274(u8 *p, u8 x);
extern int func_021BD284(int t);
extern u8 *func_021BD294(int t, int k);
extern u8 func_021BD2A4(u8 *p, u8 x);
/* 021BD1D0 guard on a callee's pointer result, then set a byte */ void func_021BD1D0(u8 *p, u8 n);
void func_021BD1E0(struct Unk021BD1E0 *p);
void func_021BD200(struct Unk021BD200 *p, u8 *q, u8 *a, int t);


/* 021BD1D0  guard on a callee's pointer result, then set a byte */
/*
 * Leaf with no calls and no pool; 7 instructions, 16 bytes: push {r3, lr}; bl func_021BCA08; cmp r0, #0; beq loc_021BD1DE; movs r1, #1; strb r1, [r0, #0xd]; pop {r3, pc}.
 */
void func_021BD1D0(u8 *p, u8 n)
{
    u8 *e = func_021BCA08(p, n);
    if (e != 0)
        e[0xd] = 1;
}


void func_021BD1E0(struct Unk021BD1E0 *p)
{
    p->f0 = 0;
    p->f2 = 6;
    p->f3 = 6;
    p->f4 = 0;
    p->b0 = 0;
    p->b1 = 0;
}


void func_021BD200(struct Unk021BD200 *p, u8 *q, u8 *a, int t)
{
    int r = func_021BD264(t);
    p->f2 = func_021BD274(q + 0x1ab8, func_021D5440(a));
    p->f3 = 6;
    p->b0 = 0;
    p->b1 = 0;
    if (r == 1 && func_021BD284(t)) {
        p->f3 = func_021BD2A4(q + 0x1ab8, func_021D5440(func_021BD294(t, 0)));
    }
}

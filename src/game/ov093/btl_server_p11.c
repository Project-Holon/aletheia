/*
 * file:     btl_server_p11.c
 * unit:     yes
 * function: func_021BD148, func_021BD170, func_021BD1B0, func_021BD1D0, func_021BD1E0, func_021BD200
 * address:  0x021BD148
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
 *   func_021BCA08 0x021BCA08 thumb ov093
 *   func_021BCB98 0x021BCB98 thumb ov093
 *   func_021BCAAC  0x021BCAAC  thumb  ov093
 *   func_021BCC50 0x021BCC50 thumb ov093
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

typedef struct { u32 a, b, c; u8 d0, flag; u16 pad; } E;

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

typedef struct { u8 *a; u32 b, c, d; } E_021BC8EC;

typedef struct { u8 pad[0x782]; u8 n; u8 pad2[0x5d]; E_021BC8EC e[4]; } S_021BC874;

extern E_021BC8EC *func_021BCA08(S_021BC874 *p, u8 x);
typedef struct { u32 a; u32 b, c; u8 d0; u8 flag; u16 pad; } E_021BCB68;

typedef struct { u8 pad[0x782]; u8 n; u8 pad2[0x5d]; E_021BCB68 e[6]; E_021BCB68 t; } S_021BCB98;

extern int func_021BCB98(S_021BCB98 *p, E_021BCB68 *cur, int start);
extern u8 *func_021BCAAC(u8 *p, u8 *q, u8 i);
extern void func_021BCC50(S_021BCB98 *p, E_021BCB68 *cur);
extern u8 func_021D5440(u8 *p);
extern int func_021BD264(int t);
extern u8 func_021BD274(u8 *p, u8 x);
extern int func_021BD284(int t);
extern u8 *func_021BD294(int t, int k);
extern u8 func_021BD2A4(u8 *p, u8 x);
int func_021BD148(void *p, u8 x);
int func_021BD170(u8 *p, u8 *q);
int func_021BD1B0(void *p, u8 x);
void func_021BD1D0(u8 *p, u8 n);
void func_021BD1E0(struct Unk021BD1E0 *p);
void func_021BD200(struct Unk021BD200 *p, u8 *q, u8 *a, int t);


int func_021BD148(void *p, u8 x)
{
    E *e = (E *)func_021BCA08((S_021BC874 *)p, x);
    if (e && e->flag == 0) {
        if (func_021BCB98((S_021BCB98 *)p, (E_021BCB68 *)e, 0) >= 0) return 1;
    }
    return 0;
}




int func_021BD170(u8 *p, u8 *q)
{
    int i = 0;
    int r;
    u8 *x = func_021BCAAC(p, q, 0);
    r = 0;
    while (x) {
        i = func_021BCB98((S_021BCB98 *)p, (E_021BCB68 *)((E *)x), i);
        if (i < 0) break;
        i++;
        x = func_021BCAAC(p, q, i);
        r = 1;
    }
    return r;
}



int func_021BD1B0(void *p, u8 x)
{
    E *e = (E *)func_021BCA08((S_021BC874 *)p, x);
    if (e && e->flag == 0) {
        func_021BCC50((S_021BCB98 *)p, (E_021BCB68 *)e);
        return 1;
    }
    return 0;
}



/* 021BD1D0  guard on a callee's pointer result, then set a byte */
/*
 * Leaf with no calls and no pool; 7 instructions, 16 bytes: push {r3, lr}; bl func_021BCA08; cmp r0, #0; beq loc_021BD1DE; movs r1, #1; strb r1, [r0, #0xd]; pop {r3, pc}.
 */
void func_021BD1D0(u8 *p, u8 n)
{
    u8 *e = (u8 *)(E *)func_021BCA08((S_021BC874 *)p, n);
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

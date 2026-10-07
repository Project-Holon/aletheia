/*
 * file:     fldmmdl_blact_p31.c
 * unit:     yes
 * function: func_0219EBF4, func_0219ED7C, func_0219ED8C
 * address:  0x0219EBF4
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
 *   func_0216D69C  0x0216D69C  thumb  ov010
 *   func_0216DA50  0x0216DA50  thumb  ov010
 *   func_0216DA7C  0x0216DA7C  thumb  ov010
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_02197E7C  0x02197E7C  thumb  ov021
 *   func_0216D438  0x0216D438  thumb  ov010
 *   func_02197EDC  0x02197EDC  thumb  ov021
 *   func_0219EA10  0x0219EA10  thumb  ov021
 *   func_0219EA24  0x0219EA24  thumb  ov021
 *   func_0216D60C  0x0216D60C  thumb  ov010
 *   func_0219E418  0x0219E418  thumb  ov021
 *   func_0219E2F4  0x0219E2F4  thumb  ov021
 *   func_0219E664  0x0219E664  thumb  ov021
 *   func_0219E9A8  0x0219E9A8  thumb  ov021
 *   func_0216DA44  0x0216DA44  thumb  ov010
 *   func_0219EA78  0x0219EA78  thumb  ov021
 *   d_021D84AC     0x021D84AC  data  ov021  a4
 *   func_0219EA94  0x0219EA94  thumb  ov021
 *   func_0219E968  0x0219E968  thumb  ov021
 *   func_0216D674  0x0216D674  thumb  ov010
 */
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed char    s8;

typedef signed int     s32;

typedef struct {
    u8  pad[0xc];
    u8  state : 4;
    u8  hi : 4;
    s8  cnt;
    s8  e;
    u8  f;
} E;

typedef signed short   s16;

typedef struct {
    u16 f0;
    u16 f2;
    s16 f4;
    u16 f6;
} Pos;

extern void *func_0216D69C(void *p);
extern void func_0216DA50(u8 *p);
extern void func_0216DA7C(u8 *p);
extern u16 func_0216D5F8(void *p);
extern int func_02197E7C(int a, int b);
extern void func_0216D438(char *a0, int a1);
extern u32 func_02197EDC(u8 *p);
extern int func_0219EA10(u32 *a, int b);
extern u32 func_0219EA24(u32, u32);
extern void func_0216D60C(u32, u16);
extern int func_0219E418(u32, u16);
extern void func_0219E2F4(void *o, void *out);
extern int func_0219E664(void *o, u32 k, void *buf);
extern int func_0219E9A8(u32, u32, s32, u16 *);
extern void func_0216DA44(u32);
extern int func_0219EA78(E *, u32);
extern u32 func_0219EA94(u32 a, u32 *b);
extern void *func_0219E968(u32 a, u32 size);
extern void func_0216D674(void *p, u16 v);
int func_0219EBF4(u32 o);
int func_0219ED7C(u32 *a);
void func_0219ED8C(u32 a);
extern u8 d_021D84AC[];


/*
 * Addresses are Black-image addresses.
 */
int func_0219EBF4(u32 o)
{
    E *e;
    u32 k;
    u16 a[4];
    u16 b[4];

    e = func_0216D69C((void *)o);
    switch (e->state) {
    case 0:
        func_0216DA50((u8 *)o);
        func_0216DA7C((u8 *)o);
        func_0216D438((char *)o, (u16)((u32)func_02197E7C((u16)((u32)func_0216D5F8((void *)o)), (u32)0)));
        e->state++;
        break;
    case 1:
        if (!func_02197EDC((u8 *)o)) {
            break;
        }
        e->cnt = func_0219EA10((u32 *)d_021D84AC, -1);
        e->state++;
    case 2:
        e->cnt--;
        if (e->cnt != 0) {
            break;
        }
        e->state++;
    case 3:
        k = func_0219EA24(e->hi, 9);
        func_0216D60C(o, k);
        if (func_0219E418(o, k)) {
            e->state = 0;
            break;
        }
        func_0219E2F4((void *)o, a);
        func_0219E664((void *)o, (u16)k, b);
        if (a[0] != b[0]) {
            e->state = 0;
            break;
        }
        if (func_0219E9A8(o, e->f, e->e, b)) {
            e->state = 0;
            break;
        }
        func_0216D438((char *)o, (u16)((u32)func_02197E7C((u16)k, (u32)0xc)));
        func_0216DA44(o);
        e->state++;
    case 4:
        if (func_02197EDC((u8 *)o)) {
            func_0216DA50((u8 *)o);
            e->state = 0;
        }
        break;
    }
    return func_0219EA78(e, o);
}


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_0219ED7C(u32 *a)
{
return func_0219EA94((u32)func_0216D69C((void *)a), a);
}


void func_0219ED8C(u32 a)
{
    u8 *q = func_0219E968(a, 16);
    Pos pos;
    func_0219E2F4((void *)a, &pos);
    q[0xc] = 0;
    q[0xd] = 0;
    q[0xf] = pos.f6;
    q[0xe] = pos.f4;
    func_0216D674((void *)a, 0);
    func_0216DA50((u8 *)a);
}

/*
 * file:     btl_rec_p06.c
 * unit:     yes
 * function: func_021EEAFC, func_021EEB00, func_021EEB2C, func_021EEB64, func_021EEB70, func_021EEB84
 * address:  0x021EEAFC
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
 *   func_02082D44  0x02082D44  arm
 *   func_021EEBA4  0x021EEBA4  thumb  ov093
 *   func_021D4C58  0x021D4C58  thumb  ov093
 *   func_021D4B58  0x021D4B58  thumb  ov093
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

typedef struct {
    u8 pad00[4];
    u32 w4;
    u32 w8;
    u8 st : 4;
    u8 hi : 4;
    u8 f0d;
    u8 mode;
    u8 f0f;
    u16 h10;
    u16 h12;
    u8 d[1];
} W;

/* 021EEB64  cmp r1,#0; beq; ldr r2,[r0,#8]; str r2,[r1]; ldr r0,[r0,#4] */
struct QW { u8 pad[4]; u32 a; u32 b; };

extern void func_02082D44(const void *, void *, int);
extern int func_021EEBA4(W *);
extern void func_021D4C58(u32 a);
extern u32 func_021D4B58(u32 a, u32 b, u32 c);
void func_021EEAFC(void);
void func_021EEB00(W *p, u16 a, const void *src, u16 n);
int func_021EEB2C(W *p);
u32 func_021EEB64(struct QW *p, u32 *out);
void func_021EEB70(W *p);
u32 func_021EEB84(W *p);


/*
 * empty function: bx lr
 */
void func_021EEAFC(void)
{
}


void func_021EEB00(W *p, u16 a, const void *src, u16 n)
{
    p->mode = 1;
    p->f0f = a;
    p->h10 = a;
    p->h12 = n;
    func_02082D44(src, p->d, n);
    p->w4 = 0;
    p->w8 = 0;
    p->st = 0;
}


int func_021EEB2C(W *p)
{
    switch (p->mode) {
    case 1:
        if (func_021EEB84(p) == 0)
            break;
        p->mode = 3;
    case 3:
        if (func_021EEBA4(p) == 0)
            break;
        p->mode = 4;
    case 4:
        return 1;
    }
    return 0;
}

/*
 * Leaf with no calls and no pool; 6 instructions, 12 bytes: cmp r1, #0; beq loc_021EEB6C; ldr r2, [r0, #8]; str r2, [r1]; ldr r0, [r0, #4]; bx lr.
 */
u32 func_021EEB64(struct QW *p, u32 *out)
{
    if (out != 0)
        *out = p->b;
    return p->a;
}


void func_021EEB70(W *p)
{
    p->mode = 0;
    if (p->hi != 0)
        func_021D4C58(p->hi);
}


u32 func_021EEB84(W *p)
{
    u16 *q;

    if (p->hi != 0) {
        q = &p->h10;
        return func_021D4B58(p->f0d, (u32)q, q[1] + 4);
    }
    return 1;
}

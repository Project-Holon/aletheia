/*
 * file:     btl_rec_p05.c
 * unit:     yes
 * function: func_021EE8D8, func_021EE8F4, func_021EE96C, func_021EE9A4, func_021EE9B4, func_021EE9E4, func_021EEA30, func_021EEA54, func_021EEA58, func_021EEAD0, func_021EEAE0, func_021EEAE8
 * address:  0x021EE8D8
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
 *   d_021F6388  0x021F6388  data  a4
 *   d_021F6384  0x021F6384  data  a4
 *   sub_02030734   0x02030734  arm
 *   d_021F3AE8     0x021F3AE8  data  ov093  a4
 *   func_020307B0   0x020307B0  arm arm9
 *   func_021D4C58   0x021D4C58  thumb
 */
typedef unsigned char u8;

typedef unsigned int u32;

typedef unsigned short u16;

typedef struct {
    u8 len;
    u8 mask;
    u8 cnt;
    u8 x : 6;
    u8 f : 1;
    u8 g : 1;
    u8 d[60];
} B;

typedef struct {
    u32 f00;
    u8 pad[8];
    u8 lo : 4;
    u8 hi : 4;
    u8 idx;
    u8 e;
    u8 f;
} Obj;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

extern void func_02082D44(const void *src, void *dst, int n);
extern void *sub_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *p);
u8 *func_021EE8D8(u8 *p, u32 *out, int flag);
void func_021EE8F4(u8 *p, u8 idx, const void *src, u32 n);
u8 *func_021EE96C(B *p, u8 b, u32 *out);
u8 *func_021EE9A4(u8 *p, u32 *out);
void func_021EE9B4(B *p, const void *src, int n);
int func_021EE9E4(u8 *p, u32 *pos, u8 *a, u8 *b, u32 *dst);
void func_021EEA30(int v);
void func_021EEA54(void);
Obj *func_021EEA58(u32 a, int idx, u32 v, u32 heap);
/* 021EEAD0 clear the low nibble of byte +0xc and zero bytes +0xe/+0xf */ void func_021EEAD0(u8 *p);
void func_021EEAE0(void *p);
/* 021EEAE8 call through a global pointer when it is set */ void func_021EEAE8(void);
extern void *d_021F6388[];
extern int d_021F6384;
extern const char d_021F3AE8[];


u8 *func_021EE8D8(u8 *p, u32 *out, int flag)
{
    p[4] = 4;
    p[5] = 0x20 | (((u8)flag & 1) << 7);
    *out = 2;
    return p + 4;
}


void func_021EE8F4(u8 *p, u8 idx, const void *src, u32 n)
{
    u8 m;
    int len;
    u32 end;

    if (p[0] == 0) {
        p[3] = (p[3] & ~0x3f) | 1;
        p[0] = 2;
    }
    m = p[1];
    if (!(m & (1 << idx))) {
        len = n * 4;
        end = p[0] + (len + 1);
        if (end <= 0x3c) {
            p[1] = m | (u8)(1 << idx);
            p[2]++;
            (p + p[0])[4] = (idx << 5) | n;
            func_02082D44(src, p + 4 + (p[0] + 1), len);
            p[0] = end;
        } else {
            p[3] |= 0x80;
        }
    }
}


u8 *func_021EE96C(B *p, u8 b, u32 *out)
{
    u8 type;

    if (p->g == 0) {
        p->d[0] = b;
        type = p->x;
        p->d[1] = 0;
        p->d[1] = ((p->f & 1) << 7) | ((type & 7) << 4) | (p->cnt & 0xf);
        *out = p->len;
        return p->d;
    }
    return 0;
}


u8 *func_021EE9A4(u8 *p, u32 *out)
{
    p[4] = 0;
    p[5] = 0x30;
    *out = 2;
    return p + 4;
}


void func_021EE9B4(B *p, const void *src, int n)
{
    func_02082D44(src, p->d, n);
    p->len = n;
    p->mask = 0;
    p->cnt = 0;
    p->x = 0;
    p->f = 0;
    p->g = 0;
}


int func_021EE9E4(u8 *p, u32 *pos, u8 *a, u8 *b, u32 *dst)
{
    u8 h;
    int len;

    if (*pos == 0) {
        *pos = 2;
    }
    if (*pos < p[0]) {
        h = (p + *pos)[4];
        *a = (h >> 5) & 7;
        *b = h & 0x1f;
        len = *b * 4;
        *pos = *pos + 1;
        func_02082D44(p + 4 + *pos, dst, len);
        *pos = *pos + len;
        return 1;
    }
    return 0;
}


void func_021EEA30(int v)
{
    int i;

    for (i = 0; i < 4; i++)
        d_021F6388[i] = 0;
    d_021F6384 = v;
}

void func_021EEA54(void) { }


Obj *func_021EEA58(u32 a, int idx, u32 v, u32 heap)
{
    Obj *o;

    o = 0;
    if (d_021F6388[idx] == 0) {
        o = sub_02030734(heap, 0xbd0, 1, d_021F3AE8, 0x7e);
        o->f00 = a;
        o->idx = idx;
        o->hi = (u8)v;
        o->e = 0;
        o->f = 0;
        o->lo = 0;
    }
    if (d_021F6384 == 0) {
        if (d_021F6388[idx] == 0)
            d_021F6388[idx] = o;
        return d_021F6388[idx];
    }
    d_021F6388[idx] = o;
    return o;
}


/* 021EEAD0  clear the low nibble of byte +0xc and zero bytes +0xe/+0xf */
/*
 * Leaf with no calls and no pool; 8 instructions, 16 bytes: ldrb r2, [r0, #0xc]; movs r1, #0; strb r1, [r0, #0xe]; strb r1, [r0, #0xf]; movs r1, #0xf; bics r2, r1; strb r2, [r0, #0xc]; bx lr.
 */
void func_021EEAD0(u8 *p)
{
    u8 v = p[0xc];

    p[0xe] = 0;
    p[0xf] = 0;
    p[0xc] = v & ~0xf;
}


/*
 * tail-call thunk to func_020307B0
 */
void func_021EEAE0(void *p)
{
    func_020307B0(p);
}


/* 021EEAE8  call through a global pointer when it is set */
/*
 * 7 instructions, 16 bytes: push {r3, lr}; ldr r0, pool_021EEAF8; ldr r0, [r0]; cmp r0, #0; beq loc_021EEAF6; bl func_021D4C58; pop {r3, pc}.
 */
void func_021EEAE8(void)
{
    u32 g = *(u32 *)0x021F6384;
    if (g != 0)
        func_021D4C58(g);
}

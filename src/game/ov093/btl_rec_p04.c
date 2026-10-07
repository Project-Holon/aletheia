/*
 * file:     btl_rec_p04.c
 * unit:     yes
 * function: func_021EE544, func_021EE5E4, func_021EE600, func_021EE608, func_021EE638, func_021EE63C, func_021EE644, func_021EE674, func_021EE688, func_021EE6B8, func_021EE830, func_021EE894, func_021EE8B4
 * address:  0x021EE544
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
 *   func_02045758  0x02045758  arm
 *   func_02045760  0x02045760  arm
 *   func_02045738  0x02045738  arm
 *   func_02045740  0x02045740  arm
 *   func_02045730  0x02045730  arm
 *   func_02041300  0x02041300  arm
 *   func_020409B4  0x020409B4  arm
 *   func_020061E4  0x020061E4  thumb
 *   func_02040618  0x02040618  arm
 *   func_02030734  0x02030734  arm
 *   d_021F3ADC  0x021F3ADC  data  a4
 *   func_020307B0   0x020307B0  arm arm9
 *   func_02082D44  0x02082D44  arm
 *   func_021D8470  0x021D8470  thumb
 *   func_021D845C  0x021D845C  thumb
 *   func_02082BCC  0x02082BCC  arm
 */
#include "../../matched/include/Obj07866.h"

struct Descriptor;
typedef unsigned char u8;

typedef unsigned int u32;

struct C {
    u8 pad00[0x8];
    void *f08;
};

typedef unsigned short u16;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

typedef struct {
    u32 a;
    u32 n : 31;
    u32 flag : 1;
    u32 w[4];
} Q_021EE644;

typedef struct {
    u32 a;
    u32 flag : 1;
    u32 n : 31;
    u32 w[4];
} Q_021EE674;

typedef struct {
    u8 *buf;
    u32 n : 31;
    u32 flag : 1;
    u32 pos[4];
} Q_021EE688;

typedef struct {
    u8 *data;          /* 0x00 */
    u32 len : 31;      /* 0x04 */
    u32 err : 1;
    u32 pos[4];        /* 0x08 */
    u32 buf[4][16];    /* 0x18 */
} Reader;

typedef struct {
    u8 *buf;
    u32 n : 31;
    u32 flag : 1;
    u32 pos[4];
} Q_021EE830;

typedef struct {
    u8 *buf;
    u32 n : 31;
    u32 flag : 1;
    u32 pos[4];
} Q_021EE894;

typedef struct {
    u8 len;
    u8 mask;
    u8 cnt;
    u8 x : 6;
    u8 f : 1;
    u8 g : 1;
    u8 d[60];
} B;

extern u8 func_02045730(struct Descriptor *p);
extern u8 func_02045738(struct Descriptor *p);
extern u8 func_02045740(struct Descriptor *p);
extern u8 func_02045758(struct Descriptor *p);
extern u8 func_02045760(struct Descriptor *p);
extern void func_020409B4(u32 index);
extern void func_02041300(u32 index, u32 a1, u32 a2, u32 a3, u8 a4, u8 a5, u8 a6);
extern void func_020061E4(u32 a);
extern void func_02040618(u32 layer, u32 a, u32 b);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *p);
extern void func_02082D44(const void *, void *, u32);
void func_021D8470(u32 *p);
void func_021D845C(u32 *p);
extern void func_02082BCC(void *, int, int);
int func_021EE544(int *st, struct C *c);
void *func_021EE5E4(u32 heap);
void func_021EE600(void *p);
void func_021EE608(u8 *p, const u8 *src, int n);
/* 021EE638 ldrb r0,[r0] */ u8 func_021EE638(u8 *p);
unsigned short *func_021EE63C(unsigned short *a, unsigned int *b);
void func_021EE644(Q_021EE644 *q, u32 a, u32 n);
void func_021EE674(Q_021EE674 *q);
int func_021EE688(Q_021EE688 *q, int i);
u32 *func_021EE6B8(Reader *r, u32 idx, u8 *outLen, u8 *outFlag);
int func_021EE830(Q_021EE830 *q);
int func_021EE894(Q_021EE894 *q, int i);
void func_021EE8B4(B *p, int b);
extern char d_021F3ADC[];


int func_021EE544(int *st, struct C *c)
{
    int a;
    int b;
    int e;
    int f;
    u8 id;

    switch (*st) {
    case 0:
        a = func_02045758(c->f08) - 1;
        b = func_02045760(c->f08) - 1;
        e = func_02045738(c->f08) + 2;
        f = func_02045740(c->f08) + 2;
        id = func_02045730(c->f08);
        func_02041300(id, 0, (u8)a, (u8)b, (u8)e, (u8)f, 0);
        func_020409B4(id);
        func_020061E4(0x547);
        (*st)++;
        break;
    case 1:
        func_02040618(3, 0, -0x90);
        func_02040618(3, 3, 0);
        (*st)++;
        break;
    case 2:
        return 1;
    }
    return 0;
}


void *func_021EE5E4(u32 heap)
{
    return func_02030734(heap, 0xC08, 1, d_021F3ADC, 0x6b);
}


/*
 * tail-call thunk to func_020307B0
 */
void func_021EE600(void *p)
{
    func_020307B0(p);
}


void func_021EE608(u8 *p, const u8 *src, int n)
{
    u32 pos;
    u32 end;

    if (p[2] == 0) {
        pos = ((struct Obj07866 *)p)->f0;
        n = n - 1;
        end = pos + n;
        if (end <= 0xC00) {
            func_02082D44(src + 1, p + 8 + pos, n);
            ((struct Obj07866 *)p)->f0 = end;
        } else {
            p[2] = 1;
        }
    }
}


/* 021EE638  ldrb r0,[r0] */
/*
 * Reads the u8 field at offset 0 of the argument and returns it.
 */
u8 func_021EE638(u8 *p) { return *p; }

unsigned short *func_021EE63C(unsigned short *a, unsigned int *b)
{
    *b = *a;
    return a + 4;
}


void func_021EE644(Q_021EE644 *q, u32 a, u32 n)
{
    u32 i;

    q->a = a;
    q->n = n;
    q->flag = 0;
    for (i = 0; i < 4; i++)
        q->w[i] = 0;
}


void func_021EE674(Q_021EE674 *q)
{
    u32 i;

    for (i = 0; i < 4; i++)
        q->w[i] = 0;
}


/*
 * Stream-record head decoder (Q: buf, n:31+flag:1, pos[4]). Reads the byte
 * at stream i; if its kind field ((v >> 4) & 7) is 2, advances the stream
 * and returns bit 7. The int return type and the reuse of v for the bit
 * fix the order: kind cannot be forwarded past the redefinition of v, and
 * the u8 cast lands at the assignment, not at the return.
 */
int func_021EE688(Q_021EE688 *q, int i)
{
    int v;
    int kind;

    v = q->buf[q->pos[i]];
    kind = (v >> 4) & 7;
    v = (u8)((v >> 7) & 1);
    if (kind == 2) {
        q->pos[i]++;
        return v;
    }
    return 0;
}


/*
 * Reads the next record for channel idx from a packed byte stream. Header byte:
 * bits 0-3 count, bits 4-6 type, bit 7 flag. Type 1 carries count sub-records
 * (bits 0-4 size in words, bits 5-7 channel); the one for idx is copied into
 * buf[idx]. Type 2 is a skip, type 3 resets buf[idx]. Any error sets err.
 * The final bounds check reads len and pos into separate locals: that keeps
 * the len shift pair ahead of the pos load.
 */
u32 *func_021EE6B8(Reader *r, u32 idx, u8 *outLen, u8 *outFlag)
{
    u32 *pos;
    u32 p0;
    if (r->err) {
        func_021D8470(r->buf[idx]);
        *outLen = 1;
        *outFlag = 0;
        return r->buf[idx];
    }
    pos = r->pos;
    while ((p0 = pos[idx]) < r->len) {
        u8 b = r->data[p0];
        u8 count = b & 0xF;
        int type = (b >> 4) & 7;
        *outFlag = (b >> 7) & 1;
        pos[idx]++;
        if (pos[idx] > r->len)
            break;
        if (type == 1) {
            u32 *res = 0;
            u32 i;
            if (count == 0 || count > 4)
                break;
            for (i = 0; i < count; i++) {
                u32 p = pos[idx]++;
                u8 *dd = r->data;
                u8 c = dd[p];
                u8 id = (c >> 5) & 7;
                u8 sz = c & 0x1F;
                if (pos[idx] >= r->len)
                    break;
                if (id != idx) {
                    pos[idx] += sz * 4;
                } else {
                    func_02082D44(dd + pos[idx], r->buf[idx], sz * 4);
                    res = r->buf[idx];
                    pos[idx] += sz * 4;
                    *outLen = sz;
                }
            }
            if (res)
                return res;
        } else if (type == 3) {
            u32 *res = r->buf[idx];
            func_021D845C(res);
            *outLen = 1;
            *outFlag = 0;
            return res;
        } else if (type != 2) {
            break;
        }
        {
            u32 len = r->len;
            u32 p = pos[idx];
            if (p >= len)
                break;
        }
    }
    r->err = 1;
    func_021D8470(r->buf[idx]);
    *outLen = 1;
    *outFlag = 0;
    return r->buf[idx];
}


/*
 * Counts the bit7-flagged records in a stream (Q: buf, n:31+flag:1).
 * The buffer is read through q->buf in the loop (the compiler hoists it),
 * the bound is a local, and the locals are declared count first and
 * pos/size last; these set the register colours. pos++ sits right after
 * the byte load.
 */
int func_021EE830(Q_021EE830 *q)
{
    int count;
    u8 v;
    u8 n;
    int kind;
    u8 bit;
    u32 j;
    u8 len;
    u32 pos;
    u32 size;

    pos = 0;
    count = 0;
    size = q->n;
    if (size != 0) {
        do {
            v = q->buf[pos];
            pos++;
            n = v & 0xf;
            kind = (v >> 4) & 7;
            bit = (v >> 7) & 1;
            if (bit != 0)
                count++;
            if (pos >= size)
                break;
            if (kind != 1) {
                pos += n;
            } else {
                for (j = 0; j < n; j++) {
                    len = q->buf[pos] & 0x1f;
                    pos = pos + 1 + len * 4;
                    if (pos >= size)
                        break;
                }
            }
        } while (pos < size);
    }
    return count;
}


int func_021EE894(Q_021EE894 *q, int i)
{
    u32 p;

    if (q->flag == 0) {
        p = q->pos[i];
        if (p == q->n)
            return 1;
        return 0;
    }
    return 1;
}


void func_021EE8B4(B *p, int b)
{
    func_02082BCC(p, 0, 0x40);
    p->f = (u8)b;
}

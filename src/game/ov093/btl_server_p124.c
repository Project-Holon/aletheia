/*
 * file:     btl_server_p124.c
 * unit:     yes
 * function: func_021CC8C8, func_021CC8D8, func_021CC918, func_021CC95C, func_021CC960, func_021CC96C, func_021CC974, func_021CC99C, func_021CC9A4, func_021CC9AC, func_021CCA74, func_021CCAA8, func_021CCAD4, func_021CCAE0, func_021CCB18
 * address:  0x021CC8C8
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
 *   func_02082BCC 0x02082BCC arm
 *   d_021EFE9C     0x021EFE9C  data  a4
 *   data_021F3A84 0x021F3A84 data
 *   func_02034714 0x02034714 arm
 */
#include "../../matched/include/Obj21130.h"
#include "../../matched/include/Obj18356.h"
#include "../../matched/include/Obj01891.h"

typedef unsigned int u32;

typedef unsigned char u8;

typedef unsigned short u16;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

struct Lock {
    u32 a : 10;
    u32 b : 9;
    u32 c : 9;
    u32 d : 1;
    u32 e : 1;
    u32 f : 1;
    u32 g : 1;
};

typedef struct {
    u32 a : 10;
    u32 b : 9;
    u32 c : 9;
    u32 d : 1;
    u32 e : 1;
    u32 f : 1;
    u32 g : 1;
} Bf;

struct S {
    unsigned int x : 10;
};

/* 021CC96C  ldr r0,[r0]; lsls #1; lsrs #0x1f */
struct Q9 { u32 a : 30; u32 b : 1; u32 c : 1; };

typedef struct { unsigned low:28, a:1, b:1, c:1, d:1; } Word;

/* 021CC99C  ldr r0,[r0]; lsls #3; lsrs #0x1f */
struct Q10 { u32 a : 28; u32 b : 1; u32 c : 3; };

struct SizeEntry {
    u8 id;
    u8 size;
};

struct Rec {
    u32 id : 8;
    u32 b : 5;
    u32 size : 10;
    u32 x : 1;
    u32 pad : 2;
    u32 y : 1;
    u32 rest : 5;
};

struct Pack {
    u32 lo : 10;
    u32 off : 9;
    u32 rest : 13;
    u8 data[500];
};

typedef struct { unsigned low:10, size:9, high:13; } A;

typedef struct { unsigned low:13, size:10, high:9; } B;

typedef struct { u32 wpos,rpos; u8 buf[3000]; } Buf_021CCAA8;

typedef struct { u32 wpos,rpos; u8 buf[3000]; } Buf_021CCAE0;

typedef struct {
    u32 wpos;
    u32 rpos;
    u8 buf[3000];
} Buf_021CCB18;

extern void func_02082BCC(void *, int, u32);
extern void func_02034714(const char *expr, u32 line, const char *file);
void func_021CC8C8(u32 *p);
struct Lock func_021CC8D8(struct Lock *p, int line);
u32 func_021CC918(Bf *p, u32 v);
/* 021CC95C str r1,[r0] */ void func_021CC95C(u32 *p, u32 v, int line);
unsigned short func_021CC960(struct S *p);
int func_021CC96C(struct Q9 *p);
void func_021CC974(Word *p,int flag);
int func_021CC99C(struct Q10 *p);
u32 func_021CC9A4(u32 *p);
struct Rec *func_021CC9AC(struct Pack *p, int id, int b);
void func_021CCA74(A *p,B *q);
void func_021CCAA8(Buf_021CCAA8 *p,int v);
/* 021CCAD4 ldr r2,[r0,#4]; adds r1,r2,#1; str r1,[r0,#4]; adds r0,r0,r2; * ldrb r0,[r0,#8] */ u8 func_021CCAD4(u8 *p);
void func_021CCAE0(Buf_021CCAE0 *p,int v);
u32 func_021CCB18(Buf_021CCB18 *p);
extern struct SizeEntry d_021EFE9C[0x3B];
extern char data_021F3A84[];

void func_021CC8C8(u32 *p) { *p++=0; func_02082BCC(p,0,500); }

struct Lock func_021CC8D8(struct Lock *p, int line)
{
    struct Lock old = *p;
    p->a = 0;
    p->c = p->b;
    p->e = 0;
    p->d = 0;
    p->f = 0;
    return old;
}


u32 func_021CC918(Bf *p, u32 v)
{
    u32 old = ((struct Obj21130 *)p)->f0;
    p->a = v;
    p->c = p->b;
    p->e = 0;
    p->d = 0;
    p->f = 0;
    return old;
}


/* 021CC95C  str r1,[r0] */
/*
 * Stores the second argument (a u32) into the field at offset 0.
 */
void func_021CC95C(u32 *p, u32 v, int line) { *p = v; }


unsigned short func_021CC960(struct S *p)
{
    return p->x;
}

/*
 * Leaf with no calls and no pool; 4 instructions, 8 bytes: ldr r0, [r0]; lsls r0, r0, #1; lsrs r0, r0, #0x1f; bx lr.
 */
int func_021CC96C(struct Q9 *p) { return p->b; }

void func_021CC974(Word *p,int flag) { if(flag) {p->a=1;p->b=1;} else p->a=0; p->c=1; }

/*
 * Leaf with no calls and no pool; 4 instructions, 8 bytes: ldr r0, [r0]; lsls r0, r0, #3; lsrs r0, r0, #0x1f; bx lr.
 */
int func_021CC99C(struct Q10 *p) { return p->b; }


u32 func_021CC9A4(u32 *p)
{
    return (((struct Obj18356 *)p)->f0 << 2) >> 31;
}


struct Rec *func_021CC9AC(struct Pack *p, int id, int b)
{
    u32 i;
    u32 size;
    u32 off;
    u32 j;
    struct Rec *rec;

    i = 0;
    size = 0;
    for (; i < 0x3B; i++) {
        if (id == d_021EFE9C[i].id) {
            size = d_021EFE9C[i].size;
            break;
        }
    }
    if (size != 0) {
        while (size & 3) {
            size++;
        }
        off = p->off;
        if (off + size <= 500) {
            rec = (struct Rec *)(p->data + off);
            for (j = 0; j < size; j++) {
                p->data[p->off + j] = 0;
            }
            rec->id = id;
            rec->size = size;
            rec->b = b;
            rec->x = 0;
            rec->y = 1;
            p->off = p->off + size;
            return rec;
        }
    }
    return 0;
}

void func_021CCA74(A *p,B *q) { unsigned a,b,t; a=p->size;b=q->size;if(b<=a) {t=(u32)q-((u32)p+4);t+=b;if(t==a) p->size=a-b;} }

void func_021CCAA8(Buf_021CCAA8 *p,int v) {if(p->wpos>=3000)func_02034714(data_021F3A84,0,data_021F3A84);p->buf[p->wpos++]=v;}


/* 021CCAD4  ldr r2,[r0,#4]; adds r1,r2,#1; str r1,[r0,#4]; adds r0,r0,r2;
 *           ldrb r0,[r0,#8] */
/*
 * Leaf with no calls and no pool; 6 instructions, 12 bytes: ldr r2, [r0, #4]; adds r1, r2, #1; str r1, [r0, #4]; adds r0, r0, r2; ldrb r0, [r0, #8]; bx lr.
 */
u8 func_021CCAD4(u8 *p)
{
    u32 off = ((struct Obj01891 *)p)->f4;
    ((struct Obj01891 *)p)->f4 = off + 1;
    return *(u8 *)(p + off + 8);
}

void func_021CCAE0(Buf_021CCAE0 *p,int v) {if(p->wpos>=2999)func_02034714(data_021F3A84,0,data_021F3A84);p->buf[p->wpos++]=v>>8;p->buf[p->wpos++]=v;}


/*
 * lever: Once-300 permuter expands the byte-source local and binds rpos
 *        separately before the two loads; retain unsigned full-word cursor.
 *        The signed 32-bit temporary preserves its input bits; convert back
 *        to u32 before every modular address sum, then cast the final address.
 */
u32 func_021CCB18(Buf_021CCB18 *p)
{
    const u8 *q;
    u16 v;
    int tmp;
    tmp = p->rpos;
    q = (const u8 *)((u32)p + p->rpos);
    v = (*(const u8 *)((u32)p + (u32)tmp + 8) << 8) |
        *(const u8 *)((u32)p + p->rpos + 9);
    p->rpos += 2;
    return v;
}

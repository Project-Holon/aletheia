/*
 * file:     btl_server_p13.c
 * unit:     yes
 * function: func_021BB840, func_021BB848, func_021BB85C, func_021BB878, func_021BB890, func_021BB8A8, func_021BB8B0, func_021BB8BC, func_021BB8DC, func_021BB908, func_021BB914, func_021BB920, func_021BB930, func_021BB964, func_021BB968
 * address:  0x021BB840
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
 *   func_021B9B94 0x021B9B94 thumb ov093
 *   func_021BB830 0x021BB830 thumb ov093
 *   func_021D5844 0x021D5844 thumb ov093
 *   func_02017E1C 0x02017E1C thumb
 *   func_02027268 0x02027268 thumb
 *   func_020271DC 0x020271DC thumb
 *   func_021BA1B4 0x021BA1B4 thumb ov093
 *   func_021B91E4  0x021B91E4  thumb  ov093
 *   func_021B9234  0x021B9234  thumb  ov093
 *   func_02030734 0x02030734 arm
 *   func_0201B70C 0x0201B70C thumb
 *   func_021BB9D8 0x021BB9D8 thumb ov093
 *   d_021F3A70 0x021F3A70 data a4
 */
#include "../../matched/include/Obj09956.h"
#include "../../matched/include/Obj13294.h"
#include "../../matched/include/Obj13295.h"

struct Q1;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

/* 021BB840  strb r1,[r0,#0xb]; str r2,[r0]; strb r3,[r0,#0xa] */
struct Q4 { u32 w; u8 pad[6]; u8 c; u8 b; };

/* 021BB964  ldr r0,[r0,#0x44] */
struct Q5 { u8 pad[0x44]; u32 v; };

extern u8 func_021B9B94(struct Q1 *p);
extern int func_021BB830(u8 *);
extern void *func_021D5844(void *);
extern u32 func_02017E1C(void *, u32, u32);
extern void func_02027268(u32);
extern void func_020271DC(u16);
extern void func_021BA1B4(char **p, int i);
void func_021B91E4(void *p, int add);
void func_021B9234(unsigned char *p);
extern void *func_02030734(u32, u32, int, const char *, u16);
extern void *func_0201B70C(u16 heap);
extern void func_021BB9D8(u8 *p);
void func_021BB840(struct Q4 *p, int a, int b, int c);
void func_021BB848(u8 *p, void *q, u8 v);
u8 *func_021BB85C(u8 *p, unsigned int i);
u8 *func_021BB878(u8 *p, u32 i);
int func_021BB890(u8 *p, u8 i);
/* 021BB8A8 adds r0,r0,r1; adds r0,#0x30; ldrb r0,[r0] */ u8 func_021BB8A8(u8 *p, u8 i);
/* 021BB8B0 movs r3,#0xc; muls r3,r1,r3; lsls r1,r2,#2; adds r0,r0,r3; * ldr r0,[r1,r0] */ u32 func_021BB8B0(u8 *p, int i, int j);
void func_021BB8BC(u8 *p, u32 *q);
void func_021BB8DC(u8 *p, u32 *q);
void func_021BB908(int *p, int add);
void func_021BB914(int *p);
void func_021BB920(u8 *p);
void func_021BB930(u8 *p, u32 value);
u32 func_021BB964(struct Q5 *p);
u8 *func_021BB968(void *a, void *b, void *c, void *d, int e, u16 heap);
extern u8 d_021F3A70[];

void func_021BB840(struct Q4 *p, int a, int b, int c)
{
    p->b = a;
    p->w = b;
    p->c = c;
}

void func_021BB848(u8 *p, void *q, u8 v) { ((struct Obj09956 *)p)->f4 = q; p[8] = func_021B9B94(q); p[9] = v; }

u8 *func_021BB85C(u8 *p, unsigned int i) { if (i < 4 && (p+i*12)[31] != 255) return p+20+i*12; return 0; }

u8 *func_021BB878(u8 *p, u32 i) { if (((u8 *)((u32)p+i*12))[31] != 255) return (u8 *)((u32)p+20+i*12); return 0; }

int func_021BB890(u8 *p, u8 i) { if (i < 4) return func_021BB830(p+20+i*12); return 0; }


/* 021BB8A8  adds r0,r0,r1; adds r0,#0x30; ldrb r0,[r0] */
/*
 * Leaf with no calls and no pool; 4 instructions, 8 bytes: adds r0, r0, r1; adds r0, #0x30; ldrb r0, [r0]; bx lr.
 */
u8 func_021BB8A8(u8 *p, u8 i) { return *(u8 *)(p + i + 0x30); }


/* 021BB8B0  movs r3,#0xc; muls r3,r1,r3; lsls r1,r2,#2; adds r0,r0,r3;
 *           ldr r0,[r1,r0] */
/*
 * Leaf with no calls and no pool; 6 instructions, 12 bytes: movs r3, #0xc; muls r3, r1, r3; lsls r1, r2, #2; adds r0, r0, r3; ldr r0, [r1, r0]; bx lr.
 */
u32 func_021BB8B0(u8 *p, int i, int j)
{
    return *(u32 *)(p + i * 12 + j * 4);
}

void func_021BB8BC(u8 *p, u32 *q) {
    func_02017E1C(func_021D5844(q),0x73,((struct Obj13294 *)p)->fAC);
    func_02027268(((struct Obj13294 *)p)->fAC);
}

/*
 * evidence: caller narrows func_02017E1C result to u16 before 020271DC.
 */
void func_021BB8DC(u8 *p, u32 *q) {
    func_020271DC(func_02017E1C(func_021D5844(q),5,0));
    func_021BA1B4((char **)(*(u8 * *)&((struct Obj13295 *)p)->fC),7);
    func_021BA1B4((char **)(*(u8 * *)&((struct Obj13295 *)p)->fC),0x54);
}


void func_021BB908(int *p, int add)
{
    func_021B91E4((void *)p[3], add);
}


/*
 * overlays, with no outside branch; the pool relocation has no witness.
 * All bytes correct.
 *
 * UNBLOCKED: func_021B9234 is now an EXACT entry in layout/matched/ov093;
 * the call site resolves as matched, verdict promoted to EXACT.
 */
void func_021BB914(int *p)
{
    func_021B9234((unsigned char *)p[3]);
}

void func_021BB920(u8 *p) { p[0xcba] = 0; p[0xcbf] = 0; }

/*
 * Lever: left-associated pointer addition p + count + 0xcb4 preserves
 * the base-plus-count computation before the incrementing byte store.
 */
void func_021BB930(u8 *p, u32 value)
{
    u32 i;
    u32 count = p[0xcba];
    for (i = 0; i < count; i++) {
        if (value == p[0xcb4 + i]) return;
    }
    p[0xcba]++;
    *(p + count + 0xcb4) = value;
}

u32 func_021BB964(struct Q5 *p) { return p->v; }


u8 *func_021BB968(void *a, void *b, void *c, void *d, int e, u16 heap)
{
    u8 *p;
    p = func_02030734(heap, 0x212c, 1, (const char *)d_021F3A70, 0x245);
    *(void **)(p + 0) = a;
    *(void **)(p + 8) = c;
    *(void **)(p + 4) = b;
    p[0x782] = 0;
    *(u32 *)(p + 0x10) = 0;
    *(u32 *)(p + 0x14) = 0;
    *(void **)(p + 0xc) = d;
    *(u16 *)(p + 0x780) = heap;
    *(int *)(p + 0x18) = e;
    *(void **)(p + 0x4a4) = func_0201B70C(heap);
    func_021BB9D8(p);
    return p;
}

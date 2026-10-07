/*
 * file:     btl_server_p04.c
 * unit:     yes
 * function: func_021B9AE0, func_021B9AEC, func_021B9AF8, func_021B9B04, func_021B9B10, func_021B9B40, func_021B9B54, func_021B9B60, func_021B9B94, func_021B9B98, func_021B9BC4, func_021B9BF0, func_021B9C00, func_021B9C10, func_021B9C24
 * address:  0x021B9AE0
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
 *   func_021B8B9C 0x021B8B9C thumb ov093
 *   func_021CD9F4 0x021CD9F4 thumb ov093
 *   func_021D5B7C 0x021D5B7C thumb ov093
 */
typedef unsigned char  u8;

typedef unsigned int u32;

typedef unsigned short u16;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

/* 021B9B54  ldrb r3,[r0,#0x18]; adds r2,r3,#1; strb r2,[r0,#0x18];
 *           lsls r2,r3,#2; str r1,[r0,r2] */
struct Q1 { u32 items[6]; u8 count; };

/* 021B9BF0  ldrb r2,[r0,#0x18]; cmp r1,r2; bhs; lsls r1,#2; ldr r0,[r0,r1] */
struct S2_021B9BF0 { u32 items[6]; u8 count; };

struct S2_021B9C00 { u8 *items[6]; u8 count; };

extern int func_021B8B9C(unsigned char *p, unsigned char k);
extern void func_021CD9F4(void *,int);
extern int func_021D5B7C(void *);
unsigned char func_021B9AE0(unsigned int x);
char *func_021B9AEC(char *p, int i);
char *func_021B9AF8(char *p, int i);
unsigned char func_021B9B04(int a, int b);
void func_021B9B10(u8 *p,u8 i,int v);
void func_021B9B40(u8 *p);
void func_021B9B54(struct Q1 *p, u32 v);
void func_021B9B60(u8 *p);
/* 021B9B94 ldrb r0,[r0,#0x18] */ u8 func_021B9B94(struct Q1 *p);
u8 func_021B9B98(u8 *p);
u8 func_021B9BC4(u8 *p,int i);
u32 func_021B9BF0(struct S2_021B9BF0 *p, u32 i);
/* 021B9C00 same shape as 021B9BF0 */ u8 *func_021B9C00(struct S2_021B9C00 *p, u32 i);
void func_021B9C10(u32 *p, int a, int b);
void func_021B9C24(u8 *p, u8 i);

unsigned char func_021B9AE0(unsigned int x)
{
    return x & 1;
}

char *func_021B9AEC(char *p, int i)
{
    return p + 4 + i * 0x1c;
}

char *func_021B9AF8(char *p, int i)
{
    return p + 4 + i * 0x1c;
}


unsigned char func_021B9B04(int a, int b)
{
    return func_021B9B98((u8 *)func_021B9AF8((char *)a, b));
}

void func_021B9B10(u8 *p,u8 i,int v) {
    void *q;
    if(p[0x46e] && func_021B8B9C(p,i)) {
        q=*(void **)(p+i*4+16);
        if(q) func_021CD9F4(q,v);
    }
}

void func_021B9B40(u8 *p) {
    int i;
    p[24] = 0;
    for(i=0;i<6;i++) ((u32 *)p)[i]=0;
}

void func_021B9B54(struct Q1 *p, u32 v)
{
    u8 n = p->count;
    p->count = n + 1;
    p->items[n] = v;
}

void func_021B9B60(u8 *p) {
    unsigned int j;
    int i;
    j=0;
    i=0;
    for(;j<p[24];j++) {
        if(func_021D5B7C(*(void **)((u32)p+(u32)i*4))) i++;
        else func_021B9C24(p,i);
    }
}

/* 021B9B94  ldrb r0,[r0,#0x18] */
/*
 * Reads the u8 field at #0x18 of the argument and returns it.
 */
u8 func_021B9B94(struct Q1 *p) { return p->count; }

u8 func_021B9B98(u8 *p) {
    int i;
    u32 n;
    i = 0;
    n = 0;
    for (; i < p[24]; i++) if (func_021D5B7C(((void **)p)[i])) n++;
    return n;
}

u8 func_021B9BC4(u8 *p,int i) {
    u32 n=0;
    for(;i<p[24];i++) if(func_021D5B7C(*(void **)((u32)p+(u32)i*4))) n++;
    return n;
}

u32 func_021B9BF0(struct S2_021B9BF0 *p, u32 i)
{
    if (i < p->count)
        return ((u32 *)p)[i];
    return 0;
}

/* 021B9C00  same shape as 021B9BF0 */
u8 *func_021B9C00(struct S2_021B9C00 *p, u32 i)
{
    if (i < p->count)
        return p->items[i];
    return 0;
}

void func_021B9C10(u32 *p, int a, int b) {
    u32 t=*(u32 *)((u32)p+(u32)a*4);
    *(u32 *)((u32)p+(u32)a*4)=*(u32 *)((u32)p+(u32)b*4);
    *(u32 *)((u32)p+(u32)b*4)=t;
}

void func_021B9C24(u8 *p, u8 i) {
    u32 t=((u32 *)p)[i];
    for(;i<p[24]-1;i++) ((u32 *)p)[i]=((u32 *)p)[i+1];
    ((u32 *)p)[i]=t;
}

/*
 * file:     townmap_p13.c
 * unit:     yes
 * function: func_021BB190, func_021BB19C, func_021BB1BC, func_021BB204
 * address:  0x021BB190
 * region:   ov072
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021BB0E4 0x021BB0E4 thumb ov072
 *   func_02082BCC  0x02082BCC  arm
 *   func_020450F0  0x020450F0  arm
 *   func_020457B0  0x020457B0  arm
 *   func_02045808 0x02045808 arm
 *   func_020452E8 0x020452E8 arm
 */
struct U16Vec;
struct Descriptor;
typedef struct {
    int a;
    int b;
} S;

typedef unsigned int u32;

typedef unsigned short u16;

typedef struct {
    int f0;
    int f4;
    int f8;
    int fc;
    int f10;
} W;

typedef unsigned char  u8;

extern void func_021BB0E4(void *,void *);
extern void func_02082BCC(void *p, int v, int n);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_02045808(struct U16Vec *vec);
extern u32 func_020452E8(struct Descriptor *d);
void func_021BB190(char *p, int *o);
void func_021BB19C(u32 *p,const u32 *v);
void func_021BB1BC(W *p, int a, int b, int c, int d, u16 e);
void func_021BB204(void **p);


void func_021BB190(char *p, int *o)
{
    *(S *)o = *(S *)(p + 0x20);
}

void func_021BB19C(u32 *p,const u32 *v) { p[8]=v[0]+p[8]; p[9]+=v[1]; func_021BB0E4(p,p+8); }


void func_021BB1BC(W *p, int a, int b, int c, int d, u16 e)
{
    func_02082BCC(p, 0, 0x14);
    p->f8 = b;
    p->f10 = d;
    p->fc = c;
    p->f0 = func_020450F0(a, 0, 0, 0x20, 0x18, 0xe, 0);
    p->f4 = (int)func_020457B0(0xff, e);
}

void func_021BB204(void **p) { func_02045808(p[1]); func_020452E8(p[0]); func_02082BCC(p,0,0x14); }

/*
 * function: func_021F4948
 * address:  0x021F4948
 * packet:   pkt_ov048_021F4948
 * region:   ov048
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note:     the left edge is a named sum x = a + b5 * 13 computed before the
 *           f18 store (found by the permuter); inlining it in the macro
 *           argument puts the b5 load after the f18 store, and naming
 *           b5 * 13 alone gives r7 to it instead of a.
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   func_02045B38  0x02045B38  arm
 *   func_020457B0  0x020457B0  arm
 *   func_02045EC0  0x02045EC0  arm
 *   func_0201F250  0x0201F250  thumb
 *   func_020307B0  0x020307B0  arm
 *   func_0201D304  0x0201D304  thumb
 *   func_02047788  0x02047788  arm
 *   func_02047554  0x02047554  arm
 *   func_021875F4  0x021875F4  thumb  ov020
 *   func_02045C04  0x02045C04  arm
 *   func_02047790  0x02047790  arm
 *   func_02047674  0x02047674  arm
 *   func_020477D4  0x020477D4  arm
 *   func_02047804  0x02047804  arm
 *   _fflt          0x0209BDBC  arm
 *   _fdiv          0x0209CE10  arm
 *   _fgr           0x0209BBB0  arm
 *   _fmul          0x0209C77C  arm
 *   _fadd          0x0209C95C  arm
 *   _fsub          0x0209CB8C  arm
 *   _ffix          0x0209C494  arm
 *   _ll_mul        0x0209C054  arm
 *   d_021F523C     0x021F523C  data  ov048  a4
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef int            fx32;
typedef long long      s64;

#define FX_F32_TO_FX32(x) ((fx32)(((x) > 0) ? ((x) * (1 << 12) + 0.5f) : ((x) * (1 << 12) - 0.5f)))
#define FX_Mul(a, b) ((fx32)(((s64)(a) * (b) + 0x800LL) >> 12))

typedef struct P {
    u16 h0;
    u16 h2;
    u8 b4;
    u8 b5;
    u8 pad6[10];
    u32 f10;
    u32 f14;
} P;

typedef struct Q {
    u16 h0;
    u16 h2;
    int f4;
    int f8;
    u32 fC;
    u32 f10;
    u32 f14;
    u32 f18;
} Q;

typedef struct R {
    u8 b0;
    int f4;
    int f8;
    int fC;
    u32 f10;
    u16 h14;
    int f18;
    fx32 f1C;
    fx32 f20;
} R;

typedef struct { u16 h0; u16 h2; u16 h4; } Dim;
typedef struct { int f0; int f4; Dim *f8; } Img;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
struct MsgBank;
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
struct AnmCtl;
struct MsgBank;
struct Owner;
struct Rec;
struct StrObj;
struct U16Vec;
struct WordSet;
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_020307B0(void *p);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern int func_02047788(int *p);
extern int func_02047554(int *p);
extern int func_021875F4(int a0, int a1, int a2, u32 a3, u16 e0, u16 e1, u16 e2);
extern void func_02045C04(struct Rec *rec);
extern int func_02047790(int *p, int i);
extern Img *func_02047674(u32 a);
extern int func_020477D4(struct Owner *owner, u32 index);
extern u32 func_02047804(struct AnmCtl *c, u16 idx);
extern char d_021F523C[];

R *func_021F4948(P *p, const Q *q, int c)
{
    R *r;
    u32 arc;
    u32 str;
    u32 tmp;
    int width;
    int tot;
    int m;
    int a;
    int x;
    fx32 w;

    r = func_02030734(p->h0, 0x24, 0, d_021F523C, 0x180);
    arc = (u32)func_02045B38(0, (u16)q->fC, (u16)q->f10, p->h0);
    if (q->f18 != 0) {
        str = (u32)func_020457B0(0xC0, p->h0);
        tmp = (u32)func_02045EC0((struct MsgBank *)arc, q->f14);
        func_0201F250((struct WordSet *)q->f18, (void *)str, (void *)tmp);
        func_020307B0((void *)tmp);
    } else {
        str = (u32)func_02045EC0((struct MsgBank *)arc, q->f14);
    }
    width = func_0201D304((struct StrObj *)str, p->f14, 1);
    r->fC = func_021875F4(func_02047554((int *)func_02047788((int *)p->f10)), q->f4, q->f8, str, p->b4 * 14, 1, p->h0);
    func_020307B0((void *)str);
    func_02045C04((struct Rec *)arc);
    w = func_02047674(func_02047790((int *)p->f10, q->h0))->f8->h4 << 12;
    m = p->b4 * 13;
    tot = m + width;
    a = tot - m;
    x = a + p->b5 * 13;
    r->f18 = 0;
    r->f1C = FX_F32_TO_FX32((float)x / 1024.0f);
    r->f1C = FX_Mul(r->f1C, w);
    r->f20 = FX_F32_TO_FX32((float)tot / 1024.0f);
    r->f20 = FX_Mul(r->f20, w);
    r->b0 = c;
    r->f4 = 0;
    r->f8 = 0;
    r->f10 = p->f10;
    r->h14 = q->h0;
    func_020477D4((struct Owner *)r->f10, r->h14);
    func_02047804((struct AnmCtl *)r->f10, r->h14);
    return r;
}

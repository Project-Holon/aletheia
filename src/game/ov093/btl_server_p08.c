/*
 * file:     btl_server_p08.c
 * unit:     yes
 * function: func_021C0C34, func_021C0C38, func_021C0CB4, func_021C0CE8, func_021C0D70, func_021C0D90
 * address:  0x021C0C34
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
 *   func_021B9934 0x021B9934 thumb ov093
 *   func_021C0EC4 0x021C0EC4 thumb ov093
 *   func_021C0ED4 0x021C0ED4 thumb ov093
 *   func_021C0EE4 0x021C0EE4 thumb ov093
 *   func_021C0EF4 0x021C0EF4 thumb ov093
 *   func_021C0A4C 0x021C0A4C thumb ov093
 *   func_021CD4FC 0x021CD4FC thumb ov093
 *   func_021C0F04 0x021C0F04 thumb ov093
 *   func_021C11A4 0x021C11A4 thumb ov093
 *   func_021BEC08 0x021BEC08 thumb ov093
 *   func_021BA1B4 0x021BA1B4 thumb ov093
 *   func_021C0F14 0x021C0F14 thumb ov093
 */
#include "../../matched/include/Obj21064.h"
#include "../../matched/include/Obj21066.h"
#include "../../matched/include/Obj01373.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

typedef struct { u16 v; u16 idx:5, b:4, pad:4, c:1, pad2:1, flag:1; } Rec;

typedef struct { u8 pad0[2]; u8 n; u8 pad3[1]; Rec r[1]; } List;

struct Ent_021C0CB4 {
    u16 v;
    u16 lo:5;
    u16 b:4;
    u16 c:4;
    u16 d:1;
    u16 e:1;
    u16 f:1;
};

struct Q_021C0CB4 { u8 pad0[2]; u8 n; u8 pad3; struct Ent_021C0CB4 e[]; };

struct Ent_021C0CE8 {
    u16 v;
    u16 lo : 5;
    u16 b : 4;
    u16 c : 4;
    u16 d : 1;
    u16 e : 1;
    u16 f : 1;
};

struct Q_021C0CE8 { u8 pad0[2]; u8 n; u8 pad3; struct Ent_021C0CE8 e[1]; };

typedef struct Flags { u32 a:1; u32 b:1; } Flags;

extern u8 *func_021B9934(char *p, int i);
extern u32 func_021C0EC4(u8 *);
extern u32 func_021C0ED4(u8 *);
extern void func_021C0EE4(u8 *, u8 *, u8 *);
extern void func_021C0EF4(u8 *, u8 *, u8 *);
extern void func_021C0A4C(u8 *, u8 *, u8 *, u8 *, u32, u32, u8 *);
extern u32 func_021CD4FC(u8 *, u32);
extern u32 func_021C0F04(u8 *);
extern u32 func_021C11A4(u8 *, u8 *, u8 *, u8 *, u8 *, u8 *, u32, Flags);
extern int func_021BEC08(u8 *p, u8 *a);
extern void func_021BA1B4(char **p, int i);
extern u32 func_021C0F14(u8 *);
u32 func_021C0C34(u8 *p);
int func_021C0C38(u8 *p, const List *l, u32 *o0, u16 *o1, u32 *o2, u8 *o3);
int func_021C0CB4(u8 *p, const struct Q_021C0CB4 *q, u32 *out);
int func_021C0CE8(u8 *p, const struct Q_021C0CE8 *q, u32 *o1, u16 *o2, u32 *o3, u8 *o4, u8 *o5);
u32 func_021C0D70(const u8 *q);
u32 func_021C0D90(u8 *p, u8 *q, u8 *a, u8 *b, u32 c, u32 *out, u32 d);



/* 021C0C34  ldrb r0,[r0,#2] */
/*
 * Reads the u8 field at #2 of the argument and returns it.
 */
u32 func_021C0C34(u8 *p) { return p[2]; }



int func_021C0C38(u8 *p, const List *l, u32 *o0, u16 *o1, u32 *o2, u8 *o3)
{
    u32 i = 0;
    int k = 0;
    for (; i < l->n; i++) {
        if (l->r[i].flag) {
            o0[k] = (u32)func_021B9934(*(void **)(p + 8), (u8)l->r[i].idx);
            o1[k] = l->r[i].v;
            o2[k] = l->r[i].b;
            o3[k] = l->r[i].c;
            k++;
        }
    }
    return k;
}



/*
 * Record shape follows the matched unpacker func_021C0CE8.
 * The byte count admits multiple four-byte trailing records (q+4+i*4);
 * a flexible array models that extent without imposing a one-record bound.
 * The original narrows the five-bit field to u8 before the call.
 */
int func_021C0CB4(u8 *p, const struct Q_021C0CB4 *q, u32 *out)
{
    u32 i = 0;
    for (; i < q->n; i++)
        out[i] = (u32)func_021B9934(*(char * *)&((struct Obj21064 *)p)->f8, (u8)q->e[i].lo);
    return q->n;
}




/*
 * Structure recovered (7 parameters; the three stack pointers are re-stored to
 * their own slots in the prologue, `ldr r0,[sp,#0x28]; str r0,[sp,#0x28]`,
 * which the compiled code reproduces). Entries at q+4, stride 4: {u16 v; u16
 * bitfield}, bitfield lo:5 b:4 c:4 d:1 e:1 f:1 (LSB first: lsls #0x1b, #0x17,
 * #0x13, #0x12, #0x10 pairs). Loop keeps entries with f == 0 and packs
 * o1[n]=func_021B9934(p[8], lo) (u8 argument: a `lsls/lsrs #0x18` follows the
 * 5-bit extract), o2[n]=v, o3[n]=b, o4[n]=d, o5[n]=c.
 *
 * Residue: register/spill allocation of the loop. Original: q in r6, i in r7,
 * n in r4, i*4 in r5, the hoisted q+6 spilled to [sp+0x10], flag test through
 * (q+r5)+6 and the lo/b/c/d fields through ONE shared halfword load from the
 * hoisted base (`ldrh r0,[r0,r5]` after `ldr r0,[sp,#0x10]`) with the flag and v read
 * separately through q+r5. Compiled: q in r7, i spilled to [sp+0x10], the hoisted
 * q+6 in r6, and each bitfield reloaded from memory (138 B against 136 B, no
 * cast; 142 B with the u8 parameter). Struct Bits copy (`t = e[i].bits`) gives
 * the single shared load but adds a stack temp and swaps i/n.
 *
 * checks: 1 func_021B9934 is (char *p, int i) in its matched file; the original casts the lo field to u8 before the bl, so the extern parameter is u8 (tried: +4 bytes of cast, spills unchanged); 2 no twin in ov093 with a 7-parameter bitfield unpack; 3 u32/int for i and n, u8-cast loop bound, n declared before i, struct Bits copy for b/c/d, manual (h>>5)&0xf form (gives asrs/ands, wrong), pointer form q+4 cast to struct Ent: none moved q into r6 and i into r7; 4 none fits (declaration-order idiom tried as n-before-i, no change); 5 no new idiom. Sweep I would run: the permuter over declaration order and over which of the flag/lo/b/c/d reads go through a shared u16 local.
 */
int func_021C0CE8(u8 *p, const struct Q_021C0CE8 *q, u32 *o1, u16 *o2, u32 *o3, u8 *o4, u8 *o5)
{
    u32 i = 0;
    u32 n = 0;
    for (; i < q->n; i++) {
        if (q->e[i].f == 0) {
            o1[n] = (u32)func_021B9934(*(char * *)&((struct Obj21066 *)p)->f8, (u8)q->e[i].lo);
            o2[n] = q->e[i].v;
            o3[n] = q->e[i].b;
            o4[n] = q->e[i].d;
            o5[n] = q->e[i].c;
            n++;
        }
    }
    return n;
}



/*
 * Extent ends with two zero alignment bytes at 0x021C0D8E.
 * Declare i before sum, but initialize sum before i, to reproduce both
 * register allocation and the order of the initial movs instructions.
 * Each record supplies the halfword at offset 4, stride 4.
 */
u32 func_021C0D70(const u8 *q)
{
    u32 i;
    u32 sum = 0;
    i = 0;
    for (; i < q[2]; i++)
        sum += *(const u16 *)(q + 4 + i * 4);
    return sum;
}

u32 func_021C0D90(u8 *p, u8 *q, u8 *a, u8 *b, u32 c, u32 *out, u32 d)
{
    u32 k;
    u32 result;
    Flags f;
    if (func_021C0EC4(b) == 1) k = 0x1000;
    else k = 0xc00;
    result = 0;
    f.a = func_021C0ED4(b) > 1;
    f.b = d;
    func_021C0EE4(b, a, *(u8 * *)&((struct Obj01373 *)p)->f858);
    func_021C0EF4(b, a, *(u8 * *)&((struct Obj01373 *)p)->f85C);
    func_021C0A4C(p, a, *(u8 * *)&((struct Obj01373 *)p)->f858, q, c, k, *(u8 * *)&((struct Obj01373 *)p)->f86C);
    func_021C0A4C(p, a, *(u8 * *)&((struct Obj01373 *)p)->f85C, q, c, k, *(u8 * *)&((struct Obj01373 *)p)->f870);
    *out = func_021CD4FC(*(u8 * *)&((struct Obj01373 *)p)->fC, 0x30);
    if (func_021C0F04(*(u8 * *)&((struct Obj01373 *)p)->f858) != 0) {
        result += func_021C11A4(p, q, a, *(u8 * *)&((struct Obj01373 *)p)->f858, *(u8 * *)&((struct Obj01373 *)p)->f86C, *(u8 * *)&((struct Obj01373 *)p)->f4B4, k, f);
        if (result != 0 && func_021BEC08(p, a) != 0)
            func_021BA1B4((char **)(*(u8 * *)&((struct Obj01373 *)p)->f4), 0x4d);
    }
    if (func_021C0F14(*(u8 * *)&((struct Obj01373 *)p)->f85C) != 0)
        result += func_021C11A4(p, q, a, *(u8 * *)&((struct Obj01373 *)p)->f85C, *(u8 * *)&((struct Obj01373 *)p)->f870, *(u8 * *)&((struct Obj01373 *)p)->f4B4, k, f);
    return result;
}

/*
 * file:     ui_scene_p12.c
 * unit:     yes
 * function: func_021B83A0, func_021B8404, func_021B841C, func_021B8434, func_021B8460, func_021B8990, func_021B8A44
 * address:  0x021B83A0
 * region:   ov067
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   _s32_div_f 0x0209C0A4 arm
 *   func_0201C6B4 0x0201C6B4 thumb
 *   func_02035BA4 0x02035BA4 arm
 *   func_021B92F0 0x021B92F0 thumb ov067
 *   func_021B8EA0 0x021B8EA0 thumb ov067
 *   func_021B9190 0x021B9190 thumb ov067
 *   func_021B91D0 0x021B91D0 thumb ov067
 *   func_021B91BC 0x021B91BC thumb ov067
 *   func_021B9228 0x021B9228 thumb ov067
 *   func_020061E4 0x020061E4 thumb
 *   func_02041EE4 0x02041EE4 arm
 *   d_021B94F8 0x021B94F8 data a1
 *   func_02035CB8  0x02035CB8  arm
 *   func_0202EDE4  0x0202EDE4  thumb
 */
#include "../../matched/include/Obj09864.h"
#include "../../matched/include/Obj05147.h"

struct PrintSys;
typedef unsigned char u8;

typedef struct S_021B83A0 {
    u8 pad[0x94];
    volatile u8 cnt;
    u8 idx;
} S_021B83A0;

typedef unsigned short u16;

typedef signed short s16;

typedef unsigned int   u32;

typedef signed char s8;

struct Ent {u32 f0,f4;};

struct Ops { void (*a)(void); void (*b)(void *,int,int); void (*c)(void *,int); };

struct S_021B8460 {
 u8 f0,f1,pad2[0x1c-2];
 const struct Ent *f1c; struct Ops *f20; void *f24; u32 f28; void *f2c; u32 f30; int f34;
 u8 pad38[0x46-0x38]; s8 f46,f47,f48,f49,f4a; u8 f4b;
 u16 f4c,f4e,f50,f52; u32 f54;
 u8 pad58[4]; s16 f5c; u8 pad5e[4]; s16 f62; u16 f64;
 s8 f66,f67; u8 f68,f69; u16 f6a; u32 f6c,f70;
 u8 pad74[0x85-0x74]; s8 f85;
 u8 count:5; u8 ready:1; u8 drag:1; u8 trigger:1;
 u8 f87,f88,f89; u16 f8a; u32 f8c,f90;
};

struct S_021B8990 {
    u8 _0[0x2c];
    u8 *f2c;
    u8 _30[0x4e - 0x30];
    u16 f4e;
    u8 _50[0x74 - 0x50];
    u8 f74;
    u8 f75;
    u8 f76;
    u8 f77;
    u8 f78;
    u8 _79[0x7d - 0x79];
    u8 f7d;
    u8 f7e;
    u8 f7f;
    int f80;
};

struct S_021B8A44 {
    u8 _0[0x12];
    u8 f12;
    u8 _13[0x64 - 0x13];
    u16 f64;
    u8 _66[0x7d - 0x66];
    u8 f7d;
    u8 f7e;
    u8 _7f;
    int f80;
};

extern int _s32_div_f(int a, int b);
extern u32 func_0201C6B4(const struct PrintSys *p);
extern int func_02035BA4(const void *p);
extern void func_021B92F0(struct S_021B8460 *,u32,u32);
extern int func_021B8EA0(struct S_021B8460 *);
extern s8 func_021B9190(const s8 *,int);
extern void func_021B91D0(struct S_021B8460 *,int,int);
extern s8 func_021B91BC(s8,s8,int);
extern void func_021B9228(struct S_021B8460 *p, int i, int a2);
extern void func_020061E4(u32);
extern void func_02041EE4(u32 index, u32 a, u32 b);
extern u32 func_02035CB8(u32 *outA, u32 *outB);
extern u32 func_0202EDE4(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4);
void func_021B83A0(S_021B83A0 *p);
u8 func_021B8404(u8 *p, int n);
int func_021B841C(u8 *p, int n);
void func_021B8434(u8 *p, int a, u8 b, u16 c, u32 d);
int func_021B8460(struct S_021B8460 *s);
void func_021B8990(struct S_021B8990 *s, int idx);
u32 func_021B8A44(struct S_021B8A44 *s);
extern const u8 d_021B94F8[];


void func_021B83A0(S_021B83A0 *p)
{
    u8 v;
    if (p->cnt < 20) {
        p->cnt = p->cnt + 1;
    }
    v = p->cnt;
    if (v == 20) {
        p->idx = 0;
    } else if (v >= 16) {
        p->idx = 1;
    } else if (v >= 12) {
        p->idx = 2;
    } else if (v >= 8) {
        p->idx = 3;
    } else if (v >= 4) {
        p->idx = 4;
    } else {
        p->idx = 5;
    }
}

/*
 * extent: trailing two-byte alignment padding at 0x021B841A.
 * Zero divisors remain admitted; call the ROM runtime helper directly.
 */
u8 func_021B8404(u8 *p, int n)
{
    if (n < 0) n = (int)(0u - (unsigned int)n);
    return _s32_div_f(p[5] << 3, n);
}

int func_021B841C(u8 *p, int n)
{
    if (n < 0) return ((struct Obj09864 *)p)->f62;
    return ((struct Obj09864 *)p)->f64 - ((struct Obj09864 *)p)->f62;
}


void func_021B8434(u8 *p, int a, u8 b, u16 c, u32 d)
{
    p[0x67] = a;
    p[0x68] = b;
    p[0x69] = 0;
    ((struct Obj05147 *)p)->f50 = c;
    ((struct Obj05147 *)p)->f4E = 1;
    ((struct Obj05147 *)p)->f6C = d;
}

#pragma opt_propagation off

/*
 * 2026-10-05 (wD9r P4): 5 bytes differ, size equal (1328), 27 of 27 relocations resolved. Residue: the
 *   second f1c table read (offsets 0134..013A, the `r != -1 && table[r].f4 == 0 && ready == 1 && table[r].f4 == 0`
 *   test) is `ldr r0,[f1c]; lsls r1,r4,#3; adds r0,r0,#4; ldr r1,[r0,r1]` in the original (base+4 added
 *   first, register-offset load); we emit `ldr r1,[f1c]; lsls r0,r4,#3; adds r0,r1,r0; ldr r1,[r0,#4]`.
 *   The earlier draft (docs/notes/pkt_ov067_021B8460.c.txt) used an inline `second()` helper and
 *   `count += (u8)1`; both were dropped here (plain `s->f1c[r].f4` and `count++` give the same 5 bytes).
 *   Tried (25 compiles): plain f1c[r].f4 twice; struct Ent pointer at +4; header struct with Ent e[1];
 *   integer base `(u32)f1c + 4 + r*8` and `+ r*8 + 4`; u8 * base; `&f1c->f4 + r*8` and
 *   `(&f1c->f4)[r*2]`; u8 * field type; a local q = f1c+4 set before the test (gives the original
 *   `adds #4` + register-offset form, but q is hoisted above the `r != -1` compare, so 15 bytes differ),
 *   q set in a comma expression (propagated, 5), q set under `if (r != -1)` (966, q takes r6);
 *   all six per-function pragmas (lifetimes, propagation, dead_assignments, scheduling, peephole: 5;
 *   common_subs: 971); --lang c (5). Idioms checked: indexed-field-stays-inline-or-base-and-index-swap
 *   (5), pointer-sum-with-a-far-offset-associates-differently (5), a-loop-indexes-the-base-and-leaves-
 *   the-field-offset-in-place (5), an-integer-table-base-multiplies-into-a-copy-of-the-index (5),
 *   a-far-offset-before-the-index-keeps-base-and-index-separate-across-calls (5).
 * 2026-10-05 (wD9r P4b, 25 more compiles, all still 5 bytes unless noted): the differing read at 0134 is the ONLY
 *   table read in this block; the original reuses r1 for the second `cmp r1,#0` at 014E, so the two tests share one
 *   load (our CSE does the same). Tried: u32 (*f1c)[2] with f1c[r][1]; static inline IsFree(t,r) for one or both
 *   tests; (&f1c->f4)[r*2] and ((u32 *)f1c + 1 + r*2) on both tests (5), on one test only (915, second read not
 *   CSE'd); inline F4(const u32 *p,int r){return p[r*2];} on &f1c->f4 for both/one test; a second struct Ent2 at
 *   f1c+4 indexed [r].a through a cast or an inline helper; u32 local `t` assigned in the condition
 *   `(t = ...) == 0 && ready == 1 && t == 0`; the condition split into two nested ifs with a `goto fail` into the
 *   else block; f1c without const (5); volatile f4 (996, and a stand-in). Observation: with the pointer-sum form on a
 *   single uncached read, the base/index registers match (r0/r1) but the add is `adds r1,r0,r1; ldr [r1,#4]`;
 *   with a CSE'd read they swap (r1/r0). The original has base+4 as a separate node plus the shifted index.
 *   Open: a source where base+4 is a value live only inside the block after the `r != -1` branch
 *   (a local read twice would stay unpropagated) without being live across later blocks.
 *
 * recoup 2026-10-05 (R12, 15 compiles, all still 5 bytes unless noted): levers 1-2 n/a (callees and widths
 *   already from matched callers; f4 is a plain u32). Lever 3 n/a (no spill slots, r is r4 in both). Lever 4:
 *   table pointer local `t = s->f1c` set right after the call (10 bytes, ldr hoisted above the -1 compare);
 *   `q = &f1c->f4` set in a comma expression, with opt_propagation / opt_lifetimes / opt_dead_assignments off
 *   (15 each, q hoisted above the compare). Lever 5/6: `p = &f1c[r].f4` read once and reused (5);
 *   `*(u32 *)((u8 *)f1c + (r<<3) + 4)`, `4 + (u8 *)f1c + r*8`, `(*(u32 (*)[2])(f1c+r))[1]` (5 each);
 *   `((u32 *)f1c)[r*2+1]` on both tests (1332 B, lsls/adds/lsls form); q scoped inside `if(r!=-1)` with the
 *   success path reached by goto (1328 B, 163 differ, still folds `adds r0,r1,r0; ldr [r0,#4]`).
 *   Finding: every form that keeps base+4 as a tree node is folded into the load offset; every form that
 *   keeps it unfolded (a named local) is hoisted above the `r != -1` compare. Residue unchanged.
 *   Idioms checked this pass: none new beyond the five listed above.
 *
 *   round 2 (27 more compiles, 37 total, 5 bytes unless noted): different spellings on the two tests (995 off, 1332 B);
 *   `(r<<1)+1` / `r<<1|1` / `r*2+1` u32 index forms (1332-1336 B, 1000 off); `q=(u8 *)f1c+4` assigned inside the first
 *   test and reused (5); a DEAD `q=(u8 *)f1c+4` in the first test with the second test spelled
 *   `*(u32 *)((u8 *)f1c + 4 + r*8)` gives 3 bytes (registers and lsls order match, only `adds r0,#4; ldr [r0,r1]`
 *   vs `adds r0,r0,r1; ldr [r0,#4]` differs) but the dead q is a stand-in, not filed; off=r*8 local (5, 11 when set
 *   before the -1 test); `(&f1c[r].f0)[1]`, `((const Ent *)((u8 *)f1c + r*8))->f4`, `*(&f1c->f4 + r*2)` (5);
 *   static inline Rd(base,off) with the +4 in the caller or the callee, Fld() returning f1c+4, Free(const Ent *),
 *   Free(const u32 *) (5 each); `*(const Ent *const *)&f1c` (5); u32 `f1c` field with `[r*2+1]` (1336 B); pragmas
 *   opt_loop_invariants off and opt_strength_reduction off (5). Asm grep for `adds rN,#4; ldr [rN,rM]` with any shift
 *   finds only this function (other hits are folded constant offsets). The original needs base+4 as an unfolded node;
 *   mwcc folds a constant into the load offset unless the sum has another use, and no use of f1c+4 exists in this block.
 *
 * pass 2 2026-10-06 P2L07: EXACT. Closed with `#pragma opt_propagation off` and two named locals set in
 *   the second test after the `r != -1` compare: a byte offset `o = r*8` assigned first, then a byte pointer
 *   `q = (const u8 *)s->f1c + 4`, and both reads spelled `*(u32 *)(q + o)`. The named pointer keeps base+4 as
 *   its own value (register-offset load); assigning the offset first gives the original `lsls` before `adds #4`.
 *   Without the offset local (q only) 3 bytes differ (adds/lsls order swapped). EXACT in --lang c99 and --lang c.
 */
int func_021B8460(struct S_021B8460 *s)
{
 int r,n,v,a; const u8 *q; int o;
 if((int)func_0201C6B4((const struct PrintSys *)s->f34)==0) return 1;
 if(s->f50==3 && s->f70==1) {
  r=func_02035BA4(s->f2c);
  if(s->drag==1) {
   if(s->trigger==0) {
    if(r==-1) {
     s->f85=s->f90-s->f8c;
     a=s->f85;
     if(a<0) a=-a;
     if(a>=16) { s->count=0; s->drag=0; s->trigger=1; }
    } else if(s->count!=3) {
     s->f8c=s->f54;
     s->count++;
    }
   }
  } else if(r!=-1 && s->f1c[r].f4==0) {
   s->f5c=r;
   s->drag=1;
   s->count=0;
   s->f8c=s->f54;
   s->f90=s->f54;
  }
 }
 if(s->f69==0) {
  if(s->f68==0) {
   r=func_02035BA4(s->f2c);
   if(r!=-1 && (o=r*8, q=(const u8 *)s->f1c+4, *(u32 *)(q+o)==0) && s->ready==1 && *(u32 *)(q+o)==0 &&
     ((s->f85<0 && s->f87<r)||(s->f85>0 && s->f87>r))) {
    s->ready=0;
    n=func_021B841C((u8 *)s,s->f67);
    if(n!=0) {
     v=s->f87-r;
     if(v<0) v=-v;
     s->f68=v;
     if(s->f68>(u32)n) s->f68=n;
     s->f87=r;
    } else {
     s->f8c=s->f54;
     s->f90=s->f54;
     s->drag=0;
     func_021B92F0(s,(u16)s->f5c,255);
     s->f4e=s->f50;
     return 0;
    }
   } else {
    s->f8c=s->f54;
    s->f90=s->f54;
    s->ready=0;
    s->drag=0;
    func_021B92F0(s,(u16)s->f5c,255);
    s->f4e=s->f50;
    return 0;
   }
  }
  func_021B92F0(s,255,(u16)s->f5c);
  if(s->f50==3) {
   if(s->f70==0) {
    if(s->f67<0) s->f5c++;
    else s->f5c--;
   } else {
    if(s->trigger==1) {
     if(func_021B8EA0(s)==1) s->count=0;
     s->trigger=0;
    }
    if(s->drag==1 && s->count==3) {
     r=func_02035BA4(s->f2c);
     if(r!=-1 && s->f1c[r].f4==0) s->f5c=r;
     s->f70=0;
     s->f87=s->f5c;
     s->drag=0;
     s->count=0;
     s->f8c=s->f54;
     s->f90=s->f54;
     s->f20->b(s->f24,s->f5c+s->f62,1);
     s->f4e=s->f50;
     return 0;
    }
    if(s->f68==1) {
     n=func_021B841C((u8 *)s,s->f67);
     s->f89++;
     if(s->f89!=6) {
      if(s->f67<0) s->f67=-*((u8 *)s+s->f89+11);
      else s->f67=*((u8 *)s+s->f89+11);
      s->f68=d_021B94F8[s->f89];
     }
     if(s->f68>(u32)n) s->f68=n;
    }
   }
  }
  s->f69=func_021B8404((u8 *)s,s->f67);
  s->f68--;
  if(s->f67<0) {
   s->f62--;
   v=func_021B9190((s8 *)s,-1);
   func_021B91D0(s,s->f62,v);
   s->f46=func_021B91BC(s->f46,s->f48,-1);
   v=func_021B9190((s8 *)s,-1);
   func_021B9228(s,s->f62-(u8)s->f49,(s8)(s->f4a+v));
   s->f47=func_021B91BC(s->f47,s->f49,-1);
  } else {
   s->f62++;
   v=func_021B9190((s8 *)s,1);
   func_021B91D0(s,s->f62+((u8)s->f48-1),v);
   s->f46=func_021B91BC(s->f46,s->f48,1);
   v=func_021B9190((s8 *)s,1);
   func_021B9228(s,s->f62-1,(s8)(s->f4a+v));
   s->f47=func_021B91BC(s->f47,s->f49,1);
  }
  s->f20->b(s->f24,s->f5c+s->f62,1);
  if(s->f6c==1) {
   if((u16)(s->f50+0xfffe)<=1) func_020061E4(0x645);
   else func_020061E4(0x548);
  }
 }
 s->f66=s->f66+s->f67;
 func_02041EE4(s->f0,3,(int)s->f66);
 if(s->f1!=255) func_02041EE4(s->f1,3,(int)s->f66);
 s->f20->c(s->f24,s->f67);
 s->f69--;
 return 1;
}

#pragma opt_propagation reset


void func_021B8990(struct S_021B8990 *s, int idx)
{
    int buf;
    u8 *e;
    int t;
    unsigned u;

    s->f7d = s->f2c[idx * 4];
    e = s->f2c + idx * 4;
    s->f7e = e[1];
    s->f74 = s->f2c[idx * 4];
    s->f75 = e[1];
    s->f76 = e[2];
    s->f77 = e[3];
    u = s->f74;
    if (u >= 0x20)
        u -= 0x20;
    else
        u = 0;
    s->f74 = u;
    t = s->f75 + 0x20;
    if (t <= 0xbf)
        s->f75 = t;
    else
        s->f75 = 0xbf;
    u = s->f76;
    if (u < 0)
        u = 0;
    s->f76 = u;
    t = s->f77;
    if (t <= 0xff)
        s->f77 = t;
    else
        s->f77 = 0xff;
    s->f78 = 0xff;
    if (func_02035CB8((u32 *)(&buf), (u32 *)(&s->f80)) == 0)
        s->f80 = -1;
    s->f7f = 1;
    s->f4e = 2;
}


u32 func_021B8A44(struct S_021B8A44 *s)
{
    int a;
    int b;

    if (func_02035CB8((u32 *)(&a), (u32 *)(&b)) == 0)
        b = s->f80;
    s->f80 = -1;
    return func_0202EDE4(s->f64, b, s->f7d, s->f7e, s->f12);
}

/*
 * function: func_021D32E0
 * address: 0x021D32E0
 * packet: pkt_ov093_021D32E0
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: DIFF
 * residual: 364 bytes, thirteen concrete bytes differ at +0006..+0026;
 * descriptor conversion scheduling only; body from +0028 agrees.
 * checks: 1 B8D8C/B9934/B9A24 and EA768/778/7A8/7B8 own interfaces plus D324C/D3630 rederived; all21 sites resolve; 2 no state-machine twin; 3 typed descriptor unchanged13, long scalar locals38, typed descriptor const unchanged13; 4 masked/truncated-load and const-descriptor idioms read; 5 fresh idiom directory and D324C/D3630 reread; scalar homes only.
 * wave75: six runs; stopped after three nonshrinking changes;
 * init-order and inline descriptor loader were the two scheduling variants.
 * Best y/v/x/u initializer order retained with pointer prototypes.
 * permuter: prior 300 --types consumed (22 to 13); not repeated.
 * wave76: 4 runs; typed descriptor13, long scalar locals38, typed storage-order22, const typed descriptor13. Three nonshrinking iterations; original best13 retained.
 * recoup 2026-10-05 (P17L8): extent is 364 B (lane list said 108). Twin ov093_func_021D324C (same descriptor shape, matched) gives the same callee types; all callee return types checked against matched definitions, no change. Tried, bytes differing: assignment order u,v,x,y 22; u,y,v,x 18; u,v,y,x 20; y,u,v,x 20; u8/u16 and u32/u16 local widths 36/22/13; c as a struct of four words 13; non-const a 13 and 22; pragmas scheduling/opt_propagation/opt_lifetimes off 13 and 22 (no change). Residue unchanged: original loads c[0..3] in address order and the a[1] load sits after the c[3] load, before the c[3] truncation; every source order puts a[1] after the second assignment. Best stays 13 B (y,v,x,u order).
 * recoup 2026-10-05 P30R3: 12 compiles, best stays 13 B (y,v,x,u). Tried, bytes differing: u,v,x,y order 22 (a[1] load hoisted two slots too early, above the c[1] truncation; original keeps it after the c[3] load); const c 22; decl order y,x,v,u 30 and y,u,v,x 37; scheduling/opt_propagation/opt_lifetimes off on the u,v,x,y form 22; u8,u8,u16,u16 locals 36; u16 y only 22; a[1] in a local h set after y 339; callee third parameter u8 330. Residue unchanged: scheduling of ldr a[1] relative to the c[3] truncation.
 * final push 2026-10-05 G4L5: 38 compiles, 3 rounds, best stays 13 B (y,v,x,u). Tried, bytes differing: u,v,x,y with &0xFFFF/&0xFF masks 22; second-definition `k=c[i]; k=(u8)k` forms 31/34; raw c0..c3 temporaries 22; inline g1/g2 call helpers 13 (y,v,x,u) and 22; array k[3] for u,v,x 37; struct C4 param view 22/13; callee u8 params (8D8C, 9934, 9A24) with u32 or u8 locals 311-332 (extra lsl/lsr per call); initialiser declarations 22; int locals 36/38; u32 s,t 13/22; a[1] through a local w or a1 pointer 22/13 (propagated away); pragmas opt_common_subs, opt_dead_assignments, peephole off 22 and 13; volatile u,v,x (info only) 44; orders x,y,u,v 24 and v,u,x,y 25. Residue unchanged: ldr r1,[r5,#4] lands in the stall slot after the 2nd c load; original has it after the 4th. No matched twin has the 4-field shape (asm pattern search hit only 021D266C, unrelated).
 * pass 2 2026-10-06 P2L26: 40 compiles, 3 rounds, best stays 13 B (y,v,x,u). Tried, bytes differing: local struct/array for u,v,x (const and non-const a) 37; address-taken struct through a pointer local 270; volatile u,v,x with const or non-const a 44 (a[1] still hoisted above the volatile stores); inline ReadArgs(c,&u,&v,&x) helpers 22; do-while(0)/label around the assignments 22; decl orders x,v,u,y 27, y,u,v,x 37, p,q,s,t,y,x,v,u 30; u assigned inside the first call argument 21; ((void **)a)[i] 22; unprototyped func_021B8D8C 22/13; register hints 22; named g0/g1 with and without opt_propagation off 22; optimization_level 3 22/13, level 2 202, optimize_for_size 247. Finding: a[1] is free from the start in every form and always takes the 2nd load stall (the 1st goes to the b copy); the original holds it until after the x store. Research in scratchpad wD9r/p2_P2L26/research.md.
 * pass 3 2026-10-06 P3L12: 38 compiles, 3 rounds, best stays 13 B (y,v,x,u). Finding: with non-const a and x address-taken (dummy escape call, info only) the first 0x2C bytes schedule exactly like the original (a[1] waits for the x store, which may alias it); escaping only v moves a[1] to the stall after the v store. But an address-taken local always sits above the spill slots (x at 0x14, original 0), and making all six u,v,x,t,p,q address-taken (or one struct {x,v,u,t,p,q} with escape) gives the exact frame but forwards u in r3 to the first call (31-42 B). The original has no add rX, sp, so no visible escape. Tried, bytes differing: volatile c 22; preceding functions in the file 22/13; escaped x with const a 71, non-const a 52; escaped u,v,x 61; all six 42; struct {x,v,u,t,p,q} 37, with escape 31; pq[2] array 37; struct pointer local with/without opt_propagation off 332/336; escaped array k[3] 55; x as u32 x[1] 52; x as 4th parameter 31, escaped 368; scheduling off 22 (no change); inline Show(&w, y) helper 37; array initialiser 40; pq loop 306; void **a 22. Research in scratchpad wD9r/p3_P3L12/research.md.
 * symbols:
 *   func_021B8D8C 0x021B8D8C thumb ov093
 *   func_021B9934 0x021B9934 thumb ov093
 *   func_021B9A24 0x021B9A24 thumb ov093
 *   func_021CD9E0 0x021CD9E0 thumb ov093
 *   func_021D66D0 0x021D66D0 thumb ov093
 *   func_021EA768 0x021EA768 thumb ov093
 *   func_021EA778 0x021EA778 thumb ov093
 *   func_021EA7A8 0x021EA7A8 thumb ov093
 *   func_021EA7B8 0x021EA7B8 thumb ov093
 *   d_021F3B64 0x021F3B64 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_021B8D8C(void *, void *, u32);
extern u8 *func_021B9934(char *, int);
extern int func_021B9A24(u32, u32);
extern u32 func_021CD9E0(u8 *);
extern void func_021D66D0(void *, u32);
extern void func_021EA768(u32, int, int);
extern int func_021EA778(u32, int);
extern void func_021EA7A8(u32, int);
extern int func_021EA7B8(u32, int);
extern u32 d_021F3B64[];
int func_021D32E0(const u32 *a, int *b, u32 *c)
{
    u32 u, v, x, y;
    int s, t;
    u8 *p, *q;
    y = (u16)c[3];
    v = (u8)c[1];
    x = (u16)c[2];
    u = (u8)c[0];
    s = func_021B8D8C((void *)a[0], (void *)a[1], u);
    t = func_021B8D8C((void *)a[0], (void *)a[1], v);
    p = func_021B9934((char *)a[1], (u32)u);
    q = func_021B9934((char *)a[1], v);
    switch (*b) {
    case 0:
        if (func_021CD9E0((u8 *)a)) {
            func_021D66D0(p, x);
            func_021D66D0(q, y);
            return 1;
        }
        if (func_021B9A24(u, v)) {
            func_021D66D0(p, x);
            func_021D66D0(q, y);
            return 1;
        }
        func_021EA768((int)a[21], s, 0);
        d_021F3B64[1] = 8;
        (*b)++;
        break;
    case 1:
        func_021EA778(a[21], s);
        if (d_021F3B64[1]) d_021F3B64[1]--;
        else {
            func_021EA768(a[21], t, 0);
            (*b)++;
        }
        break;
    case 2: {
        u8 r, z;
        r = func_021EA778(a[21], s);
        z = func_021EA778(a[21], t);
        if (r && z) (*b)++;
        break;
    }
    case 3:
        func_021D66D0(p, x);
        func_021D66D0(q, y);
        d_021F3B64[1] = 0;
        (*b)++;
        break;
    case 4:
        d_021F3B64[1]++;
        if (d_021F3B64[1] > 8) {
            func_021EA7A8(a[21], s);
            (*b)++;
        }
        break;
    case 5:
        if (func_021EA7B8(a[21], s)) {
            func_021EA7A8(a[21], t);
            (*b)++;
        }
        break;
    case 6:
        if (func_021EA7B8(a[21], t)) (*b)++;
        break;
    default:
        return 1;
    }
    do { return 0; } while (0);
}

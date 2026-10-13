/*
 * function: func_021FD14C
 * address: 0x021FD14C
 * packet: pkt_ov132_021FD14C
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * followers: unlabelled leaves begin at 021FD208 and 021FD218 (not part of this function; function body is 188 bytes).
 * note 2026-10-05 (wave P13 lane B5): 6/188 bytes differ, all register colour: the allocation result q is in r6 and q+4 (s) in r4, the original has q r4, s r6 (m2 r7, p r5 match). Callee types checked (02008468 int, 020173E8 u32, 02030734 returns void*, 0203D3F8 u32, caller compares result with 1). Tried, all the same 6 bytes: separate locals for the first size pair; one variable reused for the first size and q; both q and s as u32; q typed as header struct with s = q->data; s declared before q; s set before or after p->buffer store and after m; s = q; s += 4; m+s order; sizes in block locals; all six per-function pragmas (opt_lifetimes, opt_propagation, opt_common_subs, opt_dead_assignments, scheduling, peephole). Without a local s (q+4 written at each use) the 0x4e<<2 offset is hoisted and 121 bytes differ; p->buffer instead of q is worse (123). Idioms read: two-long-lived-values-in-each-others-registers, a-result-computed-in-a-dying-local-takes-that-locals-register, a-colour-swap-no-source-form-fixes-can-be-opt-lifetimes-off, a-field-read-into-its-own-local-before-a-getter-subtraction-sets-the-colour-order, array-bases-as-pointer-locals-reopen-a-flat-declaration-order.
 * recoup 2026-10-05 P29R10: still 6/188 bytes (q r6/s r4 vs original q r4/s r6). New tries, all the same 6 bytes unless noted: q=p->buffer=alloc chain; s=q+4 before m; m reusing a; int sizes; reversed and regrouped declaration orders (7 layouts, no effect); q as u32* with s=(char*)(q+1); q as header struct with s=q->data; const void* source in func_02082D44; q and s as u32; a+b+4 order (15 bytes). Worse: s=p->buffer+4 (110), plus copy from p->buffer (123), no s local with q+4 / q+4+m / q+m+4 (121), s after first copy (125), s set at the call (125), s before p->buffer store (25). No twin in src/matched/ov (callees 02030734+02082D44+020173E8 share no file). Idioms re-read: two-long-lived-values-in-each-others-registers, a-colour-swap-no-source-form-fixes-can-be-opt-lifetimes-off.
 * final push 2026-10-05 G2L10: still 6/188 bytes (q r6/s r4 vs original q r4/s r6). Analysis: q and s interfere, equal cost, so the tie is the simplify order; s (later vreg) is coloured first. With q+4 written at each use q does get r4 but the 0x4e<<2 offset is hoisted (121 bytes), so the named s is right. New tries, all the same 6 bytes unless noted: s=q+4 before m (24 bytes); declaration orders s,q and m,b,a; block-scoped a/b/q and m/s with initialisers; sizes inlined in the alloc call; p->buffer=q=alloc; s=p->buffer then if(s) free (and q likewise); opt_lifetimes+opt_propagation off together; q void* with (char*)q+4; q u32 with s char*; q char* with s u32; static inline halloc wrapper (0x533 as a line argument); static inline fill(p,q,m) for the three copies; u16 heap local (178); first/second pointers as locals (128); inline bufsize() for both size sums (63). Idioms read: two-long-lived-values-in-each-others-registers, a-result-computed-in-a-dying-local-takes-that-locals-register, a-colour-swap-no-source-form-fixes-can-be-opt-lifetimes-off, a-dying-pointer-loads-scratch-colour-can-be-an-allocator-tie, a-field-read-into-its-own-local-before-a-getter-subtraction-sets-the-colour-order, const-on-a-read-only-source-parameter-settles-a-register-tie. Twins: ov132 021FD350 and 021FC848 (same callees, no matching shape); mwcc ALLOCATOR_CASEBOOK is PPC but says vreg birth order decides ties.
 * pass 2 2026-10-06 P2L12: still 6/188 bytes (q r6/s r4 vs original q r4/s r6), 39 compiles. New tries, all 6 bytes unless noted: local names; s reused for the 020399A8 result with a/b reused for the final sizes (with and without opt_lifetimes off); opt_lifetimes off with declaration orders s,q and m,s,b,q,a; named size locals for the copies and t=s+m; 02082D44(void*,void*,int) with int a/m; s assigned inside the first copy's argument list; s from a static inline Data(q); alloc in a static inline Alloc(p,size); register on q or s; char *const q and s in nested blocks; sibling 021FD350 form (char *p with casts, n reused, h local) with named s. Worse: cursor forms q+=4/q+=m, s=q;s+=4, q++ or q+=4 in the call argument (62 to 67): any second definition frees r7 and hoists the 0x138 offset. Coloring.c (mwcc_ref): select pops the simplify stack, so the order of q vs s comes from vreg numbering or degree; declaration order has no effect here. Assembly hits checked (adds r1,rX,#0 then adds rY,rX,#K before a call): ov010 0216787A, ov093 021C462E, ov116 021D6DF4, ov172 021B7350, all loop copies, no match.
 * pass 3 2026-10-06 P3L06: still 6/188 bytes (q r6/s r4 vs original q r4/s r6), 40 compiles. New tries, all 6 bytes unless noted: zero local (021FD350 style); s=&q[4] and &s[m]; p->buffer=alloc then q=p->buffer (store forwarded); full sibling style (int n, m reused for every size pair, h local); u8 and u16 return for 02008468 with u8/u16 m; long m and long a,b,m; s+=m in the third copy argument; 4+q and m+s; m reusing b; separate old local for the free guard; Owner *const p; opt_loop_invariants off; opt_strength_reduction off; opt_propagation off with t=alloc, s=t+4, q=t (q born after s); inline Header(p,q) returning s; inline Pack(p,q) with m and s inside; inline Copy wrapper; m/s inner block without initialisers (both orders); a/b/q inner block to the first copy; c99 mid-block declarations; local aggregates {head,body} (both orders) and {head,first,second} (021FC848 row style). Worse: first copy from s-4 (120, q and s merge); q+4+m with named s (121); inline Pack(p,q,q+4,m) (121, s propagated). Diagnostics: removing m or s gives q r4 first, so only the q/s/m clique orders s first; dsi 1.1, 1.2, 1.2p2 give the same 6 bytes. Asm scan (adds rLow,rX,#0 plus adds rY,rX,#K before a call): only ov198 02210E20 (matched, base=p+4 from a parameter, not applicable). Idioms read: of-two-equal-temps-the-later-born-one-gets-the-lower-register, a-masked-locals-declared-width-is-invisible-in-the-diff-and-decides-its-register, a-no-code-self-assignment-reorders-the-register-colouring (stand-in, not used), declaration-position-orders-block-scope-colouring, a-width-stored-in-the-handle-temp-it-replaces-keeps-the-original-colours, two-long-lived-values-in-each-others-registers (callees read no hidden arguments).
 * pass 4 2026-10-06 P4L04: EXACT* (--lang c99 and --lang c). The third block pointer is computed up front as t=q+4+MYSTATUS_GetSize() and the second copy writes to q+4 with no named s: CSE turns the shared q+4 into a temp born before the first copy, and t is forward-substituted into the third copy as temp+m, which gives the image colours (q r4, q+4 r6, size r7). Same layout as the row pointers in 021FC848 (P(row,0x88)=buf+4+MYSTATUS_GetSize()).
 * symbols:
 *   func_020307B0 0x020307B0 arm
 *   func_02030734 0x02030734 arm
 *   MYSTATUS_GetSize 0x02008468 thumb
 *   POKE_TOOL_GetBoxParamSize 0x020173E8 thumb
 *   func_02082D44 0x02082D44 arm
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_SendData 0x0203D3F8 arm
 *   d_021FDE5C 0x021FDE5C data a4
 */
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned char u8;
typedef struct {u16 heap;u8 pad[0x12a];u32 value;void *first,*second;char *buffer;u8 tail[0x70];} Owner;
extern u32 func_020307B0(void *p);
extern void *func_02030734(u32,u32,int,const char *,u16);
extern int MYSTATUS_GetSize(void);
extern u32 POKE_TOOL_GetBoxParamSize(void);
extern void func_02082D44(void *,void *,u32);
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern u32 GFL_NET_SendData(u32,u32,u32,u32,u32,u32,u32,u32);
extern const char d_021FDE5C[];
u32 func_021FD14C(Owner *p)
{
    u32 a, b;
    char *q, *t;
    if(p->buffer) func_020307B0(p->buffer);
    a=MYSTATUS_GetSize();
    b=POKE_TOOL_GetBoxParamSize();
    q=func_02030734(p->heap,a+4+b,0,d_021FDE5C,0x533);
    p->buffer=q;
    t=q+4+MYSTATUS_GetSize();
    func_02082D44(&p->value,q,4);
    func_02082D44(p->first,q+4,MYSTATUS_GetSize());
    func_02082D44(p->second,t,POKE_TOOL_GetBoxParamSize());
    return GFL_NET_SendData((u32)GFL_NET_HANDLE_GetCurrentHandle(),0xff,0x1101,MYSTATUS_GetSize()+4+POKE_TOOL_GetBoxParamSize(),(u32)p->buffer,1,0,1);
}

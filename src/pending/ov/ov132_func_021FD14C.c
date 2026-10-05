/*
 * function: func_021FD14C
 * address: 0x021FD14C
 * packet: pkt_ov132_021FD14C
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: DIFF
 * followers: unlabelled leaves begin at 021FD208 and 021FD218 (not part of this function; function body is 188 bytes).
 * note 2026-10-05 (wave P13 lane B5): 6/188 bytes differ, all register colour: the allocation result q is in r6 and q+4 (s) in r4, the original has q r4, s r6 (m2 r7, p r5 match). Callee types checked (02008468 int, 020173E8 u32, 02030734 returns void*, 0203D3F8 u32, caller compares result with 1). Tried, all the same 6 bytes: separate locals for the first size pair; one variable reused for the first size and q; both q and s as u32; q typed as header struct with s = q->data; s declared before q; s set before or after p->buffer store and after m; s = q; s += 4; m+s order; sizes in block locals; all six per-function pragmas (opt_lifetimes, opt_propagation, opt_common_subs, opt_dead_assignments, scheduling, peephole). Without a local s (q+4 written at each use) the 0x4e<<2 offset is hoisted and 121 bytes differ; p->buffer instead of q is worse (123). Idioms read: two-long-lived-values-in-each-others-registers, a-result-computed-in-a-dying-local-takes-that-locals-register, a-colour-swap-no-source-form-fixes-can-be-opt-lifetimes-off, a-field-read-into-its-own-local-before-a-getter-subtraction-sets-the-colour-order, array-bases-as-pointer-locals-reopen-a-flat-declaration-order.
 * recoup 2026-10-05 P29R10: still 6/188 bytes (q r6/s r4 vs original q r4/s r6). New tries, all the same 6 bytes unless noted: q=p->buffer=alloc chain; s=q+4 before m; m reusing a; int sizes; reversed and regrouped declaration orders (7 layouts, no effect); q as u32* with s=(char*)(q+1); q as header struct with s=q->data; const void* source in func_02082D44; q and s as u32; a+b+4 order (15 bytes). Worse: s=p->buffer+4 (110), plus copy from p->buffer (123), no s local with q+4 / q+4+m / q+m+4 (121), s after first copy (125), s set at the call (125), s before p->buffer store (25). No twin in src/matched/ov (callees 02030734+02082D44+020173E8 share no file). Idioms re-read: two-long-lived-values-in-each-others-registers, a-colour-swap-no-source-form-fixes-can-be-opt-lifetimes-off.
 * symbols:
 *   func_020307B0 0x020307B0 arm
 *   func_02030734 0x02030734 arm
 *   func_02008468 0x02008468 thumb
 *   func_020173E8 0x020173E8 thumb
 *   func_02082D44 0x02082D44 arm
 *   func_020399A8 0x020399A8 arm
 *   func_0203D3F8 0x0203D3F8 arm
 *   d_021FDE5C 0x021FDE5C data a4
 */
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned char u8;
typedef struct {u16 heap;u8 pad[0x12a];u32 value;void *first,*second;char *buffer;u8 tail[0x70];} Owner;
extern void func_020307B0(void *);
extern void *func_02030734(u32,u32,int,const char *,u16);
extern int func_02008468(void);
extern u32 func_020173E8(void);
extern void func_02082D44(void *,void *,u32);
extern void *func_020399A8(void);
extern u32 func_0203D3F8(u32,u32,u32,u32,u32,u32,u32,u32);
extern const char d_021FDE5C[];
u32 func_021FD14C(Owner *p)
{
    u32 a, b, m;
    char *q, *s;
    if(p->buffer) func_020307B0(p->buffer);
    a=func_02008468();
    b=func_020173E8();
    q=func_02030734(p->heap,a+4+b,0,d_021FDE5C,0x533);
    p->buffer=q;
    m=func_02008468();
    s=q+4;
    func_02082D44(&p->value,q,4);
    func_02082D44(p->first,s,func_02008468());
    func_02082D44(p->second,s+m,func_020173E8());
    return func_0203D3F8((u32)func_020399A8(),0xff,0x1101,func_02008468()+4+func_020173E8(),(u32)p->buffer,1,0,1);
}

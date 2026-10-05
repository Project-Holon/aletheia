/*
 * function: func_021B074C
 * address: 0x021B074C
 * packet: pkt_ov013_021B074C
 * region: ov013
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: arm
 * status: DIFF
 * Remove request from its slot; clear mask and shut down an empty session.
 * residual: DIFF 172/172 bytes, 18 concrete bytes differ; all seven relocations resolved.
 * evidence: fresh two-argument clear helper and pointer-to-slot loop each tied 18. Decrement before slot-clear gave 26; u16 loop check gave 180 bytes/84. Remaining table-base colour and slot/global store scheduling.
 * checks: 1 own matched 1A48(char*), 1720(u32), 133C(u32), and current 3018 callers reread; 2 no exact session twin; 3 const request remains best, fresh u16 counter adds truncation and 8 bytes; 4 inline, flag/input identity and no-code self-assignment idioms read; 5 full directory and fresh ov013 neighbours reread, no addressed stack aggregate; next hypothesis an independently sourced slot-clear helper, no further manual reorder.
 * permuter: prior typed budget-300 baseline/best 18 consumed; not repeated.
 * prior evidence: inline clearSlot, enum zero and long counter stayed 18; word array gave 20.
 * recoup 2026-10-05 (lane C9, 18 compiles): residue unchanged, 18 B: table base r2 instead of r3 (+04,+10), and the order/colours of ldr r6 / mov zero / ldr f20 / str slot (+28..+34; original zero=r2, f20=r1, ours zero=r1 reused by f20). Callee returns checked from matched definitions (1A48, 1720, 133C all void): no change. Tried with results: f20-- before slot clear 26 B (f20 gets r2, zero r1, base r3 right but order wrong); arg pointer local before the stores 18; f20 read into a local before the clear and written back as n-1 (also via a Ctx pointer local, and as n=f20-1) 18 (load is forwarded after the store); Chan struct array with cast 18; non-const p 18; table pointer local 18; pragmas opt_lifetimes, opt_common_subs, opt_dead_assignments, scheduling, peephole each 18, opt_propagation 180 B/146. Reading: original has zero and the f20 value live at the same time (base takes r3) with the zero defined first; no plain source order found that keeps the f20 load before the slot store while the sub follows it.
 * symbols:
 *   d_021B3CB0 0x021B3CB0 data ov013 a4
 *   d_021B3CBC 0x021B3CBC data ov013 a4
 *   d_021B3C84 0x021B3C84 data ov013 a4
 *   func_021B1A48 0x021B1A48 arm ov013
 *   func_021B1720 0x021B1720 arm ov013
 *   func_021B133C 0x021B133C arm ov013
 *   func_021B3018 0x021B3018 arm ov013
 */
typedef unsigned int u32;
typedef unsigned char u8;
typedef struct { u8 pad0[8]; u32 f8; } Req;
typedef struct { u8 pad0[4]; u32 f4; u8 pad8[12]; int f14; u8 pad18[8]; int f20; } Ctx;
extern Req *d_021B3CB0[3];
extern char d_021B3CBC[];
extern Ctx d_021B3C84;
extern void func_021B1A48(char *p);
extern void func_021B1720(u32 i);
extern void func_021B133C(u32 i);
extern void func_021B3018(void);
void func_021B074C(const Req *p)
{
    u32 i;
    for(i=0;i<3;i++) {
        if(d_021B3CB0[i]==p) {
            d_021B3CB0[i]=0;
            d_021B3C84.f20--;
            func_021B1A48(d_021B3CBC+i*0x94);
            func_021B1720(i);
            func_021B133C(i);
            d_021B3C84.f4 &= ~p->f8;
            break;
        }
    }
    if(d_021B3C84.f20==0) {
        d_021B3C84.f14=1;
        func_021B3018();
        d_021B3C84.f4=0;
    }
}

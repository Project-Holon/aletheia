/*
 * function: func_021C8FA8
 * address: 0x021C8FA8
 * packet: pkt_ov114_021C8FA8
 * region: ov114
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: arm
 * lang: c99
 * status: DIFF
 * checks: 1 current own SDK Process/Response/Shutdown/GetLastError/97E0
 * and memcpy bodies rederived; memcpy returns void pointer and takes uint size.
 * 2 current 8F2C/941C/8C68/87FC and sibling poller lack an exact twin.
 * 3 nonconst response unchanged40; unsigned state unchanged40, byte Hdr fields
 * retained; no entry parameter to narrow. 4 aggregate/pointer/enum, const source
 * and inline-wrapper idioms reread. 5 full unfiltered idiom directory and
 * live ov114/115/116 neighbours refreshed; no new exact lever.
 * retry-wave78: FINAL retry-exhausted: five compiled one calls baseline1044/40,
 * direct Hdr assignment with own memcpy ABI1044/40, temporary Hdr1068/713,
 * unsigned state1044/40, nonconst response1044/40. Three nongains STOP.
 * residual: 1044/1044 bytes, 40 concrete bytes out, all 34 sites resolve.
 * fresh pass: macro-free expansion and memcpy ABI repair flat; reversed
 * inline arguments flat; explicit byte locals worse. Three nongains STOP.
 * permuter: earlier once300 consumed, including failed macro baseline
 * 1036/814 and invalid volatile/uninitialized best; never repeated.
 * remaining: header-copy byte registers, len load/store scheduling, and
 * odd-state final state/result store order. Best macro-free C retained.
 * 2026-10-05 P23L9: extent is 1044 B (lane size 44 was wrong); 40 B differ, all
 * in three places. (1) header copy in cases 6, 8, 10: original loads code to r1,
 * sub to r0 (the dying pointer register), then the pool word to r2 (case 2: r2, r0,
 * pool r3 with len loaded between); ours gives r2, r1, pool r0. (2) last block
 * (cases 3,5,7,9,11): original stores state, then sub r0,r5,#0x10, then stores
 * result; ours does the sub first. Tried, one compile each: field by field
 * copy (48 B out), local Hdr temp (40), u8 byte locals (43), 2-byte array struct
 * cast (40), byte pointer d[0]=s[0] (63), result stored before state (41, mvn
 * first), int local holding 12 (40), opt_lifetimes, opt_propagation, scheduling,
 * peephole off (all 40; scheduling off does not move the sub, so it is codegen
 * order, not the scheduler). Idioms read: const-source-pointer struct copy,
 * chained assignment, global struct member reread, copy and step hoisted above a
 * call, dead store blocks propagation, two-word struct copy, 8-byte pair copy,
 * load above unrelated store, compute operands before store: none moved it.
 * Callees: DWCi_EncSessionGetResponse is a matched ov_sdk definition; no arity or
 * void problem found.
 * recoup 2026-10-05 P30R4: 40 -> 32 B. The last block (cases 3,5,7,9,11) now
 * writes d_021D4084.state / .result directly instead of through ctx: closes the
 * state-store-before-sub order (8 B). Remaining 32 B: header copy colours in cases
 * 2, 6, 8, 10 (original b0,b1,pool = r1,r0,r2; ours r2,r1,r0) and case 2 len load
 * placed between the byte loads. Tried, no change from 32 (or worse): direct global
 * in every use (100), direct in header cases (32), resp local (40), field-by-field
 * copy (40), byte-array Hdr (32), non-const source (32), dest as array element (32),
 * GetResponse returning const Hdr * (32), opt_common_subs, opt_dead_assignments,
 * opt_lifetimes, opt_propagation off (32 each). 17 compiles.
 * symbols:
 *   d_021D4084 0x021D4084 data a4
 *   d_021D421C 0x021D421C data a1
 *   DWCi_EncSessionProcess 0x021CA0A0 arm ov114
 *   DWCi_EncSessionShutdown 0x021CA1B4 arm ov114
 *   DWCi_EncSessionGetResponse 0x021CA228 arm ov114
 *   DWC_GetLastErrorEx 0x02059E38 arm
 *   func_021C97E0 0x021C97E0 arm ov114
 *   func_02092344 0x02092344 arm
 */
typedef unsigned char u8;
typedef unsigned long u32;
typedef struct { u8 code,sub; } Hdr;
typedef struct { Hdr h[4]; } Payload;
typedef enum { STATE_IDLE=0,STATE_END=12 } State;
typedef struct {
    State state;
    int result;
    u8 pad[0x198-8];
    Hdr hdr;
    u8 pad19a[2];
    u8 *buf;
} Ctx;
extern Ctx d_021D4084;
extern Hdr d_021D421C;
extern int DWCi_EncSessionProcess(void);
extern void DWCi_EncSessionShutdown(void);
extern u32 DWCi_EncSessionGetResponse(u32 *);
extern int DWC_GetLastErrorEx(int *,int *);
extern int func_021C97E0(unsigned);
extern void *func_02092344(void *,const void *,unsigned int);
static inline void copyHdr(Hdr *out,const Hdr *in)
{
    *out=*in;
}
void func_021C8FA8(void)
{
    u32 len;
    int code,type;
    const u8 *resp;
    Ctx *ctx;
    ctx=&d_021D4084;
    switch(ctx->state) {
    case 2:
        switch(DWCi_EncSessionProcess()) {
        case 1:
            ctx->state=12;
            DWC_GetLastErrorEx(&code,&type);
            ctx->result=func_021C97E0(type);
            DWCi_EncSessionShutdown(); return;
        case 8:
            ctx->state=12;
            copyHdr(&d_021D421C,(const Hdr *)DWCi_EncSessionGetResponse(&len));
            if(len!=0) ctx->result=ctx->hdr.code;
            else ctx->result=-2;
            DWCi_EncSessionShutdown(); return;
        }
        return;
    case 4:
        switch(DWCi_EncSessionProcess()) {
        case 1:
            ctx->state=12;
            DWC_GetLastErrorEx(&code,&type);
            ctx->result=func_021C97E0(type);
            DWCi_EncSessionShutdown(); return;
        case 8:
            ctx->state=12;
            resp=(u8 *)DWCi_EncSessionGetResponse(&len);
            func_02092344(ctx->buf,resp,0xa8c);
            if(len==0xa8c) ctx->result=0;
            else {
                switch(ctx->buf[0]) {
                case 2: ctx->result=-3; break;
                case 5: ctx->result=-2; break;
                default: ctx->result=-5; break;
                }
            }
            DWCi_EncSessionShutdown(); return;
        }
        return;
    case 6:
        switch(DWCi_EncSessionProcess()) {
        case 1:
            ctx->state=12;
            DWC_GetLastErrorEx(&code,&type);
            ctx->result=func_021C97E0(type);
            DWCi_EncSessionShutdown(); return;
        case 8:
            ctx->state=12;
            copyHdr(&d_021D421C,(const Hdr *)DWCi_EncSessionGetResponse(&len));
            switch(ctx->hdr.code) {
            case 1: ctx->result=0; break;
            case 2: ctx->result=-3; break;
            case 4: ctx->result=-1; break;
            case 5: ctx->result=-2; break;
            default: ctx->result=-5; break;
            }
            DWCi_EncSessionShutdown(); return;
        }
        return;
    case 8:
        switch(DWCi_EncSessionProcess()) {
        case 1:
            ctx->state=12;
            DWC_GetLastErrorEx(&code,&type);
            ctx->result=func_021C97E0(type);
            DWCi_EncSessionShutdown(); return;
        case 8:
            ctx->state=12;
            copyHdr(&d_021D421C,(const Hdr *)DWCi_EncSessionGetResponse(&len));
            switch(ctx->hdr.code) {
            case 1: ctx->result=0; break;
            case 3: ctx->result=1; break;
            case 4: ctx->result=2; break;
            case 5: ctx->result=-2; break;
            default: ctx->result=-5; break;
            }
            DWCi_EncSessionShutdown(); return;
        }
        return;
    case 10:
        switch(DWCi_EncSessionProcess()) {
        case 1:
            ctx->state=12;
            DWC_GetLastErrorEx(&code,&type);
            ctx->result=func_021C97E0(type);
            DWCi_EncSessionShutdown(); return;
        case 8:
            ctx->state=12;
            resp=(u8 *)DWCi_EncSessionGetResponse(&len);
            *(Payload *)ctx->buf=*(Payload *)resp;
            if(len==8) ctx->result=0;
            else {
                switch(ctx->buf[0]) {
                case 1: ctx->result=0; break;
                case 3: ctx->result=1; break;
                case 4: ctx->result=2; break;
                case 5: ctx->result=-2; break;
                default: ctx->result=-5; break;
                }
            }
            DWCi_EncSessionShutdown(); return;
        }
        return;
    case 3: case 5: case 7: case 9: case 11:
        d_021D4084.state=12; d_021D4084.result=-4;
        DWCi_EncSessionShutdown(); return;
    case 0: case 1: case 12: break;
    }
}

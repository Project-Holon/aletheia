/*
 * function: func_021C8FA8
 * address: 0x021C8FA8
 * packet: pkt_ov114_021C8FA8
 * region: ov114
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: arm
 * lang: c99
 * status: EXACT
 * held 2026-10-05 (integrator): kept in pending for the user. The fixed-address cast
 *   (Ctx *)0x021D4084 names an overlay global by its link address, which the authors could not
 *   know when writing the code; a form without it (memcpy alone) is 52 B off.
 * final push 2026-10-05 G7L2: EXACT (was DIFF 32 B). Two changes. (1) The 2-byte header copy
 * into d_021D421C is memcpy(&d_021D421C, resp, 2): mwcc then creates the destination pool word
 * first, so the byte loads take r1/r0 and the pool r2 as in the original (see
 * docs/idioms/a-pair-copy-with-the-destination-pool-load-between-the-two-loads-is-memcpy.md).
 * DWCi_EncSessionGetResponse returns const void * so the call result feeds memcpy directly.
 * (2) ctx is the fixed address (Ctx *)0x021D4084, also used in the last block. With ctx known
 * to be d_021D4084, mwcc proves it distinct from d_021D421C and hoists the ctx->hdr.code read
 * and the len stack load above the header stores; a fixed-address pointer leaves the read after
 * the stores like the original. The pool word still resolves to d_021D4084.
 * Earlier notes (DIFF history): struct copies, byte locals, pragmas, field copies, direct
 * globals and const variants were all flat at 32 B and are superseded.
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
#include "../../matched/arm9_sdk/libc/string.h"
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
extern const void *DWCi_EncSessionGetResponse(u32 *);
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
    ctx=(Ctx *)0x021D4084;
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
            memcpy(&d_021D421C,DWCi_EncSessionGetResponse(&len),2);
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
            resp=(const u8 *)DWCi_EncSessionGetResponse(&len);
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
            memcpy(&d_021D421C,DWCi_EncSessionGetResponse(&len),2);
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
            memcpy(&d_021D421C,DWCi_EncSessionGetResponse(&len),2);
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
            resp=(const u8 *)DWCi_EncSessionGetResponse(&len);
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
        ctx->state=12; ctx->result=-4;
        DWCi_EncSessionShutdown(); return;
    case 0: case 1: case 12: break;
    }
}

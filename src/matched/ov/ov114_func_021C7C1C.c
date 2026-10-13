/*
 * function: DPW_TR_Main
 * address:  0x021C7C1C
 * packet:   pkt_ov114_021C7C1C
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * residual: none (EXACT in --lang c99 and --lang c, 2620 bytes).
 * retry: renewed wave77 R11; named completed 204, ctx pointer improves to 202;
 *   const response, long fields, long len retain 202; iteration stopped after
 *   three nongains. Own-definition API correction and unsigned ctx retain 202.
 * prior: enum setter 204; enum inline poll 242; unsigned fields 204.
 * previous: permuter budget 600 was already run, best 163 in previous environment.
 * checks: 1 current own Process int/0, Shutdown void/0, Response ulong with ulong pointer, error int with two int pointers, 8EB4 int/uint and memcpy void pointer/3 reread; 2 live8EB4/8C68/87FC and sibling poller lack exact twin; 3 const response unchanged202; 4 global-base, aggregate-inline and small-constant idioms reread; 5 unfiltered directory/live neighbours refreshed, no stack aggregate rescue.
 * retry-wave78: FINAL retry-exhausted: one CCERR from prior comment's embedded comment terminator repaired; five compiled one calls baseline2620/202, independent case-scoped Ctx pointers2620/202, long fields2620/202, inline Hdr copy2620/202, const response2620/202. Three nongains STOP; previous permuter600 remains consumed. Best baseline retained.
 *
 * recoup 2026-10-05 (P22L8): real extent 2620 B (the 52 B lane size was wrong). Baseline 202/2620, only the
 *   prologue webs differ (orig 24 r4, ctx r5, hdr r6, -13 r7, 0 r8; build hdr r4, -13 r5, 0 r6, 24 r7, ctx r8: a
 *   cyclic rotation). Tried, all at or above 202: direct extern-object access (204); hdr as pointer local, both
 *   declaration orders (313); the shared error path as a static inline Fail(ctx) (286); switch on the extern
 *   field (202); ctx assigned after declaration (202); constants as locals fin/zero/bad (202, propagated);
 *   each of the six per-function pragmas (202 each). Callee types checked: all match their uses. No twin
 *   (grep of DWCi_EncSessionProcess/GetResponse hits only the SDK leaves).
 *
 * recoup 2026-10-05 P30R7: baseline 202/2620 (five prologue webs rotate). Tried: cancel group
 *   moved to the top of the switch (2074, layout changes); ctx declared last (202); ctx first
 *   (202); constants fin/bad/zero as initialised locals in the order 24, ctx, hdr, -13, 0 plus
 *   hdr pointer (2102, size 2616, constants fold to immediates); hdr pointer alone (313);
 *   direct extern access gives ctx r4, hdr r5, -13 r6, 0 r7, 24 r8 (204: listing order) while
 *   the image order is 24, ctx, hdr, -13, 0, so only 24 must be coloured first; local done = 24
 *   in direct form (204, propagated); pragmas opt_loop_invariants, opt_strength_reduction,
 *   opt_dead_code off (202 each). Callee types re-checked: no change. Open question: what makes
 *   the constant 24 the first web (first def before the ctx load).
 *
 * final push 2026-10-05 G9L3: 202 to 26 B. The five prologue webs now colour as the original
 *   (24 r4, ctx r5, hdr r6, -13 r7, 0 r8) once the FIRST header copy (case 2) is
 *   memcpy(&d_021D3EF0, DWCi_EncSessionGetResponse(&len), 2) with the callee returning
 *   const void *. The same colours come from opt_propagation off plus a named Hdr pointer set at
 *   that one site; memcpy at all six sites gives 125 (colours right, but the load of ctx->hdr.code
 *   is then hoisted above the two byte stores at every site); memcpy only at a later site gives
 *   220. Residue 26 B: (1) at that first site the ldrb of ctx->hdr.code (ldrb [r5,#0x1c4]) is
 *   scheduled before the source loads, original has it after the two stores (the store through a
 *   register-held destination does not order against the symbol-based load; the sibling 021C8FA8
 *   fixes it only with a fixed-address ctx, which is not accepted); (2) the shared cancel block
 *   at +0A18 stores state after the sub that derives -12 from 24, the original stores state first.
 *   Tried without gain on the hoist: unsized array and u32 base casts for ctx, inline getter,
 *   inline copyHdr helper, five per-function pragmas (scheduling off has no effect), resp or
 *   Hdr-pointer locals, result stored before state (27). Per-site struct-copy variants at the
 *   first site (resp local, Hdr pointer, field copy, named dest pointer without the pragma): 202
 *   to 207. Header copy as one named hp for all sites under opt_propagation off: 313.
 *   Matched-assembly search for the ldrb/ldrb/strb/strb/ldrb word sequence: only this function.
 *
 * pass 2 2026-10-06 P2L38: EXACT (was 26 B). The context is the global itself, accessed directly
 *   (gDpwTrWork.field everywhere, no Ctx pointer local), and every 2-byte header copy is
 *   memcpy(&gDpwTrWork.hdr, DWCi_EncSessionGetResponse(&len), 2). The member address gives its own
 *   pool word (the d_021D3EF0 label, shared in r6), the memcpy form gives the original colours, and
 *   because the copy and the switch read now name the same object, mwcc keeps the read of
 *   hdr.code after the two byte stores and keeps the cancel block's state store before the -12
 *   (both residues came from a ctx pointer that mwcc resolved to gDpwTrWork while the stores went to
 *   the separate d_021D3EF0 object). With a ctx pointer for the switch read the stored byte is
 *   forwarded (1854 B); with memcpy into &d_021D3EF0 the read is hoisted (26 B).
 *
 * DWC encryption-session poll: a switch on the session state (0..24); every
 * even state 2..22 runs DWCi_EncSessionProcess and on 1 (error) or 8 (done)
 * moves to state 24 and maps the response to a result code; every odd state
 * 3..23 is a cancel (-12).  Real extent 0x021C7C1C..0x021C864C plus three
 * pool words; the listing extent of 2716 bytes also covers the filed leaves
 * 0x021C8658/0x021C866C/0x021C86A8.  d_021D3EF0 is gDpwTrWork + 0x1c4.
 *
 * symbols:
 *   gDpwTrWork                  0x021D3D2C  data  a4
 *   DWCi_EncSessionProcess      0x021CA0A0  arm
 *   DWCi_EncSessionShutdown     0x021CA1B4  arm
 *   DWCi_EncSessionGetResponse  0x021CA228  arm
 *   DWC_GetLastErrorEx          0x02059E38  arm
 *   DPW_TR_ConvertDwcError               0x021C8EB4  arm
 *   func_02092344               0x02092344  arm
 */

#include "../../matched/arm9_sdk/libc/string.h"
typedef unsigned char u8;
typedef unsigned long u32;

typedef struct {
    u8 code;
    u8 sub;
} Hdr;

typedef struct {
    int state;              /* 0x000 */
    int result;             /* 0x004 */
    u8 pad8[0x1c4 - 0x8];
    Hdr hdr;                /* 0x1c4 */
    u8 pad1c6[2];
    u8 *buf;                /* 0x1c8 */
} Ctx;

extern Ctx gDpwTrWork;

extern int DWCi_EncSessionProcess(void);
extern void DWCi_EncSessionShutdown(void);
extern const void *DWCi_EncSessionGetResponse(u32 *len);
extern int DWC_GetLastErrorEx(int *code, int *type);
extern int DPW_TR_ConvertDwcError(unsigned int type);
extern void *func_02092344(void *dst, const void *src, unsigned int n);

void DPW_TR_Main(void)
{
    u32 len;
    int code;
    int type;
    const u8 *resp;

    switch (gDpwTrWork.state) {
    case 2:
        switch (DWCi_EncSessionProcess()) {
        case 1:
            gDpwTrWork.state = 24;
            DWC_GetLastErrorEx(&code, &type);
            gDpwTrWork.result = DPW_TR_ConvertDwcError(type);
            DWCi_EncSessionShutdown();
            return;
        case 8:
            gDpwTrWork.state = 24;
            memcpy(&gDpwTrWork.hdr, DWCi_EncSessionGetResponse(&len), 2);
            switch (gDpwTrWork.hdr.code) {
            case 1: gDpwTrWork.result = 0; break;
            case 2: gDpwTrWork.result = -5; break;
            case 3: gDpwTrWork.result = -4; break;
            case 7: gDpwTrWork.result = -1; break;
            case 12: gDpwTrWork.result = -6; break;
            case 13: gDpwTrWork.result = -7; break;
            case 8: gDpwTrWork.result = -8; break;
            case 9: gDpwTrWork.result = -9; break;
            case 10: gDpwTrWork.result = -10; break;
            case 11: gDpwTrWork.result = -11; break;
            case 14: gDpwTrWork.result = -2; break;
            default: gDpwTrWork.result = -13; break;
            }
            DWCi_EncSessionShutdown();
            return;
        }
        return;
    case 4:
        switch (DWCi_EncSessionProcess()) {
        case 1:
            gDpwTrWork.state = 24;
            DWC_GetLastErrorEx(&code, &type);
            gDpwTrWork.result = DPW_TR_ConvertDwcError(type);
            DWCi_EncSessionShutdown();
            return;
        case 8:
            gDpwTrWork.state = 24;
            memcpy(&gDpwTrWork.hdr, DWCi_EncSessionGetResponse(&len), 2);
            switch (gDpwTrWork.hdr.code) {
            case 1: gDpwTrWork.result = 0; break;
            case 2: gDpwTrWork.result = -5; break;
            case 3: gDpwTrWork.result = -4; break;
            case 5: gDpwTrWork.result = -3; break;
            case 14: gDpwTrWork.result = -2; break;
            default: gDpwTrWork.result = -13; break;
            }
            DWCi_EncSessionShutdown();
            return;
        }
        return;
    case 6:
        switch (DWCi_EncSessionProcess()) {
        case 1:
            gDpwTrWork.state = 24;
            DWC_GetLastErrorEx(&code, &type);
            gDpwTrWork.result = DPW_TR_ConvertDwcError(type);
            DWCi_EncSessionShutdown();
            return;
        case 8:
            gDpwTrWork.state = 24;
            resp = (const u8 *)DWCi_EncSessionGetResponse(&len);
            func_02092344(gDpwTrWork.buf, resp, 0x128);
            if (len == 0x128) {
                gDpwTrWork.result = 0;
            } else {
                switch (gDpwTrWork.buf[0]) {
                case 5: gDpwTrWork.result = -3; break;
                case 3: gDpwTrWork.result = -4; break;
                case 14: gDpwTrWork.result = -2; break;
                default: gDpwTrWork.result = -13; break;
                }
            }
            DWCi_EncSessionShutdown();
            return;
        }
        return;
    case 8:
        switch (DWCi_EncSessionProcess()) {
        case 1:
            gDpwTrWork.state = 24;
            DWC_GetLastErrorEx(&code, &type);
            gDpwTrWork.result = DPW_TR_ConvertDwcError(type);
            DWCi_EncSessionShutdown();
            return;
        case 8:
            gDpwTrWork.state = 24;
            resp = (const u8 *)DWCi_EncSessionGetResponse(&len);
            func_02092344(gDpwTrWork.buf, resp, 0x128);
            if (len == 0x128) {
                gDpwTrWork.result = 1;
            } else {
                switch (gDpwTrWork.buf[0]) {
                case 5: gDpwTrWork.result = -3; break;
                case 3: gDpwTrWork.result = -4; break;
                case 4: gDpwTrWork.result = 0; break;
                case 14: gDpwTrWork.result = -2; break;
                default: gDpwTrWork.result = -13; break;
                }
            }
            DWCi_EncSessionShutdown();
            return;
        }
        return;
    case 10:
        switch (DWCi_EncSessionProcess()) {
        case 1:
            gDpwTrWork.state = 24;
            DWC_GetLastErrorEx(&code, &type);
            gDpwTrWork.result = DPW_TR_ConvertDwcError(type);
            DWCi_EncSessionShutdown();
            return;
        case 8:
            gDpwTrWork.state = 24;
            memcpy(&gDpwTrWork.hdr, DWCi_EncSessionGetResponse(&len), 2);
            switch (gDpwTrWork.hdr.code) {
            case 1: gDpwTrWork.result = 0; break;
            case 5: gDpwTrWork.result = -3; break;
            case 3: gDpwTrWork.result = -4; break;
            case 14: gDpwTrWork.result = -2; break;
            default: gDpwTrWork.result = -13; break;
            }
            DWCi_EncSessionShutdown();
            return;
        }
        return;
    case 12:
        switch (DWCi_EncSessionProcess()) {
        case 1:
            gDpwTrWork.state = 24;
            DWC_GetLastErrorEx(&code, &type);
            gDpwTrWork.result = DPW_TR_ConvertDwcError(type);
            DWCi_EncSessionShutdown();
            return;
        case 8:
            gDpwTrWork.state = 24;
            memcpy(&gDpwTrWork.hdr, DWCi_EncSessionGetResponse(&len), 2);
            switch (gDpwTrWork.hdr.code) {
            case 1: gDpwTrWork.result = 0; break;
            case 5: gDpwTrWork.result = -3; break;
            case 2: gDpwTrWork.result = -5; break;
            case 3: gDpwTrWork.result = -4; break;
            case 14: gDpwTrWork.result = -2; break;
            default: gDpwTrWork.result = -13; break;
            }
            DWCi_EncSessionShutdown();
            return;
        }
        return;
    case 14:
        switch (DWCi_EncSessionProcess()) {
        case 1:
            gDpwTrWork.state = 24;
            DWC_GetLastErrorEx(&code, &type);
            gDpwTrWork.result = DPW_TR_ConvertDwcError(type);
            DWCi_EncSessionShutdown();
            return;
        case 8:
            gDpwTrWork.state = 24;
            resp = (const u8 *)DWCi_EncSessionGetResponse(&len);
            *(Hdr *)gDpwTrWork.buf = *(Hdr *)resp;
            switch (gDpwTrWork.buf[0]) {
            case 1:
                if (len - 2 >= 0x128) {
                    gDpwTrWork.result = (len - 2) / 0x128;
                    func_02092344(gDpwTrWork.buf, resp + 2, len - 2);
                } else if (len == 2) {
                    gDpwTrWork.result = 0;
                }
                break;
            case 14: gDpwTrWork.result = -2; break;
            default: gDpwTrWork.result = -13; break;
            }
            DWCi_EncSessionShutdown();
            return;
        }
        return;
    case 16:
        switch (DWCi_EncSessionProcess()) {
        case 1:
            gDpwTrWork.state = 24;
            DWC_GetLastErrorEx(&code, &type);
            gDpwTrWork.result = DPW_TR_ConvertDwcError(type);
            DWCi_EncSessionShutdown();
            return;
        case 8:
            gDpwTrWork.state = 24;
            resp = (const u8 *)DWCi_EncSessionGetResponse(&len);
            func_02092344(gDpwTrWork.buf, resp, 0x128);
            if (len == 0x128) {
                gDpwTrWork.result = 0;
            } else {
                switch (gDpwTrWork.buf[0]) {
                case 2: gDpwTrWork.result = -5; break;
                case 12: gDpwTrWork.result = -6; break;
                case 13: gDpwTrWork.result = -7; break;
                case 8: gDpwTrWork.result = -8; break;
                case 9: gDpwTrWork.result = -9; break;
                case 10: gDpwTrWork.result = -10; break;
                case 11: gDpwTrWork.result = -11; break;
                case 14: gDpwTrWork.result = -2; break;
                default: gDpwTrWork.result = -13; break;
                }
            }
            DWCi_EncSessionShutdown();
            return;
        }
        return;
    case 18:
        switch (DWCi_EncSessionProcess()) {
        case 1:
            gDpwTrWork.state = 24;
            DWC_GetLastErrorEx(&code, &type);
            gDpwTrWork.result = DPW_TR_ConvertDwcError(type);
            DWCi_EncSessionShutdown();
            return;
        case 8:
            gDpwTrWork.state = 24;
            memcpy(&gDpwTrWork.hdr, DWCi_EncSessionGetResponse(&len), 2);
            switch (gDpwTrWork.hdr.code) {
            case 1: gDpwTrWork.result = 0; break;
            case 2: gDpwTrWork.result = -5; break;
            case 14: gDpwTrWork.result = -2; break;
            }
            DWCi_EncSessionShutdown();
            return;
        }
        return;
    case 20:
        switch (DWCi_EncSessionProcess()) {
        case 1:
            gDpwTrWork.state = 24;
            DWC_GetLastErrorEx(&code, &type);
            gDpwTrWork.result = DPW_TR_ConvertDwcError(type);
            DWCi_EncSessionShutdown();
            return;
        case 8:
            gDpwTrWork.state = 24;
            memcpy(&gDpwTrWork.hdr, DWCi_EncSessionGetResponse(&len), 2);
            switch (gDpwTrWork.hdr.code) {
            case 1: gDpwTrWork.result = 0; break;
            case 6: gDpwTrWork.result = 1; break;
            case 7: gDpwTrWork.result = 2; break;
            case 14: gDpwTrWork.result = -2; break;
            default: gDpwTrWork.result = -13; break;
            }
            DWCi_EncSessionShutdown();
            return;
        }
        return;
    case 22:
        switch (DWCi_EncSessionProcess()) {
        case 1:
            gDpwTrWork.state = 24;
            DWC_GetLastErrorEx(&code, &type);
            gDpwTrWork.result = DPW_TR_ConvertDwcError(type);
            DWCi_EncSessionShutdown();
            return;
        case 8:
            gDpwTrWork.state = 24;
            resp = (const u8 *)DWCi_EncSessionGetResponse(&len);
            *(Hdr *)gDpwTrWork.buf = *(Hdr *)resp;
            if (len == 8) {
                gDpwTrWork.result = 0;
            } else {
                switch (gDpwTrWork.buf[0]) {
                case 1: gDpwTrWork.result = 0; break;
                case 6: gDpwTrWork.result = 1; break;
                case 7: gDpwTrWork.result = 2; break;
                case 14: gDpwTrWork.result = -2; break;
                default: gDpwTrWork.result = -13; break;
                }
            }
            DWCi_EncSessionShutdown();
            return;
        }
        return;
    case 3:
    case 5:
    case 7:
    case 9:
    case 11:
    case 13:
    case 15:
    case 17:
    case 19:
    case 21:
    case 23:
        gDpwTrWork.state = 24;
        gDpwTrWork.result = -12;
        DWCi_EncSessionShutdown();
        return;
    case 0:
    case 1:
    case 24:
        break;
    }
}

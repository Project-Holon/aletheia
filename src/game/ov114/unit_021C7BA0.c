/*
 * file:     unit_021C7BA0.c
 * unit:     yes
 * function: func_021C7BA0, func_021C7C1C, func_021C8658, func_021C866C, func_021C86A8, func_021C86B8, func_021C8770, func_021C87FC, func_021C887C, func_021C88FC, func_021C8978, func_021C89F0, func_021C8B18, func_021C8BC4, func_021C8C68, func_021C8D14, func_021C8DA0, func_021C8E18, func_021C8EB4, func_021C8F2C, func_021C8FA8, func_021C93BC, func_021C93D0
 * address:  0x021C7BA0
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021D3D2C                  0x021D3D2C  data  a4
 *   DWCi_EncSessionProcess      0x021CA0A0  arm
 *   DWCi_EncSessionShutdown     0x021CA1B4  arm
 *   DWCi_EncSessionGetResponse  0x021CA228  arm
 *   DWC_GetLastErrorEx          0x02059E38  arm
 *   func_02092344               0x02092344  arm
 *   d_021D3D28   0x021D3D28  data  a4
 *   d_021CF538   0x021CF538  data  a4
 *   d_021CF5B8   0x021CF5B8  data  a4
 *   d_021D3D40   0x021D3D40  data  a4
 *   func_021C9EE4 0x021C9EE4  arm
 *   func_021CA470 0x021CA470  arm
 *   func_021CA1B4 0x021CA1B4  arm
 *   d_021CF5D4   0x021CF5D4  data  a4
 *   func_021CA188  0x021CA188  arm  ov114
 *   g_021D3D2C     0x021D3D2C  data ov114 a4
 *   d_021CF634   0x021CF634  data  a4
 *   d_021D3E6C 0x021D3E6C data a4
 *   d_021CF654 0x021CF654 data a4
 *   d_021D3D38 0x021D3D38 data a4
 *   d_021CF674 0x021CF674 data a4
 *   d_021CF69C 0x021CF69C data a4
 *   d_021CF6B8 0x021CF6B8 data a4
 *   func_02087C6C 0x02087C6C arm
 *   DWC_UpdateConnection  0x0205D074  arm
 *   DWC_ClearError        0x02059F18  arm
 *   d_021D4084 0x021D4084 data a4
 *   d_021D3EFC 0x021D3EFC data a4
 *   func_021C97E0 0x021C97E0 arm ov114
 *   d_021CF594 0x021CF594 data a4
 *   d_021CF5F4 0x021CF5F4 data a4
 *   d_021CF614 0x021CF614 data a4
 *   d_021CF578                       0x021CF578  data  a4
 */
#include "../../matched/arm9_sdk/libc/string.h"
#include "../../matched/include/G_Six.h"
#include "../../matched/include/G_Six.h"
#include "../../matched/arm9_sdk/libc/string.h"

typedef struct {
    unsigned char code;
    unsigned char sub;
} Hdr;

typedef struct {
    int state;                          /* 0x000 */
    int result;                         /* 0x004 */
    unsigned int id;                    /* 0x008 */
    unsigned int arg0;                  /* 0x00c */
    unsigned int arg1;                  /* 0x010 */
    unsigned char pad14[4];
    unsigned char pad18[2];
    unsigned char byte;                 /* 0x01a */
    unsigned char pad1b[0x13c - 0x1b];
    unsigned int a;                     /* 0x13c */
    unsigned int pad140[0x20];
    unsigned int count;                 /* 0x1c0 */
    Hdr hdr;                            /* 0x1c4 */
    unsigned char pad1c6[2];
    unsigned char *buf;                 /* 0x1c8 */
} State;

typedef unsigned char u8;

typedef struct { u8 a,b,c,d,e,f; } Six;

typedef unsigned int u32;

typedef enum { STATE_IDLE = 0, STATE_END = 12 } EncState;

typedef struct {
    EncState state;
    int result;
    unsigned int id;
    unsigned int arg0;
    unsigned int arg1;
    unsigned char pad14[0x198 - 0x14];
    Hdr hdr;
    unsigned char pad19a[2];
    unsigned char *buf;
} Ctx4084;

typedef struct { Hdr h[4]; } Payload;

extern int DWCi_EncSessionProcess(void);
extern void DWCi_EncSessionShutdown(void);
extern const void *DWCi_EncSessionGetResponse(u32 *len);
extern int DWC_GetLastErrorEx(int *code, int *type);
extern void *func_02092344(void *dst, const void *src, unsigned int n);
extern void func_021C9EE4(int server, char *initdata);
extern int func_021CA470(void *, unsigned int, void *, unsigned int, unsigned int);
extern void func_021CA1B4(void);
extern void func_021CA188(void);
extern void func_02087C6C(void *);
extern int DWC_UpdateConnection(void);
extern void DWC_ClearError(void);
extern int func_021C97E0(unsigned);
void func_021C7BA0(unsigned int a, unsigned int b, unsigned int c, int d);
void func_021C7C1C(void);
void EXT_TestResetCounter(void);
int func_021C866C(void);
int func_021C86A8(void);
void func_021C86B8(const void *a, const void *b, int c);
void func_021C8770(void);
void func_021C87FC(unsigned int x);
void func_021C887C(unsigned int x);
void func_021C88FC(void);
void func_021C8978(void);
void func_021C89F0(void);
void func_021C8B18(const Six *p, int x, unsigned int y);
void func_021C8BC4(const void *p, unsigned int x);
void func_021C8C68(unsigned a, const void *p, unsigned c, const void *q, unsigned n);
void func_021C8D14(void);
void func_021C8DA0(void);
void func_021C8E18(unsigned char *p, unsigned x);
int func_021C8EB4(u32 type);
void func_021C8F2C(unsigned a, unsigned b, unsigned c, unsigned mode);
void func_021C8FA8(void);
int func_021C93D0(void);
extern State d_021D3D2C;
extern int d_021D3D28;
extern unsigned int d_021D3D40[];
extern unsigned int d_021CF538[];
extern unsigned int d_021D3E6C[], d_021CF578[];
extern const unsigned int d_021D3D38[];
extern unsigned int d_021CF594[];
extern unsigned int d_021CF5B8[];
extern unsigned int d_021CF5D4[];
extern unsigned int d_021CF538[], d_021CF5F4[];
extern unsigned int d_021CF538[], d_021CF614[];
extern unsigned int d_021CF538[], d_021CF634[];
extern unsigned d_021D3E6C[], d_021CF538[], d_021CF654[];
extern unsigned d_021CF538[], d_021CF674[];
extern unsigned d_021CF538[], d_021CF69C[];
extern unsigned d_021CF538[], d_021CF6B8[];
extern Ctx4084 d_021D4084;
extern unsigned d_021D3EFC;











/*
 * d_021D3D2C 0x021D3D2C data a4
 * d_021D3D28 0x021D3D28 data a4
 */
void func_021C7BA0(unsigned int a, unsigned int b, unsigned int c, int d)
{
    d_021D3D2C.state = 1;
    d_021D3D2C.result = 0;
    d_021D3D2C.id = a;
    d_021D3D2C.arg0 = b;
    d_021D3D2C.arg1 = c;
    switch (d) {
    case 0: d_021D3D28 = 0; break;
    case 1: d_021D3D28 = 1; break;
    case 2: d_021D3D28 = 2; break;
    default: d_021D3D28 = 1; break;
    }
}











/*
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
 *   (d_021D3D2C.field everywhere, no Ctx pointer local), and every 2-byte header copy is
 *   memcpy(&d_021D3D2C.hdr, DWCi_EncSessionGetResponse(&len), 2). The member address gives its own
 *   pool word (the d_021D3EF0 label, shared in r6), the memcpy form gives the original colours, and
 *   because the copy and the switch read now name the same object, mwcc keeps the read of
 *   hdr.code after the two byte stores and keeps the cancel block's state store before the -12
 *   (both residues came from a ctx pointer that mwcc resolved to d_021D3D2C while the stores went to
 *   the separate d_021D3EF0 object). With a ctx pointer for the switch read the stored byte is
 *   forwarded (1854 B); with memcpy into &d_021D3EF0 the read is hoisted (26 B).
 *
 * DWC encryption-session poll: a switch on the session state (0..24); every
 * even state 2..22 runs DWCi_EncSessionProcess and on 1 (error) or 8 (done)
 * moves to state 24 and maps the response to a result code; every odd state
 * 3..23 is a cancel (-12).  Real extent 0x021C7C1C..0x021C864C plus three
 * pool words; the listing extent of 2716 bytes also covers the filed leaves
 * 0x021C8658/0x021C866C/0x021C86A8.  d_021D3EF0 is d_021D3D2C + 0x1c4.
 */
void func_021C7C1C(void)
{
    u32 len;
    int code;
    int type;
    const u8 *resp;

    switch (d_021D3D2C.state) {
    case 2:
        switch (DWCi_EncSessionProcess()) {
        case 1:
            d_021D3D2C.state = 24;
            DWC_GetLastErrorEx(&code, &type);
            d_021D3D2C.result = func_021C8EB4(type);
            DWCi_EncSessionShutdown();
            return;
        case 8:
            d_021D3D2C.state = 24;
            memcpy(&d_021D3D2C.hdr, DWCi_EncSessionGetResponse(&len), 2);
            switch (d_021D3D2C.hdr.code) {
            case 1: d_021D3D2C.result = 0; break;
            case 2: d_021D3D2C.result = -5; break;
            case 3: d_021D3D2C.result = -4; break;
            case 7: d_021D3D2C.result = -1; break;
            case 12: d_021D3D2C.result = -6; break;
            case 13: d_021D3D2C.result = -7; break;
            case 8: d_021D3D2C.result = -8; break;
            case 9: d_021D3D2C.result = -9; break;
            case 10: d_021D3D2C.result = -10; break;
            case 11: d_021D3D2C.result = -11; break;
            case 14: d_021D3D2C.result = -2; break;
            default: d_021D3D2C.result = -13; break;
            }
            DWCi_EncSessionShutdown();
            return;
        }
        return;
    case 4:
        switch (DWCi_EncSessionProcess()) {
        case 1:
            d_021D3D2C.state = 24;
            DWC_GetLastErrorEx(&code, &type);
            d_021D3D2C.result = func_021C8EB4(type);
            DWCi_EncSessionShutdown();
            return;
        case 8:
            d_021D3D2C.state = 24;
            memcpy(&d_021D3D2C.hdr, DWCi_EncSessionGetResponse(&len), 2);
            switch (d_021D3D2C.hdr.code) {
            case 1: d_021D3D2C.result = 0; break;
            case 2: d_021D3D2C.result = -5; break;
            case 3: d_021D3D2C.result = -4; break;
            case 5: d_021D3D2C.result = -3; break;
            case 14: d_021D3D2C.result = -2; break;
            default: d_021D3D2C.result = -13; break;
            }
            DWCi_EncSessionShutdown();
            return;
        }
        return;
    case 6:
        switch (DWCi_EncSessionProcess()) {
        case 1:
            d_021D3D2C.state = 24;
            DWC_GetLastErrorEx(&code, &type);
            d_021D3D2C.result = func_021C8EB4(type);
            DWCi_EncSessionShutdown();
            return;
        case 8:
            d_021D3D2C.state = 24;
            resp = (const u8 *)DWCi_EncSessionGetResponse(&len);
            func_02092344(d_021D3D2C.buf, resp, 0x128);
            if (len == 0x128) {
                d_021D3D2C.result = 0;
            } else {
                switch (d_021D3D2C.buf[0]) {
                case 5: d_021D3D2C.result = -3; break;
                case 3: d_021D3D2C.result = -4; break;
                case 14: d_021D3D2C.result = -2; break;
                default: d_021D3D2C.result = -13; break;
                }
            }
            DWCi_EncSessionShutdown();
            return;
        }
        return;
    case 8:
        switch (DWCi_EncSessionProcess()) {
        case 1:
            d_021D3D2C.state = 24;
            DWC_GetLastErrorEx(&code, &type);
            d_021D3D2C.result = func_021C8EB4(type);
            DWCi_EncSessionShutdown();
            return;
        case 8:
            d_021D3D2C.state = 24;
            resp = (const u8 *)DWCi_EncSessionGetResponse(&len);
            func_02092344(d_021D3D2C.buf, resp, 0x128);
            if (len == 0x128) {
                d_021D3D2C.result = 1;
            } else {
                switch (d_021D3D2C.buf[0]) {
                case 5: d_021D3D2C.result = -3; break;
                case 3: d_021D3D2C.result = -4; break;
                case 4: d_021D3D2C.result = 0; break;
                case 14: d_021D3D2C.result = -2; break;
                default: d_021D3D2C.result = -13; break;
                }
            }
            DWCi_EncSessionShutdown();
            return;
        }
        return;
    case 10:
        switch (DWCi_EncSessionProcess()) {
        case 1:
            d_021D3D2C.state = 24;
            DWC_GetLastErrorEx(&code, &type);
            d_021D3D2C.result = func_021C8EB4(type);
            DWCi_EncSessionShutdown();
            return;
        case 8:
            d_021D3D2C.state = 24;
            memcpy(&d_021D3D2C.hdr, DWCi_EncSessionGetResponse(&len), 2);
            switch (d_021D3D2C.hdr.code) {
            case 1: d_021D3D2C.result = 0; break;
            case 5: d_021D3D2C.result = -3; break;
            case 3: d_021D3D2C.result = -4; break;
            case 14: d_021D3D2C.result = -2; break;
            default: d_021D3D2C.result = -13; break;
            }
            DWCi_EncSessionShutdown();
            return;
        }
        return;
    case 12:
        switch (DWCi_EncSessionProcess()) {
        case 1:
            d_021D3D2C.state = 24;
            DWC_GetLastErrorEx(&code, &type);
            d_021D3D2C.result = func_021C8EB4(type);
            DWCi_EncSessionShutdown();
            return;
        case 8:
            d_021D3D2C.state = 24;
            memcpy(&d_021D3D2C.hdr, DWCi_EncSessionGetResponse(&len), 2);
            switch (d_021D3D2C.hdr.code) {
            case 1: d_021D3D2C.result = 0; break;
            case 5: d_021D3D2C.result = -3; break;
            case 2: d_021D3D2C.result = -5; break;
            case 3: d_021D3D2C.result = -4; break;
            case 14: d_021D3D2C.result = -2; break;
            default: d_021D3D2C.result = -13; break;
            }
            DWCi_EncSessionShutdown();
            return;
        }
        return;
    case 14:
        switch (DWCi_EncSessionProcess()) {
        case 1:
            d_021D3D2C.state = 24;
            DWC_GetLastErrorEx(&code, &type);
            d_021D3D2C.result = func_021C8EB4(type);
            DWCi_EncSessionShutdown();
            return;
        case 8:
            d_021D3D2C.state = 24;
            resp = (const u8 *)DWCi_EncSessionGetResponse(&len);
            *(Hdr *)d_021D3D2C.buf = *(Hdr *)resp;
            switch (d_021D3D2C.buf[0]) {
            case 1:
                if (len - 2 >= 0x128) {
                    d_021D3D2C.result = (len - 2) / 0x128;
                    func_02092344(d_021D3D2C.buf, resp + 2, len - 2);
                } else if (len == 2) {
                    d_021D3D2C.result = 0;
                }
                break;
            case 14: d_021D3D2C.result = -2; break;
            default: d_021D3D2C.result = -13; break;
            }
            DWCi_EncSessionShutdown();
            return;
        }
        return;
    case 16:
        switch (DWCi_EncSessionProcess()) {
        case 1:
            d_021D3D2C.state = 24;
            DWC_GetLastErrorEx(&code, &type);
            d_021D3D2C.result = func_021C8EB4(type);
            DWCi_EncSessionShutdown();
            return;
        case 8:
            d_021D3D2C.state = 24;
            resp = (const u8 *)DWCi_EncSessionGetResponse(&len);
            func_02092344(d_021D3D2C.buf, resp, 0x128);
            if (len == 0x128) {
                d_021D3D2C.result = 0;
            } else {
                switch (d_021D3D2C.buf[0]) {
                case 2: d_021D3D2C.result = -5; break;
                case 12: d_021D3D2C.result = -6; break;
                case 13: d_021D3D2C.result = -7; break;
                case 8: d_021D3D2C.result = -8; break;
                case 9: d_021D3D2C.result = -9; break;
                case 10: d_021D3D2C.result = -10; break;
                case 11: d_021D3D2C.result = -11; break;
                case 14: d_021D3D2C.result = -2; break;
                default: d_021D3D2C.result = -13; break;
                }
            }
            DWCi_EncSessionShutdown();
            return;
        }
        return;
    case 18:
        switch (DWCi_EncSessionProcess()) {
        case 1:
            d_021D3D2C.state = 24;
            DWC_GetLastErrorEx(&code, &type);
            d_021D3D2C.result = func_021C8EB4(type);
            DWCi_EncSessionShutdown();
            return;
        case 8:
            d_021D3D2C.state = 24;
            memcpy(&d_021D3D2C.hdr, DWCi_EncSessionGetResponse(&len), 2);
            switch (d_021D3D2C.hdr.code) {
            case 1: d_021D3D2C.result = 0; break;
            case 2: d_021D3D2C.result = -5; break;
            case 14: d_021D3D2C.result = -2; break;
            }
            DWCi_EncSessionShutdown();
            return;
        }
        return;
    case 20:
        switch (DWCi_EncSessionProcess()) {
        case 1:
            d_021D3D2C.state = 24;
            DWC_GetLastErrorEx(&code, &type);
            d_021D3D2C.result = func_021C8EB4(type);
            DWCi_EncSessionShutdown();
            return;
        case 8:
            d_021D3D2C.state = 24;
            memcpy(&d_021D3D2C.hdr, DWCi_EncSessionGetResponse(&len), 2);
            switch (d_021D3D2C.hdr.code) {
            case 1: d_021D3D2C.result = 0; break;
            case 6: d_021D3D2C.result = 1; break;
            case 7: d_021D3D2C.result = 2; break;
            case 14: d_021D3D2C.result = -2; break;
            default: d_021D3D2C.result = -13; break;
            }
            DWCi_EncSessionShutdown();
            return;
        }
        return;
    case 22:
        switch (DWCi_EncSessionProcess()) {
        case 1:
            d_021D3D2C.state = 24;
            DWC_GetLastErrorEx(&code, &type);
            d_021D3D2C.result = func_021C8EB4(type);
            DWCi_EncSessionShutdown();
            return;
        case 8:
            d_021D3D2C.state = 24;
            resp = (const u8 *)DWCi_EncSessionGetResponse(&len);
            *(Hdr *)d_021D3D2C.buf = *(Hdr *)resp;
            if (len == 8) {
                d_021D3D2C.result = 0;
            } else {
                switch (d_021D3D2C.buf[0]) {
                case 1: d_021D3D2C.result = 0; break;
                case 6: d_021D3D2C.result = 1; break;
                case 7: d_021D3D2C.result = 2; break;
                case 14: d_021D3D2C.result = -2; break;
                default: d_021D3D2C.result = -13; break;
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
        d_021D3D2C.state = 24;
        d_021D3D2C.result = -12;
        DWCi_EncSessionShutdown();
        return;
    case 0:
    case 1:
    case 24:
        break;
    }
}











void EXT_TestResetCounter(void)
{
    d_021D3D2C.state = 0;
}











/*
 * Unlabelled ARM leaf in a .word run (disasm.py only labels lr-saving
 * prologues).  Extent 0x021C866C..0x021C86A8 (60 bytes) read from the ov114
 * listing: 14 instructions plus one pool word naming d_021D3D2C.
 */
int func_021C866C(void)
{
    switch (d_021D3D2C.state) {
    case 1:
        return 1;
    case 0x18:
        d_021D3D2C.state = 1;
        return 1;
    }
    return 0;
}











/*
 * Unlabelled ARM leaf in a .word run.  Extent 0x021C86A8..0x021C86B8
 * (16 bytes): ldr/ldr/bx plus one pool word naming d_021D3D2C.
 */
int func_021C86A8(void)
{
    return d_021D3D2C.result;
}








void func_021C86B8(const void *a, const void *b, int c)
{
    func_02092344(d_021D3D40, a, 0x128);
    d_021D3D2C.a = 0;
    func_02092344(d_021D3E6C, b, c);
    d_021D3D2C.count = c;
    func_021C9EE4(d_021D3D28, (char *)d_021CF538);
    if (func_021CA470(d_021CF578, d_021D3D2C.id, d_021D3D40, 0x1b0, 0) == 0) {
        d_021D3D2C.state = 2;
        return;
    }
    d_021D3D2C.state = 24;
    d_021D3D2C.result = -13;
    func_021CA1B4();
}










/*
 * closed 2026-10-05 (integrator): the pair copy is memcpy(d_021D3D40, d_021D3D38, 8), the form that closed the sibling ov114 021C8D14 (lane G2L9).
 * residual: 8 concrete bytes, first copy/store scheduling; original best restored.
 * retry: wave24 R1, 3 targeted changes (bound object, const global pointer,
 *   typed destination Pair) did not shrink 8; one --budget 300 --types
 *   permuter compiled 300 candidates and found no improvement. Do not rerun.
 * stale-note 2026-10-05: ov_sdk func_021CA470 now returns int (calls func_021CA240), so the void-return blocker below no longer holds.
 * owner-blocker (stale): the integrator SDK ov114 0x021CA470; matched ov_sdk definition
 *   void func_021CA470(int,int,int,int,int) conflicts with caller return use.
 *   021C87B8: bl 021CA470; 021C87BC: cmp r0,#0.
 *   021CA488: bl 021CA240; 021CA48C: add sp,sp,#8; 021CA490: pop {r3,pc}
 *   preserve r0 from SDK 021CA240's int return. Definition remains untouched.
 *   The C below is the historically compiled recovery sketch, not eligible
 *   for a new caller retry until the owner's prototype is corrected.
 * renewed-pass: wave77 R11; signed copy, own Initialize ABI and inline copy all retained 140/8; consumed prior permuter retained.
 * checks: 1 own SDK definitions audited 2/5/0, void-return discrepancy above stops matching; 2 live 87FC/8C68/8DA0 twins reread, their declarations also predate SDK definitions; 3 signed copy and integer server ABI unchanged 8; further checks stopped at SDK owner blocker; 4 scheduling/global-base/aggregate-copy idioms read; 5 unfiltered idiom directory refreshed and neighbours reread, no stack aggregate in best C.
 * recoup 2026-10-05 (P17L1, 21 compiles): residue unchanged at 8 B: original loads r0=[d28], pool r1 BEFORE the two stores of the pair copy; ours stores r3 first.
 *   Tried, all 8 B or worse: Pair struct copy via cast (8), Pair with address-of (21, pool order moves), u64 copy (98, ldm/stm), early srv local (8),
 *   srv local + struct copy (8), const pointer var and const pointee on d28 (8), const source d38 (8), int/char* prototypes as in matched 87FC/8C68 (8),
 *   named dst/src pointer locals (8), loads into locals then stores with srv read between (8), six per-function pragmas (all 8).
 *   Idioms: an-eight-byte-pair-copy-loads-both-words-first, a-two-word-copy-between-different-bases-is-a-struct-assignment,
 *   a-load-scheduled-above-an-unrelated-store-reads-through-a-const-pointer, a-const-source-pointer-hoists-the-last-load-of-a-struct-copy (no change).
 * d_021D3D28 0x021D3D28 data a4
 * d_021D3D2C 0x021D3D2C data a4
 * d_021CF538 0x021CF538 data a4
 * d_021D3D40 0x021D3D40 data a4
 * func_021C9EE4 0x021C9EE4 arm ov114
 * func_021CA470 0x021CA470 arm ov114
 * func_021CA1B4 0x021CA1B4 arm ov114
 * d_021D3D38 0x021D3D38 data a4
 * d_021CF594 0x021CF594 data a4
 */
void func_021C8770(void)
{
    memcpy(d_021D3D40, d_021D3D38, 8);
    func_021C9EE4(d_021D3D28, (char *)d_021CF538);
    if (func_021CA470(d_021CF594, d_021D3D2C.id, d_021D3D40, 8, 0) == 0) {
        d_021D3D2C.state = 4;
        return;
    }
    d_021D3D2C.state = 24;
    d_021D3D2C.result = -13;
    func_021CA1B4();
}











/*
 * symbol overlay hints are deliberately omitted: `d_021D3D40` lives in
 * overlapping bss, and naming ov114 explicitly makes the hint contested,
 * while leaving it off lets the function's own region disambiguate.
 */
void func_021C87FC(unsigned int x)
{
    d_021D3D2C.buf = (unsigned char *)x;
    func_021C9EE4(d_021D3D28, (char *)d_021CF538);
    if (func_021CA470(d_021CF5B8, d_021D3D2C.id, d_021D3D40, 0x1b0, 0) == 0) {
        d_021D3D2C.state = 6;
        return;
    }
    d_021D3D2C.state = 0x18;
    d_021D3D2C.result = -0x0d;
    func_021CA1B4();
}











/*
 * Twin of func_021C87FC: same shape, a different packet-descriptor
 * constant (d_021CF5D4) and a success code of 8 instead of 6.  Overlay
 * hints omitted for the same overlapping-bss reason.
 */
void func_021C887C(unsigned int x)
{
    d_021D3D2C.buf = (unsigned char *)x;
    func_021C9EE4(d_021D3D28, (char *)d_021CF538);
    if (func_021CA470(d_021CF5D4, d_021D3D2C.id, d_021D3D40, 0x1b0, 0) == 0) {
        d_021D3D2C.state = 8;
        return;
    }
    d_021D3D2C.state = 0x18;
    d_021D3D2C.result = -0x0d;
    func_021CA1B4();
}










/*
 * d_021D3D28 0x021D3D28 data a4
 * d_021D3D2C 0x021D3D2C data a4
 * d_021CF538 0x021CF538 data a4
 * d_021CF5F4 0x021CF5F4 data a4
 * d_021D3D40 0x021D3D40 data a4
 * func_021C9EE4 0x021C9EE4 arm ov114
 * func_021CA470 0x021CA470 arm ov114
 * func_021CA1B4 0x021CA1B4 arm ov114
 */
void func_021C88FC(void)
{
    func_021C9EE4(d_021D3D28, (char *)d_021CF538);
    if (func_021CA470(d_021CF5F4, d_021D3D2C.id, d_021D3D40, 0x1b0, 0) == 0) {
        d_021D3D2C.state = 10;
        return;
    }
    d_021D3D2C.state = 0x18;
    d_021D3D2C.result = -13;
    func_021CA1B4();
}










/*
 * d_021D3D28 0x021D3D28 data a4
 * d_021D3D2C 0x021D3D2C data a4
 * d_021CF538 0x021CF538 data a4
 * d_021CF614 0x021CF614 data a4
 * d_021D3D40 0x021D3D40 data a4
 * func_021C9EE4 0x021C9EE4 arm ov114
 * func_021CA470 0x021CA470 arm ov114
 * func_021CA1B4 0x021CA1B4 arm ov114
 */
void func_021C8978(void)
{
    func_021C9EE4(d_021D3D28, (char *)d_021CF538);
    if (func_021CA470(d_021CF614, d_021D3D2C.id, d_021D3D40, 0, 0) == 0) {
        d_021D3D2C.state = 12;
        return;
    }
    d_021D3D2C.state = 0x18;
    d_021D3D2C.result = -13;
    func_021CA1B4();
}









/*
 * A dispatch tracker: the global 0x021D3D2C holds an even step id; each even
 * case runs the shared handler func_021CA188 and advances the id by one.
 * func_021CA188 is resolved by the sdk class; the global by sole-ref.
 */
void func_021C89F0(void)
{
    switch (d_021D3D2C.state) {
    case 2:  func_021CA188(); d_021D3D2C.state = 3;  break;
    case 4:  func_021CA188(); d_021D3D2C.state = 5;  break;
    case 6:  func_021CA188(); d_021D3D2C.state = 7;  break;
    case 8:  func_021CA188(); d_021D3D2C.state = 9;  break;
    case 10: func_021CA188(); d_021D3D2C.state = 11; break;
    case 12: func_021CA188(); d_021D3D2C.state = 13; break;
    case 14: func_021CA188(); d_021D3D2C.state = 15; break;
    case 16: func_021CA188(); d_021D3D2C.state = 17; break;
    case 18: func_021CA188(); d_021D3D2C.state = 19; break;
    case 20: func_021CA188(); d_021D3D2C.state = 21; break;
    case 22: func_021CA188(); d_021D3D2C.state = 23; break;
    }
}






#pragma opt_propagation off






/*
 * residual: 16 concrete bytes, first pool base load (state) is delayed after the six byte loads
 * owner-blocker: the integrator SDK ov114 0x021CA470; matched ov_sdk definition
 *   void func_021CA470(int,int,int,int,int) conflicts with caller return use.
 *   021C8B84: bl 021CA470; 021C8B88: cmp r0,#0.
 *   021CA488: bl 021CA240; 021CA48C: add sp,sp,#8; 021CA490: pop {r3,pc}
 *   preserve r0 from SDK 021CA240's int return. Definition remains untouched.
 *   The C below is the historically compiled recovery sketch, not eligible
 *   for a new caller retry until the owner's prototype is corrected.
 * renewed-pass: wave77 R11; signed six-byte locals 30, local state 50, long state 30; u16 x check 30; once-only permuter 300 retained 172/30 with identical baseline.
 * checks: 1 own SDK definitions audited 2/5/0, void-return discrepancy above stops matching; 2 live 87FC/8C68/8DA0 twins reread, their declarations also predate SDK definitions; 3 u16 x compiled unchanged 30; emitted permuter baseline agrees 172/30, 300 candidates no improvement; 4 scheduling/global-base/aggregate-copy idioms read; 5 unfiltered idiom directory refreshed and neighbours reread, no stack aggregate in best C.
 * recoup 2026-10-05 (wave P15 D2): DIFF 30/172 (same residue). Callee prototypes taken from the matched siblings 021C8C68/021C8DA0 (int server, char *initdata; int return of 021CA470): no change. Twin search: grep -l func_021C9EE4 src/matched/ov (12 hits, all ov114 siblings); no sibling has a 6-byte copy. Tried: struct copy d = *p (interleaved ldrb/strb, 48 B); local Six copy (208 B); u8 locals in natural store order (42 B); state pointer local (48 B); out pointer local before or after the u8 locals (30 B); both pointer locals (48 B); u8 x parameter (30 B); u8 array and u8 *p (30 B); y store first with late loads (54 B); x byte store first (55 B); six per-function pragmas (30 B each). Residue: output base r4 and state base r5 are swapped, and the original loads the state pool word before the six byte loads while ours loads it after them. Idioms checked: two-long-lived-values-in-each-others-registers (no missing arg, no join local: 30), a-spilled-offset-derived-at-the-top (n/a), the-block-constant-in-a-callee-saved-register (n/a), a-const-source-pointer-hoists-the-last-load (const p: 48 B with struct copy), a-copy-and-a-pointer-step-hoisted-above-a-call (n/a), a-callee-declared-void (callee returns int already: 30).
 * final push 2026-10-05 G6L10: DIFF 16/172 (was 30/172), best form below. Found: with #pragma opt_propagation off, a named State pointer assigned late (after the byte loads and stores, here just before the if, used once for words[2]) gives the original colours (state r5, output r4); declared first or used for the early stores it flips them back (41 to 48 B). Only residue: the original loads the state pool word before the six byte loads (ours after them, 4 instructions shifted). Tried without gain: memcpy(d,p,6) (50 B), struct copy any layout (50 B, interleaved two-register copy), array-typed state (28 to 41 B), both pointers named (130+ B, extra r8), s assigned after the call or before it (16 B), x/y store first (44 to 55 B), x then y order (41 B), opt_lifetimes off and opt_common_subs off on the best form (16 B), extern int server instead of void* cast (no change), extern declaration order (30 B). Matched-assembly search for pool-ldr then four ldrb from an argument register: ov114 021C8B18 is the only hit in all overlays and arm9, no twin. Idioms: opt-propagation-off-with-named-locals, a-pair-copy-memcpy (not a pair copy here: 50 B), of-two-equal-temps-the-later-born-one-gets-the-lower-register (colour half applies).
 * pass 2 2026-10-06 P2L31: EXACT. Two levers together: a const source pointer (the six
 *   byte loads no longer depend on the state store, so the y store written first puts the
 *   state pool load first and the loads schedule above the store) and, under
 *   opt_propagation off, a named destination pointer o assigned first (its stores stay
 *   pointer stores that keep all six loads ahead of them, and it takes r4, state r5).
 *   const p alone with y first: 48 B (loads interleave with the stores); o without const: 54 B;
 *   o assigned after the loads: 15 B (state/out colours swapped).
 * d_021D3D28 0x021D3D28 data a4
 * d_021D3D2C 0x021D3D2C data a4
 * d_021CF538 0x021CF538 data a4
 * d_021D3D40 0x021D3D40 data a4
 * func_021C9EE4 0x021C9EE4 arm ov114
 * func_021CA470 0x021CA470 arm ov114
 * func_021CA1B4 0x021CA1B4 arm ov114
 * d_021CF634 0x021CF634 data a4
 */
void func_021C8B18(const Six *p, int x, unsigned int y)
{
    Six *o;
    u8 a, b, c, d, e, f;
    o = ((Six *)d_021D3D40);
    d_021D3D2C.buf = (unsigned char *)y;
    a = p->a; b = p->b; c = p->c; d = p->d; e = p->e; f = p->f;
    o->f = f;
    o->a = a;
    o->b = b;
    o->c = c;
    o->d = d;
    o->e = e;
    d_021D3D2C.byte = x;
    func_021C9EE4(d_021D3D28, (char *)d_021CF538);
    if (func_021CA470(d_021CF634, d_021D3D2C.id, ((Six *)d_021D3D40), 7, 0) == 0) {
        d_021D3D2C.state = 14;
        return;
    }
    d_021D3D2C.state = 24;
    d_021D3D2C.result = -13;
    func_021CA1B4();
}






#pragma opt_propagation reset






void func_021C8BC4(const void *p, unsigned int x)
{
    d_021D3D2C.buf = (unsigned char *)x;
    memcpy(d_021D3D40, p, 8);
    func_021C9EE4(d_021D3D28, (char *)d_021CF538);
    if (func_021CA470(d_021CF634, d_021D3D2C.id, d_021D3D40, 8, 0) == 0) {
        d_021D3D2C.state = 14;
        return;
    }
    d_021D3D2C.state = 24;
    d_021D3D2C.result = -13;
    func_021CA1B4();
}




void func_021C8C68(unsigned a, const void *p, unsigned c, const void *q, unsigned n)
{
    d_021D3D2C.buf = (unsigned char *)c;
    func_02092344(d_021D3D40, p, 0x128);
    d_021D3D2C.a = a;
    func_02092344(d_021D3E6C, q, n);
    d_021D3D2C.count = n;
    func_021C9EE4(d_021D3D28, (char *)d_021CF538);
    if (func_021CA470(d_021CF654, d_021D3D2C.id, d_021D3D40, 0x1b0, 0) == 0) {
        d_021D3D2C.state = 16;
        return;
    }
    d_021D3D2C.state = 24;
    d_021D3D2C.result = -13;
    func_021CA1B4();
}




void func_021C8D14(void)
{
    memcpy(d_021D3D40, d_021D3D38, 8);
    func_021C9EE4(d_021D3D28, (char *)d_021CF538);
    if (func_021CA470(d_021CF674, d_021D3D2C.id, d_021D3D40, 8, 0) == 0) {
        d_021D3D2C.state = 18;
        return;
    }
    d_021D3D2C.state = 24;
    d_021D3D2C.result = -13;
    func_021CA1B4();
}




void func_021C8DA0(void)
{
    func_021C9EE4(d_021D3D28, (char *)d_021CF538);
    if (func_021CA470(d_021CF69C, d_021D3D2C.id, d_021D3D40, 0, 0) == 0) {
        d_021D3D2C.state = 20;
        return;
    }
    d_021D3D2C.state = 24;
    d_021D3D2C.result = -13;
    func_021CA1B4();
}



void func_021C8E18(unsigned char *p, unsigned x)
{
    func_02087C6C(p + 0x1c);
    func_02092344(d_021D3D40, p, 100);
    d_021D3D2C.buf = (unsigned char *)x;
    func_021C9EE4(d_021D3D28, (char *)d_021CF538);
    if (func_021CA470(d_021CF6B8, d_021D3D2C.id, d_021D3D40, 100, 0) == 0) {
        d_021D3D2C.state = 22;
        return;
    }
    d_021D3D2C.state = 24;
    d_021D3D2C.result = -13;
    func_021CA1B4();
}




/*
 * Non-SDK callee of func_021C7C1C (ov114 dependency tree).  Switch on the
 * request kind maps to a DWC result code; DWC_UpdateConnection failing
 * demotes -13 to -14; DWC_ClearError always runs on the non--13 path.
 *
 * Case-order tell: mwcc lays the per-arm stubs down in SOURCE order, so the
 * only spelling that reproduces the image lists case 5 before case 4 even
 * though the jump table is indexed by value.  -15, -14, -13 are the three
 * result codes; the r5==-13 (case 7) path skips both calls entirely.
 */
int func_021C8EB4(u32 type)
{
    int r;

    switch (type) {
    case 0:
    case 1:
    case 2:
        r = -15;
        break;
    case 3:
        r = -14;
        break;
    case 5:
        r = -14;
        break;
    case 4:
        r = -15;
        break;
    case 6:
        r = -14;
        break;
    case 7:
        r = -13;
        break;
    default:
        r = -14;
        break;
    }

    if (r != -13) {
        if (DWC_UpdateConnection() != 0)
            r = -14;
        DWC_ClearError();
    }

    return r;
}



void func_021C8F2C(unsigned a, unsigned b, unsigned c, unsigned mode)
{
    d_021D4084.state = 1;
    d_021D4084.result = 0;
    d_021D4084.id = a;
    d_021D4084.arg0 = b;
    d_021D4084.arg1 = c;
    switch (mode) {
    case 0: d_021D3EFC = 0; break;
    case 1: d_021D3EFC = 1; break;
    case 2: d_021D3EFC = 2; break;
    default: d_021D3EFC = 1; break;
    }
}


void func_021C8FA8(void)
{
    u32 len;
    int code,type;
    const u8 *resp;
    switch(d_021D4084.state) {
    case 2:
        switch(DWCi_EncSessionProcess()) {
        case 1:
            d_021D4084.state=12;
            DWC_GetLastErrorEx(&code,&type);
            d_021D4084.result=func_021C97E0(type);
            DWCi_EncSessionShutdown(); return;
        case 8:
            d_021D4084.state=12;
            memcpy(&d_021D4084.hdr,DWCi_EncSessionGetResponse(&len),2);
            if(len!=0) d_021D4084.result=d_021D4084.hdr.code;
            else d_021D4084.result=-2;
            DWCi_EncSessionShutdown(); return;
        }
        return;
    case 4:
        switch(DWCi_EncSessionProcess()) {
        case 1:
            d_021D4084.state=12;
            DWC_GetLastErrorEx(&code,&type);
            d_021D4084.result=func_021C97E0(type);
            DWCi_EncSessionShutdown(); return;
        case 8:
            d_021D4084.state=12;
            resp=(const u8 *)DWCi_EncSessionGetResponse(&len);
            func_02092344(d_021D4084.buf,resp,0xa8c);
            if(len==0xa8c) d_021D4084.result=0;
            else {
                switch(d_021D4084.buf[0]) {
                case 2: d_021D4084.result=-3; break;
                case 5: d_021D4084.result=-2; break;
                default: d_021D4084.result=-5; break;
                }
            }
            DWCi_EncSessionShutdown(); return;
        }
        return;
    case 6:
        switch(DWCi_EncSessionProcess()) {
        case 1:
            d_021D4084.state=12;
            DWC_GetLastErrorEx(&code,&type);
            d_021D4084.result=func_021C97E0(type);
            DWCi_EncSessionShutdown(); return;
        case 8:
            d_021D4084.state=12;
            memcpy(&d_021D4084.hdr,DWCi_EncSessionGetResponse(&len),2);
            switch(d_021D4084.hdr.code) {
            case 1: d_021D4084.result=0; break;
            case 2: d_021D4084.result=-3; break;
            case 4: d_021D4084.result=-1; break;
            case 5: d_021D4084.result=-2; break;
            default: d_021D4084.result=-5; break;
            }
            DWCi_EncSessionShutdown(); return;
        }
        return;
    case 8:
        switch(DWCi_EncSessionProcess()) {
        case 1:
            d_021D4084.state=12;
            DWC_GetLastErrorEx(&code,&type);
            d_021D4084.result=func_021C97E0(type);
            DWCi_EncSessionShutdown(); return;
        case 8:
            d_021D4084.state=12;
            memcpy(&d_021D4084.hdr,DWCi_EncSessionGetResponse(&len),2);
            switch(d_021D4084.hdr.code) {
            case 1: d_021D4084.result=0; break;
            case 3: d_021D4084.result=1; break;
            case 4: d_021D4084.result=2; break;
            case 5: d_021D4084.result=-2; break;
            default: d_021D4084.result=-5; break;
            }
            DWCi_EncSessionShutdown(); return;
        }
        return;
    case 10:
        switch(DWCi_EncSessionProcess()) {
        case 1:
            d_021D4084.state=12;
            DWC_GetLastErrorEx(&code,&type);
            d_021D4084.result=func_021C97E0(type);
            DWCi_EncSessionShutdown(); return;
        case 8:
            d_021D4084.state=12;
            resp=(const u8 *)DWCi_EncSessionGetResponse(&len);
            *(Payload *)d_021D4084.buf=*(Payload *)resp;
            if(len==8) d_021D4084.result=0;
            else {
                switch(d_021D4084.buf[0]) {
                case 1: d_021D4084.result=0; break;
                case 3: d_021D4084.result=1; break;
                case 4: d_021D4084.result=2; break;
                case 5: d_021D4084.result=-2; break;
                default: d_021D4084.result=-5; break;
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




void func_021C93BC(void)
{
    d_021D4084.state = 0;
}



int func_021C93D0(void)
{
    switch (d_021D4084.state) {
    case 1:
        return 1;
    case 12:
        d_021D4084.state = 1;
        return 1;
    }
    return 0;
}

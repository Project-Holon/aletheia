/*
 * function: func_021C7C1C
 * address:  0x021C7C1C
 * packet:   pkt_ov114_021C7C1C
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 * residual: 202 concrete bytes differ, same-size 2620; five prologue webs rotate.
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
 * DWC encryption-session poll: a switch on the session state (0..24); every
 * even state 2..22 runs DWCi_EncSessionProcess and on 1 (error) or 8 (done)
 * moves to state 24 and maps the response to a result code; every odd state
 * 3..23 is a cancel (-12).  Real extent 0x021C7C1C..0x021C864C plus three
 * pool words; the listing extent of 2716 bytes also covers the filed leaves
 * 0x021C8658/0x021C866C/0x021C86A8.  d_021D3EF0 is d_021D3D2C + 0x1c4.
 *
 * symbols:
 *   d_021D3D2C                  0x021D3D2C  data  a4
 *   d_021D3EF0                  0x021D3EF0  data  a1
 *   DWCi_EncSessionProcess      0x021CA0A0  arm
 *   DWCi_EncSessionShutdown     0x021CA1B4  arm
 *   DWCi_EncSessionGetResponse  0x021CA228  arm
 *   DWC_GetLastErrorEx          0x02059E38  arm
 *   func_021C8EB4               0x021C8EB4  arm
 *   func_02092344               0x02092344  arm
 */

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

extern Ctx d_021D3D2C;
extern Hdr d_021D3EF0;

extern int DWCi_EncSessionProcess(void);
extern void DWCi_EncSessionShutdown(void);
extern u32 DWCi_EncSessionGetResponse(u32 *len);
extern int DWC_GetLastErrorEx(int *code, int *type);
extern int func_021C8EB4(unsigned int type);
extern void *func_02092344(void *dst, const void *src, unsigned int n);

void func_021C7C1C(void)
{
    u32 len;
    int code;
    int type;
    u8 *resp;
    Ctx *ctx = &d_021D3D2C;

    switch (ctx->state) {
    case 2:
        switch (DWCi_EncSessionProcess()) {
        case 1:
            ctx->state = 24;
            DWC_GetLastErrorEx(&code, &type);
            ctx->result = func_021C8EB4(type);
            DWCi_EncSessionShutdown();
            return;
        case 8:
            ctx->state = 24;
            d_021D3EF0 = *(Hdr *)DWCi_EncSessionGetResponse(&len);
            switch (ctx->hdr.code) {
            case 1: ctx->result = 0; break;
            case 2: ctx->result = -5; break;
            case 3: ctx->result = -4; break;
            case 7: ctx->result = -1; break;
            case 12: ctx->result = -6; break;
            case 13: ctx->result = -7; break;
            case 8: ctx->result = -8; break;
            case 9: ctx->result = -9; break;
            case 10: ctx->result = -10; break;
            case 11: ctx->result = -11; break;
            case 14: ctx->result = -2; break;
            default: ctx->result = -13; break;
            }
            DWCi_EncSessionShutdown();
            return;
        }
        return;
    case 4:
        switch (DWCi_EncSessionProcess()) {
        case 1:
            ctx->state = 24;
            DWC_GetLastErrorEx(&code, &type);
            ctx->result = func_021C8EB4(type);
            DWCi_EncSessionShutdown();
            return;
        case 8:
            ctx->state = 24;
            d_021D3EF0 = *(Hdr *)DWCi_EncSessionGetResponse(&len);
            switch (ctx->hdr.code) {
            case 1: ctx->result = 0; break;
            case 2: ctx->result = -5; break;
            case 3: ctx->result = -4; break;
            case 5: ctx->result = -3; break;
            case 14: ctx->result = -2; break;
            default: ctx->result = -13; break;
            }
            DWCi_EncSessionShutdown();
            return;
        }
        return;
    case 6:
        switch (DWCi_EncSessionProcess()) {
        case 1:
            ctx->state = 24;
            DWC_GetLastErrorEx(&code, &type);
            ctx->result = func_021C8EB4(type);
            DWCi_EncSessionShutdown();
            return;
        case 8:
            ctx->state = 24;
            resp = (u8 *)DWCi_EncSessionGetResponse(&len);
            func_02092344(ctx->buf, resp, 0x128);
            if (len == 0x128) {
                ctx->result = 0;
            } else {
                switch (ctx->buf[0]) {
                case 5: ctx->result = -3; break;
                case 3: ctx->result = -4; break;
                case 14: ctx->result = -2; break;
                default: ctx->result = -13; break;
                }
            }
            DWCi_EncSessionShutdown();
            return;
        }
        return;
    case 8:
        switch (DWCi_EncSessionProcess()) {
        case 1:
            ctx->state = 24;
            DWC_GetLastErrorEx(&code, &type);
            ctx->result = func_021C8EB4(type);
            DWCi_EncSessionShutdown();
            return;
        case 8:
            ctx->state = 24;
            resp = (u8 *)DWCi_EncSessionGetResponse(&len);
            func_02092344(ctx->buf, resp, 0x128);
            if (len == 0x128) {
                ctx->result = 1;
            } else {
                switch (ctx->buf[0]) {
                case 5: ctx->result = -3; break;
                case 3: ctx->result = -4; break;
                case 4: ctx->result = 0; break;
                case 14: ctx->result = -2; break;
                default: ctx->result = -13; break;
                }
            }
            DWCi_EncSessionShutdown();
            return;
        }
        return;
    case 10:
        switch (DWCi_EncSessionProcess()) {
        case 1:
            ctx->state = 24;
            DWC_GetLastErrorEx(&code, &type);
            ctx->result = func_021C8EB4(type);
            DWCi_EncSessionShutdown();
            return;
        case 8:
            ctx->state = 24;
            d_021D3EF0 = *(Hdr *)DWCi_EncSessionGetResponse(&len);
            switch (ctx->hdr.code) {
            case 1: ctx->result = 0; break;
            case 5: ctx->result = -3; break;
            case 3: ctx->result = -4; break;
            case 14: ctx->result = -2; break;
            default: ctx->result = -13; break;
            }
            DWCi_EncSessionShutdown();
            return;
        }
        return;
    case 12:
        switch (DWCi_EncSessionProcess()) {
        case 1:
            ctx->state = 24;
            DWC_GetLastErrorEx(&code, &type);
            ctx->result = func_021C8EB4(type);
            DWCi_EncSessionShutdown();
            return;
        case 8:
            ctx->state = 24;
            d_021D3EF0 = *(Hdr *)DWCi_EncSessionGetResponse(&len);
            switch (ctx->hdr.code) {
            case 1: ctx->result = 0; break;
            case 5: ctx->result = -3; break;
            case 2: ctx->result = -5; break;
            case 3: ctx->result = -4; break;
            case 14: ctx->result = -2; break;
            default: ctx->result = -13; break;
            }
            DWCi_EncSessionShutdown();
            return;
        }
        return;
    case 14:
        switch (DWCi_EncSessionProcess()) {
        case 1:
            ctx->state = 24;
            DWC_GetLastErrorEx(&code, &type);
            ctx->result = func_021C8EB4(type);
            DWCi_EncSessionShutdown();
            return;
        case 8:
            ctx->state = 24;
            resp = (u8 *)DWCi_EncSessionGetResponse(&len);
            *(Hdr *)ctx->buf = *(Hdr *)resp;
            switch (ctx->buf[0]) {
            case 1:
                if (len - 2 >= 0x128) {
                    ctx->result = (len - 2) / 0x128;
                    func_02092344(ctx->buf, resp + 2, len - 2);
                } else if (len == 2) {
                    ctx->result = 0;
                }
                break;
            case 14: ctx->result = -2; break;
            default: ctx->result = -13; break;
            }
            DWCi_EncSessionShutdown();
            return;
        }
        return;
    case 16:
        switch (DWCi_EncSessionProcess()) {
        case 1:
            ctx->state = 24;
            DWC_GetLastErrorEx(&code, &type);
            ctx->result = func_021C8EB4(type);
            DWCi_EncSessionShutdown();
            return;
        case 8:
            ctx->state = 24;
            resp = (u8 *)DWCi_EncSessionGetResponse(&len);
            func_02092344(ctx->buf, resp, 0x128);
            if (len == 0x128) {
                ctx->result = 0;
            } else {
                switch (ctx->buf[0]) {
                case 2: ctx->result = -5; break;
                case 12: ctx->result = -6; break;
                case 13: ctx->result = -7; break;
                case 8: ctx->result = -8; break;
                case 9: ctx->result = -9; break;
                case 10: ctx->result = -10; break;
                case 11: ctx->result = -11; break;
                case 14: ctx->result = -2; break;
                default: ctx->result = -13; break;
                }
            }
            DWCi_EncSessionShutdown();
            return;
        }
        return;
    case 18:
        switch (DWCi_EncSessionProcess()) {
        case 1:
            ctx->state = 24;
            DWC_GetLastErrorEx(&code, &type);
            ctx->result = func_021C8EB4(type);
            DWCi_EncSessionShutdown();
            return;
        case 8:
            ctx->state = 24;
            d_021D3EF0 = *(Hdr *)DWCi_EncSessionGetResponse(&len);
            switch (ctx->hdr.code) {
            case 1: ctx->result = 0; break;
            case 2: ctx->result = -5; break;
            case 14: ctx->result = -2; break;
            }
            DWCi_EncSessionShutdown();
            return;
        }
        return;
    case 20:
        switch (DWCi_EncSessionProcess()) {
        case 1:
            ctx->state = 24;
            DWC_GetLastErrorEx(&code, &type);
            ctx->result = func_021C8EB4(type);
            DWCi_EncSessionShutdown();
            return;
        case 8:
            ctx->state = 24;
            d_021D3EF0 = *(Hdr *)DWCi_EncSessionGetResponse(&len);
            switch (ctx->hdr.code) {
            case 1: ctx->result = 0; break;
            case 6: ctx->result = 1; break;
            case 7: ctx->result = 2; break;
            case 14: ctx->result = -2; break;
            default: ctx->result = -13; break;
            }
            DWCi_EncSessionShutdown();
            return;
        }
        return;
    case 22:
        switch (DWCi_EncSessionProcess()) {
        case 1:
            ctx->state = 24;
            DWC_GetLastErrorEx(&code, &type);
            ctx->result = func_021C8EB4(type);
            DWCi_EncSessionShutdown();
            return;
        case 8:
            ctx->state = 24;
            resp = (u8 *)DWCi_EncSessionGetResponse(&len);
            *(Hdr *)ctx->buf = *(Hdr *)resp;
            if (len == 8) {
                ctx->result = 0;
            } else {
                switch (ctx->buf[0]) {
                case 1: ctx->result = 0; break;
                case 6: ctx->result = 1; break;
                case 7: ctx->result = 2; break;
                case 14: ctx->result = -2; break;
                default: ctx->result = -13; break;
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
        ctx->state = 24;
        ctx->result = -12;
        DWCi_EncSessionShutdown();
        return;
    case 0:
    case 1:
    case 24:
        break;
    }
}

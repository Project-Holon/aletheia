/*
 * function: WORLDTRADE_DEMO_EvolveStep
 * address:  0x021F6FD4
 * packet:   pkt_021F6FD4
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WORLDTRADE_DEMO_GetSlotRecord  0x021F7338  thumb
 *   WORLDTRADE_DEMO_InitSlotRecord  0x021F7374  thumb
 *   WORLDTRADE_SetStateAndReturn  0x021F4EC0  thumb
 *   WORLDTRADE_ADAPTER_AllocHeapBuf  0x02202608  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_02012984  0x02012984  thumb
 *   SHINKA_CHECK_CheckEvolution  0x0201B2B0  thumb
 *   func_020307B0  0x020307B0  arm
 *   func_02030734  0x02030734  arm
 *   MI_CpuFill8  0x02082BCC  arm
 *   POKEPARTY_Create  0x0201A920  thumb
 *   POKEPARTY_Add  0x0201A98C  thumb
 *   func_02034A5C  0x02034A5C  arm
 *   func_02034AC4  0x02034AC4  arm
 *   PROCSYS_Push  0x02031348  arm
 *   WORLDTRADE_CopyPokemon  0x0200AD9C  thumb
 *   POKEPARTY_GetMember  0x0201AB28  thumb
 *   func_02019CE0  0x02019CE0  thumb
 *   str_02203B6C   0x02203B6C  data  a1
 *   d_02208C40     0x02208C40  data  ov195
 *   ov067_id       0x00000043  data
 *   ov195_id       0x000000C3  data
 *
 * Two-state step. State 0, once the +0x12F4 busy word clears: for kind 9
 * (or kinds 8/10 when the stored entry differs from the one rebuilt from
 * the save data by WORLDTRADE_ADAPTER_AllocHeapBuf/WORLDTRADE_CopyPokemon) build a 0x14-byte request
 * (SHINKA_CHECK_CheckEvolution result, list holding the entry, out byte) at +0x10DC,
 * load overlay 67 and start the overlay-195 task (d_02208C40, hinted to
 * ov195 because this function names ov195_id), then go to state 1; any
 * failure calls WORLDTRADE_SetStateAndReturn(p, 1, 0) and returns 3. State 1 copies the
 * result back into the entry, frees the request, refreshes the record
 * (WORLDTRADE_DEMO_InitSlotRecord), clears the DISPCNT window bits, unloads overlay 67 and
 * calls WORLDTRADE_SetStateAndReturn(p, 7, 0xC). Returns 2 while waiting, else 3.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    void *f0;
    void *list;
    u16 f8;
    u8 fA;
    u8 fB;
    u32 fC;
    u32 f10;
} Req;

typedef struct {
    void *save;
    u8 pad4[0x40 - 4];
    void *f40;
} Ctx;

typedef struct {
    Ctx *ctx;
    u8 pad4[0x20 - 4];
    int kind;
    u8 pad24[0x28 - 0x24];
    int state;
    u8 pad2C[0xEA4 - 0x2C];
    void *fEA4;
    u8 padEA8[0x10DC - 0xEA8];
    Req *req;
    u8 pad10E0[0x12F0 - 0x10E0];
    void *f12F0;
    u32 busy;
    u32 f12F8;
} Obj;

extern char str_02203B6C[];
extern u8 d_02208C40[];
extern u8 ov067_id[];
extern u8 ov195_id[];

extern void *WORLDTRADE_DEMO_GetSlotRecord(Obj *p, int kind);
extern void WORLDTRADE_DEMO_InitSlotRecord(Obj *p);
extern void WORLDTRADE_SetStateAndReturn(u8 *p, u32 a, u32 b);
extern void *WORLDTRADE_ADAPTER_AllocHeapBuf(u32 heap);
extern u32 func_02017E1C(void *p, u32 id, u32 v);
typedef signed int     s32;
struct BigObj;
struct Ctx;
struct Party;
struct PartyMon;
struct RecDC;
extern void *func_020120F4(const struct Ctx *p);
extern u8 func_02012984(const struct BigObj *p);
extern u32 SHINKA_CHECK_CheckEvolution(void *party, void *mon, u32 context, u32 param, u8 timezone, u32 *methodOut, u16 heap);
extern u32 func_020307B0(void *p);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void MI_CpuFill8(void *, int, int);
extern struct Party *POKEPARTY_Create(u32 heap);
extern u32 POKEPARTY_Add(struct Party *p, const struct PartyMon *src);
extern void func_02034A5C(s32 handle);
extern int func_02034AC4(s32 handle);
extern void PROCSYS_Push(void *h, u32 id, void *a, void *b);
extern void WORLDTRADE_CopyPokemon(void *save, void *mon);
extern void *POKEPARTY_GetMember(void *list, u32 i);
extern void func_02019CE0(const struct RecDC *src, struct RecDC *dest);

int WORLDTRADE_DEMO_EvolveStep(Obj *p)
{
    int ret = 2;

    switch (p->state) {
    case 0:
        if (p->busy != 0) {
            break;
        }
        if (p->kind == 9) {
            void *e = WORLDTRADE_DEMO_GetSlotRecord(p, p->kind);
            u32 out;
            u32 r;

            func_02017E1C(e, 6, 0);
            r = SHINKA_CHECK_CheckEvolution(0, e, 1, (u32)p->fEA4, func_02012984(func_020120F4(p->ctx->f40)), &out, 0x48);
            if (r != 0) {
                Req *w;

                if (p->req != 0) {
                    func_020307B0(p->req);
                    p->req = 0;
                }
                p->req = func_02030734(0x48, 0x14, 0, str_02203B6C, 0xEB);
                MI_CpuFill8(p->req, 0, 0x14);
                w = p->req;
                w->f0 = func_020120F4(p->ctx->f40);
                w->list = POKEPARTY_Create(0x48);
                POKEPARTY_Add(w->list, e);
                w->f8 = r;
                w->fA = 0;
                w->fB = out;
                w->fC = 1;
                w->f10 = 0;
                func_02034A5C((u32)ov067_id);
                PROCSYS_Push(p->f12F0, (u32)ov195_id, d_02208C40, p->req);
                p->state = 1;
            } else {
                WORLDTRADE_SetStateAndReturn((u8 *)p, 1, 0);
                ret = 3;
            }
        } else if (p->kind == 8 || p->kind == 10) {
            void *e = WORLDTRADE_DEMO_GetSlotRecord(p, p->kind);
            void *mon = WORLDTRADE_ADAPTER_AllocHeapBuf(0x48);
            u32 out;
            u32 r;

            WORLDTRADE_CopyPokemon(p->ctx->save, mon);
            if (func_02017E1C(e, 5, 0) != func_02017E1C(mon, 5, 0)
                || func_02017E1C(e, 0, 0) != func_02017E1C(mon, 0, 0)) {
                func_02017E1C(e, 6, 0);
                r = 0;
                if (p->f12F8 != 0) {
                    p->f12F8 = 0;
                    r = SHINKA_CHECK_CheckEvolution(0, e, 1, (u32)mon, func_02012984(func_020120F4(p->ctx->f40)), &out, 0x48);
                }
                if (r != 0) {
                    Req *w;

                    if (p->req != 0) {
                        func_020307B0(p->req);
                        p->req = 0;
                    }
                    p->req = func_02030734(0x48, 0x14, 0, str_02203B6C, 0x130);
                    MI_CpuFill8(p->req, 0, 0x14);
                    w = p->req;
                    w->f0 = func_020120F4(p->ctx->f40);
                    w->list = POKEPARTY_Create(0x48);
                    POKEPARTY_Add(w->list, e);
                    w->f8 = r;
                    w->fA = 0;
                    w->fB = out;
                    w->fC = 1;
                    w->f10 = 0;
                    func_02034A5C((u32)ov067_id);
                    PROCSYS_Push(p->f12F0, (u32)ov195_id, d_02208C40, p->req);
                    p->state = 1;
                } else {
                    WORLDTRADE_SetStateAndReturn((u8 *)p, 1, 0);
                    ret = 3;
                }
            } else {
                WORLDTRADE_SetStateAndReturn((u8 *)p, 1, 0);
                ret = 3;
            }
            func_020307B0(mon);
        } else {
            WORLDTRADE_SetStateAndReturn((u8 *)p, 1, 0);
            ret = 3;
        }
        break;
    case 1:
        if (p->busy != 0) {
            break;
        }
        if (p->req != 0) {
            Req *w = p->req;
            void *e = WORLDTRADE_DEMO_GetSlotRecord(p, p->kind);

            func_02019CE0(POKEPARTY_GetMember(w->list, 0), e);
            func_020307B0(w->list);
            func_020307B0(p->req);
            p->req = 0;
        }
        WORLDTRADE_DEMO_InitSlotRecord(p);
        *(volatile u32 *)0x04000000 &= ~0xE000;
        func_02034AC4((u32)ov067_id);
        WORLDTRADE_SetStateAndReturn((u8 *)p, 7, 0xC);
        ret = 3;
        break;
    }
    return ret;
}

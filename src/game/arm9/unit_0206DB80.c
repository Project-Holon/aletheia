/*
 * file:     unit_0206DB80.c
 * unit:     yes
 * function: func_0206DB80, func_0206DBDC, func_0206DBF4, func_0206DC00, func_0206DDA4, func_0206DE88
 * address:  0x0206DB80
 * region:   arm9
 * compiler: dsi/../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   g_0214BAB4       0x0214BAB4  data
 *   func_02082AA8    0x02082AA8  arm
 *   g_020A84C0     0x020A84C0  data
 *   OS_IsRunOnTwl  0x02085D3C  arm
 *   MI_SendNDmaGXCommandAsyncFast  0x027300F0  arm  twl
 *   MI_SendNDmaGXCommandAsync  0x0272FEF4  arm  twl
 *   func_02082960  0x02082960  arm
 *   func_02082760  0x02082760  arm
 *   func_02082B0C  0x02082B0C  arm
 *   func_0207DC98    0x0207DC98  arm
 *   func_0207BDE0    0x0207BDE0  arm
 *   func_0207DCC8    0x0207DCC8  arm
 */
typedef unsigned int u32;

struct GxList { u32 count; u32 cmds[1]; };

struct GeState {
    struct GxList *list;
    volatile u32 busy;
    u32 f8;
};

typedef void (*MICallback)(void *arg);

extern void func_02082AA8(const void *src, void *dst, u32 n);
extern int  OS_IsRunOnTwl(void);
extern void MI_SendNDmaGXCommandAsyncFast(u32 ndma, const void *src, u32 sz, MICallback cb, void *arg);
extern void MI_SendNDmaGXCommandAsync(u32 ndma, const void *src, u32 sz, MICallback cb, void *arg);
extern void func_02082960(u32 dma, const void *src, u32 sz, MICallback cb, void *arg);
extern void func_02082760(u32 dma, const void *src, u32 sz, MICallback cb, void *arg);
extern void func_02082B0C(const void *src, void *dst, u32 n);
extern u32  func_0207DC98(void *p);
extern void func_0207BDE0(void *p, void *q);
extern u32  func_0207DCC8(void *p);
void func_0206DB80(void);
void func_0206DBDC(void);
void func_0206DBF4(void *arg);
void func_0206DC00(const u32 *src, u32 sz);
void func_0206DDA4(u32 cmd, const void *params, u32 n);
void func_0206DE88(void *a, void *b);
extern struct GeState g_0214BAB4;
extern u32 g_020A84C0;      /* GXi_DmaId */



/*
 * Drains the block described by the global pair at 0x0214BAB4: word 1
 * non-zero means a transfer is still in flight, so wait for it; then word 0's
 * object has its payload (object + 4) filled with 0x04000400 over count*4
 * bytes and its count zeroed.
 *
 * PIN ../2.0/sp2, the address-rematerialisation tell (docs/FRONTEND-PINS.md).
 * The original loads the pool word at 0x0206DBD4 THREE times -- `ldr r0,
 * [pc, #0x48]` at +0004, `ldr r0, [pc, #0x34]` at +0018 and `ldr r0,
 * [pc, #0xc]` at +0040 -- and its prologue is `push {r3, lr}`, i.e. not one
 * callee-saved register is spent.  1.1p1 -O4,p instead materialises the
 * address once into r4 across the func_02082AA8 call, growing the push to
 * `push {r4, lr}` and shortening the tail by one load: 88 bytes against the
 * original's 92, 23 concrete bytes out (the residue docs/notes/
 * pkt_0206DB80.c.txt recorded).  No spelling of the C moves it under 1.1p1:
 * volatile on the array elements, a named local for the head pointer and the
 * fully spelled-out `g[0][0]` form all give the same r4.  Under the pin the
 * same C is 92 bytes, 0 mismatches.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0206DB80.c \
 *       --func func_0206DB80 --addr 0x0206DB80 --cc ../2.0/sp2 --arm
 */
void func_0206DB80(void)
{
    if (g_0214BAB4.busy != 0)
        func_0206DBDC();
    if (g_0214BAB4.list != 0 && g_0214BAB4.list->count != 0) {
        func_02082AA8(g_0214BAB4.list->cmds, (void *)0x04000400, g_0214BAB4.list->count * 4);
        g_0214BAB4.list->count = 0;
    }
}




/*
 * Spin on the word at +4 of the same global NNS_G3dGeSetBuffer/60 hold the head
 * pointer in.  The `volatile` is load-bearing: without it mwccarm proves the
 * word cannot change inside the empty loop and collapses the re-read into a
 * single load plus a self-branch (24 bytes against the original's 20, and the
 * load lands at +0 instead of +4).
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0206DBDC.c \
 *       --func func_0206DBDC --addr 0x0206DBDC --cc 1.1p1 --arm
 */
void func_0206DBDC(void)
{
    while (g_0214BAB4.busy != 0)
        ;
}




/*
 * NitroSystem G3D gecom.c: the GX-command DMA completion callback that
 * NNS_G3dGeSendDL (func_0206DC00) passes to the async DMA start; it clears
 * the in-flight word it is handed (&g_0214BAB4.busy).  A 12-byte leaf with
 * no lr save, so disasm.py folds it into func_0206DBDC's listing extent;
 * filed as the witness that clears func_0206DC00's ABS32 site once
 * 0x0206DBF4 is seeded in layout/function_starts.txt.
 */
void func_0206DBF4(void *arg)
{
    *(volatile u32 *)arg = 0;
}



/*
 * NitroSystem G3D NNS_G3dGeSendDL (gecom.c): send a display list. Under 256
 * bytes, or with no GX DMA channel (GXi_DmaId at 0x020A84C0 == -1), it goes
 * through func_0206DDA4 (NNS_G3dGeBufferOP_N) one command word + args.
 * Otherwise flush the buffer, raise the in-flight word at +4 and start an
 * async GX-command DMA with the completion callback func_0206DBF4
 * (clears *arg) and arg = &g_0214BAB4.busy. The +8 word selects the Fast
 * variant; on TWL hardware (OS_IsRunOnTwl) an id above 3 is an NDMA channel
 * id - 4 handled by the TWL-only routines at 0x027300F0 / 0x0272FEF4.
 *
 * EXACT under ../2.0/sp2 (dsi/1.1p1 pushes {r3-r8,lr} and is 12 bytes
 * short), 14 of 14 relocations resolved (wave 19, 2026-09-24):
 *   - PC24 0x027300F0 and 0x0272FEF4: TWL code, region `twl` (the DSi-mode
 *     autoload block of arm9i.bin), named with the `twl` token. Both are
 *     traced ARM function starts in asm/twl/twl.s, which exists only with a
 *     user-supplied DSi key (see tools/modcrypt.py). No branch outside this
 *     function targets either one, so `label` refuses them; they resolve as
 *     `sole-ref/code` over the twl listing (attest_sole_ref_twl_code()).
 *   - ABS32 0x0206DBF4: resolves as `matched` (src/matched/func_0206DBF4.c,
 *     shard pkt_0206DC00).
 */
void func_0206DC00(const u32 *src, u32 sz)
{
    if (sz < 0x100 || g_020A84C0 == (u32)-1) {
        func_0206DDA4(*src, src + 1, (sz >> 2) - 1);
        return;
    }
    func_0206DB80();
    g_0214BAB4.busy = 1;
    if (g_0214BAB4.f8) {
        if (OS_IsRunOnTwl()) {
            u32 id = g_020A84C0;
            u32 dma = id > 3 ? (u32)-1 : id;
            if (dma == (u32)-1)
                MI_SendNDmaGXCommandAsyncFast(id > 3 ? id - 4 : (u32)-1, src, sz, func_0206DBF4, (void *)&g_0214BAB4.busy);
            else
                func_02082960(dma, src, sz, func_0206DBF4, (void *)&g_0214BAB4.busy);
        } else {
            func_02082960(g_020A84C0 > 3 ? (u32)-1 : g_020A84C0, src, sz, func_0206DBF4, (void *)&g_0214BAB4.busy);
        }
    } else {
        if (OS_IsRunOnTwl()) {
            u32 id = g_020A84C0;
            u32 dma = id > 3 ? (u32)-1 : id;
            if (dma == (u32)-1)
                MI_SendNDmaGXCommandAsync(id > 3 ? id - 4 : (u32)-1, src, sz, func_0206DBF4, (void *)&g_0214BAB4.busy);
            else
                func_02082760(dma, src, sz, func_0206DBF4, (void *)&g_0214BAB4.busy);
        } else {
            func_02082760(g_020A84C0 > 3 ? (u32)-1 : g_020A84C0, src, sz, func_0206DBF4, (void *)&g_0214BAB4.busy);
        }
    }
}




/*
 * NitroSystem G3D NNS_G3dGeBufferOP_N (gecom.c): append op + num argument
 * words to the current geometry command buffer while a display-list send is
 * in flight and the buffer has room (0xc0 words); otherwise flush the buffer
 * (func_0206DB80) or wait out the send (func_0206DBDC), then write op to
 * GXFIFO 0x04000400 and send the arguments after it (func_02082AA8).
 *
 * The last 46 bytes were one hoisted load: the fix is that the in-flight word
 * at +4 is a VOLATILE FIELD of the one global (never CSE'd between the
 * list != 0 and list == 0 arms), not a second volatile declaration of the
 * same address. Under dsi/1.1p1 the same C pushes {r3-r7,lr}; pinned
 * ../2.0/sp2 as the rest of the cluster.
 */
void func_0206DDA4(u32 cmd, const void *params, u32 n)
{
    if (g_0214BAB4.list != 0) {
        if (g_0214BAB4.busy != 0) {
            u32 count = g_0214BAB4.list->count;
            if (count + 1 + n <= 0xc0) {
                g_0214BAB4.list->count = count + 1;
                g_0214BAB4.list->cmds[count] = cmd;
                if (n == 0)
                    return;
                func_02082B0C(params,
                              &g_0214BAB4.list->cmds[g_0214BAB4.list->count],
                              n * 4);
                g_0214BAB4.list->count += n;
                return;
            }
        }
        if (g_0214BAB4.list->count != 0) {
            func_0206DB80();
        } else if (g_0214BAB4.busy != 0) {
            func_0206DBDC();
        }
    } else if (g_0214BAB4.busy != 0) {
        func_0206DBDC();
    }
    *(u32 *)0x04000400 = cmd;
    func_02082AA8(params, (void *)0x04000400, n * 4);
}




/*
 * The 3D-engine reset path: drain the pending display list (func_0206DB80),
 * zero GXFIFO's control words at 0x04000440/0x04000444/0x04000454, then, if a
 * matrix block was given, spin func_0207DC98 on a 0x40-byte stack scratch
 * until it reports ready and hand the pair to func_0207BDE0; if a second block
 * was given, spin func_0207DCC8 on it; finally write 1 to 0x04000448 and 2 to
 * 0x04000440 (the store to 0x04000440 is spelled `str r0, [r1, #-8]` off the
 * 0x04000448 pool word, so the two are one base in the original too).
 *
 * PIN ../2.0/sp2, the cluster pin (docs/FRONTEND-PINS.md, and the sibling
 * src/matched/func_0206DB80.c).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0206DE88.c \
 *       --func func_0206DE88 --addr 0x0206DE88 --cc ../2.0/sp2 --arm
 */
void func_0206DE88(void *a, void *b)
{
    u32 tmp[0x10];

    func_0206DB80();
    *(u32 *)0x04000440 = 0;
    *(u32 *)0x04000444 = 0;
    *(u32 *)0x04000454 = 0;
    if (a != 0) {
        while (func_0207DC98(tmp) != 0)
            ;
        func_0207BDE0(tmp, a);
    }
    if (b != 0) {
        while (func_0207DCC8(b) != 0)
            ;
    }
    *(u32 *)0x04000448 = 1;
    *(u32 *)0x04000440 = 2;
}

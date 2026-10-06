/*
 * file:     unit_02078C40_p02.c
 * unit:     yes
 * function: func_02078F30, func_0207902C, func_02079164
 * address:  0x02078F30
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   g_02150D20  0x02150D20  data
 *   func_0209125C  0x0209125C  thumb
 *   FSi_GetOverlayBinarySize  0x02078CB0  arm
 *   OS_IsRunOnTwl  0x02085D3C  arm
 *   OS_GetBootType  0x02087B04  arm
 *   FSi_CompareDigest  0x02078F30  arm
 *   MI_CpuFill8  0x02082BCC  arm
 *   OS_Terminate  0x02088234  arm
 *   MIi_UncompressBackward  0x02004DF4  arm
 *   DC_FlushRange  0x020862F0  arm
 *   SDK_LTDAUTOLOAD_LTDMAIN_START  0x02700000  data
 *   SDK_LTDAUTOLOAD_LTDMAIN_BSS_END  0x02735B40  data
 *   fsi_overlay_state  0x02150D20  data
 *   SDK_OVERLAY_DIGEST_END  0x020A9E64  data
 *   SDK_OVERLAY_DIGEST  0x020A8BE0  data
 *   func_02087988  0x02087988  arm
 *   func_0208799C  0x0208799C  arm
 *   g_021542B8     0x021542B8  data
 */
typedef unsigned char u8;

typedef unsigned int u32_02078F30;

struct S78F30 {
    u8  pad00[0x18];
    u32_02078F30 f18;
    u32_02078F30 f1c;
};

typedef unsigned short u16;

typedef unsigned long u32_0207902C;

typedef int BOOL;

typedef void (*FSOverlayFunc)(void);

typedef struct FSOverlayInfoHeader
{
    u32_0207902C id;
    u8 *ram_address;
    u32_0207902C ram_size;
    u32_0207902C bss_size;
    FSOverlayFunc *sinit_init;
    FSOverlayFunc *sinit_init_end;
    u32_0207902C file_id;
    u32_0207902C compressed : 24;
    u32_0207902C flag : 8;
} FSOverlayInfoHeader;

typedef struct FSOverlayInfo
{
    FSOverlayInfoHeader header;
    int target;
    u32_0207902C file_pos[2];
} FSOverlayInfo;

typedef struct FSiOverlayState
{
    BOOL once;
} FSiOverlayState;

typedef unsigned int u32_02079164;

struct Node02079164 {
    struct Node02079164 *next;
    void (*fn)(void *);
    void *arg;
};

struct Iter020792B8 {
    u32_02079164 unk00;
    u32_02079164 base;
    u32_02079164 len0;
    u32_02079164 len1;
    u32_02079164 pad[7];
};

extern void func_02082BCC(void *, int, u32_02078F30);
extern void func_02082D44(u32_02078F30, void *, u32_02078F30);
extern u32_02078F30  func_02085D3C(void);
extern void func_0209125C(u32_02078F30 a, u32_02078F30 b, u32_02078F30 c, u32_02078F30 d, u32_02078F30 e);
extern u32_02078F30  func_0208139C(u32_02078F30);
extern void func_020816FC(void *digest, const void *bin_ptr, u32_02078F30 bin_len, const void *key_ptr, u32_02078F30 key_len);
extern u32_0207902C FSi_GetOverlayBinarySize(FSOverlayInfo *p_ovi);
extern BOOL OS_IsRunOnTwl(void);
extern u16 OS_GetBootType(void);
extern BOOL FSi_CompareDigest(const u8 *spec_digest, void *src, int len, BOOL table_mode);
extern void MI_CpuFill8(void *dstp, u8 data, u32_0207902C size);
extern void OS_Terminate(void);
extern void MIi_UncompressBackward(void *bottom);
extern void DC_FlushRange(void *startAddr, u32_0207902C nBytes);
extern u32_02079164  func_02087988(void);
extern void func_0208799C(u32_02079164 e);
int func_02078F30(u8 *a0, u32_02078F30 a1, u32_02078F30 a2, int a3);
void func_0207902C(FSOverlayInfo *p_ovi);
extern struct S78F30 g_02150D20;
extern u8 SDK_LTDAUTOLOAD_LTDMAIN_START[];
extern u8 SDK_LTDAUTOLOAD_LTDMAIN_BSS_END[];
extern FSiOverlayState fsi_overlay_state;
extern u8 SDK_OVERLAY_DIGEST_END[];
extern u8 SDK_OVERLAY_DIGEST[];
extern struct Node02079164 *g_021542B8;


/*
 * DRAFT: compiles the whole 252-byte range; verdict pending.
 */
int func_02078F30(u8 *a0, u32_02078F30 a1, u32_02078F30 a2, int a3)
{
    u8 buf[0x14];
    u8 tmp[0x40];
    u32_02078F30 handle;
    u32_02078F30 v;
    u32_02078F30 i;

    func_02082BCC(buf, 0, 0x14);
    func_02082D44(g_02150D20.f18, tmp, g_02150D20.f1c);

    if (a3 == 0 && func_02085D3C() != 0) {
        v = g_02150D20.f1c;
        func_0209125C((u32_02078F30)buf, a1, a2, (u32_02078F30)tmp, v);
    } else {
        handle = 0;
        if (a3 != 0) {
            handle = func_0208139C(1);
        }
        v = g_02150D20.f1c;
        func_020816FC(buf, (const void *)a1, a2, tmp, v);
        if (a3 != 0) {
            func_0208139C(handle);
        }
    }

    i = 0;
    while (i < 0x14) {
        if (*(u32_02078F30 *)(buf + i) != *(u32_02078F30 *)(a0 + i)) {
            break;
        }
        i += 4;
    }
    return i == 0x14;
}


/*
 * notes:    bytes identical; SDK_LTDAUTOLOAD_LTDMAIN_START and _BSS_END resolve under the `linker` class (undefined in fs_overlay.o and in libfs; values = layout.json twl ram_start / bss_end)
 *
 * sdk:      FS_StartOverlay (libfs.TWL.HYB.a fs_overlay.o)
 */
void func_0207902C(FSOverlayInfo *p_ovi)
{
    u32_0207902C rare_size = FSi_GetOverlayBinarySize(p_ovi);

    if (((u32_0207902C)p_ovi->header.ram_address >= (u32_0207902C)SDK_LTDAUTOLOAD_LTDMAIN_START) &&
        ((u32_0207902C)p_ovi->header.ram_address < (u32_0207902C)SDK_LTDAUTOLOAD_LTDMAIN_BSS_END) && OS_IsRunOnTwl())
    {
        if (!fsi_overlay_state.once)
        {
            fsi_overlay_state.once = 1;
        }
    }
    if (OS_GetBootType() != 1)
    {
        BOOL ret = 0;

        if ((p_ovi->header.flag & 2) != 0)
        {
            const u32_0207902C max = (u32_0207902C)((SDK_OVERLAY_DIGEST_END - SDK_OVERLAY_DIGEST) / 20);

            if (p_ovi->header.id < max)
            {
                ret = FSi_CompareDigest(SDK_OVERLAY_DIGEST + p_ovi->header.id * 20,
                                        p_ovi->header.ram_address, (int)rare_size, 0);
            }
        }
        if (!ret)
        {
            MI_CpuFill8(p_ovi->header.ram_address, 0, rare_size);
            OS_Terminate();
            return;
        }
    }
    if ((p_ovi->header.flag & 1) != 0)
    {
        MIi_UncompressBackward(p_ovi->header.ram_address + rare_size);
    }
    DC_FlushRange(p_ovi->header.ram_address, p_ovi->header.ram_size);
    {
        FSOverlayFunc *p = p_ovi->header.sinit_init;
        FSOverlayFunc *q = p_ovi->header.sinit_init_end;

        for (; p < q; ++p)
        {
            if (*p)
            {
                (**p)();
            }
        }
    }
}


/*
 * 0x02079164..0x02079264: the callback-flush worker and its one-line
 * wrapper.
 *
 * func_02079164 repeatedly detaches, inside the 0x02087988/0x0208799C
 * critical section, every node of the global list g_021542B8 whose
 * callback argument (+8) falls in the descriptor's byte range, or whose
 * callback function (+4) does when the argument is null, then runs the
 * detached callbacks with interrupts restored and starts over.  The
 * branch back to the function header is that restart: a callback may
 * queue new nodes, so the list is rescanned until a pass detaches
 * nothing.  The range is [it->base, it->base + it->len0 + it->len1).
 *
 * func_02079254 is folded into the same unit deliberately.  The `bl` at
 * 0x02079258 is 0x02079164's only reference in the whole image, so as two
 * separate files neither can attest the other and both cap at MATCH; in
 * one unit that call site is class `local` and the range is EXACT, which
 * in turn attests 0x02079254 for src/matched/func_020792B8.c.
 *
 * Three things the byte match pinned down, in the order they cost time:
 *
 *  - 0x02087988's result is live in r0 across the whole scan loop and is
 *    0x0208799C's argument (the SDK disable/restore-interrupts pair).
 *    Spelling both as `void f(void)` leaves r0 free, and the allocator
 *    then has one spare register and picks a different colouring for
 *    every local in the function.
 *  - `cur->arg` and `cur->fn` are read into locals before the test, not
 *    referenced inside it: the original loads +4 unconditionally, ahead
 *    of the branch that only one arm of the test needs.
 *  - which locals live in the function scope and which in the `for` body
 *    block decides the colouring outright.  `prev` and `list` outlive the
 *    loop body's declarations here; moving either one inside the block
 *    moves eight or more bytes.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02079164.c  *       --addr 0x02079164 --cc 1.1p1 --arm
 */
void func_02079164(struct Iter020792B8 *it)
{
    struct Node02079164 *prev;
    struct Node02079164 *list;

    for (;;) {
        struct Node02079164 *head;
        struct Node02079164 *tail;
        struct Node02079164 *cur;
        struct Node02079164 *next;
        u32_02079164 lo;
        u32_02079164 hi;
        u32_02079164 arg;
        u32_02079164 fn;
        u32_02079164 e;

        head = 0;
        tail = 0;
        lo = it->base;
        hi = lo + (it->len0 + it->len1);

        e = func_02087988();

        list = g_021542B8;
        prev = 0;
        cur = list;
        while (cur != 0) {
            arg = (u32_02079164)cur->arg;
            next = cur->next;
            fn = (u32_02079164)cur->fn;
            if ((arg == 0 && fn >= lo && fn < hi) || (arg >= lo && arg < hi)) {
                if (tail != 0) {
                    tail->next = cur;
                } else {
                    head = cur;
                }
                if (list == cur) {
                    g_021542B8 = next;
                    list = next;
                }
                cur->next = 0;
                tail = cur;
                if (prev != 0) {
                    prev->next = next;
                }
            } else {
                prev = cur;
            }
            cur = next;
        }

        func_0208799C(e);

        if (head == 0) {
            return;
        }

        do {
            next = head->next;
            if (head->fn != 0) {
                head->fn(head->arg);
            }
            head = next;
        } while (head != 0);

    }
}

/*
 * 0x02079164..0x02079264: the callback-flush worker and its one-line
 * wrapper.
 *
 * func_02079164 repeatedly detaches, inside the 0x02087988/0x0208799C
 * critical section, every node of the global list g_021542B8 whose
 * callback argument (+8) falls in the descriptor's byte range, or whose
 * callback function (+4) does when the argument is null, then runs the
 * detached callbacks with interrupts restored and starts over.  The
 * branch back to the function header is that restart: a callback may
 * queue new nodes, so the list is rescanned until a pass detaches
 * nothing.  The range is [it->base, it->base + it->len0 + it->len1).
 *
 * func_02079254 is folded into the same unit deliberately.  The `bl` at
 * 0x02079258 is 0x02079164's only reference in the whole image, so as two
 * separate files neither can attest the other and both cap at MATCH; in
 * one unit that call site is class `local` and the range is EXACT, which
 * in turn attests 0x02079254 for src/matched/func_020792B8.c.
 *
 * Three things the byte match pinned down, in the order they cost time:
 *
 *  - 0x02087988's result is live in r0 across the whole scan loop and is
 *    0x0208799C's argument (the SDK disable/restore-interrupts pair).
 *    Spelling both as `void f(void)` leaves r0 free, and the allocator
 *    then has one spare register and picks a different colouring for
 *    every local in the function.
 *  - `cur->arg` and `cur->fn` are read into locals before the test, not
 *    referenced inside it: the original loads +4 unconditionally, ahead
 *    of the branch that only one arm of the test needs.
 *  - which locals live in the function scope and which in the `for` body
 *    block decides the colouring outright.  `prev` and `list` outlive the
 *    loop body's declarations here; moving either one inside the block
 *    moves eight or more bytes.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02079164.c  *       --addr 0x02079164 --cc 1.1p1 --arm
 */
int func_02079254(struct Iter020792B8 *it)
{
    func_02079164(it);
    return 1;
}

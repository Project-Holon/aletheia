/*
 * function: func_0206DC00
 * address:  0x0206DC00
 * packet:   pkt_0206BEA0
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * NitroSystem G3D NNS_G3dGeSendDL (gecom.c): send a display list. Under 256
 * bytes, or with no GX DMA channel (GXi_DmaId at 0x020A84C0 == -1), it goes
 * through func_0206DDA4 (NNS_G3dGeBufferOP_N) one command word + args.
 * Otherwise flush the buffer, raise the in-flight word at +4 and start an
 * async GX-command DMA with the completion callback func_0206DBF4
 * (clears *arg) and arg = &g_0214BAB4.busy. The +8 word selects the Fast
 * variant; on TWL hardware (func_02085D3C) an id above 3 is an NDMA channel
 * id - 4 handled by the TWL-only routines at 0x027300F0 / 0x0272FEF4.
 *
 * BLOCKED (MATCH, every concrete byte right under ../2.0/sp2; dsi/1.1p1
 * pushes {r3-r8,lr} and is 12 bytes short):
 *   - PC24 0x027300F0 and 0x0272FEF4: TWL code, region `twl` (the DSi-mode
 *     autoload block of arm9i.bin, 2026-09-24), named with the `twl` token.
 *     asm/twl/twl.s exists only with a user-supplied DSi key (arm9i is
 *     modcrypted; see tools/modcrypt.py), and the only branches in the
 *     image to either address are this function's own two bl, which the
 *     label rule refuses. Class needed: label, via a branch from the
 *     decrypted TWL code.
 *   - ABS32 0x0206DBF4: CLEARED 2026-09-23 (wave 16). The 12-byte leaf is
 *     filed EXACT as src/matched/func_0206DBF4.c (shard pkt_0206DC00) and
 *     the site now resolves as `matched`: 12 of 14 relocations resolve,
 *     the two TWL-ltd PC24 sites above are the whole remaining cap.
 *
 * symbols:
 *   g_020A84C0     0x020A84C0  data
 *   g_0214BAB4     0x0214BAB4  data
 *   func_0206DBF4  0x0206DBF4  arm
 *   func_0206DDA4  0x0206DDA4  arm
 *   func_0206DB80  0x0206DB80  arm
 *   func_02085D3C  0x02085D3C  arm
 *   func_027300F0  0x027300F0  arm  twl
 *   func_0272FEF4  0x0272FEF4  arm  twl
 *   func_02082960  0x02082960  arm
 *   func_02082760  0x02082760  arm
 */

typedef unsigned int u32;

struct GxList { u32 count; u32 cmds[1]; };
struct GeState {
    struct GxList *list;
    volatile u32 busy;
    u32 f8;
};
extern struct GeState g_0214BAB4;
extern u32 g_020A84C0;      /* GXi_DmaId */

typedef void (*MICallback)(void *arg);
extern void func_0206DBF4(void *arg);
extern void func_0206DDA4(u32 cmd, const void *params, u32 n);
extern void func_0206DB80(void);
extern int  func_02085D3C(void);
extern void func_027300F0(u32 ndma, const void *src, u32 sz, MICallback cb, void *arg);
extern void func_0272FEF4(u32 ndma, const void *src, u32 sz, MICallback cb, void *arg);
extern void func_02082960(u32 dma, const void *src, u32 sz, MICallback cb, void *arg);
extern void func_02082760(u32 dma, const void *src, u32 sz, MICallback cb, void *arg);

void func_0206DC00(const u32 *src, u32 sz)
{
    if (sz < 0x100 || g_020A84C0 == (u32)-1) {
        func_0206DDA4(*src, src + 1, (sz >> 2) - 1);
        return;
    }
    func_0206DB80();
    g_0214BAB4.busy = 1;
    if (g_0214BAB4.f8) {
        if (func_02085D3C()) {
            u32 id = g_020A84C0;
            u32 dma = id > 3 ? (u32)-1 : id;
            if (dma == (u32)-1)
                func_027300F0(id > 3 ? id - 4 : (u32)-1, src, sz, func_0206DBF4, (void *)&g_0214BAB4.busy);
            else
                func_02082960(dma, src, sz, func_0206DBF4, (void *)&g_0214BAB4.busy);
        } else {
            func_02082960(g_020A84C0 > 3 ? (u32)-1 : g_020A84C0, src, sz, func_0206DBF4, (void *)&g_0214BAB4.busy);
        }
    } else {
        if (func_02085D3C()) {
            u32 id = g_020A84C0;
            u32 dma = id > 3 ? (u32)-1 : id;
            if (dma == (u32)-1)
                func_0272FEF4(id > 3 ? id - 4 : (u32)-1, src, sz, func_0206DBF4, (void *)&g_0214BAB4.busy);
            else
                func_02082760(dma, src, sz, func_0206DBF4, (void *)&g_0214BAB4.busy);
        } else {
            func_02082760(g_020A84C0 > 3 ? (u32)-1 : g_020A84C0, src, sz, func_0206DBF4, (void *)&g_0214BAB4.busy);
        }
    }
}

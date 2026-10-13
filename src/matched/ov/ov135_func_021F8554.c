/*
 * function: func_021F8554
 * address:  0x021F8554
 * packet:   pkt_021F8554
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * 2026-10-05 (D8 lane19): re-verified, MATCH; unresolved callee is arm9 0x0200960C or 0x02009628 (Thumb getters, printed as .word). Needs label seeds. Source is byte-correct; no C change possible.
 *
 * blocker: ARM9 call targets 0x0200960C and 0x02009628 (Thumb getters 'ldr r1, =0x347 / =0x346; ldrb r0, [r0, r1]; bx lr') are printed as .word data in asm/arm9/main.s, so their relocations stay wildcarded. Every other byte is identical; labelling those two starts makes this EXACT.
 *
  *
  *
 * symbols:
 *   func_021F6B34  0x021F6B34  thumb
 *   func_022026A0  0x022026A0  thumb
 *   POKE_TOOL_ChangeBoxForm  0x020179B8  thumb  arm9
 *   POKE_TOOL_GetPartyParamSize  0x020173EC  thumb  arm9
 *   POKE_TOOL_ChangeForm  0x02017988  thumb  arm9
 */

typedef signed char s8;
typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct {
    u8 pad0[0x18];
    void *status;
    void *prof;
} Ctx;

typedef struct {
    Ctx *ctx;
    u8 pad4[0xC4 - 4];
    u16 box;
    u16 slot;
    u8 padC8[0xCC - 0xC8];
    void *mon;
} Work;

extern int func_021F6B34(int v);
extern u32 func_02017E88(void *p, u32 id, u32 v);
extern u32 POKE_TOOL_ChangeForm(void *p, u32 a);
extern u32 POKE_TOOL_GetPartyParamSize(void);
extern void func_02082B0C(const void *src, void *dst, u32 n);
struct Sub0200852CObj;
struct Sub02009470Obj;
extern int POKE_TOOL_ChangeBoxForm(int a0, int a1);
extern void func_022026A0(u8 *p, u32 k);
extern const void *func_020084F4(const void *p);
extern void func_0201F41C(const u16 *src, u16 *dst, u32 n);
extern u32 func_02008530(const struct Sub0200852CObj *obj);
extern u8 func_0200856C(const struct Sub0200852CObj *obj);
extern u8 func_02008570(const struct Sub0200852CObj *obj);
extern u8 func_02008554(const struct Sub0200852CObj *obj);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern u8 func_02009628(const struct Sub02009470Obj *obj);
extern u8 func_02009584(const struct Sub02009470Obj *obj);
extern u8 func_0200960C(const struct Sub02009470Obj *obj);

void func_021F8554(u8 *dst, Work *p)
{
    u32 species;

    if (func_021F6B34(p->box) != 0) {
        species = func_02017E88(p->mon, 5, 0);
        if (species == 0x1EC || species == 0x286) {
            POKE_TOOL_ChangeForm(p->mon, 0);
        }
        func_02082B0C(p->mon, dst, POKE_TOOL_GetPartyParamSize());
    } else {
        species = func_02017E88(p->mon, 5, 0);
        if (species == 0x1EC || species == 0x286) {
            POKE_TOOL_ChangeBoxForm((int)p->mon, 0);
        }
        func_022026A0(p->mon, (u32)dst);
    }
    func_0201F41C(func_020084F4(p->ctx->prof), (u16 *)(dst + 0x110), 8);
    *(u32 *)(dst + 0x10C) = func_02008530(p->ctx->prof);
    dst[0x120] = func_0200856C(p->ctx->prof);
    dst[0x121] = func_02008570(p->ctx->prof);
    dst[0x122] = func_02008554(p->ctx->prof);
    dst[0xF6] = func_02008550(p->ctx->prof);
    dst[0x124] = 0x15;
    dst[0x125] = 2;
    dst[0x126] = func_02009628(p->ctx->status);
    dst[0x127] = func_02009584(p->ctx->status);
    dst[0xF7] = func_0200960C(p->ctx->status);
}

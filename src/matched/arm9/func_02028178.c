/*
 * unit:     no
 * function: APP_TASKMENU_WIN_Update
 * address:  0x02028178
 * packet:   pkt_02028178
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   _s32_div_f     0x0209C0A4  arm
 *   func_02045770  0x02045770  arm
 *   func_0201C6C4  0x0201C6C4  thumb
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   func_02045730  0x02045730  arm
 *   func_02041B6C  0x02041B6C  arm
 *   APP_TASKMENU_SetWinActive  0x02027B30  thumb
 *   APP_TASKMENU_UpdateCursorColorBlend  0x02027BF4  thumb
 *
 * blocker: MATCH*, one relocation site without a witness. All 160 concrete
 * bytes match.
 *   +0098 APP_TASKMENU_UpdateCursorColorBlend: the `bl` at 0x02028210 inside this function is the
 *     only branch to 0x02027BF4 anywhere in the image (grep over
 *     asm/arm9/main.s and asm/overlays/ finds the definition plus this one
 *     call site), so the `label` class has no witness outside the compared
 *     range and no manifest entry reproduces 0x02027BF4 yet. A second
 *     caller, or an EXACT entry covering APP_TASKMENU_UpdateCursorColorBlend, unsticks it.
 *
 * The trailing `*`: the inferred extent runs to 0x02028230 because the next
 * function, at 0x02028218, saves no lr and so carries no label. It is a
 * six-instruction leaf that zeroes the halfword at +0x14 and tail-calls
 * through a pool word (`ldr r3, [pc, #0]; bx r3`); a second unlabelled leaf
 * (`bx lr`) follows it at 0x0202822E. Both are seeds for
 * layout/function_starts.txt.
 *
 * The per-frame step of an animation object.  Two independent phases: tear
 * down the finished sub-object at +0xc once its sequence has run out, then
 * advance the frame counter at +0x10 and re-post every other frame.  The
 * `(4 / h)` divisor is the same `_s32_div_f` helper APP_TASKMENU_WIN_IsFinish uses on
 * the same two halfwords.
 *
 * The parity test on the frame index is the signed `% 2` sequence
 * (lsrs #31 / lsls #31 / subs / rors #31 / adds), not a mask: the counter
 * is read as a signed value, so a plain `& 1` would be four bytes shorter
 * and wrong.
 */
#include "../include/Obj00864.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

struct Anim {
    u32 obj;
    u32 unk04;
    u32 unk08;
    u32 unk0c;
    u32 unk10_pos;
    u16 frame;
    u16 div;
    u8  unk14[4];
    u8  unk18_a[2];
    u32 ctx;
    u16 unk1c;
    u16 unk1e;
};

struct Descriptor;
extern void *func_02045770(struct Descriptor *obj);
struct Cfg;
struct PrintSys;
struct S;
extern u32 func_0201C6C4(struct PrintSys *p, void *v);
extern void BMP_WIN_TransferChars(struct Descriptor *obj);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_02041B6C(u32 bit);
extern void APP_TASKMENU_SetWinActive(u32 a0, struct S *s, int mode);
extern void APP_TASKMENU_UpdateCursorColorBlend(u16 *phase, u16 *out, u16 mode, u32 slot, u16 c0, u16 c1);

void APP_TASKMENU_WIN_Update(u8 *p)
{
    u32 obj;
    u16 *ctx;

    if (((struct Obj00864 *)p)->fC != 0) {
        if (func_0201C6C4((struct PrintSys *)(*(u32 *)(*(u32 *)&((struct Obj00864 *)p)->f18 + 0x14)),
                          (void *)((u32)func_02045770((struct Descriptor *)((struct Obj00864 *)p)->f0))) == 0) {
            obj = ((struct Obj00864 *)p)->f0;
            BMP_WIN_TransferChars((struct Descriptor *)obj);
            BMP_WIN_MakeScreen((struct Cfg *)obj);
            func_02041B6C(func_02045730((struct Descriptor *)obj));
            ((struct Obj00864 *)p)->fC = 0;
        }
    }

    if (((struct Obj00864 *)p)->f8 != 0) {
        s32 d = 4 / (s32)((struct Obj00864 *)p)->f12;

        if ((u8)((s32)((struct Obj00864 *)p)->f10 / d % 2) == 0) {
            APP_TASKMENU_SetWinActive(((struct Obj00864 *)p)->f0, (struct S *)(*(u32 *)&((struct Obj00864 *)p)->f18), 1);
        } else {
            APP_TASKMENU_SetWinActive(((struct Obj00864 *)p)->f0, (struct S *)(*(u32 *)&((struct Obj00864 *)p)->f18), 0);
        }
        ((struct Obj00864 *)p)->f10 = ((struct Obj00864 *)p)->f10 + 1;
    }

    ctx = *(u16 * *)&((struct Obj00864 *)p)->f18;
    APP_TASKMENU_UpdateCursorColorBlend((u16 *)(p + 0x14), (u16 *)(p + 0x16), (u8)ctx[0], (u8)ctx[1],
                  ((struct Obj00864 *)p)->f1C, ((struct Obj00864 *)p)->f1E);
}

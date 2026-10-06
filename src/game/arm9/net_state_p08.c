/*
 * file:     net_state_p08.c
 * unit:     yes
 * function: func_020369F8, func_02036A50, func_02036AF4
 * address:  0x020369F8
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
 *   str_020A79C4  0x020A79C4  data
 *   str_020A79EC  0x020A79EC  data
 *   func_02034714 0x02034714  arm
 *   func_020366FC 0x020366FC  arm
 *   func_020369C8   0x020369C8  arm
 *   func_020367C4   0x020367C4  arm
 *   func_02082BCC   0x02082BCC  arm
 *   func_02030734 0x02030734  arm
 */
#include "../../matched/include/Obj11349.h"
#include "../../matched/include/Obj08825.h"
#include "../../matched/include/Obj08826.h"

typedef unsigned char u8;

typedef unsigned int  u32;

typedef unsigned short u16;

extern void func_02034714(const char *expr, u32 line, const char *file);
extern u32 func_020366FC(u32 *p);
extern u32 func_020369C8(u32 *p);
extern int   func_020367C4(int slot, u16 *info, u32 arg, int flag);
extern void *func_02082BCC(void *dst, int val, u32 size);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
void func_020369F8(u8 *p);
int func_02036A50(u32 list, u16 *info);
void func_02036AF4(u8 *p, u32 n, u32 a, u32 b);
extern const u8 str_020A79C4[];
extern const u8 str_020A79EC[];



/*
 *           the file string at 0x020A79C4 is not NUL-terminated immediately
 *           before this message, so the `string` class refuses. Every concrete
 *           byte of the body reproduces.
 */
void func_020369F8(u8 *p)
{
    if (((struct Obj11349 *)p)->f10 != 0) {
        ((struct Obj11349 *)p)->f10 = 0;
        return;
    }
    if (func_020366FC((u32 *)p) != 0) {
        return;
    }
    if (func_020366FC((u32 *)(p + 8)) != 0) {
        return;
    }
    func_02034714((const char *)str_020A79C4, 0x12f, (const char *)str_020A79EC);
}



/*
 *           unlabelled work not in the slice and itself only called from here)
 *           and func_020367C4 (pkt_020367C4, not this lane's).  Filing
 *           func_020369F8 would still leave func_020367C4 unwitnessed, so the
 *           park is capped either way.
 *
 * Byte-identical at 164 bytes; only the two PC24 call fields at +0x40 and
 * +0x54 stay wildcarded (func_020369C8 resolves `matched`, func_02082BCC
 * resolves `label x566`).
 *
 * Spellings that mattered: every `return 1` must be a `goto` to one label at
 * the END of the function -- plain `return`s make mwcc predicate all three of
 * them inline (`moveq r0,#1; popeq`) and the frame shifts by 25 bytes.  And
 * `flag = 1;` sits BEFORE the 0xFFFF test, which is why the original shows
 * `mov r8,r6` between the `ldrh` and the `cmp`.
 */
int func_02036A50(u32 list, u16 *info)
{
    int flag = 0;

    if (info[2] == 0)
        goto done;
    while (1) {
        int slot = func_020369C8((u32 *)list);

        if (slot == 0)
            goto done;
        func_020369F8((u8 *)list);
        if (func_020367C4(slot, info, ((struct Obj08825 *)list)->f14, flag) == 0) {
            ((struct Obj08825 *)list)->f10 = slot;
            goto done;
        }
        flag = 1;
        if (info[2] == 0xffff) {
            ((struct Obj08825 *)list)->f10 = slot;
            return 0;
        }
        func_02082BCC((void *)slot, 0, 0x14);
        if (info[2] == 0)
            break;
    }
done:
    return 1;
}


void func_02036AF4(u8 *p, u32 n, u32 a, u32 b)
{
    func_02082BCC(p, 0, 0x28);
    ((struct Obj08826 *)p)->f18 = (u32)func_02030734(b, n * 0x14, 1, (const char *)str_020A79C4, 0x173);
    ((struct Obj08826 *)p)->f1C = n;
    ((struct Obj08826 *)p)->f14 = a;
}

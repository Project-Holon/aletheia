/*
 * function: func_02036A50
 * address:  0x02036A50
 * packet:   pkt_020369F8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * blocker:  label -- func_020369F8 (this lane's own packet pkt_020369F8, but
 *           unlabelled work not in the slice and itself only called from here)
 *           and func_020367C4 (pkt_020367C4, not this lane's).  Filing
 *           func_020369F8 would still leave func_020367C4 unwitnessed, so the
 *           park is capped either way.
 *
 * symbols:
 *   func_020369C8   0x020369C8  arm
 *   func_020369F8   0x020369F8  arm
 *   func_020367C4   0x020367C4  arm
 *   func_02082BCC   0x02082BCC  arm
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

typedef unsigned short u16;
typedef unsigned int   u32;

typedef unsigned char  u8;
extern u32 func_020369C8(u32 *p);
extern void func_020369F8(u8 *p);
extern int   func_020367C4(int slot, u16 *info, u32 arg, int flag);
extern void *func_02082BCC(void *dst, int val, u32 size);

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
        if (func_020367C4(slot, info, *(u32 *)(list + 0x14), flag) == 0) {
            *(u32 *)(list + 0x10) = slot;
            goto done;
        }
        flag = 1;
        if (info[2] == 0xffff) {
            *(u32 *)(list + 0x10) = slot;
            return 0;
        }
        func_02082BCC((void *)slot, 0, 0x14);
        if (info[2] == 0)
            break;
    }
done:
    return 1;
}

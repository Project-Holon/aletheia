/*
 * file:     btlv_effvm_p10.c
 * unit:     yes
 * function: func_021F7E74, func_021F7E84, func_021F7E94, func_021F7EA4
 * address:  0x021F7E74
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021F7A28  0x021F7A28  thumb  ov094
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern void func_021F7A28(int a, u32 b);
void func_021F7E74(u32 a);
void func_021F7E84(u32 a);
void func_021F7E94(int a);
void func_021F7EA4(u32 a);


void func_021F7E74(u32 a)
{
    func_021F7A28(a, 0x285);
}


/*
 * Unlabelled tail-call stub, filed as a witness for the caller ov093 func_021EA354 (wave B3 lane 17).
 */
void func_021F7E84(u32 a)
{
    func_021F7A28(a, 0x286);
}


/*
 * Thumb tail call through r3 with a constant second argument. Labelled in wave D8.
 */
void func_021F7E94(int a)
{
    func_021F7A28(a, 0x26E);
}


/*
 * Unlabelled tail-call stub, filed for the caller ov093 func_021D284C (lane S16).
 */
void func_021F7EA4(u32 a)
{
    func_021F7A28(a, 0x26F);
}

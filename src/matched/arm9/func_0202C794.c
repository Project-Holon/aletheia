/*
 * unit:     no
 * function: func_0202C794
 * address:  0x0202C794
 * packet:   pkt_0202C794
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_0201297C  0x0201297C  thumb
 *   func_0215E6A8  0x0215E6A8  thumb
 *   func_0202C8B8  0x0202C8B8  thumb
 *   func_0202C934  0x0202C934  thumb
 *   func_0202C970  0x0202C970  thumb
 *   func_0202C824  0x0202C824  thumb
 *   func_021647E8  0x021647E8  thumb  ov010
 *   func_02013C10  0x02013C10  thumb
 *
 * note:     wave 16: promoted.  0x021647E8 is the unlabelled ov010 tail-call
 *           thunk matched in src/matched/func_021647E8.c (`matched, overlay`
 *           under the ov010 hint); 0x0202C8B8 now resolves as `matched`.
 *
 * A chain of four probes, each returning a u8 reason code unless it comes
 * back 0xffff ("nothing to say"); the sentinel is kept in a callee-saved
 * register, which is why it is one pool word and four `cmp r0, r7`.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 func_020120F4(void *p);
extern u32 func_0201297C(u32 ctx);
extern u32 func_0215E6A8(u32 a, u16 b);
extern u32 func_0202C8B8(void *a, u32 b, u32 c);
extern u32 func_0202C934(void *a, u32 b, u32 c);
extern u32 func_0202C970(void *a, u32 b, u32 c);
extern u32 func_0202C824(u32 a);
extern u32 func_021647E8(u32 a, u16 b);
extern u32 func_02013C10(u16 a);

u8 func_0202C794(void *a0, u32 a1)
{
    u32 ctx = func_020120F4(a0);
    u32 saved = func_0201297C(ctx);
    u32 r;

    r = func_0215E6A8(ctx, (u16)a1);
    if (r != 0xffff) {
        return (u8)r;
    }
    r = func_0202C8B8(a0, ctx, a1);
    if (r != 0xffff) {
        return (u8)r;
    }
    r = func_0202C934(a0, ctx, a1);
    if (r != 0xffff) {
        return (u8)r;
    }
    r = func_0202C970(a0, ctx, a1);
    if (r != 0xffff) {
        return (u8)r;
    }
    if (func_0202C824(ctx) != 0) {
        return (u8)func_021647E8(saved, (u16)a1);
    }
    return (u8)func_02013C10((u16)a1);
}

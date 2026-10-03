/*
 * function: func_021EA058
 * address:  0x021EA058
 * packet:   pkt_ov093_021EA058
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   sub_020082B8  0x020082B8  thumb
 *   sub_020082D4  0x020082D4  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;

struct MyItemSave;
extern void sub_020082B8(struct MyItemSave *p, const s16 *a, const s16 *b);
extern void sub_020082D4(struct MyItemSave *p, u16 a, u16 b);

void func_021EA058(char *p)
{
    if (*(u16 *)(p + 0xde) != 0 && *(u8 *)(p + 0x12c) != 6 && *(int *)(p + 0xd0) != 1) {
        sub_020082B8(*(void **)(p + 0xe4), (s16 *)(p + 0xf8), (s16 *)(p + 0x100));
        sub_020082D4(*(void **)(p + 0xe4), *(u16 *)(p + 0xde), *(u8 *)(p + 0xf2));
    }
}

/*
 * function: NATSUKI_CalcUseItem
 * address:  0x0201B7B4
 * packet:   pkt_0201B7A0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02020FE4  0x02020FE4  thumb
 *   NATSUKI_Apply  0x0201B850  thumb
 *
 * Three bytes are built one selector at a time - selectors 0x3C, 0x3D, 0x3E
 * - and the three-byte buffer is then handed to NATSUKI_Apply along with
 * the caller's own second and fourth arguments.  No literal pool: the only
 * pointers are the two call targets.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/NATSUKI_CalcUseItem.c \
 *       --func NATSUKI_CalcUseItem --addr 0x0201B7B4 --cc 1.1p1 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed char    s8;
typedef unsigned int   u32;

extern u32 func_02020FE4(void *a, u32 sel, u32 id);
extern void NATSUKI_Apply(void *mon, const s8 *tbl, int a2, u32 a3);

void NATSUKI_CalcUseItem(void *a0, int a1, u16 a2, u16 a3)
{
    u8 buf[3];
    int i;

    for (i = 0; i < 3; i++) {
        buf[i] = (u8)func_02020FE4((void *)(u32)a1, (u16)(i + 0x3C), a3);
    }
    NATSUKI_Apply(a0, (const s8 *)buf, a2, a3);
}

/*
 * function: PROF_WORD_Delete
 * address:  0x021F5354
 * packet:   pkt_021F5354
 * region:   ov194
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_020307B0(void *p);

void PROF_WORD_Delete(u8 *p)
{
    int i;

    for (i = 0; i < 7; i++) {
        func_020307B0((void *)(*(u32 *)(p + i * 4)));
    }
    func_020307B0((void *)((u32)p));
}


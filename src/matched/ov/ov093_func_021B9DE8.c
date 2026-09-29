/*
 * function: func_021B9DE8
 * address:  0x021B9DE8
 * packet:   pkt_ov093_021B9DE8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT* (extent 80, compiled 78, trailing padding)
 *
 * symbols:
 *   func_020307B0  0x020307B0  arm
 */

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern void func_020307B0(void *p);

void func_021B9DE8(char *p)
{
    u32 i;
    char *q;

    for (i = 0; i < 4; i++) {
        q = p + i * 0x28;
        if (*(void **)(q + 0x20)) {
            func_020307B0(*(void **)(q + 0x20));
            *(void **)(q + 0x20) = 0;
        }
        if (*(void **)(q + 0x24)) {
            func_020307B0(*(void **)(q + 0x24));
            *(void **)(q + 0x24) = 0;
        }
    }
    for (i = 0; i < 4; i++) {
        q = p + i * 4;
        if (*(void **)(q + 0x3e0)) {
            func_020307B0(*(void **)(q + 0x3e0));
            *(void **)(q + 0x3e0) = 0;
        }
    }
}

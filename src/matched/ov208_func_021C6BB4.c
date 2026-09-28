/*
 * function: ov208_func_021C6BB4
 * address:  0x021C6BB4
 * packet:   pkt_ov208_021C6BB4
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ov208_func_021C6D10  0x021C6D10  thumb
 *   ov208_func_021C6C00  0x021C6C00  thumb
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern int  ov208_func_021C6D10(void *a0, u8 *p, int key);
extern u32  ov208_func_021C6C00(void *a0, u8 *p, int key);

#define W(o) (*(u32 *)(p + (o)))

void ov208_func_021C6BB4(void *a0, u8 *p, int key)
{
    if ((W(0x6b8) == 4 && W(0x6b4) != 0 && W(0x694) == 5) || W(0x6d4) != 0) {
        if (ov208_func_021C6D10(a0, p, key) == 0)
            ov208_func_021C6C00(a0, p, key);
    }
}

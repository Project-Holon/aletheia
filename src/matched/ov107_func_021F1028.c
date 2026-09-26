/*
 * function: func_021F1028
 * address:  0x021F1028
 * packet:   pkt_ov107_021F1028
 * region:   ov107
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

extern int func_020399A8(void *);
extern void func_02039C68(int, int, int);

void func_021F1028(int *p)
{
    int r = func_020399A8(p);
    func_02039C68(r, 0x40, 4);
    p[1] = 4;
}

/*
 * function: func_0205082C
 * address:  0x0205082C
 * packet:   pkt_0205082C
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_020500A0(char *e);

void func_0205082C(void *p, int idx, u16 h)
{
    char *e = (char *)(*(u32 *)((char *)p + 24) + idx * 40);
    *(u16 *)(e + 14) = h;
    func_020500A0(e);
}

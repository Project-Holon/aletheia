/*
 * function: func_0200E18C
 * address:  0x0200E18C
 * packet:   pkt_0200E024
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Runs func_0200E06C, then func_0200E124, then the initialiser.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0200E18C.c \
 *       --func func_0200E18C --addr 0x0200E18C --thumb --cc 1.1p1
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern void func_0200E06C(char *p);
extern void func_0200E124(u32 *p, u32 a);
extern void func_0200E024(void *obj);

void func_0200E18C(u8 *p, u32 a)
{
    func_0200E06C((char *)p);
    func_0200E124((u32 *)p, a);
    func_0200E024(p);
}

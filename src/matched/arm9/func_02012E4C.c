/*
 * function: func_02012E4C
 * address:  0x02012E4C
 * packet:   pkt_02012E4C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02012E4C.c \
 *       --func func_02012E4C --addr 0x02012E4C --cc 1.1p1 --thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
typedef signed char s8;

extern void func_02034F84(int v);
extern void func_02012CE0(u8 *p);
extern void func_0201042C(void);
extern void func_0203516C(int mode);
extern void func_02007374(char *a0, u32 a1);

void func_02012E4C(u8 *p, u32 id)
{
    func_02034F84(0x80);
    func_02012CE0(p);
    func_0201042C();
    *(u8 *)(p + 0x1ce) = 1;
    func_0203516C(2);
    func_02007374((char *)*(u32 *)p, id);
}

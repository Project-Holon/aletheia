/*
 * function: func_021DECB0
 * address: 0x021DECB0
 * packet: pkt_ov183_021DECB0
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two trailing zero bytes are alignment padding before the next labelled function.
 * symbols:
 *   func_021DF388 0x021DF388 thumb ov183
 *   func_021FC734 0x021FC734 thumb ov186
 *   func_020409B4 0x020409B4 arm
 *   func_021FB494 0x021FB494 thumb ov186
 *   func_021FC0C8 0x021FC0C8 thumb ov186
 *   func_021FBDA4 0x021FBDA4 thumb ov186
 *   func_021FD744 0x021FD744 thumb ov186
 */
typedef unsigned int   u32;
typedef unsigned char  u8;
extern void func_021DF388(char *p);
extern void func_021FC734(u8 *p);
extern void func_020409B4(u32 index);
extern void func_021FB494(char *p);
extern void func_021FC0C8(char *p, unsigned i);
extern void func_021FBDA4(void *, int);
extern void func_021FD744(void *);
void func_021DECB0(void *a, int b, char *p)
{
    func_021DF388(p + 0x28);
    *(int *)(p + 0x100) = 0;
    func_021FC734(*(void **)(p + 0xC));
    *(void **)(p + 0xC) = 0;
    func_021FC734(*(void **)(p + 8));
    *(void **)(p + 8) = 0;
    func_020409B4(4);
    func_020409B4(1);
    func_021FB494(*(void **)(p + 4));
    *(void **)(p + 4) = 0;
    func_021FC0C8(*(void **)(*(char **)(p + 0x108) + 0x10), 6);
    func_021FBDA4(*(void **)(*(char **)(p + 0x108) + 0x10), 24);
    *(int *)(p + 0x104) = 0;
    func_021FD744(a);
}

/*
 * function: func_021DFF78
 * address: 0x021DFF78
 * packet: pkt_ov183_021DFF78
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021FB494 0x021FB494 thumb ov186
 *   func_021FCC80 0x021FCC80 thumb ov186
 *   func_0201F868 0x0201F868 thumb
 *   func_021FBDA4 0x021FBDA4 thumb ov186
 *   func_020409B4 0x020409B4 arm
 */
typedef unsigned short u16;
typedef unsigned int   u32;
extern void func_021FB494(char *p);
extern void func_021FCC80(char *p);
extern void func_0201F868(void *);
extern void func_021FBDA4(int a, unsigned mode);
extern void func_020409B4(u32 index);
int func_021DFF78(char *p, char *q)
{
    if (*(void **)(p + 0xc)) {
        func_021FB494(*(void **)(p + 0xc));
        *(void **)(p + 0xc) = 0;
    }
    func_021FCC80(*(void **)(p + 0x18));
    *(void **)(p + 0x18) = 0;
    func_0201F868(*(void **)(p + 0x14));
    *(void **)(p + 0x14) = 0;
    func_021FBDA4(*(int *)(q + 8), 27);
    func_020409B4(4);
    return 1;
}

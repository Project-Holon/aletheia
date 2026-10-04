/*
 * function: func_021B98F8
 * address: 0x021B98F8
 * packet: pkt_ov072_021B98F8
 * region: ov072
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * note: trailing two-byte alignment padding.
 * symbols:
 *   func_021B9944 0x021B9944 thumb ov072
 *   func_021BB758 0x021BB758 thumb ov072
 *   func_021B9958 0x021B9958 thumb ov072
 */
#include "../include/Obj20772.h"
extern void func_021B9944(void *);
extern void func_021BB758(char *);
extern int func_021B9958(int *);
int func_021B98F8(int a, int b, int c, char *p) {
    func_021B9944(p + 4);
    func_021BB758(*(char * *)&((struct Obj20772 *)p)->f0);
    return func_021B9958((int *)(p + 4)) != 0;
}

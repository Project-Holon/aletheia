/*
 * function: func_021B99AC
 * address: 0x021B99AC
 * packet: pkt_ov072_021B99AC
 * region: ov072
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * note: trailing two-byte alignment padding.
 * symbols:
 *   func_0204E720 0x0204E720 arm
 *   func_0204E804 0x0204E804 arm
 *   func_021B9964 0x021B9964 thumb ov072
 */
typedef signed int     s32;
typedef unsigned int   u32;
extern void func_0204E720(u32 a, s32 b, s32 c, s32 d);
extern int func_0204E804(void);
extern void func_021B9964(int *);
void func_021B99AC(int *p, int *state) {
    switch (*state) {
    case 0: func_0204E720(3,0,16,0); *state = 1; break;
    case 1: if (func_0204E804() == 0) *state = 2; break;
    case 2: func_021B9964(p); break;
    }
}

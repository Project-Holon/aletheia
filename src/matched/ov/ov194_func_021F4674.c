/*
 * function: func_021F4674
 * address: 0x021F4674
 * packet: pkt_ov194_021F4674
 * region: ov194
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204E720 0x0204E720 arm
 *   func_0204E804 0x0204E804 arm
 *   func_021F462C 0x021F462C thumb ov194
 *   func_021F47B4 0x021F47B4 thumb ov194
 */
typedef signed int     s32;
typedef unsigned int   u32;
extern void func_0204E720(u32 a, s32 b, s32 c, s32 d);
extern int func_0204E804(void);
extern void func_021F462C(unsigned char *,unsigned);
extern void func_021F47B4(unsigned char *owner, void *unused, char *p);
void func_021F4674(unsigned char *p,int *state) {
    switch (*state) {
    case 0: func_0204E720(3,16,0,0); *state=1; break;
    case 1: if (!func_0204E804()) *state=2; break;
    case 2: func_021F462C(p,(unsigned)func_021F47B4); break;
    }
}

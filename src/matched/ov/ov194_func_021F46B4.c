/*
 * function: func_021F46B4
 * address: 0x021F46B4
 * packet: pkt_ov194_021F46B4
 * region: ov194
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   FADE_Start 0x0204E720 arm
 *   FADE_IsActive 0x0204E804 arm
 *   func_021F462C 0x021F462C thumb ov194
 *   func_021F4A5C 0x021F4A5C thumb ov194
 */
typedef signed int     s32;
typedef unsigned int   u32;
extern void FADE_Start(u32 a, s32 b, s32 c, s32 d);
extern int FADE_IsActive(void);
extern void func_021F462C(unsigned char *,unsigned);
extern void func_021F4A5C(unsigned char *a, int unused, char *p);
void func_021F46B4(unsigned char *p,int *state) {
    switch (*state) {
    case 0: FADE_Start(3,0,16,0); *state=1; break;
    case 1: if (!FADE_IsActive()) *state=2; break;
    case 2: func_021F462C(p,(unsigned)func_021F4A5C); break;
    }
}

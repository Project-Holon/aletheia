/*
 * function: func_021EDA04
 * address:  0x021EDA04
 * packet:   pkt_ov093_021EDA04
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021B98AC  0x021B98AC  thumb  ov093
 *   func_021D5B68  0x021D5B68  thumb  ov093
 *   func_021F803C  0x021F803C  thumb  ov094
 */
typedef unsigned char u8;
typedef unsigned int u32;
struct E { int a0; u8 *owner; u8 k8; u8 v9; u8 fa; u8 fb; };
extern int func_021B98AC(char *const *, u8);
extern int func_021D5B68(int);
extern void func_021F803C(u32, u32, u32);
void func_021EDA04(struct E *e)
{
    if (e->fb != 0) {
        e->a0 = func_021B98AC(*(char *const **)(e->owner + 0x138), e->k8);
        if (func_021D5B68(e->a0) == 0) {
            func_021F803C(*(u32 *)(e->owner + 0x134), e->a0, e->v9);
            e->fa = 1;
        }
    }
}

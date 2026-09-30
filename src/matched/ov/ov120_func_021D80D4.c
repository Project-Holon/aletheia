/*
 * function: func_021D80D4
 * address: 0x021D80D4
 * packet: pkt_ov120_021D80D4
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * follower: two zero padding bytes at 021D8116.
 * symbols:
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 *   func_020456F8 0x020456F8 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_020452E8 0x020452E8 arm
 */
extern void *func_02045770(void *);
extern void func_02043B5C(void *,int);
extern void func_02045334(void *);
extern void func_020456F8(void *);
extern void func_02041B6C(int);
extern void func_020452E8(void *);
void func_021D80D4(char *p)
{
    if (*(void **)(p+0x84)) {
        func_02043B5C(func_02045770(*(void **)(p+0x84)),0);
        func_02045334(*(void **)(p+0x84));
        func_020456F8(*(void **)(p+0x84));
        func_02041B6C(1);
        func_020452E8(*(void **)(p+0x84));
        *(void **)(p+0x84)=0;
    }
}

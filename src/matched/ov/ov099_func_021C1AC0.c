/*
 * function: func_021C1AC0
 * address: 0x021C1AC0
 * packet: pkt_ov099_021C1AC0
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021C1A44 0x021C1A44 thumb ov099
 *   func_021C1F74 0x021C1F74 thumb ov099
 *   func_02051C6C 0x02051C6C arm
 *   func_0201ED04 0x0201ED04 thumb
 *   func_02043598 0x02043598 arm
 */
extern int func_021C1A44(char *);
extern void func_021C1F74(char *);
extern void func_02051C6C(void *);
extern void func_0201ED04(void *);
extern void func_02043598(int, int);
void func_021C1AC0(char *p)
{
    if (func_021C1A44(p)) {
        func_021C1F74(p);
        func_02051C6C(*(void **)(p + 0x8c8));
        *(void **)(p + 0x8c8) = 0;
        func_0201ED04(*(void **)(p + 0x8b0));
        *(void **)(p + 0x8b0) = 0;
        func_02043598(1, 1);
        func_02043598(14, 0);
    }
}

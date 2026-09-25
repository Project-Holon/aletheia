/*
 * function: func_021F966C
 * address:  0x021F966C
 * packet:   pkt_021F966C
 * region:   ov186
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * Blocker: every concrete byte reproduces; 0x0200E9F4 and 0x0200EA04 are
 *   unlabelled Thumb leaves with no branch anywhere outside this range, so
 *   the two calls stay wildcarded.
 *
 * symbols:
 *   func_02012EBC   0x02012EBC  thumb
 *   func_021FC4DC   0x021FC4DC  thumb
 *   func_0200E9F4   0x0200E9F4  thumb
 *   func_0200EA04   0x0200EA04  thumb
 *
 * Fill the output record from the source object and its nested handle.
 */


extern int func_02012EBC(int);
extern int func_021FC4DC(int);
extern void func_0200E9F4(int);
extern int func_0200EA04(void);

void func_021F966C(char *r5, int *r4)
{
    int x;
    x = func_02012EBC(*(int *)(*(int *)(*(int *)((char *)r4 + 0x18) + 0xC) + 4));
    *(int *)(r5 + 8) = r4[1];
    *(int *)(r5 + 4) = r4[3];
    *(int *)(r5 + 0xC) = r4[2];
    *(int *)r5 = func_021FC4DC(r4[0]);
    *(int *)(r5 + 0x10) = *(int *)(*(int *)(*(int *)((char *)r4 + 0x18) + 0xC) + 4);
    func_0200E9F4(x);
    *(int *)(r5 + 0x14) = func_0200EA04();
}

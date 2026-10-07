/*
 * function: func_021F96AC,func_021F9728
 * unit: yes
 * extent: empty-return follower 0x021F9728; zero halfwords at 0x021F9726
 *   and 0x021F972A are alignment padding.
 * address: 0x021F96AC
 * packet: pkt_ov186_021F96AC
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: ctx declared `const int *` lets the type-6 arm load ctx[5]/ctx[6]
 *   ahead of the out[0] store (021F96E4..021F96EA); a plain pointer left 13
 *   bytes, block locals for the two loads 74.
 * symbols:
 *   func_021FC4DC 0x021FC4DC thumb ov186
 *   func_02082BCC 0x02082BCC arm
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern u32 func_021FC4DC(u8 *p);
extern void func_02082BCC(void *dstp, u8 data, u32 size);
void func_021F96AC(int *out, int *source, const int *ctx, int type)
{
    out[7] = *(int *)(source[6] + 8);
    out[10] = *(int *)(source[6] + 8) + 0x17C0;
    if (type == 1) {
        out[0] = ctx[2];
        *(int *)(*(int *)(source[6] + 8) + 0x17C4) = out[0];
        func_02082BCC((void *)out[10], 0, 4);
    } else if (type == 6) {
        out[0] = 3;
        out[8] = ctx[5];
        out[9] = ctx[6];
        *(int *)(*(int *)(source[6] + 8) + 0x17C4) = 3;
        func_02082BCC((void *)out[10], 0, 4);
    } else if (type == 2) {
        out[0] = *(int *)(*(int *)(source[6] + 8) + 0x17C4);
        out[1] = 1;
    }
    out[4] = source[1];
    out[2] = source[3];
    out[5] = source[2];
    out[3] = func_021FC4DC((u8 *)source[0]);
    out[6] = source[5];
}
void func_021F9728(void)
{
}

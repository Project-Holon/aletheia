/*
 * function: BTLV_EFFVM_ResolveSideFromVm
 * address:  0x021FD070
 * packet:   pkt_021FD1CC
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   VM_GetUserData  0x02011324  thumb  arm9
 */
struct OneBit {
    unsigned int v : 1;
};

extern struct OneBit *VM_GetUserData(int a);

int BTLV_EFFVM_ResolveSideFromVm(int a, int b)
{
    int r = b;

    if (VM_GetUserData(a)->v)
        r ^= 1;
    return r;
}

/*
 * function: GFL_USE_PollFrameInput
 * address:  0x020055F8
 * packet:   pkt_02005438
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   PROCSYS_MainGlobal  0x020312B4  arm
 *   GFL_NET_ERR_PollNetState  0x0200F2D4  thumb
 */

extern void func_02034F5C(void);
extern int GFL_NET_ERR_PollNetState(void);
extern int PROCSYS_MainGlobal(void);
extern void func_0203F3F0(void);
void GFL_USE_PollFrameInput(void)
{
    func_02034F5C();
    GFL_NET_ERR_PollNetState();
    PROCSYS_MainGlobal();
    func_0203F3F0();
}

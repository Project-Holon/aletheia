/*
 * unit: yes
 * function: COMPATIBLE_IRC_SYS_SetPlayerReady,COMPATIBLE_IRC_SYS_GetRecvBuffer,COMPATIBLE_IRC_SYS_GetRecvSize,COMPATIBLE_IRC_SYS_IsEqual,COMPATIBLE_IRC_SYS_ClearPartnerReady,COMPATIBLE_IRC_SYS_StartSessionCallback,COMPATIBLE_IRC_SYS_ExitCallback
 * address: 0x021B6634
 * packet: pkt_ov101_021B6634
 * region: ov101
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02080D24 0x02080D24 arm
 */
typedef unsigned int u32;
extern u32 func_02080D24(u32);
void COMPATIBLE_IRC_SYS_SetPlayerReady(u32 *p, int i)
{
    p[19] |= 1 << i;
    if (func_02080D24(p[19]) >= 2)
        p[20] = 1;
}
int COMPATIBLE_IRC_SYS_GetRecvBuffer(void) { return 0x021B7520; }
int COMPATIBLE_IRC_SYS_GetRecvSize(void) { return 4; }
int COMPATIBLE_IRC_SYS_IsEqual(int a, int b) { return a == b ? 1 : 0; }
void COMPATIBLE_IRC_SYS_ClearPartnerReady(int *p) { p[20] = 0; }
void COMPATIBLE_IRC_SYS_StartSessionCallback(void) { }
void COMPATIBLE_IRC_SYS_ExitCallback(int *p) { p[21] = 1; }

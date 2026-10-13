/*
 * function: func_021CB8AC
 * address:  0x021CB8AC
 * packet:   pkt_ov021_021CB8AC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Task step: closes the message window, optionally resumes the field, then waits for the save to finish.
 *
 * Formerly MATCH on unwitnessed callees; their matched entries now witness them.
 * The caller leaves the owner pointer in r0 for BSUBWAY_COMM_DeleteCommandTable, so the extern
 * keeps one (ignored) parameter.
 *
 * symbols:
 *   GFL_NET_IsParentAid  0x0203D378  arm
 *   GFL_NET_SetLoginOption  0x0203D7BC  arm
 *   BSUBWAY_COMM_DeleteCommandTable  0x02167B18  thumb  ov010
 *   GFL_NET_GetNegotiationNum  0x0203D1B4  arm
 *   GFL_NET_Exit  0x0203CEAC  arm
 *   GFL_NET_IsSessionNull  0x0203CDBC  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u8  pad0[0xc];
    u16 lo   : 9;
    u16 flag : 1;
    u16 hi   : 6;
} Owner;

extern u32 GFL_NET_IsParentAid(void);
extern void GFL_NET_SetLoginOption(u8 a0);
extern void BSUBWAY_COMM_DeleteCommandTable(void *p);
extern int GFL_NET_GetNegotiationNum(void);
extern int GFL_NET_Exit(int a0);
extern int GFL_NET_IsSessionNull(void);

int func_021CB8AC(void *task, int *state, Owner **work)
{
    switch (*state) {
    case 0:
        if (GFL_NET_IsParentAid() == 1)
            GFL_NET_SetLoginOption(0);
        if ((*work)->flag == 1)
            BSUBWAY_COMM_DeleteCommandTable(*work);
        (*state)++;
        break;
    case 1:
        if (GFL_NET_IsParentAid() == 1) {
            if (GFL_NET_GetNegotiationNum() <= 1) {
                GFL_NET_Exit(0);
                (*state)++;
            }
        } else {
            GFL_NET_Exit(0);
            (*state)++;
        }
        break;
    case 2:
        if (GFL_NET_IsSessionNull() == 1)
            return 1;
        break;
    }
    return 0;
}

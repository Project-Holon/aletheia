/*
 * function: UNION_COMM_UpdateReset
 * address:  0x02172D7C
 * packet:   pkt_ov012_02172D7C
 * region:   ov012
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   GFL_NET_Exit  0x0203CEAC  arm
 *   GFL_NET_StartSession  0x0203CBAC  arm
 *   GFL_NET_EndDeviceWrapper  0x0203D0FC  arm
 *   UNION_COMM_ExitCallback  0x02172D14  thumb  ov012
 *   UNION_COMM_SessionStartCallback  0x02172C98  thumb  ov012
 *   d_02175380     0x02175380  data   ov012
 */

typedef unsigned char u8;

typedef unsigned int   u32;
struct Req;
extern int GFL_NET_Exit(int a0);
extern void GFL_NET_StartSession(struct Req *req, u32 a2, u32 a3);
extern void GFL_NET_EndDeviceWrapper(int a);
extern void UNION_COMM_ExitCallback(u8 *p);
extern void UNION_COMM_SessionStartCallback(u8 *p);
extern char d_02175380[];

int UNION_COMM_UpdateReset(u8 *p)
{
    switch (p[0x3561]) {
    case 0:
        if (p[0x3562] == 1) {
            return 1;
        }
        return 0;
    case 1:
        switch (p[0x3562]) {
        case 0:
        case 1:
            p[0x3561] = 2;
            break;
        case 2:
            p[0x3561] = 4;
            break;
        default:
            p[0x3561] = 0;
            break;
        }
        break;
    case 2:
        p[0x3560] = 4;
        if (GFL_NET_Exit((int)UNION_COMM_ExitCallback) == 0) {
            UNION_COMM_ExitCallback(p);
        }
        p[0x3561]++;
        break;
    case 3:
        if (p[0x3560] == 5) {
            if (p[0x3562] == 1) {
                p[0x3561] = 0;
            } else {
                p[0x3561]++;
            }
        }
        break;
    case 4:
        p[0x3560] = 1;
        GFL_NET_StartSession((struct Req *)d_02175380, (u32)UNION_COMM_SessionStartCallback, (u32)p);
        p[0x3561]++;
        break;
    case 5:
        if (p[0x3560] >= 2) {
            p[0x3560] = 3;
            GFL_NET_EndDeviceWrapper(0);
            p[0x3561] = 0;
        }
        break;
    }
    return 1;
}

/*
 * function: INTRUDE_CMD_RecvJoinRequest
 * address:  0x02173DE0
 * packet:   pkt_ov011_02173DE0
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0203D378  0x0203D378  arm
 *   INTRUDE_COMM_ReceiveJoinRequest  0x02176048  thumb ov011
 *   func_020399A8  0x020399A8  arm
 *   func_0203D1E8  0x0203D1E8  arm
 *   NET_WHPIPE_SetBeaconStatus  0x021780FC  thumb ov014
 */

typedef unsigned int   u32;
typedef unsigned char  u8;
u32 func_0203D378(void);
int INTRUDE_COMM_ReceiveJoinRequest(char *a, char *b, void *c, int d);
struct Entry;
struct Entry *func_020399A8(void);
void func_0203D1E8(u32 unused, void *arg);
void NET_WHPIPE_SetBeaconStatus(u8 value);

typedef struct { int w0; unsigned f : 4; } S;

void INTRUDE_CMD_RecvJoinRequest(int a, int b, S *c, char *d)
{
    unsigned t;

    if (func_0203D378()) {
        if (INTRUDE_COMM_ReceiveJoinRequest(d, d + 0x1AC, c, a) == 1) {
            t = c->f;
            if (t == 0 || t == 3) {
                func_0203D1E8((u32)func_020399A8(), 0);
                NET_WHPIPE_SetBeaconStatus(1);
                d[0x93C] = 1;
            }
        }
    }
}

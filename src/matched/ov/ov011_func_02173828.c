/*
 * function: INTRUDE_COMM_SendStatusRecord
 * address:  0x02173828
 * packet:   pkt_ov011_02173828
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   INTRUDE_COMM_IsLinked  0x021736D8  thumb ov011
 *   func_020399A8  0x020399A8  arm
 *   GFL_NET_IsSendQueueEntryOfHandle  0x0203D578  arm
 *   func_02082D44  0x02082D44  arm
 *   func_0203D3F8  0x0203D3F8  arm
 *   func_0203D378  0x0203D378  arm
 *   INTRUDE_COMM_SetSessionRequestSendFlag  0x02175920  thumb ov011
 *   INTRUDE_COMM_SetSessionResultSendFlag  0x0217592C  thumb ov011
 */

int INTRUDE_COMM_IsLinked(void);
struct Entry;
struct Entry *func_020399A8(void);
int GFL_NET_IsSendQueueEntryOfHandle(int a, int b);
void func_02082D44(void *d, void *s, int n);
unsigned int func_0203D3F8(unsigned int entry, unsigned int sendID, unsigned int c, unsigned int d, unsigned int e, unsigned int f, unsigned int g, unsigned int h);
typedef unsigned int   u32;
u32 func_0203D378(void);
void INTRUDE_COMM_SetSessionRequestSendFlag(void *p);
void INTRUDE_COMM_SetSessionResultSendFlag(void *p);

int INTRUDE_COMM_SendStatusRecord(char *p)
{
    int r;

    if (INTRUDE_COMM_IsLinked() == 0) {
        return 0;
    }
    if (GFL_NET_IsSendQueueEntryOfHandle((int)func_020399A8(), 0x203) == 1) {
        return 0;
    }
    func_02082D44(p + 0x160, p + 0x3A4, 0x4C);
    r = func_0203D3F8((int)func_020399A8(), 0xFF, 0x203, 0x4C, (unsigned int)(p + 0x3A4), 0, 0, 1);
    if (r == 1) {
        p[0x8FE] = 0;
        if (func_0203D378() == 1) {
            p[0x903] = 1;
            INTRUDE_COMM_SetSessionRequestSendFlag(p + 0x1AC);
            INTRUDE_COMM_SetSessionResultSendFlag(p + 0x1AC);
        }
    }
    return r;
}

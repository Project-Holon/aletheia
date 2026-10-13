/*
 * function: FIELD_MSGBG_DeleteAllSubMsgWin
 * address:  0x02191978
 * packet:   pkt_ov021_02191978
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_MSGBG_FreeSubMsgWin  0x0219194C  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef short          s16;

extern int FIELD_MSGBG_FreeSubMsgWin(void *a);

typedef struct P { u8 pad[0xA0]; volatile u32 arr[8]; } P;
void FIELD_MSGBG_DeleteAllSubMsgWin(P *p)
{
    int i;
    for (i = 0; i < 8; i++) {
        if (p->arr[i] != 0) {
            p->arr[i] = 0;
            {
                u32 t = p->arr[i];
                p->arr[i] = 0;
                FIELD_MSGBG_FreeSubMsgWin((void *)t);
            }
        }
    }
}

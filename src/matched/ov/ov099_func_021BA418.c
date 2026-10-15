/*
 * function: WIFICLUBACTOR_UpdatePlayer
 * address:  0x021BA418
 * packet:   pkt_ov099_021BA418
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Lever: the pad read is a named local (t) assigned before k = 2, so the
 * movs r7,#2 lands after the first blx.
 *
 * symbols:
 *   WF2DMAP_OBJ_GetSlot  0x021C49A4  thumb  ov127
 *   KEY_GetCont  0x0203630C  arm
 *   WIFICLUBACTOR_QueueMoveCommand  0x021BA594  thumb  ov099
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;

typedef struct {
    char pad00[0xc];
    int fc;
} W;

typedef struct {
    void *f0;
} S;

extern int WF2DMAP_OBJ_GetSlot(u8 *p, unsigned int i);
extern unsigned int KEY_GetCont(void);
extern void WIFICLUBACTOR_QueueMoveCommand(char *p, int a, int b, int c);

int WIFICLUBACTOR_UpdatePlayer(W *w, S *s)
{
    int a;
    int b;
    int k;
    int t;

    a = WF2DMAP_OBJ_GetSlot(s->f0, 6);
    b = WF2DMAP_OBJ_GetSlot(s->f0, 4);
    if (WF2DMAP_OBJ_GetSlot(s->f0, 5) != 0) {
        return 0;
    }
    if (w->fc == 1) {
        return 0;
    }
    t = KEY_GetCont();
    k = 2;
    if (t & 2) {
        k = 3;
    }
    if (KEY_GetCont() & 0x40) {
        if (a == 0) {
            WIFICLUBACTOR_QueueMoveCommand((char *)w, k, a, b);
        } else {
            WIFICLUBACTOR_QueueMoveCommand((char *)w, 1, 0, b);
        }
    } else if (KEY_GetCont() & 0x80) {
        if (a == 1) {
            WIFICLUBACTOR_QueueMoveCommand((char *)w, k, a, b);
        } else {
            WIFICLUBACTOR_QueueMoveCommand((char *)w, 1, 1, b);
        }
    } else if (KEY_GetCont() & 0x20) {
        if (a == 2) {
            WIFICLUBACTOR_QueueMoveCommand((char *)w, k, a, b);
        } else {
            WIFICLUBACTOR_QueueMoveCommand((char *)w, 1, 2, b);
        }
    } else if (KEY_GetCont() & 0x10) {
        if (a == 3) {
            WIFICLUBACTOR_QueueMoveCommand((char *)w, k, a, b);
        } else {
            WIFICLUBACTOR_QueueMoveCommand((char *)w, 1, 3, b);
        }
    }
    return 0;
}

/*
 * function: WORLDTRADE_ADAPTER_UpdateMessageSystem
 * address:  0x022029F8
 * packet:   pkt_022029F8
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   PRINTSYS_QUE_Main  0x0201C4E4  thumb  arm9
 *   BMP_WIN_TransferChars  0x02045334  arm  arm9
 *   PRINTSYS_QUE_IsExistTarget  0x0201C6C4  thumb  arm9
 *   BMP_WIN_GetBmp  0x02045770  arm  arm9
 */

typedef signed char s8;
typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct {
    void *win;
    u8 busy;
} Ent;

typedef struct {
    u8 pad0[4];
    void *queue;
    u8 pad8[0x10 - 8];
    Ent ent[8];
    void *active[8];
} Printer;

struct Descriptor;
struct PrintSys;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern u32 PRINTSYS_QUE_IsExistTarget(struct PrintSys *p, void *v);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern u32 PRINTSYS_QUE_Main(struct PrintSys *ps);

void WORLDTRADE_ADAPTER_UpdateMessageSystem(Printer *q)
{
    int i;
    void *queue;

    for (i = 0; i < 8; i++) {
        if (q->active[i] != 0) {
            queue = q->queue;
            if (q->ent[i].busy != 0 && PRINTSYS_QUE_IsExistTarget(queue, BMP_WIN_GetBmp(q->ent[i].win)) == 0) {
                BMP_WIN_TransferChars(q->ent[i].win);
                q->ent[i].busy = 0;
            }
            if (q->ent[i].busy == 0) {
                q->active[i] = 0;
            }
        }
    }
    PRINTSYS_QUE_Main(q->queue);
}

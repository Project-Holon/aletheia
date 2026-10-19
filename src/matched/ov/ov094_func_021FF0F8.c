/*
 * function: BTLV_MCSS_RemoveSprite
 * address:  0x021FF0F8
 * packet:   pkt_ov094_021FF0F8
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTLV_MCSS_FindSpriteIndex  0x022019F4  thumb  ov094
 *   MCSS_Del  0x02015BA4  thumb
 *   TCBL_IsDeletePending  0x02030EE8  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02030EAC  0x02030EAC  arm
 */

typedef struct {
    void *h;                /* 0x00 */
    char pad04[0x24];
    void *task;             /* 0x28 */
    char pad2c[0x30];
} Entry;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry e[14];            /* 0x008 */
} Work;

extern int BTLV_MCSS_FindSpriteIndex(char *p, int key);
extern void MCSS_Del(void *obj, void *h);
typedef unsigned int   u32;
struct S02030EE8;
extern u32 TCBL_IsDeletePending(struct S02030EE8 *p);
extern u32 func_020307B0(void *p);
struct Node;
extern void func_02030EAC(struct Node *n);

void BTLV_MCSS_RemoveSprite(Work *w, int key)
{
    int idx = BTLV_MCSS_FindSpriteIndex((char *)w, key);

    MCSS_Del(w->obj, w->e[idx].h);
    w->e[idx].h = 0;
    if (w->e[idx].task != 0) {
        func_020307B0((void *)TCBL_IsDeletePending(w->e[idx].task));
        func_02030EAC(w->e[idx].task);
        w->e[idx].task = 0;
    }
}

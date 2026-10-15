/*
 * function: BOX2_MAIN_WaitCursorMove
 * address:  0x021DD930
 * packet:   pkt_ov170_021DD930
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BOX2_SEQ_SetSlotDrawPriorityB 0x021EC7B8 thumb
 *   BOX2_SEQ_GetSlotPos 0x021EC548 thumb
 *   BOX2_UI_IsTopBarMid 0x021EF4A4 thumb
 *   BOX2_SEQ_SetActorDrawEnable 0x021EC000 thumb
 *   BOX2_SEQ_AddActorSurfacePos 0x021EC08C thumb
 *   BOX2_SEQ_SetSlotDrawPriority 0x021EC768 thumb
 *   BOX2_SEQ_SetSlotDimB 0x021ED75C thumb
 *   BOX2_SEQ_MoveCursorToSlot 0x021ED7C4 thumb
 */
#include "../include/Obj00000.h"
#include "../include/Obj23836.h"
#include "../include/Obj23837.h"
#include "../include/Obj23838.h"

typedef struct {
    unsigned short id;
    unsigned short slot;
    unsigned short f4;
    unsigned short used;
    int vx;
    int vy;
    short dx;
    short dy;
    short x;
    short y;
} Entry;

typedef struct {
    Entry e[7];
    int count;
} Move;

struct WinMgr;
extern void BOX2_SEQ_SetSlotDrawPriorityB(char *p, int i, unsigned j, int flag);
extern void BOX2_SEQ_GetSlotPos(unsigned i, short *x, short *y, int mode);
extern int BOX2_UI_IsTopBarMid(struct WinMgr *mgr);
extern void BOX2_SEQ_SetActorDrawEnable(char *p, int i, int v);
extern void BOX2_SEQ_AddActorSurfacePos(char *p, int i, int a, int b, unsigned short c);
extern void BOX2_SEQ_SetSlotDrawPriority(char *p, unsigned i, int flag);
extern void BOX2_SEQ_SetSlotDimB(char **p, int i);
extern void BOX2_SEQ_MoveCursorToSlot(char *p, int i);

int BOX2_MAIN_WaitCursorMove(unsigned char *p)
{
    Move *m = *(Move * *)&((struct Obj23836 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->f60;
    Entry *e;
    unsigned i;
    int k;
    short t[2];
    if (m->count == 8) {
        for (i = 0; i < 7; i++) {
            e = &m->e[i];
            if (e->used == 0)
                continue;
            BOX2_SEQ_SetSlotDrawPriorityB(*(char * *)&((struct Obj00000 *)p)->f2C, e->id, e->slot, 1);
            k = *(unsigned char *)(*(char * *)&((struct Obj00000 *)p)->f2C + e->id + 0x3DD2);
            if (e->slot < 0x1E) {
                BOX2_SEQ_GetSlotPos(e->slot, &t[1], &t[0], p[0x1A]);
            } else if (e->slot < 0x24) {
                BOX2_SEQ_GetSlotPos(e->slot, &t[1], &t[0], p[0x1A]);
                if (p[0x1A] == 2 && BOX2_UI_IsTopBarMid(*(struct WinMgr * *)&((struct Obj23837 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->f74) == 0)
                    t[0] += 0xC0;
            } else {
                if (e->id >= 0x1E) {
                    BOX2_SEQ_GetSlotPos(0x24, &t[1], &t[0], p[0x1A]);
                    if (p[0x1A] == 2 && BOX2_UI_IsTopBarMid(*(struct WinMgr * *)&((struct Obj23838 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->f74) == 0)
                        t[0] += 0xC0;
                } else {
                    BOX2_SEQ_GetSlotPos(e->id, &t[1], &t[0], p[0x1A]);
                }
                BOX2_SEQ_SetActorDrawEnable(*(char * *)&((struct Obj00000 *)p)->f2C, k, 0);
            }
            BOX2_SEQ_AddActorSurfacePos(*(char * *)&((struct Obj00000 *)p)->f2C, k, t[1], t[0], 0);
            if (e->used == 2)
                BOX2_SEQ_SetActorDrawEnable(*(char * *)&((struct Obj00000 *)p)->f2C, k, 0);
        }
        BOX2_SEQ_SetSlotDimB((char **)p, p[0x16]);
        BOX2_SEQ_MoveCursorToSlot(*(char * *)&((struct Obj00000 *)p)->f2C, 0x24);
        return 0;
    }
    m->count++;
    for (i = 0; i < 7; i++) {
        e = &m->e[i];
        if (e->used == 0)
            continue;
        k = *(unsigned char *)(*(char * *)&((struct Obj00000 *)p)->f2C + e->id + 0x3DD2);
        t[1] = e->x + ((unsigned)(m->count * e->vx) >> 16) * e->dx;
        t[0] = e->y + ((unsigned)(m->count * e->vy) >> 16) * e->dy;
        BOX2_SEQ_AddActorSurfacePos(*(char * *)&((struct Obj00000 *)p)->f2C, k, t[1], t[0], 0);
        BOX2_SEQ_SetSlotDrawPriority(*(char * *)&((struct Obj00000 *)p)->f2C, e->id, 0);
    }
    BOX2_SEQ_SetSlotDimB((char **)p, p[0x16]);
    BOX2_SEQ_MoveCursorToSlot(*(char * *)&((struct Obj00000 *)p)->f2C, 0x24);
    return 1;
}

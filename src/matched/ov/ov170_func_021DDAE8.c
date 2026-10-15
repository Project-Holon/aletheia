/*
 * function: BOX2_MAIN_WaitBoxScroll
 * address:  0x021DDAE8
 * packet:   pkt_ov170_021DDAE8
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Twin of src/matched/ov170_func_021DD930.c.
 *
 * symbols:
 *   BOX2_SEQ_GetSlotPos 0x021EC548 thumb
 *   BOX2_SEQ_AddActorSurfacePos 0x021EC08C thumb
 *   BOX2_SEQ_SetSlotDrawPriority 0x021EC768 thumb
 *   BOX2_SEQ_SetSlotDimB 0x021ED75C thumb
 *   BOX2_SEQ_MoveCursorToSlot 0x021ED7C4 thumb
 */
#include "../include/Obj00000.h"
#include "../include/Obj23839.h"

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

extern void BOX2_SEQ_GetSlotPos(unsigned i, short *x, short *y, int mode);
extern void BOX2_SEQ_AddActorSurfacePos(char *p, int i, int a, int b, unsigned short c);
extern void BOX2_SEQ_SetSlotDrawPriority(char *p, unsigned i, int flag);
extern void BOX2_SEQ_SetSlotDimB(char **p, int i);
extern void BOX2_SEQ_MoveCursorToSlot(char *p, int i);

int BOX2_MAIN_WaitBoxScroll(unsigned char *p)
{
    Move *m = *(Move * *)&((struct Obj23839 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->f60;
    Entry *e;
    unsigned i;
    int k;
    short t[2];
    if (m->count == 8) {
        for (i = 0; i < 7; i++) {
            e = &m->e[i];
            if (e->used == 0)
                continue;
            k = *(unsigned char *)(*(char * *)&((struct Obj00000 *)p)->f2C + e->id + 0x3DD2);
            BOX2_SEQ_GetSlotPos(e->slot, &t[1], &t[0], p[0x1A]);
            if (e->slot >= 0x1E)
                t[0] += 0x90;
            BOX2_SEQ_AddActorSurfacePos(*(char * *)&((struct Obj00000 *)p)->f2C, k, t[1], t[0], 0);
        }
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
        break;
    }
    BOX2_SEQ_SetSlotDimB((char **)p, p[0x16]);
    BOX2_SEQ_MoveCursorToSlot(*(char * *)&((struct Obj00000 *)p)->f2C, 0x24);
    return 1;
}

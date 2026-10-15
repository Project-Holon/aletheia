/*
 * function: BOX2_MAIN_UpdateBoxSlots
 * address:  0x021DD530
 * packet:   pkt_ov170_021DD530
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   POKEPARTY_GetCount 0x0201AA18 thumb
 *   func_02007610 0x02007610 thumb
 *   BOX2_MAIN_GetPartyValueAt 0x021DD25C thumb
 *   BOX2_MAIN_MoveMonToParty 0x021DD330 thumb
 *   BOX2_MAIN_AddMonToParty 0x021DD39C thumb
 *   BOX2_MAIN_GetBoxMon 0x021DD3DC thumb
 *   BOX2_MAIN_SwapPartyMembers 0x021DD414 thumb
 *   BOX2_MAIN_ShiftMemberToEnd 0x021DD42C thumb
 *   BOX2_MAIN_CompactParty 0x021DD464 thumb
 *   BOX2_MAIN_RegisterSeenAndForm 0x021DD4B8 thumb
 *   BOX2_MAIN_MoveMonIntoBox 0x021DD810 thumb
 *   BOX2_UI_DrawSlot 0x021EDAB0 thumb
 *   BOX2_UI_DrawSlotByName 0x021EDB34 thumb
 */
#include "../include/Obj00000.h"
#include "../include/Obj23829.h"

typedef struct {
    unsigned short id;
    unsigned short slot;
    unsigned short src;
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
    unsigned a;
    unsigned b;
} Move;

extern unsigned POKEPARTY_GetCount(void *party);
extern void func_02007610(void *save, unsigned b1, unsigned a, unsigned b2, unsigned c);
extern unsigned BOX2_MAIN_GetPartyValueAt(void ***p, unsigned short a, int box, unsigned id, unsigned v);
extern void BOX2_MAIN_MoveMonToParty(unsigned char *p, unsigned short *q, unsigned short *t);
extern void BOX2_MAIN_AddMonToParty(unsigned char *p, unsigned short *q);
extern void BOX2_MAIN_GetBoxMon(char *p, unsigned char *a);
extern void BOX2_MAIN_SwapPartyMembers(char **p, char *q);
extern void BOX2_MAIN_ShiftMemberToEnd(int *p, unsigned char *a);
extern void BOX2_MAIN_CompactParty(unsigned char *p, unsigned box, unsigned a, unsigned b);
extern void BOX2_MAIN_RegisterSeenAndForm(unsigned char *p, unsigned a, unsigned b);
extern void BOX2_MAIN_MoveMonIntoBox(unsigned char *p, unsigned b, unsigned a, unsigned box);
extern void BOX2_UI_DrawSlot(char *p, int i);
extern void BOX2_UI_DrawSlotByName(char *p, int a);

void BOX2_MAIN_UpdateBoxSlots(unsigned char *p)
{
    Move *m = *(Move * *)&((struct Obj23829 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->f60;
    unsigned short n;
    if (m->a == 0xFF)
        return;
    n = POKEPARTY_GetCount(((void **)((struct Obj00000 *)p)->f0)[2]);
    if (m->b >= 0x24) {
        if (m->a < 0x1E)
            BOX2_MAIN_CompactParty(p, p[0x17], m->a, m->b - 0x24);
        else
            BOX2_MAIN_RegisterSeenAndForm(p, m->a, m->b - 0x24);
        return;
    }
    if (m->a < 0x1E) {
        if (m->b < 0x1E) {
            func_02007610(((void **)((struct Obj00000 *)p)->f0)[1], p[0x17], m->a, p[0x14], m->b);
            BOX2_UI_DrawSlot((char *)p, p[0x14]);
            BOX2_UI_DrawSlotByName((char *)p, p[0x14]);
            if (p[0x14] != p[0x17]) {
                BOX2_UI_DrawSlot((char *)p, p[0x17]);
                BOX2_UI_DrawSlotByName((char *)p, p[0x17]);
            }
            return;
        }
        if (m->b - 0x1E < n) {
            BOX2_MAIN_MoveMonToParty(p, (short unsigned int *)(&m->e[0]), (short unsigned int *)(&m->e[1]));
            BOX2_MAIN_MoveMonIntoBox(p, m->b, m->a, p[0x17]);
        } else {
            BOX2_MAIN_AddMonToParty(p, (short unsigned int *)(&m->e[0]));
            BOX2_MAIN_MoveMonIntoBox(p, m->b, m->a, p[0x17]);
        }
        return;
    }
    if (m->b < 0x1E) {
        if (BOX2_MAIN_GetPartyValueAt((void ***)p, m->b, p[0x14], 0xA9, 0)) {
            BOX2_MAIN_MoveMonToParty(p, (short unsigned int *)(&m->e[1]), (short unsigned int *)(&m->e[0]));
            BOX2_MAIN_MoveMonIntoBox(p, m->b, m->a, p[0x14]);
        } else {
            BOX2_MAIN_GetBoxMon((char *)p, (unsigned char *)(&m->e[m->a - 0x1E]));
            BOX2_MAIN_MoveMonIntoBox(p, m->b, m->a, p[0x14]);
        }
        return;
    }
    if (m->b - 0x1E < n)
        BOX2_MAIN_SwapPartyMembers((char **)p, (char *)m);
    else
        BOX2_MAIN_ShiftMemberToEnd((int *)p, (unsigned char *)(&m->e[m->a - 0x1E]));
}

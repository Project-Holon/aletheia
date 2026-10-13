/*
 * function: WEATHER_TASK_LinkParticle
 * address:  0x021A277C
 * packet:   pkt_ov021_021A277C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

typedef struct Node021A277C {
    u32 pad0;
    u32 handle;
    u8 pad8[0x28];
    struct Node021A277C *prev;
    struct Node021A277C *next;
} Node021A277C;

typedef struct {
    u8 pad[0x774];
    Node021A277C *head;
    int count;
} Obj021A277C;

struct Obj;
void CLACT_SetActorDrawEnable(struct Obj *h, unsigned int v);

void WEATHER_TASK_LinkParticle(Obj021A277C *p, Node021A277C *n)
{
    Node021A277C *tail;

    p->count++;
    if (p->head == 0) {
        p->head = n;
        n->next = n;
        p->head->prev = n;
        return;
    }
    tail = p->head->prev;
    n->prev = tail;
    n->next = tail->next;
    tail->next->prev = n;
    tail->next = n;
    CLACT_SetActorDrawEnable((struct Obj *)n->handle, 1);
}

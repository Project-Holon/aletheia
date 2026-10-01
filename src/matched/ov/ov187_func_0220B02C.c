/*
 * packet: pkt_ov187_0220B02C
 * function: func_0220B02C
 * address: 0x0220B02C
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * region: ov187
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02031348 0x02031348 arm
 *   func_02031330 0x02031330 arm
 */
typedef struct Entry { int id; const void *descriptor; void *(*create)(unsigned short, void *, unsigned); void (*destroy)(void *, void *); } Entry;
typedef struct State { void *handle; unsigned state; void *work; unsigned pad; unsigned short heap, pad2; void *payload; Entry *table; unsigned previous, desired, current; } State;
extern void func_02031348(void *, int, const void *, void *);
extern int func_02031330(void *);
int func_0220B02C(State *p)
{
    switch (p->state) {
    case 0:
        p->previous = p->current;
        p->current = p->desired;
        p->state = 1;
        break;
    case 1:
        if (p->table[p->current].create) p->work = p->table[p->current].create(p->heap, p->payload, p->previous);
        else p->work = 0;
        func_02031348(p->handle, p->table[p->current].id, p->table[p->current].descriptor, p->work);
        p->state = 2;
        break;
    case 2:
        if (!func_02031330(p->handle)) p->state = 3;
        break;
    case 3:
        if (p->table[p->current].destroy) {
            p->table[p->current].destroy(p->work, p->payload);
            p->work = 0;
        }
        if (p->current != p->desired) p->state = 0;
        else p->state = 4;
        break;
    case 4: return 1;
    }
    return 0;
}

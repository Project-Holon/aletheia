/*
 * function: BTLV_SCD_PushTask
 * address: 0x06899E48
 * packet: pkt_ov095_06899E48
 * region: ov095
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * Queue storage has four 16-byte entries, as cleared by BTLV_SCD_ClearTasks.
 */
typedef unsigned int u32;
typedef struct Entry { void *a; void *b; void *self; u32 zero; } Entry;
typedef struct Q { u32 pad[8]; Entry entries[4]; int count; } Q;
void BTLV_SCD_PushTask(Q *p, void *a, void *b) {
 int i = p->count++;
 Entry *e = &p->entries[i];
 e->a=a;
 e->b=b;
 e->self=p;
 e->zero=0;
}

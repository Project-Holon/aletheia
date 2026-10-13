/*
 * function: CROWD_SpawnInitialPeople
 * address:  0x021F405C
 * packet:   pkt_ov055_021F405C
 * region:   ov055
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   CROWD_FindFreePerson  0x021F3B20  thumb  ov055
 *   CROWD_SpawnPerson  0x021F3F9C  thumb  ov055
 */

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct E { char b[10]; u16 w; } E;
typedef struct S {
    short lim[6];
    u8 n;
    u8 pad[13];
    E ent[2];
    short cnt[2];
} S;

extern u8 *CROWD_FindFreePerson(u8 *p);
extern void CROWD_SpawnPerson(const char *a, int b, const u16 *c, u8 *d, u16 e);

void CROWD_SpawnInitialPeople(S *p, char *q, int k)
{
    int i, j, n, acc;

    for (i = 0; i < p->n; i++) {
        n = (p->ent[i].w * 6) / p->lim[k];
        acc = 0;
        for (j = 0; j < n; j++) {
            u8 *e = CROWD_FindFreePerson((u8 *)q);
            if (e) {
                CROWD_SpawnPerson(q, (int)p, (const u16 *)(&p->ent[i]), e, (u16)(acc / 6));
                acc += p->lim[k];
            }
        }
    }
}

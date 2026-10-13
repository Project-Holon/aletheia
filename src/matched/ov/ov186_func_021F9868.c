/*
 * function: func_021F9868
 * address:  0x021F9868
 * packet:   pkt_021F9868
 * region:   ov186
 * status:   EXACT*
 * symbols:
 *   func_021F98F8  0x021F98F8  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   BATTLE_REC_Load  0x0200B570  thumb
 */
typedef struct Inner {
    int f0;
    int f4;
} Inner;

typedef struct Mid {
    int pad0;
    int pad4;
    int f8;
    Inner *p0c;
} Mid;

typedef struct Top {
    int w0;
    int w1;
    int w2;
    int w3;
    int w4;
    int w5;
    Mid *f18;
    int w7;
    int w8;
    int w9;
    int f28;
    int f2c;
} Top;

void func_021F98F8(char *p, int skip, void *sys, int heap);
struct Big;
void *func_02012EBC(struct Big *p);
typedef unsigned int   u32;
typedef unsigned short u16;
u32 BATTLE_REC_Load(void *a, u16 heap, u32 *dp, u32 id);

void func_021F9868(Top *p, Top *q)
{
    int buf[1];

    if (p->f28 == 0)
        return;
    func_021F98F8((char *)q->f18->f8 + 0x1748, 0, (void *)q->f18->p0c->f4, 0x5a);
    BATTLE_REC_Load((void *)((int)func_02012EBC((struct Big *)q->f18->p0c->f4)), 0x805a, (u32 *)buf, p->f2c);
}

/*
 * function: TOUCHBAR_Update
 * address:  0x021B63D0
 * packet:   pkt_ov067_021B63D0
 * region:   ov067
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   TOUCHBAR_CheckButtonPressed  0x021B6934  thumb  ov067
 *   TOUCHBAR_IsButtonActorIdle  0x021B69A4  thumb  ov067
 */

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct Ent {
    u8 b[0x38];
} Ent;

typedef struct S {
    u32 f00;
    u32 f04;
    u32 f08;
    u8 pad0c[0x20 - 0x0c];
    Ent ent[1];
} S;

extern int TOUCHBAR_CheckButtonPressed(struct S *p);
extern int TOUCHBAR_IsButtonActorIdle(void **p);

void TOUCHBAR_Update(S *p)
{
    u32 i;

    switch (p->f08) {
    case 0:
        p->f00 = -1;
        for (i = 0; i < p->f04; i++) {
            if (TOUCHBAR_CheckButtonPressed((struct S *)(&p->ent[i]))) {
                p->f00 = i;
                p->f08 = 1;
                return;
            }
        }
        break;
    case 1:
        p->f08 = 2;
    case 2:
        if (TOUCHBAR_IsButtonActorIdle((void **)(&p->ent[p->f00]))) {
            p->f08 = 3;
        }
        break;
    case 3:
        p->f08 = 0;
        break;
    }
}

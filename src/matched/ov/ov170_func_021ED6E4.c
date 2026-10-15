/*
 * function: BOX2_SEQ_SetSlotDim
 * address:  0x021ED6E4
 * packet:   pkt_ov170_021ED6E4
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   CLACT_GetActorDrawPriority 0x0204B838 arm
 *   CLACT_GetActorBgPriority 0x0204B864 arm
 *   BOX2_SEQ_SetActorDrawEnable 0x021EC000 thumb
 *   BOX2_SEQ_SetActorBgPriority 0x021EC030 thumb
 *   BOX2_SEQ_SetActorDrawPriority 0x021EC048 thumb
 */

extern int CLACT_GetActorDrawPriority(int a);
typedef unsigned int   u32;
typedef unsigned char  u8;
extern u32 CLACT_GetActorBgPriority(u8 *a0);
extern void BOX2_SEQ_SetActorDrawEnable(char *p, int i, int v);
extern void BOX2_SEQ_SetActorBgPriority(char *p, int i, int c);
extern void BOX2_SEQ_SetActorDrawPriority(char *p, int i, int c);

void BOX2_SEQ_SetSlotDim(char **p, int v)
{
    int j;
    for (j = 0; j < 8u; j++) {
        if (*(int *)(p[11] + j * 4 + 0x9FD4) != 0) {
            BOX2_SEQ_SetActorDrawEnable(p[11], j + 0x58, v);
            if (v == 1 && ((unsigned char *)p)[0x16] != 0xFF) {
                unsigned char k = *(unsigned char *)(p[11] + ((unsigned char *)p)[0x16] + 0x3DD2);
                BOX2_SEQ_SetActorDrawPriority(p[11], j + 0x58, CLACT_GetActorDrawPriority(*(int *)(p[11] + k * 4 + 0x9E74)) + 1);
                BOX2_SEQ_SetActorBgPriority(p[11], j + 0x58, CLACT_GetActorBgPriority((u8 *)(*(int *)(p[11] + k * 4 + 0x9E74))));
            }
        }
    }
}

/*
 * function: FIELD_G3D_MAPPER_StepBlocks
 * address:  0x0218CC34
 * packet:   pkt_ov021_0218CC34
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_G3D_MAP_Update  0x02169308  thumb  ov010
 *   FIELD_G3D_MAPPER_StampFrame  0x0218DEF0  thumb  ov021
 */

typedef struct {
    int h;
    unsigned char pad[0x24];
} Ent;

typedef struct {
    unsigned char pad[0x1C];
    int f1C;
    int f20;
    Ent *f24;
    unsigned char pad2[6];
    unsigned short n;
} S;

typedef unsigned char  u8;
void FIELD_G3D_MAP_Update(u8 *p);
void FIELD_G3D_MAPPER_StampFrame(char *p);

void FIELD_G3D_MAPPER_StepBlocks(S *p)
{
    int i;
    if (p->f1C != 0) {
        for (i = 0; i < p->n; i++)
            FIELD_G3D_MAP_Update((u8 *)p->f24[i].h);
        FIELD_G3D_MAPPER_StampFrame((char *)p);
    }
}

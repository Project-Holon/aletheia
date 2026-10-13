/*
 * function: FLDEFF_BUBBLE_Init
 * address:  0x021D072C
 * packet:   pkt_ov021_021D072C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FLDMMDL_CheckPossibleAcmd  0x0216D3CC  thumb  ov010
 *   FIELD_EFFECT_GetObjectParam  0x021AC1AC  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef signed char s8;

typedef struct S {
    int *f0;
    int f4;
    u8 f8;
    s8 f9;
    s8 fA;
    u8 padB;
    u8 rows[6][0x14];
} S;

typedef struct Src021D072C {
    int *f0;
    int f4;
} Src021D072C;

extern int FIELD_EFFECT_GetObjectParam(u32 a);
extern int FLDMMDL_CheckPossibleAcmd(int p);

void FLDEFF_BUBBLE_Init(void *a, S *s)
{
    Src021D072C *r = (Src021D072C *)FIELD_EFFECT_GetObjectParam((u32)a);

    *(Src021D072C *)s = *r;
    s->fA = 0x78;
    s->f8 = FLDMMDL_CheckPossibleAcmd(s->f4);
    s->f9 = 5;
}

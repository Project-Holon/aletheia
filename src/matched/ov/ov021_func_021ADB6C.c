/*
 * function: FLDEFF_ENCOUNT_Init
 * address:  0x021ADB6C
 * packet:   pkt_ov021_021ADB6C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_EFFECT_GetObjectParam  0x021AC1AC  thumb  ov021
 *   FIELD_EFFECT_SetObjectPos  0x021AC1CC  thumb  ov021
 *   FIELD_EFFECT_GetObjectMode  0x021AC1A0  thumb  ov021
 *   FIELD_EFFECT_UpdateObject  0x021AC178  thumb  ov021
 */
typedef unsigned short u16;

typedef struct S40 {
    int w[10];
} S40;

typedef struct Dst {
    u16 h0;
    u16 pad2;
    S40 s4;
    int pad2c[2];
    int f34;
} Dst;

extern int FIELD_EFFECT_GetObjectParam(unsigned int a);
extern void FIELD_EFFECT_SetObjectPos(int a, int *b);
typedef unsigned int   u32;
extern int FIELD_EFFECT_GetObjectMode(u32 a);
extern void FIELD_EFFECT_UpdateObject(int a);

void FLDEFF_ENCOUNT_Init(int a, Dst *b)
{
    int *s = (int *)FIELD_EFFECT_GetObjectParam(a);

    b->f34 = s[0];
    b->s4 = *(S40 *)s;
    FIELD_EFFECT_SetObjectPos(a, s + 7);
    if (FIELD_EFFECT_GetObjectMode(a) == 0) {
        b->h0 = 1;
    }
    FIELD_EFFECT_UpdateObject(a);
}

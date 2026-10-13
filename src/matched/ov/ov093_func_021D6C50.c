/*
 * function: BTL_POKEPARAM_Transform
 * address:  0x021D6C50
 * packet:   pkt_ov093_021D6C50
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   MI_CpuCopy8    0x02082D44  arm
 *   MI_CpuFill8    0x02082BCC  arm
 *   func_021D51DC  0x021D51DC  thumb  ov093
 *   gBtlPokeParamTransformMoves     0x021F3B8C  data  a4
 *   gBtlPokeParamTransformKept     0x021F3BC4  data  a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u32 w[0x3b]; } Head;
typedef struct { u16 h[6]; u8 pad[2]; } Ent;
typedef struct Unk021D6C50 {
    u32 pad00[6];
    u8 pad18[3];
    u8 lo : 5;
    u8 flag : 1;
    u8 hi : 2;
    u8 pad1c[0x104 - 0x1c];
    Ent ent[4];
    u8 pad13c[8];
    u8 f144;
    u8 pad145;
    u16 f146;
    u16 f148;
    u16 f14a;
    u16 f14c;
    u16 f14e;
    u8 pad150[2];
    u8 f152;
    u8 f153[2];
    u8 f155[2];
    u8 pad157[0x1f2 - 0x157];
    u16 h1f2;
    u8 pad1f4[4];
} S;
extern void MI_CpuCopy8(const void *src, void *dst, u32 size);
extern void MI_CpuFill8(void *dst, u8 val, u32 size);
struct S;
extern void func_021D51DC(struct S *p, u32 a, u32 b, u32 c);
extern u8 gBtlPokeParamTransformMoves[0x38];
extern Head gBtlPokeParamTransformKept;
int BTL_POKEPARAM_Transform(S *a, S *b)
{
    u16 save;
    int i;
    if (a->flag == 0 && b->flag == 0 && b->h1f2 == 0) {
        MI_CpuCopy8(a->ent, gBtlPokeParamTransformMoves, 0x38);
        gBtlPokeParamTransformKept = *(Head *)a;
        save = a->h1f2;
        *a = *b;
        *(Head *)a = gBtlPokeParamTransformKept;
        a->h1f2 = save;
        MI_CpuCopy8(gBtlPokeParamTransformMoves, a->ent, 0x38);
        for (i = 0; i < 4; i++)
            func_021D51DC((struct S *)(&a->ent[i]), b->ent[i].h[3], 5, 0);
        MI_CpuFill8(a->f153, 0, sizeof(a->f153));
        MI_CpuFill8(a->f155, 0, sizeof(a->f155));
        a->f148 = 10000;
        a->f146 = 0;
        a->f14a = 0;
        a->f14c = 0;
        a->f144 = 0x11;
        a->f14e = 0;
        a->flag = 1;
        return 1;
    }
    return 0;
}

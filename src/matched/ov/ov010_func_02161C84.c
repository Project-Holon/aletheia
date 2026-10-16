/*
 * function: EVENT_FIELD_PROCLINK_SetCommProcParam
 * address:  0x02161C84
 * packet:   pkt_ov010_02161C84
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MI_CpuFill8  0x02082BCC  arm
 *   ICA_ANIME_GetField1C  0x020120F4  thumb
 *   GAME_DATA_GetMyStatus  0x02012944  thumb
 *   func_02008550  0x02008550  thumb
 */

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct {
    u32 a;
    u32 b;
    u32 c;
    u8 d;
    u8 e;
    u8 f;
    u8 g : 7;
    u8 h : 1;
} S;

extern void MI_CpuFill8(void *p, u32 v, u32 n);
struct Ctx;
extern void *ICA_ANIME_GetField1C(const struct Ctx *p);
extern u8 *GAME_DATA_GetMyStatus(void *p);
struct Sub0200852CObj;
extern u8 func_02008550(const struct Sub0200852CObj *obj);

void EVENT_FIELD_PROCLINK_SetCommProcParam(S *s, int a, int b, u8 d, u32 c, u8 e, u8 f, u8 g)
{
    MI_CpuFill8(s, 0, 0x18);
    s->a = a;
    s->b = b;
    s->d = d;
    s->c = c;
    s->e = e;
    s->f = f;
    s->g = g;
    s->h = (u8)(int)func_02008550((const struct Sub0200852CObj *)((int)GAME_DATA_GetMyStatus(ICA_ANIME_GetField1C((const struct Ctx *)a))));
}

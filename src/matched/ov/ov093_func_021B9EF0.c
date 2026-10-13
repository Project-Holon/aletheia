/*
 * function: BTL_TRAINER_SLOT_InitFromPacket
 * address:  0x021B9EF0
 * packet:   pkt_ov093_021B9EF0
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   STRBUF_Create  0x020457B0  arm
 *   STRBUF_SetChars  0x02045A00  arm
 *   MI_CpuCopy8  0x02082D44  arm
 *   PMSI_PARAM_Copy  0x02024570  thumb
 *   PMSI_PARAM_ClearSentence  0x0202428C  thumb
 */

typedef unsigned short u16;

struct H {
    u16 a, b, c, d;
};

struct A {
    int vt;
    int q;
    u16 h8;
    u16 ha;
    int c;
    u16 h[4];
    struct H s18;
    struct H s20;
};

struct B {
    int f0;
    int f4;
    int f8;
    char b[8];
    int f14;
    struct H s18;
    struct H s20;
    char pad[0x68 - 0x28];
    int f68;
};

typedef unsigned int   u32;
struct Buf;
struct U16Vec;
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void STRBUF_SetChars(struct Buf *buf, const void *src, u32 n);
extern void MI_CpuCopy8(const void *, void *, int);
struct Rec8;
extern void PMSI_PARAM_Copy(struct Rec8 *dst, const struct Rec8 *src);
extern void PMSI_PARAM_ClearSentence(void *obj);

void BTL_TRAINER_SLOT_InitFromPacket(struct A *p, const struct B *src)
{
    unsigned int i;
    int t, u;

    p->vt = 0;
    if (src) {
        p->ha = src->f0;
        p->h8 = src->f4;
        t = (int)STRBUF_Create(0x20, 0x12);
        u = src->f68 + 1;
        p->q = t;
        STRBUF_SetChars((struct Buf *)t, (char *)src + 0x28, u);
        p->c = src->f8;
        MI_CpuCopy8(src->b, p->h, 8);
        PMSI_PARAM_Copy((struct Rec8 *)(&p->s18), (const struct Rec8 *)(&src->s18));
        PMSI_PARAM_Copy((struct Rec8 *)(&p->s20), (const struct Rec8 *)(&src->s20));
    } else {
        p->ha = 0;
        p->h8 = 0;
        p->q = 0;
        for (i = 0; i < 4; i++) {
            p->h[i] = 0;
        }
        PMSI_PARAM_ClearSentence(&p->s18);
        PMSI_PARAM_ClearSentence(&p->s20);
    }
}

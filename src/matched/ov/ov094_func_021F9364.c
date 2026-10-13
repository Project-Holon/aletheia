/*
 * function: func_021F9364
 * address:  0x021F9364
 * packet:   pkt_ov094_021F9364
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   G3D_SYSTEM_GetResourceFile  0x02046F48  arm
 *   NNS_G3dGetTex  0x0206E964  arm
 *   PALANM_BlendColors  0x02021F64  thumb
 *   func_02061CA4  0x02061CA4  arm
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

typedef struct {
    u32 **a0;           /* 0 */
    u16 **a4;           /* 4 */
    u8 en;              /* 8 */
    u8 n;               /* 9 */
    u8 cur;             /* 0xA */
    u8 tgt;             /* 0xB */
    u8 cnt;             /* 0xC */
    u8 rl;              /* 0xD */
    u16 col;            /* 0xE */
} P;

typedef struct {
    char pad[0x2C];
    u32 w2c;            /* 0x2C */
    u16 h30;            /* 0x30 */
    char pad2[6];
    u32 o38;            /* 0x38 */
} Q;

struct Tagged;
extern void *G3D_SYSTEM_GetResourceFile(struct Tagged *p);
extern unsigned char *NNS_G3dGetTex(unsigned char *p);
extern void PALANM_BlendColors(u16 *src, u16 *dst, u32 count, int weight, u16 color);
typedef signed int     s32;
extern s32 func_02061CA4(void *p, u32 a, u32 b, s32 size);

void func_021F9364(P *p)
{
    int i;
    Q *q;
    u32 sz;
    u32 off;

    if (p->en != 0) {
        if (p->cnt == 0) {
            p->cnt = p->rl;
            for (i = 0; i < p->n; i++) {
                q = (Q *)NNS_G3dGetTex(G3D_SYSTEM_GetResourceFile((struct Tagged *)p->a0[i]));
                sz = q->h30 << 3;
                off = (u16)q->w2c << 3;
                PALANM_BlendColors((u16 *)((char *)q + q->o38), p->a4[i], (u16)(sz >> 1), p->cur, p->col);
                func_02061CA4((void *)1, off, (u32)p->a4[i], sz);
            }
            if (p->cur == p->tgt) {
                p->en = 0;
            } else if (p->cur > p->tgt) {
                p->cur = p->cur - 1;
            } else {
                p->cur = p->cur + 1;
            }
        } else {
            p->cnt = p->cnt - 1;
        }
    }
}

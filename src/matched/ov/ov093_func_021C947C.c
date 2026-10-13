/*
 * function: func_021C947C
 * address:  0x021C947C
 * packet:   pkt_ov093_021C947C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021B9934  0x021B9934  thumb  ov093
 *   BTL_POKEPARAM_IsFainted  0x021D5B68  thumb  ov093
 *   BTL_SERVER_CMD_Push  0x021CD4B0  thumb  ov093
 *   BTL_POKEPARAM_ResetStatStages  0x021D5F08  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern u8 *func_021B9934(char *p, int i);
extern int BTL_POKEPARAM_IsFainted(void *p);
extern void BTL_SERVER_CMD_Push(void *w, volatile u32 id, ...);
extern void BTL_POKEPARAM_ResetStatStages(char *p);

typedef struct { int pad0; int pad1; char *f8; void *fc; } P;
typedef struct { u32 w; u8 n; u8 ids[1]; } Ent;

int func_021C947C(P *p, const Ent *e)
{
    int r = 0;
    u32 i;
    u8 *a;

    for (i = 0; i < e->n; i++) {
        a = func_021B9934(p->f8, e->ids[i]);
        if (BTL_POKEPARAM_IsFainted(a) == 0) {
            BTL_SERVER_CMD_Push(p->fc, 0xd, e->ids[i]);
            BTL_POKEPARAM_ResetStatStages((char *)a);
            r = 1;
        }
    }
    return r;
}

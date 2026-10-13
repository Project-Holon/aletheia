/*
 * function: func_021BC008
 * address: 0x021BC008
 * packet: pkt_ov206_021BC008
 * region: ov206
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   STRBUF_Delete 0x02045808 arm
 *   POKE_PERSONAL_Delete 0x0201AE14 thumb
 *   MSGDATA_Delete 0x02045C04 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 */
typedef unsigned char u8;
typedef struct S {
    char pad0[0x1b8];
    void *g[3];
    void *w[7];
    void *objs[35];
    void *x;
    void *a[16];
} S;
struct Rec;
struct U16Vec;
extern void STRBUF_Delete(struct U16Vec *vec);
extern void POKE_PERSONAL_Delete(void *);
typedef unsigned int   u32;
extern u32 MSGDATA_Delete(struct Rec *rec);
extern void ARC_TOOL_DeleteHandle(void *);
void func_021BC008(S *p)
{
    u8 i;
    for (i = 0; i < 16; i++)
        STRBUF_Delete(p->a[i]);
    if (p->x != 0)
        POKE_PERSONAL_Delete(p->x);
    for (i = 0; i < 35; i++) {
        switch (i) {
        case 1:
            if (p->g[0] == 0)
                MSGDATA_Delete(p->objs[i]);
            break;
        case 2:
            if (p->g[1] == 0)
                MSGDATA_Delete(p->objs[i]);
            break;
        case 3:
            if (p->g[2] == 0)
                MSGDATA_Delete(p->objs[i]);
            break;
        default:
            MSGDATA_Delete(p->objs[i]);
            break;
        }
    }
    for (i = 0; i < 7; i++)
        ARC_TOOL_DeleteHandle(p->w[i]);
}

/*
 * function: CTVT_CAMVIEW_SetWindowLayout
 * address: 0x021B796C
 * packet: pkt_ov172_021B796C
 * region: ov172
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   COMM_TVT_SYS_GetLayoutMode 0x021BE05C thumb ov172
 *   CTVT_CAMVIEW_SetWindowCurRect 0x021B7888 thumb ov172
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct {
    int active;
    int anim;
    int busy;
    u16 cur[4];
    u16 tgt[4];
} Ent;
typedef struct {
    u8 pad0[0x20];
    int wide;
    u8 pad24[0x10];
    Ent ent[4];
} Q;
extern int COMM_TVT_SYS_GetLayoutMode(void *p);
extern void CTVT_CAMVIEW_SetWindowCurRect(void *p, u16 a, u16 b, u16 c, u16 d);
void CTVT_CAMVIEW_SetWindowLayout(void *p, char *q, int i)
{
    Q *s;
    int sub;
    int mode;
    s = (Q *)q;
    sub = COMM_TVT_SYS_GetLayoutMode(p);
    mode = i;
    if (sub == 1 && i != 0)
        mode = 1;
    if (s->wide == 0) {
        s->ent[i].tgt[0] = (mode == 0 || mode == 2) ? 0 : 0x80;
        s->ent[i].tgt[1] = (mode == 0 || mode == 1) ? 0 : 0x60;
        s->ent[i].tgt[2] = 0x80;
        s->ent[i].tgt[3] = (sub == 1) ? 0xc0 : 0x60;
    } else {
        s->ent[i].tgt[0] = (mode == 0 || mode == 2) ? 0 : 0x40;
        s->ent[i].tgt[1] = (mode == 0 || mode == 1) ? 0 : 0x30;
        s->ent[i].tgt[2] = 0x40;
        s->ent[i].tgt[3] = (sub == 1) ? 0x60 : 0x30;
    }
    if (s->ent[i].anim == 0) {
        s->ent[i].cur[0] = s->ent[i].tgt[0];
        s->ent[i].cur[1] = s->ent[i].tgt[1];
        s->ent[i].cur[2] = s->ent[i].tgt[2];
        s->ent[i].cur[3] = s->ent[i].tgt[3];
    } else {
        s->ent[i].busy = 1;
        switch (mode) {
        case 0:
            if (s->wide == 0)
                CTVT_CAMVIEW_SetWindowCurRect(&s->ent[i], 0, 0, 0x80, 0);
            else
                CTVT_CAMVIEW_SetWindowCurRect(&s->ent[i], 0, 0, 0x40, 0);
            break;
        case 1:
            if (s->wide == 0)
                CTVT_CAMVIEW_SetWindowCurRect(&s->ent[i], 0x80, 0, 0, (sub == 1) ? 0xc0 : 0x60);
            else
                CTVT_CAMVIEW_SetWindowCurRect(&s->ent[i], 0x40, 0, 0, (sub == 1) ? 0x60 : 0x30);
            break;
        case 2:
            if (s->wide == 0)
                CTVT_CAMVIEW_SetWindowCurRect(&s->ent[i], 0, 0x60, 0x80, 0);
            else
                CTVT_CAMVIEW_SetWindowCurRect(&s->ent[i], 0, 0x30, 0x40, 0);
            break;
        case 3:
            if (s->wide == 0)
                CTVT_CAMVIEW_SetWindowCurRect(&s->ent[i], 0x80, 0x60, 0, 0x60);
            else
                CTVT_CAMVIEW_SetWindowCurRect(&s->ent[i], 0x40, 0x30, 0, 0x30);
            break;
        }
    }
    s->ent[i].active = 1;
}

/*
 * function: BTL_SERVER_FLOW_ItemEffectCureSick
 * address:  0x021CC350
 * packet:   pkt_ov093_021CC350
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_POKEPARAM_IsFainted  0x021D5B68  thumb  ov093
 *   BTL_POKEPARAM_HasSick  0x021D62C4  thumb  ov093
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Rec {
    int f00;
    u32 f04;
    u8 f08;
    u8 pad[11];
    u8 f14;
} Rec;

extern int BTL_POKEPARAM_IsFainted(void *m);
struct Unk021D62A8;
extern int BTL_POKEPARAM_HasSick(struct Unk021D62A8 *p, int i);
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);

int BTL_SERVER_FLOW_ItemEffectCureSick(void *a, void *m, int c, int d, u32 v)
{
    u8 id;
    Rec *r;

    if (BTL_POKEPARAM_IsFainted(m) == 0 && BTL_POKEPARAM_HasSick(m, v) != 0) {
        id = BTL_POKEPARAM_GetPokeId(m);
        r = (Rec *)BTL_SERVER_FLOW_AllocCmdRecord(a, 11, id);
        r->f14 = 1;
        r->f08 = id;
        r->f04 = v;
        BTL_SERVER_FLOW_CommitCmdRecord(a, r);
        return 1;
    }
    return 0;
}

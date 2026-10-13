/*
 * function: BTL_EVENT_EnablePokeFactors
 * address: 0x021D7438
 * packet: pkt_ov093_021D7438
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   data_021F3CB0 0x021F3CB0 data a4
 */
typedef unsigned int u32;
typedef struct Node {
    struct Node *prev, *next;
    u32 f8, fC;
    int id;
    u32 prio;
    u32 serial:16, f16:8, b24:1, mark:1, b26:1, busy:1, b28:1, b29:1, b30:1, b31:1;
    unsigned char pad[0x1C];
    unsigned short key;
    unsigned char sub, kind;
} Node;
typedef struct { u32 serial; Node *head; u32 used; Node *pool[0x84]; } List;
extern List data_021F3CB0;
int BTL_EVENT_EnablePokeFactors(int kind, int id) { Node *n; int found=0; for(n=data_021F3CB0.head; n; n=n->next) { if(n->kind==kind && n->id==id) { n->b30=0; found=1; } } return found; }

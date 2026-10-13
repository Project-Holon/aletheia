/*
 * function: UNION_APP_UpdateLeaves
 * address:  0x02183E48
 * packet:   pkt_ov022_02183E48
 * region:   ov022
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GFL_NET_IsConnectMember  0x0203D1C0  arm
 *   GFL_NET_IsParentAid  0x0203D378  arm
 *   UNION_COMM_RemoveMember  0x02173614  thumb  ov012
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned int u32;

typedef void (*Cb)(int idx, u8 *ent, u32 arg);

typedef struct Ent {
    u32 w[8];
    u8 f20[8];
} Ent;

typedef struct S {
    u8 b00, b01, b02, b03, b04, b05, b06, b07, b08, b09, b0a, b0b, b0c, b0d, b0e, b0f;
    u8 b10, b11;
    u8 pad12[0x2c - 0x12];
    Ent ents[5];
    Cb cbf4;
    Cb cbf8;
    u32 argfc;
} S;

typedef struct T14 {
    u8 pad[0x14];
    u8 f[1];
} T14;

extern u32 GFL_NET_IsConnectMember(u32 index);
extern u32 GFL_NET_IsParentAid(void);
extern void UNION_COMM_RemoveMember(u8 *self, const u8 *mac);

typedef struct C {
    u8 pad[0x2830];
    T14 t;
} C;

void UNION_APP_UpdateLeaves(S *s, C *c)
{
    int i;
    u32 m;
    u8 mask;
    Cb cb;

    for (i = 0; i < 5; i++) {
        m = 1 << i;
        if (s->b0e & m) {
            if (GFL_NET_IsConnectMember((u8)i) == 0) {
                if (GFL_NET_IsParentAid() == 1 || (s->b01 & m)) {
                    cb = s->cbf8;
                    if (cb != 0) {
                        cb(i & 0xff, (u8 *)&s->ents[i], s->argfc);
                    }
                    s->b01 &= (u8)(m ^ 0xff);
                    s->b0e &= (u8)(m ^ 0xff);
                }
                UNION_COMM_RemoveMember(c->t.f, s->ents[i].f20);
            }
        }
    }
}

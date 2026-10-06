/*
 * function: func_021CBF38
 * address:  0x021CBF38
 * packet:   pkt_ov021_021CBF38
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Builds the two battle-subway opponent mons at +0x30 of the party block from a trainer record.
 *
 * symbols:
 *   func_021688BC  0x021688BC  thumb  ov010
 *   func_021CBEFC  0x021CBEFC  thumb  ov021
 *   func_021684E8  0x021684E8  thumb  ov010
 *   func_020307B0  0x020307B0  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u8 raw[0x3c];
} BattleMon;

typedef struct {
    u32 otId;
    u16 member[2];
    u32 pid[2];
} Rec;

extern void *func_021688BC(u8 *party, int id, u16 heap);
extern u8 func_021CBEFC(u32 v);
struct BattleMon;
extern u32 func_021684E8(struct BattleMon *out, u32 member, u32 otId, u32 pid, u8 iv, u8 itemIdx, int useItem, u16 heap);
extern void func_020307B0(void *p);

void func_021CBF38(void *unused, u8 *party, int id, int useItem, Rec *rec, u16 heap)
{
    u8 iv;
    void *buf;
    int i;

    buf = func_021688BC(party, id, heap);
    iv = func_021CBEFC(id);

    for (i = 0; i < 2; i++)
        func_021684E8((struct BattleMon *)((BattleMon *)(party + 0x30) + i), rec->member[i], rec->otId, rec->pid[i], iv, i, useItem, heap);
    func_020307B0(buf);
}

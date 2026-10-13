/*
 * function: UNION_APP_SetMemberEntry
 * address:  0x02183FB8
 * packet:   pkt_ov022_02183FB8
 * region:   ov022
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 *   GFL_NET_GetHandleNetID  0x0203D1A4  arm
 *   func_02008550  0x02008550  thumb
 *   func_02008554  0x02008554  thumb
 *   UNION_COMM_AddMember  0x0217357C  thumb  ov012
 */

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct { u32 w[10]; } Blk;
struct Entry;
struct Link;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern u32 GFL_NET_GetHandleNetID(struct Link *p);
struct Sub0200852CObj;
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern u8 func_02008554(const struct Sub0200852CObj *obj);
extern int UNION_COMM_AddMember(u8 *self, const u8 *mac, u32 a2, u32 a3);

typedef struct { u8 pad[0x14]; u8 tab[1]; } Inner;


void UNION_APP_SetMemberEntry(u8 *self, u8 *peer, u32 idx, const Blk *src)
{
    Inner *in = (Inner *)&peer[0x2830];
    *(Blk *)(self + 0x2c + idx * 0x28) = *src;
    self[0xe] |= (u8)(1 << idx);
    if (idx != GFL_NET_GetHandleNetID((struct Link *)GFL_NET_HANDLE_GetCurrentHandle())) {
        u32 a = func_02008554((const struct Sub0200852CObj *)src);
        u32 b = func_02008550((const struct Sub0200852CObj *)src);
        UNION_COMM_AddMember(in->tab, (const u8 *)src + 0x20, a, (u8)b);
    }
}

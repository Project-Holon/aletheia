/*
 * function: WIFIBATTLEMATCH_NET_GetRapPair
 * address: 0x021DC8A0
 * packet: pkt_ov175_021DC8A0
 * region: ov175
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Pair aggregate assignment preserves the forward load and store order.
 * leaf: coordinated transfer from B10's extent to unblock 021D6C54.
 */
typedef unsigned int u32;
typedef struct { char pad[0x1220]; u32 a,b; } Obj;
typedef struct {u32 a,b;} Pair;
void WIFIBATTLEMATCH_NET_GetRapPair(const Obj *p,Pair *out)
{
    *out=*(const Pair *)((const char *)p+0x1220);
}

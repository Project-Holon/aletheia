/*
 * function: BATTLE_CHAMPIONSHIP_FLOW_InvokeCallback
 * address: 0x0217B35C
 * packet: pkt_ov176_0217B35C
 * region: ov176
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * leaf: sole blocker of owned 0217B0C8 MATCH; no prior source/unit/shard, parent claim accepted.
 * symbols:
 *   WIFIBATTLEMATCH_UTIL_InvokeCallback 0x021E8A80 thumb ov177
 */
typedef struct {void (*fn)(void *,int *,int);int a;int b;} CB;
extern void WIFIBATTLEMATCH_UTIL_InvokeCallback(CB *);
void BATTLE_CHAMPIONSHIP_FLOW_InvokeCallback(CB **p)
{
    WIFIBATTLEMATCH_UTIL_InvokeCallback(*p);
}

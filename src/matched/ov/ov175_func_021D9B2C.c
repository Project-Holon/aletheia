/*
 * function: WIFIBATTLEMATCH_NET_VerifyCompSignature
 * address:  0x021D9B2C
 * packet:   pkt_ov175_021D9B2C
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   POKE_TOOL_GetPartyParamSize  0x020173EC  thumb
 *   POKEPARTY_GetCount  0x0201AA18  thumb
 *   POKEPARTY_GetMember  0x0201AB28  thumb
 *   NHTTP_RAP_EvilCheckAllocArray  0x021B9A64  thumb  ov114
 *   NHTTP_RAP_EvilCheckSetElement  0x021B9A94  thumb  ov114
 *   NHTTP_RAP_VerifySignature  0x021B9A1C  thumb  ov114
 *   NHTTP_RAP_EvilCheckFreeArray  0x021B9A8C  thumb  ov114
 *
 * Serialises a list: allocates count records of 0x020173EC's size from heap (heap | 0x8000, top-down), copies every entry in, hands the buffer to the ov114 writer with the +0x54 block, frees it and returns the writer's result.
 *
 * Leaf: +008A NHTTP_RAP_EvilCheckFreeArray resolves as matched through
 *     src/matched/ov/ov114_func_021B9A8C.c (pkt_ov114_021B9A8C), the
 *     unlabelled ov114 tail-call stub to 0x020307B0. Twin of
 *     ov175_func_021D67BC.c; 0201AA18/0201AB28 prototypes follow the
 *     matched arm9 callers (pointer list, u32 count).
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u32 POKE_TOOL_GetPartyParamSize(void);
extern u32 POKEPARTY_GetCount(void *p);
extern void *POKEPARTY_GetMember(void *p, u32 idx);
extern u8 *NHTTP_RAP_EvilCheckAllocArray(int a, int b, int c);
extern void NHTTP_RAP_EvilCheckSetElement(int p, int a, u32 b, int n);
extern int NHTTP_RAP_VerifySignature(void *a, int b, int c, char *d, u16 e);
extern void NHTTP_RAP_EvilCheckFreeArray(void *buf);

u32 WIFIBATTLEMATCH_NET_VerifyCompSignature(char *obj, void *list, u32 heapId)
{
    int heap = (heapId & 0x7fff) | 0x8000;
    u32 size = POKE_TOOL_GetPartyParamSize();
    void *buf = NHTTP_RAP_EvilCheckAllocArray(size, POKEPARTY_GetCount(list), (u16)heap);
    int i;
    u32 ret;

    for (i = 0; i < (int)POKEPARTY_GetCount(list); i++) {
        void *e = POKEPARTY_GetMember(list, i);
        NHTTP_RAP_EvilCheckSetElement((int)buf, (int)e, POKE_TOOL_GetPartyParamSize(), i);
    }
    size = POKE_TOOL_GetPartyParamSize();
    ret = NHTTP_RAP_VerifySignature(buf, size, POKEPARTY_GetCount(list), obj + 0x54, (u16)heap);
    NHTTP_RAP_EvilCheckFreeArray(buf);
    return ret;
}

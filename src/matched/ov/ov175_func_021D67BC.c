/*
 * function: WIFIBATTLEMATCH_NET_VerifyPartySignature
 * address: 0x021D67BC
 * packet: pkt_ov175_021D67BC
 * region: ov175
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: `int i` declared before the list pointer gives i r4 and list r5
 * (declaration-order-decides-which-register-a-local-gets.md); the earlier
 * DIFF was that r4/r5 swap alone.
 * leaf: +008A NHTTP_RAP_EvilCheckFreeArray resolves as matched through
 *   src/matched/ov/ov114_func_021B9A8C.c (pkt_ov114_021B9A8C), the
 *   unlabelled ov114 tail-call stub to 0x020307B0.
 * symbols:
 *   POKE_TOOL_GetPartyParamSize 0x020173EC thumb
 *   POKEPARTY_GetCount 0x0201AA18 thumb
 *   POKEPARTY_GetMember 0x0201AB28 thumb
 *   NHTTP_RAP_EvilCheckAllocArray 0x021B9A64 thumb ov114
 *   NHTTP_RAP_EvilCheckSetElement 0x021B9A94 thumb ov114
 *   NHTTP_RAP_VerifySignature 0x021B9A1C thumb ov114
 *   NHTTP_RAP_EvilCheckFreeArray 0x021B9A8C thumb ov114
 */
typedef unsigned int u32;
typedef unsigned short u16;
extern u32 POKE_TOOL_GetPartyParamSize(void);
extern u32 POKEPARTY_GetCount(void *p);
extern void *POKEPARTY_GetMember(void *p, u32 idx);
typedef unsigned char  u8;
extern u8 *NHTTP_RAP_EvilCheckAllocArray(int a, int b, int c);
extern void NHTTP_RAP_EvilCheckSetElement(int p, int a, u32 b, int n);
extern int NHTTP_RAP_VerifySignature(void *a, int b, int c, char *d, u16 e);
extern void NHTTP_RAP_EvilCheckFreeArray(void *);
int WIFIBATTLEMATCH_NET_VerifyPartySignature(char *p, u16 heapId)
{
    int i;
    u32 size;
    void *list=p+0xd4;
    int heap=(heapId&0x7fff)|0x8000;
    void *buf;
    u32 ret;
    size=POKE_TOOL_GetPartyParamSize();
    buf=NHTTP_RAP_EvilCheckAllocArray(size,POKEPARTY_GetCount(list),(u16)heap);
    for(i=0;i<(int)POKEPARTY_GetCount(list);i++) {
        void *entry=POKEPARTY_GetMember(list,i);
        NHTTP_RAP_EvilCheckSetElement((int)buf,(int)entry,POKE_TOOL_GetPartyParamSize(),i);
    }
    size=POKE_TOOL_GetPartyParamSize();
    ret=NHTTP_RAP_VerifySignature(buf,size,POKEPARTY_GetCount(list),p+0x54,heap);
    NHTTP_RAP_EvilCheckFreeArray(buf);
    return ret;
}

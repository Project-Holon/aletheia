/*
 * function: func_021D67BC
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
 * leaf: +008A func_021B9A8C resolves as matched through
 *   src/matched/ov/ov114_func_021B9A8C.c (pkt_ov114_021B9A8C), the
 *   unlabelled ov114 tail-call stub to 0x020307B0.
 * symbols:
 *   POKE_TOOL_GetPartyParamSize 0x020173EC thumb
 *   POKEPARTY_GetCount 0x0201AA18 thumb
 *   POKEPARTY_GetMember 0x0201AB28 thumb
 *   func_021B9A64 0x021B9A64 thumb ov114
 *   func_021B9A94 0x021B9A94 thumb ov114
 *   func_021B9A1C 0x021B9A1C thumb ov114
 *   func_021B9A8C 0x021B9A8C thumb ov114
 */
typedef unsigned int u32;
typedef unsigned short u16;
extern u32 POKE_TOOL_GetPartyParamSize(void);
extern u32 POKEPARTY_GetCount(void *p);
extern void *POKEPARTY_GetMember(void *p, u32 idx);
typedef unsigned char  u8;
extern u8 *func_021B9A64(int a, int b, int c);
extern void func_021B9A94(int p, int a, u32 b, int n);
extern int func_021B9A1C(void *a, int b, int c, char *d, u16 e);
extern void func_021B9A8C(void *);
int func_021D67BC(char *p, u16 heapId)
{
    int i;
    u32 size;
    void *list=p+0xd4;
    int heap=(heapId&0x7fff)|0x8000;
    void *buf;
    u32 ret;
    size=POKE_TOOL_GetPartyParamSize();
    buf=func_021B9A64(size,POKEPARTY_GetCount(list),(u16)heap);
    for(i=0;i<(int)POKEPARTY_GetCount(list);i++) {
        void *entry=POKEPARTY_GetMember(list,i);
        func_021B9A94((int)buf,(int)entry,POKE_TOOL_GetPartyParamSize(),i);
    }
    size=POKE_TOOL_GetPartyParamSize();
    ret=func_021B9A1C(buf,size,POKEPARTY_GetCount(list),p+0x54,heap);
    func_021B9A8C(buf);
    return ret;
}

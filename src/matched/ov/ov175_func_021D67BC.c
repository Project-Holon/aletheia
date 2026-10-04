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
 *   func_020173EC 0x020173EC thumb
 *   func_0201AA18 0x0201AA18 thumb
 *   func_0201AB28 0x0201AB28 thumb
 *   func_021B9A64 0x021B9A64 thumb ov114
 *   func_021B9A94 0x021B9A94 thumb ov114
 *   func_021B9A1C 0x021B9A1C thumb ov114
 *   func_021B9A8C 0x021B9A8C thumb ov114
 */
typedef unsigned int u32;
typedef unsigned short u16;
extern u32 func_020173EC(void);
extern u32 func_0201AA18(void *p);
extern void *func_0201AB28(void *p, u32 idx);
extern void *func_021B9A64(int,int,u16);
extern void func_021B9A94(void *,void *,u32,int);
extern u32 func_021B9A1C(void *,u32,u32,char *,u16);
extern void func_021B9A8C(void *);
u32 func_021D67BC(char *p,u32 heapId)
{
    int i;
    u32 size;
    void *list=p+0xd4;
    int heap=(heapId&0x7fff)|0x8000;
    void *buf;
    u32 ret;
    size=func_020173EC();
    buf=func_021B9A64(size,func_0201AA18(list),heap);
    for(i=0;i<(int)func_0201AA18(list);i++) {
        void *entry=func_0201AB28(list,i);
        func_021B9A94(buf,entry,func_020173EC(),i);
    }
    size=func_020173EC();
    ret=func_021B9A1C(buf,size,func_0201AA18(list),p+0x54,heap);
    func_021B9A8C(buf);
    return ret;
}

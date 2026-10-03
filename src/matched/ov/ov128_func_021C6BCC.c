/*
 * function: func_021C6BCC
 * address: 0x021C6BCC
 * packet: pkt_ov128_021C6BCC
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0201283C 0x0201283C thumb
 *   func_0200846C 0x0200846C thumb
 *   func_020457B0 0x020457B0 arm
 *   func_020099D4 0x020099D4 thumb
 *   func_02045924 0x02045924 arm
 *   func_020084E4 0x020084E4 thumb
 *   func_02045808 0x02045808 arm
 *   func_0201F02C 0x0201F02C thumb
 *   func_020307B0 0x020307B0 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern void *func_0201283C(const void *);
extern void *func_0200846C(int);
typedef unsigned int   u32;
struct Sub020097BCEnt;
struct Sub020097BCObj;
struct U16Vec;
struct WordSet;
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern struct Sub020097BCEnt *func_020099D4(struct Sub020097BCObj *obj, int i);
extern void func_02045924(void *,const void *);
extern void func_020084E4(u16 *out, struct U16Vec *vec);
extern void func_02045808(struct U16Vec *vec);
extern void func_0201F02C(struct WordSet *p, u32 i, void *a);
extern void func_020307B0(void *);
void func_021C6BCC(u8 *p,u8 *q,int idx,unsigned heap)
{
    void *base;
    void *obj;
    void *str;
    base=func_0201283C(*(void **)(q+4));
    obj=func_0200846C(heap);
    str=func_020457B0(10,heap);
    func_02045924(str,func_020099D4(base,idx));
    func_020084E4(obj,str);
    func_02045808(str);
    func_0201F02C(*(void **)p,0,obj);
    func_020307B0(obj);
}

/*
 * function: func_021D6244
 * address: 0x021D6244
 * packet: pkt_ov131_021D6244
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045EC0 0x02045EC0 arm
 *   func_02045808 0x02045808 arm
 *   func_020457B0 0x020457B0 arm
 */
typedef unsigned int   u32;
struct MsgBank;
struct StrObj;
struct U16Vec;
struct WordSet;
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern void func_02045808(struct U16Vec *vec);
extern void func_0201C724(void *,int,short,short,void *,int,unsigned short);
void func_021D6244(unsigned char *p,int a,void *b,int c,unsigned short d,short e,unsigned short f) {
 void *t=func_020457B0(16,*(unsigned short *)p);
 void *s=func_02045EC0(*(void **)(p+124),c);
 int w;
 func_0201F250(b,t,s);
 w=func_0201D304(t,*(int *)(p+128),0);
 func_0201C724(*(void **)(p+132),a,(short)(d-w),e,t,*(int *)(p+128),f);
 func_02045808(s);
 func_02045808(t);
}

/*
 * function: func_021F3EF0
 * address: 0x021F3EF0
 * packet: pkt_ov194_021F3EF0
 * region: ov194
 * status: EXACT
 * symbols:
 *   func_0201EC64 0x0201EC64 thumb
 *   func_0201EEF4 0x0201EEF4 thumb
 *   func_0201EE0C 0x0201EE0C thumb
 *   func_0201F164 0x0201F164 thumb
 *   func_0201CE48 0x0201CE48 thumb
 *   func_0201F250 0x0201F250 thumb
 *   func_02012FFC 0x02012FFC thumb
 *   func_0201CCE4 0x0201CCE4 thumb
 *   func_0201ED04 0x0201ED04 thumb
 *   func_02045874 0x02045874 arm
 *   func_02045808 0x02045808 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_0204581C 0x0204581C arm
 *   func_0216C0D4 0x0216C0D4 thumb ov010
 *   func_0216C0E4 0x0216C0E4 thumb ov010
 *   func_021F46B4 0x021F46B4 thumb ov194
 */
typedef unsigned int u32;
typedef unsigned short u16;
struct U16Vec;
struct WordSet;
extern struct WordSet *func_0201EC64(u32 heap);
extern int func_0216C0E4(int *);
extern void func_0216C0D4(int *,int);
extern void func_0201EEF4(struct WordSet *p, u32 i, void *mon);
typedef unsigned char  u8;
struct CharBuf;
struct Rec3;
extern struct U16Vec *func_02045874(struct U16Vec *src, u32 heapId);
extern void func_0201EE0C(void *,u32,const void *,u32,u32,u32);
extern void func_02045808(struct U16Vec *vec);
extern void func_0201F164(struct WordSet *p, u32 i, u32 a, u32 b);
extern void func_0201CE48(struct Rec3 *p);
struct Descriptor;
extern void *func_02045770(struct Descriptor *);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_0204581C(struct U16Vec *vec);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern signed char func_02012FFC(void);
/* The caller consumes R0 returned by the legacy void forwarding wrapper. */
extern int func_0201CCE4(u32,u32,u32,u32,u32,u32,u32,u32,u32,u16);
extern void func_0201ED04(struct WordSet *p);
extern void func_021F46B4(unsigned char *p, int *state);
void func_021F3EF0(char *p,char *q,int *w,u32 heap)
{
    void *set=func_0201EC64(heap);
    if(func_0216C0E4(w)) func_0201EEF4(set,0,(void *)w[2]);
    else {
        int text=(int)func_02045874((struct U16Vec *)w[8],heap);
        func_0216C0D4(w,text);
        func_0201EE0C(set,0,(void *)text,0,0,0);
        func_02045808((struct U16Vec *)text);
    }
    func_0201F164(set,1,w[4],w[5]);
    if(*(int *)p) func_0201CE48((struct Rec3 *)(*(int *)p));
    func_02043B5C((struct CharBuf *)((int)func_02045770((struct Descriptor *)*(int *)(q+20))),*(u16 *)(q+32));
    func_0204581C(*(void **)(q+28));
    func_0201F250(set,*(void **)(q+28),(void *)w[3]);
    *(int *)p=func_0201CCE4(*(u32 *)(q+20),0,0,*(u32 *)(q+28),*(u32 *)(q+4),func_02012FFC(),*(u32 *)(p+4),2,heap,*(u16 *)(q+32));
    *(u16 *)(p+14)=0;
    *(void (**)(void))(p+8)=(void (*)(void))func_021F46B4;
    *(u16 *)(p+12)=60;
    func_0201ED04(set);
}

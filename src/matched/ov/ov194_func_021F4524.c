/*
 * function: func_021F4524
 * address: 0x021F4524
 * packet: pkt_ov194_021F4524
 * region: ov194
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02045874 0x02045874 arm
 *   func_021F2328 0x021F2328 thumb ov194
 *   func_0204589C 0x0204589C arm
 *   func_021F253C 0x021F253C thumb ov194
 *   func_02045838 0x02045838 arm
 *   func_02045808 0x02045808 arm
 *   func_020458F8 0x020458F8 arm
 */
typedef unsigned short u16;
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Buf;
struct U16Vec;
extern struct U16Vec *func_02045874(struct U16Vec *src, u32 heapId);
struct Strbuf;
extern void func_021F2328(char *,struct Strbuf *);
extern int func_0204589C(struct Buf *a, struct Buf *b);
extern int func_021F253C(u8 *p);
extern void func_02045838(struct U16Vec *dst, struct U16Vec *src);
extern void func_02045808(struct U16Vec *vec);
extern u16 func_020458F8(struct U16Vec *vec);
void func_021F4524(char *p) {
    int text;
    char *obj;
    *(int *)(*(char **)(p+0x2c4)+28)=0;
    text=(int)func_02045874((struct U16Vec *)(*(unsigned *)(*(char **)(p+0x2c4)+32)),30);
    func_021F2328(p+0x68,(struct Strbuf *)*(int *)(*(char **)(p+0x2c4)+32));
    if (func_0204589C((struct Buf *)text,(struct Buf *)(*(int *)(*(char **)(p+0x2c4)+32))))
        *(int *)(*(char **)(p+0x2c4)+28)=1;
    if (!func_021F253C((u8 *)((int)(p+0x68)))) {
        func_02045838((struct U16Vec *)(*(int *)(*(char **)(p+0x2c4)+32)),(struct U16Vec *)text);
        *(int *)(*(char **)(p+0x2c4)+28)=1;
    }
    func_02045808((struct U16Vec *)text);
    if (!func_020458F8((struct U16Vec *)(*(unsigned *)(*(char **)(p+0x2c4)+32)))) {
        obj=*(char **)(p+0x2c4);
        if (*(int *)obj!=0 && *(int *)obj!=3) *(int *)(obj+28)=1;
    }
}

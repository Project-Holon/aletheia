/*
 * function: func_02210420
 * address: 0x02210420
 * packet: pkt_ov198_02210420
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   sub_0201C6B4 0x0201C6B4 thumb
 *   sub_0201C6EC 0x0201C6EC thumb
 *   func_020221A4 0x020221A4 thumb
 *   func_020221B8 0x020221B8 thumb
 *   sub_0201CE48 0x0201CE48 thumb
 *   func_0202CA0C 0x0202CA0C thumb
 *   func_02210774 0x02210774 thumb ov198
 *   func_0220E74C 0x0220E74C thumb ov198
 *   func_0220BE04 0x0220BE04 thumb ov198
 *   func_022105E4 0x022105E4 thumb ov198
 *   sub_02031140 0x02031140 arm
 *   func_022119E8 0x022119E8 thumb ov198
 *   func_0220AF64 0x0220AF64 thumb ov196
 *   sub_02030EAC 0x02030EAC arm
 *   func_020307B0 0x020307B0 arm
 */
typedef unsigned char u8;
typedef unsigned int u32;
struct PrintSys;struct Rec3;struct Obj;struct S02031140;struct Node;
extern u32 sub_0201C6B4(const struct PrintSys *);
extern void sub_0201C6EC(struct PrintSys *);
extern u32 func_020221A4(void);
extern void func_020221B8(void);
extern void sub_0201CE48(struct Rec3 *);
extern void func_0202CA0C(struct Obj *);
extern void func_02210774(char *);
extern void func_0220E74C(char *);
extern void func_0220BE04(char *);
extern void func_022105E4(void);
extern void sub_02031140(struct S02031140 *);
extern u32 func_022119E8(u8 *);
extern void func_0220AF64(void *);
extern void sub_02030EAC(struct Node *);
extern void func_020307B0(void *);
int func_02210420(struct Node *task,char *p)
{
    if(*(int *)(p+0x2540)==1) {
        if(sub_0201C6B4(*(struct PrintSys **)(p+0x1eac))==0) {
            if(*(int *)(*(char **)p+0x34)==1) sub_0201C6EC(*(struct PrintSys **)(p+0x1eac));
            else return 0;
        }
        if(func_020221A4()==0) {
            if(*(int *)(*(char **)p+0x34)==1) func_020221B8();
            else return 0;
        }
        if(*(struct Rec3 **)(p+0x1eb0)) sub_0201CE48(*(struct Rec3 **)(p+0x1eb0));
        if(*(struct Obj **)(p+0x2194)) func_0202CA0C(*(struct Obj **)(p+0x2194));
        func_02210774(p);
        func_0220E74C(p);
        func_0220BE04(p);
        func_022105E4();
        sub_02031140(*(struct S02031140 **)(p+0x1d4));
        func_022119E8((u8 *)p);
        func_0220AF64(*(void **)(p+0x2188));
        if(*(int *)(p+0x218c)==1) **(u8 **)(*(char **)p+0x44)=1;
        else **(u8 **)(*(char **)p+0x44)=0;
    }
    (*(u8 **)p)[0x4c]=1;
    sub_02030EAC(task);
    func_020307B0(p);
    return 1;
}

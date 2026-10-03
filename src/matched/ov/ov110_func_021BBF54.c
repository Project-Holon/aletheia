/*
 * function: func_021BBF54
 * address: 0x021BBF54
 * packet: pkt_ov110_021BBF54
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: plain signed-halfword assignments and named coordinate results.
 * prototype: original call truncates space to u16; legacy 02040618 fourth input is unused by 02042360.
 * symbols:
 *   func_02040618 0x02040618 arm
 *   func_0204B4EC 0x0204B4EC arm
 *   func_0204B49C 0x0204B49C arm
 *   func_02030EAC 0x02030EAC arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef struct { u8 pad[0x14]; void *desc[2]; void *items[2][2]; } Obj;
extern void func_02040618(unsigned,unsigned,unsigned);
extern s16 func_0204B4EC(void *,u16,unsigned);
extern void func_0204B49C(void *,s16,u16,unsigned);
struct Node;
extern void func_02030EAC(struct Node *n);
int func_021BBF54(Obj *p)
{
    int delta,i,j;
    u8 *b=(u8 *)p;
    if(b[0x19c]>5) return 1;
    if(b[0x19d]) delta=-8; else delta=8;
    *(s16 *)(b+0x19a)=*(s16 *)(b+0x19a)+delta;
    *(s16 *)(b+0x198)=*(s16 *)(b+0x198)+delta;
    func_02040618(4,3,*(s16 *)(b+0x19a));
    for(i=0;i<2;i++) {
        s16 pos=func_0204B4EC(p->desc[i],i,1)-delta;
        func_0204B49C(p->desc[i],pos,i,1);
        for(j=0;j<2;j++) {
            s16 pos=func_0204B4EC(p->items[j][i],i,1)-delta;
            func_0204B49C(p->items[j][i],pos,i,1);
        }
    }
    b[0x19c]++;
    if(b[0x19d] && b[0x19c]==7) {
        func_02030EAC(*(void **)(b+0x1a4));
        *(void **)(b+0x1a4)=0;
        func_02030EAC(*(void **)(b+0x1b0));
        *(void **)(b+0x1b0)=0;
    }
    *(int *)(b+0x1b8)=1;
    return 0;
}

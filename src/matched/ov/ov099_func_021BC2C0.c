/*
 * function: func_021BC2C0
 * address: 0x021BC2C0
 * packet: pkt_ov099_021BC2C0
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Lever: case4/case5 guard is a switch, retaining two compares; an equality disjunction folds to a range.
 * symbols:
 *   func_02045770 0x02045770 arm
 *   func_0201C6C4 0x0201C6C4 thumb
 *   func_02045334 0x02045334 arm
 *   func_020200CC 0x020200CC thumb
 *   func_021BA8EC 0x021BA8EC thumb ov099
 *   func_021BA8BC 0x021BA8BC thumb ov099
 *   func_0202020C 0x0202020C thumb
 *   func_0201F868 0x0201F868 thumb
 *   func_021BAAB8 0x021BAAB8 thumb ov099
 *   func_0202EB14 0x0202EB14 thumb
 *   func_0202EB0C 0x0202EB0C thumb
 *   func_021BDDD0 0x021BDDD0 thumb ov099
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int     s32;
struct Descriptor;
struct Obj;
struct PrintSys;
extern void *func_02045770(struct Descriptor *p);
extern u32 func_0201C6C4(struct PrintSys *p, void *v);
extern void func_02045334(struct Descriptor *d);
extern s32 func_020200CC(struct Obj *o);
extern void func_021BA8EC(char *);
extern void *func_021BA8BC(void *);
extern void func_0202020C(struct Obj *o, u16 *a, u16 *b);
extern void func_0201F868(void *);
extern void func_021BAAB8(char *,int,int);
extern int func_0202EB14(void);
extern u32 func_0202EB0C(void);
extern int func_021BDDD0(char *);
int func_021BC2C0(char *p,int v)
{
    int r;
    void *q;
    q = *(void **)(p+0x1b8);
    if (*(u8 *)(p+0x1b0) != 0) {
        if (func_0201C6C4(q,func_02045770(*(void **)(p+0x1ac))) == 0) {
            func_02045334(*(void **)(p+0x1ac));
            *(u8 *)(p+0x1b0)=0;
        }
    }
    r=func_020200CC(*(void **)(p+0xbc));
    switch(r) {
    case 4: case 5:
        if (*(u8 *)(*(char **)(p+0x248)+0x46)==0) return v;
        break;
    }
    if (r!=-1) func_021BA8EC(p);
    switch(r) {
    case -1: return v;
    case -2:
        *(u8 *)(p+0x1353)=0x9b;
        *(u32 *)(p+0x1cc)=0x8a;
        break;
    case 4:
        if (*(u8 *)(*(char **)(p+0x248)+0x45)==0) {
            func_021BAAB8(p,0x8c,0);
            *(u32 *)(p+0x1cc)=0x47;
        } else {
            *(u8 *)(p+0x1353)=0x4b;
            *(u32 *)(p+0x1cc)=0x8a;
        }
        break;
    case 5:
        if (*(u8 *)(*(char **)(p+0x248)+0x45)==0) {
            func_021BAAB8(p,0x8c,0);
            *(u32 *)(p+0x1cc)=0x47;
        } else if (func_0202EB14()==0 && func_0202EB0C()!=0) {
            func_021BAAB8(p,0x95,0);
            *(u32 *)(p+0x1cc)=0xa4;
        } else {
            *(u8 *)(p+0x1353)=0x4c;
            *(u32 *)(p+0x1cc)=0x8a;
        }
        break;
    case 6:
        if (func_021BDDD0(p)==0) {
            func_021BAAB8(p,0x79,0);
            *(u32 *)(p+0x1cc)=0x47;
        } else if (*(u8 *)(*(char **)(p+0x248)+0x44)!=*(u8 *)(*(char **)(p+0x248)+0x45)) {
            *(u8 *)(p+0x1352)=6;
            *(u32 *)(p+0x1cc)=0x7d;
        } else {
            *(u8 *)(p+0x1353)=0x4d;
            *(u32 *)(p+0x1cc)=0x8a;
        }
        break;
    case 7: *(u32 *)(p+0x1cc)=0x4e; break;
    }
    *(void **)(p+0x1a4)=func_021BA8BC(*(void **)(p+0x1a4));
    func_0202020C(*(void **)(p+0xbc),0,(u16 *)(p+0x23c));
    func_0201F868(*(void **)(p+0xb8));
    return v;
}

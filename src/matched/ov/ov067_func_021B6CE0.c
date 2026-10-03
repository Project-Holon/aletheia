/*
 * function: func_021B6CE0
 * address: 0x021B6CE0
 * packet: pkt_ov067_021B6CE0
 * region: ov067
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: struct bank array; explicit top-of-loop break preserves both guards.
 * ownership: Wave37 B7 conditional leaf cleared by parent after source/unit/SDK audit.
 * extent: two zero alignment bytes at 0x021B6D6E precede labelled 0x021B6D70.
 * residency: ov110 initializer 021C0134 loads 67; 021BAEDC creates caller+78 through ov067 021B6C74.
 * symbols:
 *   func_020458F8 0x020458F8 arm
 *   func_02082A7C 0x02082A7C arm
 *   func_02045F50 0x02045F50 arm
 *   func_02045CAC 0x02045CAC arm
 *   func_021B6D70 0x021B6D70 thumb ov067
 */
typedef unsigned short u16;
typedef unsigned u32;
typedef struct { u32 id,index; } Pair;
typedef struct { u32 str,count; void *bank[1]; } Obj;
struct MsgBank;
struct Obj;
struct U16Vec;
extern u16 func_020458F8(struct U16Vec *vec);
extern void func_02082A7C(u32,void *,u32);
extern u16 func_02045F50(const struct Obj *o);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern int func_021B6D70(u32,u32,u32);
u32 func_021B6CE0(Obj *p,u32 id,u32 unused,u32 str,Pair *out,u32 max)
{
    u32 count;
    u32 n;
    void *bank;
    u32 i,j,length;
    count=0;
    length=func_020458F8((void *)str);
    func_02082A7C(-1,out,max*8);
    if(length) {
        n=func_02045F50(p->bank[id]);
        bank=p->bank[id];
        i=0;
        j=0;
        for(;;i++) {
            if(i>=n) break;
            if(j>=max) break;
            func_02045CAC(bank,i,(void *)p->str);
            if(func_021B6D70(str,p->str,func_020458F8((void *)str))) {
                if(j<max) {
                    out[j].id=id;
                    out[j].index=i;
                    j++;
                }
                count++;
            }
        }
    }
    return count;
}

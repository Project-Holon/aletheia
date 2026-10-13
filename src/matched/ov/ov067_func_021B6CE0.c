/*
 * function: MSGSEARCH_Search
 * address: 0x021B6CE0
 * packet: pkt_ov067_021B6CE0
 * region: ov067
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * lever: struct bank array; explicit top-of-loop break preserves both guards.
 * ownership: Wave37 B7 conditional leaf cleared by parent after source/unit/SDK audit.
 * extent: two zero alignment bytes at 0x021B6D6E precede labelled 0x021B6D70.
 * residency: ov110 initializer 021C0134 loads 67; 021BAEDC creates caller+78 through ov067 021B6C74.
 * symbols:
 *   STRBUF_GetLength 0x020458F8 arm
 *   func_02082A7C 0x02082A7C arm
 *   func_02045F50 0x02045F50 arm
 *   MSGDATA_ReadString 0x02045CAC arm
 *   MSGSEARCH_PrefixMatches 0x021B6D70 thumb ov067
 */
typedef unsigned short u16;
typedef unsigned u32;
typedef struct { u32 id,index; } Pair;
typedef struct { u32 str,count; void *bank[1]; } Obj;
struct MsgBank;
struct Obj;
struct U16Vec;
extern u16 STRBUF_GetLength(struct U16Vec *vec);
extern void func_02082A7C(u32,void *,u32);
extern u16 func_02045F50(const struct Obj *o);
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern int MSGSEARCH_PrefixMatches(u32,u32,u32);
u32 MSGSEARCH_Search(Obj *p,u32 id,u32 unused,u32 str,Pair *out,u32 max)
{
    u32 count;
    u32 n;
    void *bank;
    u32 i,j,length;
    count=0;
    length=STRBUF_GetLength((void *)str);
    func_02082A7C(-1,out,max*8);
    if(length) {
        n=func_02045F50(p->bank[id]);
        bank=p->bank[id];
        i=0;
        j=0;
        for(;;i++) {
            if(i>=n) break;
            if(j>=max) break;
            MSGDATA_ReadString(bank,i,(void *)p->str);
            if(MSGSEARCH_PrefixMatches(str,p->str,STRBUF_GetLength((void *)str))) {
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

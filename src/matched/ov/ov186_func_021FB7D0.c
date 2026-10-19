/*
 * function: BR_BTN_DATA_CreateLabel
 * address: 0x021FB7D0
 * packet: pkt_ov186_021FB7D0
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BR_BTN_DATA_GetRowField 0x021FB7B0 thumb ov186
 *   WORDSET_CreateDefault 0x0201EC64 thumb
 *   WORDSET_SetSlotTag 0x0201EE0C thumb
 *   func_02045EC0 0x02045EC0 arm
 *   STRBUF_GetLength 0x020458F8 arm
 *   STRBUF_Create 0x020457B0 arm
 *   WORDSET_CopyTaggedText 0x0201F250 thumb
 *   WORDSET_Delete 0x0201ED04 thumb
 *   STRBUF_Delete 0x02045808 arm
 */
extern int BR_BTN_DATA_GetRowField(void *,int);
struct MsgBank;
struct WordSet;
extern struct WordSet *WORDSET_CreateDefault(unsigned int heap);
extern void WORDSET_SetSlotTag(struct WordSet *p, unsigned int i, const void *src, unsigned int n, unsigned int f, unsigned int c);
extern void *func_02045EC0(struct MsgBank *bank, unsigned int index);
typedef unsigned short u16;
typedef unsigned int   u32;
struct U16Vec;
struct WordSet;
extern u16 STRBUF_GetLength(struct U16Vec *vec);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void WORDSET_CopyTaggedText(struct WordSet *ws, void *dst, void *src);
extern u32 WORDSET_Delete(struct WordSet *p);
extern void STRBUF_Delete(struct U16Vec *vec);
void *BR_BTN_DATA_CreateLabel(unsigned *const *p,void *record,struct MsgBank *archive,unsigned short heap)
{
    int n,index,ok;
    void *tmp,*src,*result;
    n=BR_BTN_DATA_GetRowField(record,11);
    ok=0;
    if(n>=1 && n<=4){index=n-1;ok=1;}
    if(ok){
        if((*p)[index]!=0){
            tmp=WORDSET_CreateDefault((unsigned short)((heap&0x7fff)|0x8000));
            WORDSET_SetSlotTag(tmp,0,(const void *)((*p+index)[4]),(*p+index)[8],1,2);
            src=func_02045EC0(archive,(int)BR_BTN_DATA_GetRowField(record,3));
            result=STRBUF_Create(STRBUF_GetLength(src)+7,heap);
            WORDSET_CopyTaggedText(tmp,result,src);
            WORDSET_Delete(tmp);
            STRBUF_Delete(src);
        }else{
            result=func_02045EC0(archive,(int)BR_BTN_DATA_GetRowField(record,3));
        }
    }else{
        result=func_02045EC0(archive,(int)BR_BTN_DATA_GetRowField(record,3));
    }
    return result;
}

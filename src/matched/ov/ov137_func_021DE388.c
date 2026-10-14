/*
 * function: GURU2_RECEIPT_UpdateMemberSlots
 * address: 0x021DE388
 * packet: pkt_ov137_021DE388
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: A two-word union copies as one record and compares through its u64 view; the struct member zero preserves both word stores.
 * symbols:
 *   GURU2_RECEIPT_GetUnionApp 0x021DCF50 thumb ov137
 *   UNION_APP_GetMemberEntry 0x02184180 thumb ov022
 *   func_02008530 0x02008530 thumb
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef union { struct { u32 a,b; } words; u64 wide; } Pair;
typedef struct { char pad[0x4824]; Pair current,previous; } Record;
extern void *GURU2_RECEIPT_GetUnionApp(u8 *p);
extern char *UNION_APP_GetMemberEntry(unsigned char *p, int i);
struct Sub0200852CObj;
extern u32 func_02008530(const struct Sub0200852CObj *obj);
int GURU2_RECEIPT_UpdateMemberSlots(char *p) {
    int changed;
    int i;
    u32 *slot;
    Record *record;
    changed=0;
    for(i=0;i<5;i++) {
        slot=(u32 *)(p+i*8);
        slot[0x13c/4]=slot[0x138/4];
        slot[0x138/4]=(u32)UNION_APP_GetMemberEntry(GURU2_RECEIPT_GetUnionApp((u8 *)p),(u8)i);
        record=(Record *)(p+i*16);
        record->previous=record->current;
        if (slot[0x138/4]) {
            record->current.words.a=func_02008530((void *)slot[0x138/4]);
            record->current.words.b=1;
        } else {
            record->current.wide=0;
        }
    }
    for(i=0;i<5;i++) {
        slot=(u32 *)(p+i*8);
        if (slot[0x13c/4]!=slot[0x138/4]) {
            changed=1;
            if (slot[0x138/4]==0) *(u32 *)(p+i*4+0x160)=3;
            else *(u32 *)(p+i*4+0x160)=1;
        } else {
            record=(Record *)(p+i*16);
            if (record->current.wide!=record->previous.wide) {
                changed=1;
                if (record->current.words.b==0) *(u32 *)(p+i*4+0x160)=3;
                else *(u32 *)(p+i*4+0x160)=1;
            }
        }
    }
    return changed;
}

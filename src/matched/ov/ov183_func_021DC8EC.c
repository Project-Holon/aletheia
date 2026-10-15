/*
 * function: BR_CODEIN_RecordSetupProfile
 * address: 0x021DC8EC
 * packet: pkt_ov183_021DC8EC
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note 2026-10-05: re-run, bytes identical to the original; the only unresolved relocation is the BL to arm9 0x0200B98C (Thumb, 64 bytes, no code-start label, no asm/arm9 witness). Integrator: seed a label at 0x0200B98C; no source change needed.
 * blocker: ARM9 0200B98C lacks code-start witness, unresolved own calls +0128/+0146/+0232; no overlay leaves filed while ARM9 blocks.
 * blocker-C: prior verified Thumb EXACT from ov183_func_021DF838.c header, blocker-r2.log, dsi/1.1p1 -O4,p; table 0x0209DDCC data a4.
 * typedef unsigned char u8;
 * typedef unsigned short u16;
 * typedef unsigned long long u64;
 * extern const u16 BattleRecModeTable[];
 * u64 BATTLE_REC_GetHeaderParam(char *p,int selector,int index) {
 *   int i;u16 v;
 *   switch(selector) {
 *   case 0: v=((u16 *)p)[index];if(v>0x289)return 0;return v;
 *   case 1: return *(u8 *)(p+index+0x18)&0x7f;
 *   case 2: v=*(u16 *)(p+0x24);if(v>0x270f)return 0x270f;return v;
 *   case 3: for(i=0;i<0x29;i++)if(*(u16 *)(p+0x26)==BattleRecModeTable[i])return i;return 0;
 *   case 4: return *(u64 *)(p+0x38);
 *   case 5: return *(u8 *)(p+0x2a);
 *   case 6: return (*(u8 *)(p+index+0x18)&0x80)>>7;
 *   case 7: return *(u8 *)(p+0x2b);
 *   default:return 0;
 *   }
 * }
 * lever: counter declared before context locals restores stack homes; named selector fixes call-result addition operand order (existing idioms).
 * abi: EE0C retains caller's sixth outgoing word (2), beyond callee's five used arguments.
 * symbols:
 *   BR_CODEIN_RecordIsType1 0x021DD228 thumb ov183
 *   BR_CODEIN_RecordIsType2 0x021DD25C thumb ov183
 *   BR_RES_LoadBgGraphics 0x021FB964 thumb ov186
 *   BR_RES_GetFont 0x021FC20C thumb ov186
 *   BR_RES_GetMsgData 0x021FC214 thumb ov186
 *   BR_RES_GetWordSet 0x021FC21C thumb ov186
 *   BR_UTIL_Create 0x021FC6A4 thumb ov186
 *   BR_UTIL_SetTextLayout 0x021FC868 thumb ov186
 *   BR_UTIL_SetTextFromBuffer 0x021FC7C4 thumb ov186
 *   BR_CODEIN_RecordSetupActors 0x021DCBD8 thumb ov183
 *   STRBUF_Create 0x020457B0 arm
 *   STRBUF_Delete 0x02045808 arm
 *   func_02045EC0 0x02045EC0 arm
 *   GDS_PROFILE_CreateNameStr 0x0200D6D0 thumb
 *   func_0200D6EC 0x0200D6EC thumb
 *   func_0200D774 0x0200D774 thumb
 *   WORDSET_SetSlotTag 0x0201EE0C thumb
 *   WORDSET_SetSlotNumber 0x0201EFA4 thumb
 *   WORDSET_CopyTaggedText 0x0201F250 thumb
 *   BATTLE_REC_GetHeaderParam 0x0200B98C thumb
 *   _ll_udiv 0x0209C00C arm
 *   _ull_mod 0x0209C018 arm
 *   d_021E32C8 0x021E32C8 data a4
 */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef unsigned long long u64;
typedef struct {u8 x,y,w,h;u32 message;} Descriptor;
typedef struct U16Vec U16Vec;
typedef struct MsgBank MsgBank;
typedef struct WordSet WordSet;
typedef struct GdsProfile GdsProfile;
typedef struct GdsRecord GdsRecord;
typedef struct RecGet RecGet;
extern const Descriptor d_021E32C8[];
extern int BR_CODEIN_RecordIsType1(void *),BR_CODEIN_RecordIsType2(void *);
extern void BR_RES_LoadBgGraphics(void *ctx, unsigned kind, unsigned short heap);
extern unsigned BR_RES_GetFont(char *p);
extern int BR_RES_GetMsgData(char *);
extern int BR_RES_GetWordSet(char *);
extern void *BR_UTIL_Create(u16,unsigned,u16,u16,u8,u8,void *,u16);
extern void BR_UTIL_SetTextLayout(u8 *p, u32 a, u32 b, u32 c);
extern void BR_UTIL_SetTextFromBuffer(char *,void *,void *,u16);
extern void BR_CODEIN_RecordSetupActors(char *,void *,void *,u16);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void *GDS_PROFILE_CreateNameStr(const void *,u32);
extern void *func_0200D774(struct GdsProfile *p, struct GdsRecord *out, u32 tag);
extern u32 func_0200D6EC(struct RecGet *p);
extern void WORDSET_SetSlotTag(struct WordSet *p, u32 i, const void *src, u32 n, u32 f, u32 c);
extern void WORDSET_SetSlotNumber(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void WORDSET_CopyTaggedText(struct WordSet *ws, void *dst, void *src);
extern unsigned long long BATTLE_REC_GetHeaderParam(u8 *p, int selector, int index);
void BR_CODEIN_RecordSetupProfile(char *p,char *q)
{
    u16 record[4];
    int i;
    void *font;
    MsgBank *bank;
    WordSet *words;
    int ready;
    const Descriptor *d;
    char *slot;
    U16Vec *text;
    if(!*(int *)(p+0xd4)) {
        *(int *)(p+0xd4)=1;
        if(BR_CODEIN_RecordIsType1(*(void **)(p+0xc4))) BR_RES_LoadBgGraphics((void *)(*(int *)(q+0x10)),7,*(u16 *)(p+0xb4));
        else BR_RES_LoadBgGraphics((void *)(*(int *)(q+0x10)),6,*(u16 *)(p+0xb4));
        font=(void *)BR_RES_GetFont(*(char **)(q+0x10));
        bank=(MsgBank *)BR_RES_GetMsgData(*(char **)(q+0x10));
        words=(WordSet *)BR_RES_GetWordSet(*(char **)(q+0x10));
        for(i=0;i<5;i++) {
            d=&d_021E32C8[i];
            slot=p+i*4;
            *(void **)(slot+0x30)=BR_UTIL_Create(1,d->x,d->y,d->w,d->h,14,*(void **)(p+4),*(u16 *)(p+0xb4));
            switch(i) {
            case 0:
                {
                void *name;
                void *message;
                text=STRBUF_Create(128,*(u16 *)(p+0xb4));
                name=GDS_PROFILE_CreateNameStr(*(void **)(p+0xc0),*(u16 *)(p+0xb4));
                message=func_02045EC0(bank,d->message);
                WORDSET_SetSlotTag(words,0,name,func_0200D6EC(*(RecGet **)(p+0xc0)),1,2);
                WORDSET_CopyTaggedText(words,text,message);
                STRBUF_Delete((U16Vec *)name);STRBUF_Delete((U16Vec *)message);
                BR_UTIL_SetTextLayout(*(void **)(slot+0x30),0,1,0);
                ready=1;break;
                }
            case 1:
                {
                u32 selector;
                selector=BATTLE_REC_GetHeaderParam(*(void **)(p+0xc4),3,0);
                text=func_02045EC0(bank,selector+d->message);
                BR_UTIL_SetTextLayout(*(void **)(slot+0x30),0,1,0);ready=1;break;
                }
            case 2:
                {
                u64 value;
                u64 quotient;
                u32 low,middle,high;
                void *message;
                void *temporary;
                value=BATTLE_REC_GetHeaderParam(*(void **)(p+0xc4),4,0);
                low=value%100000ULL;
                quotient=value/100000ULL;
                middle=quotient%100000ULL;
                high=quotient/100000ULL;
                temporary=func_0200D774(*(GdsProfile **)(p+0xc0),(GdsRecord *)record,*(u16 *)(p+0xb4));
                if(temporary) {
                    message=func_02045EC0(bank,13);STRBUF_Delete((U16Vec *)temporary);
                } else message=func_02045EC0(bank,d->message);
                text=STRBUF_Create(128,*(u16 *)(p+0xb4));
                WORDSET_SetSlotNumber(words,2,low,5,2,1);WORDSET_SetSlotNumber(words,1,middle,5,2,1);WORDSET_SetSlotNumber(words,0,high,2,2,1);
                WORDSET_CopyTaggedText(words,text,message);
                BR_UTIL_SetTextLayout(*(void **)(slot+0x30),0,1,0);STRBUF_Delete((U16Vec *)message);
                ready=1;break;
                }
            case 3:
                if(BR_CODEIN_RecordIsType2(*(void **)(p+0xc4))) {
                    u32 count;
                    void *message;
                    count=BATTLE_REC_GetHeaderParam(*(void **)(p+0xc4),2,0);
                    text=STRBUF_Create(128,*(u16 *)(p+0xb4));
                    message=func_02045EC0(bank,d->message);
                    WORDSET_SetSlotNumber(words,0,count,4,0,1);WORDSET_CopyTaggedText(words,text,message);STRBUF_Delete((U16Vec *)message);
                    BR_UTIL_SetTextLayout(*(void **)(slot+0x30),0,1,1);ready=1;
                } else ready=0;
                break;
            case 4:
                if(BR_CODEIN_RecordIsType2(*(void **)(p+0xc4))) {
                    text=func_02045EC0(bank,d->message);
                    BR_UTIL_SetTextLayout(*(void **)(slot+0x30),0,1,1);ready=1;
                } else ready=0;
                break;
            }
            if(ready) {
                BR_UTIL_SetTextFromBuffer(*(char **)(slot+0x30),text,font,0x3da0);STRBUF_Delete(text);
            }
        }
        BR_CODEIN_RecordSetupActors(p,*(void **)(q+0x18),*(void **)(p+0xc4),*(u16 *)(p+0xb4));
    }
}

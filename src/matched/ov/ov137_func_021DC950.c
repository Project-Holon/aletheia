/*
 * function: GURU2_PartyListArgsCreate
 * address: 0x021DC950
 * packet: pkt_ov137_021DC950
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 * func_02030734 0x02030734 arm
 * gGuru2AllocFileName 0x021E2260 data a4
 *   GAME_DATA_GetMyItem  0x0201292C  thumb  arm9
 *   GAME_DATA_GetMyParty  0x02012934  thumb  arm9
 *   POKEPARTY_GetCount  0x0201AA18  thumb  arm9
 *   POKEPARTY_GetMember  0x0201AB28  thumb  arm9
 */
typedef unsigned int u32;
typedef unsigned short u16;
extern void *func_02030734(u32 heapId,u32 size,int clear,const char *site,u16 tag);
struct BigObj;
extern void *GAME_DATA_GetMyParty(const struct BigObj *p);
extern void *GAME_DATA_GetMyItem(const struct BigObj *p);
extern u32 POKEPARTY_GetCount(void *);
extern void *POKEPARTY_GetMember(void *p, u32 idx);
extern const unsigned char gGuru2AllocFileName[];
struct DC950Src {
    u32 pad_00[4];
    void *unk_10;
};
struct DC950Obj {
    void *unk_00;
    void *unk_04;
    u32 pad_08[11];
    int unk_34;
    u32 unk_38;
    int unk_3c;
    u32 pad_40[22];
};
struct DC950Obj *GURU2_PartyListArgsCreate(struct DC950Src *p,int a,int b)
{
    struct DC950Obj *v;
    int i;
    v=func_02030734(4,sizeof(struct DC950Obj),1,(const char *)gGuru2AllocFileName,256);
    v->unk_00=GAME_DATA_GetMyParty(p->unk_10);
    v->unk_04=GAME_DATA_GetMyItem(p->unk_10);
    v->unk_38=0;
    v->unk_34=a;
    v->unk_3c=b;
    for(i=0;i<(int)POKEPARTY_GetCount(v->unk_00);i++) POKEPARTY_GetMember(v->unk_00,i);
    return v;
}

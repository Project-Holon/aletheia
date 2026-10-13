/*
 * function: func_021DC950
 * address: 0x021DC950
 * packet: pkt_ov137_021DC950
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 * func_02030734 0x02030734 arm
 * d_021E2260 0x021E2260 data a4
 *   GAME_DATA_GetMyItem  0x0201292C  thumb  arm9
 *   GAME_DATA_GetMyParty  0x02012934  thumb  arm9
 */
typedef unsigned int u32;
typedef unsigned short u16;
extern void *func_02030734(u32 heapId,u32 size,int clear,const char *site,u16 tag);
struct BigObj;
extern void *GAME_DATA_GetMyParty(const struct BigObj *p);
extern void *GAME_DATA_GetMyItem(const struct BigObj *p);
extern u32 func_0201AA18(void *);
extern void *func_0201AB28(void *p, u32 idx);
extern const unsigned char d_021E2260[];
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
struct DC950Obj *func_021DC950(struct DC950Src *p,int a,int b)
{
    struct DC950Obj *v;
    int i;
    v=func_02030734(4,sizeof(struct DC950Obj),1,(const char *)d_021E2260,256);
    v->unk_00=GAME_DATA_GetMyParty(p->unk_10);
    v->unk_04=GAME_DATA_GetMyItem(p->unk_10);
    v->unk_38=0;
    v->unk_34=a;
    v->unk_3c=b;
    for(i=0;i<(int)func_0201AA18(v->unk_00);i++) func_0201AB28(v->unk_00,i);
    return v;
}

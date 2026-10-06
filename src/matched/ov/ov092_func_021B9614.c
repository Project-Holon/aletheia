/*
 * function: func_021B9614
 * address: 0x021B9614
 * packet: pkt_ov092_021B9614
 * region: ov092
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note: 2026-10-05 matched. Loader order (context, id, descriptor, argument). Closing forms: case 1, 2 and 5 are
 *   `if (busy != 1) { body; break; } return 0;` (return block after the body); `ok = 0; if (f == 1) ok = 1;`;
 *   `if (flag) x = 0; else x = 1;`; `case 6: default: return 1;`; the case 4 tail `r68 = 1; break;` written in
 *   the guarded arm and again after it (cross-jumped copy leaves the b stub); species and slot as u16 locals,
 *   box/bslot declared first; the source record pointer s is not const. Case 4 mask and slot use a two-field view.
 * symbols:
 *   func_02031330 0x02031330 arm
 *   func_02012934 0x02012934 thumb
 *   func_02012944 0x02012944 thumb
 *   func_0200CA1C 0x0200CA1C thumb
 *   func_0201293C 0x0201293C thumb
 *   func_021B9A14 0x021B9A14 thumb ov092
 *   func_0201AC2C 0x0201AC2C thumb
 *   func_0201B038 0x0201B038 thumb
 *   func_0201B170 0x0201B170 thumb
 *   func_021B9AA0 0x021B9AA0 thumb ov092
 *   func_021B9C80 0x021B9C80 thumb ov092
 *   func_021B9C34 0x021B9C34 thumb ov092
 *   func_021B9CA4 0x021B9CA4 thumb ov092
 *   func_02012F08 0x02012F08 thumb
 *   func_0200C278 0x0200C278 thumb
 *   func_0200C29C 0x0200C29C thumb
 *   func_021B9BD8 0x021B9BD8 thumb ov092
 *   func_0201AB28 0x0201AB28 thumb
 *   func_02008500 0x02008500 thumb
 *   func_02017E40 0x02017E40 thumb
 *   func_0201AA18 0x0201AA18 thumb
 *   func_0201AA14 0x0201AA14 thumb
 *   func_02007698 0x02007698 thumb
 *   func_020076D0 0x020076D0 thumb
 *   func_02045B38 0x02045B38 arm
 *   func_0201296C 0x0201296C thumb
 *   func_020142E8 0x020142E8 thumb
 *   func_02045EC0 0x02045EC0 arm
 *   func_02045C04 0x02045C04 arm
 *   func_020127A4 0x020127A4 thumb
 *   func_02012AC8 0x02012AC8 thumb
 *   func_02013E4C 0x02013E4C thumb
 *   func_0202F190 0x0202F190 thumb
 *   func_0200CA38 0x0200CA38 thumb
 *   func_02017E1C 0x02017E1C thumb
 *   func_0200CED4 0x0200CED4 thumb
 *   func_0200CFA0 0x0200CFA0 thumb
 *   func_0200CDE0 0x0200CDE0 thumb
 *   func_02031348 0x02031348 arm
 *   func_02012EBC 0x02012EBC thumb
 *   func_0200C0F0 0x0200C0F0 thumb
 *   func_0216C0A4 0x0216C0A4 thumb ov010
 *   func_0216C0E4 0x0216C0E4 thumb ov010
 *   func_0216C0D4 0x0216C0D4 thumb ov010
 *   func_02012F2C 0x02012F2C thumb
 *   func_02008DF0 0x02008DF0 thumb
 *   func_0216C0C0 0x0216C0C0 thumb ov010
 *   func_021B9D04 0x021B9D04 thumb ov092
 *   func_0201A98C 0x0201A98C thumb
 *   func_020185F0 0x020185F0 thumb
 *   func_020074D8 0x020074D8 thumb
 *   func_02005E30 0x02005E30 thumb
 *   func_02005E50 0x02005E50 thumb
 *   func_02005D28 0x02005D28 thumb
 *   func_02012984 0x02012984 thumb
 *   func_0201B2B0 0x0201B2B0 thumb
 *   func_02030734 0x02030734 arm
 *   func_020307B0 0x020307B0 arm
 *   data_0220BAB0 0x0220BAB0 data a4 ov207
 *   data_021F5580 0x021F5580 data a4 ov194
 *   data_02208C40 0x02208C40 data a4 ov195
 *   ov207_id 0x000000CF data a1
 *   ov194_id 0x000000C2 data a1
 *   ov195_id 0x000000C3 data a1
 *   data_021B9DC0 0x021B9DC0 data a1
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u8 pad[0x38]; u16 idx, mask; } Rec;
typedef struct { void *save, *party; u16 species; u8 slot, method; u32 x, flag; } Extra;
extern const u8 data_0220BAB0[], data_021F5580[], data_02208C40[], data_021B9DC0[];
extern const u8 ov207_id[], ov194_id[], ov195_id[];
extern u32 func_02031330(void *);
typedef signed int     s32;
struct Big;
struct BigObj;
struct Blk34;
struct Blk37;
struct MsgBank;
struct Party;
struct PartyMon;
struct Rec;
struct Rec44;
struct Rec534;
struct S;
struct SaveBlock;
struct Sub02007454Entry;
struct Sub02008C20Obj;
extern void *func_02012934(const struct BigObj *p);
extern u8 *func_02012944(void *);
extern void *func_0200CA1C(void *);
extern u32 func_0201293C(const struct BigObj *p);
extern void func_021B9A14(u8 *a0, struct S *s);
extern void func_0201AC2C(const struct Rec534 *src, struct Rec534 *dst);
extern void func_0201B038(void *);
extern void func_0201B170(void *);
extern void func_021B9AA0(void *);
extern u32 func_021B9C80(u32, u32);
extern void func_021B9C34(struct S *s, void *party, int c);
extern void func_021B9CA4(struct S *s, void *party);
extern void *func_02012F08(int *p);
extern u32 func_0200C278(struct Blk34 *p, u32 v);
extern u32 func_0200C29C(struct Blk34 *p, u32 v);
extern void func_021B9BD8(void *);
extern void *func_0201AB28(void *, u32);
extern void func_02008500(void *, void *);
extern void func_02017E40(void *, u32, u32);
extern u32 func_0201AA18(void *p);
extern u32 func_0201AA14(void *p);
extern u32 func_02007698(void *);
extern int func_020076D0(void *, int *, int *);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern u32 func_0201296C(const struct BigObj *p);
extern u32 func_020142E8(void *bitmap, s32 id);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_02045C04(struct Rec *rec);
extern void *func_020127A4(struct SaveBlock *p);
extern u16 func_02012AC8(const struct Rec44 *p);
extern u32 func_02013E4C(u32);
extern void func_0202F190(void *, u32, u32, u32, u16);
extern u32 func_0200CA38(struct Blk37 *p);
extern u32 func_02017E1C(void *, u32, u32);
extern u32 func_0200CED4(struct Blk37 *p, u16 id);
extern void func_0200CFA0(struct Blk37 *p, void *m);
extern void func_0200CDE0(struct Blk37 *p, void *m);
extern void func_02031348(void *, u32, const u8 *, void *);
extern void *func_02012EBC(struct Big *p);
extern void *func_0200C0F0(void *);
extern int *func_0216C0A4(unsigned short a, int b, int c, int d, int e, int f, int g, int h);
extern int func_0216C0E4(int *p);
extern void func_0216C0D4(int *p, int a1);
extern void *func_02012F2C(int *p);
extern u32 func_02008DF0(struct Sub02008C20Obj *obj, int i);
extern int func_0216C0C0(int a0);
extern void func_021B9D04(void *);
extern u32 func_0201A98C(struct Party *p, const struct PartyMon *src);
extern void *func_020185F0(void *);
extern int func_020074D8(void **save, const struct Sub02007454Entry *src);
extern void func_02005E30(u32);
extern int func_02005E50(void);
extern void func_02005D28(void);
extern u8 func_02012984(const struct BigObj *p);
extern u16 func_0201B2B0(void *, void *, u32, u32, u8, u32 *, u16);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *p);
int func_021B9614(void *unused, u32 *step, u8 *s, u8 *r)
{
    u32 busy;
    void *party;
    int box, bslot;
    u32 method;
    void *mon;
    u8 *buf;
    void *dex, *save, *bank;
    int amount, used, index;
    int flag;
    unsigned long dexno;
    u16 species;
    u16 slot;
    Extra *e;
    busy = func_02031330((*(void **)((u8 *)(r)+( 64))));
    if (busy == 1) return 0;
    switch (*step) {
    case 0:
        party = func_02012934((*(void **)((u8 *)(s)+( 0))));
        buf = func_02012944((*(void **)((u8 *)(s)+( 0))));
        dex = func_0200CA1C((*(void **)((u8 *)(s)+( 0))));
        save = (void *)func_0201293C((*(void **)((u8 *)(s)+( 0))));
        (((Rec *)r)->idx) = 0;
        (((Rec *)r)->mask) = 0;
        if ((*(u32 *)((u8 *)((*(void **)((u8 *)(s)+( 4))))+( 0))) <= 1) {
            func_021B9A14(r, (struct S *)s);
            func_0201AC2C((*(void **)((u8 *)((*(void **)((u8 *)(s)+( 4))))+( 36))), party);
            func_0201B038(party);
            func_0201B170(party);
            if ((*(u32 *)((u8 *)((*(void **)((u8 *)(s)+( 4))))+( 140))) == 1) func_021B9AA0(party);
            func_021B9C34((struct S *)s, party, func_021B9C80((u32)(*(void **)((u8 *)(s)+( 4))) + 8, (*(u16 *)((u8 *)(r)+( 60)))));
            func_021B9CA4((struct S *)s, party);
            amount = (*(u32 *)((u8 *)((*(void **)((u8 *)(s)+( 4))))+( 136)));
            if (amount > 0) func_0200C278(func_02012F08((*(void **)((u8 *)(s)+( 0)))), amount);
            else if (amount < 0) func_0200C29C(func_02012F08((*(void **)((u8 *)(s)+( 0)))), -amount);
        }
        func_021B9BD8(party);
        if ((*(u32 *)((u8 *)((*(void **)((u8 *)(s)+( 4))))+( 140))) == 5) {
            (*(void **)((u8 *)(r)+( 8))) = func_0201AB28((*(void **)((u8 *)((*(void **)((u8 *)(s)+( 4))))+( 40))), *((u8 *)(*(void **)((u8 *)(s)+( 4))) + 144));
            func_02008500(buf, (*(void **)((u8 *)(r)+( 4))));
            func_02017E40((*(void **)((u8 *)(r)+( 8))), 141, (*(u32 *)((u8 *)(r)+( 4))));
            used = (int)func_0201AA18(party);
            if (used >= (int)func_0201AA14(party)) {
                box = func_02007698(save); bslot = 0;
                func_020076D0(save, &box, &bslot);
                (*(u32 *)((u8 *)(r)+( 48))) = box;
                bank = func_02045B38(0, 2, 234, 82);
                index = func_020142E8((void *)func_0201296C((*(void **)((u8 *)(s)+( 0)))), 0x96d) ? 177 : 176;
                (*(void **)((u8 *)(r)+( 44))) = func_02045EC0(bank, index);
                func_02045C04(bank);
            }
            func_0202F190((*(void **)((u8 *)(r)+( 8))), 0, (u32)buf, func_02013E4C(func_02012AC8(func_020127A4((*(void **)((u8 *)(s)+( 0)))))), (*(u16 *)((u8 *)(r)+( 60))));
            flag = 0;
            dexno = func_0200CA38(dex);
            if (func_0200CED4(dex, func_02017E1C((*(void **)((u8 *)(r)+( 8))), 5, 0)) == 0) flag = 1;
            func_0200CFA0(dex, (*(void **)((u8 *)(r)+( 8))));
            func_0200CDE0(dex, (*(void **)((u8 *)(r)+( 8))));
            (*(u32 *)((u8 *)(r)+( 20))) = dexno;
            (*(void **)((u8 *)(r)+( 16))) = (*(void **)((u8 *)(r)+( 8)));
            (*(void **)((u8 *)(r)+( 24))) = (*(void **)((u8 *)(r)+( 44)));
            (*(void **)((u8 *)(r)+( 28))) = save;
            (*(u32 *)((u8 *)(r)+( 32))) = (*(u32 *)((u8 *)(r)+( 48)));
            (*(void **)((u8 *)(r)+( 36))) = (*(void **)((u8 *)(s)+( 0)));
            if (flag) (*(u32 *)((u8 *)(r)+( 12))) = 0; else (*(u32 *)((u8 *)(r)+( 12))) = 1;
            func_02031348((*(void **)((u8 *)(r)+( 64))), (u32)ov207_id, data_0220BAB0, r + 12);
            ++*step;
        } else *step = 4;
        break;
    case 1:
        if (busy != 1) {
        save = (void *)func_0201293C((*(void **)((u8 *)(s)+( 0))));
        flag = 0;
        if ((*(u32 *)((u8 *)(r)+( 40))) == 1) flag = 1;
        if (flag) {
            bank = func_0200C0F0(func_02012EBC((*(void **)((u8 *)(s)+( 0)))));
            (*(void **)((u8 *)(r)+( 0))) = func_0216C0A4((*(u16 *)((u8 *)(r)+( 60))), (int)(*(void **)((u8 *)(r)+( 8))), 10, 0, (int)(*(void **)((u8 *)(r)+( 44))), (int)save, (*(u32 *)((u8 *)(r)+( 48))), (int)bank);
            func_02031348((*(void **)((u8 *)(r)+( 64))), (u32)ov194_id, data_021F5580, (*(void **)((u8 *)(r)+( 0))));
            ++*step;
        } else *step = 3;
        break;
        }
        return 0;
    case 2:
        if (busy != 1) {
        if (!func_0216C0E4((*(void **)((u8 *)(r)+( 0))))) {
            func_0216C0D4((*(void **)((u8 *)(r)+( 0))), (u32)(*(u32 *)((u8 *)(r)+( 4))));
            func_02017E40((*(void **)((u8 *)(r)+( 8))), 115, (*(u32 *)((u8 *)(r)+( 4))));
            func_02008DF0(func_02012F2C((*(void **)((u8 *)(s)+( 0)))), 30);
        }
        func_0216C0C0((int)(*(void **)((u8 *)(r)+( 0))));
        (*(void **)((u8 *)(r)+( 0))) = 0;
        ++*step;
        break;
        }
        return 0;
    case 3:
        party = func_02012934((*(void **)((u8 *)(s)+( 0))));
        func_021B9D04((*(void **)((u8 *)(r)+( 8))));
        if (!(*(void **)((u8 *)(r)+( 44)))) func_0201A98C(party, (*(void **)((u8 *)(r)+( 8))));
        else {
            save = (void *)func_0201293C((*(void **)((u8 *)(s)+( 0))));
            func_020074D8(save, func_020185F0((*(void **)((u8 *)(r)+( 8)))));
        }
        ++*step;
        break;
    case 4: {
        void *party;
        if (!(*(u32 *)((u8 *)(r)+( 68)))) {
            if ((*(u32 *)((u8 *)((*(void **)((u8 *)(s)+( 4))))+( 140))) == 5 && (((Rec *)r)->mask)) {
                if (!(*(u32 *)((u8 *)(r)+( 72)))) { func_02005E30(30); (*(u32 *)((u8 *)(r)+( 72))) = 1; break; }
                if (func_02005E50()) break;
                func_02005D28();
                (*(u32 *)((u8 *)(r)+( 68))) = 1;
                break;
            }
            (*(u32 *)((u8 *)(r)+( 68))) = 1;
            break;
        }
        if ((((Rec *)r)->mask)) {
            species = 0;
            party = func_02012934((*(void **)((u8 *)(s)+( 0))));
            *step = 6;
            while ((((Rec *)r)->mask)) {
                if ((((Rec *)r)->mask) & 1) {
                    mon = func_0201AB28(party, (((Rec *)r)->idx));
                    species = func_0201B2B0(party, mon, 0, (*(u16 *)((u8 *)((*(void **)((u8 *)(s)+( 4))))+( 18))), func_02012984((*(void **)((u8 *)(s)+( 0)))), &method, (*(u16 *)((u8 *)(r)+( 60))));
                    slot = (((Rec *)r)->idx);
                }
                (((Rec *)r)->mask) = (((Rec *)r)->mask) >> 1;
                (((Rec *)r)->idx)++;
                if (species) {
                    e = func_02030734((*(u16 *)((u8 *)(r)+( 60))), 20, 0, (const char *)data_021B9DC0, 0x1ca);
                    e->save = (*(void **)((u8 *)(s)+( 0))); e->party = party; e->species = species; e->slot = slot; e->method = method; e->x = 0; e->flag = 1;
                    (*(void **)((u8 *)(r)+( 52))) = e;
                    func_02031348((*(void **)((u8 *)(r)+( 64))), (u32)ov195_id, data_02208C40, e);
                    *step = 5;
                    break;
                }
            }
        } else *step = 6;
        break;
    }
    case 5:
        if (busy != 1) {
        func_020307B0((*(void **)((u8 *)(r)+( 52))));
        (*(void **)((u8 *)(r)+( 52))) = 0;
        if ((((Rec *)r)->mask)) *step = 4;
        else ++*step;
        break;
        }
        return 0;
    case 6:
    default:
        return 1;
    }
    return 0;
}

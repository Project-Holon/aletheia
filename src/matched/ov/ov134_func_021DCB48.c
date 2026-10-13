/*
 * function: func_021DCB48
 * address: 0x021DCB48
 * packet: pkt_ov134_021DCB48
 * region: ov134
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   POKE_REGULATION_AdjustPartyLevels 0x0201A2A8 thumb
 *   func_0200873C 0x0200873C thumb
 *   func_02034AC4 0x02034AC4 arm
 *   PLIST_COMM_Start 0x021B6100 thumb ov090
 *   ov90_id 0x0000005A data a1
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u8 *a; void *party; u32 f8; u8 fC, padD[3]; u32 f10; void *save; u8 tail[20]; } Args;
typedef struct {
    void *party;
    u32 f4, f8, fC, f10;
    u8 *a;
    u8 pad18[24];
    u16 f30, pad32;
    u32 f34, f38, f3C, f40;
    u16 f44, f46;
    u8 f48, marks[6], pad4F;
    u32 f50;
    u16 f54, pad56;
    u32 f58, pad5C;
    u16 f60, pad62;
    u32 f64;
    u8 pad68[12];
    u32 f74, f78;
    u8 f7C, pad7D[15];
    u32 f8C, f90;
    u8 f94;
} Output;
struct Big;
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern void POKE_REGULATION_AdjustPartyLevels(void *, void *);
struct Sub02008700Obj;
extern struct Sub02008700Obj *func_0200873C(void *sys);
extern int func_02034AC4(int);
extern void PLIST_COMM_Start(u8 *);
extern const char ov90_id[];
void func_021DCB48(Args *p, void *unused, Output *out)
{
    u8 *a;
    void *b;
    u8 i;
    a = p->a;
    b = GAME_DATA_GetSaveControl(p->save);
    out->party = p->party;
    POKE_REGULATION_AdjustPartyLevels(a, out->party);
    out->f4 = 0;
    out->f8 = 0;
    out->fC = (u32)func_0200873C(b);
    out->f10 = 0;
    out->f30 = 0;
    out->f34 = 26;
    out->a = a;
    switch (a[0xba]) {
    case 0:
        out->f38 = 0;
        out->f64 = 1;
        break;
    case 1:
        out->f38 = 1;
        out->f64 = 1;
        break;
    case 2:
        out->f38 = 1;
        out->f64 = 1;
        break;
    case 3:
        out->f38 = 1;
        out->f64 = 1;
        break;
    case 4:
        out->f38 = 2;
        out->f64 = 2;
        break;
    }
    out->f44 = 0;
    out->f46 = 0;
    out->f48 = 0;
    out->f3C = 0;
    out->f40 = 0;
    for (i = 0; i < 6; i++) out->marks[i] = 0;
    out->f50 = 0;
    out->f58 = 0;
    out->f54 = 0;
    out->f74 = p->f10;
    out->f78 = p->f8;
    out->f7C = p->fC;
    out->f8C = a[184];
    if (a[185] != 0) {
        out->f90 = 1;
        out->f60 = a[185];
    } else {
        out->f90 = 0;
        out->f60 = 0;
    }
    out->f94 = 0;
    func_02034AC4((int)ov90_id);
    PLIST_COMM_Start((u8 *)out);
}

/*
 * function: func_021EFD98
 * address:  0x021EFD98
 * packet:   pkt_ov107_021EFD98
 * region:   ov107
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   GAME_DATA_GetBoxManager  0x0201293C  thumb
 *   ZUKAN_SAVE_GetFromGameData  0x0200CA1C  thumb
 *   func_021F11C4  0x021F11C4  thumb
 *   GAME_DATA_GetTrainerRecord  0x02012F2C  thumb
 *   func_02008DAC  0x02008DAC  thumb
 *   func_021F11CC  0x021F11CC  thumb
 *   func_0202F27C  0x0202F27C  thumb
 *   func_020074D8  0x020074D8  thumb
 *   POKE_TOOL_CreateFromBoxParam  0x0201747C  thumb
 *   ZUKAN_SAVE_RegisterCaught  0x0200CDE0  thumb
 *   func_020307B0  0x020307B0  arm
 *   func_02034714  0x02034714  arm
 *   d_021F6E08     0x021F6E08  data
 */

typedef struct {
    int f00;
    void *f04;
} Ov107Save;

typedef struct {
    unsigned short f00;
    unsigned char pad02[6];
    Ov107Save *f08;
    void *f0C;
    unsigned char pad10[0x18];
    unsigned char f28;
} Ov107Ctx;

extern unsigned char d_021F6E08[];

struct BigObj;
unsigned int GAME_DATA_GetBoxManager(const struct BigObj *p);
void *ZUKAN_SAVE_GetFromGameData(void *);
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Blk37;
struct Mon;
struct Sub02007454Entry;
struct Sub02008C20Obj;
u8 func_021F11C4(u8 *p);
void *GAME_DATA_GetTrainerRecord(int *p);
u32 func_02008DAC(struct Sub02008C20Obj *obj, int i, u32 delta);
void *func_021F11CC(void *, int);
void func_0202F27C(void *);
int func_020074D8(void **save, const struct Sub02007454Entry *src);
void *POKE_TOOL_CreateFromBoxParam(struct Mon *p, u32 heap);
void ZUKAN_SAVE_RegisterCaught(struct Blk37 *p, void *m);
u32 func_020307B0(void *p);
void func_02034714(const char *expr, u32 line, const char *file);

void func_021EFD98(Ov107Ctx *p)
{
    void *party;
    void *box;
    unsigned int n;
    void *dex;
    void *mon;
    int ok;
    unsigned char i;

    party = (void *)GAME_DATA_GetBoxManager(p->f08->f04);
    box = ZUKAN_SAVE_GetFromGameData(p->f08->f04);
    n = func_021F11C4(p->f0C);
    if (p->f28 == 0) {
        dex = GAME_DATA_GetTrainerRecord(p->f08->f04);
        func_02008DAC(dex, 7, n);
        func_02008DAC(dex, 0x54, n);
    }
    for (i = 0; i < n; i++) {
        mon = func_021F11CC(p->f0C, i);
        func_0202F27C(mon);
        ok = func_020074D8(party, mon);
        mon = POKE_TOOL_CreateFromBoxParam(mon, p->f00);
        ZUKAN_SAVE_RegisterCaught(box, mon);
        func_020307B0(mon);
        if (ok != 1) {
            func_02034714((const char *)d_021F6E08, 0, (const char *)d_021F6E08);
        }
    }
}

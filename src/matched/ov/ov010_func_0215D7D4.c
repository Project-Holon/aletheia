/*
 * function: SCRCMD_MUSICAL_GetProgramInfo
 * address:  0x0215D7D4
 * packet:   pkt_ov010_0215D7D4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   SCRCMD_WORK_GetGameData  0x0215A5E4  thumb  ov010
 *   GAME_DATA_GetSaveBlock2A  0x02012F44  thumb
 *   func_0200A750  0x0200A750  thumb
 */

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

typedef struct {
    u8 pad[0x14];
    u8 *f14;
} Cur;

typedef struct {
    u8 b0;
    u8 b1;
    u16 h2;
} Rec;

extern unsigned int SCRIPT_WORK_ReadWorkValue(void *a0, void *a1);
extern u16 *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
extern void *SCRCMD_WORK_GetGameData(void *a0);
extern void *GAME_DATA_GetSaveBlock2A(void *);
struct Big;
struct BigSub4;
extern struct BigSub4 *func_0200A750(struct Big *p, u32 index);

int SCRCMD_MUSICAL_GetProgramInfo(Cur *a, void *b)
{
    int f;
    u32 k;
    u16 *out;
    Rec *r;
    f = SCRIPT_WORK_ReadWorkValue(a, b);
    k = *a->f14;
    a->f14++;
    out = SCRIPT_WORK_ReadWorkPointer(a, b);
    r = (Rec *)func_0200A750(GAME_DATA_GetSaveBlock2A(SCRCMD_WORK_GetGameData(b)), (u8)f);
    switch (k) {
    case 0:
        switch (r->b0) {
        case 0: *out = 0x18; break;
        case 1: *out = 0xf; break;
        case 2: *out = 0x2d; break;
        case 3: *out = 0xc; break;
        case 4: *out = 0; break;
        }
        break;
    case 1:
        *out = f + 5;
        break;
    case 2:
        f += 0xf;
        *out = f;
        break;
    case 3:
        *out = r->b1;
        break;
    case 4:
        *out = r->h2;
        break;
    }
    return 0;
}
